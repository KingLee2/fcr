#include "mvibot_core_init.h"
#include"../common/stof.h"
#include"../common/exec.h"

using namespace std;
using json = nlohmann::json;
//class lift, brush, suction, temperature, sensor, battery, config
class tool_node : public rclcpp::Node{
    private:
        //declare var 
        string mvibot_seri_;
        float ts_scan_sensor;
        int local_uart_live;
        //
        int start_software_launch=0;
        // radar1 status
        int radar1_live=0;
        float time_live_radar1=0;
        // radar2 status
        int radar2_live=0;
        float time_live_radar2=0;
        // camera1 status
        int camera1_live=0;
        float time_live_camera1=0;
        // camera2 status
        int camera2_live=0;
        float time_live_camera2=0;
        // uart
        // int uart_live=0;
        // battery status
        int battery_status=0;
        float time_live_batterry=0;
        // ready sensor when radar 1 2 camera 1 2 is ready
        int dym_set_camera1=0,dym_set_camera2=0;
        int reset_radar1,reset_radar2,reset_camera1,reset_camera2;
        //
        string robot_config_string;
        //declare pub//
        //pub history
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr history_pub_;
        //pub config
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_config_pub_;
        //pub sensor status
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr  sensor_status_pub_;
        //temperature
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr temperature_pub_;
        //water level
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr water_level_pub_;
        //brush
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr brush_status_pub_;
        //suction
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr suction_status_pub_;
        //valve
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr valve_status_pub_;
        //lift
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_brush_status_pub_;
        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr lift_brush_data_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_brush_mode_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_suction_status_pub_;
        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr lift_suction_data_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr lift_suction_mode_pub_;
        //charge
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr charge_status_pub_;
        // battery
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr battery_status_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr battery_cell_status_pub_;
        //declare sub//
        // brush
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr brush_status_sub_;
        //suction
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr suction_status_sub_;
        //valve
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr valve_status_sub_;
        //lift brush
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lift_brush_power_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lift_brush_control_sub_;
        //lift suction
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lift_suction_power_sub_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lift_suction_control_sub_;
        //sub sensor data
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan1_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan2_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr camera1_scan_sub_;
        rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr camera2_scan_sub_;
	    //charge
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr charge_control_sub_;
        ////config sub
        //operation
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr operation_sub_;
        //serial camera
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr serial_camera_sub_;
        //wifi
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr wifi_connect_sub_;
        //ethernet
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr ethernet_connect_sub_;
	    //declare timer//
        rclcpp::TimerBase::SharedPtr timer_;
        //
        rclcpp::Time check_time_pub;
    public:
        tool_node(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            // auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            // auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            // rclcpp::SubscriptionOptions sub_options;
            // sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            ts_scan_sensor = 1.0;
            //load file config robot//
            robot_load_config();
            //init pub //
            //pub history
            history_pub_ = this->create_publisher<std_msgs::msg::String>("history",1);
            //pub config
            robot_pub_ = this->create_publisher<std_msgs::msg::String>("robot",1);
            robot_status_pub_ = this->create_publisher<std_msgs::msg::String>("robot_status",1);
            robot_config_pub_ = this->create_publisher<std_msgs::msg::String>("config_robot",1);
            //pub sensor status
            sensor_status_pub_ = this->create_publisher<std_msgs::msg::String>("sensor_status",1);
            //temperature
            temperature_pub_ = this->create_publisher<std_msgs::msg::String>("temperature",1);
            //temperature
            water_level_pub_ = this->create_publisher<std_msgs::msg::String>("water_level",1);
            //brush
            brush_status_pub_ = this->create_publisher<std_msgs::msg::String>("brush_status",1);
            //suction
            suction_status_pub_ = this->create_publisher<std_msgs::msg::String>("suction_status",1);
            //valve
            valve_status_pub_ = this->create_publisher<std_msgs::msg::String>("valve_status",1);
            //lift brush
            lift_brush_status_pub_ = this->create_publisher<std_msgs::msg::String>("lift_brush_status",1);
            lift_brush_data_pub_ = this->create_publisher<std_msgs::msg::Float32>("lift_brush_data",1);
            lift_brush_mode_pub_ = this->create_publisher<std_msgs::msg::String>("lift_brush_mode",1);
            //lift suction
            lift_suction_status_pub_ = this->create_publisher<std_msgs::msg::String>("lift_suction_status",1);
            lift_suction_data_pub_ = this->create_publisher<std_msgs::msg::Float32>("lift_suction_data",1);
            lift_suction_mode_pub_ = this->create_publisher<std_msgs::msg::String>("lift_suction_mode",1);
            ///
	        //charge
            charge_status_pub_ = this->create_publisher<std_msgs::msg::String>("charge_status",1);
            battery_status_pub_ = this->create_publisher<std_msgs::msg::String>("battery_status",1);
            battery_cell_status_pub_ = this->create_publisher<std_msgs::msg::String>("battery_cell_status",1);
            //init sub //
            //config sub
            //operation
            auto operation_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                static string file_name;
                file_name = "/home/mvibot/floorCleaningRobot_ws/config/mode";
                try{
                    std::ofstream file(file_name);
                    if (!file.is_open()){
                        return;
                    }
                    file <<msg.data;
                    file.close();    
                }
                catch (const std::exception& e){
                    send_history("error", "Error config operation: " + std::string(e.what()));
                }
            };
            operation_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri + "/operation",qos_profile, operation_callback);
            //camera
            auto camera_config_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                string file_camera1, file_camera2;
                json camera_config;
                string camera1_config;
                string camera2_config;
                file_camera1 = "/home/mvibot/floorCleaningRobot_ws/config/serial_camera1";
                file_camera2 = "/home/mvibot/floorCleaningRobot_ws/config/serial_camera2";
                camera_config = msg.data;
                camera1_config = camera_config["serial_camera1"].get<string>();
                camera2_config = camera_config["serial_camera2"].get<string>();
                try{
                    //
                    std::ofstream file1(file_camera1);
                    if (!file1.is_open()){
                        return;
                    }
                    file1 <<camera1_config;
                    file1.close();
                    //
                    std::ofstream file2(file_camera2);
                    if (!file2.is_open()){
                        return;
                    }
                    file2 <<camera2_config;
                    file2.close();
                }
                catch (const std::exception& e){
                    send_history("error", "Error config camera: " + std::string(e.what()));
                }
            };
            serial_camera_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri+"/camera_config",qos_profile,camera_config_callback);
            //wifi config
            auto wifi_config_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                string file_wifi_type, file_wifi_ssid, file_wifi_password;
                json wifi_config;
                string wifi_mode_config, ssid_config, pw_config;
                file_wifi_type = "/home/mvibot/floorCleaningRobot_ws/config/wifi_type";
                file_wifi_ssid = "/home/mvibot/floorCleaningRobot_ws/config/wifi_ssid";
                file_wifi_password = "/home/mvibot/floorCleaningRobot_ws/config/wifi_password";
                wifi_config = msg.data;
                wifi_mode_config = wifi_config["mode"].get<string>();
                ssid_config = wifi_config["ssid"].get<string>();
                pw_config = wifi_config["password"].get<string>();
                try{
                    //
                    std::ofstream file1(file_wifi_type);
                    if (!file1.is_open()){
                        return;
                    }
                    file1 <<wifi_mode_config;
                    file1.close();
                    //
                    std::ofstream file2(file_wifi_ssid);
                    if (!file2.is_open()){
                        return;
                    }
                    file2 <<ssid_config;
                    file2.close();
                    //
                    std::ofstream file3(file_wifi_password);
                    if (!file3.is_open()){
                        return;
                    }
                    file3 <<pw_config;
                    file3.close();
                }
                catch (const std::exception& e){
                    send_history("error", "Error config wifi: " + std::string(e.what()));
                }
            };
            wifi_connect_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri+"/wifi_config", qos_profile, wifi_config_callback);
            //ethernet
            auto ethernet_config_callback= [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                static string file_name;
                file_name = "/home/mvibot/floorCleaningRobot_ws/config/lan_type";
                try{
                    std::ofstream file(file_name);
                    if (!file.is_open()){
                        return;
                    }
                    file <<msg.data;
                    file.close();
                }
                catch (const std::exception& e){
                    send_history("error", "Error config ethernet: " + std::string(e.what()));
                }
            };
            ethernet_connect_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri+"/ethernet_config",qos_profile,ethernet_config_callback);
            //sensor
            auto laser_scan1_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{

                std::lock_guard<std::mutex> lock(mutex_tool);
                radar1_live_status = 1;
            };
            laser_scan1_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan1",qos_profile,laser_scan1_callback);
            auto laser_scan2_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                radar2_live_status = 1;
            };
            laser_scan2_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/laser/scan1",qos_profile,laser_scan2_callback);
            auto camera1_scan_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                camera1_live_status = 1;
            };
            camera1_scan_sub_ =  this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/camera1/scan",qos_profile,camera1_scan_callback);
            auto camera2_scan_callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                camera2_live_status = 1;
            };
            camera2_scan_sub_ =  this->create_subscription<sensor_msgs::msg::LaserScan>(mvibot_seri_+"/camera2/scan",qos_profile,camera2_scan_callback);
            //brush
            auto brush_status_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") brush_send_uart_status = 1;
                else if(msg.data == "0") brush_send_uart_status = 0;
            };
            brush_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/brush_state", qos_profile, brush_status_callback);
            //suction
            auto suction_status_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") suction_send_uart_status = 1;
                else if(msg.data == "0") suction_send_uart_status = 0;
            };
            suction_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/suction_state", qos_profile, suction_status_callback);
            //valve
            auto valve_status_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") valve_send_uart_status = 1;
                else if(msg.data == "0") valve_send_uart_status = 0;
            };
            valve_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/valve_state", qos_profile, valve_status_callback);
            //lift brush
            auto lift_brush_power_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_brush_power_send_uart = 1;
                else if(msg.data == "0") lift_brush_power_send_uart = 0;
            };
            lift_brush_power_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_brush_power", qos_profile, lift_brush_power_callback);
            auto lift_brush_control_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_brush_control_send_uart = 1;
                else if(msg.data == "0") lift_brush_control_send_uart = 0;
            };
            lift_brush_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_brush_control", qos_profile, lift_brush_control_callback);
            auto lift_suction_power_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_suction_power_send_uart = 1;
                else if(msg.data == "0") lift_suction_power_send_uart = 0;
            };
            lift_suction_power_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_suction_power", qos_profile, lift_suction_power_callback);
            auto lift_suction_control_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_suction_control_send_uart = 1;
                else if(msg.data == "0") lift_suction_control_send_uart = 0;
            };
            lift_suction_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_suction_control", qos_profile, lift_suction_control_callback);
            ///
	        //charge
            auto charge_control_callback = [this](std_msgs::msg::String msg)->void{
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") charge_control_status = 1;
                else if(msg.data == "0") charge_control_status = 0;
            };
            charge_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/charge_control", qos_profile, charge_control_callback);
	        //init timer//
            auto timer_callback = [this]()->void{
                {
                    std::lock_guard<std::mutex> lock(mutex_socket);
                    local_uart_live = uart_live;
                }
                std::lock_guard<std::mutex> lock(mutex_tool);
                rclcpp::Time now = this->get_clock()->now();
                if (check_time_pub.nanoseconds() > 0) {
                    rclcpp::Duration dt = now - check_time_pub;
                    RCLCPP_INFO(this->get_logger(), "pub data tool with period: %.6f s", dt.seconds());
                }
                check_time_pub = now;
                //
                pub_robot();
                pub_robot_config();
                pub_information_robot();
                //
                check_sensor();
                //
                pub_temperature();
                pub_water_level();
                pub_status_brush();
                pub_status_suction();
                pub_status_valve();
                pub_status_lift_brush();
                pub_data_lift_brush();
                pub_mode_lift_brush();
                pub_status_lift_suction();
                pub_data_lift_suction();
                pub_mode_lift_suction();
                // 
                pub_status_charge();
                //
                pub_battery_status();
                pub_battery_cell_status();
                //
            };
            timer_ = this->create_wall_timer(1000ms, timer_callback);
        }
        void send_history(string status, string info);
        //
        string load_file(string name_file);
        void robot_load_config();
        void pub_robot_config();
        void pub_robot();
        void pub_information_robot();
        //
        void pub_sensor_status();
        void check_sensor();
        //
        void pub_temperature();
        void pub_water_level();
        void pub_status_brush();
        void pub_status_suction();
        void pub_status_valve();
        void pub_status_lift_brush();
        void pub_status_lift_suction();
        void pub_data_lift_brush();
        void pub_data_lift_suction();
        void pub_mode_lift_brush();
        void pub_mode_lift_suction();
        //
	    void pub_status_charge();
        void pub_battery_status();
        void pub_battery_cell_status();
};
void tool_node::send_history(string status, string info){
    static std_msgs::msg::String history_msg;
    history_msg.data = mvibot_seri+"|" + "status:"+status + "|" + "content:" + info;
    history_pub_->publish(history_msg);
}
//
string tool_node::load_file(string name_file){
    //
    static string value_return;
    try
    {
	    std::ifstream file(define_path+"config/"+name_file);
	    std::string str; 
	    std::string data;
        std::getline(file, str);
        value_return=str;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        value_return="-1";
    }
    return value_return;
}
void tool_node::robot_load_config(){
    static string config;
    static string my_port;
    // //
    // robot_config_string=mvibot_seri+"|";
    config=load_file("name_seri");
    if(config!="-1"){
        mvibot_seri = config;
        robot_config_string=mvibot_seri+"|";
    }
    // robot config 
    config=load_file("robot_R");
    if(config!="-1") R=stof_f(config);
    if(config!="-1") robot_config_string+="robot_R:"+config+"|";
    //
    config=load_file("robot_L");
    if(config!="-1") L=stof_f(config);
    if(config!="-1") robot_config_string+="robot_L:"+config+"|";
    //
    config=load_file("robot_gear");
    if(config!="-1") gear=stof_f(config);
    if(config!="-1") robot_config_string+="robot_gear:"+config+"|";
    //
    config=load_file("robot_ax");
    if(config!="-1") ax=stof_f(config);
    if(config!="-1") robot_config_string+="robot_ax:"+config+"|";
    //
    config=load_file("robot_aw");
    if(config!="-1") aw=stof_f(config);
    if(config!="-1") robot_config_string+="robot_aw:"+config+"|";
    //
    config=load_file("robot_vmax");
    if(config!="-1") v_max=stof_f(config);
    if(config!="-1") robot_config_string+="robot_vmax:"+config+"|";
    //
    config=load_file("robot_wmax");
    if(config!="-1") w_max=stof_f(config);
    if(config!="-1") robot_config_string+="robot_wmax:"+config+"|";
    //
    config=load_file("robot_volume");
    if(config!="-1") volume=stof_f(config);
    if(config!="-1") robot_config_string+="robot_volume:"+config+"|";
    //
    config=load_file("robot_low_battery");
    if(config!="-1") robot_config_string+="robot_low_battery:"+config+"|";
    //
    config=load_file("robot_type_connect");
    if(config!="-1") {
        robot_config_string+="robot_type_connect:"+config+"|";
        if(config=="lan") my_port=load_file("lan_port");
        if(config=="wifi") my_port=load_file("wifi_port");
    }
    // camera seri config
    config=load_file("serial_camera1");
    if(config!="-1") robot_config_string+="serial_camera1:"+config+"|";
    //
    config=load_file("serial_camera2");
    if(config!="-1") robot_config_string+="serial_camera2:"+config+"|";  
    // lan cònfig
    config=load_file("lan_type");
    if(config!="-1") robot_config_string+="lan_type:"+config+"|";  
    config=load_file("lan_ipv4");
    if(config!="-1") robot_config_string+="lan_ipv4:"+config+"|";  
    config=load_file("lan_ipv4_gateway");
    if(config!="-1") robot_config_string+="lan_ipv4_gateway:"+config+"|";  
    config=load_file("lan_ipv4_dns");
    if(config!="-1") robot_config_string+="lan_ipv4_dns:"+config+"|";  
    // wifi cònfig
    config=load_file("wifi_type");
    if(config!="-1") robot_config_string+="wifi_type:"+config+"|";  
    config=load_file("wifi_ssid");
    if(config!="-1") robot_config_string+="wifi_ssid:"+config+"|";
    config=load_file("wifi_password");
    if(config!="-1") robot_config_string+="wifi_password:"+config+"|";
    config=load_file("wifi_ipv4");
    if(config!="-1") robot_config_string+="wifi_ipv4:"+config+"|";  
    config=load_file("wifi_ipv4_gateway");
    if(config!="-1") robot_config_string+="wifi_ipv4_gateway:"+config+"|";  
    config=load_file("wifi_ipv4_dns");
    if(config!="-1") robot_config_string+="wifi_ipv4_dns:"+config+"|";  
    //  operating config
    config=load_file("mode");
    if(config!="-1") mode = config;
    if(config!="-1") robot_config_string+="mode:"+config+"|";  
    //
    // config=load_file("ip_robot");
    // if(config!="-1") robot_config_string+="ip_robot:"+config+"|";  
    //
    config=load_file("is_master");
    if(config!="-1") robot_config_string+="is_master:"+config+"|";  
    //
    config="ip -4 addr show "+my_port+" | grep -oP '(?<=inet\\s)\\d+(\\.\\d+){3}'";
    config=exec(config.c_str());
    config.erase(std::remove(config.begin(), config.end(), '\n'), config.cend());
    robot_config_string+="ip_robot:"+config;//+"|"; 
    try{
        std::ofstream file(define_path+"config/ip_robot");
        if (!file.is_open()){
            cout<<"error open file ip_robot"<<endl;
            return;
        }
        file <<config;
        file.close();
    }catch(const std::exception& e){
        cout<<"error| update ip_robot into file:"<<e.what()<<endl;
    }
    /*
    config=load_file("ip_node");
    if(config!="-1") robot_config_string+="ip_node:"+config;//+"|";  
    //*/
}
void tool_node::pub_robot(){
    static float creat_fun=0;
    if(creat_fun==1){
        static std_msgs::msg::String msg;
        msg.data=mvibot_seri+"|robot";
        robot_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_information_robot(){
    static float creat_fun=0;
    static vector<string> list={"mode","robot_type_connect","ip_robot"};
    // static vector<string> list={"name","mode","ip_robot"};
    static vector<string> param;
    static std_msgs::msg::String msg;
    if(creat_fun==1){
            robot_status_pub_->publish(msg);
    }else{
        creat_fun=1;
        param.resize(list.size());
        for(int i=0;i<list.size();i++){
            try{
                    std::ifstream file(define_path+"config/"+list[i]);
                    static std::string str; 
                    static std::string data;
                    data="";
                    while (std::getline(file, str))
                    {
                        // Process str
                        data=str;
                    }
                    file.close();
                    param[i]=data;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        msg.data=mvibot_seri;
        for(int i=0;i<list.size();i++){
            msg.data=msg.data+"|";
            msg.data=msg.data+list[i]+":"+param[i];
        }
    }
}
void tool_node::pub_robot_config(){
    static float creat_fun=0;
    if(creat_fun==1){
        static std_msgs::msg::String msg;
        msg.data=robot_config_string;
        robot_config_pub_->publish(msg);
    }else creat_fun=1;
}
//
void tool_node::pub_sensor_status(){
    static std_msgs::msg::String sensor_status_msg;
    static float create_fun = 0;
    if(create_fun==1){
        sensor_status_msg.data=mvibot_seri+"|";
        sensor_status_msg.data=sensor_status_msg.data+"uart:"+to_string((int)local_uart_live)+"|";
        sensor_status_msg.data=sensor_status_msg.data+"radar1:"+to_string((int)radar1_live)+"|";
        sensor_status_msg.data=sensor_status_msg.data+"radar2:"+to_string((int)radar2_live)+"|";
        sensor_status_msg.data=sensor_status_msg.data+"camera1:"+to_string((int)camera1_live)+"|";
        sensor_status_msg.data=sensor_status_msg.data+"camera2:"+to_string((int)camera2_live)+"|";
        sensor_status_msg.data=sensor_status_msg.data+"battery:"+to_string((int)battery_status);
        sensor_status_pub_->publish(sensor_status_msg);
    }else create_fun=1;
}
void tool_node::check_sensor(){
    // radar1 
    if(radar1_live_status==1){
        if(time_live_radar1<0) time_live_radar1=0;
        else time_live_radar1+=(float)ts_scan_sensor;
        if(time_live_radar1>=2.0) time_live_radar1=2.0;
    }else{
        if(time_live_radar1>0) time_live_radar1=0;
        else time_live_radar1-=(float)ts_scan_sensor;
        if(time_live_radar1<=-30.0) time_live_radar1=-30.0;
    }
    radar1_live_status=0;
    if(time_live_radar1>=2.0){
        if(radar1_live==0){
            send_history("normal","Radar1 is available");
            radar1_live=1;
            RCLCPP_INFO(this->get_logger(),"Radar1 is available");
        }
    }
    else{
        if(radar1_live==1){
            // time to restartup sensor when sensor is live before
            if(time_live_radar1<=-3.0) 
            {
                radar1_live=0;
                time_live_radar1=0;
                reset_radar1=1;
                send_history("error","Restart radar1 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart radar1 because no signal");
            }
        }else{
            // time to restartup sensor
            if(time_live_radar1<=-5.0){
                radar1_live=0;
                time_live_radar1=0;
                reset_radar1=1;
                send_history("error","Restart radar1 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart radar1 because no signal");
            }
        }
    }
    // radar2
    if(radar2_live_status==1){
        if(time_live_radar2<0) time_live_radar2=0;
        else time_live_radar2+=(float)ts_scan_sensor;
        if(time_live_radar2>=2.0) time_live_radar2=2.0;
    }else{
        if(time_live_radar2>0) time_live_radar2=0;
        else time_live_radar2-=(float)ts_scan_sensor;
        if(time_live_radar2<=-30.0) time_live_radar2=-30.0;
    }
    radar2_live_status=0;
    if(time_live_radar2>=2.0){
        if(radar2_live==0){ 
            send_history("normal","Radar2 is available");
            radar2_live=1;
            RCLCPP_INFO(this->get_logger(),"Radar2 is available");
        }
    }
    else{
        if(radar2_live==1){
            // time to restartup sensor when sensor is live before
            if(time_live_radar2<=-3.0) 
            {
                radar2_live=0;
                time_live_radar2=0;
                reset_radar2=1;
                send_history("error","Restart radar2 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart radar2 because no signal");
            }
        }else{
            // time to restartup sensor
            if(time_live_radar2<=-5.0){
                radar2_live=0;
                time_live_radar2=0;
                reset_radar2=1;
                send_history("error","Restart radar2 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart radar2 because no signal");
            }
        }
    }
    // camera1
    if(camera1_live_status==1){
        if(time_live_camera1<0) time_live_camera1=0;
        else time_live_camera1+=(float)ts_scan_sensor;
        if(time_live_camera1>=5.0) time_live_camera1=5.0;
    }else{
        if(time_live_camera1>0) time_live_camera1=0;
        else time_live_camera1-=(float)ts_scan_sensor;
        if(time_live_camera1<=-30.0) time_live_camera1=-30.0;
    }
    camera1_live_status=0;
    if(time_live_camera1>=5.0){
        if(camera1_live==0){
            send_history("normal","Camera1 is available");
            camera1_live=1;
            dym_set_camera1=1;
            RCLCPP_INFO(this->get_logger(),"Camera1 is available");
        }
    }
    else{
        if(camera1_live==1){
            // time to restartup sensor when sensor is live before
            if(time_live_camera1<=-5.0) 
            {
                camera1_live=0;
                time_live_camera1=0;
                reset_camera1=1;
                send_history("error","Restart camera1 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart camera1 because no signal");
            }
        }else{
            // time to restartup sensor
            if(time_live_camera1<=-30.0){
                camera1_live=0;
                time_live_camera1=0;
                reset_camera1=1;
                send_history("error","Restart camera1 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart camera1 because no signal");
            }
        }
    }
    // camera2
    if(camera2_live_status==1){
        if(time_live_camera2<0) time_live_camera2=0;
        else time_live_camera2+=(float)ts_scan_sensor;
        if(time_live_camera2>=5.0) time_live_camera2=5.0;
    }else{
        if(time_live_camera2>0) time_live_camera2=0;
        else time_live_camera2-=(float)ts_scan_sensor;
        if(time_live_camera2<=-30.0) time_live_camera2=-30.0;
    }
    camera2_live_status=0;
    if(time_live_camera2>=5.0) {
        if(camera2_live==0){
            send_history("normal","Camera2 is available");
            camera2_live=1;
            dym_set_camera2=1;
            RCLCPP_INFO(this->get_logger(),"Camera2 is available");
        }
    }
    else{
        if(camera2_live==1){
            // time to restartup sensor when sensor is live before
            if(time_live_camera2<=-5.0) 
            {
                camera2_live=0;
                time_live_camera2=0;
                reset_camera2=1;
                send_history("error","Restart camera2 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart camera2 because no signal");
            }
        }else{
            // time to restartup sensor
            if(time_live_camera2<=-30.0){
                camera2_live=0;
                time_live_camera2=0;
                reset_camera2=1;
                send_history("error","Restart camera2 because no signal");
                RCLCPP_INFO(this->get_logger(),"Restart camera2 because no signal");
            }
        }
    }
    if(radar1_live==1 && radar2_live==1 && camera1_live==1 && camera2_live==1 && local_uart_live==1) mvibot_sensor_ready=1;
    else mvibot_sensor_ready=0;
    RCLCPP_INFO(rclcpp::get_logger("Sensor"), "mvibot_sensor_ready: %d", mvibot_sensor_ready);
    // first time ready -> start launch mvibot software
    if(start_software_launch==0 && mvibot_sensor_ready==1){
        //
        send_history("normal","Sensor startup success. Start up mode: "+mode);
        RCLCPP_INFO(rclcpp::get_logger("sensor"),"Sensor startup success. Start up mode: %s",mode);
        //// TAM THOI CHUA KICH HOAT
        // static string command;
        start_software_launch=1;
        // command="";
        // command=command+"roslaunch mvibot_v4 mvibot_software.launch name_seri:="+mvibot_seri+" mode:="+mode+" &";
        // system(command.c_str());
    }
    // battery check
    if(battery_live_status==1 && local_uart_live==1){
        if(time_live_batterry<0) time_live_batterry=0;
        else{
            time_live_batterry+=(float)ts_scan_sensor;
            if(time_live_batterry>=5.0) time_live_batterry=5.0;
        }
    }else{
        if(time_live_batterry>0) time_live_batterry=0;
        else{
            time_live_batterry-=(float)ts_scan_sensor;
            if(time_live_batterry<=-5.0) time_live_batterry=-5.0;
        }
    }
    battery_live_status=0;
    if(time_live_batterry>=3.0){
        if(battery_status!=1) send_history("normal","Battery is available");
        battery_status=1;
    }
    if(time_live_batterry<=-2.0){
        if(battery_status!=0) send_history("error","Battery no signal");
        battery_status=0;
    }
    //pub sensor status
    pub_sensor_status();
}
//
void tool_node::pub_temperature(){
    static float creat_fun=0;
    if(creat_fun==1){
        static std_msgs::msg::String msg;
        msg.data=mvibot_seri+"|";
        msg.data=msg.data+"temperature_outside"+":"+to_string(temperature_outside)+"|";
        msg.data=msg.data+"temperature_electric_box"+":"+to_string(temperature_electric_box);
        temperature_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_water_level(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"dirty_water_level"+":"+to_string(dirty_water_level)+"|";
            msg.data=msg.data+"clean_water_level"+":"+to_string(clean_water_level);
            water_level_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_status_brush(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"brush"+":"+to_string(brush_receive_uart_status);
            
            brush_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_status_suction(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"suction"+":"+to_string(suction_receive_uart_status);
            
            suction_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_status_valve(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"valve"+":"+to_string(valve_receive_uart_status);
            
            valve_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_status_lift_brush(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_brush_power"+":"+to_string(lift_brush_power_receive_uart)+"|";
            msg.data=msg.data+"lift_brush_control"+":"+to_string(lift_brush_control_receive_uart);
            lift_brush_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_status_lift_suction(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_suction_power"+":"+to_string(lift_suction_power_receive_uart)+"|";
            msg.data=msg.data+"lift_suction_control"+":"+to_string(lift_suction_control_receive_uart);
            lift_suction_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_data_lift_brush(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::Float32 msg;
            // gan du lieu nhan tu uart
            msg = lift_brush_data;
            lift_brush_data_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_data_lift_suction(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::Float32 msg;
            // gan du lieu nhan tu uart
            msg = lift_suction_data;
            lift_suction_data_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_mode_lift_brush(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_brush_mode"+":"+to_string(lift_brush_mode);
            
            lift_brush_mode_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_mode_lift_suction(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_suction_mode"+":"+to_string(lift_suction_mode);
            
            lift_suction_mode_pub_->publish(msg);
    }else creat_fun=1;
}
//
void tool_node::pub_status_charge(){
    static float creat_fun=0;
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"charge_status"+":"+to_string(charge_receive_uart_status);
            charge_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_node::pub_battery_status(){
    static float creat_fun=0;
    static std_msgs::msg::String battery_msg;
    if(creat_fun==1){
        battery_msg.data=mvibot_seri+"|";
        if(battery_live_status==1){
            battery_msg.data=battery_msg.data+"soc:"+to_string((int)battery_soc)+"|";
            battery_msg.data=battery_msg.data+"vol:"+to_string(battery_vol)+"|";
            battery_msg.data=battery_msg.data+"cycle:"+to_string((int)battery_cycle)+"|";
            battery_msg.data=battery_msg.data+"capacity_now:"+to_string(battery_mah_now/100)+"|";
            battery_msg.data=battery_msg.data+"capacity_max:"+to_string(battery_mah_max/100)+"|";
            if(battery_current>=0) battery_msg.data=battery_msg.data+"charge:1|";
            else battery_msg.data=battery_msg.data+"charge:0|";
            battery_msg.data=battery_msg.data+"current:"+to_string(battery_current/100)+"|";
            battery_msg.data=battery_msg.data+"num_cell:"+to_string((int)battery_num_cell)+"|";
            battery_msg.data=battery_msg.data+"temperature:"+to_string(battery_temperature);
        }else battery_msg.data="N/A";
        battery_status_pub_->publish(battery_msg);
    }else creat_fun=1;
}
void tool_node::pub_battery_cell_status(){
    static float creat_fun=0;
    static std_msgs::msg::String battery_cell_msg;
    if(creat_fun==1){
        battery_cell_msg.data=mvibot_seri+"|";
        if(battery_live_status==1){
            for(int i=0;i<7;i++){
                battery_cell_msg.data=battery_cell_msg.data+"Cell"+to_string(i+1)+":"+to_string(battery_cell[i])+"|";
            }
            battery_cell_msg.data=battery_cell_msg.data+"Cell"+to_string(7+1)+":"+to_string(battery_cell[7]);
        }else battery_cell_msg.data="N/A";
        battery_cell_status_pub_->publish(battery_cell_msg);
    }else creat_fun=1;
}