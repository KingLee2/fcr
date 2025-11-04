#include "mvibot_core_init.h"

using namespace std;
//
int start_software_launch=0;
// radar1 status
int radar1_live=0;
float time_live_radar1=0;
// radar2 status
int radar2_live=0;
float time_live_radar2=0;
// camera1 status
int camera1_live=0;
int camera1_config=0;
float time_live_camera1=0;
// camera2 status
int camera2_live=0;
int camera2_config=0;
float time_live_camera2=0;
// uart
// int uart_live=0;
// battery status
int battery_status=0;
float time_live_batterry=0;
// battery small status
int battery_small_status=0;
float time_live_batterry_small=0;
// ready sensor when radar 1 2 camera 1 2 is ready
int dym_set_camera1=0,dym_set_camera2=0;
int reset_radar1,reset_radar2,reset_camera1,reset_camera2;

class sensor : public rclcpp::Node{
    public:
        void send_history(string status, string info){
            static std_msgs::msg::String history_msg;
            history_msg.data = mvibot_seri+"|" + "status:"+status + "|" + "content:" + info;
            history_pub_->publish(history_msg);
        }
        void pub_sensor_status(){
            static std_msgs::msg::String sensor_status_msg;
            static float create_fun = 0;
            if(create_fun==1){
                sensor_status_msg.data=mvibot_seri+"|";
                sensor_status_msg.data=sensor_status_msg.data+"uart:"+to_string((int)local_uart_live)+"|";
                sensor_status_msg.data=sensor_status_msg.data+"radar1:"+to_string((int)radar1_live)+"|";
                sensor_status_msg.data=sensor_status_msg.data+"radar2:"+to_string((int)radar2_live)+"|";
                sensor_status_msg.data=sensor_status_msg.data+"camera1:"+to_string((int)camera1_live)+"|";
                sensor_status_msg.data=sensor_status_msg.data+"camera2:"+to_string((int)camera2_live)+"|";
                sensor_status_msg.data=sensor_status_msg.data+"battery:"+to_string((int)battery_status);
                // sensor_status_msg.data=sensor_status_msg.data+"battery_small:"+to_string((int)battery_small_status);
                sensor_status_pub_->publish(sensor_status_msg);
                // RCLCPP_INFO(this->get_logger(),"SEND SENSOR STATUS");
            }else create_fun=1;
        }
        void check_sensor(){
            {
                std::lock_guard<std::mutex> lock(mutex_socket);
                local_uart_live = uart_live;
            }
            std::lock_guard<std::mutex> lock(mutex_sensor);
            // radar1 
            if(radar1_live_status==1){
                if(time_live_radar1<0) time_live_radar1=0;
                else time_live_radar1+=(float)ts_scan_sensor;
                if(time_live_radar1>=2.0) time_live_radar1=2.0;
            }else{
                if(time_live_radar1>0) time_live_radar1=0;
                else time_live_radar1-=(float)ts_scan_sensor;
                if(time_live_radar1<=-30.0) time_live_radar1=-30.0;
            }
            radar1_live_status=0;
            if(time_live_radar1>=2.0){
                if(radar1_live==0){
                    send_history("normal","Radar1 is available");
                    radar1_live=1;
                    RCLCPP_INFO(this->get_logger(),"Radar1 is available");
                }
            }
            else{
                if(radar1_live==1){
                    // time to restartup sensor when sensor is live before
                    if(time_live_radar1<=-3.0) 
                    {
                        radar1_live=0;
                        time_live_radar1=0;
                        reset_radar1=1;
                        send_history("error","Restart radar1 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart radar1 because no signal");
                    }
                }else{
                    // time to restartup sensor
                    if(time_live_radar1<=-5.0){
                        radar1_live=0;
                        time_live_radar1=0;
                        reset_radar1=1;
                        send_history("error","Restart radar1 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart radar1 because no signal");
                    }
                }
            }
            // radar2
            if(radar2_live_status==1){
                if(time_live_radar2<0) time_live_radar2=0;
                else time_live_radar2+=(float)ts_scan_sensor;
                if(time_live_radar2>=2.0) time_live_radar2=2.0;
            }else{
                if(time_live_radar2>0) time_live_radar2=0;
                else time_live_radar2-=(float)ts_scan_sensor;
                if(time_live_radar2<=-30.0) time_live_radar2=-30.0;
            }
            radar2_live_status=0;
            if(time_live_radar2>=2.0){
                if(radar2_live==0){ 
                    send_history("normal","Radar2 is available");
                    radar2_live=1;
                    RCLCPP_INFO(this->get_logger(),"Radar2 is available");
                }
            }
            else{
                if(radar2_live==1){
                    // time to restartup sensor when sensor is live before
                    if(time_live_radar2<=-3.0) 
                    {
                        radar2_live=0;
                        time_live_radar2=0;
                        reset_radar2=1;
                        send_history("error","Restart radar2 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart radar2 because no signal");
                    }
                }else{
                    // time to restartup sensor
                    if(time_live_radar2<=-5.0){
                        radar2_live=0;
                        time_live_radar2=0;
                        reset_radar2=1;
                        send_history("error","Restart radar2 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart radar2 because no signal");
                    }
                }
            }
            // camera1
            if(camera1_live_status==1){
                if(time_live_camera1<0) time_live_camera1=0;
                else time_live_camera1+=(float)ts_scan_sensor;
                if(time_live_camera1>=5.0) time_live_camera1=5.0;
            }else{
                if(time_live_camera1>0) time_live_camera1=0;
                else time_live_camera1-=(float)ts_scan_sensor;
                if(time_live_camera1<=-30.0) time_live_camera1=-30.0;
            }
            camera1_live_status=0;
            if(time_live_camera1>=5.0){
                if(camera1_live==0){
                    send_history("normal","Camera1 is available");
                    camera1_live=1;
                    dym_set_camera1=1;
                    RCLCPP_INFO(this->get_logger(),"Camera1 is available");
                }
            }
            else{
                if(camera1_live==1){
                    // time to restartup sensor when sensor is live before
                    if(time_live_camera1<=-5.0) 
                    {
                        camera1_live=0;
                        time_live_camera1=0;
                        reset_camera1=1;
                        send_history("error","Restart camera1 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart camera1 because no signal");
                    }
                }else{
                    // time to restartup sensor
                    if(time_live_camera1<=-30.0){
                        camera1_live=0;
                        time_live_camera1=0;
                        reset_camera1=1;
                        send_history("error","Restart camera1 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart camera1 because no signal");
                    }
                }
            }
            // camera2
            if(camera2_live_status==1){
                if(time_live_camera2<0) time_live_camera2=0;
                else time_live_camera2+=(float)ts_scan_sensor;
                if(time_live_camera2>=5.0) time_live_camera2=5.0;
            }else{
                if(time_live_camera2>0) time_live_camera2=0;
                else time_live_camera2-=(float)ts_scan_sensor;
                if(time_live_camera2<=-30.0) time_live_camera2=-30.0;
            }
            camera2_live_status=0;
            if(time_live_camera2>=5.0) {
                if(camera2_live==0){
                    send_history("normal","Camera2 is available");
                    camera2_live=1;
                    dym_set_camera2=1;
                    RCLCPP_INFO(this->get_logger(),"Camera2 is available");
                }
            }
            else{
                if(camera2_live==1){
                    // time to restartup sensor when sensor is live before
                    if(time_live_camera2<=-5.0) 
                    {
                        camera2_live=0;
                        time_live_camera2=0;
                        reset_camera2=1;
                        send_history("error","Restart camera2 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart camera2 because no signal");
                    }
                }else{
                    // time to restartup sensor
                    if(time_live_camera2<=-30.0){
                        camera2_live=0;
                        time_live_camera2=0;
                        reset_camera2=1;
                        send_history("error","Restart camera2 because no signal");
                        RCLCPP_INFO(this->get_logger(),"Restart camera2 because no signal");
                    }
                }
            }
            if(radar1_live==1 && radar2_live==1 && camera1_live==1 && camera2_live==1 && local_uart_live==1) mvibot_sensor_ready=1;
            else mvibot_sensor_ready=0;
            RCLCPP_INFO(rclcpp::get_logger("Sensor"), "mvibot_sensor_ready: %d", mvibot_sensor_ready);
            // first time ready -> start launch mvibot software
            if(start_software_launch==0 && mvibot_sensor_ready==1){
                //
                send_history("normal","Sensor startup success. Start up mode: "+mode);
                RCLCPP_INFO(rclcpp::get_logger("sensor"),"Sensor startup success. Start up mode: %s",mode);
                //// TAM THOI CHUA KICH HOAT
                // static string command;
                start_software_launch=1;
                // command="";
                // command=command+"roslaunch mvibot_v4 mvibot_software.launch name_seri:="+mvibot_seri+" mode:="+mode+" &";
                // system(command.c_str());
            }
            // battery check
            if(battery_live_status==1 && local_uart_live==1){
                if(time_live_batterry<0) time_live_batterry=0;
                else{
                    time_live_batterry+=(float)ts_scan_sensor;
                    if(time_live_batterry>=5.0) time_live_batterry=5.0;
                }
            }else{
                if(time_live_batterry>0) time_live_batterry=0;
                else{
                    time_live_batterry-=(float)ts_scan_sensor;
                    if(time_live_batterry<=-5.0) time_live_batterry=-5.0;
                }
            }
            battery_live_status=0;
            if(time_live_batterry>=3.0){
                if(battery_status!=1) send_history("normal","Battery is available");
                battery_status=1;
                // RCLCPP_INFO(this->get_logger(),"Battery is available");
            }
            if(time_live_batterry<=-2.0){
                if(battery_status!=0) send_history("error","Battery no signal");
                battery_status=0;
                // RCLCPP_INFO(this->get_logger(),"Battery no signal");
            }
            //pub sensor status
            pub_sensor_status();
        }

