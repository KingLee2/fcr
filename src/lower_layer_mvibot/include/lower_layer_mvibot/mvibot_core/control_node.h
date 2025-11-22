#include "mvibot_core_init.h"
#include "../common/string_Iv2.h"
using namespace std;

class control_node : public rclcpp::Node{
    public:
        control_node(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
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
            ////
            auto motor_enable_callback = [this](std_msgs::msg::String::SharedPtr msg){
                static const std::string& message= msg->data;
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_control);
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
                std::lock_guard<std::mutex> lock(mutex_control);
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
                std::lock_guard<std::mutex> lock(mutex_control);
                if(message=="1") motor_reset=1;
                // unlock();
            };
            motor_reset_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_reset", qos_profile, motor_reset_callback);
            // motor_reset_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_reset", qos_profile, motor_reset_callback, sub_options);
            auto robot_vel_callback = [this](geometry_msgs::msg::Twist::SharedPtr msg)->void{
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                {
                    std::lock_guard<std::mutex> lock(mutex_tool);
                    local_mvibot_sensor_ready = mvibot_sensor_ready;
                }
                std::lock_guard<std::mutex> lock(mutex_control);
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
            ////
            auto set_led_callback = [this](std_msgs::msg::Float32MultiArray::SharedPtr msg)->void{
                // static const auto& data = msg->data;
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_control);
                // red=data[0]/255*100;
                // green=data[1]/255*100;
                // blue=data[2]/255*100;
                // //
                // led_l=data[3];
                // led_r=data[4];
                // led_b=data[5];
                // led_f=data[6];
                red=msg->data[0]/255*100;
                green=msg->data[1]/255*100;
                blue=msg->data[2]/255*100;
                //
                led_l=msg->data[3];
                led_r=msg->data[4];
                led_b=msg->data[5];
                led_f=msg->data[6];
                // unlock();
            };
            set_led_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_ + "/set_led", qos_profile, set_led_callback);
            // set_led_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_ + "/set_led", qos_profile, set_led_callback, sub_options);
            ////
            auto output_user_set_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data1;
                static string_Iv2 data2;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_control);
                data1.detect(msg.data,"","|","");
                for(int i=1; i< data1.data1.size(); i++){
                    data2.detect(data1.data1[i],"",":","");
                    for(int j=0; j< output_user.data.size();j++){
                        if(stoi(data2.data1[0]) == j){
                            output_user.data[j] = stoi(data2.data1[1]);
                        }
                    }
                }
            };
            output_user_set_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/output_user_set",qos_profile, output_user_set_callback);
            // output_user_set_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/output_user_set",qos_profile, output_user_set_callback, sub_options);
            //create pub
            //pub history
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            //publish motor status
            motor_right_status_pub_ = this->create_publisher<std_msgs::msg::String>("motor_right_status",1);
            motor_left_status_pub_ = this->create_publisher<std_msgs::msg::String>("motor_left_status",1);
            //pub gpio
            output_user_status_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("output_user_status",1);
            output_user_status_string_pub_ = this->create_publisher<std_msgs::msg::String>("output_user_status_string",1);
            input_user_status_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("input_user_status",1);
            input_user_status_string_pub_ = this->create_publisher<std_msgs::msg::String>("input_user_status_string",1);
            //
            auto motor_status_timer_callback = [this]()->void{
                static float creat_fun=0;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_motor);
                if(creat_fun==1){ 
                    motor_right_status();
                    motor_left_status();
                }else creat_fun=1;
            };
            motor_status_timer_ = this->create_wall_timer(1000ms,motor_status_timer_callback);
            // motor_right_status_timer_ = this->create_wall_timer(1000ms,motor_status_timer_callback, mutuallyExclusive_cbg);
            auto control_timer_callback = [this]()->void{
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
                 //
                {
                    std::lock_guard<std::mutex> lock(mutex_tool);
                    local_mode = mode;
                    local_n_re_connect = n_re_connect;
                    local_software_update = software_update;
                    local_software_update_status = software_update_status;
                    local_battery_soc = battery_soc;
                    local_low_battery = low_battery;
                    local_mvibot_sensor_ready = mvibot_sensor_ready;
                    local_battery_status_charge = battery_status_charge;
                }
                std::lock_guard<std::mutex> lock(mutex_control);
                // RCLCPP_INFO(rclcpp::get_logger("Motor"), "control motor");
                if(local_data_socket_ready==1){
                    //
                    rclcpp::Time now = this->get_clock()->now();
                    if (check_time_control.nanoseconds() > 0) {
                        rclcpp::Duration dt = now - check_time_control;
                        RCLCPP_INFO(this->get_logger(), "calculate motor with period: %.6f s", dt.seconds());
                    }
                    check_time_control = now;
                    //motor
                    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "v_set1: %f, w_set1: %f", v_set1, w_set1);
                    speed_robot_control();
                    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "v_set3: %f, w_set3: %f", v_set3, w_set3);
                    pid_motor();
                    // RCLCPP_INFO(rclcpp::get_logger("Motor"), "vr_out: %f, vl_out: %f", vr_out, vl_out);
                    torque_control();
                    // control_motor = 0;
                    //led
                    led_control();
                    //gpio
                    pub_output_user_status();
                    pub_input_user_status();
                    //music

                }
            };
            control_timer_= this->create_wall_timer(50ms,control_timer_callback);
            // control_motor_timer_= this->create_wall_timer(50ms,control_motor_timer_callback, reentrant_cbg);
        }
        void send_history(string status, string info){
            static std_msgs::msg::String history_msg;
            history_msg.data = mvibot_seri+"|" + "status:"+status + "|" + "content:" + info;
            history_pub_->publish(history_msg);
        }
        void motor_right_status(){
            static float creat_fun=0;
            static std_msgs::msg::String motor_right_msg;
            if(creat_fun==1){ 
                motor_right_msg.data=mvibot_seri+"|";
                motor_right_msg.data=motor_right_msg.data+"live:"+to_string((int)motor_right_state_live)+"|";
                motor_right_msg.data=motor_right_msg.data+"error:"+to_string((int)motor_right_state_error)+"|";
                motor_right_msg.data=motor_right_msg.data+"enable:"+to_string((int)motor_right_disable)+"|";
                motor_right_msg.data=motor_right_msg.data+"brake:"+to_string((int)motor_right_break);
                motor_right_status_pub_->publish(motor_right_msg);
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
        }
        void motor_left_status(){
            static float creat_fun=0;
            static std_msgs::msg::String motor_left_msg;
            if(creat_fun==1){ 
                motor_left_msg.data=mvibot_seri+"|";
                motor_left_msg.data=motor_left_msg.data+"live:"+to_string((int)motor_left_state_live)+"|";
                motor_left_msg.data=motor_left_msg.data+"error:"+to_string((int)motor_left_state_error)+"|";
                motor_left_msg.data=motor_left_msg.data+"enable:"+to_string((int)motor_left_disable)+"|";
                motor_left_msg.data=motor_left_msg.data+"brake:"+to_string((int)motor_left_break);
                motor_left_status_pub_->publish(motor_left_msg);
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
            }else creat_fun=1;
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
        void set_color_led(float cred, float cgreen, float cblue){
            red=cred;
            blue=cblue;
            green=cgreen;
        }
        void led_control(){
            set_color_led(100,100,0); //add
            led_r=1; //add
            led_l=1; //add
            led_b=1; //add
            if(local_mode=="slam"){
                set_color_led(100,0,25); //100 0 25
                led_r=3;
                led_l=3;
                led_b=3;
            }
            if(local_n_re_connect>=10){
                set_color_led(100,20,0);
                led_r=2;
                led_l=2;
                led_b=2;
            }
            if((motor_left_state_error !=0 && motor_left_state_live==1) || (motor_right_state_error !=0 && motor_right_state_live==1) || software_update_status==1){
                set_color_led(100,0,0);
                led_r=1;
                led_l=1;
                led_b=1;
            }
            if(local_battery_soc <= local_low_battery && local_battery_soc!=-1){
                set_color_led(100,0,0);
                led_r=2;
                led_l=2;
                led_b=2;
            }else{
                if(local_mvibot_sensor_ready==0) {
                    set_color_led(100,100,100);
                    led_r=1;
                    led_l=1;
                    led_b=1;
                }
            }
            if(local_battery_status_charge==1){
                set_color_led(0,0,100);
                led_r=1;
                led_l=1;
                led_b=1;
            }
            if(local_software_update==1){
                set_color_led(0,0,100);
                led_r=2;
                led_l=2;
                led_b=2;
            }
            
        }
        void pub_output_user_status(){
            static float creat_fun=0;
            static std_msgs::msg::String output_msg;
            if(creat_fun==1){
                output_user_status_pub_->publish(output_user);
                output_msg.data=mvibot_seri+"|";
                for(size_t i=0;i<output_user.data.size()-1;i++){
                    output_msg.data=output_msg.data+"out"+to_string(i)+":"+to_string((int)output_user.data[i])+"|";
                }
                output_msg.data=output_msg.data+"out"+to_string(output_user.data.size()-1)+":"+to_string((int)output_user.data[output_user.data.size()-1]);
                output_user_status_string_pub_->publish(output_msg);
            }else creat_fun=1;
        }
        void pub_input_user_status(){
            static float creat_fun=0;
            static std_msgs::msg::String input_msg;
            if(creat_fun==1){
                input_user_status_pub_->publish(input_user);
                input_msg.data=mvibot_seri+"|";
                for(size_t i=0;i<input_user.data.size()-1;i++){
                    input_msg.data=input_msg.data+"in"+to_string(i)+":"+to_string((int)input_user.data[i])+"|";
                }
                input_msg.data=input_msg.data+"in"+to_string(input_user.data.size()-1)+":"+to_string((int)input_user.data[input_user.data.size()-1]);
                input_user_status_string_pub_->publish(input_msg);
            }else creat_fun=1;
        }
    private:
        //declare sub
        //
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_enable_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_break_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_reset_sub_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr robot_vel_sub_;
        //
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr set_led_sub_;
        //
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr output_user_set_sub_;
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr motor_right_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr motor_left_status_pub_;
        //
        rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr output_user_status_pub_;
        rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr input_user_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr output_user_status_string_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr input_user_status_string_pub_;
        //
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr motor_status_timer_;
        rclcpp::TimerBase::SharedPtr control_timer_;
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
        float local_software_update_status, local_software_update;
        float local_battery_soc;
        float local_low_battery;
        int local_battery_status_charge;
        int local_n_re_connect;
        string local_mode;
        //var check time motor
        rclcpp::Time check_time_control;
};
