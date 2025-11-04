// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from tf2_web_republisher_interfaces:msg/TFArray.idl
// generated code does not contain a copyright notice
#ifndef TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "tf2_web_republisher_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tf2_web_republisher_interfaces/msg/detail/tf_array__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
bool cdr_serialize_tf2_web_republisher_interfaces__msg__TFArray(
  const tf2_web_republisher_interfaces__msg__TFArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
bool cdr_deserialize_tf2_web_republisher_interfaces__msg__TFArray(
  eprosima::fastcdr::Cdr &,
  tf2_web_republisher_interfaces__msg__TFArray * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
size_t get_serialized_size_tf2_web_republisher_interfaces__msg__TFArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
size_t max_serialized_size_tf2_web_republisher_interfaces__msg__TFArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
bool cdr_serialize_key_tf2_web_republisher_interfaces__msg__TFArray(
  const tf2_web_republisher_interfaces__msg__TFArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
size_t get_serialized_size_key_tf2_web_republisher_interfaces__msg__TFArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
size_t max_serialized_size_key_tf2_web_republisher_interfaces__msg__TFArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tf2_web_republisher_interfaces, msg, TFArray)();

#ifdef __cplusplus
}
#endif

#endif  // TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
