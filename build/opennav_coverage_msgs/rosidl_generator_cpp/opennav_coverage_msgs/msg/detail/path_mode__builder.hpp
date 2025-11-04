// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/PathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/path_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_PathMode_turn_point_distance
{
public:
  explicit Init_PathMode_turn_point_distance(::opennav_coverage_msgs::msg::PathMode & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::PathMode turn_point_distance(::opennav_coverage_msgs::msg::PathMode::_turn_point_distance_type arg)
  {
    msg_.turn_point_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathMode msg_;
};

class Init_PathMode_continuity_mode
{
public:
  explicit Init_PathMode_continuity_mode(::opennav_coverage_msgs::msg::PathMode & msg)
  : msg_(msg)
  {}
  Init_PathMode_turn_point_distance continuity_mode(::opennav_coverage_msgs::msg::PathMode::_continuity_mode_type arg)
  {
    msg_.continuity_mode = std::move(arg);
    return Init_PathMode_turn_point_distance(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathMode msg_;
};

class Init_PathMode_mode
{
public:
  Init_PathMode_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathMode_continuity_mode mode(::opennav_coverage_msgs::msg::PathMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_PathMode_continuity_mode(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::PathMode>()
{
  return opennav_coverage_msgs::msg::builder::Init_PathMode_mode();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__BUILDER_HPP_
