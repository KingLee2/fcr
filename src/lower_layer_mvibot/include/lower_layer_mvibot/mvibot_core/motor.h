#include "mvibot_core_init.h"
using namespace std;

class motor : public rclcpp::Node{
    public:
        motor(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            ts_speed_control = 0.05;
            ts_pid = 0.05;
            v_set1 = 0.0;
            v_set2 = 0.0;
            v_set3 = 0.0;
            w_set1 = 0.0;
            w_set2 = 0.0;
            w_set3 = 0.0;
            //create sub
            auto motor_enable_callback = [this](std_msgs::msg::String::SharedPtr msg){
                static const std::string& message= msg->data;
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_motor);
                if(message=="0") motor_enable=0;
                if(message=="1") motor_enable=1;
                // unlock();
            };
            motor_enable_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_enable", qos_profile, motor_enable_callback);
            // motor_enable_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_enable", qos_profile, motor_enable_callback, sub_options);
            auto motor_break_callback = [this](std_msgs::msg::String::SharedPtr msg){
                static const std::string& message= msg->data;
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_motor);
                if(message=="0") motor_break=0;
                if(message=="1") motor_break=1;
                // unlock();
            };
            motor_break_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_break", qos_profile, motor_break_callback);
            // motor_break_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_break", qos_profile, motor_break_callback, sub_options);
            auto motor_reset_callback = [this](std_msgs::msg::String::SharedPtr msg){
                static const std::string& message= msg->data;
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_motor);
                if(message=="1") motor_reset=1;
                // unlock();
            };
            motor_reset_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_reset", qos_profile, motor_reset_callback);
            // motor_reset_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_reset", qos_profile, motor_reset_callback, sub_options);
            auto robot_vel_callback = [this](geometry_msgs::msg::Twist::SharedPtr msg)->void{
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                {
                    std::lock_guard<std::mutex> lock(mutex_sensor);
                    local_mvibot_sensor_ready = mvibot_sensor_ready;
                }
                std::lock_guard<std::mutex> lock(mutex_motor);
                time_out_cmd_vel=0;
                // RCLCPP_INFO(rclcpp::get_logger("Motor"), "before receive veloc");
                if(local_mvibot_sensor_ready==1){
                    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "after receive veloc");
                    v_set1=msg->linear.x;
                    w_set1=msg->angular.z;
                    if(fabs(v_set1)>=v_max) v_set1=fabs(v_set1)/v_set1*v_max;
                    if(fabs(w_set1)>=w_max) w_set1=fabs(w_set1)/w_set1*w_max;
                }
                // unlock();
            };
            robot_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(mvibot_seri_+"/cmd_vel", qos_profile, robot_vel_callback);
            // robot_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(mvibot_seri_+"/cmd_vel", qos_profile, robot_vel_callback, sub_options);
            //create pub
            //pub history
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            //publish motor right status
            motor_right_status_pub_ = this->create_publisher<std_msgs::msg::String>("motor_right_status",1);
            auto motor_right_status_timer_callback = [this]()->void{
                static float creat_fun=0;
                static std_msgs::msg::String msg;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_motor);
                if(creat_fun==1){ 
                    msg.data=mvibot_seri+"|";
                    msg.data=msg.data+"live:"+to_string((int)motor_right_state_live)+"|";
                    msg.data=msg.data+"error:"+to_string((int)motor_right_state_error)+"|";
                    msg.data=msg.data+"enable:"+to_string((int)motor_right_disable)+"|";
                    msg.data=msg.data+"brake:"+to_string((int)motor_right_break);
                    motor_right_status_pub_->publish(msg);
                    //
                    static int live=-1,live_f=-1,brake=-1,brake_f=-1,enable=-1,enable_f=-1,error=-1,error_f=-1;
                    live=motor_right_state_live;
                    error=motor_right_state_error;
                    enable=motor_right_disable;
                    brake=motor_right_break;
                    // cout<<"Motor_right|live: "<<live<<"|live_f: "<<live_f<<endl;
                    //
                    if(live_f==-1 || (live!=live_f)){
                        if(live==0) {
                            send_history("warning","Motor right turn off");
                            // RCLCPP_INFO(this->get_logger(),"Motor right turn off");
                        }
                        else {
                            send_history("warning","Motor right turn on");
                            // RCLCPP_INFO(this->get_logger(),"Motor right turn on");
                        }
                        live_f=live;
                    }else{
                        if(live==1){
                            if(error_f!=error){
                                error_f=error;
                                if(error!=0) {
                                    send_history("error","Motor right error id:"+to_string(error));
                                    // RCLCPP_INFO(this->get_logger(),"Motor right error");
                                }
                                else {
                                    send_history("normal","Motor right no error");
                                    // RCLCPP_INFO(this->get_logger(),"Motor right no error");
                                }
                            }
                            if(enable_f!=enable){
                                enable_f=enable;
                                if(enable!=0) {
                                    send_history("normal","Motor right change to mode automation control");
                                    // RCLCPP_INFO(this->get_logger(),"Motor right change to mode automation control");
                                }
                                else {
                                    send_history("normal","Motor right change to mode manual handle");
                                    // RCLCPP_INFO(this->get_logger(),"Motor right change to mode manual handle");
                                }
                            }
                            if(brake_f!=brake){
                                brake_f=brake;
                                if(brake!=0) {
                                    send_history("normal","Motor right disable brake");
                                    // RCLCPP_INFO(this->get_logger(),"Motor right disable brake");
                                }
                                else {
                                    send_history("normal","Motor right enable brake");
                                    // RCLCPP_INFO(this->get_logger(),"Motor right enable brake");
                                }
                            }
                        }
                    }
                }else creat_fun=1;
            };
            motor_right_status_timer_ = this->create_wall_timer(1000ms,motor_right_status_timer_callback);
            // motor_right_status_timer_ = this->create_wall_timer(1000ms,motor_right_status_timer_callback, mutuallyExclusive_cbg);
            //publish motor left status
            motor_left_status_pub_ = this->create_publisher<std_msgs::msg::String>("motor_left_status",1);
            auto motor_left_status_timer_callback = [this]()->void{
                static float creat_fun=0;
                static std_msgs::msg::String msg;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_motor);
                if(creat_fun==1){ 
                    msg.data=mvibot_seri+"|";
                    msg.data=msg.data+"live:"+to_string((int)motor_left_state_live)+"|";
                    msg.data=msg.data+"error:"+to_string((int)motor_left_state_error)+"|";
                    msg.data=msg.data+"enable:"+to_string((int)motor_left_disable)+"|";
                    msg.data=msg.data+"brake:"+to_string((int)motor_left_break);
                    motor_left_status_pub_->publish(msg);
                    //
                    static int live=-1,live_f=-1,brake=-1,brake_f=-1,enable=-1,enable_f=-1,error=-1,error_f=-1;
                    live=motor_left_state_live;
                    error=motor_left_state_error;
                    enable=motor_left_disable;
                    brake=motor_left_break;
                    // cout<<"Motor_left|live: "<<live<<"|live_f: "<<live_f<<endl;
                    if(live_f==-1 || (live!=live_f)){
                        if(live==0) {
                            send_history("warning","Motor left turn off");
                            // RCLCPP_INFO(this->get_logger(),"Motor left turn off");
                        }
                        else {
                            send_history("warning","Motor left turn on");
                            // RCLCPP_INFO(this->get_logger(),"Motor left turn on");
                        }
                        live_f=live;
                    }else{
                        if(live==1){
                            if(error_f!=error){
                                error_f=error;
                                if(error!=0) {
                                    send_history("error","Motor left error id:"+to_string(error));
                                    // RCLCPP_INFO(this->get_logger(),"Motor left error");
                                }
                                else {
                                    send_history("normal","Motor left no error");
                                    // RCLCPP_INFO(this->get_logger(),"Motor right no error");
                                }
                            }
                            if(enable_f!=enable){
                                enable_f=enable;
                                if(enable!=0) {
                                    send_history("normal","Motor left change to mode automation control");
                                    // RCLCPP_INFO(this->get_logger(),"Motor left change to mode automation control");
                                }
                                else {
                                    send_history("normal","Motor left change to mode manual handle");
                                    // RCLCPP_INFO(this->get_logger(),"Motor right change to mode manual handle");
                                }
                            }
                            if(brake_f!=brake){
                                brake_f=brake;
                                if(brake!=0) {
                                    send_history("normal","Motor left disable brake");
                                    // RCLCPP_INFO(this->get_logger(),"Motor left disable brake");
                                }
                                else {
                                    send_history("normal","Motor left enable brake");
                                    // RCLCPP_INFO(this->get_logger(),"Motor left enable brake");
                                }
                            }
                        }
                    }
                    //
                }else creat_fun=1;
            };
            motor_left_status_timer_ = this->create_wall_timer(1000ms,motor_left_status_timer_callback);
            // motor_left_status_timer_ = this->create_wall_timer(1000ms,motor_left_status_timer_callback, mutuallyExclusive_cbg);
            auto control_motor_timer_callback = [this]()->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                {
                    std::lock_guard<std::mutex> lock(mutex_socket);
                    local_data_socket_ready = data_socket_ready;
                }
                {
                    std::lock_guard<std::mutex> lock(mutex_odom);
                    local_vl = vl;
                    local_vr = vr;
                }
                std::lock_guard<std::mutex> lock(mutex_motor);
                // RCLCPP_INFO(rclcpp::get_logger("Motor"), "control motor");
                if(local_data_socket_ready==1){
                    {
                        std::lock_guard<std::mutex> lock(mutex_sensor);
                        local_mvibot_sensor_ready = mvibot_sensor_ready;
                    }
                    //
                    rclcpp::Time now = this->get_clock()->now();
                    if (check_time_motor.nanoseconds() > 0) {
                        rclcpp::Duration dt = now - check_time_motor;
                        RCLCPP_INFO(this->get_logger(), "calculate motor with period: %.6f s", dt.seconds());
                    }
                    check_time_motor = now;
                    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "v_set1: %f, w_set1: %f", v_set1, w_set1);
                    speed_robot_control();
                    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "v_set3: %f, w_set3: %f", v_set3, w_set3);
                    pid_motor();
                    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "vr_out: %f, vl_out: %f", vr_out, vl_out);
                    torque_control();
                    // control_motor = 0;
                }
            };
            control_motor_timer_= this->create_wall_timer(50ms,control_motor_timer_callback);
            // control_motor_timer_= this->create_wall_timer(50ms,control_motor_timer_callback, reentrant_cbg);
        }
        void send_history(string status, string info){
            static std_msgs::msg::String history_msg;
            history_msg.data = mvibot_seri+"|" + "status:"+status + "|" + "content:" + info;
            history_pub_->publish(history_msg);
        }
        void pid_motor(){
            // caculate for speed motor
            vl_set=(2*v_set3-w_set3*L)/(2*R);
            vr_set=(2*v_set3+w_set3*L)/(2*R);
            // pid motor 
            ivr=ivr+(vr_set-vr)*(float)ts_pid;
            //
            if(fabs(ivr)*kivrl>vrl_max) {
                if(ivr>0) ivr=vrl_max*kivrl;
                if(ivr<0) ivr=-vrl_max*kivrl;
            }
            //
            vr_out=kpvrl*(vr_set-vr)+kivrl*ivr;	
            if(fabs(vr_out)>vrl_max) vr_out=fabs(vr_out)/vr_out*vrl_max;
            if(vr_set==0 && fabs(vr)<=M_PI/(2*2.5)) {
                vr_out=0;
                ivr=0;
            } 
            ivl=ivl+(vl_set-vl)*(float)ts_pid;
            //
            if(fabs(ivl)*kivrl>vrl_max){
                if(ivl>0) ivl=vrl_max*kivrl;
                if(ivl<0) ivl=-vrl_max*kivrl;
            }
            //
            vl_out=kpvrl*(vl_set-vl)+kivrl*ivl;
            if(fabs(vl_out)>vrl_max) vl_out=fabs(vl_out)/vl_out*vrl_max;
            if(vl_set==0 && fabs(vl) <= M_PI/(2*2.5)) {
                vl_out=0;
                ivl=0;
            }
            // robot emg
            if(robot_emg==1){
                vr_out=0;
                ivr=0;
                vl_out=0;
                ivl=0;
                robot_emg=0;
            }
            //
        }
        void speed_robot_control(){
            // time out cmd_vel
            if(v_set1 !=0 || w_set1 !=0){
                if(time_out_cmd_vel>=0.5){
                    v_set1=0;
                    w_set1=0;
                    time_out_cmd_vel=0.5;
                }else time_out_cmd_vel+=(float)ts_speed_control;
            }else time_out_cmd_vel=0;
            // motor stop
            static int stop;
            stop=0;
            //
            if(motor_enable==0) stop=1;
            if(motor_stop==1)   stop=1;
            if(motor_left_state_live==0 || motor_right_state_live==0) stop=1;
            if(motor_right_disable==0 || motor_left_disable==0) stop=1;
            if(motor_left_state_error!=0 || motor_right_state_error!=0) stop=1;
        
        
            //
            if(stop==1){
                // reset linear 
                v_set1=0;
                v_set2=0;
                v_set3=0;
                // reset rotary
                w_set1=0;
                w_set2=0;
                w_set3=0;
                // reset pid value
                vr_set=0;
                vl_set=0;
                vl_out=0;
                vr_out=0; 
                ivl=0;
                ivr=0;
                if(motor_stop==1) motor_stop=0;
            }else{
                if(local_mvibot_sensor_ready==0){
                    v_set1=0;
                    w_set1=0;
                }
                // acceleration for robot
                if(v_set1>v_set2) {
                    v_set2+=ax*(float)ts_speed_control;
                    if(v_set2>v_set1) v_set2=v_set1;
                }
                if(v_set1<v_set2){
                    v_set2-=ax*(float)ts_speed_control;
                    if(v_set2<v_set1) v_set2=v_set1;
                }
                if(w_set1>w_set2) {
                        w_set2+=aw*(float)ts_speed_control;
                        if(w_set2>w_set1) w_set2=w_set1;
                }
                if(w_set1<w_set2){
                        w_set2-=aw*(float)ts_speed_control;
                        if(w_set2<w_set1) w_set2=w_set1;
                }
                // if have iso safe, must write here -> v_set3 w_set3
                v_set3=v_set2;
                w_set3=w_set2;
            }
        }
        void torque_control(){
        }
        void reset_pid_motor(){
            vr_set=0;
            vl_set=0;
            vl_out=0;
            vr_out=0; 
            ivl=0;
            ivr=0;
        }
    private:
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_enable_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_break_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_reset_sub_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr robot_vel_sub_;
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr motor_right_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr motor_left_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr motor_right_status_timer_;
        rclcpp::TimerBase::SharedPtr motor_left_status_timer_;
        rclcpp::TimerBase::SharedPtr control_motor_timer_;
        //declare var
        string mvibot_seri_;
        float ts_speed_control;
        float ts_pid;
        float time_out_cmd_vel;
        int motor_stop=0;
        int robot_emg;
        float v_set1,v_set2,v_set3,w_set1,w_set2,w_set3;
        //
        int local_mvibot_sensor_ready;
        int local_data_socket_ready;
        float local_vl, local_vr;
        //var check time motor
        rclcpp::Time check_time_motor;
};
