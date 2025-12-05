#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "../common/stoi.h"
#include "../common/set_get_param.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
geometry_msgs::msg::PoseStamped pose_o,pose_n,pose_m;
geometry_msgs::msg::PoseStamped pose_o_robot,pose_n_robot,pose_m_robot; 
double getyaw(geometry_msgs::msg::Quaternion quat_msg){
    //get angle around Z
    double roll, pitch, yaw;
    tf2::Quaternion quat_tf;
    tf2::fromMsg(quat_msg, quat_tf);
    tf2::Matrix3x3(quat_tf).getRPY(roll, pitch, yaw);
    return yaw;
}
double getyaw2(double data3, double data4){
    //get angle around Z
    geometry_msgs::msg::Quaternion quat_msg;
    double roll, pitch, yaw;
    tf2::Quaternion quat_tf;
    quat_msg.x=0;
    quat_msg.y=0;
    quat_msg.z=data3;
    quat_msg.w=data4;
    tf2::fromMsg(quat_msg, quat_tf);
    tf2::Matrix3x3(quat_tf).getRPY(roll, pitch, yaw);
    return yaw;
}
int compare_pose(double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2, double thresold_position, double thresold_angle){
        geometry_msgs::msg::Pose pose_1,pose_2;
        //
        std::cout<<x1<<"|"<<y1<<"|"<<z1<<"|"<<w1<<endl;
        std::cout<<x2<<"|"<<y2<<"|"<<z2<<"|"<<w2<<endl;       
        if(sqrt(pow(x2-x1,2)+pow(y2-y1,2))<=thresold_position){
            if(sqrt(pow(z2-z1,2)+pow(w2-w1,2))<=thresold_angle){
                return 1;
            }   
        }
        return 0;
    }
class marker : public rclcpp::Node{
    public:
        marker(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            //transform
            // tf_Buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
            tf_Buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
            tf_Listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_Buffer_);
            // tf_Broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(shared_from_this());
            tf_Broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
            //publisher
            cmd_vel_pub_= this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",1);
            robot_emg_pub_ = this->create_publisher<std_msgs::msg::String>("robot_emg",1);
            marker_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("marker_function_state",1);
            //subscriber
            auto scan_callback = [this](sensor_msgs::msg::LaserScan msg) ->void {
                    if(start==1){
                        scan_safe=msg;
                    }
            };
            laser_scan_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan",qos_profile,scan_callback);
            auto marker_function_status_callback = [this](std_msgs::msg::String msg)->void{
                cout<<"config|received request,status"<<endl;
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
            auto get_position_timer_callback = [this]()->void{
                robot_position = get_position(mvibot_seri_+"/odom", mvibot_seri_+"/base_footprint");
            };
            get_position_timer_ = this->create_wall_timer(50ms,get_position_timer_callback); 
        }
        string marker_type;
        string marker_dir;
        string marker_data;
        int start;
        sensor_msgs::msg::LaserScan scan_safe;
        double r=-1;
        void reset(int mode);
        // pose to save posstion
        double x_set=0;
        double y_set=0;
        double z_set=0;
        double w_set=1;
        vector<geometry_msgs::msg::Pose> my_pose;
        vector<geometry_msgs::msg::Pose> my_pose2;
        // offset transfrom
        double off_set_x=0.0;
        double off_set_y=0.0;
        double off_set_dis=0;
        double off_set_angle=0;
        // 
        int safe;
        float  x1_footprint,y1_footprint,x2_footprint,y2_footprint;
        float  safe_x1=0.01,safe_x2=0.01,safe_y1=0.01,safe_y2=0.01;
        double *robot_position;
        double *robot_position_get;
        void process_data(string data);
        int check_safe();
        int  caculate_transforms_ofset();
        // send tranform
        int check_send_transforms_tf_frame();
        int tranfrom_pose_marker(int mode, string source_frame, string target_frame);
        int check_first_tranfrom_pose_marker();
        int tranfrom_pose_marker2(int mode);
        int tranfrom_pose_marker3(int mode, string source_frame, string target_frame);
        double *get_position(string name1, string name2);
        void send_tranform(double x, double y, double z, double w, string  name, string name2);
        int get_footprint();
        // action maker
        // int status = Finish_;
        int step=0;         // 0 nothing 1 collect & detect 2 active
        int active_step=0;
        void pub_cmd_vel(float v, float w);
        void pub_robot_emg();
        void pub_status_marker();
        int move_to_pose_n();
        int move_to_postion_pose_n();
        int move_to_orientation_pose_n();
        int action();
        // 
        double Caculate_angle(double x1, double y1, double  x2, double y2);
        //
        int new_update=0;
        // ros::Time t_send,t_get;
        rclcpp::Clock clock_tf;
        rclcpp::Time t_get, t_send;
    private:
        //declare publisher var
        //publisher
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_emg_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr marker_function_state_pub_;
        //declare subscriber var
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr marker_function_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr marker_function_info_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan_sub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr action_timer_;
        rclcpp::TimerBase::SharedPtr get_position_timer_;
        //declare tranform car
        std::unique_ptr<tf2_ros::Buffer> tf_Buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_Listener_{nullptr};
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_Broadcaster_;
        //declare var
        string mvibot_seri_, mvibot_seri_f_;
        json parameters;
        int status = Finish_;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
};

