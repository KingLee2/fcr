#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/set_get_param.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "mission_define.h"

using namespace std;
class config : public set_get_param<double>{
    public:
        config(const string &node_name , const string &sub_namespace) : set_get_param<double>(node_name, sub_namespace){
            mvibot_seri_ = this->get_namespace();
            // auto timer_action_callback = [this]()->void{
            //     status = action(1);
            //     while(status == 0){
            //         action(1);
            //     }
            // };
            // timer_action_ = this->create_wall_timer(500ms, timer_action_callback);
        }
        void process_data();
        void print();
        int action(int action);
        void reset();
    private:
        string data;
        int status=0;
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
        string mvibot_seri_;
        //
        // rclcpp::TimerBase::SharedPtr timer_action_;
};
void config::process_data(){
    // string_Iv2 data_return;
    // data_return.detect(data,"~","=","~");
    // for(int i=0;i<data_return.data1.size();i++){
    //     if(data_return.data1[i]=="max_vel_x") max_vel_x = data_return.data2[i];
    //     else if(data_return.data1[i]=="min_vel_x") min_vel_x=data_return.data2[i];
    //     else if(data_return.data1[i]=="max_vel_theta") max_vel_theta=data_return.data2[i];
    //     else if(data_return.data1[i]=="acc_lim_x") acc_lim_x=data_return.data2[i];
    //     else if(data_return.data1[i]=="acc_lim_theta") acc_lim_theta=data_return.data2[i];
    //     else if(data_return.data1[i]=="decel_lim_x") decel_lim_x = data_return.data2[i];
    //     else if(data_return.data1[i]=="decel_lim_theta") decel_lim_theta = data_return.data2[i];
    //     else if(data_return.data1[i]=="footprint_padding") footprint_padding=data_return.data2[i];
    //     else if(data_return.data1[i]=="inflation_radius") inflation_radius=data_return.data2[i];
    // }
    max_vel_x = "0.4";
    min_vel_x = "-0.4";
    max_vel_theta = "3.0";
    acc_lim_x = "0.8";
    acc_lim_theta = "3.0";
    decel_lim_x = "-0.8";
    decel_lim_theta = "-3.0";
    footprint_padding = "0.1";
    inflation_radius = "1.2";
}
void config::print(){

}
int config::action(int action){
    static int value_return;
    if(action==Active_){
        // static string config_set,config_return;
        bool set_state, get_state;
        value_return=Finish_;
        //min_vel_x
        if(min_vel_x != "none"){
            double min_vel_x_set = stod_f(min_vel_x);
            double min_vel_x_get;
            if(stod_f(min_vel_x)<-0.3) min_vel_x_set = -0.3;
            set_state = set_param(mvibot_seri_+"/controller_server/set_parameters","FollowPath.min_vel_x", min_vel_x_set);
            if(set_state == true){
                get_state = get_param(mvibot_seri_+"/controller_server/get_parameters","FollowPath.min_vel_x", min_vel_x_get);
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
        value_return=action;
    }
    return value_return;
}
void config::reset(){

}