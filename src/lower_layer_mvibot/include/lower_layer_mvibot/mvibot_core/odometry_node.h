#include "mvibot_core_init.h"
using namespace std;
class odometry_node : public rclcpp::Node{
    public:
        auto createQuaternionMsgFromYaw(double yaw){
            tf2::Quaternion q;
            q.setRPY(0, 0, yaw);
            geometry_msgs::msg::Quaternion quat_msg; //= tf2::toMsg(q);
            // tf2::fromMsg(quat_msg, q);
 	        quat_msg = tf2::toMsg(q);
            return quat_msg;
        }
        void send_tranform_footprint_baselink(){
            geometry_msgs::msg::TransformStamped transformStamped;
            transformStamped.header.stamp = this->get_clock()->now();
            transformStamped.header.frame_id = mvibot_seri_f_ + "/base_footprint";
            transformStamped.child_frame_id = mvibot_seri_f_ + "/base_link";

            transformStamped.transform.translation.x = 0;
            transformStamped.transform.translation.y = 0;
            transformStamped.transform.translation.z = 0;

            transformStamped.transform.rotation.x = 0;
            transformStamped.transform.rotation.y = 0;
            transformStamped.transform.rotation.z = 0;
            transformStamped.transform.rotation.w = 1;
            tf_Broadcaster_->sendTransform(transformStamped);
        }
        void publish_joint_states()
        {
            joint_state.header.stamp = this->get_clock()->now();
            // Nếu có encoder thực, bạn cập nhật joint_state_.position[i] tại đây

            joint_pub_->publish(joint_state);
        }
        odometry_node(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){
            auto reentrant_cbg = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
            // auto mutuallyExclusive_cbg = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            //qos
            rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
            qos_profile.best_effort();
            //get namspace
            mvibot_seri_ = this->get_namespace();
            // cout<<mvibot_seri_<<endl;
            mvibot_seri_f_ = mvibot_seri_;
            mvibot_seri_f_.erase(0,1);
            // cout<<mvibot_seri_f_<<endl;
            //tranform
            tf_Broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
            //setup odom msg
            odom_wheel.header.frame_id = mvibot_seri_f_ + "/odom";
            odom_wheel.child_frame_id = mvibot_seri_f_ + "/base_footprint";
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
            //setup joint_state
            joint_state.name = {
            "base_joint",
            "base_wheel_left",
            "base_wheel_right",
            "base_lidar_1",
            "base_lidar_2",
            "camera1",
            "camera2"
            };
            // int Joint_state (all joint fix)
            joint_state.position.resize(joint_state.name.size(), 0.0);
            joint_state.velocity.resize(joint_state.name.size(), 0.0);
            joint_state.effort.resize(joint_state.name.size(), 0.0);
            //pub odom
            odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odom_wheel",1);
            //pub imu
            imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>("imu",1);
            //pub joint_state
            joint_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("/joint_states",1);
            //sub imu
            auto imu_callback = [this](sensor_msgs::msg::Imu::SharedPtr msg)->void{
                std::lock_guard<std::mutex> lock(mutex_odom);
                imu_msg_=*msg;
                // RCLCPP_INFO(this->get_logger(),"subscribed imu data");
            };
            imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(mvibot_seri_+"/camera2/imu", qos_profile, imu_callback);
            // imu_sub = this->create_subscription<sensor_msgs::msg::Imu>(mvibot_seri_+"/camera2/imu", qos_profile, imu_callback, sub_options);
            //timer odom
            auto timer_callback = [this]()->void{
                static float ts_local=0.05;
                static geometry_msgs::msg::Quaternion odom_wheel_quat, odom_wheel_laser_quat;
		        {
                    std::lock_guard<std::mutex> lock(mutex_tool);
                    local_mvibot_sensor_ready = mvibot_sensor_ready;
                }
                std::lock_guard<std::mutex> lock(mutex_odom);
                rclcpp::Time now = this->get_clock()->now();
                if (last_pub_time.nanoseconds() > 0) {
                    rclcpp::Duration dt = now - last_pub_time;
                    RCLCPP_INFO(this->get_logger(), "Odom/imu publish period: %.6f s", dt.seconds());
                }
                last_pub_time = now;

                if(local_mvibot_sensor_ready==0){
                    vr=0;
                    vl=0;
                    imu_msg_.angular_velocity.x=0.0;
                    imu_msg_.angular_velocity.y=0.0;
                    imu_msg_.angular_velocity.z=0.0;
                }
                //odom
                //time set
                odom_wheel.header.stamp = this->get_clock()->now();
                imu_msg_.header.stamp = this->get_clock()->now();
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
                imu_pub_->publish(imu_msg_);
                // RCLCPP_INFO(this->get_logger(),"published odometry data");
                //send tranform base_footprint to base_link
                send_tranform_footprint_baselink();
                // //pub joint_state
                // publish_joint_states();
            };
            odometry_timer_ = this->create_wall_timer(50ms, timer_callback);
            // timer_ = this->create_wall_timer(50ms, timer_callback, reentrant_cbg);
        }
    private:
        //timer
        rclcpp::TimerBase::SharedPtr odometry_timer_;
        //sub
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
        //pub
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
        //transform
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_Broadcaster_;
        //
        sensor_msgs::msg::Imu imu_msg_;
        nav_msgs::msg::Odometry odom_wheel;
        sensor_msgs::msg::JointState joint_state;
        float x_wheel=0,y_wheel=0,theta_wheel=0;
        float vx_wheel,vy_wheel,vth_wheel;
        string mvibot_seri_, mvibot_seri_f_;
        //var check time pub
        rclcpp::Time last_pub_time;
        int local_mvibot_sensor_ready;
};
