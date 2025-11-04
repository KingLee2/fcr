// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice
#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "opennav_coverage_msgs/msg/detail/swath__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_opennav_coverage_msgs__msg__Swath(
  const opennav_coverage_msgs__msg__Swath * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_deserialize_opennav_coverage_msgs__msg__Swath(
  eprosima::fastcdr::Cdr &,
  opennav_coverage_msgs__msg__Swath * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_opennav_coverage_msgs__msg__Swath(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_opennav_coverage_msgs__msg__Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_key_opennav_coverage_msgs__msg__Swath(
  const opennav_coverage_msgs__msg__Swath * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_key_opennav_coverage_msgs__msg__Swath(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_key_opennav_coverage_msgs__msg__Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, opennav_coverage_msgs, msg, Swath)();

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
