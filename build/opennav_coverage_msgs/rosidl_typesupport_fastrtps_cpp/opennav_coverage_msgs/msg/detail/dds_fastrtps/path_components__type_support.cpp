// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/path_components__rosidl_typesupport_fastrtps_cpp.hpp"
#include "opennav_coverage_msgs/msg/detail/path_components__functions.h"
#include "opennav_coverage_msgs/msg/detail/path_components__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_key_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace opennav_coverage_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const opennav_coverage_msgs::msg::Swath &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  opennav_coverage_msgs::msg::Swath &);
size_t get_serialized_size(
  const opennav_coverage_msgs::msg::Swath &,
  size_t current_alignment);
size_t
max_serialized_size_Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const opennav_coverage_msgs::msg::Swath &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const opennav_coverage_msgs::msg::Swath &,
  size_t current_alignment);
size_t
max_serialized_size_key_Swath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace opennav_coverage_msgs

namespace nav_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const nav_msgs::msg::Path &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  nav_msgs::msg::Path &);
size_t get_serialized_size(
  const nav_msgs::msg::Path &,
  size_t current_alignment);
size_t
max_serialized_size_Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const nav_msgs::msg::Path &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const nav_msgs::msg::Path &,
  size_t current_alignment);
size_t
max_serialized_size_key_Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace nav_msgs


namespace opennav_coverage_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_serialize(
  const opennav_coverage_msgs::msg::PathComponents & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);

  // Member: swaths
  {
    size_t size = ros_message.swaths.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.swaths[i],
        cdr);
    }
  }

  // Member: turns
  {
    size_t size = ros_message.turns.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      nav_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.turns[i],
        cdr);
    }
  }

  // Member: contains_turns
  cdr << (ros_message.contains_turns ? true : false);

  // Member: swaths_ordered
  cdr << (ros_message.swaths_ordered ? true : false);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  opennav_coverage_msgs::msg::PathComponents & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: swaths
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

    ros_message.swaths.resize(size);
    for (size_t i = 0; i < size; i++) {
      opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.swaths[i]);
    }
  }

  // Member: turns
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

    ros_message.turns.resize(size);
    for (size_t i = 0; i < size; i++) {
      nav_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.turns[i]);
    }
  }

  // Member: contains_turns
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.contains_turns = tmp ? true : false;
  }

  // Member: swaths_ordered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.swaths_ordered = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size(
  const opennav_coverage_msgs::msg::PathComponents & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);

  // Member: swaths
  {
    size_t array_size = ros_message.swaths.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.swaths[index], current_alignment);
    }
  }

  // Member: turns
  {
    size_t array_size = ros_message.turns.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        nav_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.turns[index], current_alignment);
    }
  }

  // Member: contains_turns
  {
    size_t item_size = sizeof(ros_message.contains_turns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: swaths_ordered
  {
    size_t item_size = sizeof(ros_message.swaths_ordered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_PathComponents(
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

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: swaths
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
      size_t inner_size =
        opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Swath(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: turns
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
      size_t inner_size =
        nav_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: contains_turns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: swaths_ordered
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
    using DataType = opennav_coverage_msgs::msg::PathComponents;
    is_plain =
      (
      offsetof(DataType, swaths_ordered) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
cdr_serialize_key(
  const opennav_coverage_msgs::msg::PathComponents & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.header,
    cdr);

  // Member: swaths
  {
    size_t size = ros_message.swaths.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.swaths[i],
        cdr);
    }
  }

  // Member: turns
  {
    size_t size = ros_message.turns.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      nav_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.turns[i],
        cdr);
    }
  }

  // Member: contains_turns
  cdr << (ros_message.contains_turns ? true : false);

  // Member: swaths_ordered
  cdr << (ros_message.swaths_ordered ? true : false);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
get_serialized_size_key(
  const opennav_coverage_msgs::msg::PathComponents & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.header, current_alignment);

  // Member: swaths
  {
    size_t array_size = ros_message.swaths.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.swaths[index], current_alignment);
    }
  }

  // Member: turns
  {
    size_t array_size = ros_message.turns.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        nav_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.turns[index], current_alignment);
    }
  }

  // Member: contains_turns
  {
    size_t item_size = sizeof(ros_message.contains_turns);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: swaths_ordered
  {
    size_t item_size = sizeof(ros_message.swaths_ordered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_opennav_coverage_msgs
max_serialized_size_key_PathComponents(
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

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: swaths
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
      size_t inner_size =
        opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Swath(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: turns
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
      size_t inner_size =
        nav_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: contains_turns
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: swaths_ordered
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
    using DataType = opennav_coverage_msgs::msg::PathComponents;
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
  auto typed_message =
    static_cast<const opennav_coverage_msgs::msg::PathComponents *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PathComponents__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<opennav_coverage_msgs::msg::PathComponents *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PathComponents__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const opennav_coverage_msgs::msg::PathComponents *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PathComponents__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PathComponents(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PathComponents__callbacks = {
  "opennav_coverage_msgs::msg",
  "PathComponents",
  _PathComponents__cdr_serialize,
  _PathComponents__cdr_deserialize,
  _PathComponents__get_serialized_size,
  _PathComponents__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _PathComponents__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PathComponents__callbacks,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__PathComponents__get_type_hash,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<opennav_coverage_msgs::msg::PathComponents>()
{
  return &opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::_PathComponents__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, opennav_coverage_msgs, msg, PathComponents)() {
  return &opennav_coverage_msgs::msg::typesupport_fastrtps_cpp::_PathComponents__handle;
}

#ifdef __cplusplus
}
#endif
