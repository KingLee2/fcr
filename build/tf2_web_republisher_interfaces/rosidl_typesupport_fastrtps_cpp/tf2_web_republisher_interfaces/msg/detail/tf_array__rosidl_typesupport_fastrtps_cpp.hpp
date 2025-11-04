// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from tf2_web_republisher_interfaces:msg/TFArray.idl
// generated code does not contain a copyright notice

#ifndef TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "tf2_web_republisher_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "tf2_web_republisher_interfaces/msg/detail/tf_array__struct.hpp"

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

namespace tf2_web_republisher_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
cdr_serialize(
  const tf2_web_republisher_interfaces::msg::TFArray & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tf2_web_republisher_interfaces::msg::TFArray & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
get_serialized_size(
  const tf2_web_republisher_interfaces::msg::TFArray & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
max_serialized_size_TFArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
cdr_serialize_key(
  const tf2_web_republisher_interfaces::msg::TFArray & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
get_serialized_size_key(
  const tf2_web_republisher_interfaces::msg::TFArray & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
max_serialized_size_key_TFArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tf2_web_republisher_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tf2_web_republisher_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tf2_web_republisher_interfaces, msg, TFArray)();

#ifdef __cplusplus
}
#endif

#endif  // TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
