// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from opennav_coverage_msgs:msg/RouteMode.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/route_mode__rosidl_typesupport_fastrtps_cpp.hpp"
#include "opennav_coverage_msgs/msg/detail/route_mode__functions.h"
#include "opennav_coverage_msgs/msg/detail/route_mode__struct.hpp"

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
  const opennav_coverage_msgs::msg::RouteMode & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mode
  cdr << ros_message.mode;

  // Member: spiral_n
  cdr << ros_message.spiral_n;

  // Member: custom_order
  {
    cdr << ros_message.custom_order;
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs::msg::RouteMode & ros_message)
{
  // Member: mode
  cdr >> ros_message.mode;

  // Member: spiral_n
  cdr >> ros_message.spiral_n;

  // Member: custom_order
  {
    cdr >> ros_message.custom_order;
  }

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size(
  const opennav_coverage_msgs::msg::RouteMode & ros_message,
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

  // Member: spiral_n
  {
    size_t item_size = sizeof(ros_message.spiral_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: custom_order
  {
    size_t array_size = ros_message.custom_order.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.custom_order[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_RouteMode(
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
  // Member: spiral_n
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: custom_order
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs::msg::RouteMode;
    is_plain =
      (
      offsetof(DataType, custom_order) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_serialize_key(
  const opennav_coverage_msgs::msg::RouteMode & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mode
  cdr << ros_message.mode;

  // Member: spiral_n
  cdr << ros_message.spiral_n;

  // Member: custom_order
  {
    cdr << ros_message.custom_order;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size_key(
  const opennav_coverage_msgs::msg::RouteMode & ros_message,
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

  // Member: spiral_n
  {
    size_t item_size = sizeof(ros_message.spiral_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: custom_order
  {
    size_t array_size = ros_message.custom_order.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.custom_order[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_key_RouteMode(
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

  // Member: spiral_n
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: custom_order
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = opennav_coverage_msgs::msg::RouteMode;
    is_plain =
      (
      offsetof(DataType, custom_order) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _RouteMode__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const opennav_coverage_msgs::msg::RouteMode *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RouteMode__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<opennav_coverage_msgs::msg::RouteMode *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RouteMode__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const opennav_coverage_msgs::msg::RouteMode *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RouteMode__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RouteMode(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RouteMode__callbacks = {
  "opennav_coverage_msgs::msg",
  "RouteMode",
  _RouteMode__cdr_serialize,
  _RouteMode__cdr_deserialize,
  _RouteMode__get_serialized_size,
  _RouteMode__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _RouteMode__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RouteMode__callbacks,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__RouteMode__get_type_hash,
  &opennav_coverage_msgs__msg__RouteMode__get_type_description,
  &opennav_coverage_msgs__msg__RouteMode__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<opennav_coverage_msgs::msg::RouteMode>()
{
  return &opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::_RouteMode__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, opennav_coverage_msgs, msg, RouteMode)() {
  return &opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::_RouteMode__handle;
}

#ifdef __cplusplus
}
#endif
