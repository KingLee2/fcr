#include "mvibot_core_init.h"

using namespace std;
// led & color
extern float green,red,blue;
extern float led_r,led_l,led_f,led_b;
// mode
extern string mode;
extern int  motor_left_state_error,motor_left_state_live,motor_right_state_error,motor_right_state_live;
extern float software_update_status,software_update;
extern float battery_soc;
extern float low_battery;
extern int mvibot_sensor_ready;
extern int battery_status_charge;
extern int n_re_connect;
class led : public rclcpp::Node{
    public:
        led(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            auto set_led_callback = [this](std_msgs::msg::Float32MultiArray::SharedPtr msg)->void{
                static const auto& data = msg->data;
                // lock();
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_led);
                red=data[0]/255*100;
                green=data[1]/255*100;
                blue=data[2]/255*100;
                //
                led_l=data[3];
                led_r=data[4];
                led_b=data[5];
                led_f=data[6];
                // unlock();
            };
            set_led_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_ + "/set_led", qos_profile, set_led_callback);
            // set_led_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_ + "/set_led", qos_profile, set_led_callback, sub_options);
            auto control_led_timer_callback = [this]()->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                {
                    std::lock_guard<std::mutex> lock(mutex_socket);
                    local_data_socket_ready = data_socket_ready;
                }
                if(local_data_socket_ready == 1){
                    led_control();
                }
            };
            control_led_timer_ = this->create_wall_timer(50ms,control_led_timer_callback);
            // control_led_timer_ = this->create_wall_timer(50ms,control_led_timer_callback, reentrant_cbg);
        }
        void set_color_led(float cred, float cgreen, float cblue){
            red=cred;
            blue=cblue;
            green=cgreen;
        }
        void led_control(){
            //
            {
                std::lock_guard<std::mutex> lock(mutex_common);
                local_mode = mode;
                local_n_re_connect = n_re_connect;
                local_software_update = software_update;
                local_software_update_status = software_update_status;
            }
            //
            {
                std::lock_guard<std::mutex> lock(mutex_battery);
                local_battery_soc = battery_soc;
                local_low_battery = low_battery;
                local_battery_status_charge = battery_status_charge;
            }
            {
                std::lock_guard<std::mutex> lock(mutex_motor);
                local_motor_left_state_error = motor_left_state_error;
                local_motor_left_state_live = motor_left_state_live;
                local_motor_right_state_error = motor_right_state_error;
                local_motor_right_state_live = motor_right_state_live;
            }
            {
                std::lock_guard<std::mutex> lock(mutex_sensor);
                local_mvibot_sensor_ready = mvibot_sensor_ready;
            }
            std::lock_guard<std::mutex> lock(mutex_led);
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
            if((local_motor_left_state_error !=0 && local_motor_left_state_live==1) || (local_motor_right_state_error !=0 && local_motor_right_state_live==1) || local_software_update_status==1){
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
    private:
        //declare sub
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr set_led_sub_;
        //declare pub
        //declare timer
        rclcpp::TimerBase::SharedPtr control_led_timer_;
        //declare var
        string mvibot_seri_;
        //add
        string local_mode;
        int local_motor_left_state_error, local_motor_left_state_live, local_motor_right_state_error, local_motor_right_state_live;
        float local_software_update_status, local_software_update;
        float local_battery_soc;
        float local_low_battery;
        int local_mvibot_sensor_ready;
        int local_battery_status_charge;
        int local_n_re_connect;
        int local_data_socket_ready;
};