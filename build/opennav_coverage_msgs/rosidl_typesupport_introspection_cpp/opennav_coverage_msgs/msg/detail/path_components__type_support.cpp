// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "opennav_coverage_msgs/msg/detail/path_components__functions.h"
#include "opennav_coverage_msgs/msg/detail/path_components__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace opennav_coverage_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PathComponents_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) opennav_coverage_msgs::msg::PathComponents(_init);
}

void PathComponents_fini_function(void * message_memory)
{
  auto typed_message = static_cast<opennav_coverage_msgs::msg::PathComponents *>(message_memory);
  typed_message->~PathComponents();
}

size_t size_function__PathComponents__swaths(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<opennav_coverage_msgs::msg::Swath> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathComponents__swaths(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<opennav_coverage_msgs::msg::Swath> *>(untyped_member);
  return &member[index];
}

void * get_function__PathComponents__swaths(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<opennav_coverage_msgs::msg::Swath> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathComponents__swaths(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const opennav_coverage_msgs::msg::Swath *>(
    get_const_function__PathComponents__swaths(untyped_member, index));
  auto & value = *reinterpret_cast<opennav_coverage_msgs::msg::Swath *>(untyped_value);
  value = item;
}

void assign_function__PathComponents__swaths(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<opennav_coverage_msgs::msg::Swath *>(
    get_function__PathComponents__swaths(untyped_member, index));
  const auto & value = *reinterpret_cast<const opennav_coverage_msgs::msg::Swath *>(untyped_value);
  item = value;
}

void resize_function__PathComponents__swaths(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<opennav_coverage_msgs::msg::Swath> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PathComponents__turns(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<nav_msgs::msg::Path> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathComponents__turns(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<nav_msgs::msg::Path> *>(untyped_member);
  return &member[index];
}

void * get_function__PathComponents__turns(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<nav_msgs::msg::Path> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathComponents__turns(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nav_msgs::msg::Path *>(
    get_const_function__PathComponents__turns(untyped_member, index));
  auto & value = *reinterpret_cast<nav_msgs::msg::Path *>(untyped_value);
  value = item;
}

void assign_function__PathComponents__turns(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nav_msgs::msg::Path *>(
    get_function__PathComponents__turns(untyped_member, index));
  const auto & value = *reinterpret_cast<const nav_msgs::msg::Path *>(untyped_value);
  item = value;
}

void resize_function__PathComponents__turns(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<nav_msgs::msg::Path> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PathComponents_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathComponents, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "swaths",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<opennav_coverage_msgs::msg::Swath>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathComponents, swaths),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathComponents__swaths,  // size() function pointer
    get_const_function__PathComponents__swaths,  // get_const(index) function pointer
    get_function__PathComponents__swaths,  // get(index) function pointer
    fetch_function__PathComponents__swaths,  // fetch(index, &value) function pointer
    assign_function__PathComponents__swaths,  // assign(index, value) function pointer
    resize_function__PathComponents__swaths  // resize(index) function pointer
  },
  {
    "turns",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_msgs::msg::Path>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathComponents, turns),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathComponents__turns,  // size() function pointer
    get_const_function__PathComponents__turns,  // get_const(index) function pointer
    get_function__PathComponents__turns,  // get(index) function pointer
    fetch_function__PathComponents__turns,  // fetch(index, &value) function pointer
    assign_function__PathComponents__turns,  // assign(index, value) function pointer
    resize_function__PathComponents__turns  // resize(index) function pointer
  },
  {
    "contains_turns",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathComponents, contains_turns),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "swaths_ordered",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathComponents, swaths_ordered),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PathComponents_message_members = {
  "opennav_coverage_msgs::msg",  // message namespace
  "PathComponents",  // message name
  5,  // number of fields
  sizeof(opennav_coverage_msgs::msg::PathComponents),
  false,  // has_any_key_member_
  PathComponents_message_member_array,  // message members
  PathComponents_init_function,  // function to initialize message memory (memory has to be allocated)
  PathComponents_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PathComponents_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathComponents_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__PathComponents__get_type_hash,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<opennav_coverage_msgs::msg::PathComponents>()
{
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::PathComponents_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, opennav_coverage_msgs, msg, PathComponents)() {
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::PathComponents_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
