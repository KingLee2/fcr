#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "../common/stoi.h"
#include "mission_define.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
//
class variable_local{
    public:
        string name;
        float data;
};
class multiple_variable_local{
    public:
        vector<variable_local> var;
        //
        void add_var(variable_local new_var);
        void update_var(variable_local var_update);
        void reset_all();
        void delete_all();
        void print();
        void reset();
};
void multiple_variable_local::add_var(variable_local new_var){
    static int is_have;
    is_have=0;
    for(int i=0;i<var.size();i++){
            if(var[i].name==new_var.name){
            is_have=1;
            var[i].data=new_var.data;
        }
    }
    if(is_have==0){
        var.resize(var.size()+1);
        var[var.size()-1]=new_var;
    }
}
void multiple_variable_local::update_var(variable_local var_update){
    static int is_have;
    is_have=0;
    for(int i=0;i<var.size();i++){
        if(var[i].name==var_update.name){
            is_have=1;
            var[i].data=var_update.data;
        }
    }
    if(is_have==0){
        var.resize(var.size()+1);
        var[var.size()-1]=var_update;
        var[var.size()-1].data=0;
    }
}
void multiple_variable_local::reset_all(){
    for(int i=0;i<var.size();i++){
        var[i].data=0;
    }
}
void multiple_variable_local::delete_all(){
    var.resize(0);
}
void multiple_variable_local::print(){
    cout<<BOLDCYAN;
    cout<<"Table Global Var~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    for(int i=0;i<var.size();i++){
        cout<<"var_name:"<<var[i].name<<"="<<var[i].data<<"\t\t\t\t\t\t"<<endl;
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<RESET;
}
void multiple_variable_local::reset(){
    var.resize(0);
}


class variable_function : public rclcpp::Node{
    private:
        //declare var
        string mvibot_seri_, mvibot_seri_f_;
        //mutex
        // std::mutex mutex_common;
        //
        multiple_variable_local   my_vars_local;
        json parameters;
        int status = Finish_;
        int request = 0; //request = 1: yeu cau thuc thi, request = 0: khong co yeu cau thuc thi
        string  command_action;
        string  name_variable;
        string  focus_value;
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr variable_function_state_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr variable_pub_;
        //declare sub
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr variable_info_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr variable_function_status_sub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr action_timer_;
        // rclcpp::TimerBase::SharedPtr variable_timer_;
        
    public:
        variable_function(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            //init publisher
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            variable_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("variable_function_state",1);
            variable_pub_ = this->create_publisher<std_msgs::msg::String>("local_variable",1);
            //init subscriber
            //
            auto variable_info_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                parameters = json::parse(msg.data);
                // cout<<parameters<<endl;
                process_data();
                print(1);
                request = 1;
            };
            variable_info_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/variable_info", qos_profile, variable_info_callback);
            //
            auto variable_function_status_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                cout<<"variable|received request,status"<<endl;
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
            variable_function_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/variable_function_status", qos_profile, variable_function_status_callback);
            //init timer
            //
            auto action_timer_callback = [this]()->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                cout<<"variable|request:"<<request<<"|state:"<<status<<endl;
                if(request == 1){
                    // static int res = Finish_, res_f = Finish_;
                    // res = action();
                    // if(res!= res_f) {
                    //     pub_function_state_variable(res);
                    //     res_f = res;
                    // }
                    int res;
                    res = action();
                    pub_function_state_variable(res);
                }
                pub_variable();
            };
            action_timer_ = this->create_wall_timer(50ms, action_timer_callback);
            //
            // auto variable_timer_callback = [this]()->void{
            //     // std::lock_guard<std::mutex> lock(mutex_common);
            //     pub_variable();
            // };
            // variable_timer_ = this->create_wall_timer(1000ms, variable_timer_callback);
        }
        void pub_function_state_variable(int st);
        void pub_variable();
        void send_history(string status, string info);
        void print(int n);
        void process_data();
        int action();

};
void variable_function::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
void variable_function::pub_function_state_variable(int st){
    std_msgs::msg::String msg;
    if(st == Active_) msg.data = "active";
    else if(st == Finish_) msg.data = "finish";
    else if(st == Error_) msg.data = "error";
    else if(st == Cancel_) msg.data = "cancel";
    else if(st == Stop_) msg.data = "stop";
    else if(st == True_) msg.data = "true";
    else if(st == False_) msg.data = "false";
    variable_function_state_pub_->publish(msg);
}
void variable_function::pub_variable(){
    static float creat_fun=0;
    static std_msgs::msg::String msg;
    // std::lock_guard<std::mutex> lock(mutex_common);
    if(creat_fun==1)
    {
        msg.data="";
        msg.data=mvibot_seri_f_;
        for(int i=0;i<my_vars_local.var.size();i++){
            msg.data=msg.data+"|"+my_vars_local.var[i].name+":"+to_string(my_vars_local.var[i].data);
        }
        variable_pub_->publish(msg);
    } else creat_fun=1;
}
void variable_function::process_data(){
    cout<<parameters<<endl;
    command_action = parameters["command_action"].get<string>();
    name_variable = parameters["name_variable"].get<string>();
    focus_value = parameters["focus_value"].get<string>();
}
void variable_function::print(int n){
    for(int i=0;i<n;i++) cout<<"\t ";
    cout<<"Data:"<<parameters<<endl;
    for(int i=0;i<n;i++) cout<<"\t ";
    cout<<"command_action:"<<command_action<<endl;
    for(int i=0;i<n;i++) cout<<"\t ";
    cout<<"name_variable:"<<name_variable<<endl;
    for(int i=0;i<n;i++) cout<<"\t ";
    cout<<"focus_value:"<<focus_value<<endl;
}

