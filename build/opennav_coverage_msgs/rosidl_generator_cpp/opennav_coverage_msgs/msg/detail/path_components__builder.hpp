// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_components.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/path_components__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_PathComponents_swaths_ordered
{
public:
  explicit Init_PathComponents_swaths_ordered(::opennav_coverage_msgs::msg::PathComponents & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::PathComponents swaths_ordered(::opennav_coverage_msgs::msg::PathComponents::_swaths_ordered_type arg)
  {
    msg_.swaths_ordered = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathComponents msg_;
};

class Init_PathComponents_contains_turns
{
public:
  explicit Init_PathComponents_contains_turns(::opennav_coverage_msgs::msg::PathComponents & msg)
  : msg_(msg)
  {}
  Init_PathComponents_swaths_ordered contains_turns(::opennav_coverage_msgs::msg::PathComponents::_contains_turns_type arg)
  {
    msg_.contains_turns = std::move(arg);
    return Init_PathComponents_swaths_ordered(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathComponents msg_;
};

class Init_PathComponents_turns
{
public:
  explicit Init_PathComponents_turns(::opennav_coverage_msgs::msg::PathComponents & msg)
  : msg_(msg)
  {}
  Init_PathComponents_contains_turns turns(::opennav_coverage_msgs::msg::PathComponents::_turns_type arg)
  {
    msg_.turns = std::move(arg);
    return Init_PathComponents_contains_turns(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathComponents msg_;
};

class Init_PathComponents_swaths
{
public:
  explicit Init_PathComponents_swaths(::opennav_coverage_msgs::msg::PathComponents & msg)
  : msg_(msg)
  {}
  Init_PathComponents_turns swaths(::opennav_coverage_msgs::msg::PathComponents::_swaths_type arg)
  {
    msg_.swaths = std::move(arg);
    return Init_PathComponents_turns(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathComponents msg_;
};

class Init_PathComponents_header
{
public:
  Init_PathComponents_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathComponents_swaths header(::opennav_coverage_msgs::msg::PathComponents::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PathComponents_swaths(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::PathComponents msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::PathComponents>()
{
  return opennav_coverage_msgs::msg::builder::Init_PathComponents_header();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__BUILDER_HPP_
