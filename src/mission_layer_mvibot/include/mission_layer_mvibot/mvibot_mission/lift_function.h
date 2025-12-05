#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "../common/stoi.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class lift_function : public rclcpp::Node{
    private:
        //declare var
        string mvibot_seri_, mvibot_seri_f_;
        string object;
        string mode;
        float lift_up;
        float lift_down;
        float lift_brush_value;
        float lift_suction_value;
        json parameters;
        int status = Finish_;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
        //

        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_function_state_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_brush_power_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_brush_control_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_suction_power_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_suction_control_pub_;
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lift_info_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lift_function_status_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr lift_brush_data_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr lift_suction_data_sub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr action_timer_;
        
    public:
        lift_function(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            //init publisher
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            lift_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("lift_function_state",1);
            lift_brush_power_pub_ = this->create_publisher<std_msgs::msg::String>("lift_brush_power",1);
            lift_brush_control_pub_ = this->create_publisher<std_msgs::msg::String>("lift_brush_control",1);
            lift_suction_power_pub_ = this->create_publisher<std_msgs::msg::String>("lift_suction_power",1);
            lift_suction_control_pub_ = this->create_publisher<std_msgs::msg::String>("lift_suction_control",1);
            //init subscriber
            //
            auto lift_info_callback = [this](std_msgs::msg::String msg)->void{
                parameters = json::parse(msg.data);
                // cout<<parameters<<endl;
                process_data();
                request = 1;
            };
            lift_info_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_info", qos_profile, lift_info_callback);
            //
            auto lift_function_status_callback = [this](std_msgs::msg::String msg)->void{
                cout<<"lift|received request,status"<<endl;
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
            lift_function_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_function_status", qos_profile, lift_function_status_callback);
            //
            auto lift_brush_data_callback = [this](std_msgs::msg::Float32 msg)->void{
                lift_brush_value = msg.data;
            };
            lift_brush_data_sub_ = this->create_subscription<std_msgs::msg::Float32>(mvibot_seri_+"/lift_brush_data", qos_profile, lift_brush_data_callback);
            auto lift_suction_data_callback = [this](std_msgs::msg::Float32 msg)->void{
                lift_suction_value = msg.data;
            };
            lift_suction_data_sub_ = this->create_subscription<std_msgs::msg::Float32>(mvibot_seri_+"/lift_suction_data", qos_profile, lift_suction_data_callback);
            //init timer
            //
            auto action_timer_callback = [this]()->void{
                cout<<"lift|request:"<<request<<"|state:"<<status<<endl;
                if(request == 1){
                    int res;
                    res = action();
                    pub_function_state_lift(res);
                }
            };
            action_timer_ = this->create_wall_timer(50ms, action_timer_callback);
        }
        void pub_function_state_lift(int st);
        void pub_lift_brush(int st);
        void pub_lift_suction(int st);
        void send_history(string status, string info);
        void process_data();
        int action();
};
void lift_function::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
void lift_function::pub_function_state_lift(int st){
    std_msgs::msg::String msg;
    if(st == Active_) msg.data = "active";
    else if(st == Finish_) msg.data = "finish";
    else if(st == Error_) msg.data = "error";
    else if(st == Cancel_) msg.data = "cancel";
    else if(st == Stop_) msg.data = "stop";
    else if(st == True_) msg.data = "true";
    else if(st == False_) msg.data = "false";
    lift_function_state_pub_->publish(msg);
}
void lift_function::pub_lift_brush(int st){
    std_msgs::msg::String msg;
    if(st == 1) msg.data = "1";
    else if (st == 0) msg.data = "0";
    lift_brush_power_pub_->publish(msg);
    lift_brush_control_pub_->publish(msg);
}
void lift_function::pub_lift_suction(int st){
    std_msgs::msg::String msg;
    if(st == 1) msg.data = "1";
    else if (st == 0) msg.data = "0";
    lift_suction_power_pub_->publish(msg);
    lift_suction_control_pub_->publish(msg);
}
void lift_function::process_data(){
    object = parameters["object"].get<string>();
    mode = parameters["mode"].get<string>();
    lift_up = stof(parameters["lift_up"].get<string>());
    lift_down = stof(parameters["lift_down"].get<string>());
    cout<<"object: "<<object<< "|mode: "<<mode<<"|lift_up: "<<lift_up<<"|lift_down: "<<lift_down<<endl;
}
int lift_function::action(){
    if(status == Active_){
        if(object == "lift_brush"){
            if(mode == "lift_up"){
                pub_lift_brush(1);
                if(lift_brush_value >= lift_up){
                    status = Finish_;
                    request = 0;
                    object ="";
                    mode ="";
                    return Finish_;
                }
                else return Active_;
            }
            else if(mode == "lift_down"){
                pub_lift_brush(0);
                if(lift_brush_value <= lift_down){
                    status = Finish_;
                    request = 0;
                    object ="";
                    mode ="";
                    return Finish_;
                }
                else return Active_;
            }
        }
        else if(object == "lift_suction"){
            if(mode == "lift_up"){
                pub_lift_suction(1);
                if(lift_suction_value <= lift_down){
                    status = Finish_;
                    request = 0;
                    object ="";
                    mode ="";
                    return Finish_;
                }
                else return Active_;
            }
            else if(mode == "lift_down"){
                pub_lift_suction(0);
                if(lift_suction_value >= lift_up){
                    status = Finish_;
                    request = 0;
                    object ="";
                    mode ="";
                    return Finish_;
                }
                else return Active_;
            }
            else return Error_;
        }
        else return Error_;
    }
    else{
        return status;
    }
}