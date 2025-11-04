// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/Coordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/coordinate.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_Coordinate_axis2
{
public:
  explicit Init_Coordinate_axis2(::opennav_coverage_msgs::msg::Coordinate & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::Coordinate axis2(::opennav_coverage_msgs::msg::Coordinate::_axis2_type arg)
  {
    msg_.axis2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::Coordinate msg_;
};

class Init_Coordinate_axis1
{
public:
  Init_Coordinate_axis1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coordinate_axis2 axis1(::opennav_coverage_msgs::msg::Coordinate::_axis1_type arg)
  {
    msg_.axis1 = std::move(arg);
    return Init_Coordinate_axis2(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::Coordinate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::Coordinate>()
{
  return opennav_coverage_msgs::msg::builder::Init_Coordinate_axis1();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__BUILDER_HPP_
