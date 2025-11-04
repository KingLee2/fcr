#include "../common/library_basic.h"
#include "../common/library_ros.h"
#include "../common/string_Iv2.h"
#include "../common/stof.h"
#include "../common/stoi.h"
#include "mission_define.h"
// #include "mvibot_mission_init.h"
#include <mutex>
using namespace std;
using json = nlohmann::json;
class mission{
    public:
        string mission_id;
        std::map<string,json>contents_map;
        std::map<string,json>triggers_map;
        void reset(){
            mission_id="";
            contents_map.clear();
            triggers_map.clear();
        }
};
class module {
    public:
        string name;
        std_msgs::msg::Float32MultiArray input_user;
        std_msgs::msg::Float32MultiArray input_user1;
        std_msgs::msg::Float32MultiArray input_user2;
        std_msgs::msg::Float32MultiArray output_user;
};
class manage_mission : public rclcpp::Node{
    private:
        //Mutex
        // std::mutex mutex_common;
        
        //var
        string mvibot_seri_,mvibot_seri_f_;
        vector<json>missions_;
        vector<mission>mission_normal;
        mission mission_error;
        vector<mission>mission_charge_battery;
        // mission mission_;
        // int action_mode_mission;
        //
        vector<module> my_module;
        std_msgs::msg::Float32MultiArray input_status, input_status_1, input_status_2;
        std_msgs::msg::Float32MultiArray output_status;
        int motor_left_ready = 0;
        int motor_right_ready = 0;
        float battery_soc=-1;
        float battery_soc1=-1;
        float battery_soc2=-1;
        float want_to_charge=0;
        int status = Finish_;
        string active_mission_id = "";
        int state;
        double ts_execute_callback = 0.05;
        //pub
        //information mission active
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr active_mission_info_pub_;
        //robot
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr stop_robot_pub_;
        //gpio
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr gpio_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr gpio_function_state_pub_;
        //footprint
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr footprint_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr footprint_function_state_pub_;
        //config runtime
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr config_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr config_function_state_pub_;
        //navigation
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr navigation_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr navigation_function_state_pub_;
        //marker
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr marker_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr marker_function_state_pub_;
        //sleep
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr sleep_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr sleep_function_state_pub_;
        //variable
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr var_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr var_function_state_pub_;
        //lift
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_function_state_pub_;
        //brush
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr brush_info_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr brush_function_state_pub_;
        //history
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        //sub
        //mission
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr get_mission_normal_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr get_mission_charge_battery_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr get_mission_error_sub_;
        //get request "want to charge"
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr get_request_charge_battery_sub_;
        //get request robot (stop,continues)
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr get_request_robot_sub_;
        //get mission executed
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr get_mission_executed_sub_;
        //get status motor
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_left_status_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr motor_right_status_sub_;
        //get status battery
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr battery_status_sub_;
        // get input, output
        // rclcpp::Subscription<std_msgs::msg::String>::SharedPtr output_status_string_sub_;
        // rclcpp::Subscription<std_msgs::msg::String>::SharedPtr input_status_string_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr input_status_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr output_status_sub_;
        //get status function
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr gpio_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr footprint_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr config_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr navigation_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr marker_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sleep_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr var_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lift_function_state_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr brush_function_state_sub_;
        //timer
        // rclcpp::TimerBase::SharedPtr get_mission_normal_timer_;
        // rclcpp::TimerBase::SharedPtr get_mission_charge_timer_;
        // rclcpp::TimerBase::SharedPtr get_mission_error_timer_;
        rclcpp::TimerBase::SharedPtr execute_mission_timer_;
    public:
        manage_mission(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            mvibot_seri_ = this->get_namespace();
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            //
            mission_error.reset();
            output_status.data.resize(12);
            input_status.data.resize(30);
            input_status_1=input_status;
            input_status_2=input_status_1;
            active_mission_id = "";
            status = Finish_;
            state = N_A_;
            want_to_charge = 0;
            motor_left_ready = 1;
            motor_right_ready = 1;
            battery_soc1 = 100;
            battery_soc2 = 100;
            // init pub//
            // active mission pub
            active_mission_info_pub_ = this->create_publisher<std_msgs::msg::String>("active_mission_info",1);
            //stop robot
            stop_robot_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",1);
            //send history
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            //gpio
            gpio_info_pub_ = this->create_publisher<std_msgs::msg::String>("gpio_info",1);
            gpio_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("gpio_function_status",1);
            //footprint
            footprint_info_pub_ = this->create_publisher<std_msgs::msg::String>("footprint_info",1);
            footprint_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("footprint_function_status",1);
            //config
            config_info_pub_ = this->create_publisher<std_msgs::msg::String>("config_info",1);
            config_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("config_function_status",1);
            //sleep
            sleep_info_pub_ = this->create_publisher<std_msgs::msg::String>("sleep_info",1);
            sleep_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("sleep_function_status",1);
            //var
            var_info_pub_ = this->create_publisher<std_msgs::msg::String>("variable_info",1);
            var_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("variable_function_status",1);
            //navigation
            navigation_info_pub_ = this->create_publisher<std_msgs::msg::String>("navigation_info",1);
            navigation_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("navigation_function_status",1);
            //marker
            marker_info_pub_ = this->create_publisher<std_msgs::msg::String>("marker_info",1);
            marker_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("marker_function_status",1);
            //lift
            lift_info_pub_ = this->create_publisher<std_msgs::msg::String>("lift_info",1);
            lift_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("lift_function_status",1);
            //brush
            brush_info_pub_ = this->create_publisher<std_msgs::msg::String>("brush_info",1);
            brush_function_state_pub_ = this->create_publisher<std_msgs::msg::String>("brush_function_status",1);
            ///init subscriber///
            // sub mission normal
            auto mission_normal_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                static string file_name;
                file_name = "/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/mission_normal.json";
                try{
                    std::ofstream file(file_name);
                    if (!file.is_open()){
                        send_history("error", "Failed to open mission file: " + file_name);
                        return;
                    }
                    file <<msg.data;
                    file.close();
                    if (!load_mission_normal(file_name)) {
                        send_history("error", "Failed to load mission from: " + file_name);
                    }
                    
                }
                catch (const std::exception& e){
                    send_history("error", "Error processing mission: " + std::string(e.what()));
                }
                // unlock();
            };
            get_mission_normal_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/mission_normal",qos_profile,mission_normal_callback);
            //sub mission charge battery
            auto mission_charge_baterry_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                static string file_name;
                file_name = "/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/mission_charge_battery.json";
                try{
                    std::ofstream file(file_name);
                    if (!file.is_open()){
                        send_history("error", "Failed to open mission file: " + file_name);
                        return;
                    }
                    file <<msg.data;
                    file.close();
                    if (!load_mission_charge(file_name)) {
                        send_history("error", "Failed to load mission from: " + file_name);
                    }
                    
                }
                catch (const std::exception& e){
                    send_history("error", "Error processing mission: " + std::string(e.what()));
                }
                // unlock();
            };
            get_mission_charge_battery_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/mission_charge_battery",qos_profile,mission_charge_baterry_callback);
            //sub mission error
            auto mission_error_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                static string file_name;
                file_name = "/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/mission_error.json";
                try{
                    std::ofstream file(file_name);
                    if (!file.is_open()){
                        send_history("error", "Failed to open mission file: " + file_name);
                        return;
                    }
                    file <<msg.data;
                    file.close();
                    if (!load_mission_error(file_name)) {
                        send_history("error", "Failed to load mission from: " + file_name);
                    }
                    
                }
                catch (const std::exception& e){
                    send_history("error", "Error processing mission: " + std::string(e.what()));
                }
                // unlock();
            };
            get_mission_error_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/mission_error",qos_profile,mission_error_callback);
            // update gpio
            auto output_status_callback = [this](std_msgs::msg::Float32MultiArray msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                output_status = msg;
                // unlock();
            };
            output_status_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_+"/output_user_status",qos_profile, output_status_callback);
            auto input_status_callback = [this](std_msgs::msg::Float32MultiArray msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                input_status_2 = input_status_1;
                input_status_1 = input_status;
                input_status = msg;
                //unlock();
            };
            input_status_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(mvibot_seri_+"/input_user_status",qos_profile,input_status_callback);
            // auto output_user_status_callback = [this](std_msgs::msg::String msg)->void{
            //     static string_Iv2 data;
            //     data.detect(msg.data,"","|","");
            //     //
            //     static std_msgs::msg::Float32MultiArray output;
            //     output.data.resize(0);
            //     output.data.resize(data.data1.size()-1);
            //     for(int j=1;j<data.data1.size();j++){
            //         static string_Iv2 data2;
            //         data2.detect(data.data1[j],"",":","");
            //         output.data[j-1]=stof(data2.data1[1]);
            //     }
            //     //
            //     static int is_have;
            //     is_have=0;
            //     //lock();
            //     std::lock_guard<std::recursive_mutex> lock(mutex_module);
            //     for(int i=0;i<my_module.size();i++){
            //         if(data.data1[0]==my_module[i].name){
            //             is_have=1;
            //             my_module[i].output_user=output;
            //             break;
            //         }
            //     }
            //     //
            //     if(is_have==0){
            //         cout<<"Have_new_moudle:"<<data.data1[0]<<endl;
            //         send_history("normal","Find new module "+data.data1[0]);
            //         my_module.resize(my_module.size()+1);
            //         //
            //         my_module[my_module.size()-1].name=data.data1[0];
            //         //
            //         my_module[my_module.size()-1].output_user=output;
            //     }
            //     // unlock();

            // };
            // output_status_string_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/output_user_status_string", qos_profile, output_user_status_callback);
            // auto input_user_status_callback = [this](std_msgs::msg::String msg)->void{
            //     static string_Iv2 data;
            //     data.detect(msg.data,"","|","");
            //     //
            //     static std_msgs::msg::Float32MultiArray input;
            //     input.data.resize(0);
            //     input.data.resize(data.data1.size()-1);
            //     for(int j=1;j<data.data1.size();j++){
            //         static string_Iv2 data2;
            //         data2.detect(data.data1[j],"",":","");
            //         input.data[j-1]=stof(data2.data1[1]);
            //     }
            //     //
            //     static int is_have;
            //     is_have=0;
            //     // lock();
            //     std::lock_guard<std::recursive_mutex> lock(mutex_module);
            //     for(int i=0;i<my_module.size();i++){
            //         if(data.data1[0]==my_module[i].name){
            //             is_have=1;
            //             my_module[i].input_user=input;
            //             break;
            //         }
            //     }
            //     //
            //     if(is_have==0){
            //         cout<<"Have_new_moudle:"<<data.data1[0]<<endl;
            //         send_history("normal","Find new module "+data.data1[0]);
            //         my_module.resize(my_module.size()+1);
            //         //
            //         my_module[my_module.size()-1].name=data.data1[0];
            //         //
            //         my_module[my_module.size()-1].input_user=input;
            //     }
            //     for(int i=0;i<my_module.size();i++){
            //         my_module[i].input_user2=my_module[i].input_user1;
            //         my_module[i].input_user1=my_module[i].input_user;
            //     }
            //     // unlock();
            // };
            // input_status_string_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/output_user_status_string", qos_profile, input_user_status_callback);
            //status motor
            auto motor_left_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                static int is_ready;
                static int live=-1,live_f=-1,brake=-1,brake_f=-1,enable=-1,enable_f=-1,error=-1,error_f=-1;
                is_ready=1;
                data.detect(msg.data,"","|","");
                for(int i=0;i<data.data1.size();i++){
                    static string_Iv2 data2;
                    data2.detect(data.data1[i],"",":","");
                    if(data2.data1.size()==2){
                        if(data2.data1[0]=="live")      live=stoi_f(data2.data1[1]);
                        if(data2.data1[0]=="enable")    enable=stoi_f(data2.data1[1]);
                        if(data2.data1[0]=="brake")     brake=stoi_f(data2.data1[1]);
                        if(data2.data1[0]=="error")     error=stoi_f(data2.data1[1]);
                    }
                }
                //
                if(live==0) is_ready=0;
                else{
                    if(enable==0) is_ready=0;
                    if(brake==0)  is_ready=0;
                }
                // std::lock_guard<std::mutex> lock(mutex_common);
                ///test///
                motor_left_ready=1;
                ///test///
                // motor_left_ready=is_ready;// thuc te
                // unlock();
            };
            motor_left_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_left_status", qos_profile, motor_left_status_callback);
            auto motor_right_status_callback = [this](std_msgs::msg::String msg)->void{
                static string_Iv2 data;
                static int live=-1,live_f=-1,brake=-1,brake_f=-1,enable=-1,enable_f=-1,error=-1,error_f=-1;
                static int is_ready;
                is_ready=1;
                data.detect(msg.data,"","|","");
                for(int i=0;i<data.data1.size();i++){
                        static string_Iv2 data2;
                        data2.detect(data.data1[i],"",":","");
                        if(data2.data1.size()==2){
                            if(data2.data1[0]=="live")      live=stoi_f(data2.data1[1]);
                            if(data2.data1[0]=="enable")    enable=stoi_f(data2.data1[1]);
                            if(data2.data1[0]=="brake")     brake=stoi_f(data2.data1[1]);
                            if(data2.data1[0]=="error")     error=stoi_f(data2.data1[1]);
                        }
                    }
                    //
                    if(live==0) is_ready=0;
                    else{
                        if(enable==0) is_ready=0;
                        if(brake==0)  is_ready=0;
                    }
                    // std::lock_guard<std::mutex> lock(mutex_common);
                    ///test///
                    motor_right_ready=1;
                    ///test///
                    // motor_right_ready=is_ready;//thuc te
                    // unlock();
            };
            motor_right_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/motor_right_status", qos_profile, motor_right_status_callback);
            //status battery
            auto battery_status_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                    static string_Iv2 data;
                    data.detect(msg.data,"","|","");
                    for(int i=1;i<data.data1.size();i++){
                        static string_Iv2 data2;
                        data2.detect(data.data1[i],"",":","");
                        if(data2.data1[0]=="soc"){
                            battery_soc2 = battery_soc1;
                            battery_soc1 = battery_soc;
                            battery_soc=stof_f(data2.data1[1]);
                        }
                    }
                // unlock();
            };
            battery_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/battery_status", qos_profile, battery_status_callback);
            //get request robot (stop,continues)
            auto request_robot_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") status = Stop_;
                else if(msg.data == "continues") {
                    if(status == Stop_) status = Active_;
                }
                cout<<"status:"<<status<<endl;
            };
            get_request_robot_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/robot_state", qos_profile,request_robot_callback);
            // get request "want to charge"
            auto want_to_charge_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "1") want_to_charge = 1;
                else want_to_charge = 0;
            };
            get_request_charge_battery_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/want_to_charge", qos_profile, want_to_charge_callback);
            //get request execute mission
            auto mission_executed_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(status == Finish_) active_mission_id = msg.data;
            };
            get_mission_executed_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/executed_mission", qos_profile, mission_executed_callback);
            //get state of function
            //gpio
            auto gpio_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
                else if(msg.data == "true") state = True_;
                else if(msg.data == "false") state = False_;
            };
            gpio_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/gpio_function_state", qos_profile, gpio_function_state_callback);
            //footprint
            auto footprint_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
            };
            footprint_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/footprint_function_state", qos_profile, footprint_function_state_callback);
            //config
            auto config_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
            };
            config_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/config_function_state", qos_profile, config_function_state_callback);
            //var
            auto var_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
                else if(msg.data == "true") state = True_;
                else if(msg.data == "false") state = False_;
            };
            var_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/variable_function_state", qos_profile, var_function_state_callback);
            //sleep
            auto sleep_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
            };
            sleep_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/sleep_function_state", qos_profile, sleep_function_state_callback);
            //navigation
            auto navigation_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
            };
            navigation_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/navigation_function_state", qos_profile, navigation_function_state_callback);
            //marker
            auto marker_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
            };
            marker_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/marker_function_state", qos_profile, marker_function_state_callback);
            //lift
            auto lift_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
            };
            lift_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_function_state", qos_profile, lift_function_state_callback);
            //brush
            auto brush_function_state_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::mutex> lock(mutex_common);
                if(msg.data == "stop") state = Stop_;
                else if(msg.data == "active") state = Active_;
                else if(msg.data == "finish") state = Finish_;
                else if(msg.data == "cancel") state = Cancel_;
                else if(msg.data == "error") state = Error_;
            };
            brush_function_state_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/brush_function_state", qos_profile, brush_function_state_callback);
            //load file
            load_mission_normal("/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/mission_normal.json");
            // load_mission_charge("/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/mission_charge_battery.json");
            // load_mission_error("/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/mission_error.json");

            //init timer//
            auto execute_mission_timer_callback = [this]()->void{
                RCLCPP_INFO(this->get_logger(),"before execute mission");
                // std::lock_guard<std::mutex> lock(mutex_common);
                execute_mission();
                RCLCPP_INFO(this->get_logger(),"after execute mission");
            };
            execute_mission_timer_ = this->create_wall_timer(50ms, execute_mission_timer_callback);
        }
        void send_history(string status, string info);
        void pub_stop_robot();
        void pub_active_mission_info(string type, string mission_id, string content_id, string content_sum);
        int load_mission_normal(const string &file_name);
        int load_mission_charge(const string &file_name);
        int load_mission_error(const string &file_name);
        void check_WakeUp_condition(json wakeUp_object);
        void check_Stop_condition(json stop_object);
        void check_Continues_condition(json continues_object);
        int check_object(const json& object);
        int check_gpio(const std::map<std::string, json>& parameters);
        int handle_content(const json& content, const double& time_out, double & timer, int& status, rclcpp::Publisher<std_msgs::msg::String>::SharedPtr info_pub, rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_pub);
        void execute_mission();
        int execute_content(mission& mission, vector<string>& queue_content, string& active_content, string& next_to, int& status);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
};
void manage_mission::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri_f_+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}

