#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/set_get_param.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>

using namespace std;
class config_function : public set_get_param<double>{
    public:
        config_function(const string &node_name , const string &sub_namespace) : set_get_param<double>(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);

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
        // Kinematic params //
        //linear velocity 
        string min_vel_x = "none";
        // float min_vel_y;
        string max_vel_x = "none";
        // float max_vel_y;
        //angle velocity
        string max_vel_theta = "none";
        //acc
        string acc_lim_x = "none";
        // float acc_lim_y;
        string acc_lim_theta = "none";
        //decel
        string decel_lim_x = "none";
        // float decel_lim_y;
        string decel_lim_theta = "none";
        //footprint_padding
        string footprint_padding = "none";
        //inflation_radius
        string inflation_radius = "none";
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
    min_vel_x = parameters["min_vel_x"].get<string>();
    max_vel_x = parameters["max_vel_x"].get<string>();
    max_vel_theta = parameters["max_vel_theta"].get<string>();
    acc_lim_x = parameters["acc_lim_x"].get<string>();
    acc_lim_theta = parameters["acc_lim_theta"].get<string>();
    decel_lim_x = parameters["decel_lim_x"].get<string>();
    decel_lim_theta = parameters["decel_lim_theta"].get<string>();
    footprint_padding = parameters["footprint_padding"].get<string>();
    inflation_radius = parameters["inflation_radius"].get<string>();
    // max_vel_x = "0.4";
    // min_vel_x = "-0.4";
    // max_vel_theta = "3.0";
    // acc_lim_x = "0.8";
    // acc_lim_theta = "3.0";
    // decel_lim_x = "-0.8";
    // decel_lim_theta = "-3.0";
    // footprint_padding = "0.1";
    // inflation_radius = "1.2";
}

