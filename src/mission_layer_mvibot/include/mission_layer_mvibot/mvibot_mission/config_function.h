#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/set_get_param.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
class config_function : public rclcpp::Node{
    public:
        config_function(const string &node_name , const string &sub_namespace) : rclcpp::Node(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            //init service
            //footprint padding
            set_footprint_padding_local_client_ = this->create_client<rcl_interfaces::srv::SetParameters>("local_costmap/local_costmap/set_parameters");
            get_footprint_padding_local_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("local_costmap/local_costmap/get_parameters");
            set_footprint_padding_global_client_ = this->create_client<rcl_interfaces::srv::SetParameters>("global_costmap/global_costmap/set_parameters");
            get_footprint_padding_global_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("global_costmap/global_costmap/get_parameters");
            //velocity
            set_desired_linear_vel_client_ = this->create_client<rcl_interfaces::srv::SetParameters>("controller_server/set_parameters");
            get_desired_linear_vel_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("controller_server/get_parameters");
            //init publisher
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            config_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("config_function_state",1);
            //init subscriber
            //
            auto config_info_callback = [this](std_msgs::msg::String msg)->void{
                parameters = json::parse(msg.data);
                // cout<<parameters<<endl;
                process_data();
                request = 1;
            };
            config_info_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/config_info", qos_profile, config_info_callback);
            //
            auto config_function_status_callback = [this](std_msgs::msg::String msg)->void{
                cout<<"config|received request,status"<<endl;
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
            config_function_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/config_function_status", qos_profile, config_function_status_callback);
            //init timer
            //
            auto action_timer_callback = [this]()->void{
                cout<<"config|request:"<<request<<"|state:"<<status<<endl;
                if(request == 1){
                    int res;
                    res = action();
                    pub_function_state_config(res);
                }
            };
            action_timer_ = this->create_wall_timer(50ms, action_timer_callback);
        }
        void send_history(string status, string info);
        void pub_function_state_config(int st);
        void process_data();
        int action();
    private:
        //declare var
        string mvibot_seri_, mvibot_seri_f_;

        json parameters;
        int status = Finish_;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
        //footprint_padding
        string footprint_padding = "";
        //inflation_radius
        string inflation_radius = "";
        //velocity
        string desired_linear_vel = "";
        //declare service
        //footprint padding
        rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedPtr set_footprint_padding_local_client_;
        rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr get_footprint_padding_local_client_;
        rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedPtr set_footprint_padding_global_client_;
        rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr get_footprint_padding_global_client_;
        //desired_linear_vel
        rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedPtr set_desired_linear_vel_client_;
        rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr get_desired_linear_vel_client_;
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr config_function_state_pub_;
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr config_info_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr config_function_status_sub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr action_timer_;
};
void config_function::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
void config_function::pub_function_state_config(int st){
    std_msgs::msg::String msg;
    if(st == Active_) msg.data = "active";
    else if(st == Finish_) msg.data = "finish";
    else if(st == Error_) msg.data = "error";
    else if(st == Cancel_) msg.data = "cancel";
    else if(st == Stop_) msg.data = "stop";
    else if(st == True_) msg.data = "true";
    else if(st == False_) msg.data = "false";
    config_function_state_pub_->publish(msg);
}
void config_function::process_data(){
    cout<<parameters<<endl;
    desired_linear_vel = parameters["desired_linear_vel"].get<string>();
    footprint_padding = parameters["footprint_padding"].get<string>();
}

int config_function::action(){
    static int value_return;
    static bool set_result_vel = false;
    static bool set_done_vel = false;
    static bool set_result_local = false;
    static bool set_done_local = false;
    static bool set_result_global = false;
    static bool set_done_global = false;
    cout<<"config|status: "<<status<<endl;
    if(status==Active_){
        // static string config_set,config_return;
        value_return=Finish_;
        //desired_linear_vel
        if(desired_linear_vel != ""){
            double desired_linear_vel_set = stod_f(desired_linear_vel);
            if(stod_f(desired_linear_vel)> 0.5) desired_linear_vel_set = 0.5;
            if(!set_done_vel){
                check_param(set_desired_linear_vel_client_,get_desired_linear_vel_client_,"FollowPath.desired_linear_vel",desired_linear_vel_set,
                    [&](bool res){
                        set_result_vel = res;
                    }
                );
                set_done_vel = true;
            }
            if(!set_result_vel) value_return = Active_;
            else {
                set_result_vel = false;
                set_done_vel = false;
                //value_return = Finish_;
            }
        }
        if(footprint_padding != ""){
            double footprint_padding_set = stod_f(footprint_padding);
            if(footprint_padding_set < 0.0) footprint_padding_set = 0.0;
            //local costmap
            if(!set_done_local){
                check_param(set_footprint_padding_local_client_,get_footprint_padding_local_client_,"footprint_padding",footprint_padding_set,
                    [&](bool res){
                        set_result_local = res;
                    }
                );
                set_done_local = true;
            }
            if(!set_result_local) value_return = Active_;
            else {
                set_result_local = false;
                set_done_local = false;
                //value_return = Finish_;
            }
            //global costmap
            if(!set_done_global){
                check_param(set_footprint_padding_global_client_,get_footprint_padding_global_client_,"footprint_padding",footprint_padding_set,
                    [&](bool res){
                        set_result_global = res;
                    }
                );
                set_done_global = true;
            }
            if(!set_result_global) value_return = Active_;
            else {
                set_result_global = false;
                set_done_global = false;
                //value_return = Finish_;
            }
        }
        if(value_return == Finish_){
            status = Finish_;
            request = 0;
        }
        return value_return;
    }else{
        set_result_vel = false;
        set_done_vel = false;
        set_result_local = false;
        set_done_local = false;
        set_result_global = false;
        set_done_global = false;
        return status;
    }
}