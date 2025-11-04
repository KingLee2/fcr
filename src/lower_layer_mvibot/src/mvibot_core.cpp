// #include "../include/lower_layer_mvibot/mvibot_core/mvibot_core_init.h"
#include "../include/lower_layer_mvibot/mvibot_core/socket_client.h"
#include "../include/lower_layer_mvibot/mvibot_core/config.h"
#include "../include/lower_layer_mvibot/mvibot_core/odom.h"
#include "../include/lower_layer_mvibot/mvibot_core/imu.h"
#include "../include/lower_layer_mvibot/mvibot_core/sensor.h"
#include "../include/lower_layer_mvibot/mvibot_core/music.h"
#include "../include/lower_layer_mvibot/mvibot_core/led.h"
#include "../include/lower_layer_mvibot/mvibot_core/motor.h"
#include "../include/lower_layer_mvibot/mvibot_core/battery.h"
#include "../include/lower_layer_mvibot/mvibot_core/gpio.h"
#include "../include/lower_layer_mvibot/mvibot_core/tool_function.h"
////
#include "../include/lower_layer_mvibot/mvibot_core/tool_node.h"
#include "../include/lower_layer_mvibot/mvibot_core/socket_client_node.h"
#include "../include/lower_layer_mvibot/mvibot_core/odometry_node.h"
#include "../include/lower_layer_mvibot/mvibot_core/control_node.h"
using namespace std;

int main(int argc, char **argv){
    string mvibot_seri_;
    input_user.data.resize(15);
    output_user.data.resize(12);
    output_user.data.resize(12);
    try
    {
	    std::ifstream file(define_path+"config/name_seri");
	    std::string str; 
	    std::string data;
        std::getline(file, str);
        mvibot_seri_=str;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        mvibot_seri_="mvibot";
    }
    //some initiallization 
    rclcpp::init(argc,argv);
    rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 4);

    // //Instantiate node
    // auto socket_client_ = std::make_shared<socket_client>("socket_client",mvibot_seri_);
    // auto config_ = std::make_shared<config>("config",mvibot_seri_);
    // auto odom_ = std::make_shared<odometry>("odometry",mvibot_seri_);
    // auto Imu_ = std::make_shared<imu>("imu",mvibot_seri_);
    // auto sensor_ = std::make_shared<sensor>("sensor",mvibot_seri_);
    // //auto music_ = std::make_shared<music>("music","mvibot");
    // auto led_ = std::make_shared<led>("led",mvibot_seri_);
    // auto motor_ = std::make_shared<motor>("motor",mvibot_seri_);
    // auto battery_ = std::make_shared<battery>("battery",mvibot_seri_);
    // auto gpio_ = std::make_shared<gpio>("gpio",mvibot_seri_);
    // auto tool_function_ = std::make_shared<tool_function>("tool_function",mvibot_seri_);

    // executor.add_node(socket_client_);
    // executor.add_node(config_);
    // executor.add_node(odom_);
    // executor.add_node(Imu_);
    // executor.add_node(sensor_);
    // // executor.add_node(music_);
    // executor.add_node(led_);
    // executor.add_node(motor_);
    // executor.add_node(battery_);
    // executor.add_node(gpio_);
    // executor.add_node(tool_function_);
    //test with 4 node
    auto tool_node_ = std::make_shared<tool_node>("tool_node",mvibot_seri_);
    auto socket_client_node_ = std::make_shared<socket_client_node>("socket_client_node",mvibot_seri_);
    auto odometry_node_ = std::make_shared<odometry_node>("odometry_node",mvibot_seri_);
    auto control_node_ = std::make_shared<control_node>("control_node",mvibot_seri_);
    //
    executor.add_node(tool_node_);
    executor.add_node(socket_client_node_);
    executor.add_node(odometry_node_);
    executor.add_node(control_node_);
    //
    executor.spin();
    close(sock);
    //shutdown and exit
    rclcpp::shutdown();
    return 0;
}