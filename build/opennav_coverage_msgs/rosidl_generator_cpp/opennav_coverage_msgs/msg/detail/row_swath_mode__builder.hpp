// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:msg/RowSwathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/row_swath_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/msg/detail/row_swath_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace msg
{

namespace builder
{

class Init_RowSwathMode_offset
{
public:
  explicit Init_RowSwathMode_offset(::opennav_coverage_msgs::msg::RowSwathMode & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::msg::RowSwathMode offset(::opennav_coverage_msgs::msg::RowSwathMode::_offset_type arg)
  {
    msg_.offset = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::RowSwathMode msg_;
};

class Init_RowSwathMode_skip_ids
{
public:
  explicit Init_RowSwathMode_skip_ids(::opennav_coverage_msgs::msg::RowSwathMode & msg)
  : msg_(msg)
  {}
  Init_RowSwathMode_offset skip_ids(::opennav_coverage_msgs::msg::RowSwathMode::_skip_ids_type arg)
  {
    msg_.skip_ids = std::move(arg);
    return Init_RowSwathMode_offset(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::RowSwathMode msg_;
};

class Init_RowSwathMode_mode
{
public:
  Init_RowSwathMode_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RowSwathMode_skip_ids mode(::opennav_coverage_msgs::msg::RowSwathMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_RowSwathMode_skip_ids(msg_);
  }

private:
  ::opennav_coverage_msgs::msg::RowSwathMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::msg::RowSwathMode>()
{
  return opennav_coverage_msgs::msg::builder::Init_RowSwathMode_mode();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__BUILDER_HPP_
