#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/multi_polygon.hpp>

using namespace std;
namespace bg = boost::geometry;
using BoostPoint = bg::model::d2::point_xy<double>;
using BoostPolygon = bg::model::polygon<BoostPoint>;
using BoostMultiPolygon = bg::model::multi_polygon<BoostPolygon>;
using BoostLinestring = bg::model::linestring<BoostPoint>;
using json = nlohmann::json;
enum result {
    UNKNOW = 0,
    REJECT = 1,
    ACCEPT = 2,
    ACTIVE = 3,
    SUCCESS = 4,
    ERROR = 5,
    CANCEL = 6
};
class navigation_function : public rclcpp::Node{
    public:
        navigation_function(const string &node_name, const string sub_namespace): rclcpp::Node(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            //transform
            tf_Buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
            tf_Listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_Buffer_);
            tf_Broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
            //robot stop
            stop_robot_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",1);
            // Action Clients
            nav_complete_coverage_client_ = rclcpp_action::create_client<opennav_coverage_msgs::action::NavigateCompleteCoverage>(this, "navigate_complete_coverage");
            nav_through_poses_client_ = rclcpp_action::create_client<nav2_msgs::action::NavigateThroughPoses>(this, "navigate_through_poses");
            nav_to_pose_client_ = rclcpp_action::create_client<nav2_msgs::action::NavigateToPose>(this, "navigate_to_pose");
            follow_path_client_ = rclcpp_action::create_client<nav2_msgs::action::FollowPath>(this, "follow_path");
            compute_path_to_pose_client_ = rclcpp_action::create_client<nav2_msgs::action::ComputePathToPose>(this, "compute_path_to_pose");
            //create publisher
            pub_amcl_=this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("initialpose",1);
            pub_user_path_ = this->create_publisher<nav_msgs::msg::Path>("user_path",1);
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            navigation_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("navigation_function_state",1);
            covered_pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("covered_poses",1);
            robot_position_pub_ = this->create_publisher<std_msgs::msg::String>("robot_position",1);
            //create subscriber
            auto robot_position_callback = [this](geometry_msgs::msg::PoseWithCovarianceStamped msg)->void{
                robot_position_ = msg;
            };
            robot_position_sub_ = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(mvibot_seri_ + "/amcl_pose",qos_profile,robot_position_callback);
            //get data of function
            auto navigation_info_callback = [this](std_msgs::msg::String msg)->void{
                parameters = json::parse(msg.data);
                cout<<msg.data<<endl;
                process_data();
                request = 1;
                step = 0;
            };
            navigation_info_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/navigation_info", qos_profile, navigation_info_callback);
            //get state of function
            auto navigation_function_status_callback = [this](std_msgs::msg::String msg)->void{
		        static int st = 0;
                if(msg.data == "active"){
		            st = 1;
                    request = 1;
                    status = Active_;
                }
                else if(msg.data == "stop") {
                    if(st == 1){
                        pub_stop_robot();
                        cancel_navToPose();
                        cancel_navThroughPoses();
                        cancel_navCompleteCoverage();
                        cancel_getPathToPose();
                        cancel_followPath();
                        st = 0;
                    }
                    request = 1;
                    status = Stop_;
                }
                else if(msg.data == "error") {
                    pub_stop_robot();
                    cancel_navToPose();
                    cancel_navThroughPoses();
                    cancel_navCompleteCoverage();
                    status = Error_;
                    request = 0;
                }
                else if(msg.data == "cancel") {
                    request = 0;
                    status = Cancel_;
                }
                else if(msg.data == "finish") {
                    request = 0;
                    status = Finish_;
                }
            };
            navigation_function_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/navigation_function_status", qos_profile, navigation_function_status_callback);
            //get path to goal
            auto get_path_to_goal_callback = [this](nav_msgs::msg::Path msg)->void{
                path_ = nav_msgs::msg::Path();
                path_ =msg;
                pub_user_path(msg);
            };
            get_path_to_goal_sub_ = this->create_subscription<nav_msgs::msg::Path>(mvibot_seri_+"/plan", rclcpp::SystemDefaultsQoS(), get_path_to_goal_callback);
            auto get_path_coverage_callback = [this](nav_msgs::msg::Path msg)->void{
                path_ = nav_msgs::msg::Path();
                path_ = msg;
                pub_user_path(msg);
            };
            get_path_coverage_sub_ = this->create_subscription<nav_msgs::msg::Path>(mvibot_seri_+"/coverage_server/coverage_plan", rclcpp::SystemDefaultsQoS(), get_path_coverage_callback);
            //create service
            clear_costmap_global_srv_ = this->create_client<nav2_msgs::srv::ClearEntireCostmap>("global_costmap/clear_entirely_global_costmap");
            clear_costmap_local_srv_ = this->create_client<nav2_msgs::srv::ClearEntireCostmap>("local_costmap/clear_entirely_local_costmap");
            //
            set_initial_robot("/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/robot_position.txt");
            //timer
            auto send_robot_position_callback = [this]()->void{
                double *pos_robot;
                string data;
                pos_robot = get_position_tf("map",mvibot_seri_f_+"/base_footprint");
                save_robot_position("/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/robot_position.txt", pos_robot[0], pos_robot[1], pos_robot[2], pos_robot[3]);
                data = mvibot_seri_f_+"|x:"+to_string(pos_robot[0])+"|y:"+to_string(pos_robot[1])+"|thz:"+to_string(pos_robot[2])+"|thw:"+to_string(pos_robot[3]);
                cout<<data<<endl;
                pub_robot_position(data);
            };
            send_robot_position_timer_ = this->create_wall_timer(1000ms, send_robot_position_callback);
            auto execute_navigation_timer_callback = [this]()->void{
                cout<<"navigation|request:"<<request<<"|state:"<<status<<endl;
                if(request == 1){
                    int res;
                    res = action();
                    pub_function_state_navigation(res);
                }
            };
            execute_navigation_timer_ = this ->create_wall_timer(50ms, execute_navigation_timer_callback);
        }
        void send_history(string status, string info);
        void pub_stop_robot();
        void pub_amcl(float x, float y, float z, float w);
        void set_initial_robot(const string& file_path);
        geometry_msgs::msg::PoseStamped get_robot_position();
        double *get_position_tf(string name1, string name2);
        void pub_robot_position(string data);
        void save_robot_position(const std::string& file_path, double x, double y, double thz, double thw);
        void pub_user_path(const nav_msgs::msg::Path &path);
        void pub_function_state_navigation(int st);
        void navCompleteCoverage(const vector<geometry_msgs::msg::Polygon> &polygons, const std::string &behavior_tree="");
        void goToPose(const geometry_msgs::msg::PoseStamped &pose, const string &behavior_tree="");
        void goThroughPoses(const std::vector<geometry_msgs::msg::PoseStamped> &poses, const std::string &behavior_tree="");
        void getPathToPose(geometry_msgs::msg::PoseStamped start, geometry_msgs::msg::PoseStamped goal, std::string planner_id="", bool use_start = false);
        void followPath(const nav_msgs::msg::Path &path, const std::string &controller_id="", const std::string &goal_checker_id="");
        void update_polygon();
        void cancel_navCompleteCoverage();
        void cancel_navToPose();
        void cancel_navThroughPoses();
        void cancel_followPath();
        void cancel_getPathToPose();
        void clearLocalCostmap();
        void clearGlobalCostmap();
        void clearAllCostmap();
        void process_data();
        int action ();
        float getyaw(double data1, double data2); 
    private:
        //declare tranform var
        std::unique_ptr<tf2_ros::Buffer> tf_Buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_Listener_{nullptr};
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_Broadcaster_;
        ////action////
        rclcpp_action::Client<opennav_coverage_msgs::action::NavigateCompleteCoverage>::SharedPtr nav_complete_coverage_client_;
        rclcpp_action::Client<nav2_msgs::action::NavigateThroughPoses>::SharedPtr nav_through_poses_client_;
        rclcpp_action::Client<nav2_msgs::action::NavigateToPose>::SharedPtr nav_to_pose_client_;
        rclcpp_action::Client<nav2_msgs::action::FollowPath>::SharedPtr follow_path_client_;
        rclcpp_action::Client<nav2_msgs::action::ComputePathToPose>::SharedPtr compute_path_to_pose_client_;
        
        //// Subscriptions////
        rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr localization_pose_sub_;
        rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr robot_position_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr navigation_function_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr navigation_info_sub_;
        rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr get_path_to_goal_sub_;
        rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr get_path_coverage_sub_;
        //// Publish ////
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr stop_robot_pub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr pub_amcl_;
        rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_user_path_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr navigation_function_state_pub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr covered_pose_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_position_pub_;

        //// Services ////
        // rclcpp::Client<nav2_msgs::srv::LoadMap>::SharedPtr change_maps_srv_;
        rclcpp::Client<nav2_msgs::srv::ClearEntireCostmap>::SharedPtr clear_costmap_global_srv_;
        rclcpp::Client<nav2_msgs::srv::ClearEntireCostmap>::SharedPtr clear_costmap_local_srv_;
        //timer
        rclcpp::TimerBase::SharedPtr execute_navigation_timer_;
        rclcpp::TimerBase::SharedPtr send_robot_position_timer_;
        //define var
        geometry_msgs::msg::PoseStamped initial_pose_;
        geometry_msgs::msg::PoseWithCovarianceStamped robot_position_;
        geometry_msgs::msg::PoseStamped goal_position_;
        vector<geometry_msgs::msg::PoseStamped> many_goal_position_, robot_position_covered_;
        vector<geometry_msgs::msg::Polygon> polygons;
        nav_msgs::msg::Path path_;
        string mvibot_seri_,mvibot_seri_f_;
        json parameters;
        int status = Finish_;
        int step  = 0;
        string mode;
        int number_of_poses_remaining;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
        result states, state_planner, state_controller ;
};
float navigation_function::getyaw(double data1, double data2){
    geometry_msgs::msg::Quaternion quat_msg;
    double roll, pitch, yaw;
    tf2::Quaternion quat_tf;
    quat_msg.x=0;
    quat_msg.y=0;
    quat_msg.z=data1;
    quat_msg.w=data2;
    tf2::fromMsg(quat_msg, quat_tf);
    tf2::Matrix3x3(quat_tf).getRPY(roll, pitch, yaw);
    return yaw;
} 
double *navigation_function::get_position_tf(string source_frame, string target_frame){
    static double data[4];
    //get position
    static double x,y,z,thz,thw;
    static geometry_msgs::msg::TransformStamped transformStamped;
    try{
        transformStamped = tf_Buffer_->lookupTransform(source_frame,target_frame,tf2::TimePointZero);
        x=transformStamped.transform.translation.x;
        y=transformStamped.transform.translation.y;
        z=transformStamped.transform.translation.z;
        thz=transformStamped.transform.rotation.z;
        thw=transformStamped.transform.rotation.w;
        
    }
    catch (tf2::TransformException &e) {
        x=-1; y=-1; thz=-1; thw=-1;
        RCLCPP_ERROR(this->get_logger(),"Error occured: %s", e.what());
    }
    data[0]=x; data[1]=y; data[2]=thz; data[3]=thw;
    return data;
}
void navigation_function::pub_robot_position(string data){
    std_msgs::msg::String msg;
    msg.data = data;
    robot_position_pub_->publish(msg);
}
void navigation_function::save_robot_position(const std::string& file_path, double x, double y, double thz, double thw){
    std::ofstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << file_path << std::endl;
        return;
    }
    file << "x: "   << x   << std::endl;
    file << "y: "   << y   << std::endl;
    file << "thz: " << thz << std::endl;
    file << "thw: " << thw << std::endl;
    file.close();
}
void navigation_function::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
void navigation_function::pub_stop_robot(){
    static geometry_msgs::msg::Twist stop_robot_;
    stop_robot_.linear.x = 0.0;
    stop_robot_.angular.z = 0.0;
    stop_robot_pub_->publish(stop_robot_);
}
void navigation_function::pub_amcl(float x, float y, float z, float w){
    static geometry_msgs::msg::PoseWithCovarianceStamped amcl_;
    amcl_.header.frame_id="map";
    amcl_.pose.pose.position.x=x;
    amcl_.pose.pose.position.y=y;
    amcl_.pose.pose.orientation.z=z;
    amcl_.pose.pose.orientation.w=w;
    amcl_.pose.covariance[0]=0.25;
    amcl_.pose.covariance[7]=0.25;
    amcl_.pose.covariance[35]=0.06853892326654787;
    pub_amcl_->publish(amcl_);
}
void navigation_function::set_initial_robot(const string& file_path){
    while(pub_amcl_->get_subscription_count()==0){
        RCLCPP_INFO(this->get_logger(),"AMCL is not ready");
        sleep(0.5);
    }
    RCLCPP_INFO(this->get_logger(),"AMCL is ready");
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return;
    }
    string key;
    double value,x,y,thz,thw;
    while (file >> key >> value) {
        if (key == "x:") x = value;
        else if (key == "y:") y = value;
        else if (key == "thz:") thz = value;
        else if (key == "thw:") thw = value;
    }
    file.close();
    pub_amcl(x,y,thz,thw);
}
void navigation_function::pub_function_state_navigation(int st){
    std_msgs::msg::String msg;
    if(st == Active_) msg.data = "active";
    else if(st == Finish_) msg.data = "finish";
    else if(st == Error_) msg.data = "error";
    else if(st == Cancel_) msg.data = "cancel";
    else if(st == Stop_) msg.data = "stop";
    navigation_function_state_pub_->publish(msg);
}
geometry_msgs::msg::PoseStamped navigation_function::get_robot_position(){
    static geometry_msgs::msg::PoseStamped robot_current_pos_;
    robot_current_pos_.header.frame_id = robot_position_.header.frame_id;
    robot_current_pos_.header.stamp = robot_position_.header.stamp;
    robot_current_pos_.pose.position.x = robot_position_.pose.pose.position.x;
    robot_current_pos_.pose.position.y = robot_position_.pose.pose.position.y;
    robot_current_pos_.pose.position.z = robot_position_.pose.pose.position.z;
    robot_current_pos_.pose.orientation.z = robot_position_.pose.pose.orientation.z;
    robot_current_pos_.pose.orientation.w = robot_position_.pose.pose.orientation.w;
    return robot_current_pos_;
}
void navigation_function::navCompleteCoverage(const vector<geometry_msgs::msg::Polygon> &polygons, const string &behavior_tree){
    RCLCPP_INFO(rclcpp::get_logger("NavigateCompleteCorverage"),"wait for 'NavigateCompleteCorverage' action server");
    //wait action server 
    if(!nav_complete_coverage_client_->wait_for_action_server(std::chrono::duration<float>(5))){
        RCLCPP_INFO(rclcpp::get_logger("NavigateCompleteCorverage"), "'NavigateCompleteCorverage' action server not available");
        states = REJECT;
        return;
    }
    //goal message
    auto goal_msg = opennav_coverage_msgs::action::NavigateCompleteCoverage::Goal();
    goal_msg.polygons = polygons;
    goal_msg.behavior_tree=behavior_tree;
    //send goal and receive result//
    rclcpp_action::Client<opennav_coverage_msgs::action::NavigateCompleteCoverage>::SendGoalOptions options;
    options.goal_response_callback=[this](std::shared_ptr<rclcpp_action::ClientGoalHandle<opennav_coverage_msgs::action::NavigateCompleteCoverage>> goal_handle){
        if(!goal_handle){
            RCLCPP_ERROR(rclcpp::get_logger("NavigateCompleteCorverage"),"Goal was rejected by server!");
            send_history("error","NavigateCompleteCorverage was rejected by server!");
            states = REJECT;
        }
        else{
            RCLCPP_INFO(rclcpp::get_logger("NavigateCompleteCorverage"),"Goal was accepted by server, waiting for result");
            send_history("normal","NavigateCompleteCorverage was accepted by server, waiting for result");
            states = ACCEPT;
        }
    };
    options.feedback_callback = [this](std::shared_ptr<rclcpp_action::ClientGoalHandle<opennav_coverage_msgs::action::NavigateCompleteCoverage>>,
                        const std::shared_ptr<const opennav_coverage_msgs::action::NavigateCompleteCoverage::Feedback> feedback) {
        RCLCPP_INFO(rclcpp::get_logger("NavigateCompleteCorverage"), "Received feedback: Current Position (x = %.2f, y = %.2f, z = %.2f, w = %.2f)",
                    feedback->current_pose.pose.position.x,
                    feedback->current_pose.pose.position.y,
                    feedback->current_pose.pose.position.z,
                    feedback->current_pose.pose.orientation.w);
        states = ACTIVE;
    };
    options.result_callback = [this](const rclcpp_action::ClientGoalHandle<opennav_coverage_msgs::action::NavigateCompleteCoverage>::WrappedResult & result) {
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            RCLCPP_INFO(rclcpp::get_logger("NavigateCompleteCorverage"), "NavigateCompleteCorverage succeeded!");
            send_history("normal","NavigateCompleteCorverage succeeded!");
            states = SUCCESS;
        } else {
            string info;
            info = "";
            info += "NavigateCompleteCorverage failed with status: ";
            if(result.code == rclcpp_action::ResultCode::ABORTED){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateCompleteCorverage"), "NavigateCompleteCorverage failed with status: ABORTED");
                info+= "ABORTED";
                states = ERROR;
            }
            else if(result.code == rclcpp_action::ResultCode::CANCELED){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateCompleteCorverage"), "NavigateCompleteCorverage failed with status: CANCELED");
                info+= "CANCELED";
                states = CANCEL;
            }
            else if(result.code == rclcpp_action::ResultCode::UNKNOWN){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateCompleteCorverage"), "NavigateCompleteCorverage failed with status: UNKNOWN");
                info+= "UNKNOWN";
                // states = ERROR;
		states = CANCEL;
            }
            send_history("error",info);
        }
    };
    auto send_goal_future = nav_complete_coverage_client_->async_send_goal(goal_msg,options);
}
void navigation_function::update_polygon(){
    BoostPolygon boost_poly_original, boost_poly_covered;
    BoostMultiPolygon boost_poly_result;
    if (polygons[0].points.size() < 3 || robot_position_covered_.size() < 3) return;
    // 
    for (const auto& pt : polygons[0].points) {
        // create point of Boost from x, y
        boost::geometry::append(boost_poly_original.outer(), BoostPoint(pt.x, pt.y));
    }
    // check polygon is closed
    if (!boost::geometry::equals(boost_poly_original.outer().front(), boost_poly_original.outer().back())) {
        boost_poly_original.outer().push_back(boost_poly_original.outer().front());
    }
    // confirm polygon
    boost::geometry::correct(boost_poly_original);
    //create polygon is covered
    BoostLinestring boost_line;
    for(auto pose : robot_position_covered_){
        boost_line.emplace_back(pose.pose.position.x, pose.pose.position.y);
    }
    bg::convex_hull(boost_line, boost_poly_covered);
    bg::correct(boost_poly_covered);
    // offset brush's radius 
    BoostMultiPolygon offset_poly_covered;
    double r = 0.35;  // offset

    boost::geometry::strategy::buffer::distance_symmetric<double> distance_strategy(r);
    boost::geometry::strategy::buffer::join_round join_strategy(16);
    boost::geometry::strategy::buffer::end_round end_strategy(16);
    boost::geometry::strategy::buffer::point_circle circle_strategy(16);
    boost::geometry::strategy::buffer::side_straight side_strategy;

    bg::buffer(boost_poly_covered, offset_poly_covered,
            distance_strategy, side_strategy,
            join_strategy, end_strategy,
            circle_strategy);
    bg::difference(boost_poly_original, offset_poly_covered, boost_poly_result);
    //covert from boost.geometry to geometry_msgs::msg::Polygon
    polygons.resize(1);
    // double min_area = 1.0; 
    // for (const auto& poly : boost_poly_result) {
    //     double area = bg::area(poly);
    //     geometry_msgs::msg::Polygon ros_poly;
    //     for (const auto& pt : poly.outer()) {
    //         geometry_msgs::msg::Point32 p;
    //         p.x = pt.x();
    //         p.y = pt.y();
    //         ros_poly.points.push_back(p);
    //     }
    //     if(area >= min_area) polygons.push_back(ros_poly);
    // }
    double max_area = 0.0; 
    for (const auto& poly : boost_poly_result) {
        double area = bg::area(poly);
        geometry_msgs::msg::Polygon ros_poly;
        for (const auto& pt : poly.outer()) {
            geometry_msgs::msg::Point32 p;
            p.x = pt.x();
            p.y = pt.y();
            ros_poly.points.push_back(p);
        }
        if(area >= max_area){
            max_area = area;
            polygons[0] = ros_poly;
        }
    }
    cout<<"update polygon: "<<endl;
    for(int i=0; i<polygons[0].points.size();i++){
        cout<<polygons[0].points[i].x<<"||"<<polygons[0].points[i].y<<"||"<<polygons[0].points[i].z<<endl;
    }
    robot_position_covered_.resize(0);
}
void navigation_function::goToPose(const geometry_msgs::msg::PoseStamped &pose, const string &behavior_tree){
    RCLCPP_INFO(rclcpp::get_logger("NavigateToPose"),"wait for 'NaviagteToPose' action server");
    //wait action server 
    if(!nav_to_pose_client_->wait_for_action_server(std::chrono::duration<float>(5))){
        RCLCPP_INFO(rclcpp::get_logger("NavigateToPose"), "'NavigateToPose' action server not available");
        return;
    }
    //goal message
    auto goal_msg = nav2_msgs::action::NavigateToPose::Goal();
    goal_msg.pose=pose;
    goal_msg.behavior_tree=behavior_tree;
    RCLCPP_INFO(rclcpp::get_logger("NavigateToPose"),"Navigating to goal: x = %.2f, y = %.2f", pose.pose.position.x, pose.pose.position.y);
    //send goal and receive result//
    rclcpp_action::Client<nav2_msgs::action::NavigateToPose>::SendGoalOptions options;
    options.goal_response_callback=[this](std::shared_ptr<rclcpp_action::ClientGoalHandle<nav2_msgs::action::NavigateToPose>> goal_handle){
        if(!goal_handle){
            RCLCPP_ERROR(rclcpp::get_logger("NavigateToPose"),"Goal was rejected by server!");
            send_history("error","Goal was rejected by server!");
            states = REJECT;
        }
        else{
            RCLCPP_INFO(rclcpp::get_logger("NavigateToPose"),"Goal was accepted by server, waiting for result");
            send_history("normal","Goal was accepted by server, waiting for result");
            states = ACCEPT;
        }
    };
    options.feedback_callback = [this](std::shared_ptr<rclcpp_action::ClientGoalHandle<nav2_msgs::action::NavigateToPose>>,
                        const std::shared_ptr<const nav2_msgs::action::NavigateToPose::Feedback> feedback) {
        RCLCPP_INFO(rclcpp::get_logger("NavigateToPose"), "Received feedback: Current Position (x = %.2f, y = %.2f, z = %.2f, w = %.2f)",
                    feedback->current_pose.pose.position.x,
                    feedback->current_pose.pose.position.y,
                    feedback->current_pose.pose.position.z,
                    feedback->current_pose.pose.orientation.w);
        states = ACTIVE;
    };
    options.result_callback = [this](const rclcpp_action::ClientGoalHandle<nav2_msgs::action::NavigateToPose>::WrappedResult & result) {
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            RCLCPP_INFO(rclcpp::get_logger("NavigateToPose"), "NavigateToPose succeeded!");
            send_history("normal","NavigateToPose succeeded!");
            states = SUCCESS;
        } else {
            string info;
            info = "";
            info += "Goal failed with status: ";
            if(result.code == rclcpp_action::ResultCode::ABORTED){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateToPose"), "NavigateToPose failed with status: ABORTED");
                info+= "ABORTED";
                states = ERROR;
            }
            else if(result.code == rclcpp_action::ResultCode::CANCELED){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateToPose"), "NavigateToPose failed with status: CANCELED");
                info+= "CANCELED";
                states = CANCEL;
            }
            else if(result.code == rclcpp_action::ResultCode::UNKNOWN){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateToPose"), "NavigateToPose failed with status: UNKNOWN");
                info+= "UNKNOWN";
                states = ERROR;
            }
            send_history("error",info);
        }
    };
    auto send_goal_future = nav_to_pose_client_->async_send_goal(goal_msg,options);
}
void navigation_function::goThroughPoses(const std::vector<geometry_msgs::msg::PoseStamped> &poses, const std::string &behavior_tree){
    RCLCPP_INFO(rclcpp::get_logger("NaviagteThroughPoses"),"wait for 'NaviagteThroughPoses' action server");
    //wait action server 
    if(!nav_through_poses_client_->wait_for_action_server(std::chrono::duration<float>(5))){
        RCLCPP_INFO(rclcpp::get_logger("NavigateThroughPoses"), "'NavigateThroughPoses' action server not available");
    }
    // goal message
    auto goal_msg = nav2_msgs::action::NavigateThroughPoses::Goal();
    goal_msg.poses=poses;
    goal_msg.behavior_tree=behavior_tree;
    //navigating with number of goals
    RCLCPP_INFO(rclcpp::get_logger("NavigateThroughPoses"),"Navigating with %zu goals ...",goal_msg.poses.size());
    //send goal and receive result//
    rclcpp_action::Client<nav2_msgs::action::NavigateThroughPoses>::SendGoalOptions options;
    options.goal_response_callback=[this](std::shared_ptr<rclcpp_action::ClientGoalHandle<nav2_msgs::action::NavigateThroughPoses>> goal_handle){
        if(!goal_handle){
            RCLCPP_ERROR(rclcpp::get_logger("NavigateThroughPoses"),"Goals was rejected by server!");
            send_history("error","Goals was rejected by server!");
            states = REJECT;
        }
        else{
            RCLCPP_INFO(rclcpp::get_logger("NavigateThroughPoses"),"Goals was accepted by server, waiting for result");
            send_history("normal","Goals was accepted by server, waiting for result");
            states = ACCEPT;
        }
    };
    options.feedback_callback = [this](std::shared_ptr<rclcpp_action::ClientGoalHandle<nav2_msgs::action::NavigateThroughPoses>>,
                        const std::shared_ptr<const nav2_msgs::action::NavigateThroughPoses::Feedback> feedback) {
        RCLCPP_INFO(rclcpp::get_logger("NavigateThroughPoses"), "Received feedback: Current Position (x = %.2f, y = %.2f, z = %.2f, w = %.2f)",
                    feedback->current_pose.pose.position.x,
                    feedback->current_pose.pose.position.y,
                    feedback->current_pose.pose.position.z,
                    feedback->current_pose.pose.orientation.w);
        number_of_poses_remaining = feedback->number_of_poses_remaining;
        states = ACTIVE;
    };
    options.result_callback = [this](const rclcpp_action::ClientGoalHandle<nav2_msgs::action::NavigateThroughPoses>::WrappedResult & result) {
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            RCLCPP_INFO(rclcpp::get_logger("NavigateThroughPoses"), "NavigateThroughPoses succeeded!");
            send_history("normal","NavigateThroughPoses succeeded!");
            states = SUCCESS;
        } else {
            string info;
            info = "";
            info += "NavigateThroughPoses failed with status: ";
            if(result.code == rclcpp_action::ResultCode::ABORTED){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateThroughPoses"), "NavigateThroughPoses failed with status: ABORTED");
                info+= "ABORTED";
                states = ERROR;
            }
            else if(result.code == rclcpp_action::ResultCode::CANCELED){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateThroughPoses"), "NavigateThroughPoses failed with status: CANCELED");
                info+= "CANCELED";
                states = CANCEL;
            }
            else if(result.code == rclcpp_action::ResultCode::UNKNOWN){
                RCLCPP_ERROR(rclcpp::get_logger("NavigateThroughPoses"), "NavigateThroughPoses failed with status: UNKNOWN");
                info+= "UNKNOWN";
                states = ERROR;
            }
            send_history("error",info);
        }
    };
    auto send_goal_future=nav_through_poses_client_->async_send_goal(goal_msg, options);
}
void navigation_function::getPathToPose(geometry_msgs::msg::PoseStamped start, geometry_msgs::msg::PoseStamped goal, std::string planner_id, bool use_start){
    state_planner = UNKNOW;
    RCLCPP_INFO(rclcpp::get_logger("ComputePathToPose"),"send a 'computePathToPose' action request");
    if(!compute_path_to_pose_client_->wait_for_action_server(std::chrono::duration<float>(0.2))){
        RCLCPP_INFO(rclcpp::get_logger("ComputePathToPose"), "'computePathToPose' action server is not available, waiting ...");
        return;
    }
    auto goal_msg = nav2_msgs::action::ComputePathToPose::Goal();
    goal_msg.start = start;
    goal_msg.goal = goal;
    goal_msg.planner_id = planner_id;
    goal_msg.use_start = use_start;
    path_ = nav_msgs::msg::Path();

    //send goal and receive respond result
    RCLCPP_INFO(rclcpp::get_logger("ComputePathToPose"),"Sending request");
    RCLCPP_INFO(rclcpp::get_logger("ComputePathToPose"),"Compute Path to goal: x = %.2f, y = %.2f", goal_msg.goal.pose.position.x, goal_msg.goal.pose.position.y);
    rclcpp_action::Client<nav2_msgs::action::ComputePathToPose>::SendGoalOptions options;
    options.goal_response_callback = [this](std::shared_ptr<rclcpp_action::ClientGoalHandle<nav2_msgs::action::ComputePathToPose>> goal_handle){
        if(!goal_handle){
            RCLCPP_ERROR(rclcpp::get_logger("ComputePathToPose"),"ComputePathToPose request was rejected by server");
            state_planner = REJECT;
        }
        else{
            RCLCPP_INFO(rclcpp::get_logger("ComputePathToPose"), "ComputePathToPose request was accepted by server");
            state_planner = ACCEPT;
        }
    };
    options.result_callback = [this](const rclcpp_action::ClientGoalHandle<nav2_msgs::action::ComputePathToPose>::WrappedResult &result){
        if(result.code == rclcpp_action::ResultCode::SUCCEEDED){
            RCLCPP_INFO(rclcpp::get_logger("ComputePathToPose"),"ComputePathToPose succeeded");
            send_history("normal","ComputePathToPose succeeded");
            path_ = result.result->path;
            state_planner = SUCCESS;
        }
        else{
            string info;
            info = "";
            info += "ComputePathToPose failed with status: ";
            if(result.code == rclcpp_action::ResultCode::ABORTED){
                RCLCPP_ERROR(rclcpp::get_logger("ComputePathToPose"), "ComputePathToPose failed with status: ABORTED");
                info+= "ABORTED";
                state_planner = ERROR;
            }
            else if(result.code == rclcpp_action::ResultCode::CANCELED){
                RCLCPP_ERROR(rclcpp::get_logger("ComputePathToPose"), "ComputePathToPose failed with status: CANCELED");
                info+= "CANCELED";
                state_planner = CANCEL; 
            }
            else if(result.code == rclcpp_action::ResultCode::UNKNOWN){
                RCLCPP_ERROR(rclcpp::get_logger("ComputePathToPose"), "ComputePathToPose failed with status: UNKNOWN");
                info+= "UNKNOWN";
                state_planner = ERROR;
            }
            send_history("error",info);
        }     
    };
    auto send_goal_future = compute_path_to_pose_client_->async_send_goal(goal_msg, options);
}
void navigation_function::followPath(const nav_msgs::msg::Path &path, const std::string &controller_id, const std::string &goal_checker_id){
    state_controller = UNKNOW;
    RCLCPP_INFO(rclcpp::get_logger("FollowPath"), "Waiting for 'FollowPath' action server");
    // wait action server
    if (!follow_path_client_->wait_for_action_server(std::chrono::duration<float>(5))) {
        RCLCPP_INFO(rclcpp::get_logger("FollowPath"), "'FollowPath' action server not available");
        return;
    }
    // goal message
    auto goal_msg = nav2_msgs::action::FollowPath::Goal();
    goal_msg.path = path;
    goal_msg.controller_id = controller_id;
    goal_msg.goal_checker_id = goal_checker_id;
    RCLCPP_INFO(rclcpp::get_logger("FollowPath"), "Executing path...");
    // send goal and receive result
    rclcpp_action::Client<nav2_msgs::action::FollowPath>::SendGoalOptions options;
    options.goal_response_callback=[this](std::shared_ptr<rclcpp_action::ClientGoalHandle<nav2_msgs::action::FollowPath>> goal_handle){
        if(!goal_handle){
            RCLCPP_ERROR(rclcpp::get_logger("FollowPath"),"'Follow Path' was rejected by server!");
            state_controller = REJECT;
        }
        else{
            RCLCPP_INFO(rclcpp::get_logger("FollowPath"),"'Follow Path' was accepted by server, waiting for result");
            state_controller = ACCEPT;
        }
    };
    options.feedback_callback = [this](std::shared_ptr<rclcpp_action::ClientGoalHandle<nav2_msgs::action::FollowPath>>,
                        const std::shared_ptr<const nav2_msgs::action::FollowPath::Feedback> feedback) {
        RCLCPP_INFO(rclcpp::get_logger("FollowPath"), "'Follow Path' received feedback with distance to goal: %.2f", feedback->distance_to_goal);
    };
    options.result_callback = [this](const rclcpp_action::ClientGoalHandle<nav2_msgs::action::FollowPath>::WrappedResult & result) {
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            RCLCPP_INFO(rclcpp::get_logger("FollowPath"), "'Follow Path' succeeded!");
            state_controller = SUCCESS;
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("FollowPath"), "'Follow Path' failed with status: %d", static_cast<int>(result.code));
            state_controller = ERROR;
        }
    };
    auto send_goal_future = follow_path_client_->async_send_goal(goal_msg,options);
}
void navigation_function::cancel_navCompleteCoverage(){
    RCLCPP_INFO(rclcpp::get_logger("NavigateCompleteCorverage"), "Canceling naviagte complete coverage");
    auto cancel_goal = nav_complete_coverage_client_->async_cancel_all_goals();
}
void navigation_function::cancel_navToPose(){
    RCLCPP_INFO(rclcpp::get_logger("NavigateToPose"), "Canceling naviagte to pose");
    auto cancel_goal = nav_to_pose_client_->async_cancel_all_goals();
}
void navigation_function::cancel_navThroughPoses(){
    RCLCPP_INFO(rclcpp::get_logger("NavigateThroughPoses"), "Canceling navigate through pose");
    auto cancel_goal = nav_through_poses_client_->async_cancel_all_goals();
}
void navigation_function::cancel_getPathToPose(){
    RCLCPP_INFO(rclcpp::get_logger("ComputePathToPose"), "Canceling get path to pose");
    auto cancel_goal = compute_path_to_pose_client_->async_cancel_all_goals();
}
void navigation_function::cancel_followPath(){
    RCLCPP_INFO(rclcpp::get_logger("FollowPath"), "Canceling follow path");
    auto cancel_goal = follow_path_client_->async_cancel_all_goals();
}
void navigation_function::clearLocalCostmap(){
    RCLCPP_INFO(rclcpp::get_logger("Navigation"), "Clear Local costmap");
    if(!clear_costmap_local_srv_->wait_for_service(std::chrono::duration<float>(0.5))){
        RCLCPP_INFO(rclcpp::get_logger("Navigation"),"Clear Local costmap service not available, waiting ...");
        return;
    }
    //send request
    auto req = std::make_shared<nav2_msgs::srv::ClearEntireCostmap_Request>();
    auto clear_local_costmap_callback = [this](rclcpp::Client<nav2_msgs::srv::ClearEntireCostmap>::SharedFuture future){
        auto result_code = future.wait_for(std::chrono::seconds(0));
        if (result_code == std::future_status::ready) {
            RCLCPP_INFO(this->get_logger(), "Local costmap cleared successfully!");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Local costmap cleared fail");
        }
    };
    auto future = clear_costmap_local_srv_->async_send_request(req, clear_local_costmap_callback);
}
void navigation_function::clearGlobalCostmap(){
    RCLCPP_INFO(rclcpp::get_logger("Navigation"), "Clear Global costmap");
    if(!clear_costmap_global_srv_->wait_for_service(std::chrono::duration<float>(0.5))){
        RCLCPP_INFO(rclcpp::get_logger("Navigation"),"Clear Global costmap service not available, waiting ...");
    }
    //send request
    auto req = std::make_shared<nav2_msgs::srv::ClearEntireCostmap_Request>();
    auto clear_global_costmap_callback = [this](rclcpp::Client<nav2_msgs::srv::ClearEntireCostmap>::SharedFuture future){
        auto result_code = future.wait_for(std::chrono::seconds(0));
        if (result_code == std::future_status::ready) {
            RCLCPP_INFO(this->get_logger(), "Global costmap cleared successfully!");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Global costmap cleared fail");
        }
    };
    auto future = clear_costmap_global_srv_->async_send_request(req, clear_global_costmap_callback);
}
void navigation_function::clearAllCostmap(){
    this->clearGlobalCostmap();
    this->clearLocalCostmap();
}
void navigation_function::pub_user_path(const nav_msgs::msg::Path &path){
    pub_user_path_->publish(path);
    RCLCPP_INFO(this->get_logger(),"publish path to goal");
}
void navigation_function::process_data(){
    mode = parameters["mode"].get<string>();
    if(mode == "go_to_pose"){
        goal_position_.header.frame_id = "map";
        goal_position_.header.stamp = this->get_clock()->now();
        goal_position_.pose.position.x = std::stod(parameters["goal_position"][0].value("x","0.0"));
        goal_position_.pose.position.y = std::stod(parameters["goal_position"][0].value("y","0.0"));
        goal_position_.pose.position.z = 0.0;
        goal_position_.pose.orientation.x = 0.0;
        goal_position_.pose.orientation.y = 0.0;
        goal_position_.pose.orientation.z = std::stod(parameters["goal_position"][0].value("z","0.0"));
        goal_position_.pose.orientation.w = std::stod(parameters["goal_position"][0].value("w","1.0"));
    }
    else if(mode == "line_follow"){
        goal_position_.header.frame_id = "map";
        goal_position_.header.stamp = this->get_clock()->now();
        goal_position_.pose.position.x = std::stod(parameters["goal_position"][0].value("x","0.0"));
        goal_position_.pose.position.y = std::stod(parameters["goal_position"][0].value("y","0.0"));
        goal_position_.pose.position.z = 0.0;
        goal_position_.pose.orientation.x = 0.0;
        goal_position_.pose.orientation.y = 0.0;
        goal_position_.pose.orientation.z = std::stod(parameters["goal_position"][0].value("z","0.0"));
        goal_position_.pose.orientation.w = std::stod(parameters["goal_position"][0].value("w","1.0"));
    }
    else if(mode == "go_through_poses"){
        many_goal_position_.resize(0);
        for (const auto& goal_json : parameters["goal_position"]){
            geometry_msgs::msg::PoseStamped pose;
            pose.header.frame_id = "map";
            pose.header.stamp = this->get_clock()->now();
            pose.pose.position.x = std::stod(goal_json.value("x", "0.0"));
            pose.pose.position.y = std::stod(goal_json.value("y", "0.0"));
            pose.pose.position.z = 0.0;
            pose.pose.orientation.x = 0.0;
            pose.pose.orientation.y = 0.0;
            pose.pose.orientation.z = std::stod(goal_json.value("z", "0.0"));
            pose.pose.orientation.w = std::stod(goal_json.value("w", "1.0"));
            many_goal_position_.push_back(pose);
        }
    }
    else if(mode == "navigate_coverage"){
        /*//only polygon
        polygons.resize(0);
        polygons.resize(1);
        for(const auto& area_json : parameters["area"]){
            geometry_msgs::msg::Point32 pt;
            pt.x = std::stod(area_json.value("x","0.0"));
            pt.y = std::stod(area_json.value("y","0.0"));
            pt.z = 0.0;
            polygons[0].points.push_back(pt);
        }
        polygons[0].points.push_back(polygons[0].points[0]);
        //only polygon */
        //many polygons
        polygons.clear();
        // area: array of polygons
        if (parameters.contains("area") && parameters["area"].is_array()) {
            polygons.resize(parameters["area"].size());
            size_t poly_idx = 0;
            for (const auto& polygon_json : parameters["area"]) {
                // polygon_json: array of points
                if (!polygon_json.is_array()) {
                    continue;
                }
                for (const auto& point_json : polygon_json) {
                    geometry_msgs::msg::Point32 pt;
                    pt.x = std::stod(point_json.value("x", "0.0"));
                    pt.y = std::stod(point_json.value("y", "0.0"));
                    pt.z = 0.0;

                    polygons[poly_idx].points.push_back(pt);
                }
                // Close polygon (push first point again)
                if (!polygons[poly_idx].points.empty()) {
                    polygons[poly_idx].points.push_back(
                        polygons[poly_idx].points.front()
                    );
                }
                poly_idx++;
            }
        }
        //many polygons
    }
}
int navigation_function::action(){
    //declare var
    static int complete_position = 0;
    static float x=0, y=0, z=0, w=0;
    static float x1=0, y1=0, z1=0, w1=0;
    static geometry_msgs::msg::PoseStamped robot_current_position;
    static float dis;
    static float angle1, angle2;
    static int t = 0;

    //check active status 
    if(status == Active_){
        robot_current_position = get_robot_position();
        x1 = robot_current_position.pose.position.x;
        y1 = robot_current_position.pose.position.y;
        z1 = robot_current_position.pose.orientation.z;
        w1 = robot_current_position.pose.orientation.w;
        if(mode == "go_to_pose"){
            //Kiem tra vi tri robot voi muc tieu
            x = goal_position_.pose.position.x;
            y = goal_position_.pose.position.y;
            z = goal_position_.pose.orientation.z;
            w = goal_position_.pose.orientation.w;
            dis = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
            angle1 = getyaw(z,w);
            angle2 = getyaw(z1,w1);
            if(dis<=0.15){
                complete_position=1;
                if(fabs(sin(angle2)-sin(angle1))<=0.02 && fabs(cos(angle2)-cos(angle1))<=0.02) { //0.1 //0.08 only sin //0.05
                    complete_position=2;
                }
            }else complete_position=0;
            //kiem tra trang thai dang hoat dong
            if(step == 0){
                //send goal
                clearAllCostmap();
                goToPose(goal_position_);
                step = 1;
                return Active_;
            }
            else if(step == 1){
                //check states
                if(states == SUCCESS){
                    cancel_navToPose();
                    goal_position_ = geometry_msgs::msg::PoseStamped();
                    path_ = nav_msgs::msg::Path();
                    step = 0;
                    request = 0;
                    status = Finish_;
		            pub_user_path(path_);
                    return Finish_;
                }
                else if(states == REJECT){
                    cancel_navToPose();
                    step = 0;
                    return Active_;
                }
                else if(states == ERROR || states == CANCEL){
                    if(complete_position == 1){
                        goal_position_ = get_robot_position();
                        step = 0;
                        return Active_;
                    }
                    else if(complete_position == 2){
                        cancel_navToPose();
                        goal_position_ = geometry_msgs::msg::PoseStamped();
                        path_ = nav_msgs::msg::Path();
                        step = 0;
                        request = 0;
                        status = Finish_;
			            pub_user_path(path_);
                        return Finish_;
                    }
                    else{
                        cancel_navToPose();
                        step = 0;
                        return Active_;
                    }
                }
                else return Active_;
            }
        }
        else if(mode == "line_follow"){
            //Kiem tra vi tri robot voi muc tieu
            x = goal_position_.pose.position.x;
            y = goal_position_.pose.position.y;
            z = goal_position_.pose.orientation.z;
            w = goal_position_.pose.orientation.w;
            dis = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
            angle1 = getyaw(z,w);
            angle2 = getyaw(z1,w1);
            if(dis<=0.15){
                complete_position=1;
                if(fabs(sin(angle2)-sin(angle1))<=0.02 && fabs(cos(angle2)-cos(angle1))<=0.02) { //0.1 //0.08 only sin //0.05
                    complete_position=2;
                }
            }else complete_position=0;
            //kiem tra trang thai dang hoat dong
            if(step == 0){
                //send goal
                clearAllCostmap();
                step = 1;
                return Active_;
            }
            else if(step == 1){
                getPathToPose(robot_current_position,goal_position_);
                step = 2;
                return Active_;
            }
            else if(step == 2){
                if(state_planner == SUCCESS){
                    followPath(path_);
                    step = 3;
                    return Active_;
                }
                else {
                    step == 0;
                    return Active_;
                }
            }
            else if(step == 3){
                if(state_controller == SUCCESS){
                    cancel_getPathToPose();
                    cancel_followPath();
                    goal_position_ = geometry_msgs::msg::PoseStamped();
                    path_ = nav_msgs::msg::Path();
                    step = 0;
                    request = 0;
                    status = Finish_;
		            pub_user_path(path_);
                    return Finish_;
                }
                else if(state_controller == REJECT){
                    cancel_getPathToPose();
                    cancel_followPath();
                    step = 0;
                    return Active_;
                }
                else if(state_controller == ERROR || states == CANCEL){
                    if(complete_position == 1){
                        goal_position_ = get_robot_position();
                        step = 0;
                        return Active_;
                    }
                    else if(complete_position == 2){
                        cancel_getPathToPose();
                        cancel_followPath();
                        goal_position_ = geometry_msgs::msg::PoseStamped();
                        path_ = nav_msgs::msg::Path();
                        step = 0;
                        request = 0;
                        status = Finish_;
			            pub_user_path(path_);
                        return Finish_;
                    }
                    else{
                        cancel_getPathToPose();
                        cancel_followPath();
                        step = 0;
                        return Active_;
                    }
                }
                else return Active_;
            }
        }
        else if(mode == "go_through_poses"){
            //Kiem tra vi tri robot voi muc tieu
            x = many_goal_position_[many_goal_position_.size()-1].pose.position.x;
            y = many_goal_position_[many_goal_position_.size()-1].pose.position.y;
            z = many_goal_position_[many_goal_position_.size()-1].pose.orientation.z;
            w = many_goal_position_[many_goal_position_.size()-1].pose.orientation.w;
            dis = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
            angle1 = getyaw(z,w);
            angle2 = getyaw(z1,w1);
            if(dis<=0.15){
                complete_position=1;
                if(fabs(sin(angle2)-sin(angle1))<=0.02 && fabs(cos(angle2)-cos(angle1))<=0.02) { //0.1 //0.08 only sin //0.05
                    complete_position=2;
                }
            }else complete_position=0;
            //kiem tra trang thai dang hoat dong
            if(step == 0){
                //send goals
                clearAllCostmap();
                goThroughPoses(many_goal_position_);
                step = 1;
                return Active_;
            }
            else if(step == 1){
                //check states
                if(states == SUCCESS){
                    cancel_navThroughPoses();
                    many_goal_position_.resize(0);
                    path_ = nav_msgs::msg::Path();
                    step = 0;
                    request = 0;
                    status = Finish_;
                    return Finish_;
                }
                else if(states == REJECT){
                    cancel_navThroughPoses();
                    step = 0;
                    return Active_;
                }
                else if(states == ERROR || states == CANCEL){
                    if(complete_position==1){
                        many_goal_position_.resize(1);
                        many_goal_position_[0] = get_robot_position();
                        step = 0;
                        return Active_;
                    }
                    else if(complete_position == 2){
                        cancel_navThroughPoses();
                        many_goal_position_.resize(0);
                        path_ = nav_msgs::msg::Path();
                        pub_user_path(path_);
                        step = 0;
                        request = 0;
                        status = Finish_;
                        return Finish_;
                    }
                    else{
                        //update many_goal_position
                        many_goal_position_.erase(many_goal_position_.begin(), many_goal_position_.end() - number_of_poses_remaining);
                        step = 0;
                        return Active_;
                    }
                }
                else return Active_;
            }
        }
        else if(mode == "navigate_coverage"){
            //send covered pose
            t++;
            if(t>=20){
                covered_pose_pub_->publish(robot_current_position);
                robot_position_covered_.push_back(robot_current_position);
                t = 0;
            }
            //kiem tra trang thai dang hoat dong
            if(step == 0){
                //send goal
                clearAllCostmap();
                navCompleteCoverage(polygons);
                step = 1;
                return Active_;
            }
            else if(step == 1){
                //check state of active
                if(states == REJECT || states == CANCEL){
                    cancel_navCompleteCoverage();
                    step = 0;
                    return Active_;
                }
                else if(states == ERROR){
                    //update polygon
                    cancel_navCompleteCoverage();
                    //update_polygon();
                    step = 0;
		            //request = 0;
		            //status = Error_;
                    //return Error_;
		            return Active_;
                }
                else if(states == SUCCESS){
                    cancel_navCompleteCoverage();
                    polygons.resize(0);
                    robot_position_covered_.resize(0);
                    path_ = nav_msgs::msg::Path();
                    step = 0;
                    request = 0;
                    status = Finish_;
		            pub_user_path(path_);
                    return Finish_;
                }
                else return Active_;
            }
        }
        else return status;
    }
    else{
        step = 0;
        return status;
    }
}