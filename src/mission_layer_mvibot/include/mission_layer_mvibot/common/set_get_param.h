#include"library_ros.h"
#include "library_basic.h"
// #include"../ros_timenow/ros_timenow.h"
// #include"../stof/stof.h"
// #include"../stoi/stoi.h"
// #include <optional>

using namespace std;
#if !defined(set_get_param_define)
    
    template <typename T>
    class set_get_param : public rclcpp::Node{
        public:
            set_get_param(const string &node_name, const string &sub_namespace) : Node(node_name, sub_namespace){}
            bool set_param(const string &service_name, const string &param_name, const T &value){
                client_service_set_ = this->create_client<rcl_interfaces::srv::SetParameters>(service_name);
                
                auto request = std::make_shared<rcl_interfaces::srv::SetParameters::Request>();
                auto response = std::make_shared<rcl_interfaces::srv::SetParameters::Response>();
                if(!client_service_set_->wait_for_service(std::chrono::duration<float>(2))){
                    RCLCPP_ERROR(rclcpp::get_logger("SET PARAM"), "Service not available for %s", service_name.c_str());
                    return false;
                }
                rcl_interfaces::msg::Parameter parameters;
                parameters.name = param_name;
                //Xac dinh kieu du lieu
                if constexpr (std::is_same<T, int>::value) {
                    parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_INTEGER;
                    parameters.value.integer_value = value;
                } else if constexpr (std::is_same<T, double>::value) {
                    parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_DOUBLE;
                    parameters.value.double_value = value;
                } else if constexpr (std::is_same<T, bool>::value) {
                    parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_BOOL;
                    parameters.value.bool_value = value;
                } else if constexpr (std::is_same<T, std::string>::value) {
                    parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_STRING;
                    parameters.value.string_value = value;
                } else {
                    RCLCPP_ERROR(rclcpp::get_logger("SET PARAM"), "Unsupported type");
                    return false;
                }
                // if(param_type=="string"){
                //     parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_STRING;
                //     parameters.value.string_value = value;
                // }
                // else if(param_type == "bool"){
                //     parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_BOOL;
                //     parameters.value.bool_value = value;
                // }
                // else if(param_type == "int"){
                //     parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_INTEGER;
                //     parameters.value.integer_value = value;
                // }
                // else if(param_type == "double"){
                //     parameters.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_DOUBLE;
                //     parameters.value.double_value = value;
                // }
                request->parameters.push_back(parameters);
                //
                auto future = client_service_set_->async_send_request(request);
                if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS) {
                    RCLCPP_INFO(rclcpp::get_logger("SET PARAM"), "Set param %s success", param_name.c_str());
                    return true;
                }
                RCLCPP_ERROR(rclcpp::get_logger("SET PARAM"), "Set param failed");
                return false;      
            }
            bool get_param(const string &service_name,const string &param_name, T &output_value){
                client_service_get_ = this->create_client<rcl_interfaces::srv::GetParameters>(service_name);
                auto request=std::make_shared<rcl_interfaces::srv::GetParameters::Request>();
                auto response=std::make_shared<rcl_interfaces::srv::GetParameters::Response>();
                if(!client_service_get_->wait_for_service(std::chrono::duration<float>(2))){
                    RCLCPP_ERROR(rclcpp::get_logger("GET PARAM"), "Service not available for %s", service_name.c_str());
                    return false;
                }
                request->names.push_back(param_name);
                auto future = client_service_get_->async_send_request(request);
                if(rclcpp::spin_until_future_complete(this->get_node_base_interface(),future) == rclcpp::FutureReturnCode::SUCCESS){
                    response = future.get();
                    if(!response->values.empty()){
                        RCLCPP_INFO(rclcpp::get_logger("GET PARAM"), "Get %s Parameter is completed", param_name.c_str());
                        // if(param_type=="string") output_value = response->values[0].string_value;
                        // else if(param_type == "bool") output_value = response->values[0].bool_value;
                        // else if(param_type == "int") output_value = response->values[0].integer_value;
                        // else if(param_type == "double") output_value = response->values[0].double_value;
                        if constexpr (std::is_same<T, int>::value) output_value = response->values[0].integer_value;
                        else if constexpr (std::is_same<T, double>::value) output_value = response->values[0].double_value;
                        else if constexpr (std::is_same<T, bool>::value) output_value = response->values[0].bool_value;
                        else if constexpr (std::is_same<T, std::string>::value) output_value = response->values[0].string_value;
                        return true;
                    }
                    else{
                        RCLCPP_ERROR(rclcpp::get_logger("GET PARAM"),"No %s parameters found", param_name.c_str());
                        return false;
                    }
                }
                else{
                    RCLCPP_ERROR(rclcpp::get_logger("GET PARAM"), "Get param failed");
                    return false;
                }
            }

        private:
            rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedPtr client_service_set_;
            rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr client_service_get_;
    };
    
    #define set_get_param_define 1
#endif
