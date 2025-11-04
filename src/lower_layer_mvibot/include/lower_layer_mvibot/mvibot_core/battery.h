// #include "../common/library_basic.h"
// #include "../common/library_ros.h"
#include "mvibot_core_init.h"

using namespace std;

class battery : public rclcpp::Node{
    public:
        battery(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            //
            battery_status_pub_ = this->create_publisher<std_msgs::msg::String>("battery_status",1);
            auto battery_status_timer_callback = [this]()->void{
                static float creat_fun=0;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_battery);
                if(creat_fun==1){
                        static std_msgs::msg::String msg;
                        msg.data=mvibot_seri+"|";
                        if(battery_live_status==1){
                            msg.data=msg.data+"soc:"+to_string((int)battery_soc)+"|";
                            msg.data=msg.data+"vol:"+to_string(battery_vol)+"|";
                            msg.data=msg.data+"cycle:"+to_string((int)battery_cycle)+"|";
                            msg.data=msg.data+"capacity_now:"+to_string(battery_mah_now/100)+"|";
                            msg.data=msg.data+"capacity_max:"+to_string(battery_mah_max/100)+"|";
                            if(battery_current>=0) msg.data=msg.data+"charge:1|";
                            else msg.data=msg.data+"charge:0|";
                            msg.data=msg.data+"current:"+to_string(battery_current/100)+"|";
                            msg.data=msg.data+"num_cell:"+to_string((int)battery_num_cell)+"|";
                            msg.data=msg.data+"temperature:"+to_string(battery_temperature);
                        }else msg.data="N/A";
                        battery_status_pub_->publish(msg);
                        // CAP NHAT SAU
                        // static string cmd;
                        // cmd="echo $(date +'%d/%m/%Y %H:%M:%S') robot:"+to_string(distance_robot/1000)+" wheel_left:"+to_string(distance_wheel_left/1000)+" wheel_right:"+to_string(distance_wheel_right/1000);
                        // cmd=cmd+" \""+msg.data+"\" >> /home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/history/battery.log";
                        // system(cmd.c_str());
                        //
                }else {
                    //CAP NHAT SAU
                    // static string cmd;
                    // cmd="echo $(date +'%d/%m/%Y %H:%M:%S') start log > /home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/history/battery.log";
                    // system(cmd.c_str());
                    creat_fun=1;
                }
            };
            battery_status_timer_=this->create_wall_timer(1000ms, battery_status_timer_callback);
            // battery_status_timer_=this->create_wall_timer(1000ms, battery_status_timer_callback, mutuallyExclusive_cbg);
            //
            battery_cell_status_pub_ = this->create_publisher<std_msgs::msg::String>("battery_cell_status",1);
            auto battery_cell_status_timer_callback = [this]()->void{
                static float creat_fun=0;
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                 std::lock_guard<std::mutex> lock(mutex_battery);
                if(creat_fun==1){
                    static std_msgs::msg::String msg;
                    msg.data=mvibot_seri+"|";
                    if(battery_live_status==1){
                        for(int i=0;i<7;i++){
                            msg.data=msg.data+"Cell"+to_string(i+1)+":"+to_string(battery_cell[i])+"|";
                        }
                        msg.data=msg.data+"Cell"+to_string(7+1)+":"+to_string(battery_cell[7]);
                    }else msg.data="N/A";
                    battery_cell_status_pub_->publish(msg);
                }else creat_fun=1;
            };
            battery_cell_status_timer_ = this->create_wall_timer(1000ms,battery_cell_status_timer_callback);
            // battery_cell_status_timer_ = this->create_wall_timer(1000ms,battery_cell_status_timer_callback, mutuallyExclusive_cbg);
        }
    private:
        //declare sub
        //declare pub
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr battery_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr battery_cell_status_pub_;
        //declare timer
        rclcpp::TimerBase::SharedPtr battery_status_timer_;
        rclcpp::TimerBase::SharedPtr  battery_cell_status_timer_;
        //declare var
        string mvibot_seri_;
};
