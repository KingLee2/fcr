#include "../include/mission_layer_mvibot/common/library_basic.h"
#include "../include/mission_layer_mvibot/common/library_ros.h"
#include "../include/mission_layer_mvibot/mvibot_mission/manage_mission.h"
#include "../include/mission_layer_mvibot/mvibot_mission/navigation_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/footprint_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/config_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/marker_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/variable_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/gpio_function.h"
#include "../include/mission_layer_mvibot/mvibot_mission/mission_define.h"

using namespace std;
// std::shared_ptr<navigation> navigation_;
// std::shared_ptr<footprint> footprint_;
// std::shared_ptr<config> config_;
// std::shared_ptr<marker> marker_;
// std::shared_ptr<manage_mission> manage_mission_;
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
    //run the executors
    // executor.add_node(footprint_);
    // executor.add_node(config_);
    executor.add_node(manage_mission_);
    executor.add_node(navigation_);
    executor.add_node(variable_);
    executor.add_node(gpio_);
    // sleep(2);
    // navigation_->process_data();
    executor.spin();
    //run thread

    //shutdown and exit
    rclcpp::shutdown();
    return 0;
}