void marker::process_data(string data){
    // static string_Iv2 data_I;
    // data_I.detect(data,"~", "=", "~");
    // safe_x1=0.01; safe_x2=0.01; safe_y1=0.01; safe_y2=0.01;
    // //
    // marker_dir="";
    // marker_type="";
    // for(size_t i=0;i<data_I.data1.size();i++){
    //     //
    //     if(data_I.data1[i]=="marker_type")      marker_type=data_I.data2[i];
    //     if(data_I.data1[i]=="marker_dir")       marker_dir=data_I.data2[i];
    //     if(data_I.data1[i]=="off_set_x1")       off_set_x=stod_f(data_I.data2[i]);
    //     if(data_I.data1[i]=="off_set_y1")       off_set_y=stod_f(data_I.data2[i]);
    //     if(data_I.data1[i]=="off_set_dis")      off_set_dis=stod_f(data_I.data2[i]);
    //     if(data_I.data1[i]=="off_set_angle")    off_set_angle=stod_f(data_I.data2[i]);
    //     //
    //     if(data_I.data1[i]=="sx1") safe_x1=stof_f(data_I.data2[i]);
    //     if(data_I.data1[i]=="sx2") safe_x2=stof_f(data_I.data2[i]);
    //     if(data_I.data1[i]=="sy1") safe_y1=stof_f(data_I.data2[i]);
    //     if(data_I.data1[i]=="sy2") safe_y2=stof_f(data_I.data2[i]);
    //     if(data_I.data1[i]=="bar_distance") bar_distance=stof_f(data_I.data2[i]);
    // }
    // marker_data=data;
}

