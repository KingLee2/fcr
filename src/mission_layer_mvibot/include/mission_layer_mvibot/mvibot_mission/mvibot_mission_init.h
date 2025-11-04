#include "../common/library_basic.h"
#include "../common/library_ros.h"
using namespace std;
#if !defined(mvibot_mission_init)
    class module {
        public:
            string name;
            std_msgs::msg::Float32MultiArray input_user;
            std_msgs::msg::Float32MultiArray input_user1;
            std_msgs::msg::Float32MultiArray input_user2;
            std_msgs::msg::Float32MultiArray output_user;
    };
    vector<module> my_module;
    std_msgs::msg::Float32MultiArray input_status, input_status_1, input_status_2;
    std_msgs::msg::Float32MultiArray output_status;
    //mutex
    std::recursive_mutex mutex_gpio;
    #define mvibot_mission_init 1
#endif