void manage_mission::pub_stop_robot(){
    static geometry_msgs::msg::Twist stop_robot_;
    stop_robot_.linear.x = 0.0;
    stop_robot_.angular.z = 0.0;
    stop_robot_pub_->publish(stop_robot_);
}
void manage_mission::pub_active_mission_info(string type, string mission_id, string content_id, string content_sum){
    json mission_info;
    std_msgs::msg::String mission_info_str;
    mission_info["type"] = type;
    mission_info["mission_id"] = mission_id;
    mission_info["content_id"] = content_id;
    mission_info["content-sum"] = content_sum;
    mission_info_str.data = mission_info.dump();
    active_mission_info_pub_->publish(mission_info_str);
}

int manage_mission::load_mission_normal(const string &file_name){                                                                                                           
    std::ifstream file(file_name);
    if(!file.is_open()){
        cout<<"file is not opened"<<endl;
        return 0;
    }
    json new_missions;
    file >> new_missions;
    mission_normal.resize(0);
    // missions_.clear();
    // task_map_.clear();
    if (new_missions.is_array()) {
        missions_ = new_missions.get<vector<json>>();
        mission_normal.resize(missions_.size());
    } else {
        missions_.push_back(new_missions);
        mission_normal.resize(1);
    }
    // for(const auto& m : missions_){
    //     mission_normal[0].mission_id = m["mission_id"];
    // }
    for(size_t i=0; i<missions_.size(); i++){
        mission_normal[i].mission_id = missions_[i]["mission_id"].get<string>();
        cout<<"Mission Name: "<<mission_normal[i].mission_id<<endl;
        for (const auto& trigger : missions_[i]["triggers"]) {
            for (const auto& [key, value] : trigger.items()) {
                mission_normal[i].triggers_map[key] = value;
                cout<<key<<"|||"<<mission_normal[i].triggers_map[key]<<endl;
            }
        }
        // for(const auto& content : missions_[i]["contents"]){
        //     string content_id = content["id"].get<string>();
        //     mission_normal[i].contents_map[content_id] = content;
        //     cout<<content_id<<"|||"<<mission_normal[i].contents_map[content_id]<<endl;
        // }
        if (missions_[i].contains("contents") && missions_[i]["contents"].is_object()) {
            for (auto& [key, value] : missions_[i]["contents"].items()) {
                mission_normal[i].contents_map[key] = value;
                cout<<key<<"|||"<<mission_normal[i].contents_map[key]<<endl;
            }
        }
    }
    return 1;
}
int manage_mission::load_mission_charge(const string &file_name){
    std::ifstream file(file_name);
    if(!file.is_open()){
        cout<<"file is not opened"<<endl;
        return 0;
    }
    json new_missions;
    file >> new_missions;
    mission_charge_battery.resize(0);
    missions_.resize(0);
    // missions_.clear();
    // task_map_.clear();
    if (new_missions.is_array()) {
        missions_ = new_missions.get<vector<json>>();
        mission_charge_battery.resize(missions_.size());
    } else {
        missions_.push_back(new_missions);
        mission_charge_battery.resize(1);
    }
    // for(const auto& m : missions_){
    //     mission_normal[0].mission_id = m["mission_id"];
    // }
    for(size_t i=0; i<missions_.size(); i++){
        mission_charge_battery[i].mission_id = missions_[i]["mission_id"].get<string>();
        cout<<"Mission Name: "<<mission_charge_battery[i].mission_id<<endl;
        for (const auto& trigger : missions_[i]["triggers"]) {
            for (const auto& [key, value] : trigger.items()) {
                mission_charge_battery[i].triggers_map[key] = value;
                cout<<key<<"|||"<<mission_charge_battery[i].triggers_map[key]<<endl;
            }
        }
        for(const auto& content : missions_[i]["contents"]){
            string content_id = content["id"].get<string>();
            mission_charge_battery[i].contents_map[content_id] = content;
            cout<<content_id<<"|||"<<mission_charge_battery[i].contents_map[content_id]<<endl;
        }
    }
    return 1;
}
int manage_mission::load_mission_error(const string &file_name){
    std::ifstream file(file_name);
    if(!file.is_open()){
        cout<<"file is not opened"<<endl;
        return 0;
    }
    json new_mission;
    file >> new_mission;
    mission_error.reset();
    mission_error.mission_id = new_mission["mission_id"].get<string>();
    cout<<"Mission ID: "<<mission_error.mission_id<<endl;
    for(const auto& content : new_mission["contents"]){
        string content_id = content["id"].get<string>();
        mission_error.contents_map[content_id] = content;
        cout<<content_id<<"|||"<<mission_error.contents_map[content_id]<<endl;
    }
    return 1;
}
void manage_mission::check_WakeUp_condition(json wakeUp_object){
    static json wakeup_;
    wakeup_ = wakeUp_object;
    if(check_object(wakeup_) == True_) status = Wake_up_;
}
void manage_mission::check_Stop_condition(json stop_object){
    static json stop_ob_;
    stop_ob_ = stop_object;
    cout<<"dieu kien stop: "<<stop_ob_<<endl;
    if(check_object(stop_ob_) == True_) status = Stop_;
    cout<<"status after check stop from gpio: "<<status<<endl;
}
void manage_mission::check_Continues_condition(json continues_object){
    static json continues_ob_;
    continues_ob_ = continues_object;
    if(check_object(continues_ob_) == True_) status = Continue_;
    cout<<"status after check continues from gpio: "<<status<<endl;
}
int manage_mission::check_object(const json& object){
    cout<<"type: "<<object["type"]<<endl;
    if(object["type"].get<string>() == "and"){
        for(const auto& m : object["contents"]){
            if(check_object(m) == False_) return False_;
        }
        return True_;
    }
    else if(object["type"].get<string>() == "or"){
        for(const auto& m : object["contents"]){
            if(check_object(m)==True_) return True_;
        }
        return False_;
    }
    else if(object["type"].get<string>() == "gpio"){
        RCLCPP_INFO(this->get_logger(),"check gpio");
        if(check_gpio(object["parameters"].get<std::map<string,json>>()) == True_) return True_;
        return False_;
    }
}
int manage_mission::check_gpio(const std::map<std::string, json>& parameters){
    static std::map<string, string> input_map;
    static std::map<string, string> output_map;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    input_map.clear();
    output_map.clear();
    for (const auto& [type, pins] : parameters) {
        for (const auto& [pin, state] : pins.items()) {
            if(type=="input"){
                input_map[pin]=state;
                cout<<"input "<<pin<<": "<<state<<endl;
            }
            else if(type=="output"){
                output_map[pin]=state;
                cout<<"output "<<pin<<": "<<state<<endl;
            }
            
        }
    }

    for(pair<string, string> it : output_map){
        if(it.second == "on"){
            cout<<"Output On: "<<output_status.data[stoi(it.first)]<<endl;
            if(output_status.data[stoi(it.first)] != 1) return false;
        }
        else if(it.second == "off"){
            cout<<"Output Off: "<<output_status.data[stoi(it.first)]<<endl;
            if(output_status.data[stoi(it.first)] != 0) return false;
        }
    }
    for(pair<string, string> it : input_map){
        if(it.second == "on"){
            cout<<"Input On: "<<input_status.data[stoi(it.first)]<<endl;
            if(input_status.data[stoi(it.first)] != 1) return false;
        }
        else if(it.second == "off"){
            cout<<"Input Off: "<<input_status.data[stoi(it.first)]<<endl;
            if(input_status.data[stoi(it.first)] != 0) return false;
        }
        else if(it.second == "pullup"){
            cout<<"Input pullup: "<<input_status_2.data[stoi(it.first)]<<"|"<<input_status_1.data[stoi(it.first)]<<endl;
            if(!(input_status_2.data[stoi(it.first)] == 0 && input_status_1.data[stoi(it.first)] == 1)) return false;
        }
        else if(it.second == "pulldown"){
            cout<<"Input pulldown: "<<input_status_2.data[stoi(it.first)]<<"|"<<input_status_1.data[stoi(it.first)]<<endl;
            if(!(input_status_2.data[stoi(it.first)] == 1 && input_status_1.data[stoi(it.first)] == 0)) return false;
        }
    }
    return true;
}
int manage_mission::handle_content(const json& content, const double& time_out, double& timer, int& status, rclcpp::Publisher<std_msgs::msg::String>::SharedPtr info_pub, rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_pub){
    static int step = 0;
    static std_msgs::msg::String info_msg;
    static std_msgs::msg::String state_msg;
    cout<<"handle content|step:"<<step<<"|status:"<<status<<endl;
    if(step == 0){
        if(status == Active_){
            RCLCPP_INFO(this->get_logger(),"send infomation function");
            cout<<"INFOMATION CONTENT: "<< content["parameters"]<<endl;
            // info_msg.data = content["parameters"].get<string>();
            info_msg.data = content["parameters"].dump();
            RCLCPP_INFO(this->get_logger(),"gan thong tin vao message");
            cout<<"information: "<< info_msg.data<<endl;
            info_pub->publish(info_msg);
            state_msg.data = "active";
            state_pub->publish(state_msg);
            timer += ts_execute_callback;
            step = 1;
            return Active_;
        }
        else return status;
    }
    else if(step == 1){
        RCLCPP_INFO(this->get_logger(),"send state function");
        if(timer>time_out){
            RCLCPP_INFO(this->get_logger(),"timer lon hon timeout");
            state_msg.data = "error";
            state_pub->publish(state_msg);
            timer = 0.0;
            step = 0;
            return Error_;
        }
        else{
            RCLCPP_INFO(this->get_logger(),"timer nho hon timeout");
            if(state == Finish_){
                RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state finish");
                timer = 0.0;
                step = 0;
                state = N_A_;
                return Finish_;
            }
            else if(state == Active_){
                RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state active");
                if(status == Stop_){
                    RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state active, status stop");
                    state_msg.data = "stop";
                    state_pub->publish(state_msg);
                    return Stop_;
                }
                else{
                    RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state active, status active");
                    timer += ts_execute_callback;
                    return Active_;
                }
            }
            else if(state == Stop_){
                RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state stop");
                if(status == Active_){
                    RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state stop, status active");
                    state_msg.data = "active";
                    state_pub->publish(state_msg);
                    return Active_;
                }
                return Stop_;
            }
            else if(state == True_){
                RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state true");
                timer = 0.0;
                step = 0;
                state = N_A_;
                return True_;
            }
            else if(state == False_){
                RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state false");
                timer = 0.0;
                step = 0;
                state = N_A_;
                return False_;
            }
            else if(state == Error_){
                RCLCPP_INFO(this->get_logger(),"timer nho hon timeout, state error");
                timer = 0.0;
                step = 0;
                state = N_A_;
                return Error_;
            }
            else {
                RCLCPP_INFO(this->get_logger(),"timer nho hon timeout,state N/A");
                timer += ts_execute_callback;
                return Active_;
            }
        }
    }
}
int manage_mission::execute_content(mission& mission, vector<string>& queue_content, string& active_content, string& next_to, int& status){
    // std::lock_guard<std::recursive_mutex> lock(mutex_mission);
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    json content;
    static double timer = 0.0;
    static string type = "none";
    content = mission.contents_map[active_content];
    type = content["type"].get<string>();
    cout<<"Content ID: "<<active_content<<endl;
    cout<<"Type: "<<type<<endl;
    if(type == "start"){
        next_to = content["content"]["next"].get<string>();
        return Finish_;
    }
    else if(type == "group"){
        static std::vector<string> do_content;
        if(!queue_content.empty()){
            queue_content.erase(queue_content.begin());
        }
        do_content = content["content"]["body"].get<std::vector<string>>();
        queue_content.insert(queue_content.begin(),do_content.begin(),do_content.end());
        active_content = queue_content[0];
        if(next_to != ""){
            if(stoi(next_to)<stoi(content["content"]["next"].get<string>())){
                next_to = content["content"]["next"].get<string>();
            }
        }
        else next_to = content["content"]["next"].get<string>();
        return Active_;
    }
    else if(type == "if_else"){
        static string cond_id;
        // static json cond_content;
        static std::vector<string> then_content, else_content;
        int res;
        cond_id = content["content"]["condition"].get<string>();
        // cond_content = mission.contents_map[cond_id];
        res = execute_content(mission, queue_content, cond_id, next_to, status);
        if(res!=True_ && res!=False_) return Active_;
        else{
            if(!queue_content.empty()){
                queue_content.erase(queue_content.begin());
            }
            if(res == True_){
                then_content = content["content"]["then"].get<std::vector<string>>();
                queue_content.insert(queue_content.begin(),then_content.begin(),then_content.end());
            }
            else if(res == False_){
                else_content = content["content"]["else"].get<std::vector<string>>();
                queue_content.insert(queue_content.begin(),else_content.begin(),else_content.end());
            }
            active_content = queue_content[0];
            if(next_to != ""){
                if(stoi(next_to)<stoi(content["content"]["next"].get<string>())){
                    next_to = content["content"]["next"].get<string>();
                }
            }
            else next_to = content["content"]["next"].get<string>();
            return Active_;
        }
    }
    else if(type == "while_do"){
        static string cond_id;
        // static json cond_content;
        static std::vector<string> do_content;
        int res;
        cond_id = content["content"]["condition"].get<string>();
        // cond_content = mission.contents_map[cond_id];
        res = execute_content(mission, queue_content, cond_id, next_to, status);
        if(res!=True_ && res!=False_) return Active_;
        else{
            if(res == True_){
                do_content = content["content"]["do"].get<std::vector<string>>();
                queue_content.insert(queue_content.begin(),do_content.begin(),do_content.end());
                active_content = queue_content[0];

                if(next_to != ""){
                    if(stoi(next_to)<stoi(content["content"]["next"].get<string>())){
                        next_to = content["content"]["next"].get<string>();
                    }
                }
                else next_to = content["content"]["next"].get<string>();
                return Active_;
            }
            else return Finish_;
        }
    }
    else if(type == "try_catch"){
        /* try_catch single
        static std::vector<string> try_content;
        type = "try_catch";
        if(!queue_content.empty()){
            queue_content.erase(queue_content.begin());
        }
        try_content = content["content"]["try"].get<std::vector<string>>();
        queue_content.insert(queue_content.begin(),try_content.begin(),try_content.end());
        active_content = queue_content[0];
        if(next_to != ""){
            if(stoi(next_to)<stoi(content["content"]["next"].get<string>())){
                next_to = content["content"]["next"].get<string>();
            }
        }
        else next_to = content["content"]["next"].get<string>();
        return Active_;
        */
       static int step = 0;
       static vector<string> try_catch_content;
       static vector<string> try_catch_queue;
       static string active_try_catch;
       if(step == 0){
            // Tao hang doi thuc thi try-catch
            try_catch_queue.resize(0);
            try_catch_content = content["content"]["try"].get<std::vector<string>>();
            // try_catch_queue.insert(try_catch_queue.begin(),try_catch_content.begin(),try_catch_content.end());
            try_catch_queue.resize(try_catch_content.size());
            try_catch_queue = try_catch_content;
            if(next_to != ""){
                if(stoi(next_to)<stoi(content["content"]["next"].get<string>())){
                    next_to = content["content"]["next"].get<string>();
                }
            }
            else next_to = content["content"]["next"].get<string>();
            step = 1;
            return Active_;
       }
       else if(step == 1){
            //thuc thi try
            int res;
            active_try_catch = try_catch_queue[0];
            res = execute_content(mission, queue_content, active_try_catch, next_to, status);
            if(res == Active_) return Active_;
            else if(res == Finish_){
                try_catch_queue.erase(try_catch_queue.begin());
                if(try_catch_queue.empty()){
                    step = 0;
                    return Finish_;
                }
                else return Active_;
            }
            else if(res == Error_){
                try_catch_content = content["content"]["catch"].get<std::vector<string>>();
                if(try_catch_content.empty()) return Finish_;
                try_catch_queue.resize(try_catch_content.size());
                try_catch_queue = try_catch_content;
                step = 2;
                return Active_;
            }
       }
       else if(step == 2){
        //thuc thi catch
            int res;
            active_try_catch = try_catch_queue[0];
            res = execute_content(mission, queue_content, active_try_catch, next_to, status);
            if(res == Active_) return Active_;
            else if(res == Finish_){
                try_catch_queue.erase(try_catch_queue.begin());
                if(try_catch_queue.empty()){
                    step = 0;
                    return Finish_;
                }
                else return Active_;
            }
            else if(res == Error_) return Error_;
       }
    }
    else if(type == "and"){
        static vector<string>and_contents_list;
        static int i=0;
        int res;
        // static json and_content;
        and_contents_list = content["content"]["body"].get<std::vector<string>>();
        res = execute_content(mission, queue_content, and_contents_list[i], next_to, status);
        if(res != True_ && res != False_){
            if(res == Error_) return Error_;
            return Active_;
        }
        else{
            if(res == False_){
                i=0;
                return False_;
            }
            else i++;
        }
        if(i == and_contents_list.size()){
            i=0;
            return True_;
        }
        else return Active_;
    }
    else if(type == "or"){
        static vector<string>or_contents_list;
        static int i=0;
        int res;
        // static json or_content;
        or_contents_list = content["content"]["body"].get<std::vector<string>>();
        res = execute_content(mission, queue_content, or_contents_list[i], next_to, status);
        if(res != True_ && res != False_){
            if(res == Error_) return Error_;
            return Active_;
        }
        else{
            if(res == True_){
                i=0;
                return True_;
            }
            else i++;
        }
        cout<<"Gia tri i trong or: "<<i<<"|Gia tri size or: "<<or_contents_list.size()<<endl;
        if(i == or_contents_list.size()){
            i=0;
            return False_;
        }
        else return Active_;
    }
    else if(type == "gpio"){
        // static double time_out;
        static double time_out;
        time_out = stof(content["time_out"].get<string>());
        return handle_content(content, time_out, timer, status, gpio_info_pub_, gpio_function_state_pub_);
    //     if(time_out == 0){
    //         if(check_gpio(content["parameters"].get<std::map<string, json>>()) == True_) return True_;
    //         else return False_;
    //     }
    //     else if(time_out == -1){}
    //     else{
    //         return handle_content(content, time_out, timer, status, gpio_info_pub_, gpio_function_state_pub_);
    //     }
    }
    else if(type == "footprint"){
        static double time_out;
        time_out = stof(content["time_out"].get<string>());
        return handle_content(content, time_out, timer, status, footprint_info_pub_, footprint_function_state_pub_);
    }
    else if(type == "config"){
        static double time_out;
        time_out = stof(content["time_out"].get<string>()); 
        return handle_content(content, time_out, timer, status, config_info_pub_, config_function_state_pub_);
    }
    else if(type == "navigation"){
        static double time_out;
        RCLCPP_INFO(this->get_logger(),"get timeout");
        time_out = stof(content["time_out"].get<string>());
        cout<<"time out: "<<time_out<<endl;
        RCLCPP_INFO(this->get_logger(),"got timeout");
        return handle_content(content, time_out, timer, status, navigation_info_pub_, navigation_function_state_pub_);
    }
    else if(type == "marker"){
        static double time_out;
        time_out = stof(content["time_out"].get<string>());
        return handle_content(content, time_out, timer, status, marker_info_pub_, marker_function_state_pub_);
    }
    else if(type == "var"){
        static double time_out;
        time_out = stof(content["time_out"].get<string>());
        return handle_content(content, time_out, timer, status, var_info_pub_, var_function_state_pub_);
    }
    else if(type == "sleep"){
        static double time_out;
        time_out = stof(content["time_out"].get<string>());
        return handle_content(content, time_out, timer, status, sleep_info_pub_, sleep_function_state_pub_);
    }
    else if(type == "lift"){
        static double time_out;
        time_out = stof(content["time_out"].get<string>());
        return handle_content(content, time_out, timer, status, lift_info_pub_, lift_function_state_pub_);
    }
    else if(type == "brush"){
        static double time_out;
        time_out = stof(content["time_out"].get<string>());
        return handle_content(content, time_out, timer, status, brush_info_pub_, brush_function_state_pub_);
    }
}
void manage_mission::execute_mission(){
    // std::lock_guard<std::recursive_mutex> lock(mutex_mission);
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    //var
    RCLCPP_INFO(this->get_logger(),"start execute mission");
    static mission mission_;
    static string action_mode_mission;
    // static json content_;
    static vector<string> queue_content;
    static string next_to = "";
    static string active_content = "";
    static int active_content_sum;
    static int res;
    if(motor_left_ready==0 || motor_right_ready==0) {
        RCLCPP_INFO(this->get_logger(),"motor is not ready");
        send_history("error","motor is not ready");
        return;
    }
    // if(battery_soc1 <= 20 || battery_soc2 <= 20) want_to_charge = 1;
    // else want_to_charge = 0;
    RCLCPP_INFO(this->get_logger(),"continue execute mission");
    if(status==Finish_){
        RCLCPP_INFO(this->get_logger(),"continue execute mission, status finish");
        //kiem tra yeu cau thuc thi mission
        if(want_to_charge==1){ //mission charge
            status = Active_;
            active_content = "1";
            action_mode_mission = "mission_charge";
            mission_ = mission_charge_battery[0];
            // timer = 0.0;
            queue_content.resize(0);
            next_to = "";
            // type = "none";
        }
        else{ 
            //mission normal
            // for(size_t i=0; i < mission_normal.size(); i++){
            //     check_WakeUp_condition(mission_normal[i].triggers_map["wake_up"]);
            //     if(status == Wake_up_){
            //         status = Active_;
            //         active_mission = i;
            //         active_content = "1";
            //         action_mode_mission = mission_normal_;
            //         mission_ = mission_normal[i];
            //         timer = 0.0;
            //         queue_content.resize(0);
            //         next_to = "";
            //         type = "none";
            //         break;
            //     }
            // }
            // if(status == Finish_) return;
            for(size_t i=0; i < mission_normal.size(); i++){
                if(active_mission_id == mission_normal[i].mission_id){
                    status = Active_;
                    active_mission_id = "";
                    mission_ = mission_normal[i];
                    active_content_sum = mission_.contents_map.size();
                    cout<<"Mission ID: "<<mission_.mission_id<<endl;
                    cout<<mission_.triggers_map["stop"]<<endl;
                    cout<<mission_.triggers_map["continues"]<<endl;
                    //
                    for (const auto& [key, value] : mission_.contents_map) {
                        if (value.contains("type") && value["type"] == "start") {
                            active_content = key;
                        }
                    }
                    //
                    action_mode_mission = "mission_normal";
                    // timer = 0.0;
                    queue_content.resize(0);
                    next_to = "";
                    // type = "none";
                    break;
                }
            }
            // if(status == Finish_) return;
        }
    }
    else {
        RCLCPP_INFO(this->get_logger(),"check stop condition");
        // cout<<mission_.triggers_map["stop"]<<endl;
        check_Stop_condition(mission_.triggers_map["stop"]);
        if (status == Stop_){
            RCLCPP_INFO(this->get_logger(),"check continue condition");
            // timer = 0.0;
            check_Continues_condition(mission_.triggers_map["continues"]);
            cout<<"before check status = Continue_|status: "<<status<<endl;
            if(status == Continue_) status = Active_;
            cout<<"after check status = Continue_|status: "<<status<<endl;
        }
        RCLCPP_INFO(this->get_logger(),"complete check stop condition");
        if (status == Error_){
            RCLCPP_INFO(this->get_logger(),"continue execute mission, status error");
            //pub stop robot
            pub_stop_robot();
            //thuc thi mission error
            static string active_content_error = "1";
            static vector<string>queue_content_error;
            static string next_to_error = "";
            static int active_content_sum_error;
            static int status_mission_error = Active_;
            static int res;
            if(mission_error.contents_map.empty()){
                status_mission_error = Finish_;
                RCLCPP_INFO(this->get_logger(),"finish mission error");
            }
            if(status_mission_error == Active_){
                RCLCPP_INFO(this->get_logger(),"active mission error");
                action_mode_mission = "mission_error";
                active_content_sum_error = mission_error.contents_map.size();
                res = execute_content(mission_error, queue_content_error, active_content_error, next_to_error, status_mission_error);
                if(res == Active_){
                    status_mission_error = Active_;
                }
                else if(res == Error_){
                    status_mission_error = Error_;
                }
                else if(res == Finish_){
                    queue_content_error.erase(queue_content_error.begin());
                    if(queue_content_error.empty()){
                        if(next_to_error == ""){
                            active_content_error = to_string(stoi(active_content_error)+1);
                        }
                        else{
                            active_content_error = next_to_error;
                            next_to_error ="";
                        }
                    }
                    else active_content_error = queue_content_error[0];
                    if(mission_error.contents_map[active_content_error]["type"].get<string>() == "end"){
                        status_mission_error = Finish_;
                        active_content_error = "";
                    }
                    else status_mission_error = Active_;
                }
                pub_active_mission_info(action_mode_mission, mission_error.mission_id, active_content_error, to_string(active_content_sum_error));
            }

        }
        else { //
            // RCLCPP_INFO(this->get_logger(),"continue execute mission, status active");
            // content_ = mission_.contents_map[active_content];
            cout<<"before execute content|status: "<<status<<endl;
            res = execute_content(mission_, queue_content, active_content, next_to, status);
            cout<<"result execute content: "<<res<<endl;
            
            if(res == Active_) {
                status = Active_;
            }
            else if(res == Stop_) {
                pub_stop_robot();
                status = Stop_;
            }
            else if(res == Error_){
                pub_stop_robot();
                status = Error_;
            } 
            else if(res == Finish_){
                // type = "none";
                queue_content.erase(queue_content.begin());
                if(queue_content.empty()){
                    if(next_to == ""){
                        active_content = to_string(stoi(active_content)+1);
                    }
                    else{
                        active_content = next_to;
                        next_to ="";
                    }
                }
                else active_content = queue_content[0];
                if(mission_.contents_map[active_content]["type"].get<string>() == "end"){
                    status = Finish_;
                    action_mode_mission = "N_A";
                    active_content = "";
                    mission_.reset();
                }
                else status = Active_;
            }
            pub_active_mission_info(action_mode_mission, mission_.mission_id, active_content, to_string(active_content_sum));
        }
    }
}