int marker::caculate_transforms_ofset(){
    static int value_return;
    value_return=0;
    if(marker_type=="none_marker_dis" || marker_type=="none_marker_angle" ){
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
    }else{
        static double theta0, theta1;
        my_pose2.resize(2);
        theta0=getyaw(my_pose[0].orientation);
        if(theta0>M_PI/2) theta0=theta0-M_PI;
        if(theta0<-M_PI/2) theta0=theta0+M_PI;
        // caculator tranfom
        my_pose2[0]=my_pose[0];
        double x0,y0,x1,y1,xn,yn;
        x0=my_pose2[0].position.x;
        y0=my_pose2[0].position.y;
        x1=x0+off_set_x*sin(M_PI/2-theta0);
        y1=y0+off_set_x*cos(M_PI/2-theta0);
        xn=x1-off_set_y*sin(theta0);
        yn=y1+off_set_y*cos(theta0);
        //
        my_pose2[1]=my_pose2[0];
        my_pose2[1].position.x=xn;
        my_pose2[1].position.y=yn;
    }
    // check position robot with frame odom
    if(robot_position[0]!=-1 || robot_position[1]!=-1 || robot_position[2]!=-1 || robot_position[3]!=-1){
        value_return=1;
        x_set=robot_position[0];
        y_set=robot_position[1];
        z_set=robot_position[2];
        w_set=robot_position[3];
        std::cout<<x_set<<"|"<<y_set<<"|"<<z_set<<"|"<<w_set<<endl;
        //
        new_update=1;
    }
    else{
        value_return=0;
        std::cout<<"Robot position not have !"<<endl;
    }
    return value_return;
}
double *marker::get_position(string name1, string name2){
    static double data[6];
    //get position
    static double x,y,z,thz,thw;
    static double sec=0,nsec=0;
    static geometry_msgs::msg::TransformStamped transformStamped;
    try{
        transformStamped = tf_Buffer_->lookupTransform(name1,name2,tf2::TimePointZero);
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
int marker::check_send_transforms_tf_frame(){
    static int value_return;
    // check tranfrom is true
    robot_position_get=get_position(mvibot_seri_+"/odom",mvibot_seri_+"/base_marker");
    // update time get time
    // t_get.sec=(uint32_t)robot_position_get[4];
    // t_get.nsec=(uint32_t)robot_position_get[5];
    // t_get = rclcpp::Time((uint32_t)robot_position_get[4]*1000000000+(uint32_t)robot_position_get[5]);
    t_get = rclcpp::Time(static_cast<int32_t>(robot_position_get[4]), static_cast<uint32_t>(robot_position_get[5]));
    //
    value_return=0;
    if(t_get>t_send+rclcpp::Duration::from_seconds(0.2)) //0.1->0.2 tf2::durationFromSec(0.2)
    {
        if(compare_pose(x_set,y_set,z_set,w_set,robot_position_get[0],robot_position_get[1],robot_position_get[2],robot_position_get[3],0.05000,0.05000)) 
        value_return=1;
    }
    return value_return;
}

int marker::tranfrom_pose_marker(int mode, string source_frame, string target_frame){
    static int value_return;
    static geometry_msgs::msg::TransformStamped target;
    value_return=0;
    try {             
        target=tf_Buffer_->lookupTransform(mvibot_seri_+"/"+target_frame, mvibot_seri_+"/"+source_frame, tf2::TimePointZero, tf2::durationFromSec(0.1));
        if(mode==1){
            pose_o.header.stamp=target.header.stamp;
            pose_n.header.stamp=target.header.stamp;
            //
            pose_o.pose=my_pose2[0];
            pose_n.pose=my_pose2[1];
            //
            pose_o.header.frame_id=mvibot_seri_+"/"+source_frame;
            pose_n.header.frame_id=mvibot_seri_+"/"+source_frame;
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
void marker::send_tranform(double x, double y, double z, double w, string  name1, string name2){
    static geometry_msgs::msg::TransformStamped transformStamped;
    transformStamped.header.stamp = clock_tf.now();
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
int marker::tranfrom_pose_marker2(int mode){
    static int value_return;
    static geometry_msgs::msg::TransformStamped target;
    value_return=0;
    try{
        try {             
            target=tf_Buffer_->lookupTransform(mvibot_seri_+"/base_footprint", mvibot_seri_+"/base_marker", tf2::TimePointZero, tf2::durationFromSec(0.1));
            if(mode==1){
                pose_o.header.stamp=target.header.stamp;
                pose_n.header.stamp=target.header.stamp;
                //
                pose_o.pose=my_pose2[0];
                pose_n.pose=my_pose2[1];
                //
                pose_o.header.frame_id=mvibot_seri_+"/base_marker";
                pose_n.header.frame_id=mvibot_seri_+"/base_marker";
                //
                tf2::doTransform(pose_o, pose_o_robot, target);
                tf2::doTransform(pose_n, pose_n_robot, target);
            }
            value_return=1;
        } catch(tf2::TransformException &e){
            RCLCPP_ERROR(this->get_logger(),"Error occured1: %s ", e.what());
            value_return=0;
        }
    }catch(const std::exception& e){
            RCLCPP_ERROR(this->get_logger(),"Error occured2: %s ", e.what());
            value_return=0;
    }
    return value_return;
}
//
int marker::check_first_tranfrom_pose_marker(){
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
int marker::get_footprint(){
    static string footprint_return;
    bool state_get_footprint;
    state_get_footprint = get_param(mvibot_seri_+"/global_costmap/global_costmap/get_parameters","footprint", footprint_return);
    if(state_get_footprint == true){
        cout<<"footprint: "<<footprint_return<<endl;
        static string footprint_string_1;
        footprint_string_1 = "";
        for(size_t i=0; i<footprint_return.length();i++){
            if(footprint_return[i] != '[' && footprint_return[i] != ']') footprint_string_1 += footprint_return[i];
        }
        static string_Iv2 footprint_string_2;
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
        return 1;
    }
    else return 0;
}
int marker::check_safe(){
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
            if(x>x1_footprint-1 && x<=x1_footprint-0.5 && x<x2_footprint+1 && x>=x2_footprint+0.5) free_space = 3;
            else if (x>x1_footprint-0.5 && x<x2_footprint+0.5) free_space = 2;
        }
        //them
    }
    return free_space;
}
void marker::pub_cmd_vel(float v, float w){
    static geometry_msgs::msg::Twist cmd_msg;
    static float creat_fun = 0;
    if(creat_fun == 1){
        if(start!=1){
            v=0;
            w=0;
        }
        cmd_msg.linear.x = (double)v;
        cmd_msg.angular.z = (double)w;
        pub_cmd_vel_->publish(cmd_msg);
    }
    else creat_fun = 1;
}
void marker::pub_robot_emg(){
    static float creat_fun=0;
    std_msgs::msg::String msg;
    msg.data = "1";
    if(creat_fun==1){
        pub_robot_emg_->publish(msg);
    }
    else creat_fun=1;
}
void marker::pub_status_marker(){
    static float creat_fun=0;
    static std_msgs::msg::String data;
    if(creat_fun==1){
        if(start==0) data.data="0";
        if(start==1) data.data="1";
        if(start==2) data.data="2";
        pub_status_marker_->publish(data);
    }
    else creat_fun=1;
}
int marker::move_to_postion_pose_n(){
    static int value_return;
    value_return=0;
    std::cout<<"move to postion pose_n:"<<endl;
    std::cout<<"\t _x:"<<pose_n_robot.pose.position.x;
    std::cout<<"|_y:"<<pose_n_robot.pose.position.y;
    std::cout<<"|_theta:"<<atan2(pose_n_robot.pose.position.y,pose_n_robot.pose.position.x)/M_PI*180<<endl;
    //
    static double dis,angle;
    static double x,y;
    x=pose_n_robot.pose.position.x;
    y=pose_n_robot.pose.position.y;
    if(marker_type=="none_marker_dis"){
        angle=getyaw(pose_n_robot.pose.orientation);
        dis=fabs(x);
        off_set_dis=x;
    }
    else{
        angle=atan2(y,x);
        dis=sqrt(x*x+y*y);
    }
    //
    if(angle>M_PI*1/2) angle=angle-M_PI;
    if(angle<-M_PI_2*1/2) angle=angle+M_PI;
    //
    static float v,w;
    v=0;
    w=0;
    //
    if(fabs(dis)<=0.01){ // 0.005
        value_return=1;
        v=0;
        w=0;
        pub_cmd_vel(0,0);
        pub_robot_emg();
    }else{
        if(fabs(angle)<=M_PI/180*30){
            static int k;
            if(x>0) k=1;
            if(x<0) k=-1;
            //
            if(fabs(dis)>=0.6)  v=0.3*k;
            else if(fabs(dis)<0.6 && fabs(dis)>=0.4) v=0.25*k;
            else if(fabs(dis)<0.4 && fabs(dis)>=0.2) v=0.15*k;
            else if(fabs(dis)<0.2 && fabs(dis)>=0.1) v=0.08*k;
            else if(fabs(dis)<0.1 && fabs(dis)>=0.05) v=0.04*k;
            else if(fabs(dis)<0.05 && fabs(dis)>=0.03) v=0.02*k;
            else if(fabs(dis)<=0.03) v=0.02*k;
            //
            static int k2;
            if(angle>0) k2=1;
            if(angle<0) k2=-1;
            //
            if(fabs(angle)>=M_PI/180*15) w=k2*M_PI/180*10;	    
            else if( fabs(angle)<M_PI/180*15 &&  fabs(angle)>=M_PI/180*10) w=k2*M_PI/180*5;	    
            else if( fabs(angle)<M_PI/180*10 &&  fabs(angle)>=M_PI/180*5) w=k2*M_PI/180*5;	    
            else if( fabs(angle)<M_PI/180*5 &&  fabs(angle)>=M_PI/180*3) w=k2*M_PI/180*3;
            else if( fabs(angle)<M_PI/180*3 &&  fabs(angle)>=M_PI/180/2) w=k2*M_PI/180*1;
            else if( fabs(angle)<M_PI/180/2) w=k2*M_PI/180/2;
        }
        else{
            v=0;
            if(angle>0) w=M_PI/10;//180*10;
            else w=-M_PI/10;
        }
    }
    std::cout<<"v:"<<v<<"|w"<<w<<endl;
    //
    if(safe!=0){
        pub_robot_emg();
        pub_cmd_vel(0,0);
    }else pub_cmd_vel(v,w);
    return value_return;
}
//
int marker::move_to_orientation_pose_n(){
    static int value_return;
    value_return=0;
    std::cout<<"move to orientation pose_n:"<<endl;
    std::cout<<"_theta:"<<getyaw(pose_n_robot.pose.orientation)/M_PI*180<<endl;
    //
    static double dis,angle;
    // static double x,y;
    angle=getyaw(pose_n_robot.pose.orientation);
    //
    if(marker_type=="none_marker_angle") off_set_angle=angle/M_PI*180;
    static float v,w;
    v=0;
    w=0;
    if(fabs(angle)<=M_PI/180*30){
            if(fabs(angle)<=M_PI/180/3){
                value_return=1;
                v=0;
                w=0;
                pub_robot_emg();
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
    std::cout<<"v:"<<v<<"|w"<<w<<endl;
    //
    if(safe!=0){
        pub_robot_emg();
        pub_cmd_vel(0,0);
    }else pub_cmd_vel(v,w);
    return value_return;
}
int marker::move_to_pose_n(){
    static int value_return;
    value_return=0;
    std::cout<<"move to postion pose_n:"<<endl;
    std::cout<<"\t _x:"<<pose_n_robot.pose.position.x;
    std::cout<<"|_y:"<<pose_n_robot.pose.position.y;
    std::cout<<"|_theta:"<<atan2(pose_n_robot.pose.position.y,pose_n_robot.pose.position.x)/M_PI*180<<endl;
    //
    static double dis,angle;
    static double x,y;
    x=pose_n_robot.pose.position.x;
    y=pose_n_robot.pose.position.y;
    if(marker_type=="none_marker_dis"){
        angle=getyaw(pose_n_robot.pose.orientation);
        dis=fabs(x);
        off_set_dis=x;
        if(angle>M_PI*1/2) angle=angle-M_PI;
        if(angle<-M_PI*1/2) angle=angle+M_PI;
    }
    else{
        angle=atan2(y,x);
        if(angle>M_PI*1/2) angle=angle-M_PI;//-M_PI*1/720;
        if(angle<-M_PI*1/2) angle=angle+M_PI;//-M_PI*1/720;
        angle=angle+Caculate_angle(pose_o.pose.position.x,pose_o.pose.position.y,x,y)/2;
        dis=sqrt(x*x+y*y);
    }
    //
    static float v,w;
    v=0;
    w=0;
    //
    static int a=0;
    //
    if(fabs(dis)<=0.0075 || r==0){ // 0.005 |r==0
        value_return=1;
        v=0;
        w=0;
        a=0;
        pub_cmd_vel(0,0);
        pub_robot_emg();
    }else{
        if(fabs(angle)<=M_PI/180*30){
             if(fabs(angle)<=M_PI/180/3){//3
                //v=0;
                w=0;
                static int k;
                static double r1 = 1;
                if(a==0 && r>0){
                    r1=r;
                    a=1;
                    r=-1;
                }
                if(x>0) k=1;
                if(x<0) k=-1;
                //
                if(fabs(dis)>=0.6)  v=0.06*k;
                else if(fabs(dis)<0.6 && fabs(dis)>=0.4) v=0.05*k;
                else if(fabs(dis)<0.4 && fabs(dis)>=0.3) v=0.04*k;
                else if(fabs(dis)<0.3 && fabs(dis)>=0.2) v=0.035*k;
                else if(fabs(dis)<0.2 && fabs(dis)>=0.1) v=0.03*k;
                else if(fabs(dis)<0.1 && fabs(dis)>=0.05) v=0.025*k;
                else if(fabs(dis)<0.05 && fabs(dis)>=0.03) v=0.02*k;
                else if(fabs(dis)<=0.03) v=0.01*k;
                // if(fabs(dis)>=0.6)  v=0.1*k;
                // else if(fabs(dis)<0.6 & fabs(dis)>=0.4) v=0.08*k;
                // else if(fabs(dis)<0.4 & fabs(dis)>=0.3) v=0.07*k;
                // else if(fabs(dis)<0.3 & fabs(dis)>=0.2) v=0.06*k;
                // else if(fabs(dis)<0.2 & fabs(dis)>=0.1) v=0.05*k;
                // else if(fabs(dis)<0.1 & fabs(dis)>=0.05) v=0.04*k;
                // else if(fabs(dis)<0.05 & fabs(dis)>=0.03) v=0.02*k;
                // else if(fabs(dis)<=0.03) v=0.01*k;
                if(marker_type=="none_marker_dis"){
                    if(fabs(dis)>=0.6)  v=0.3*k;
                    else if(fabs(dis)<0.6 && fabs(dis)>=0.4) v=0.25*k;
                    else if(fabs(dis)<0.4 && fabs(dis)>=0.2) v=0.15*k;
                    else if(fabs(dis)<0.2 && fabs(dis)>=0.1) v=0.08*k;
                    else if(fabs(dis)<0.1 && fabs(dis)>=0.05) v=0.04*k;
                    else if(fabs(dis)<0.05 && fabs(dis)>=0.03) v=0.02*k;
                    else if(fabs(dis)<=0.03) v=0.02*k;
                    w=0;
                }else w=v/r1;
                
            //
            }else{
                //
                v=0;
                static int k2;
                if(angle>0) k2=1;//, angle=angle-M_PI+M_PI*1/720;
                if(angle<0) k2=-1;//, angle=angle-M_PI-M_PI*1/720;
                if(fabs(angle)>=M_PI/180*15) w=k2*M_PI/180*10;	    
                else if( fabs(angle)<M_PI/180*15 &&  fabs(angle)>=M_PI/180*10) w=k2*M_PI/180*5;	    
                else if( fabs(angle)<M_PI/180*10 &&  fabs(angle)>=M_PI/180*5) w=k2*M_PI/180*4;	    
                else if( fabs(angle)<M_PI/180*5 &&  fabs(angle)>=M_PI/180*3) w=k2*M_PI/180*2;
                else if( fabs(angle)<M_PI/180*3 &&  fabs(angle)>=M_PI/180/2) w=k2*M_PI/180/1;
                else if( fabs(angle)<M_PI/180/1) w=k2*M_PI/180/4;
            } 
        }
        else{
            v=0;
            if(angle>0) w=M_PI/10;//180*10;
            else w=-M_PI/10;
        }
    }
    std::cout<<"v:"<<v<<"|w"<<w<<endl;
    //
    if(safe!=0 || r == 0){  //| r <= 0
        pub_robot_emg();
        pub_cmd_vel(0,0);
    }else pub_cmd_vel(v,w);
    return value_return;
}
double marker::Caculate_angle(double x1, double y1, double  x2, double y2){
    static double x,y,x1_,y1_,x2_,y2_;
    // Tam I(x,y) cua duong tron di qua B(X2,Y2) va tiep tuyen tai A(x1,y1), A thuoc Ox
    x=x1;
    y=((x1-x2)*(x1-x2)+y2*y2)/(2*y2);
    r=abs(y);
    // Tính vector
    x1_ = x1 - x;
    y1_ = y1 - y;
    x2_ = x2 - x;
    y2_ = y2 - y;

    double dot_product = x1_ * x2_ + y1_ * y2_;
    double magnitude1 = sqrt(x1_ * x1_ + y1_ * y1_);
    double magnitude2 = sqrt(x2_ * x2_ + y2_ * y2_);
    double cos_theta = dot_product / (magnitude1 * magnitude2);
    double angle_rad = acos(cos_theta);
    //double angle_deg = angle_rad ;//* 180 / M_PI;
    //return angle_deg;
    return angle_rad;
}
int marker::action(){
    static int value_return;
    static int res;
    value_return = Finish_;

    if(step==0){
        res=caculate_transforms_ofset();
        if(res==1){
            step=1;
            pub_marker();
        }
        std::cout<<"Cacluate transfrom offset finish"<<endl;
        value_return = Active_;
    }
    else if(step>=1){
        send_tranform(x_set,y_set,z_set,w_set,mvibot_seri_+"/odom",mvibot_seri_+"/base_marker");
        if(new_update==1){
            new_update=0;
            t_send= clock_tf.now();
        }
        //
        if(step==1){
            std::cout<<"Check is send transform odom->base_marker"<<endl;
            res=check_send_transforms_tf_frame();
            if(res==1) step=2;
            value_return = Active_;
        }
        else if(step>=2){
            static int status_transfrom_pose;
            status_transfrom_pose=tranfrom_pose_marker(1,"base_maker", "base_footprint");
            if(step==2){
                std::cout<<"Check first pose is match with position robot!"<<endl;
                if(status_transfrom_pose==1){
                    if(check_first_tranfrom_pose_marker()){
                        std::cout<<"Fisrt pose is match with postion robot"<<endl;
                        step=3;
                    }
                }
                value_return = Active_;
            }
            else if(step==3){
                std::cout<<"Get footprint robot!"<<endl;
                if(get_footprint() == 1) {
                    std::cout<<"Finish get footprint robot!"<<endl;                  
                    step=4;
                    active_step=0;
                }
                value_return = Active_;
            }
            else if(step==4){
                std::cout<<"Action move!"<<endl;
                if(status_transfrom_pose){
                    // safe
                    if(safe==0) {
                        if(check_safe()==1)  safe=30;
                    }
                    else{
                        if(check_safe()==0) safe--;
                        if(safe<0) safe=0;
                    }
                    //
                    //if(active_step==0) res=move_to_postion_pose_n();
                    if(active_step==0) res=move_to_pose_n();
                    if(active_step==1) res=move_to_orientation_pose_n();
                    //
                    if(res==1){
                        active_step++;
                        if(active_step>=2){
                            active_step=0;
                            step=0;
                            reset(0);
                            start=2;
                            pub_cmd_vel(0,0);
                            pub_robot_emg();
                            //
                            off_set_x=0.0;
                            off_set_y=0.0;
                            off_set_dis=0.0;
                            off_set_angle=0.0;
                            marker_data="";
                            //
                            std::cout<<"Finish marker"<<endl;
                            value_return = Finish_;
                        }
                    }
                }
            }
        }
    }
    return value_return;
}
void marker::reset(int mode){
    if(mode==0){
        process_data(marker_data);
        step=0;
        active_step=0;
        new_update=0;
    }else if(mode==1){
        step=0;
        active_step=0;
        new_update=0;
    }
   
}