// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "opennav_coverage_msgs/msg/detail/path_components__rosidl_typesupport_introspection_c.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "opennav_coverage_msgs/msg/detail/path_components__functions.h"
#include "opennav_coverage_msgs/msg/detail/path_components__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `swaths`
#include "opennav_coverage_msgs/msg/swath.h"
// Member `swaths`
#include "opennav_coverage_msgs/msg/detail/swath__rosidl_typesupport_introspection_c.h"
// Member `turns`
#include "nav_msgs/msg/path.h"
// Member `turns`
#include "nav_msgs/msg/detail/path__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__msg__PathComponents__init(message_memory);
}

void opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_fini_function(void * message_memory)
{
  opennav_coverage_msgs__msg__PathComponents__fini(message_memory);
}

size_t opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__size_function__PathComponents__swaths(
  const void * untyped_member)
{
  const opennav_coverage_msgs__msg__Swath__Sequence * member =
    (const opennav_coverage_msgs__msg__Swath__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_const_function__PathComponents__swaths(
  const void * untyped_member, size_t index)
{
  const opennav_coverage_msgs__msg__Swath__Sequence * member =
    (const opennav_coverage_msgs__msg__Swath__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_function__PathComponents__swaths(
  void * untyped_member, size_t index)
{
  opennav_coverage_msgs__msg__Swath__Sequence * member =
    (opennav_coverage_msgs__msg__Swath__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__fetch_function__PathComponents__swaths(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const opennav_coverage_msgs__msg__Swath * item =
    ((const opennav_coverage_msgs__msg__Swath *)
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_const_function__PathComponents__swaths(untyped_member, index));
  opennav_coverage_msgs__msg__Swath * value =
    (opennav_coverage_msgs__msg__Swath *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__assign_function__PathComponents__swaths(
  void * untyped_member, size_t index, const void * untyped_value)
{
  opennav_coverage_msgs__msg__Swath * item =
    ((opennav_coverage_msgs__msg__Swath *)
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_function__PathComponents__swaths(untyped_member, index));
  const opennav_coverage_msgs__msg__Swath * value =
    (const opennav_coverage_msgs__msg__Swath *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__resize_function__PathComponents__swaths(
  void * untyped_member, size_t size)
{
  opennav_coverage_msgs__msg__Swath__Sequence * member =
    (opennav_coverage_msgs__msg__Swath__Sequence *)(untyped_member);
  opennav_coverage_msgs__msg__Swath__Sequence__fini(member);
  return opennav_coverage_msgs__msg__Swath__Sequence__init(member, size);
}

size_t opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__size_function__PathComponents__turns(
  const void * untyped_member)
{
  const nav_msgs__msg__Path__Sequence * member =
    (const nav_msgs__msg__Path__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_const_function__PathComponents__turns(
  const void * untyped_member, size_t index)
{
  const nav_msgs__msg__Path__Sequence * member =
    (const nav_msgs__msg__Path__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_function__PathComponents__turns(
  void * untyped_member, size_t index)
{
  nav_msgs__msg__Path__Sequence * member =
    (nav_msgs__msg__Path__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__fetch_function__PathComponents__turns(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nav_msgs__msg__Path * item =
    ((const nav_msgs__msg__Path *)
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_const_function__PathComponents__turns(untyped_member, index));
  nav_msgs__msg__Path * value =
    (nav_msgs__msg__Path *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__assign_function__PathComponents__turns(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nav_msgs__msg__Path * item =
    ((nav_msgs__msg__Path *)
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_function__PathComponents__turns(untyped_member, index));
  const nav_msgs__msg__Path * value =
    (const nav_msgs__msg__Path *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__resize_function__PathComponents__turns(
  void * untyped_member, size_t size)
{
  nav_msgs__msg__Path__Sequence * member =
    (nav_msgs__msg__Path__Sequence *)(untyped_member);
  nav_msgs__msg__Path__Sequence__fini(member);
  return nav_msgs__msg__Path__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__PathComponents, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "swaths",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__PathComponents, swaths),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__size_function__PathComponents__swaths,  // size() function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_const_function__PathComponents__swaths,  // get_const(index) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_function__PathComponents__swaths,  // get(index) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__fetch_function__PathComponents__swaths,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__assign_function__PathComponents__swaths,  // assign(index, value) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__resize_function__PathComponents__swaths  // resize(index) function pointer
  },
  {
    "turns",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__PathComponents, turns),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__size_function__PathComponents__turns,  // size() function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_const_function__PathComponents__turns,  // get_const(index) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__get_function__PathComponents__turns,  // get(index) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__fetch_function__PathComponents__turns,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__assign_function__PathComponents__turns,  // assign(index, value) function pointer
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__resize_function__PathComponents__turns  // resize(index) function pointer
  },
  {
    "contains_turns",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__PathComponents, contains_turns),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "swaths_ordered",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__PathComponents, swaths_ordered),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_members = {
  "opennav_coverage_msgs__msg",  // message namespace
  "PathComponents",  // message name
  5,  // number of fields
  sizeof(opennav_coverage_msgs__msg__PathComponents),
  false,  // has_any_key_member_
  opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_member_array,  // message members
  opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__PathComponents__get_type_hash,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description,
  &opennav_coverage_msgs__msg__PathComponents__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, msg, PathComponents)() {
  opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, msg, Swath)();
  opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Path)();
  if (!opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__msg__PathComponents__rosidl_typesupport_introspection_c__PathComponents_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
