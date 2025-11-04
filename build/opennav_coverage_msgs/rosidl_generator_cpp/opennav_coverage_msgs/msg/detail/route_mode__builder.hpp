// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/RouteMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/route_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/route_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_RouteMode_custom_order
{
public:
  explicit Init_RouteMode_custom_order(::opennav_coverage_msgs::msg::RouteMode & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::RouteMode custom_order(::opennav_coverage_msgs::msg::RouteMode::_custom_order_type arg)
  {
    msg_.custom_order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::RouteMode msg_;
};

class Init_RouteMode_spiral_n
{
public:
  explicit Init_RouteMode_spiral_n(::opennav_coverage_msgs::msg::RouteMode & msg)
  : msg_(msg)
  {}
  Init_RouteMode_custom_order spiral_n(::opennav_coverage_msgs::msg::RouteMode::_spiral_n_type arg)
  {
    msg_.spiral_n = std::move(arg);
    return Init_RouteMode_custom_order(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::RouteMode msg_;
};

class Init_RouteMode_mode
{
public:
  Init_RouteMode_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RouteMode_spiral_n mode(::opennav_coverage_msgs::msg::RouteMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_RouteMode_spiral_n(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::RouteMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::RouteMode>()
{
  return opennav_coverage_msgs::msg::builder::Init_RouteMode_mode();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__BUILDER_HPP_
