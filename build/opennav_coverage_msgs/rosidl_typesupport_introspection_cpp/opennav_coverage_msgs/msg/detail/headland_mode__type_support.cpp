// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from opennav_coverage_msgs:msg/HeadlandMode.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "opennav_coverage_msgs/msg/detail/headland_mode__functions.h"
#include "opennav_coverage_msgs/msg/detail/headland_mode__struct.hpp"
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

void HeadlandMode_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) opennav_coverage_msgs::msg::HeadlandMode(_init);
}

void HeadlandMode_fini_function(void * message_memory)
{
  auto typed_message = static_cast<opennav_coverage_msgs::msg::HeadlandMode *>(message_memory);
  typed_message->~HeadlandMode();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HeadlandMode_message_member_array[2] = {
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::HeadlandMode, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "width",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::HeadlandMode, width),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HeadlandMode_message_members = {
  "opennav_coverage_msgs::msg",  // message namespace
  "HeadlandMode",  // message name
  2,  // number of fields
  sizeof(opennav_coverage_msgs::msg::HeadlandMode),
  false,  // has_any_key_member_
  HeadlandMode_message_member_array,  // message members
  HeadlandMode_init_function,  // function to initialize message memory (memory has to be allocated)
  HeadlandMode_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HeadlandMode_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HeadlandMode_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__HeadlandMode__get_type_hash,
  &opennav_coverage_msgs__msg__HeadlandMode__get_type_description,
  &opennav_coverage_msgs__msg__HeadlandMode__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<opennav_coverage_msgs::msg::HeadlandMode>()
{
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::HeadlandMode_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, opennav_coverage_msgs, msg, HeadlandMode)() {
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::HeadlandMode_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
