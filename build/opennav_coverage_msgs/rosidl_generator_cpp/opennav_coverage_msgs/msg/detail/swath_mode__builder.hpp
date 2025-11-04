// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/SwathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/swath_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH_MODE__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/swath_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_SwathMode_step_angle
{
public:
  explicit Init_SwathMode_step_angle(::opennav_coverage_msgs::msg::SwathMode & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::SwathMode step_angle(::opennav_coverage_msgs::msg::SwathMode::_step_angle_type arg)
  {
    msg_.step_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::SwathMode msg_;
};

class Init_SwathMode_best_angle
{
public:
  explicit Init_SwathMode_best_angle(::opennav_coverage_msgs::msg::SwathMode & msg)
  : msg_(msg)
  {}
  Init_SwathMode_step_angle best_angle(::opennav_coverage_msgs::msg::SwathMode::_best_angle_type arg)
  {
    msg_.best_angle = std::move(arg);
    return Init_SwathMode_step_angle(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::SwathMode msg_;
};

class Init_SwathMode_mode
{
public:
  explicit Init_SwathMode_mode(::opennav_coverage_msgs::msg::SwathMode & msg)
  : msg_(msg)
  {}
  Init_SwathMode_best_angle mode(::opennav_coverage_msgs::msg::SwathMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_SwathMode_best_angle(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::SwathMode msg_;
};

class Init_SwathMode_objective
{
public:
  Init_SwathMode_objective()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SwathMode_mode objective(::opennav_coverage_msgs::msg::SwathMode::_objective_type arg)
  {
    msg_.objective = std::move(arg);
    return Init_SwathMode_mode(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::SwathMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::SwathMode>()
{
  return opennav_coverage_msgs::msg::builder::Init_SwathMode_objective();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH_MODE__BUILDER_HPP_
