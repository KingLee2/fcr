// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/path_components__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "opennav_coverage_msgs/msg/detail/path_components__struct.h"
#include "opennav_coverage_msgs/msg/detail/path_components__functions.h"
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

#include "nav_msgs/msg/detail/path__functions.h"  // turns
#include "opennav_coverage_msgs/msg/detail/swath__functions.h"  // swaths
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_serialize_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_deserialize_nav_msgs__msg__Path(
  eprosima::fastcdr::Cdr & cdr,
  nav_msgs__msg__Path * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t get_serialized_size_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t max_serialized_size_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_serialize_key_nav_msgs__msg__Path(
  const nav_msgs__msg__Path * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t get_serialized_size_key_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t max_serialized_size_key_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path)();

bool cdr_serialize_opennav_coverage_msgs__msg__Swath(
  const opennav_coverage_msgs__msg__Swath * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_opennav_coverage_msgs__msg__Swath(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs__msg__Swath * ros_message);

size_t get_serialized_size_opennav_coverage_msgs__msg__Swath(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_opennav_coverage_msgs__msg__Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_opennav_coverage_msgs__msg__Swath(
  const opennav_coverage_msgs__msg__Swath * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_opennav_coverage_msgs__msg__Swath(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_opennav_coverage_msgs__msg__Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, opennav_coverage_msgs, msg, Swath)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _PathComponents__ros_msg_type = opennav_coverage_msgs__msg__PathComponents;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_opennav_coverage_msgs__msg__PathComponents(
  const opennav_coverage_msgs__msg__PathComponents * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: swaths
  {
    size_t size = ros_message->swaths.size;
    auto array_ptr = ros_message->swaths.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_opennav_coverage_msgs__msg__Swath(
        &array_ptr[i], cdr);
    }
  }

  // Field name: turns
  {
    size_t size = ros_message->turns.size;
    auto array_ptr = ros_message->turns.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_nav_msgs__msg__Path(
        &array_ptr[i], cdr);
    }
  }

  // Field name: contains_turns
  {
    cdr << (ros_message->contains_turns ? true : false);
  }

  // Field name: swaths_ordered
  {
    cdr << (ros_message->swaths_ordered ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_deserialize_opennav_coverage_msgs__msg__PathComponents(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs__msg__PathComponents * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: swaths
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

    if (ros_message->swaths.data) {
      opennav_coverage_msgs__msg__Swath__Sequence__fini(&ros_message->swaths);
    }
    if (!opennav_coverage_msgs__msg__Swath__Sequence__init(&ros_message->swaths, size)) {
      fprintf(stderr, "failed to create array for field 'swaths'");
      return false;
    }
    auto array_ptr = ros_message->swaths.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_opennav_coverage_msgs__msg__Swath(cdr, &array_ptr[i]);
    }
  }

  // Field name: turns
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

    if (ros_message->turns.data) {
      nav_msgs__msg__Path__Sequence__fini(&ros_message->turns);
    }
    if (!nav_msgs__msg__Path__Sequence__init(&ros_message->turns, size)) {
      fprintf(stderr, "failed to create array for field 'turns'");
      return false;
    }
    auto array_ptr = ros_message->turns.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_nav_msgs__msg__Path(cdr, &array_ptr[i]);
    }
  }

  // Field name: contains_turns
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->contains_turns = tmp ? true : false;
  }

  // Field name: swaths_ordered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->swaths_ordered = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_opennav_coverage_msgs__msg__PathComponents(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PathComponents__ros_msg_type * ros_message = static_cast<const _PathComponents__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: swaths
  {
    size_t array_size = ros_message->swaths.size;
    auto array_ptr = ros_message->swaths.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_opennav_coverage_msgs__msg__Swath(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: turns
  {
    size_t array_size = ros_message->turns.size;
    auto array_ptr = ros_message->turns.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_nav_msgs__msg__Path(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: contains_turns
  {
    size_t item_size = sizeof(ros_message->contains_turns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: swaths_ordered
  {
    size_t item_size = sizeof(ros_message->swaths_ordered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_opennav_coverage_msgs__msg__PathComponents(
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

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: swaths
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
        max_serialized_size_opennav_coverage_msgs__msg__Swath(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: turns
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
        max_serialized_size_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: contains_turns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: swaths_ordered
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs__msg__PathComponents;
    is_plain =
      (
      offsetof(DataType, swaths_ordered) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
bool cdr_serialize_key_opennav_coverage_msgs__msg__PathComponents(
  const opennav_coverage_msgs__msg__PathComponents * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: swaths
  {
    size_t size = ros_message->swaths.size;
    auto array_ptr = ros_message->swaths.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_opennav_coverage_msgs__msg__Swath(
        &array_ptr[i], cdr);
    }
  }

  // Field name: turns
  {
    size_t size = ros_message->turns.size;
    auto array_ptr = ros_message->turns.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_nav_msgs__msg__Path(
        &array_ptr[i], cdr);
    }
  }

  // Field name: contains_turns
  {
    cdr << (ros_message->contains_turns ? true : false);
  }

  // Field name: swaths_ordered
  {
    cdr << (ros_message->swaths_ordered ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t get_serialized_size_key_opennav_coverage_msgs__msg__PathComponents(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PathComponents__ros_msg_type * ros_message = static_cast<const _PathComponents__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: swaths
  {
    size_t array_size = ros_message->swaths.size;
    auto array_ptr = ros_message->swaths.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_opennav_coverage_msgs__msg__Swath(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: turns
  {
    size_t array_size = ros_message->turns.size;
    auto array_ptr = ros_message->turns.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_nav_msgs__msg__Path(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: contains_turns
  {
    size_t item_size = sizeof(ros_message->contains_turns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: swaths_ordered
  {
    size_t item_size = sizeof(ros_message->swaths_ordered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_opennav_coverage_msgs
size_t max_serialized_size_key_opennav_coverage_msgs__msg__PathComponents(
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
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: swaths
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
        max_serialized_size_key_opennav_coverage_msgs__msg__Swath(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: turns
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
        max_serialized_size_key_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: contains_turns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: swaths_ordered
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs__msg__PathComponents;
    is_plain =
      (
      offsetof(DataType, swaths_ordered) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _PathComponents__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const opennav_coverage_msgs__msg__PathComponents * ros_message = static_cast<const opennav_coverage_msgs__msg__PathComponents *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_opennav_coverage_msgs__msg__PathComponents(ros_message, cdr);
}

static bool _PathComponents__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  opennav_coverage_msgs__msg__PathComponents * ros_message = static_cast<opennav_coverage_msgs__msg__PathComponents *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_opennav_coverage_msgs__msg__PathComponents(cdr, ros_message);
}

static uint32_t _PathComponents__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_opennav_coverage_msgs__msg__PathComponents(
      untyped_ros_message, 0));
}

static size_t _PathComponents__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_opennav_coverage_msgs__msg__PathComponents(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PathComponents = {
  "opennav_coverage_msgs::msg",
  "PathComponents",
  _PathComponents__cdr_serialize,
  _PathComponents__cdr_deserialize,
  _PathComponents__get_serialized_size,
  _PathComponents__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _PathComponents__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PathComponents,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__PathComponents__get_type_hash,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, opennav_coverage_msgs, msg, PathComponents)() {
  return &_PathComponents__type_support;
}

#if defined(__cplusplus)
}
#endif
