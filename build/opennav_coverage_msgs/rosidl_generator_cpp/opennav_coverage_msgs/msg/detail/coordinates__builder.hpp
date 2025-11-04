// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/Coordinates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/coordinates.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/coordinates__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_Coordinates_coordinates
{
public:
  Init_Coordinates_coordinates()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::opennav_coverage_msgs::msg::Coordinates coordinates(::opennav_coverage_msgs::msg::Coordinates::_coordinates_type arg)
  {
    msg_.coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::Coordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::Coordinates>()
{
  return opennav_coverage_msgs::msg::builder::Init_Coordinates_coordinates();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__BUILDER_HPP_
