// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice

#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "opennav_coverage_msgs/msg/detail/swath__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace opennav_coverage_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_serialize(
  const opennav_coverage_msgs::msg::Swath & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs::msg::Swath & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size(
  const opennav_coverage_msgs::msg::Swath & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_serialize_key(
  const opennav_coverage_msgs::msg::Swath & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size_key(
  const opennav_coverage_msgs::msg::Swath & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_key_Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, opennav_coverage_msgs, msg, Swath)();

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
