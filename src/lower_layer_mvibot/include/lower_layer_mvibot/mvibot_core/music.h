#include "mvibot_core_init.h"

using namespace std;

class music : public rclcpp::Node{
    public:
        music(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            auto music_name_callback = [this](std_msgs::msg::String::SharedPtr msg)->void{
                static const std::string& message= msg->data;
                // lock();
                static string cmd;
                cmd="";
                cmd="wget -O "+define_path+"mp3/custom.mp3 "+message+" &"; //download file tu duong dan file ve thu muc mp3
                system(cmd.c_str());
                // unlock();
            };
            // music_name_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_ + "/music_name",qos_profile, music_name_callback);
            music_name_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_ + "/music_name",qos_profile, music_name_callback, sub_options);
            auto music_start_callback = [this](std_msgs::msg::Float32::SharedPtr msg)->void{
                static float value = msg->data;
                // lock();
                std::lock_guard<std::mutex> lock(mutex_music);
                if(value==0) start_music_n=0;
                if(value==1) start_music_n=1;
                if(value==2) start_music_n=2;
                if(value==3) start_music_n=3;
                if(value==4) start_music_n=4;
                // unlock();
            };
            // music_start_sub_ = this->create_subscription<std_msgs::msg::Float32>(mvibot_seri_ + "/music_start", qos_profile, music_start_callback);
            music_start_sub_ = this->create_subscription<std_msgs::msg::Float32>(mvibot_seri_ + "/music_start", qos_profile, music_start_callback, sub_options);
            auto music_control_timer_callback = [this]()->void{
                // music_control();
            };
            // music_control_timer_ = this->create_wall_timer(500ms,music_control_timer_callback);
            music_control_timer_ = this->create_wall_timer(50ms,music_control_timer_callback, reentrant_cbg);
        }
        void on_music(int mode){
            if(mode==0) system("killall -9 mplayer");
            else{
                if(status_music_n!=0) system("killall -9 mplayer");
                static string cmd;
                static string file;
                //cmd="mplayer -af channels=2:2:0:0:1:0 -ao alsa:device=hw=1.0 "+define_path+"mp3/";
                cmd="sudo pulseaudio --start && sudo mplayer "+define_path+"mp3/";
             //
                if(mode==2) file="buzze2.mp3";
                if(mode==1) file="buzze.mp3";
                if(mode==3) file="basic.mp3";
                if(mode==4) file="custom.mp3";
                //
                //basic.mp3 -loop 0 -volume 50 -lirc no &";
                cmd=cmd+file+" -loop 0 -volume "+to_string(volume)+" -lirc no &";
                system(cmd.c_str());
            }
            status_music_n=mode;
        }
        void off_music(){
            system("killall -9 mplayer");
            status_music_n=0;
        }
        void music_control(){
            {
                std::lock_guard<std::mutex> lock(mutex_motor);
                local_motor_right_state_error = motor_right_state_error;
                local_motor_right_state_live = motor_right_state_live;
                local_motor_left_state_error = motor_left_state_error;
                local_motor_left_state_live = motor_left_state_live;
            }
            std::lock_guard<std::mutex> lock(mutex_music);
            if((motor_right_state_error !=0 && motor_right_state_live ==1) || (motor_left_state_error !=0  && motor_left_state_live ==1)){
                if(status_music_n!=1) on_music(1);
            }else{
                if(status_music_n!=start_music_n) on_music(start_music_n);
            }
        }
    private:
        //declare subscriber
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr music_name_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr music_start_sub_;
        //declare publisher

        //declare timer
        rclcpp::TimerBase::SharedPtr music_control_timer_;
        //declare var
        string mvibot_seri_;
        // music
        int status_music_n=0;
        int start_music_n=0;
        std::mutex mutex_music;
        //
        int local_motor_right_state_error;
        int local_motor_right_state_live;
        int local_motor_left_state_error;
        int local_motor_left_state_live;
};
