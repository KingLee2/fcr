#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "../common/stoi.h"
#include "../common/set_get_param.h"
#include "mission_define.h"
using namespace std;
// int safe;
// float  x1_footprint,y1_footprint,x2_footprint,y2_footprint;
// float  safe_x1=0.01,safe_x2=0.01,safe_y1=0.01,safe_y2=0.01;
//postion and pose robot
// double *robot_position;
// double *robot_position_get;
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
// define point
class point{
public:
    float x;
    float y;
};
 // define multiple point
class points {
    public:
        vector<point> points;
};
class line{
    public:
        float x1;
        float x2;
        float y1;
        float y2;
        float A;
        float B;
        float C;
        //
        vector<point> points;
        //
        void addpoint(point point_add){
            static int size;
            size=points.size();
            points.resize(size+1);
            points[size]=point_add;
        }
        void caculate(){
            static int size;
            size=points.size();
            if(size>=2){
                static float sum_1,sum_2;
                sum_1=0; sum_2=0;
                for(int i=0;i<size;i++){
                    sum_1+=points[i].x;
                    sum_2+=points[i].y;
                }
                //
                static float x_,y_;
                x_=sum_1/size;
                y_=sum_2/size;
                //
                sum_1=0; sum_2=0;
                for(int i=0;i<size;i++){
                    sum_1+=(points[i].x-x_)*(points[i].y-y_);
                    sum_2+=(points[i].x-x_)*(points[i].x-x_);
                }
                static float a,b;
                b=sum_1/sum_2;
                a=y_-b*x_;
                A=b;
                B=-1;
                C=a;
            }
        }
        float caculate_dis(){
            static int size;
            size=points.size();
            if(size>=2){
                static float dis,dis_x,dis_y;
                dis_x=points[0].x-points[size-1].x;
                dis_y=points[0].y-points[size-1].y;
                dis=sqrt(dis_x*dis_x+dis_y*dis_y);
                return dis;
            }else return 0;
        }
        float caculate_distance(point point_caculate){
            static float dis;
            static float x,y;
            x=point_caculate.x;
            y=point_caculate.y;
            dis=fabs(A*x+B*y+C)/sqrt(A*A+B*B);
            return dis;
        }
        float caculate_atan2(){
            return atan2(B,A);
        }
};
// define point by line intersect line
point line_cut(line line1, line line2){
    static float d,dx,dy;
    static float a1,a2,b1,b2,c1,c2;
    //
    a1=line1.A;
    b1=line1.B;
    c1=line1.C;
    a2=line2.A;
    b2=line2.B;
    c2=line2.C;
    d=a1*b2-a2*b1;
    dx=c1*b2-c2*b1;
    dy=a1*c2-a2*c1;            
    //
    static point point_return;
    point_return.x=-dx/d;
    point_return.y=-dy/d;
    //
    return point_return;
}
// data for robot
class data_marker{
    public:
        int num_msg=5; //5
        // data
        vector<sensor_msgs::msg::LaserScan> my_scan;
        vector<point>   my_points;
        vector<points>  my_group;
        vector<points>  my_group2;
        vector<points>  my_group3;
        // line & pose after detect
        vector<line>            my_lines;
        vector<vector<line>>    my_lines2; 
        vector<vector<line>>    my_lines2_1;
        vector<line>            my_lines3; 
        //
        int process_data(string marker_dir);
        void reset();
};
int data_marker::process_data(string marker_dir){
    static int n;
    static int value_return;
    n=my_scan.size();
    if(n>=num_msg){
        value_return=1;
        //
        std::cout<<"Start process**********************************"<<endl;
        std::cout<<"Get "<<num_msg<<" msg:Finsh"<<endl;
        //
        std::cout<<"process point:"<<endl;
        static float theta,x,y;
        for(size_t i=0;i<my_scan[0].ranges.size();i++){
                theta=my_scan[0].angle_min+i*my_scan[0].angle_increment;
                for(int j=0;j<n;j++){  
                    //
                    static float x_max,x_min;
                    static float y_max=1.0,y_min=-1.0;
                    if(marker_dir=="front_ward") {
                        x_max=2.2; x_min=0.5;
                        x=my_scan[j].ranges[i]*cos(theta);
                        y=my_scan[j].ranges[i]*sin(theta);
                    }else if(marker_dir=="back_ward"){
                        x_max=-0.5; x_min=-2.2;
                        x=-my_scan[j].ranges[i]*cos(theta);
                        y=-my_scan[j].ranges[i]*sin(theta);
                    }
                    //   
                    if(x>=x_min && x<=x_max){
                        if(y>=y_min && y<=y_max){
                            static int size_points;
                            size_points=my_points.size();
                            my_points.resize(size_points+1);
                            my_points[size_points].x=x;
                            my_points[size_points].y=y;
                        }
                    }
                }
            }
        std::cout<<"\t num_point:"<<my_points.size()<<endl;
        // process group
        // for the rotary cw/ccw of radar. 
        // 2 point continuous in angle if have distane > 0.1 then they are 2 group
        std::cout<<"process group points:"<<endl;
        for(size_t i=0;i<my_points.size();i++){
                static int size_points;
                static int size_group;
                static float x,y;
                x=my_points[i].x;
                y=my_points[i].y;
                //
                size_group=my_group.size();
                if(size_group==0) {
                        my_group.resize(1);
                        size_group=1;
                }
                //
                size_points=my_group[size_group-1].points.size();
                if(size_points==0){
                        my_group[size_group-1].points.resize(1);
                        size_points=1;
                        my_group[size_group-1].points[size_points-1].x=x;
                        my_group[size_group-1].points[size_points-1].y=y;
                }else{
                    static float dis_x,dis_y;
                    dis_x=x-my_group[size_group-1].points[size_points-1].x;
                    dis_y=y-my_group[size_group-1].points[size_points-1].y;
                    if(sqrt(dis_x*dis_x+dis_y*dis_y)<=0.1){
                        my_group[size_group-1].points.resize(size_points+1);
                        my_group[size_group-1].points[size_points].x=x;
                        my_group[size_group-1].points[size_points].y=y;
                    }else{
                        my_group.resize(size_group+1);
                        my_group[size_group].points.resize(1);
                        my_group[size_group].points[0].x=x;
                        my_group[size_group].points[0].y=y;
                    }
                }
            }
        std::cout<<"\t num_group:"<<my_group.size()<<endl;
        // group filter
        // fillter points with neighbor, point filletr by  avegare 10 point around it 
        std::cout<<"filter group...."<<endl;
        my_group2.resize(my_group.size());
        for(size_t i=0;i<my_group2.size();i++){
            my_group2[i].points=my_group[i].points;
            if(my_group[i].points.size()>11) 
            {
                static float sum_x,sum_y,n;
                for(size_t j=5;j<my_group2[i].points.size()-5;j++){
                    sum_x=0;
                    sum_y=0;
                    n=0;
                    for(size_t k=j-5;k<=j+5;k++){
                        sum_x+=my_group[i].points[k].x;
                        sum_y+=my_group[i].points[k].y;
                        n++;
                    }
                    my_group2[i].points[j].x=sum_x/n;
                    my_group2[i].points[j].y=sum_y/n;
                }
            }
        }
        // group filter with perimeter
        // because with vl , L ,Bar marker always have perimeter > 0.3 then remove if group have perimeter < 0.3
        std::cout<<"filter group with perimeter...."<<endl;
        my_group3.resize(0);
        for(size_t i=0;i<my_group2.size();i++){
            static float perimeter;
            perimeter=0;
            if(my_group2[i].points.size()>=2){
                for(size_t j=1;j<my_group2[i].points.size();j++){
                    static float dis_x,dis_y;
                    dis_x=my_group2[i].points[j].x-my_group2[i].points[j-1].x;
                    dis_y=my_group2[i].points[j].y-my_group2[i].points[j-1].y;
                    perimeter+=sqrt(dis_x*dis_x+dis_y*dis_y);
                }
            }
            if(perimeter>0.3){
                std::cout<<"\t group:"<<i<<endl;
                std::cout<<"\t \t size_points:"<<my_group2[i].points.size()<<endl;
                std::cout<<"\t \t perimeter:"<<perimeter<<endl;
                //
                my_group3.resize(my_group3.size()+1);
                my_group3[my_group3.size()-1]=my_group2[i];
            }
        }
        // detect line detect small line 0.1 & 0.05
        my_lines.resize(0);
        my_lines2.resize(my_group3.size());
        static line line1,line2;
        static float distance_max;
        static size_t n;
        distance_max=0;
        static int is_break;
        is_break=0;
        for(size_t i=0;i<my_group3.size();i++){
            for(size_t j=0;j<my_group3[i].points.size();j++){
                line1.points.resize(0);
                line2.points.resize(0);
                distance_max=0;
                is_break=0;
                for(size_t k=j;k<my_group3[i].points.size();k++){
                    if(line1.caculate_dis()<0.1){
                        line1.addpoint(my_group3[i].points[k]);
                    }else{
                        line1.caculate();
                        for(size_t n=0;n<line1.points.size();n++){
                            static float distance;
                            distance=line1.caculate_distance(line1.points[n]);
                            if(distance_max<distance) distance_max=distance;
                        }
                        if(distance_max<0.005){
                            line2.points.resize(0);
                            for(n=k;n<my_group3[i].points.size();n++){
                                if(line2.caculate_dis()<0.05){
                                    line2.addpoint(my_group3[i].points[n]);
                                }else{
                                    for(size_t m=0;m<line2.points.size();m++){
                                        static float distance;
                                        distance=line1.caculate_distance(line2.points[m]);
                                        k++;
                                        if(distance<0.005) line1.addpoint(line2.points[m]);
                                        else{
                                            static float check_sum;
                                            static int n_check;
                                            n_check=0;
                                            check_sum=0;
                                            for(size_t h=m;h<line2.points.size();h++){
                                                check_sum+=line1.caculate_distance(line2.points[h]);
                                                n_check++;
                                            }
                                            check_sum=check_sum/n_check;
                                            if(check_sum>=0.005){
                                                is_break=1;
                                                break;
                                            }else line1.addpoint(line2.points[m]);
                                            is_break=1;
                                            break;
                                            
                                        }
                                    }
                                    line2.points.resize(0);
                                    line1.caculate();
                                }
                                if(is_break) {
                                    static int size;
                                    size=my_lines.size();
                                    my_lines.resize(size+1);
                                    my_lines[size]=line1;
                                    //
                                    size=my_lines2[i].size();
                                    my_lines2[i].resize(size+1);
                                    my_lines2[i][size]=line1;
                                    j=k;
                                    break;
                                }
                            }
                        }else{
                            is_break=1;
                            break;
                        }
                        if(is_break) break;
                    }
                }
            }
            //
            static int size;
            size=my_lines.size();
            my_lines.resize(size+1);
            my_lines[size]=line1;
            size=my_lines2[i].size();
            my_lines2[i].resize(size+1);
            my_lines2[i][size]=line1;
        } 
        // combie line if line have as same as 
        for(size_t i=0;i<my_lines2.size();i++){
            for(size_t j=1;j<my_lines2[i].size();j++){
                static float ampha,beta,delta;
                ampha=my_lines2[i][j-1].caculate_atan2();
                beta=my_lines2[i][j].caculate_atan2();
                delta=tan(beta-ampha);
                if(fabs(delta)<=M_PI/180*10 || my_lines2[i][j].caculate_dis()<=0.05){
                    for(size_t k=0;k<my_lines2[i][j].points.size();k++){
                        my_lines2[i][j-1].addpoint(my_lines2[i][j].points[k]);
                    }
                    my_lines2[i][j-1].caculate();
                    for(size_t k=j;k<my_lines2[i].size()-1;k++){
                        my_lines2[i][k]=my_lines2[i][k+1];
                    }
                    my_lines2[i].resize(my_lines2[i].size()-1);
                    j--;
                }
            }  
        }
        // update line with new point
        for(size_t i=0;i<my_lines2.size();i++){
            for(size_t j=0;j<my_lines2[i].size();j++)
            my_lines2[i][j].points.resize(0);
        }
        for(size_t i=0;i<my_group3.size();i++){
            for(size_t j=0;j<my_group3[i].points.size();j++){
                for(size_t k=0;k<my_lines2[i].size();k++){
                    if(my_lines2[i][k].caculate_distance(my_group3[i].points[j])<=0.01)
                    my_lines2[i][k].addpoint(my_group3[i].points[j]);
                }
            }
        }
        for(size_t i=0;i<my_lines2.size();i++){
            for(size_t j=0;j<my_lines2[i].size();j++)
            my_lines2[i][j].caculate();
        }
        // get infor line
        std::cout<<"infor line"<<endl;
        for(size_t i=0;i<my_lines2.size();i++){
            std::cout<<"\t group:"<<i<<endl;
            for(size_t j=0;j<my_lines2[i].size();j++)
            {
                std::cout<<"\t \t line:"<<j<<endl;
                std::cout<<"\t \t \t dis:"<<my_lines2[i][j].caculate_dis()<<endl;
                std::cout<<"\t \t \t angle:"<<my_lines2[i][j].caculate_atan2()/M_PI*180<<endl;
            }
        }
        //
    }else {
        std::cout<<"Not enough data scan->get more scan data"<<endl;
        value_return=0;
    }
    return value_return;
}
void data_marker::reset(){
        //
        my_scan.resize(0);
        my_points.resize(0);
        my_group.resize(0);
        my_group2.resize(0);
        my_group3.resize(0);
        my_lines.resize(0);
        my_lines2.resize(0);
        my_lines2_1.resize(0);
        my_lines3.resize(0);
}
class marker : public set_get_param<string>{
    public:
        marker(const string &node_name, const string &sub_namespace) : set_get_param<string>(node_name, sub_namespace){
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
            pub_cmd_vel_= this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",1);
            pub_robot_emg_ = this->create_publisher<std_msgs::msg::String>("robot_emg",1);
            pub_status_marker_ = this->create_publisher<std_msgs::msg::String>("status_marker",1);
            pub_marker_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("visualization_marker",1);
            //subscriber
            auto scan1_callback = [this](sensor_msgs::msg::LaserScan msg) ->void {
                // lock();
                    if(start==1 && marker_dir=="front_ward"){
                        static int n;
                        n=my_data.my_scan.size();
                        if(n<my_data.num_msg){
                            std::cout<<"get_laser1_msg:"<<n+1<<endl;
                            my_data.my_scan.resize(my_data.my_scan.size()+1);
                            my_data.my_scan[n]=msg;
                        }
                    }
                // unlock();
            };
            sub_laser_scan1_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/base_link/scan1",1,scan1_callback);
            auto scan2_callback = [this](sensor_msgs::msg::LaserScan msg) -> void{
                // lock();
                    if(start==1){
                        static int n;
                        n=my_data.my_scan.size();
                        if(n<my_data.num_msg && marker_dir=="back_ward"){
                            std::cout<<"get_laser2_msg:"<<n+1<<endl;
                            my_data.my_scan.resize(my_data.my_scan.size()+1);
                            // inverse before add
                            static sensor_msgs::msg::LaserScan msg2;
                            msg2=msg;
                            for(size_t i=0;i<msg2.ranges.size()/2;i++){
                                static float a;
                                a=msg2.ranges[i];
                                msg2.ranges[i]=msg2.ranges[i+msg2.ranges.size()/2];
                                msg2.ranges[i+msg2.ranges.size()/2]=a;
                            }
                            my_data.my_scan[n]=msg2;
                        }
                    }
                // unlock();
            };
            sub_laser_scan2_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/base_link/scan2",1,scan2_callback);
            auto scan_callback = [this](sensor_msgs::msg::LaserScan msg) ->void {
                // lock();
                    if(start==1){
                        scan_safe=msg;
                    }
                // unlock();
            };
            sub_laser_scan_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan",1,scan_callback);
            auto start_marker_callback = [this](std_msgs::msg::String msg) -> void {
                // lock();
                    if(msg.data=="0"){
                        if(start==1){
                            start=0;
                            pub_robot_emg();
                            pub_cmd_vel(0,0);
                        }
                        start=0;
                    }else if (msg.data=="1"){
                        if(start==0){
                            if(marker_data!=""){
                                start=1;
                                reset(1);
                            }
                        } 
                    }else{
                        if(start==0){
                            pub_robot_emg();
                            pub_cmd_vel(0,0);
                            start=1;
                            reset(0);
                            process_data(msg.data);
                            std::cout<<msg.data<<endl;
                        }
                    }
                // unlock();
            };
            sub_start_marker_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/start_marker",1,start_marker_callback);
            auto get_position_timer_callback = [this]()->void{
                robot_position = get_position(mvibot_seri_+"/odom", mvibot_seri_+"/base_footprint");
            };
            get_position_timer_ = this->create_wall_timer(50ms,get_position_timer_callback); 
        }
        data_marker my_data;
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
        // detect
        int detect_vl();
        int detect_bar(float bar_distance);
        float bar_distance;
        int detect_l();
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
        int status=0;         // 0 nothing 1 collect & detect 2 active
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
        //visualization marker
        void marker_modify(visualization_msgs::msg::MarkerArray &marker,int num, int group, int id);
        void marker_scale(visualization_msgs::msg::MarkerArray &marker, int num, float sx, float sy, float sz);
        void marker_position(visualization_msgs::msg::MarkerArray &marker, int num, float xm, float y, float z);
        void marker_orientation(visualization_msgs::msg::MarkerArray &marker, int num, float x, float y, float z, float w);
        void marker_color(visualization_msgs::msg::MarkerArray &marker, int num, float r, float g, float b);
        void pub_marker();
        //
        int new_update=0;
        // ros::Time t_send,t_get;
        rclcpp::Clock clock_tf;
        rclcpp::Time t_get, t_send;
    private:
        //declare publisher var
        //publisher
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_vel_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_robot_emg_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_status_marker_;
        rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr pub_marker_;
        //declare subscriber var
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_laser_scan1_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_laser_scan2_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_start_marker_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_laser_scan_;
        //declare timer
        rclcpp::TimerBase::SharedPtr get_position_timer_;
        //declare tranform car
        std::unique_ptr<tf2_ros::Buffer> tf_Buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_Listener_{nullptr};
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_Broadcaster_;
        //declare var
        string mvibot_seri_;
};
void marker::marker_modify(visualization_msgs::msg::MarkerArray &marker, int num, int group, int id){
    static int size;
    size = marker.markers.size();
    if(num<size && num>=0){
        marker.markers[num].header.frame_id=mvibot_seri_+"/base_link";
        marker.markers[num].header.stamp=clock_tf.now();
        marker.markers[num].ns=to_string(group);
        marker.markers[num].id=id;
    }
}
void marker::marker_scale(visualization_msgs::msg::MarkerArray & marker,int num, float sx, float sy, float sz){
    static int size;
    size=marker.markers.size();
    if(num<size & num >=0){
        marker.markers[num].scale.x=sx;
        marker.markers[num].scale.y=sy;
        marker.markers[num].scale.z=sz;
    }
}
void marker::marker_position(visualization_msgs::msg::MarkerArray & marker,int num, float x, float y, float z){
    static int size;
    size=marker.markers.size();
    if(num<size & num >=0){
        marker.markers[num].pose.position.x=x;
        marker.markers[num].pose.position.y=y;
        marker.markers[num].pose.position.z=z;
    }
}
void marker::marker_orientation(visualization_msgs::msg::MarkerArray & marker,int num, float x, float y, float z, float w){
    static int size;
    size=marker.markers.size();
    if(num<size & num >=0){
        marker.markers[num].pose.orientation.x=x;
        marker.markers[num].pose.orientation.y=y;
        marker.markers[num].pose.orientation.z=z;
        marker.markers[num].pose.orientation.w=w;
    }
}
void marker::marker_color(visualization_msgs::msg::MarkerArray & marker,int num, float r, float g, float b){
    static int size;
    size=marker.markers.size();
    if(num<size & num >=0){
        marker.markers[num].color.r=r;
        marker.markers[num].color.g=g;
        marker.markers[num].color.b=b;
        marker.markers[num].color.a=1.0;
    }
}
void marker::pub_marker(){
    visualization_msgs::msg::MarkerArray marker;
    //delete old
    marker.markers.resize(4);
    for(int i=0; i<marker.markers.size();i++){
        marker.markers[i].action=visualization_msgs::msg::Marker::DELETEALL;
        marker.markers[i].ns=to_string(i);
    }
    pub_marker_->publish(marker);
    marker.markers.resize(0);
    //my_point
    marker.markers.resize(my_data.my_points.size());
    for(int i=0; i<my_data.my_points.size();i++){
        marker_modify(marker,i,0,i);
        marker_position(marker,i,my_data.my_points[i].x,my_data.my_points[i].y,1.5);
        marker_orientation(marker,i,0,0,0,1);
        marker_color(marker,i,1,0,0);
        marker_scale(marker,i,0.01,0.01,0.01);
        marker.markers[i].type=visualization_msgs::msg::Marker::CUBE;
        marker.markers[i].action=visualization_msgs::msg::Marker::ADD;
    }
    //my_group
    for(int i=0;i<my_data.my_group.size();i++){
        //
        static float r,g,b;
        r=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        g=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        b=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        //
        static int k;
        k=marker.markers.size();
        marker.markers.resize(k+my_data.my_group[i].points.size());
        for(int j=k;j<marker.markers.size();j++){
            marker_modify(marker,j,1,j);
            marker_position(marker,j, my_data.my_group[i].points[j-k].x, my_data.my_group[i].points[j-k].y,1.25);
            marker_orientation(marker,j,0,0,0,1);
            marker_color(marker,j,r,g,b);
            marker_scale(marker,j,0.01,0.01,0.01);
            marker.markers[j].type=visualization_msgs::msg::Marker::SPHERE;
            marker.markers[j].action=visualization_msgs::msg::Marker::ADD;
        }
    }
    // my group fillter
    for(int i=0;i<my_data.my_group3.size();i++){
        //
        static float r,g,b;
        r=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        g=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        b=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        //
        static int k;
        k=marker.markers.size();
        marker.markers.resize(k+my_data.my_group3[i].points.size());
        for(int j=k;j<marker.markers.size();j++){
            marker_modify(marker,j,2,j);
            marker_position(marker,j,my_data.my_group3[i].points[j-k].x, my_data.my_group3[i].points[j-k].y,1.0);
            marker_orientation(marker,j,0,0,0,1);
            marker_color(marker,j,r,g,b);
            marker_scale(marker,j,0.01,0.01,0.01);
            marker.markers[j].type=visualization_msgs::msg::Marker::SPHERE;
            marker.markers[j].action=visualization_msgs::msg::Marker::ADD;
        }
    }
    // my line
    for(int n=0;n<my_data.my_lines2.size();n++){
        for(int i=0;i<my_data.my_lines2[n].size();i++){
            //
            static float r,g,b;
            r=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            g=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            b=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            //
            static int k;
            k=marker.markers.size();
            marker.markers.resize(k+my_data.my_lines2[n][i].points.size());
            for(int j=k;j<marker.markers.size();j++){
                marker_modify(marker,j,3,j);
                marker_position(marker,j, my_data.my_lines2[n][i].points[j-k].x, my_data.my_lines2[n][i].points[j-k].y,0.75);
                marker_orientation(marker,j,0,0,0,1);
                marker_color(marker,j,r,g,b);
                marker_scale(marker,j,0.01,0.01,0.01);
                marker.markers[j].type=visualization_msgs::msg::Marker::SPHERE;
                marker.markers[j].action=visualization_msgs::msg::Marker::ADD;
            }
        }
    }
    // my pose
    static int k;
    k=marker.markers.size();
    marker.markers.resize(k+my_pose.size());
    for(int i=k;i<marker.markers.size();i++){
        //
        static float r,g,b;
        r=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        g=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        b=static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
        //    
        marker_modify(marker,i,4,i);
        marker_position(marker,i,my_pose[i-k].position.x,my_pose[i-k].position.y,0.5);
        marker_orientation(marker,i,0,0, my_pose[i-k].orientation.z, my_pose[i-k].orientation.w);
        marker_color(marker,i,r,g,b);
        marker_scale(marker,i,1,0.02,0.02);
        marker.markers[i].type=visualization_msgs::msg::Marker::ARROW;
        marker.markers[i].action=visualization_msgs::msg::Marker::ADD;
    }
    // my pose2
    k=marker.markers.size();
    marker.markers.resize(k+my_pose2.size());
    for(int i=k;i<marker.markers.size();i++){
        //
        static float r,g,b;
        r=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        g=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        b=static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
        //    
        marker_modify(marker,i,5,i);
        marker_position(marker,i,my_pose2[i-k].position.x,my_pose2[i-k].position.y,0.0);
        marker_orientation(marker,i,0,0,my_pose2[i-k].orientation.z, my_pose2[i-k].orientation.w);
        marker_color(marker,i,r,g,b);
        marker_scale(marker,i,1,0.02,0.02);
        marker.markers[i].type=visualization_msgs::msg::Marker::ARROW;
        marker.markers[i].action=visualization_msgs::msg::Marker::ADD;
    }
    pub_marker_->publish(marker);
}
//
void marker::process_data(string data){
    static string_Iv2 data_I;
    data_I.detect(data,"~", "=", "~");
    safe_x1=0.01; safe_x2=0.01; safe_y1=0.01; safe_y2=0.01;
    //
    marker_dir="";
    marker_type="";
    for(size_t i=0;i<data_I.data1.size();i++){
        //
        if(data_I.data1[i]=="marker_type")      marker_type=data_I.data2[i];
        if(data_I.data1[i]=="marker_dir")       marker_dir=data_I.data2[i];
        if(data_I.data1[i]=="off_set_x1")       off_set_x=stod_f(data_I.data2[i]);
        if(data_I.data1[i]=="off_set_y1")       off_set_y=stod_f(data_I.data2[i]);
        if(data_I.data1[i]=="off_set_dis")      off_set_dis=stod_f(data_I.data2[i]);
        if(data_I.data1[i]=="off_set_angle")    off_set_angle=stod_f(data_I.data2[i]);
        //
        if(data_I.data1[i]=="sx1") safe_x1=stof_f(data_I.data2[i]);
        if(data_I.data1[i]=="sx2") safe_x2=stof_f(data_I.data2[i]);
        if(data_I.data1[i]=="sy1") safe_y1=stof_f(data_I.data2[i]);
        if(data_I.data1[i]=="sy2") safe_y2=stof_f(data_I.data2[i]);
        if(data_I.data1[i]=="bar_distance") bar_distance=stof_f(data_I.data2[i]);
    }
    marker_data=data;
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
int marker::detect_bar(float bar_distance){
    static int value_return;
    static vector<vector<line>> my_lines_group_memory;
    static vector<line> my_lines_memory;
    //
    value_return=-1;
    //bar_distance=0.785;
    //
    my_lines_group_memory.resize(0);
    for(int i=0;i<my_data.my_lines2.size();i++){
        for(int j=0;j<my_data.my_lines2[i].size();j++){
            for(int k=i+1;k<my_data.my_lines2.size();k++){
                for(int h=0;h<my_data.my_lines2[k].size();h++){
                    static float ampha,beta,delta;
                    ampha=my_data.my_lines2[i][j].caculate_atan2();
                    beta=my_data.my_lines2[k][h].caculate_atan2();
                    delta=beta-ampha;
                    // check delta //
                    if(fabs(delta)<M_PI/180*2)   
                    {
                        static float dis1,dis2;
                        dis1=my_data.my_lines2[i][j].caculate_dis();
                        dis2=my_data.my_lines2[k][h].caculate_dis();
                        if((dis1>=0.5 | dis2>=0.5) & dis1 >=0.15 & dis2 >=0.15){
                            my_lines_group_memory.resize(my_lines_group_memory.size()+1);
                            my_lines_group_memory[my_lines_group_memory.size()-1].resize(2);
                            my_lines_group_memory[my_lines_group_memory.size()-1][0]=my_data.my_lines2[i][j];
                            my_lines_group_memory[my_lines_group_memory.size()-1][1]=my_data.my_lines2[k][h];
                        }
                    }
                }
            }
        }
    }
    cout<<"Num bar group have:"<<my_lines_group_memory.size()<<endl;
    cout<<"Check bar group with distance_bar_set:"<<bar_distance<<endl;
    static int num_bar_pass;
    static point point_1,point_2;
    num_bar_pass=0;
    for(int k=0;k<my_lines_group_memory.size();k++){
        point_1.x=0;
        point_1.y=0;
        for(int i=0;i<my_lines_group_memory[k][0].points.size();i++){
            point_1.x+=my_lines_group_memory[k][0].points[i].x;
            point_1.y+=my_lines_group_memory[k][0].points[i].y;
        }
        point_1.x=point_1.x/my_lines_group_memory[k][0].points.size();
        point_1.y=point_1.y/my_lines_group_memory[k][0].points.size();
        //
        point_2.x=0;
        point_2.y=0;
        for(int i=0;i<my_lines_group_memory[k][1].points.size();i++){
            point_2.x+=my_lines_group_memory[k][1].points[i].x;
            point_2.y+=my_lines_group_memory[k][1].points[i].y;
        }
        point_2.x=point_2.x/my_lines_group_memory[k][1].points.size();
        point_2.y=point_2.y/my_lines_group_memory[k][1].points.size();
        //
        static float dis1,dis2;
        dis1=my_lines_group_memory[k][0].caculate_distance(point_2);
        dis2=my_lines_group_memory[k][1].caculate_distance(point_1);
        if(fabs(dis1-bar_distance)<=0.05 & fabs(dis2-bar_distance)<=0.05){
            num_bar_pass++;
            my_lines_memory.resize(2);
            my_lines_memory[0]=my_lines_group_memory[k][0];
            my_lines_memory[1]=my_lines_group_memory[k][1];
        }
    }
    cout<<num_bar_pass<<endl;
    if(my_lines_memory.size()!=0 & num_bar_pass==1){
            my_lines_memory[0].points.resize(0);
            my_lines_memory[1].points.resize(0);
            for(int i=0;i<my_data.my_points.size();i++){
                //
                if(my_lines_memory[0].caculate_distance(my_data.my_points[i])<=0.01){
                    my_lines_memory[0].addpoint(my_data.my_points[i]);
                }
                //
                if(my_lines_memory[1].caculate_distance(my_data.my_points[i])<=0.01){
                    my_lines_memory[1].addpoint(my_data.my_points[i]);
                }
            }
            my_lines_memory[0].caculate();
            my_lines_memory[1].caculate();
            //
            static float dis1_to_o;
            static point point_1s;
            dis1_to_o=999;
            point_1.x=0;
            point_1.y=0;
            for(int i=0;i<my_lines_memory[0].points.size();i++){
                point_1.x+=my_lines_memory[0].points[i].x;
                point_1.y+=my_lines_memory[0].points[i].y;
                //
                static float x_to_o,y_to_o,dis_to_o;
                x_to_o=my_lines_memory[0].points[i].x;
                y_to_o=my_lines_memory[0].points[i].y;
                dis_to_o=sqrt(x_to_o*x_to_o+y_to_o*y_to_o);
                if(dis_to_o<dis1_to_o){
                    dis1_to_o=dis_to_o;
                    point_1s=my_lines_memory[0].points[i];
                }
            }
            point_1.x=point_1.x/my_lines_memory[0].points.size();
            point_1.y=point_1.y/my_lines_memory[0].points.size();
            //
            static float dis2_to_o;
            static point point_2s;
            dis2_to_o=999;
            point_2.x=0;
            point_2.y=0;
            for(int i=0;i<my_lines_memory[1].points.size();i++){
                point_2.x+=my_lines_memory[1].points[i].x;
                point_2.y+=my_lines_memory[1].points[i].y;
                //
                static float x_to_o,y_to_o,dis_to_o;
                x_to_o=my_lines_memory[1].points[i].x;
                y_to_o=my_lines_memory[1].points[i].y;
                dis_to_o=sqrt(x_to_o*x_to_o+y_to_o*y_to_o);
                if(dis_to_o<dis2_to_o){
                    dis2_to_o=dis_to_o;
                    point_2s=my_lines_memory[1].points[i];
                }
            }
            point_2.x=point_2.x/my_lines_memory[1].points.size();
            point_2.y=point_2.y/my_lines_memory[1].points.size();
            //
            static line line1;
            line1.A=tan(my_lines_memory[1].caculate_atan2());
            line1.B=-1;
            line1.C=-point_1.x*line1.A-point_1.y*line1.B;
            static point point_1d;
            point_1d=line_cut(line1,my_lines_memory[1]);
            //
            static line line2;
            line2.A=tan(my_lines_memory[0].caculate_atan2());
            line2.B=-1;
            line2.C=-point_2.x*line2.A-point_2.y*line2.B;
            static point point_2d;
            point_2d=line_cut(line2,my_lines_memory[0]);
            //
            static line line3;
            static float xo_1,yo_1;
            xo_1=(point_1.x+point_2.x)/2;
            yo_1=(point_1.y+point_2.y)/2;
            line3.A=tan((my_lines_memory[0].caculate_atan2()+my_lines_memory[0].caculate_atan2())/2);
            line3.B=-1;
            line3.C=-xo_1*line3.A-yo_1*line3.B;
            //
            static line line4;
            line4.A=tan((my_lines_memory[0].caculate_atan2()+my_lines_memory[0].caculate_atan2())/2);
            line4.B=-1;
            line4.C=-point_1s.x*line4.A-point_1s.y*line4.B;
            //
            static line line5;
            line5.A=tan((my_lines_memory[0].caculate_atan2()+my_lines_memory[0].caculate_atan2())/2);
            line5.B=-1;
            line5.C=-point_2s.x*line5.A-point_2s.y*line5.B;
            //
            static line line6;
            line6.A=tan((my_lines_memory[0].caculate_atan2()+my_lines_memory[0].caculate_atan2())/2+M_PI_2);
            line6.B=-1;
            line6.C=-xo_1*line6.A-yo_1*line6.B;
            //
            static float theta,x,y;
            static point point_o1,point_o2;
            point_o1=line_cut(line6,line4);
            point_o2=line_cut(line6,line5);
            //
            cout<<point_o1.x<<"|"<<point_o1.y<<endl;
            theta=(my_lines_memory[0].caculate_atan2()+my_lines_memory[0].caculate_atan2())/2+M_PI_2;
            if(sqrt(point_o1.x*point_o1.x+point_o1.y*point_o1.y)<sqrt(point_o2.x*point_o2.x+point_o2.y*point_o2.y))
            {
                x=point_o1.x;
                y=point_o1.y;
            }else{
                x=point_o2.x;
                y=point_o2.y;
            }        
            if(theta>M_PI_2) theta=theta-M_PI;
            if(theta<-M_PI_2) theta=theta+M_PI;
            //
            static tf2::Quaternion quat;
            static  geometry_msgs::msg::Quaternion quat_msg;
            quat.setRPY(0,0,theta);
            quat_msg = tf2::toMsg(quat);
            my_pose.resize(3);
            my_pose[0].position.x=(double)x;
            my_pose[0].position.y=(double)y;
            my_pose[0].orientation=quat_msg;
            my_pose[1].position.x=(double)point_1s.x;
            my_pose[1].position.y=(double)point_1s.y;
            my_pose[1].orientation=quat_msg;
            my_pose[2].position.x=(double)point_2s.x;
            my_pose[2].position.y=(double)point_2s.y;
            my_pose[2].orientation=quat_msg;
            //
            my_data.my_lines2.resize(1);
            my_data.my_lines2[0].resize(2);
            my_data.my_lines2[0][0]=my_lines_memory[0];
            my_data.my_lines2[0][1]=my_lines_memory[1];
            value_return=1;
            // UPDATE SAU
            // static string cmd;
            // cmd="";
            // cmd=cmd+"echo "+to_string( my_pose[0].position.x)+"\t"+to_string( my_pose[0].position.y)+"\t"+to_string(getyaw(my_pose[0].orientation));
            // static struct timespec realtime;
            // clock_gettime(CLOCK_REALTIME, &realtime);
            // cmd=cmd+" >> /home/mvibot/floorCleaningRobot/src/mission_layer_mvibot/data/bar/"+to_string(realtime.tv_sec)+".txt";
            // system(cmd.c_str());
            // static ofstream myfile;
            // myfile.open("/home/mvibot/floorCleaningRobot/src/mission_layer_mvibot/data/bar/"+to_string(realtime.tv_sec)+".txt",ios::app);
            // for(int i=0;i<my_data.my_points.size();i++){
            //     cmd=to_string(my_data.my_points[i].x)+"\t"+to_string(my_data.my_points[i].y)+"\n";
            //     myfile<<cmd;
            // }
            // myfile.close();
            
    } 
    return value_return;
}
int marker::detect_l(){
    static int value_return;
    value_return=-1;
    //
    static line line3,line4;
    static float dis_error_min;
    dis_error_min=99;
    for(int i=0;i<my_data.my_lines2.size();i++){
        for(int j=1;j<my_data.my_lines2[i].size();j++){
                static float ampha,beta,delta;
                ampha=my_data.my_lines2[i][j-1].caculate_atan2();
                beta=my_data.my_lines2[i][j].caculate_atan2();
                //
                static float dis1,dis2,dis3;
                dis1=my_data.my_lines2[i][j-1].caculate_dis();
                dis2=my_data.my_lines2[i][j].caculate_dis();
                cout<<fabs(fabs(ampha-beta)-M_PI/2)/M_PI*180<<endl;
                if(fabs(fabs(ampha-beta)-M_PI/2)<=M_PI/180*5)
                {
                    cout<<dis1<<"|"<<dis2<<endl;
                    if(dis1 < 0.4+0.05 & dis1 > 0.4 -0.05 & dis2 <0.6+0.05 & dis2 > 0.6-0.05){
                        static float dis_error_sum;
                        dis_error_sum=fabs(0.4-dis1)+fabs(0.6-dis2);
                        if(dis_error_sum < dis_error_min){
                            line3=my_data.my_lines2[i][j-1];
                            line4=my_data.my_lines2[i][j];
                            dis_error_min=dis_error_sum;
                            value_return=1;
                        }
                    }
                }
            }
    }
    if(value_return==1){
        static float x,y;
        static tf2::Quaternion quat;
        static  geometry_msgs::msg::Quaternion quat_msg;
        static point point_1;
        //
        point_1=line_cut(line3,line4);
        cout<<"\t x:"<<point_1.x<<"|y:"<<point_1.y<<endl;
        my_pose.resize(1);
        my_pose[0].position.x=point_1.x;
        my_pose[0].position.y=point_1.y;
        //
        static float beta;
        beta=line3.caculate_atan2();
        if(beta>M_PI_2) beta=beta-M_PI;
        if(beta<-M_PI_2) beta=beta+M_PI;
        quat.setRPY(0,0,beta);
        quat_msg = tf2::toMsg(quat);
        my_pose[0].orientation=quat_msg;
        // UPDATE SAU
        // static string cmd;
        // cmd="";
        // cmd=cmd+"echo "+to_string( my_pose[0].position.x)+"\t"+to_string( my_pose[0].position.y)+"\t"+to_string(getyaw(my_pose[0].orientation));
        // static struct timespec realtime;
        // clock_gettime(CLOCK_REALTIME, &realtime);
        // cmd=cmd+" >> /home/mvibot/mvibot_ws/src/mvibot/data/l/"+to_string(realtime.tv_sec)+".txt";
        // system(cmd.c_str());
        // //
        // static ofstream myfile;
        // myfile.open("/home/mvibot/mvibot_ws/src/mvibot/data/l/"+to_string(realtime.tv_sec)+".txt",ios::app);
        // for(int i=0;i<my_data.my_points.size();i++){
        //     cmd=to_string(my_data.my_points[i].x)+"\t"+to_string(my_data.my_points[i].y)+"\n";
        //     myfile<<cmd;
        // }
        // myfile.close();
        //
    }
    return value_return;
}
int marker::detect_vl(){
    static int value_return;
    value_return=-1;
    static float ampha1;
    // vl detect
    static int num_group;
    static line line1,line2,line3;
    for(int i=0;i<my_data.my_lines2.size();i++){
        for(int j=1;j<my_data.my_lines2[i].size()-1;j++){
                static float ampha,beta,delta;
                ampha1=ampha;
                beta=my_data.my_lines2[i][j].caculate_atan2();
                delta=my_data.my_lines2[i][j+1].caculate_atan2();
                //
                static float dis1,dis2,dis3;
                dis1=my_data.my_lines2[i][j-1].caculate_dis();
                dis2=my_data.my_lines2[i][j].caculate_dis();
                dis3=my_data.my_lines2[i][j+1].caculate_dis();
                if(fabs(fabs(delta-beta)-2*M_PI/3)<=M_PI/180*10 | fabs(fabs(delta-beta)-M_PI/3)<=M_PI/180*10)
                {
                    if(fabs(fabs(beta-ampha)-5*M_PI/6)< M_PI/180*10 | fabs(fabs(beta-ampha)-1*M_PI/6)< M_PI/180*10){
                        if(dis1>=0.35 &  dis2 >=0.15 & dis2 <=0.2 &  dis3>=0.15 & dis3 <=0.2){ 
                            value_return=1;
                            num_group=i;
                            line1=my_data.my_lines2[i][j-1];
                            line2=my_data.my_lines2[i][j];
                            line3=my_data.my_lines2[i][j+1];
                            //
                            line1.points.resize(0);
                            line2.points.resize(0);
                            line3.points.resize(0);
                            //
                            for(int k=0;k<my_data.my_group3[i].points.size();k++){
                                if(my_data.my_lines2[i][j-1].caculate_distance(my_data.my_group3[i].points[k]) <= 0.02) line1.addpoint(my_data.my_group3[i].points[k]);
                                if(my_data.my_lines2[i][j].caculate_distance(my_data.my_group3[i].points[k]) <= 0.02) line2.addpoint(my_data.my_group3[i].points[k]);
                                if(my_data.my_lines2[i][j+1].caculate_distance(my_data.my_group3[i].points[k]) <= 0.02) line3.addpoint(my_data.my_group3[i].points[k]);
                            }
                            line1.caculate();
                            line2.caculate();
                            line3.caculate();
                        }
                    }
                }
            }
    }
    if(value_return==1){
        static point point_1,point_2,point_3;
        //
        point_1.x=0;
        point_1.y=0;
        for(int i=0;i<line1.points.size();i++){
            point_1.x+=line1.points[i].x;
            point_1.y+=line1.points[i].y;
        }
        point_1.x=point_1.x/line1.points.size();
        point_1.y=point_1.y/line1.points.size();
        static  line line1_2;
        line1_2.points.resize(0);
        for(int i=0;i<line1.points.size();i++){
            static float dis_x,dis_y;
            dis_x=point_1.x-line1.points[i].x;
            dis_y=point_1.y-line1.points[i].y;
            if(sqrt(dis_x*dis_x+dis_y*dis_y)<=0.1) line1_2.addpoint(line1.points[i]);
        }
        line1_2.caculate();
        //
        point_2.x=0;
        point_2.y=0;
        for(int i=0;i<line2.points.size();i++){
            point_2.x+=line2.points[i].x;
            point_2.y+=line2.points[i].y;
        }
        point_2.x=point_2.x/line2.points.size();
        point_2.y=point_2.y/line2.points.size();
        static  line line2_2;
        line2_2.points.resize(0);
        for(int i=0;i<line2.points.size();i++){
            static float dis_x,dis_y;
            dis_x=point_2.x-line2.points[i].x;
            dis_y=point_2.y-line2.points[i].y;
            if(sqrt(dis_x*dis_x+dis_y*dis_y)<=0.05) line2_2.addpoint(line2.points[i]);
        }
        line2_2.caculate();
        //
         point_3.x=0;
         point_3.y=0;
        for(int i=0;i<line3.points.size();i++){
             point_3.x+=line3.points[i].x;
             point_3.y+=line3.points[i].y;
        }
        point_3.x= point_3.x/line3.points.size();
        point_3.y= point_3.y/line3.points.size();
        static  line line3_2;
        line3_2.points.resize(0);
        for(int i=0;i<line3.points.size();i++){
            static float dis_x,dis_y;
            dis_x= point_3.x-line3.points[i].x;
            dis_y= point_3.y-line3.points[i].y;
            if(sqrt(dis_x*dis_x+dis_y*dis_y)<=0.05) line3_2.addpoint(line3.points[i]);
        }
        line3_2.caculate();
        //
        //cout<<line1_2.caculate_atan2()/M_PI*180<<"A"<<line2_2.caculate_atan2()/M_PI*180<<"A"<<line3_2.caculate_atan2()/M_PI*180<<"A"<<endl;
        my_data.my_lines2[num_group].resize(3);
        my_data.my_lines2[num_group][0]=line1_2;
        my_data.my_lines2[num_group][1]=line2_2;
        my_data.my_lines2[num_group][2]=line3_2;
        //
        static point point_o;
        point_o=line_cut(line1_2,line2_2);
        cout<<"\t x:"<<point_o.x<<"|y:"<<point_o.y<<endl;
        static point point_o2,point_o3;
        point_o2=line_cut(line2_2,line3_2);
        point_o3=line_cut(line3_2,line1_2);
        //
        static float dis_1_2,dis_3_2;
        dis_1_2=sqrt((point_o.x-point_o2.x)*(point_o.x-point_o2.x)+(point_o.y-point_o2.y)*(point_o.y-point_o2.y));
        dis_3_2=sqrt((point_o3.x-point_o2.x)*(point_o3.x-point_o2.x)+(point_o3.y-point_o2.y)*(point_o3.y-point_o2.y));
        cout<<dis_1_2<<"|"<<dis_3_2<<endl;
        if(fabs(dis_1_2-0.15)<=0.03){
                my_pose.resize(1);
                my_pose[0].position.x=(double)point_o.x;
                my_pose[0].position.y=(double)point_o.y;
                //
                ampha1=line1_2.caculate_atan2();
                static tf2::Quaternion quat;
                static  geometry_msgs::msg::Quaternion quat_msg;
                if(ampha1>M_PI_2) ampha1=ampha1-M_PI;
                if(ampha1<-M_PI_2) ampha1=ampha1+M_PI;
                quat.setRPY(0,0,ampha1);
                quat_msg = tf2::toMsg(quat);
                my_pose[0].orientation=quat_msg;
                //UPDATE SAU
                // // save data to txt
                // static string cmd;
                // cmd="";
                // cmd=cmd+"echo "+to_string( my_pose[0].position.x)+"\t"+to_string( my_pose[0].position.y)+"\t"+to_string(getyaw(my_pose[0].orientation));
                // static struct timespec realtime;
                // clock_gettime(CLOCK_REALTIME, &realtime);
                // cmd=cmd+" >> /home/mvibot/mvibot_ws/src/mvibot/data/vl/"+to_string(realtime.tv_sec)+".txt";
                // system(cmd.c_str());
                // //
                // static ofstream myfile;
                // myfile.open("/home/mvibot/mvibot_ws/src/mvibot/data/vl/"+to_string(realtime.tv_sec)+".txt",ios::app);
                // for(int i=0;i<my_data.my_points.size();i++){
                //     cmd=to_string(my_data.my_points[i].x)+"\t"+to_string(my_data.my_points[i].y)+"\n";
                //     myfile<<cmd;
                // }
                // myfile.close();
                //
        }else value_return=0;
        //
    }
    //value_return=0;
    return value_return;
}

int marker::action(){
    static int value_return;
    static int res;
    value_return = Finish_;
    //
    if(status==0){
        std::cout<<"Collect data..."<<endl;
        if(marker_type=="none_marker_dis" || marker_type=="none_marker_angle"){
            status=1;
            std::cout<<"Finsish collect data..."<<endl;
        }
        else{
            if(my_data.process_data(marker_dir)){
                status=1;
                std::cout<<"Finsish collect data..."<<endl;
            }
        }
        value_return = Active_;
    }
    else if(status==1){
        if(marker_type=="none_marker_dis" || marker_type=="none_marker_angle"){
            status=2;
            std::cout<<"don 't near detect so skip"<<endl;
        }else{
            // detect maker
            res=1;
            if(marker_type=="vl_marker")    res=detect_vl();
            if(marker_type=="bar_marker")   res=detect_bar(bar_distance);
            if(marker_type=="l_marker")     res=detect_l();
            //
            if(res==1) {
                std::cout<<"\t Detect finsh"<<endl;
                std::cout<<"\t Continue caculate tranform offset...."<<endl;
                status=2;
            }
            else{
                my_data.reset();
                status=0;
                std::cout<<"Can't detect. Retry collet laser msg...."<<endl;
            }
        }
        value_return = Active_;
    }
    else if(status==2){
        res=caculate_transforms_ofset();
        if(res==1){
            status=3;
            pub_marker();
        }
        std::cout<<"Cacluate transfrom offset finish"<<endl;
        value_return = Active_;
    }
    else if(status>=3){
        send_tranform(x_set,y_set,z_set,w_set,mvibot_seri_+"/odom",mvibot_seri_+"/base_marker");
        if(new_update==1){
            new_update=0;
            t_send= clock_tf.now();
        }
        //
        if(status==3){
            std::cout<<"Check is send transform odom->base_marker"<<endl;
            res=check_send_transforms_tf_frame();
            if(res==1) status=4;
            value_return = Active_;
        }
        else if(status>=4){
            static int status_transfrom_pose;
            status_transfrom_pose=tranfrom_pose_marker(1,"base_maker", "base_footprint");
            if(status==4){
                std::cout<<"Check first pose is match with position robot!"<<endl;
                if(status_transfrom_pose==1){
                    if(check_first_tranfrom_pose_marker()){
                        std::cout<<"Fisrt pose is match with postion robot"<<endl;
                        status=5;
                    }
                }
                value_return = Active_;
            }
            else if(status==5){
                std::cout<<"Get footprint robot!"<<endl;
                if(get_footprint() == 1) {
                    std::cout<<"Finish get footprint robot!"<<endl;                  
                    status=6;
                    active_step=0;
                }
                value_return = Active_;
            }
            else if(status==6){
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
                            status=0;
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
        my_data.reset();
        process_data(marker_data);
        status=0;
        active_step=0;
        new_update=0;
    }else if(mode==1){
        my_data.reset();
        status=0;
        active_step=0;
        new_update=0;
    }
   
}