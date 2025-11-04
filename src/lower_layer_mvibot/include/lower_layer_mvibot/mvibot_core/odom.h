#include "mvibot_core_init.h"
using namespace std;
class odometry : public rclcpp::Node{
    public:
        auto createQuaternionMsgFromYaw(double yaw){
            tf2::Quaternion q;
            q.setRPY(0, 0, yaw);
            geometry_msgs::msg::Quaternion quat_msg; //= tf2::toMsg(q);
            // tf2::fromMsg(quat_msg, q);
 	        quat_msg = tf2::toMsg(q);
            return quat_msg;
        }
        odometry(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            // auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            //get namspace
            mvibot_seri_ = this->get_namespace();
            // cout<<mvibot_seri_<<endl;
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            // cout<<mvibot_seri_f_<<endl;
            //setup odom msg
            odom_wheel.header.frame_id = mvibot_seri_f_ + "/odom";
            odom_wheel.child_frame_id = mvibot_seri_f_ + "/base_footprint";
            // odom_wheel.header.frame_id = "mvibot/odom";
            // odom_wheel.child_frame_id =  "mvibot/base_footprint";
            odom_wheel.pose.pose.position.z = 0.0;
            for(size_t i=0;i<36;i++){
                if(i==0||i==7||i==35){
                    odom_wheel.pose.covariance[i]=0.01;
                    if(i==35)  odom_wheel.pose.covariance[i]=M_PI/60; 
                }
                if(i==0||i==35){
                    odom_wheel.twist.covariance[i]=0.02;
                }
            }
            odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odom_wheel",1);
            auto timer_callback = [this]()->void{
                static float ts_local=0.05;
                static geometry_msgs::msg::Quaternion odom_wheel_quat, odom_wheel_laser_quat;
		        {
                    std::lock_guard<std::mutex> lock(mutex_sensor);
                    local_mvibot_sensor_ready = mvibot_sensor_ready;
                }
                std::lock_guard<std::mutex> lock(mutex_odom);
                rclcpp::Time now = this->get_clock()->now();
                if (last_pub_time.nanoseconds() > 0) {
                    rclcpp::Duration dt = now - last_pub_time;
                    RCLCPP_INFO(this->get_logger(), "Odometry publish period: %.6f s", dt.seconds());
                }
                last_pub_time = now;

                if(local_mvibot_sensor_ready==0){
                    vr=0;
                    vl=0;
                }
                //time set
                odom_wheel.header.stamp = this->get_clock()->now();
                x_wheel=x_wheel+R/2*(vl+vr)*cos(theta_wheel)*ts_local;
                y_wheel=y_wheel+R/2*(vl+vr)*sin(theta_wheel)*ts_local;
                theta_wheel=theta_wheel+R/L*(vr-vl)*ts_local;
                vy_wheel=0;
                vx_wheel=R/2*(vr+vl);
                vth_wheel=R/L*(vr-vl);
                odom_wheel.pose.pose.position.x=x_wheel;
                odom_wheel.pose.pose.position.y=y_wheel;
                odom_wheel_quat= createQuaternionMsgFromYaw(theta_wheel);
                odom_wheel.pose.pose.orientation=odom_wheel_quat;
                odom_wheel.twist.twist.linear.x = vx_wheel;
                odom_wheel.twist.twist.linear.y = vy_wheel;
                odom_wheel.twist.twist.angular.z = vth_wheel;
                // distance robot have been move
                distance_robot+=fabs(vx_wheel)*(float)ts_local;
                distance_wheel_left+=fabs(vl*R)*(float)ts_local;
                distance_wheel_right+=fabs(vr*R)*(float)ts_local;
                odom_pub_->publish(odom_wheel);
                // RCLCPP_INFO(this->get_logger(),"published odometry data");
            };
            timer_ = this->create_wall_timer(50ms, timer_callback);
            // timer_ = this->create_wall_timer(50ms, timer_callback, reentrant_cbg);
        }
             
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
        nav_msgs::msg::Odometry odom_wheel;
        float x_wheel=0,y_wheel=0,theta_wheel=0;
        float vx_wheel,vy_wheel,vth_wheel;
        string mvibot_seri_, mvibot_seri_f_;
        //var check time pub
        rclcpp::Time last_pub_time;
        int local_mvibot_sensor_ready;
};
