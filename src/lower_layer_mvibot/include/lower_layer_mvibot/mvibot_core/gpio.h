#include "mvibot_core_init.h"
#include "../common/string_Iv2.h"

using namespace std;
//gpio
// extern std_msgs::msg::Float32MultiArray input_user;
// extern std_msgs::msg::Float32MultiArray output_user;
class gpio : public rclcpp::Node{
    public:
        gpio(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            //create sub
            auto output_user_set_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data1;
                static string_Iv2 data2;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_gpio);
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
            //
            output_user_status_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("output_user_status",1);
            output_user_status_string_pub_ = this->create_publisher<std_msgs::msg::String>("output_user_status_string",1);
            auto output_user_status_timer_callback = [this]()->void{
                static float creat_fun=0;
                static std_msgs::msg::String msg;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_gpio);
                if(creat_fun==1){
                    output_user_status_pub_->publish(output_user);
                    msg.data=mvibot_seri+"|";
                    for(size_t i=0;i<output_user.data.size()-1;i++){
                        msg.data=msg.data+"out"+to_string(i)+":"+to_string((int)output_user.data[i])+"|";
                    }
                    msg.data=msg.data+"out"+to_string(output_user.data.size()-1)+":"+to_string((int)output_user.data[output_user.data.size()-1]);
                    output_user_status_string_pub_->publish(msg);
                }else creat_fun=1;
            };
            output_user_status_timer_ = this->create_wall_timer(50ms, output_user_status_timer_callback);
            // output_user_status_timer_ = this->create_wall_timer(50ms, output_user_status_timer_callback, reentrant_cbg);
            //
            input_user_status_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("input_user_status",1);
            input_user_status_string_pub_ = this->create_publisher<std_msgs::msg::String>("input_user_status_string",1);
            auto input_user_status_timer_callback = [this]()->void{
                static float creat_fun=0;
                static std_msgs::msg::String msg;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                 std::lock_guard<std::mutex> lock(mutex_gpio);
                if(creat_fun==1){
                    input_user_status_pub_->publish(input_user);
                    msg.data=mvibot_seri+"|";
                    for(size_t i=0;i<input_user.data.size()-1;i++){
                        msg.data=msg.data+"in"+to_string(i)+":"+to_string((int)input_user.data[i])+"|";
                    }
                    msg.data=msg.data+"in"+to_string(input_user.data.size()-1)+":"+to_string((int)input_user.data[input_user.data.size()-1]);
                    input_user_status_string_pub_->publish(msg);
                }else creat_fun=1;
            };
            input_user_status_timer_ = this->create_wall_timer(50ms, input_user_status_timer_callback);
            // input_user_status_timer_ = this->create_wall_timer(50ms, input_user_status_timer_callback, reentrant_cbg);
        }
    private:
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr output_user_set_sub_;
        //declare pub
        rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr output_user_status_pub_;
        rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr input_user_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr output_user_status_string_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr input_user_status_string_pub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr output_user_status_timer_;
        rclcpp::TimerBase::SharedPtr input_user_status_timer_;
        //declare var
        string mvibot_seri_;
};