int config_function::action(){
    static int value_return;
    cout<<"config|status: "<<status<<endl;
    if(status==Active_){
        // static string config_set,config_return;
        bool set_state, get_state;
        value_return=Finish_;
        cout<<"config|set param"<<endl;
        //min_vel_x
        if(min_vel_x != "none"){
            double min_vel_x_set = stod_f(min_vel_x);
            double min_vel_x_get;
            if(stod_f(min_vel_x)<-0.3) min_vel_x_set = -0.3;
            cout<<"config|before set param min_vel_x"<<endl;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.min_vel_x", min_vel_x_set);
            cout<<"config|set param min_vel_x: "<<set_state<<endl;
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.min_vel_x", min_vel_x_get);
                cout<<"config|get param min_vel_x: "<<get_state<<endl;
                if(get_state == true) cout<<"min_vel_x: "<<min_vel_x_get<<endl;
            }
            if(min_vel_x_get!=min_vel_x_set) value_return = Active_;
        }
        if(max_vel_x != "none"){
            double max_vel_x_set = stod_f(max_vel_x);
            double max_vel_x_get;
            if(stod_f(max_vel_x) > 0.5) max_vel_x_set = 0.5;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.max_vel_x", max_vel_x_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.max_vel_x", max_vel_x_get);
                if(get_state == true) cout<<"max_vel_x: "<<max_vel_x_get<<endl;
            }
            if(max_vel_x_get!=max_vel_x_set) value_return = Active_;
        }
        if(max_vel_theta != "none"){
            double max_vel_theta_set = stod_f(max_vel_theta);
            double max_vel_theta_get;
            if(stod_f(max_vel_x) > 3.14) max_vel_theta_set = 3.14;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.max_vel_theta", max_vel_theta_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.max_vel_theta", max_vel_theta_get);
                if(get_state == true) cout<<"max_vel_theta: "<<max_vel_theta_get<<endl;
            }
            if(max_vel_theta_get!=max_vel_theta_set) value_return = Active_;
        }
        if(acc_lim_x != "none"){
            double acc_lim_x_set = stod_f(acc_lim_x);
            double acc_lim_x_get;
            if(acc_lim_x_set > 1.0) acc_lim_x_set = 1.0;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.acc_lim_x", acc_lim_x_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.acc_lim_x", acc_lim_x_get);
                if(get_state == true) cout<<"acc_lim_x: "<<acc_lim_x_get<<endl;
            }
            if(acc_lim_x_get!=acc_lim_x_set) value_return = Active_;
        }
        if(acc_lim_theta != "none"){
            double acc_lim_theta_set = stod_f(acc_lim_theta);
            double acc_lim_theta_get;
            if(acc_lim_theta_set > 3.0) acc_lim_theta_set = 3.0;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.acc_lim_theta", acc_lim_theta_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.acc_lim_theta", acc_lim_theta_get);
                if(get_state == true) cout<<"acc_lim_theta: "<<acc_lim_theta_get<<endl;
            }
            if(acc_lim_theta_get!=acc_lim_theta_set) value_return = Active_;
        }
        if(decel_lim_x != "none"){
            double decel_lim_x_set = stod_f(decel_lim_x);
            double decel_lim_x_get;
            if(decel_lim_x_set < -1.0) decel_lim_x_set = -1.0;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.decel_lim_x", decel_lim_x_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.decel_lim_x", decel_lim_x_get);
                if(get_state == true) cout<<"decel_lim_x: "<<decel_lim_x_get<<endl;
            }
            if(decel_lim_x_get!=decel_lim_x_set) value_return = Active_;
        }
        if(decel_lim_theta != "none"){
            double decel_lim_theta_set = stod_f(decel_lim_theta);
            double decel_lim_theta_get;
            if(decel_lim_theta_set < -3.0) decel_lim_theta_set = -3.0;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.decel_lim_theta", decel_lim_theta_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.decel_lim_theta", decel_lim_theta_get);
                if(get_state == true) cout<<"decel_lim_theta: "<<decel_lim_theta_get<<endl;
            }
            if(decel_lim_theta_get!=decel_lim_theta_set) value_return = Active_;
        }
        if(footprint_padding != "none"){
            double footprint_padding_set = stod_f(footprint_padding);
            double footprint_padding_get;
            if(footprint_padding_set < 0.0) footprint_padding_set = 0.0;
            //local costmap
            set_state = set_param(mvibot_seri_+"/local_costmap/local_costmap/set_parameters","footprint_padding", footprint_padding_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/local_costmap/local_costmap/get_parameters","footprint_padding", footprint_padding_get);
                if(get_state == true) cout<<"footprint_padding with local costmap: "<<footprint_padding_get<<endl;
            }
            if(footprint_padding_get!=footprint_padding_set) value_return = Active_;
            //global costmap
            set_state = set_param(mvibot_seri_+"/global_costmap/global_costmap/set_parameters","footprint_padding", footprint_padding_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/global_costmap/global_costmap/get_parameters","footprint_padding", footprint_padding_get);
                if(get_state == true) cout<<"footprint_padding with global costmap: "<<footprint_padding_get<<endl;
            }
            if(footprint_padding_get!=footprint_padding_set) value_return = Active_;
        }
        if(inflation_radius != "none"){
            double inflation_radius_set = stod_f(inflation_radius);
            double inflation_radius_get;
            if(inflation_radius_set < 0.0) inflation_radius_set = 0.0;
            //local costmap
            set_state = set_param(mvibot_seri_+"/local_costmap/local_costmap/set_parameters","inflation_layer.inflation_radius", inflation_radius_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/local_costmap/local_costmap/get_parameters","inflation_layer.inflation_radius", inflation_radius_get);
                if(get_state == true) cout<<"inflation_radius with local costmap: "<<inflation_radius_get<<endl;
            }
            if(inflation_radius_get!=inflation_radius_set) value_return = Active_;
            //global costmap
            set_state = set_param(mvibot_seri_+"/global_costmap/global_costmap/set_parameters","inflation_layer.inflation_radius", inflation_radius_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/global_costmap/global_costmap/get_parameters","inflation_layer.inflation_radius", inflation_radius_get);
                if(get_state == true) cout<<"inflation_radius with global costmap: "<<inflation_radius_get<<endl;
            }
            if(inflation_radius_get!=inflation_radius_set) value_return = Active_;
        }
        return value_return;
    }else{
        return status;
    }
}