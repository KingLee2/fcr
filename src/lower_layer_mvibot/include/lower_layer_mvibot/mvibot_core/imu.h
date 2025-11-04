#include "mvibot_core_init.h"

using namespace std;
class imu : public rclcpp::Node{
    public:
        imu(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            rclcpp::SubscriptionOptions sub_options;
            sub_options.callback_group = reentrant_cbg;
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            mvibot_seri_ = this->get_namespace();
            auto imu_callback = [this](sensor_msgs::msg::Imu::SharedPtr msg)->void{
                // lock();
                std::lock_guard<std::mutex> lock(mutex_imu);
                imu_msg_=*msg;
                // RCLCPP_INFO(this->get_logger(),"subscribed imu data");
                // unlock();
            };
            imu_sub = this->create_subscription<sensor_msgs::msg::Imu>(mvibot_seri_+"/camera2/imu", qos_profile, imu_callback);
            // imu_sub = this->create_subscription<sensor_msgs::msg::Imu>(mvibot_seri_+"/camera2/imu", qos_profile, imu_callback, sub_options);
            imu_pub = this->create_publisher<sensor_msgs::msg::Imu>("imu",1);
            auto imu_timer_callback = [this]()->void{
                {
                    std::lock_guard<std::mutex> lock(mutex_sensor);
                    local_mvibot_sensor_ready = mvibot_sensor_ready;
                }
                std::lock_guard<std::mutex> lock(mutex_imu);
                rclcpp::Time now = this->get_clock()->now();
                if (check_time_imu.nanoseconds() > 0) {
                    rclcpp::Duration dt = now - check_time_imu;
                    RCLCPP_INFO(this->get_logger(), "pub imu with period: %.6f s", dt.seconds());
                }
                check_time_imu = now;
                if(local_mvibot_sensor_ready==0){
                    imu_msg_.angular_velocity.x=0.0;
                    imu_msg_.angular_velocity.y=0.0;
                    imu_msg_.angular_velocity.z=0.0;
                }
                imu_msg_.header.stamp = this->get_clock()->now();
                imu_pub->publish(imu_msg_);
                // RCLCPP_INFO(this->get_logger(),"published imu data with 20hz");
            };
            timer_ = this->create_wall_timer(50ms, imu_timer_callback);
            // timer_ = this->create_wall_timer(50ms, imu_timer_callback, reentrant_cbg);
        }
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;
        sensor_msgs::msg::Imu imu_msg_;
        string mvibot_seri_;
        std::mutex mutex_imu;
        int local_mvibot_sensor_ready;
        //var check time pub imu
        rclcpp::Time check_time_imu;
};