        sensor(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            ts_scan_sensor = 1.0;
            auto laser_scan1_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_sensor);
                radar1_live_status = 1;
                // RCLCPP_INFO(this->get_logger(),"RECEIVE DATA RADAR1");
                // unlock();
            };
            laser_scan1_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan1",qos_profile,laser_scan1_callback);
            // laser_scan1_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan1",qos_profile,laser_scan1_callback, sub_options);
            auto laser_scan2_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_sensor);
                radar2_live_status = 1;
                // RCLCPP_INFO(this->get_logger(),"RECEIVE DATA RADAR2");
                // unlock();
            };
            laser_scan2_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan1",qos_profile,laser_scan2_callback);
            // laser_scan2_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan1",qos_profile,laser_scan2_callback, sub_options);
            auto camera1_scan_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_sensor);
                camera1_live_status = 1;
                // RCLCPP_INFO(this->get_logger(),"RECEIVE DATA CAMERA1");
                // unlock();
            };
            camera1_scan_sub_ =  this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/camera1/scan",qos_profile,camera1_scan_callback);
            // camera1_scan_sub_ =  this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/camera1/scan",qos_profile,camera1_scan_callback, sub_options);
            auto camera2_scan_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_sensor);
                camera2_live_status = 1;
                // RCLCPP_INFO(this->get_logger(),"RECEIVE DATA CAMERA2");
                // unlock();
            };
            camera2_scan_sub_ =  this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/camera2/scan",qos_profile,camera2_scan_callback);
            // camera2_scan_sub_ =  this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/camera2/scan",qos_profile,camera2_scan_callback, sub_options);
            //pub history
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            //pub sensor status
            sensor_status_pub_ = this->create_publisher<std_msgs::msg::String>("sensor_status",1);
            //check sensor
            auto check_sensor_timer_callback = [this]()->void{
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                check_sensor();
                // unlock();
            };
            check_sensor_Timer_ = this->create_wall_timer(1000ms,check_sensor_timer_callback); //1000ms
            // check_sensor_Timer_ = this->create_wall_timer(1000ms,check_sensor_timer_callback, mutuallyExclusive_cbg);
        }

    private:
        //sub sensor data
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan1_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan2_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr camera1_scan_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr camera2_scan_sub_;
        //pub sensor status
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr  sensor_status_pub_;
        //pub history
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        //check sensor
        rclcpp::TimerBase::SharedPtr check_sensor_Timer_;
        string mvibot_seri_;
        float ts_scan_sensor;
        //
        int local_uart_live;
};