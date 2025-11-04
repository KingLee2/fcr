// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/swath.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/swath__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_Swath_end
{
public:
  explicit Init_Swath_end(::opennav_coverage_msgs::msg::Swath & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::Swath end(::opennav_coverage_msgs::msg::Swath::_end_type arg)
  {
    msg_.end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::Swath msg_;
};

class Init_Swath_start
{
public:
  Init_Swath_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Swath_end start(::opennav_coverage_msgs::msg::Swath::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_Swath_end(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::Swath msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::Swath>()
{
  return opennav_coverage_msgs::msg::builder::Init_Swath_start();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__BUILDER_HPP_
