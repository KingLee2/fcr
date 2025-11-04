#include "../include/higher_layer_mvibot/common/library_basic.h"
#include "../include/higher_layer_mvibot/common/library_ros.h"
#include "../include/higher_layer_mvibot/common/string_Iv2.h"
#include "../include/higher_layer_mvibot/mvibot_server/mvibot_server_init.h"
#include "../include/higher_layer_mvibot/mvibot_server/robot_information.h"
#include "../include/higher_layer_mvibot/mvibot_server/fcr_server.h"
#include "../include/higher_layer_mvibot/mvibot_server/mvibot_mysql.h"

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
    rclcpp::executors::MultiThreadedExecutor executor;

    //Instantiate node
    auto fcr_database_ = std::make_shared<fcr_database>("fcr_database", mvibot_seri_);
    auto fcr_server_ = std::make_shared<fcr_server>("fcr_server", mvibot_seri_);
    //run the executors
    executor.add_node(fcr_database_);
    executor.add_node(fcr_server_);
    executor.spin();
    //shutdown and exit
    rclcpp::shutdown();
    return 0;
}