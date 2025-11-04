// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from opennav_coverage_msgs:msg/PathMode.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "opennav_coverage_msgs/msg/detail/path_mode__functions.h"
#include "opennav_coverage_msgs/msg/detail/path_mode__struct.hpp"
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

void PathMode_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) opennav_coverage_msgs::msg::PathMode(_init);
}

void PathMode_fini_function(void * message_memory)
{
  auto typed_message = static_cast<opennav_coverage_msgs::msg::PathMode *>(message_memory);
  typed_message->~PathMode();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PathMode_message_member_array[3] = {
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathMode, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "continuity_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathMode, continuity_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "turn_point_distance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::PathMode, turn_point_distance),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PathMode_message_members = {
  "opennav_coverage_msgs::msg",  // message namespace
  "PathMode",  // message name
  3,  // number of fields
  sizeof(opennav_coverage_msgs::msg::PathMode),
  false,  // has_any_key_member_
  PathMode_message_member_array,  // message members
  PathMode_init_function,  // function to initialize message memory (memory has to be allocated)
  PathMode_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PathMode_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathMode_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__PathMode__get_type_hash,
  &opennav_coverage_msgs__msg__PathMode__get_type_description,
  &opennav_coverage_msgs__msg__PathMode__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<opennav_coverage_msgs::msg::PathMode>()
{
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::PathMode_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, opennav_coverage_msgs, msg, PathMode)() {
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::PathMode_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
