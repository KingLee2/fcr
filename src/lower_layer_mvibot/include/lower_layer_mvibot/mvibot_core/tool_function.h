#include "mvibot_core_init.h"

using namespace std;
//class lift, brush, suction, temperature
class tool_function : public rclcpp::Node{
    private:
        //declare var 
        string mvibot_seri_;
        //declare pub//
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
        ///
        //charge
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr charge_status_pub_;
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
        ///
	    //charge
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr charge_control_sub_;
	//declare timer//
        rclcpp::TimerBase::SharedPtr timer_;
    public:
        tool_function(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = mutuallyExclusive_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            //init pub //
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
            //init sub //
            //brush
            auto brush_status_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") brush_send_uart_status = 1;
                else if(msg.data == "0") brush_send_uart_status = 0;
            };
            brush_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/brush_state", qos_profile, brush_status_callback);
            // brush_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/brush_state", qos_profile, brush_status_callback, sub_options);
            //suction
            auto suction_status_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") suction_send_uart_status = 1;
                else if(msg.data == "0") suction_send_uart_status = 0;
            };
            suction_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/suction_state", qos_profile, suction_status_callback);
            // suction_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/suction_state", qos_profile, suction_status_callback, sub_options);
            //valve
            auto valve_status_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") valve_send_uart_status = 1;
                else if(msg.data == "0") valve_send_uart_status = 0;
            };
            valve_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/valve_state", qos_profile, valve_status_callback);
            // valve_status_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/valve_state", qos_profile, valve_status_callback, sub_options);
            //lift brush
            auto lift_brush_power_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_brush_power_send_uart = 1;
                else if(msg.data == "0") lift_brush_power_send_uart = 0;
            };
            lift_brush_power_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_brush_power", qos_profile, lift_brush_power_callback);
            // lift_brush_power_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_brush_power", qos_profile, lift_brush_power_callback, sub_options);
            auto lift_brush_control_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_brush_control_send_uart = 1;
                else if(msg.data == "0") lift_brush_control_send_uart = 0;
            };
            lift_brush_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_brush_control", qos_profile, lift_brush_control_callback);
            // lift_brush_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_brush_control", qos_profile, lift_brush_control_callback, sub_options);
            auto lift_suction_power_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_suction_power_send_uart = 1;
                else if(msg.data == "0") lift_suction_power_send_uart = 0;
            };
            lift_suction_power_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_suction_power", qos_profile, lift_suction_power_callback);
            // lift_suction_power_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_suction_power", qos_profile, lift_suction_power_callback, sub_options);
            auto lift_suction_control_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") lift_suction_control_send_uart = 1;
                else if(msg.data == "0") lift_suction_control_send_uart = 0;
            };
            lift_suction_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_suction_control", qos_profile, lift_suction_control_callback);
            // lift_suction_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/lift_suction_control", qos_profile, lift_suction_control_callback, sub_options);
            ///
	        //charge
            auto charge_control_callback = [this](std_msgs::msg::String msg)->void{
                // std::lock_guard<std::recursive_mutex> lock(mutex_common);
                std::lock_guard<std::mutex> lock(mutex_tool);
                //nhan du lieu gan vao bien gui uart
                if(msg.data == "1") charge_control_status = 1;
                else if(msg.data == "0") charge_control_status = 0;
            };
            charge_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/charge_control", qos_profile, charge_control_callback);
            // charge_control_sub_ = this->create_subscription<std_msgs::msg::String>(mvibot_seri_+"/charge_control", qos_profile, charge_control_callback, sub_options);
	        //init timer//
            auto timer_callback = [this]()->void{
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
                ///
                pub_status_charge(); 
            };
            timer_ = this->create_wall_timer(1000ms, timer_callback);
            // timer_ = this->create_wall_timer(1000ms, timer_callback, reentrant_cbg);
        }
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
	    void pub_status_charge(); 
};
void tool_function::pub_temperature(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"temperature_outside"+":"+to_string(temperature_outside)+"|";
            msg.data=msg.data+"temperature_electric_box"+":"+to_string(temperature_electric_box);
            temperature_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_water_level(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"dirty_water_level"+":"+to_string(dirty_water_level)+"|";
            msg.data=msg.data+"clean_water_level"+":"+to_string(clean_water_level);
            water_level_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_status_brush(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"brush"+":"+to_string(brush_receive_uart_status);
            
            brush_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_status_suction(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"suction"+":"+to_string(suction_receive_uart_status);
            
            suction_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_status_valve(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"valve"+":"+to_string(valve_receive_uart_status);
            
            valve_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_status_lift_brush(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_brush_power"+":"+to_string(lift_brush_power_receive_uart)+"|";
            msg.data=msg.data+"lift_brush_control"+":"+to_string(lift_brush_control_receive_uart);
            lift_brush_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_status_lift_suction(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_suction_power"+":"+to_string(lift_suction_power_receive_uart)+"|";
            msg.data=msg.data+"lift_suction_control"+":"+to_string(lift_suction_control_receive_uart);
            lift_suction_status_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_data_lift_brush(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::Float32 msg;
            // gan du lieu nhan tu uart
            msg = lift_brush_data;
            lift_brush_data_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_data_lift_suction(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::Float32 msg;
            // gan du lieu nhan tu uart
            msg = lift_suction_data;
            lift_suction_data_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_mode_lift_brush(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_brush_mode"+":"+to_string(lift_brush_mode);
            
            lift_brush_mode_pub_->publish(msg);
    }else creat_fun=1;
}
void tool_function::pub_mode_lift_suction(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"lift_suction_mode"+":"+to_string(lift_suction_mode);
            
            lift_suction_mode_pub_->publish(msg);
    }else creat_fun=1;
}
///////
void tool_function::pub_status_charge(){
    static float creat_fun=0;
    // std::lock_guard<std::recursive_mutex> lock(mutex_common);
    std::lock_guard<std::mutex> lock(mutex_tool);
    if(creat_fun==1){
            static std_msgs::msg::String msg;
            msg.data=mvibot_seri+"|";
            msg.data=msg.data+"charge_status"+":"+to_string(charge_receive_uart_status);
            charge_status_pub_->publish(msg);
    }else creat_fun=1;
}
