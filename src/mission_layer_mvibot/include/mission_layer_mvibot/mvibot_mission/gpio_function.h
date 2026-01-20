#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "../common/stoi.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class gpio_function : public rclcpp::Node{
    private:
        //declare var
        string mvibot_seri_, mvibot_seri_f_;
        //
        std_msgs::msg::Float32MultiArray input_status, input_status_1, input_status_2;
        std_msgs::msg::Float32MultiArray output_status;
        //
        json parameters;
        string not_set_out;
        std::map<string, string> input_map;
        std::map<string, string> output_map;
        int status = Finish_;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
        
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr gpio_function_state_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr set_output_pub_;
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr gpio_info_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr gpio_function_status_sub_;
        // get input, output
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr input_status_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr output_status_sub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr action_timer_;
    public:
        gpio_function(const string &name_node, const string &sub_namespace) : Node(name_node, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            //init publisher
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            gpio_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("gpio_function_state",1);
            set_output_pub_ = this->create_publisher<std_msgs::msg::String>("output_user_set",1);
            //init subscriber
            auto output_status_callback = [this](std_msgs::msg::Float32MultiArray msg)->void{
                output_status = msg;
            };
            output_status_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_+"/output_user_status",qos_profile, output_status_callback);
            auto input_status_callback = [this](std_msgs::msg::Float32MultiArray msg)->void{
                input_status_2 = input_status_1;
                input_status_1 = input_status;
                input_status = msg;
            };
            input_status_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_+"/input_user_status",qos_profile,input_status_callback);
            //
            auto gpio_info_callback = [this](std_msgs::msg::String msg)->void{
                parameters = json::parse(msg.data);
                process_data();
                request = 1;
            };
            gpio_info_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/gpio_info", qos_profile, gpio_info_callback);
            //
            auto gpio_function_status_callback = [this](std_msgs::msg::String msg)->void{
                cout<<"gpio|received request,status"<<endl;
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
            gpio_function_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/gpio_function_status", qos_profile, gpio_function_status_callback);
            //init timer
            //
            auto action_timer_callback = [this]()->void{
                cout<<"gpio|request:"<<request<<"|state:"<<status<<endl;
                if(request == 1){
                    int res;
                    res = action();
                    pub_function_state_gpio(res);
                }
            };
            action_timer_ = this->create_wall_timer(50ms, action_timer_callback);
        }
        void send_history(string status, string info);
        void pub_function_state_gpio(int st);
        void pub_output_set(string pin, string state);
        void process_data();
        int action();
};
void gpio_function::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
void gpio_function::pub_function_state_gpio(int st){
    std_msgs::msg::String msg;
    if(st == Active_) msg.data = "active";
    else if(st == Finish_) msg.data = "finish";
    else if(st == Error_) msg.data = "error";
    else if(st == Cancel_) msg.data = "cancel";
    else if(st == Stop_) msg.data = "stop";
    else if(st == True_) msg.data = "true";
    else if(st == False_) msg.data = "false";
    gpio_function_state_pub_->publish(msg);
}

void gpio_function::process_data(){
    std::map<std::string, json> output_parameters;
    std::map<std::string, json> input_parameters;
    not_set_out = parameters["not_set_out"].get<string>();
    output_parameters = parameters["output"].get<std::map<string,json>>();
    input_parameters = parameters["input"].get<std::map<string,json>>();
    input_map.clear();
    output_map.clear();
    for (const auto& [pin, state] : output_parameters) {
        output_map[pin]=state;
    }
    for (const auto& [pin, state] : input_parameters) {
        input_map[pin]=state;
    }
}
int gpio_function::action(){
    static int value_return;
    if(status == Active_){
        //input
        for(pair<string, string> it : input_map){
            if(it.second == "on"){
                // cout<<"Input On: "<<input_status.data[stoi(it.first)]<<endl;
                if(input_status.data[stoi(it.first)] != 1){
                    request = 0;
                    status = Finish_;
                    return False_;
                }
            }
            else if(it.second == "off"){
                // cout<<"Input Off: "<<input_status.data[stoi(it.first)]<<endl;
                if(input_status.data[stoi(it.first)] != 0){
                    request = 0;
                    status = Finish_;
                    return False_;
                }
            }
            else if(it.second == "pullup"){
                // cout<<"Input pullup: "<<input_status_2.data[stoi(it.first)]<<"|"<<input_status_1.data[stoi(it.first)]<<endl;
                if(!(input_status_2.data[stoi(it.first)] == 0 && input_status_1.data[stoi(it.first)] == 1)){
                    request = 0;
                    status = Finish_;
                    return False_;
                }
            }
            else if(it.second == "pulldown"){
                // cout<<"Input pulldown: "<<input_status_2.data[stoi(it.first)]<<"|"<<input_status_1.data[stoi(it.first)]<<endl;
                if(!(input_status_2.data[stoi(it.first)] == 1 && input_status_1.data[stoi(it.first)] == 0)){
                    request = 0;
                    status = Finish_;
                    return False_;
                }
            }
        }
        //output
        if(not_set_out == "1"){
            // cout<<"Not set out"<<endl;
            for(pair<string, string> it : output_map){
                if(it.second == "on"){
                    // cout<<"Output On: "<<output_status.data[stoi(it.first)]<<endl;
                    if(output_status.data[stoi(it.first)] != 1){
                        request = 0;
                        status = Finish_;
                        return False_;
                    }
                }
                else if(it.second == "off"){
                    // cout<<"Output Off: "<<output_status.data[stoi(it.first)]<<endl;
                    if(output_status.data[stoi(it.first)] != 0){
                        request = 0;
                        status = Finish_;
                        return False_;
                    }
                }
            }
        }
        else{
            // cout<<"set out"<<endl;
            std_msgs::msg::String msg;
            msg.data=mvibot_seri_f_;
            for(pair<string, string> it : output_map){
                if(it.second == "on"){
                    // cout<<"Output On: "<<output_status.data[stoi(it.first)]<<endl;
                    output_status.data[stoi(it.first)] = 1;
                    msg.data=msg.data+"|"+it.first+":1";
                }
                else if(it.second == "off"){
                    // cout<<"Output Off: "<<output_status.data[stoi(it.first)]<<endl;
                    output_status.data[stoi(it.first)] = 0;
                    msg.data=msg.data+"|"+it.first+":0";
                }
            }
            set_output_pub_->publish(msg);
            request = 0;
            status = Finish_;
            return Finish_;
        }
        request = 0;
        status = Finish_;
        return True_;
    }
    else{
        return status;
    }
}
