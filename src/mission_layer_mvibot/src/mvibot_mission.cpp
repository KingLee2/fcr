#include "../include/mission_layer_mvibot/common/library_basic.h"
#include "../include/mission_layer_mvibot/common/library_ros.h"
#include "../include/mission_layer_mvibot/mvibot_mission/manage_mission.h"
#include "../include/mission_layer_mvibot/mvibot_mission/navigation_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/config_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/marker_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/variable_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/gpio_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/sleep_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/brush_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/suction_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/lift_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/mission_define.h"

using namespace std;
int main(int argc, char **argv){
    string mvibot_seri_;
    try
    {
	    std::ifstream file("/home/mvibot/floorCleaningRobot_ws/config/name_seri");
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
    //create thread

    //create thread class

    //Instantiate node
    auto manage_mission_ = std::make_shared<manage_mission>("manage_mission",mvibot_seri_); 
    auto navigation_ = std::make_shared<navigation_function>("navigation_function",mvibot_seri_);
    auto variable_ = std::make_shared<variable_function>("variable_function",mvibot_seri_);
    auto gpio_ = std::make_shared<gpio_function>("gpio_function",mvibot_seri_);
    auto sleep_ = std::make_shared<sleep_function>("sleep_function",mvibot_seri_);
    auto brush_ = std::make_shared<brush_function>("brush_function",mvibot_seri_);
    auto suction_ = std::make_shared<suction_function>("suction_function",mvibot_seri_);
    auto lift_ = std::make_shared<lift_function>("lift_function",mvibot_seri_);
    auto config_ = std::make_shared<config_function>("config_function",mvibot_seri_);
    auto marker_ = std::make_shared<marker_function>("marker_function",mvibot_seri_);
    
    //run the executors
    executor.add_node(manage_mission_);
    executor.add_node(navigation_);
    executor.add_node(variable_);
    executor.add_node(gpio_);
    executor.add_node(sleep_);
    executor.add_node(brush_);
    executor.add_node(suction_);
    executor.add_node(lift_);
    executor.add_node(config_);
    executor.add_node(marker_);
    executor.spin();

    //shutdown and exit
    rclcpp::shutdown();
    return 0;
}