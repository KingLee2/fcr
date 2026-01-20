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