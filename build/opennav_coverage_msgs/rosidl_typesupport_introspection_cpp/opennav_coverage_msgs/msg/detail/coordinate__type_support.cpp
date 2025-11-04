// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from opennav_coverage_msgs:msg/Coordinate.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "opennav_coverage_msgs/msg/detail/coordinate__functions.h"
#include "opennav_coverage_msgs/msg/detail/coordinate__struct.hpp"
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

void Coordinate_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) opennav_coverage_msgs::msg::Coordinate(_init);
}

void Coordinate_fini_function(void * message_memory)
{
  auto typed_message = static_cast<opennav_coverage_msgs::msg::Coordinate *>(message_memory);
  typed_message->~Coordinate();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Coordinate_message_member_array[2] = {
  {
    "axis1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::Coordinate, axis1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "axis2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs::msg::Coordinate, axis2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Coordinate_message_members = {
  "opennav_coverage_msgs::msg",  // message namespace
  "Coordinate",  // message name
  2,  // number of fields
  sizeof(opennav_coverage_msgs::msg::Coordinate),
  false,  // has_any_key_member_
  Coordinate_message_member_array,  // message members
  Coordinate_init_function,  // function to initialize message memory (memory has to be allocated)
  Coordinate_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Coordinate_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Coordinate_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__Coordinate__get_type_hash,
  &opennav_coverage_msgs__msg__Coordinate__get_type_description,
  &opennav_coverage_msgs__msg__Coordinate__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace opennav_coverage_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<opennav_coverage_msgs::msg::Coordinate>()
{
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::Coordinate_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, opennav_coverage_msgs, msg, Coordinate)() {
  return &::opennav_coverage_msgs::msg::rosidl_typesupport_introspection_cpp::Coordinate_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
