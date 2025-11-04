// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from opennav_coverage_msgs:msg/Coordinates.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/coordinates__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "opennav_coverage_msgs/msg/detail/coordinates__struct.h"
#include "opennav_coverage_msgs/msg/detail/coordinates__functions.h"
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

#include "opennav_coverage_msgs/msg/detail/coordinate__functions.h"  // coordinates

// forward declare type support functions

bool cdr_serialize_opennav_coverage_msgs__msg__Coordinate(
  const opennav_coverage_msgs__msg__Coordinate * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_opennav_coverage_msgs__msg__Coordinate(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs__msg__Coordinate * ros_message);

size_t get_serialized_size_opennav_coverage_msgs__msg__Coordinate(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_opennav_coverage_msgs__msg__Coordinate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_opennav_coverage_msgs__msg__Coordinate(
  const opennav_coverage_msgs__msg__Coordinate * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_opennav_coverage_msgs__msg__Coordinate(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_opennav_coverage_msgs__msg__Coordinate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, opennav_coverage_msgs, msg, Coordinate)();


using _Coordinates__ros_msg_type = opennav_coverage_msgs__msg__Coordinates;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_opennav_coverage_msgs__msg__Coordinates(
  const opennav_coverage_msgs__msg__Coordinates * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: coordinates
  {
    size_t size = ros_message->coordinates.size;
    auto array_ptr = ros_message->coordinates.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_opennav_coverage_msgs__msg__Coordinate(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_deserialize_opennav_coverage_msgs__msg__Coordinates(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs__msg__Coordinates * ros_message)
{
  // Field name: coordinates
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->coordinates.data) {
      opennav_coverage_msgs__msg__Coordinate__Sequence__fini(&ros_message->coordinates);
    }
    if (!opennav_coverage_msgs__msg__Coordinate__Sequence__init(&ros_message->coordinates, size)) {
      fprintf(stderr, "failed to create array for field 'coordinates'");
      return false;
    }
    auto array_ptr = ros_message->coordinates.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_opennav_coverage_msgs__msg__Coordinate(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_opennav_coverage_msgs__msg__Coordinates(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Coordinates__ros_msg_type * ros_message = static_cast<const _Coordinates__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: coordinates
  {
    size_t array_size = ros_message->coordinates.size;
    auto array_ptr = ros_message->coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_opennav_coverage_msgs__msg__Coordinate(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_opennav_coverage_msgs__msg__Coordinates(
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

  // Field name: coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_opennav_coverage_msgs__msg__Coordinate(
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
    using DataType = opennav_coverage_msgs__msg__Coordinates;
    is_plain =
      (
      offsetof(DataType, coordinates) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_key_opennav_coverage_msgs__msg__Coordinates(
  const opennav_coverage_msgs__msg__Coordinates * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: coordinates
  {
    size_t size = ros_message->coordinates.size;
    auto array_ptr = ros_message->coordinates.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_opennav_coverage_msgs__msg__Coordinate(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_key_opennav_coverage_msgs__msg__Coordinates(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Coordinates__ros_msg_type * ros_message = static_cast<const _Coordinates__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: coordinates
  {
    size_t array_size = ros_message->coordinates.size;
    auto array_ptr = ros_message->coordinates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_opennav_coverage_msgs__msg__Coordinate(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_key_opennav_coverage_msgs__msg__Coordinates(
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
  // Field name: coordinates
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_opennav_coverage_msgs__msg__Coordinate(
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
    using DataType = opennav_coverage_msgs__msg__Coordinates;
    is_plain =
      (
      offsetof(DataType, coordinates) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Coordinates__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const opennav_coverage_msgs__msg__Coordinates * ros_message = static_cast<const opennav_coverage_msgs__msg__Coordinates *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_opennav_coverage_msgs__msg__Coordinates(ros_message, cdr);
}

static bool _Coordinates__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  opennav_coverage_msgs__msg__Coordinates * ros_message = static_cast<opennav_coverage_msgs__msg__Coordinates *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_opennav_coverage_msgs__msg__Coordinates(cdr, ros_message);
}

static uint32_t _Coordinates__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_opennav_coverage_msgs__msg__Coordinates(
      untyped_ros_message, 0));
}

static size_t _Coordinates__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_opennav_coverage_msgs__msg__Coordinates(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Coordinates = {
  "opennav_coverage_msgs::msg",
  "Coordinates",
  _Coordinates__cdr_serialize,
  _Coordinates__cdr_deserialize,
  _Coordinates__get_serialized_size,
  _Coordinates__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Coordinates__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Coordinates,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__Coordinates__get_type_hash,
  &opennav_coverage_msgs__msg__Coordinates__get_type_description,
  &opennav_coverage_msgs__msg__Coordinates__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, opennav_coverage_msgs, msg, Coordinates)() {
  return &_Coordinates__type_support;
}

#if defined(__cplusplus)
}
#endif
