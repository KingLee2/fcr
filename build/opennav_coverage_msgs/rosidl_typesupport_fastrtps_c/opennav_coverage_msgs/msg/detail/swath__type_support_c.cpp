// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/swath__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "opennav_coverage_msgs/msg/detail/swath__struct.h"
#include "opennav_coverage_msgs/msg/detail/swath__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point32__functions.h"  // end, start

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_serialize_geometry_msgs__msg__Point32(
  const geometry_msgs__msg__Point32 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_deserialize_geometry_msgs__msg__Point32(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Point32 * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t get_serialized_size_geometry_msgs__msg__Point32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t max_serialized_size_geometry_msgs__msg__Point32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_serialize_key_geometry_msgs__msg__Point32(
  const geometry_msgs__msg__Point32 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Point32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Point32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32)();


using _Swath__ros_msg_type = opennav_coverage_msgs__msg__Swath;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_opennav_coverage_msgs__msg__Swath(
  const opennav_coverage_msgs__msg__Swath * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: start
  {
    cdr_serialize_geometry_msgs__msg__Point32(
      &ros_message->start, cdr);
  }

  // Field name: end
  {
    cdr_serialize_geometry_msgs__msg__Point32(
      &ros_message->end, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_deserialize_opennav_coverage_msgs__msg__Swath(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs__msg__Swath * ros_message)
{
  // Field name: start
  {
    cdr_deserialize_geometry_msgs__msg__Point32(cdr, &ros_message->start);
  }

  // Field name: end
  {
    cdr_deserialize_geometry_msgs__msg__Point32(cdr, &ros_message->end);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_opennav_coverage_msgs__msg__Swath(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Swath__ros_msg_type * ros_message = static_cast<const _Swath__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: start
  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->start), current_alignment);

  // Field name: end
  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->end), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_opennav_coverage_msgs__msg__Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: start
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: end
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs__msg__Swath;
    is_plain =
      (
      offsetof(DataType, end) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_key_opennav_coverage_msgs__msg__Swath(
  const opennav_coverage_msgs__msg__Swath * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: start
  {
    cdr_serialize_key_geometry_msgs__msg__Point32(
      &ros_message->start, cdr);
  }

  // Field name: end
  {
    cdr_serialize_key_geometry_msgs__msg__Point32(
      &ros_message->end, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_key_opennav_coverage_msgs__msg__Swath(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Swath__ros_msg_type * ros_message = static_cast<const _Swath__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: start
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point32(
    &(ros_message->start), current_alignment);

  // Field name: end
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point32(
    &(ros_message->end), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_key_opennav_coverage_msgs__msg__Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: start
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: end
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs__msg__Swath;
    is_plain =
      (
      offsetof(DataType, end) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Swath__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const opennav_coverage_msgs__msg__Swath * ros_message = static_cast<const opennav_coverage_msgs__msg__Swath *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_opennav_coverage_msgs__msg__Swath(ros_message, cdr);
}

static bool _Swath__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  opennav_coverage_msgs__msg__Swath * ros_message = static_cast<opennav_coverage_msgs__msg__Swath *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_opennav_coverage_msgs__msg__Swath(cdr, ros_message);
}

static uint32_t _Swath__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_opennav_coverage_msgs__msg__Swath(
      untyped_ros_message, 0));
}

static size_t _Swath__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_opennav_coverage_msgs__msg__Swath(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Swath = {
  "opennav_coverage_msgs::msg",
  "Swath",
  _Swath__cdr_serialize,
  _Swath__cdr_deserialize,
  _Swath__get_serialized_size,
  _Swath__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Swath__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Swath,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__Swath__get_type_hash,
  &opennav_coverage_msgs__msg__Swath__get_type_description,
  &opennav_coverage_msgs__msg__Swath__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, opennav_coverage_msgs, msg, Swath)() {
  return &_Swath__type_support;
}

#if defined(__cplusplus)
}
#endif
