// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from opennav_coverage_msgs:msg/HeadlandMode.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/headland_mode__rosidl_typesupport_fastrtps_cpp.hpp"
#include "opennav_coverage_msgs/msg/detail/headland_mode__functions.h"
#include "opennav_coverage_msgs/msg/detail/headland_mode__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace opennav_coverage_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_serialize(
  const opennav_coverage_msgs::msg::HeadlandMode & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mode
  cdr << ros_message.mode;

  // Member: width
  cdr << ros_message.width;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs::msg::HeadlandMode & ros_message)
{
  // Member: mode
  cdr >> ros_message.mode;

  // Member: width
  cdr >> ros_message.width;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size(
  const opennav_coverage_msgs::msg::HeadlandMode & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.mode.size() + 1);

  // Member: width
  {
    size_t item_size = sizeof(ros_message.width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_HeadlandMode(
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

  // Member: mode
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // Member: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs::msg::HeadlandMode;
    is_plain =
      (
      offsetof(DataType, width) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_serialize_key(
  const opennav_coverage_msgs::msg::HeadlandMode & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mode
  cdr << ros_message.mode;

  // Member: width
  cdr << ros_message.width;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size_key(
  const opennav_coverage_msgs::msg::HeadlandMode & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.mode.size() + 1);

  // Member: width
  {
    size_t item_size = sizeof(ros_message.width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_key_HeadlandMode(
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

  // Member: mode
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs::msg::HeadlandMode;
    is_plain =
      (
      offsetof(DataType, width) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _HeadlandMode__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const opennav_coverage_msgs::msg::HeadlandMode *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HeadlandMode__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<opennav_coverage_msgs::msg::HeadlandMode *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HeadlandMode__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const opennav_coverage_msgs::msg::HeadlandMode *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HeadlandMode__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HeadlandMode(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HeadlandMode__callbacks = {
  "opennav_coverage_msgs::msg",
  "HeadlandMode",
  _HeadlandMode__cdr_serialize,
  _HeadlandMode__cdr_deserialize,
  _HeadlandMode__get_serialized_size,
  _HeadlandMode__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _HeadlandMode__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HeadlandMode__callbacks,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__HeadlandMode__get_type_hash,
  &opennav_coverage_msgs__msg__HeadlandMode__get_type_description,
  &opennav_coverage_msgs__msg__HeadlandMode__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<opennav_coverage_msgs::msg::HeadlandMode>()
{
  return &opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::_HeadlandMode__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, opennav_coverage_msgs, msg, HeadlandMode)() {
  return &opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::_HeadlandMode__handle;
}

#ifdef __cplusplus
}
#endif
