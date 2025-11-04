#include "mvibot_server_init.h"

using namespace std;
    class fcr_server : public rclcpp::Node{
    private:
        //mutex var
        // std::recursive_mutex mutex_common;
        //robot var
        string mvibot_seri_, mvibot_seri_f_;
        //map var
        nav_msgs::msg::OccupancyGrid my_map;
        int save_map_ = -1;
        int load_map_ = -1;
        // nav_msgs::msg::OccupancyGrid map_selector;
        //declare pub//
        rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr map_pub_;
        //declare sub//
        //sub map
        rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr map_request_sub_;
        //sub robot
        // rclcpp::Subscription<std_msgs::msg::String>::SharedPtr history_robot_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr robot_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr infor_robot_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sensor_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr battery_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr battery_cell_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_right_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_left_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr input_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr output_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr robot_config_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr pos_robot_sub_;
        //sub request reset slam_toolbox
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr reset_slam_toolbox_sub_;
        //declare service //
        rclcpp::Client<nav2_msgs::srv::SaveMap>::SharedPtr save_map_srv_;
        rclcpp::Client<nav2_msgs::srv::LoadMap>::SharedPtr load_map_srv_;
        //declare timer
        rclcpp::TimerBase::SharedPtr map_timer_;
        rclcpp::TimerBase::SharedPtr reset_server_timer_;

    public:
        fcr_server(const string& node_name, const string& sub_namespace) : Node(node_name, sub_namespace){
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            rclcpp::QoS qos_profile(rclcpp::KeepLast(5));
            qos_profile.best_effort();
            rclcpp::QoS qos_profile_map(rclcpp::KeepLast(1));
            qos_profile_map.reliability(RMW_QOS_POLICY_RELIABILITY_RELIABLE);
            qos_profile_map.durability(RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL);
            //init pub//
            map_pub_ = this->create_publisher<nav_msgs::msg::OccupancyGrid>("map2",qos_profile_map);
            //init sub//
            //get robot
            auto robot_callback = [this](std_msgs::msg::String msg)->void{
                static int is_have = 0;
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                if(data.data1.size()==2){
                    for(int i=0;i<my_robots.size();i++){
                        if(my_robots[i].name_seri==data.data1[0]) {
                            is_have=1;
                            my_robots[i].time_out=0;
                        }
                    }
                    if(is_have==0){
                        my_robots.resize(my_robots.size()+1);
                        my_robots[my_robots.size()-1].name_seri=data.data1[0];
                        my_robots[my_robots.size()-1].type=data.data1[1];
                        my_robots[my_robots.size()-1].id=my_robots.size();
                        cout << "robot_id: "<<my_robots[my_robots.size()-1].id<<endl;
                        my_robots[my_robots.size()-1].update_database=0;
                        // my_robots[my_robots.size()-1].node=new node_v2_3;
                        // my_robots[my_robots.size()-1].node->name_seri=my_robots[my_robots.size()-1].name_seri;   
                        // my_robots[my_robots.size()-1].node->init();
                        // printf("Add new: %s \n" , my_robots[my_robots.size()-1].name_seri.c_str());
                    }
                }  

            };
            robot_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/robot",qos_profile, robot_callback);
            //get robot status
            auto robot_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].robot_status=msg.data;
                        break;
                    }
                }
            };
            infor_robot_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/robot_status", qos_profile, robot_status_callback);
            //get sensor status
            auto sensor_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].sensor_status=msg.data;
                        break;
                    }
                }
            };
            sensor_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/sensor_status", qos_profile, sensor_status_callback);
            //get battery status
            auto battery_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].battery_status=msg.data;
                        // my_robots[i].battery_status_chart=data.data1[0] + "|" + data.data1[1];
                        break;
                    }
                }
            };
            battery_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/battery_status", qos_profile, battery_status_callback);
            //get cell battery status
            auto battery_cell_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].battery_cell_status=msg.data;
                        break;
                    }
                }
            };
            battery_cell_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/battery_cell_status", qos_profile, battery_cell_status_callback);
            //get motor right status
            auto motor_right_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].motor_right_status=msg.data;
                        break;
                    }
                }
            };
            motor_right_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_right_status", qos_profile, motor_right_status_callback);
            //get motor left status
            auto motor_left_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].motor_left_status=msg.data;
                        break;
                    }
                }
            };
            motor_left_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_left_status", qos_profile, motor_left_status_callback);
            //get input status
            auto input_user_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].input_user_status=msg.data;
                        break;
                    }
                }
            };
            input_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/input_user_status_string", qos_profile, input_user_status_callback);
            //get output status
            auto output_user_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].output_user_status=msg.data;
                        break;
                    }
                }
            };
            output_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/output_user_status_string", qos_profile, output_user_status_callback);
            //get robot config
            auto robot_config_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].robot_config_status=msg.data;
                        break;
                    }
                }
            };
            robot_config_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/config_robot", qos_profile, robot_config_callback);
            //get pose robot
            auto pose_robot_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                std::lock_guard<std::recursive_mutex> lock(mutex_robot);
                data.detect(msg.data,"","|","");
                for(int i=0;i<my_robots.size();i++){
                    if(my_robots[i].name_seri==data.data1[0]){
                        my_robots[i].pose_robot=msg.data;
                        break;
                    }
                }
            };
            pos_robot_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/robot_position",qos_profile, pose_robot_callback);
            // auto history_robot_callback = [this](std_msgs::msg::String msg)->void{
            //     static string_Iv2 data;
            //     std::lock_guard<std::recursive_mutex> lock(mutex_robot);
            //     data.detect(msg.data,"","|","");
            //     for(int i=0;i<my_robots.size();i++){
            //         if(my_robots[i].name_seri==data.data1[0]){
            //             my_robots[i].history_robot=msg.data;
            //             break;
            //         }
            //     }
            // };
            // history_robot_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/history", qos_profile, history_robot_callback);
            //get map
            auto map_callback = [this](nav_msgs::msg::OccupancyGrid msg)->void{
                my_map = msg;
            };
            map_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(mvibot_seri_+"/map", qos_profile_map, map_callback);
            //get request map
            auto request_map_callback = [this](std_msgs::msg::String msg)->void{ //msg="request:0|action:active_map|name_map:...", request(save_map, delete_map, active_map)
                static string data;
                static string_Iv2 data1;
                std::lock_guard<std::recursive_mutex> lock(mutex_common);
                data = msg.data;
                data1.detect(data,"","|","");
                for(int i=0; i<data1.data1.size();i++){
                    static string_Iv2 data2;
                    data2.detect(data1.data1[i],"",":","");
                    if(data2.data1[0]=="request") request_map = stoi(data2.data1[1]);
                    else if(data2.data1[0]=="action") action_map = data2.data1[1];
                    else if(data2.data1[0]=="name_map") name_map = data2.data1[1];
                }
                if(action_map == "active_map") name_map_active =name_map;
            };
            map_request_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/request_map",qos_profile, request_map_callback);
            //reset slam toolbox
            auto reset_slam_toolbox_callback = [this](std_msgs::msg::String msg)->void{
                if(msg.data == "1"){
                    string cmd="";
                    cmd="ros2 lifecycle set /slam_toolbox deactivate";
                    system(cmd.c_str());
                    RCLCPP_INFO(this->get_logger(),"slam toolbox inactive");
                    sleep(5);
                    cmd="";
                    cmd="ros2 lifecycle set /slam_toolbox activate";
                    system(cmd.c_str());
                    RCLCPP_INFO(this->get_logger(),"slam toolbox active");
                }
            };
            reset_slam_toolbox_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/reset_slam_toolbox",qos_profile, reset_slam_toolbox_callback);
            //init service
            load_map_srv_=this->create_client<nav2_msgs::srv::LoadMap>("map_server/load_map");
            save_map_srv_=this->create_client<nav2_msgs::srv::SaveMap>("map_saver/save_map");
            //
            // name_map_active = "28_11ok";
            // run map server
            if(name_map_active!=""){
                string map_url;
                map_url = package_path + "maps/" + name_map_active + ".yaml";
                load_map(map_url);
                process_map_active = 1;
                update_map_database = 1;
                action_map = "active_map";
            }
            //init timer//
            auto map_timer_callback = [this]()->void{
                std::lock_guard<std::recursive_mutex> lock(mutex_common);
                //execute request(save_map, delete_map, active_map)
                process_request_map();
                //pub map with layer map
                cout<<"start pub map"<<endl;
                pub_map();
            };
            map_timer_ = this->create_wall_timer(100ms, map_timer_callback);
            auto reset_server_timer_callback = [this]()->void{
                
            };
            reset_server_timer_ = this->create_wall_timer(1000ms, reset_server_timer_callback);
        }
        double getyaw(geometry_msgs::msg::Quaternion quat_msg);
        nav_msgs::msg::OccupancyGrid get_map_select(string path);
        void pub_map();
        int load_map(string map_url);
        int save_map(string map_topic, string map_url);
        void process_request_map(); 
};
int fcr_server::load_map(string map_url){
    RCLCPP_INFO(rclcpp::get_logger("Map"), "Load Map");
    if(!load_map_srv_->wait_for_service(std::chrono::duration<float>(0.5))){
        RCLCPP_INFO(rclcpp::get_logger("Map"),"Load Map service not available");
        return 0;
    }
    //send request
    auto req = std::make_shared<nav2_msgs::srv::LoadMap_Request>();
    req->map_url = map_url;
    auto load_map_service_callback = [this](rclcpp::Client<nav2_msgs::srv::LoadMap>::SharedFuture result){
        if(result.get()->result == nav2_msgs::srv::LoadMap::Response::RESULT_SUCCESS){
            RCLCPP_INFO(rclcpp::get_logger("Map"),"Load Map successed");
            load_map_ = 1;
        }
        else {
            RCLCPP_INFO(rclcpp::get_logger("Map"),"Load Map not successed");
            load_map_ = 0;
        }
    };
    auto future = load_map_srv_->async_send_request(req,load_map_service_callback);
    return 1;
}
int fcr_server::save_map(string map_topic, string map_url){
    RCLCPP_INFO(rclcpp::get_logger("Map"), "Save Map");
    while(!save_map_srv_->wait_for_service(std::chrono::duration<float>(0.5))){
        RCLCPP_INFO(rclcpp::get_logger("Map"),"Save Map service not available");
        return 0;
    }
    //send request
    auto req = std::make_shared<nav2_msgs::srv::SaveMap_Request>();
    req->map_topic = map_topic;
    req->map_url = map_url;
    req->image_format = "pgm";
    req->map_mode = "trinary";
    req->free_thresh = 0.25;
    req->occupied_thresh = 0.65;
    auto save_map_service_callback = [this](rclcpp::Client<nav2_msgs::srv::SaveMap>::SharedFuture result){
        if(result.get()->result == 1){
            RCLCPP_INFO(rclcpp::get_logger("Map"),"Save Map successed");
            save_map_ = 1;
        }
        else {
            RCLCPP_INFO(rclcpp::get_logger("Map"),"Save Map not successed");
            save_map_ = 0;
        }
    };
    auto future = save_map_srv_->async_send_request(req,save_map_service_callback);
    return 1;
}
double fcr_server::getyaw(geometry_msgs::msg::Quaternion quat_msg){
    //get angle around Z
    double roll, pitch, yaw;
    tf2::Quaternion quat_tf;
    tf2::fromMsg(quat_msg, quat_tf);
    tf2::Matrix3x3(quat_tf).getRPY(roll, pitch, yaw);
    return yaw;
}
void fcr_server::pub_map(){
    static float creat_fun=0;
	if(creat_fun==1)
	{
        static int have_to_pub;
        // static uint32_t n=0;
        static nav_msgs::msg::OccupancyGrid map_var;
        have_to_pub=0;
        //kiem tra yeu cau lay map
        // if(request_map==1){
        //     request_map=0;
        //     have_to_pub=1;
        // }
        if(process_map_active ==1){
            process_map_active = 0;
            have_to_pub=1;
        }
        //kiem tra sub map
        // if(map_pub_->get_subscription_count()!=n){
        //     n=map_pub_->get_subscription_count();
        //     have_to_pub=1;
        // }
        //Kiem tra layer
        std::lock_guard<std::recursive_mutex> lock(mutext_layer_map);
        for(int i=0;i<my_layers.size();i++){
            if(my_layers[i].is_have==0) {
                have_to_pub=1;
                my_layers.erase(my_layers.begin()+i);
                i--;
            }
        }
        //Kiem tra pub layer
        for(int i=0;i<my_layers.size();i++){
            //
            if(my_layers[i].is_pub==0) {
                my_layers[i].is_pub=1;
                have_to_pub=1;
            }
        }
        if(have_to_pub==1){
            have_to_pub=0;
            // for(int i=0;i<my_map.data.size();i++) my_map.data[i]=-1;
            map_var=my_map;
            for(int i=0;i<map_var.data.size();i++)
            {
                static float x,y;
                static float x_origin,y_origin,yaw_origin;
                x_origin=map_var.info.origin.position.x;
                y_origin=map_var.info.origin.position.y;
                // yaw_origin=tf::getYaw(map_var.info.origin.orientation);
                yaw_origin = getyaw(map_var.info.origin.orientation);
                // convert to x y origin
                x=(float)(i-(uint32_t)(i/map_var.info.width)*map_var.info.width)*map_var.info.resolution;
                y=(float)((uint32_t)(i/map_var.info.width))*map_var.info.resolution;
                //
                x=x+x_origin;
                y=y+y_origin;
                //
                static float dis;
                dis=sqrt(x*x+y*y);
                static float ampha;
                ampha=atan2(y,x);
                //
                ampha=ampha+yaw_origin;
                x=dis*cos(ampha);
                y=dis*sin(ampha);
                // check cost map layer
                // cout<<"check cost map layer"<<endl;
                for(int j=0;j<my_layers.size();j++){
                    if(name_map_active==my_layers[j].name_map){
                        static float x_layer,y_layer,yaw_layer;
                        x_layer=x-my_layers[j].xo;
                        y_layer=y-my_layers[j].yo;
                        yaw_layer=0-my_layers[j].yawo;
                        //
                        static float dis_layer;
                        dis_layer=sqrt(x_layer*x_layer+y_layer*y_layer);
                        //
                        static float ampha_layer;
                        ampha_layer=atan2(y_layer,x_layer);
                        ampha_layer=ampha_layer+yaw_layer;
                        x_layer=dis_layer*cos(ampha_layer);
                        y_layer=dis_layer*sin(ampha_layer);
                        //
                        if(fabs(x_layer)<=my_layers[j].width/2 &  fabs(y_layer)<=my_layers[j].heigth/2) {
                            static float vlaue_cost;
                            if(my_layers[j].type_layer=="dead_zone") vlaue_cost=100;
                            if(my_layers[j].type_layer=="high_zone") vlaue_cost=95;
                            if(map_var.data[i] < vlaue_cost) map_var.data[i]=vlaue_cost;
                        }
                    }
                }
                //
            }
            cout<<"act pub map"<<endl;
            map_pub_->publish(map_var);
        }
	} else creat_fun=1;
}
void fcr_server::process_request_map(){
    if(request_map == 1){
        if(action_map == "save_map"){
            string map_topic, map_url;
            map_topic = "/map";
            map_url = package_path + "maps/" + name_map;
            save_map(map_topic, map_url);
            
        }
        else if(action_map == "delete_map"){
            static string cmd;
            cmd="";
            cmd=cmd+"rm "+package_path+"maps/"+name_map+".*";
            system(cmd.c_str());
        }
        else if(action_map == "active_map"){
            string map_url;
            map_url = package_path + "maps/" + name_map_active + ".yaml";
            load_map(map_url);
            process_map_active = 1;
        }
        request_map = 0;
        update_map_database = 1;
    }
}