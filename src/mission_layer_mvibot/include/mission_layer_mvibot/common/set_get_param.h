#include"library_ros.h"
#include "library_basic.h"
// #include"../ros_timenow/ros_timenow.h"
// #include"../stof/stof.h"
// #include"../stoi/stoi.h"
// #include <optional>

using namespace std;
#if !defined(set_get_param_define)
    //set param
    template<typename T>
    void set_param(
        const rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedPtr &client,
        const std::string &name,
        const T &value,
        std::function<void(bool)> callback)
    {
        auto request = std::make_shared<rcl_interfaces::srv::SetParameters::Request>();
        rclcpp::Parameter param(name, value);
        request->parameters.push_back(param.to_parameter_msg());

        if (!client->wait_for_service(std::chrono::seconds(2))) {
            callback(false);
            return;
        }

        client->async_send_request(
            request,
            [callback](rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedFuture result) {
                bool success = result.get()->results[0].successful;
                callback(success);
            }
        );
    }
    //get param
    template<typename T>
    void get_param(
        const rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr &client,
        const std::string &name,
        std::function<void(std::optional<T>)> callback)
    {
        auto request = std::make_shared<rcl_interfaces::srv::GetParameters::Request>();
        request->names.push_back(name);

        if (!client->wait_for_service(std::chrono::seconds(2))) {
            callback(std::nullopt);
            return;
        }

        client->async_send_request(
            request,
            [callback](rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedFuture future) {
                auto values = future.get()->values;
                if (values.empty()) {
                    callback(std::nullopt);
                    return;
                }
                const auto & v = values[0];

                if constexpr (std::is_same_v<T, int>) {
                    callback(v.integer_value);
                } else if constexpr (std::is_same_v<T, double>) {
                    callback(v.double_value);
                } else if constexpr (std::is_same_v<T, bool>) {
                    callback(v.bool_value);
                } else if constexpr (std::is_same_v<T, std::string>) {
                    callback(v.string_value);
                } else {
                    static_assert(!sizeof(T*), "Unsupported parameter type");
                }
            }
        );
    }
    //set and get
    template<typename T>
    void check_param(
        const rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedPtr &set_client,
        const rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr &get_client,
        const std::string &name,
        const T &value,
        std::function<void(bool)> callback)
    {
        set_param<T>(set_client, name, value, 
            [=](bool success){
                if (!success) {
                    callback(false);
                    return;
                }
                // read again
                get_param<T>(get_client, name,
                    [=](std::optional<T> v){
                        if (v.has_value() && v.value() == value) {
                            callback(true);
                        } else {
                            callback(false);
                        }
                    }
                );
            }
        );
    }
    #define set_get_param_define 1
#endif
