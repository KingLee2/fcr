#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "../common/stoi.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class sleep_function : public rclcpp::Node{
    private:
        //declare var
        string mvibot_seri_, mvibot_seri_f_;

        json parameters;
        int status = Finish_;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
        long double time;
        long double time_sleep;
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr sleep_function_state_pub_;
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sleep_info_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sleep_function_status_sub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr action_timer_;
        
    public:
        sleep_function(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            time = 0.0;
            time_sleep = 0.0;
            //init publisher
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            sleep_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("sleep_function_state",1);
            //init subscriber
            //
            auto sleep_info_callback = [this](std_msgs::msg::String msg)->void{
                parameters = json::parse(msg.data);
                // cout<<parameters<<endl;
                process_data();
                request = 1;
            };
            sleep_info_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/sleep_info", qos_profile, sleep_info_callback);
            //
            auto sleep_function_status_callback = [this](std_msgs::msg::String msg)->void{
                cout<<"sleep|received request,status"<<endl;
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
            sleep_function_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/sleep_function_status", qos_profile, sleep_function_status_callback);
            //init timer
            //
            auto action_timer_callback = [this]()->void{
                cout<<"sleep|request:"<<request<<"|state:"<<status<<endl;
                if(request == 1){
                    int res;
                    res = action();
                    pub_function_state_sleep(res);
                }
            };
            action_timer_ = this->create_wall_timer(50ms, action_timer_callback);
        }
        void pub_function_state_sleep(int st);
        void send_history(string status, string info);
        void process_data();
        int action();
};
void sleep_function::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
void sleep_function::pub_function_state_sleep(int st){
    std_msgs::msg::String msg;
    if(st == Active_) msg.data = "active";
    else if(st == Finish_) msg.data = "finish";
    else if(st == Error_) msg.data = "error";
    else if(st == Cancel_) msg.data = "cancel";
    else if(st == Stop_) msg.data = "stop";
    else if(st == True_) msg.data = "true";
    else if(st == False_) msg.data = "false";
    sleep_function_state_pub_->publish(msg);
}
void sleep_function::process_data(){
    cout<<parameters<<endl;
    time_sleep = stof(parameters["time_sleep"].get<string>());
}
int sleep_function::action(){
    if(status == Active_){
        time += 0.05;
        if(time>=time_sleep){
            status = Finish_;
            request = 0;
            time = 0.0;
            return Finish_;
        }
        else return Active_;
    }
    else{
        return status;
    }
}