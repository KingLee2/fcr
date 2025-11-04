// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/HeadlandMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/headland_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__HEADLAND_MODE__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__HEADLAND_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/headland_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_HeadlandMode_width
{
public:
  explicit Init_HeadlandMode_width(::opennav_coverage_msgs::msg::HeadlandMode & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::HeadlandMode width(::opennav_coverage_msgs::msg::HeadlandMode::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::HeadlandMode msg_;
};

class Init_HeadlandMode_mode
{
public:
  Init_HeadlandMode_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HeadlandMode_width mode(::opennav_coverage_msgs::msg::HeadlandMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_HeadlandMode_width(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::HeadlandMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::HeadlandMode>()
{
  return opennav_coverage_msgs::msg::builder::Init_HeadlandMode_mode();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__HEADLAND_MODE__BUILDER_HPP_