int variable_function::action(){
    static int value_return;
    if(status == Active_){
        static int is_have;
        is_have = 0;
        for(int i=0;i<my_vars_local.var.size();i++){
            if(my_vars_local.var[i].name==name_variable){
                is_have=i+1;
            }
        }
        if(command_action == "new"){
            variable_local local_variable; 
            local_variable.name = name_variable;
            local_variable.data = stof_f(focus_value);
            my_vars_local.add_var(local_variable);
            cout<<"create variable had completed"<<endl;
            value_return = Finish_;
        }
        else if(command_action == "equal"){ //=
            if(is_have==0){
                cout<<"Error not have variable"<<endl; 
                value_return = Error_;
            }else{
                my_vars_local.var[is_have-1].data=stof_f(focus_value);
                cout<<"set variable had completed"<<endl; 
                value_return = Finish_;
            }
        }
        else if(command_action == "equal_+"){ //+=
            if(is_have==0){
                cout<<"Error not have variable"<<endl; 
                value_return = Error_;
            }else{
                my_vars_local.var[is_have-1].data+=stof_f(focus_value);
                cout<<"Add variable had completed"<<endl;
                value_return = Finish_;
            }
        }
        else if(command_action == "equal_-"){ //-=
            if(is_have==0){
                cout<<"Error not have variable"<<endl; 
                value_return = Error_;
            }else{
                my_vars_local.var[is_have-1].data-=stof_f(focus_value);
                cout<<"Sub variable had completed"<<endl;
                value_return = Finish_;
            }
        }
        else if(command_action == "equal_as"){ //==
            if(is_have == 0) {
                cout<<"Error not have variable"<<endl;
                value_return = Error_;
            }
            else{
                if(my_vars_local.var[is_have-1].data==stof_f(focus_value)){
                    cout<<"Equal variable is true"<<endl;
                    value_return = True_;
                }
                else{
                    cout<<"Equal variable is false"<<endl;
                    value_return = False_;
                }
            }
        }
        else if(command_action == "equal_not"){ //!=
            if(is_have == 0) {
                cout<<"Error not have variable"<<endl;
                value_return = Error_;
            }
            else{
                if(my_vars_local.var[is_have-1].data!=stof_f(focus_value)){
                    cout<<"Equal not variable is true"<<endl;
                    value_return = True_;
                }
                else{
                    cout<<"Equal not variable is false"<<endl;
                    value_return = False_;
                }
            }
        }
        else if(command_action == "smaller_as"){ //<
            if(is_have == 0) {
                cout<<"Error not have variable"<<endl;
                value_return = Error_;
            }
            else{
                if(my_vars_local.var[is_have-1].data < stof_f(focus_value)){
                    cout<<"smaller_as variable is true"<<endl;
                    value_return = True_;
                }
                else{
                    cout<<"smaller_as variable is false"<<endl;
                    value_return = False_;
                }
            }
        }
        else if(command_action == "bigger_as"){ //>
            if(is_have == 0) {
                cout<<"Error not have variable"<<endl;
                value_return = Error_;
            }
            else{
                if(my_vars_local.var[is_have-1].data > stof_f(focus_value)){
                    cout<<"bigger_as variable is true"<<endl;
                    value_return = True_;
                }
                else{
                    cout<<"bigger_as variable is false"<<endl;
                    value_return = False_;
                }
            }
        }
        else if(command_action == "reset"){ 
            my_vars_local.reset_all();
            cout<<"reset variable had completed"<<endl;
            value_return = Finish_;
        }
        else if(command_action == "delete"){
            my_vars_local.delete_all();
            cout<<"delete variable had completed"<<endl;
            value_return = Finish_;
        }
        status = Finish_;
        request = 0;
        return value_return;
        
    }
    else{
        return status;
    }
}