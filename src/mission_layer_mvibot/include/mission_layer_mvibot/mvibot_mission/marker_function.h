#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/set_get_param.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
class marker_function : public rclcpp::Node{
    public:
        marker_function(const string &node_name , const string &sub_namespace) : rclcpp::Node(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            //transform
            tf_Buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
            tf_Listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_Buffer_);
            tf_Broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
            //init publisher
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            marker_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("marker_function_state",1);
            cmd_vel_pub_= this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",1);
            //init service client
            get_footprint_local_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("local_costmap/local_costmap/get_parameters");
            //init subscriber
            //
            auto scan_callback = [this](sensor_msgs::msg::LaserScan msg) ->void {
                scan_safe=msg;
            };
            laser_scan_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan",qos_profile,scan_callback);
            //
            auto marker_info_callback = [this](std_msgs::msg::String msg)->void{
                parameters = json::parse(msg.data);
                process_data();
                request = 1;
                step = 0;
            };
            marker_info_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/marker_info", qos_profile, marker_info_callback);
            //
            auto marker_function_status_callback = [this](std_msgs::msg::String msg)->void{
                cout<<"marker|received request,status"<<endl;
                if(msg.data == "active"){
                    request = 1;
                    status = Active_;
                }
                else if(msg.data == "stop") {
                    request = 1;
                    status = Stop_;
                }
                else if(msg.data == "error") {
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
            marker_function_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/marker_function_status", qos_profile, marker_function_status_callback);
            //init timer
            //
            auto action_timer_callback = [this]()->void{
                //get position robot
                robot_position = get_position(mvibot_seri_f_+"/odom", mvibot_seri_f_+"/base_footprint");
                cout<<"marker|request:"<<request<<"|state:"<<status<<endl;
                if(request == 1){
                    int res;
                    res = action();
                    pub_function_state_marker(res);
                }
            };
            action_timer_ = this->create_wall_timer(50ms, action_timer_callback);
        }
        void send_history(string status, string info);
        void pub_function_state_marker(int st);
        void process_data();
        int action();
        void pub_cmd_vel(float v, float w);
        double getyaw(geometry_msgs::msg::Quaternion quat_msg);
        double *get_position(string name1, string name2);
        int caculate_transforms_ofset();
        void send_tranform(double x, double y, double z, double w, string  name1, string name2);
        int check_send_transforms_tf_frame();
        int compare_pose(double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2, double thresold_position, double thresold_angle);
        int tranfrom_pose_marker(int mode, string source_frame, string target_frame);
        int check_first_tranfrom_pose_marker();
        int get_footprint();
        int check_safe();
        int move_to_goal();
    private:
        //declare var
        string mvibot_seri_, mvibot_seri_f_;
        json parameters;
        int status = Finish_;
        int step = 0;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
        sensor_msgs::msg::LaserScan scan_safe;
        string marker_type;
        //
        double x_set=0;
        double y_set=0;
        double z_set=0;
        double w_set=1;
        vector<geometry_msgs::msg::Pose> my_pose;
        vector<geometry_msgs::msg::Pose> my_pose2;
        geometry_msgs::msg::PoseStamped pose_o,pose_n;
        geometry_msgs::msg::PoseStamped pose_o_robot,pose_n_robot;
        double *robot_position;
        double *robot_position_get;
        // offset transfrom
        double off_set_dis=0;
        double off_set_angle=0;
        //
        int safe = 0;
        float  x1_footprint,y1_footprint,x2_footprint,y2_footprint;
        float  safe_x1=0.5,safe_x2=0.5,safe_y1=0.2,safe_y2=0.2;
        //declare tranform
        std::unique_ptr<tf2_ros::Buffer> tf_Buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_Listener_{nullptr};
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_Broadcaster_;
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr marker_function_state_pub_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr marker_info_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr marker_function_status_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan_sub_;
        //service
        rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr get_footprint_local_client_;
        //declare timer
        rclcpp::TimerBase::SharedPtr action_timer_;
};
void marker_function::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
void marker_function::pub_cmd_vel(float v, float w){
    static geometry_msgs::msg::Twist cmd_msg;
    static float creat_fun = 0;
    if(creat_fun == 1){
        if(status != Active_){
            v=0;
            w=0;
        }
        cmd_msg.linear.x = (double)v;
        cmd_msg.angular.z = (double)w;
        cmd_vel_pub_->publish(cmd_msg);
    }
    else creat_fun = 1;
}
void marker_function::pub_function_state_marker(int st){
    std_msgs::msg::String msg;
    if(st == Active_) msg.data = "active";
    else if(st == Finish_) msg.data = "finish";
    else if(st == Error_) msg.data = "error";
    else if(st == Cancel_) msg.data = "cancel";
    else if(st == Stop_) msg.data = "stop";
    else if(st == True_) msg.data = "true";
    else if(st == False_) msg.data = "false";
    marker_function_state_pub_->publish(msg);
}
void marker_function::process_data(){
    // cout<<parameters<<endl;
    marker_type = parameters["marker_type"].get<string>();
    if(parameters["safe_x1"].get<string>()!= "") safe_x1 = stof(parameters["safe_x1"].get<string>());
    if(parameters["safe_x2"].get<string>()!= "") safe_x2 = stof(parameters["safe_x2"].get<string>());
    if(parameters["safe_y1"].get<string>()!= "") safe_y1 = stof(parameters["safe_y1"].get<string>());
    if(parameters["safe_y2"].get<string>()!= "") safe_y2 = stof(parameters["safe_y2"].get<string>());
    if(marker_type == "none_marker_dis"){
        off_set_dis = stof(parameters["off_set_dis"].get<string>());
    }
    else if(marker_type == "none_marker_angle"){
        off_set_angle = stof(parameters["off_set_angle"].get<string>());
    }
}
double marker_function::getyaw(geometry_msgs::msg::Quaternion quat_msg){
    //get angle around Z
    double roll, pitch, yaw;
    tf2::Quaternion quat_tf;
    tf2::fromMsg(quat_msg, quat_tf);
    tf2::Matrix3x3(quat_tf).getRPY(roll, pitch, yaw);
    return yaw;
}
double *marker_function::get_position(string name1, string name2){
    static double data[6];
    //get position
    static double x,y,z,thz,thw;
    static double sec=0,nsec=0;
    static geometry_msgs::msg::TransformStamped transformStamped;
    try{
        transformStamped = tf_Buffer_->lookupTransform(name1,name2,tf2::TimePointZero,tf2::durationFromSec(0.1));
        x=transformStamped.transform.translation.x;
        y=transformStamped.transform.translation.y;
        z=transformStamped.transform.translation.z;
        thz=transformStamped.transform.rotation.z;
        thw=transformStamped.transform.rotation.w;
        sec=(double)transformStamped.header.stamp.sec;
        nsec=(double)transformStamped.header.stamp.nanosec;
    }
    catch (tf2::TransformException &e) {
        x=-1; y=-1; thz=-1; thw=-1; sec=0; nsec=0;
        RCLCPP_ERROR(this->get_logger(),"Error occured: %s", e.what());
    }
    data[0]=x; data[1]=y; data[2]=thz; data[3]=thw; data[4]=sec; data[5]=nsec;
    return data;
}
int marker_function::caculate_transforms_ofset(){
    static int value_return;
    value_return=0;
    // creat pose for marker dis or angle
    my_pose.resize(1);
    if(marker_type=="none_marker_dis"){
        my_pose[0].position.x=off_set_dis;
        my_pose[0].position.y=0;
        my_pose[0].position.z=0;
        //
        my_pose[0].orientation.x=0;
        my_pose[0].orientation.y=0;
        my_pose[0].orientation.z=0;
        my_pose[0].orientation.w=1;
    }else if(marker_type=="none_marker_angle"){
        my_pose[0].position.x=0;
        my_pose[0].position.y=0;
        my_pose[0].position.z=0;
        //
        //static geometry_msgs::msg::Quaternion quat;
        //quat=tf::createQuaternionMsgFromYaw(off_set_angle/180*M_PI);
        static tf2::Quaternion quat;
        quat.setEuler(0,0,off_set_angle/180*M_PI);
        static geometry_msgs::msg::Quaternion quat_msg;
        quat_msg = tf2::toMsg(quat);
        my_pose[0].orientation=quat_msg;
    }
    // caculator tranfom
    static double theta;
    my_pose2.resize(2);
    theta=getyaw(my_pose[0].orientation);
    // origin pose (pose o)
    my_pose2[0]=my_pose[0];
    // tranfrom pose (pose n)
    my_pose2[1]=my_pose[0];
    //        
    
    // check position robot with frame odom
    if(robot_position[0]!=-1 || robot_position[1]!=-1 || robot_position[2]!=-1 || robot_position[3]!=-1){
        value_return=1;
        x_set=robot_position[0];
        y_set=robot_position[1];
        z_set=robot_position[2];
        w_set=robot_position[3];
        std::cout<<x_set<<"|"<<y_set<<"|"<<z_set<<"|"<<w_set<<endl;
        //
    }
    else{
        value_return=0;
        std::cout<<"Robot position not have !"<<endl;
    }
    return value_return;
}
void marker_function::send_tranform(double x, double y, double z, double w, string  name1, string name2){
    static geometry_msgs::msg::TransformStamped transformStamped;
    transformStamped.header.stamp = this->get_clock()->now();
    transformStamped.header.frame_id = name1;
    transformStamped.child_frame_id = name2;

    transformStamped.transform.translation.x = x;
    transformStamped.transform.translation.y = y;
    transformStamped.transform.translation.z = 0;

    transformStamped.transform.rotation.x = 0;
    transformStamped.transform.rotation.y = 0;
    transformStamped.transform.rotation.z = z;
    transformStamped.transform.rotation.w = w;
    tf_Broadcaster_->sendTransform(transformStamped);
}
int marker_function::compare_pose(double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2, double thresold_position, double thresold_angle){
    geometry_msgs::msg::Pose pose_1,pose_2;
    //
    // std::cout<<x1<<"|"<<y1<<"|"<<z1<<"|"<<w1<<endl;
    // std::cout<<x2<<"|"<<y2<<"|"<<z2<<"|"<<w2<<endl;       
    if(sqrt(pow(x2-x1,2)+pow(y2-y1,2))<=thresold_position){
        if(sqrt(pow(z2-z1,2)+pow(w2-w1,2))<=thresold_angle){
            return 1;
        }   
    }
    return 0;
}
int marker_function::check_send_transforms_tf_frame(){
    static int value_return;
    // check tranfrom is true
    robot_position_get=get_position(mvibot_seri_f_+"/odom",mvibot_seri_f_+"/base_marker");
    //
    value_return=0;
    if(compare_pose(x_set,y_set,z_set,w_set,robot_position_get[0],robot_position_get[1],robot_position_get[2],robot_position_get[3],0.05000,0.05000)) value_return=1;
    return value_return;
}
int marker_function::tranfrom_pose_marker(int mode, string source_frame, string target_frame){
    static int value_return;
    static geometry_msgs::msg::TransformStamped target;
    value_return=0;
    try {             
        target=tf_Buffer_->lookupTransform(mvibot_seri_f_+"/"+target_frame, mvibot_seri_f_+"/"+source_frame, tf2::TimePointZero, tf2::durationFromSec(0.1));
        if(mode==1){
            pose_o.header.stamp=target.header.stamp;
            pose_n.header.stamp=target.header.stamp;
            //
            pose_o.pose=my_pose2[0];
            pose_n.pose=my_pose2[1];
            //
            pose_o.header.frame_id=mvibot_seri_f_+"/"+source_frame;
            pose_n.header.frame_id=mvibot_seri_f_+"/"+source_frame;
            //
            tf2::doTransform(pose_o, pose_o_robot, target);
            tf2::doTransform(pose_n, pose_n_robot, target);
        }
        value_return=1;
    } catch(tf2::TransformException &e){
        RCLCPP_ERROR(this->get_logger(),"Error occured1: %s ", e.what());
        value_return=0;
    }
    return value_return;
}
int marker_function::check_first_tranfrom_pose_marker(){
    static int value_return;
    static double xo1,yo1,xo2,yo2;
    static double zo1,wo1,zo2,wo2;
    //
    xo1=pose_o.pose.position.x;
    yo1=pose_o.pose.position.y;
    zo1=pose_o.pose.orientation.z;
    wo1=pose_o.pose.orientation.w;
    //
    xo2=pose_o_robot.pose.position.x;
    yo2=pose_o_robot.pose.position.y;
    zo2=pose_o_robot.pose.orientation.z;
    wo2=pose_o_robot.pose.orientation.w;   
    //
    value_return=0;
    if(compare_pose(xo1,yo1,zo1,wo1,xo2,yo2,zo2,wo2,0.05000,0.05000)) value_return=1;
    else value_return=0;
    return value_return;
}
int marker_function::get_footprint(){
    //
    static bool wait_callback = false;
    static string footprint_string = "";
    if(wait_callback) return 0;
    if(footprint_string.empty()){
        cout<<"marker|before send footprint"<<endl;
        get_param<std::string>(get_footprint_local_client_,"footprint",
            [&](std::optional<std::string> v){
                if (!v.has_value()) {
                    RCLCPP_ERROR(this->get_logger(), "footprint not found");
                    footprint_string = false;
                    return;
                }
                else{
                    footprint_string = v.value();
                    RCLCPP_INFO(this->get_logger(), "Footprint received: %s", footprint_string.c_str());
                }
                wait_callback = false;
            }
        );
        cout<<"marker|after send footprint"<<endl;
        wait_callback = true;
        return 0;
    }
    // cout<< "marker|footprint: "<<footprint_string<<endl;
    //
    string footprint_string_1;
    footprint_string_1 = "";
    for(size_t i=0; i<footprint_string.length();i++){
        if(footprint_string[i] != '[' && footprint_string[i] != ']') footprint_string_1 += footprint_string[i];
    }
    string_Iv2 footprint_string_2;
    footprint_string_2.detect(footprint_string_1,"",",","");
    for(size_t i=0;i<footprint_string_2.data1.size();i=i+2){
        if(stof_f(footprint_string_2.data1[i])>0) x2_footprint=stof_f(footprint_string_2.data1[i]);
        if(stof_f(footprint_string_2.data1[i])<0) x1_footprint=stof_f(footprint_string_2.data1[i]);
    }
    for(size_t i=1;i<footprint_string_2.data1.size();i=i+2){
        if(stof_f(footprint_string_2.data1[i]) >0) y2_footprint=stof_f(footprint_string_2.data1[i]);
        if(stof_f(footprint_string_2.data1[i]) <0) y1_footprint=stof_f(footprint_string_2.data1[i]);
    }
    std::cout<<x1_footprint<<"|"<<y1_footprint<<"|"<<x2_footprint<<"|"<<y2_footprint<<endl;
    footprint_string.clear();
    return 1;
}
int marker_function::check_safe(){
    static int free_space;
    free_space=0;
    for(size_t i=0;i<scan_safe.ranges.size();i++){
        static float x,y,theta;
        theta=scan_safe.angle_min+i*scan_safe.angle_increment;
        x=scan_safe.ranges[i]*cos(theta);
        y=scan_safe.ranges[i]*sin(theta);
        //check safe
        if(x>x1_footprint-safe_x1 && x<=x2_footprint+safe_x2){
            if(y>=y1_footprint-safe_y1 && y<=y2_footprint+safe_y2){
                if(!((x>x1_footprint && x<x2_footprint) && (y>y1_footprint && y<y2_footprint))){
                    std::cout<<"OB"<<endl;
                    std::cout<<x<<"|"<<y<<endl;
                    free_space=1;
                    break;
                }
            }
        }
        //them
        else{
            // if(x>x1_footprint-1 && x<=x1_footprint-0.5 && x<x2_footprint+1 && x>=x2_footprint+0.5) free_space = 3;
            // else if (x>x1_footprint-0.5 && x<x2_footprint+0.5) free_space = 2;
            free_space = 0;
        }
        //them
    }
    return free_space;
}
int marker_function::move_to_goal(){
    static int value_return;
    static float v,w;
    value_return = 0;
    std::cout<<"move to postion pose_n:"<<endl;
    std::cout<<"_x:"<<pose_n_robot.pose.position.x;
    std::cout<<"|_y:"<<pose_n_robot.pose.position.y;
    std::cout<<"|_theta:"<<atan2(pose_n_robot.pose.position.y,pose_n_robot.pose.position.x)/M_PI*180<<endl;
    //
    static double dis,angle;
    static double x,y;
    x=pose_n_robot.pose.position.x;
    y=pose_n_robot.pose.position.y;
    if(marker_type=="none_marker_dis"){
        // angle=getyaw(pose_n_robot.pose.orientation);
        dis=fabs(x);
        off_set_dis=x;
        // if(angle>M_PI*1/2) angle=angle-M_PI;
        // if(angle<-M_PI*1/2) angle=angle+M_PI;
        v=0;
        w=0;
        if(fabs(dis)<=0.0075){ // 0.005 |r==0
            value_return=1;
            v=0;
            w=0;
            pub_cmd_vel(0,0);
        }
        else{
            int k;
            if(x>0) k=1;
            if(x<0) k=-1;
            if(fabs(dis)>=0.6)  v=0.3*k;
            else if(fabs(dis)<0.6 && fabs(dis)>=0.4) v=0.25*k;
            else if(fabs(dis)<0.4 && fabs(dis)>=0.2) v=0.15*k;
            else if(fabs(dis)<0.2 && fabs(dis)>=0.1) v=0.08*k;
            else if(fabs(dis)<0.1 && fabs(dis)>=0.05) v=0.04*k;
            else if(fabs(dis)<0.05 && fabs(dis)>=0.03) v=0.02*k;
            else if(fabs(dis)<=0.03) v=0.02*k;
            w=0;
        }
    }
    else if(marker_type == "none_marker_angle"){
        angle=getyaw(pose_n_robot.pose.orientation);
        cout<<"marker|none_marker_angle, angle: "<<angle<<endl;
        v=0;
        w=0;
        if(fabs(angle)<=M_PI/180*30){
            if(fabs(angle)<=M_PI/180/3){
                value_return=1;
                v=0;
                w=0;
                pub_cmd_vel(0,0);
            }else{
                static int k2;
                if(angle>0) k2=1;//, angle=angle-M_PI;//+M_PI*1/720;
                if(angle<0) k2=-1;//, angle=angle-M_PI;//-M_PI*1/360;
                //
                if(fabs(angle)>=M_PI/180*15) w=k2*M_PI/180*10;	    
                else if( fabs(angle)<M_PI/180*15 &&  fabs(angle)>=M_PI/180*10) w=k2*M_PI/180*5;	    
                else if( fabs(angle)<M_PI/180*10 &&  fabs(angle)>=M_PI/180*5) w=k2*M_PI/180*5;	    
                else if( fabs(angle)<M_PI/180*5 &&  fabs(angle)>=M_PI/180*3) w=k2*M_PI/180*3;
                else if( fabs(angle)<M_PI/180*3 &&  fabs(angle)>=M_PI/180/2) w=k2*M_PI/180*1;
                else if( fabs(angle)<M_PI/180/1) w=k2*M_PI/180/4;
            } 
        }
        else{
            if(angle>0) w=M_PI/10;
            else w=-M_PI/10;
        }
    }
    if(safe!=0){  //| r <= 0
        // cout<<"marker|not safe: pub velocity 0"<<endl;
        pub_cmd_vel(0,0);
        // cout<<"marker|not safe: done pub velocity 0"<<endl;
    }else pub_cmd_vel(v,w);
    return value_return;
}

int marker_function::action(){
    static int res;
    if(status==Active_){
        // static string config_set,config_return;
        cout<<"marker|step: "<<step<<endl;
        if(step == 0){
            res=caculate_transforms_ofset();
            // cout<<"marker|set goal|res: "<<res<<endl;
            if(res == 1) step = 1;
            return Active_;
        }
        else if(step >= 1){
            send_tranform(x_set,y_set,z_set,w_set,mvibot_seri_f_+"/odom",mvibot_seri_f_+"/base_marker");
            // cout<<"marker|send tranform "<<endl;
            if(step == 1){
                res=check_send_transforms_tf_frame();
                // cout<<"marker|check send tranform|res: "<<res<<endl;
                if(res==1) step=2;
                return Active_;
            }
            else if(step >=2){
                static int status_transfrom_pose;
                status_transfrom_pose=tranfrom_pose_marker(1,"base_marker", "base_footprint");
                cout<<"marker|get tranform base_footprint to base_marker|res: "<<status_transfrom_pose<<endl;
                if(step==2){
                    // std::cout<<"marker|Check first pose is match with position robot!"<<endl;
                    if(status_transfrom_pose==1){
                        if(check_first_tranfrom_pose_marker()){
                            // std::cout<<"marker|Fisrt pose is match with postion robot"<<endl;
                            step=3;
                        }
                    }
                    return Active_;
                }
                else if(step == 3){
                    // std::cout<<"marker|Get footprint robot!"<<endl;
                    if(get_footprint() == 1) {
                        // std::cout<<"marker|Finish get footprint robot!"<<endl;
                        step=4;
                    }
                    return Active_;
                }
                else if(step == 4){
                    // std::cout<<"marker|Action move!"<<endl;
                    if(status_transfrom_pose){
                        // safe
                        if(safe==0) {
                            if(check_safe()==1)  safe=2;
                        }
                        else{
                            if(check_safe()==0) safe--;
                            if(safe<0) safe=0;
                        }
                        //
                        res = move_to_goal();
                        // cout<<"marker|move to goal with res: "<<res<<endl;
                        if(res==1){
                            step=0;
                            status = Finish_;
                            request = 0;
                            pub_cmd_vel(0.0,0.0);
                            //
                            off_set_dis=0.0;
                            off_set_angle=0.0;
                            //
                            std::cout<<"Finish marker"<<endl;
                            return Finish_;
                        }
                    }
                    return Active_;
                }
            }
        }
    }else{
        return status;
    }
}
