// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from opennav_coverage_msgs:msg/Coordinates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "opennav_coverage_msgs/msg/detail/coordinates__rosidl_typesupport_introspection_c.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "opennav_coverage_msgs/msg/detail/coordinates__functions.h"
#include "opennav_coverage_msgs/msg/detail/coordinates__struct.h"


// Include directives for member types
// Member `coordinates`
#include "opennav_coverage_msgs/msg/coordinate.h"
// Member `coordinates`
#include "opennav_coverage_msgs/msg/detail/coordinate__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__msg__Coordinates__init(message_memory);
}

void opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_fini_function(void * message_memory)
{
  opennav_coverage_msgs__msg__Coordinates__fini(message_memory);
}

size_t opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__size_function__Coordinates__coordinates(
  const void * untyped_member)
{
  const opennav_coverage_msgs__msg__Coordinate__Sequence * member =
    (const opennav_coverage_msgs__msg__Coordinate__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__get_const_function__Coordinates__coordinates(
  const void * untyped_member, size_t index)
{
  const opennav_coverage_msgs__msg__Coordinate__Sequence * member =
    (const opennav_coverage_msgs__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__get_function__Coordinates__coordinates(
  void * untyped_member, size_t index)
{
  opennav_coverage_msgs__msg__Coordinate__Sequence * member =
    (opennav_coverage_msgs__msg__Coordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__fetch_function__Coordinates__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const opennav_coverage_msgs__msg__Coordinate * item =
    ((const opennav_coverage_msgs__msg__Coordinate *)
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__get_const_function__Coordinates__coordinates(untyped_member, index));
  opennav_coverage_msgs__msg__Coordinate * value =
    (opennav_coverage_msgs__msg__Coordinate *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__assign_function__Coordinates__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  opennav_coverage_msgs__msg__Coordinate * item =
    ((opennav_coverage_msgs__msg__Coordinate *)
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__get_function__Coordinates__coordinates(untyped_member, index));
  const opennav_coverage_msgs__msg__Coordinate * value =
    (const opennav_coverage_msgs__msg__Coordinate *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__resize_function__Coordinates__coordinates(
  void * untyped_member, size_t size)
{
  opennav_coverage_msgs__msg__Coordinate__Sequence * member =
    (opennav_coverage_msgs__msg__Coordinate__Sequence *)(untyped_member);
  opennav_coverage_msgs__msg__Coordinate__Sequence__fini(member);
  return opennav_coverage_msgs__msg__Coordinate__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_member_array[1] = {
  {
    "coordinates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__Coordinates, coordinates),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__size_function__Coordinates__coordinates,  // size() function pointer
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__get_const_function__Coordinates__coordinates,  // get_const(index) function pointer
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__get_function__Coordinates__coordinates,  // get(index) function pointer
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__fetch_function__Coordinates__coordinates,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__assign_function__Coordinates__coordinates,  // assign(index, value) function pointer
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__resize_function__Coordinates__coordinates  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_members = {
  "opennav_coverage_msgs__msg",  // message namespace
  "Coordinates",  // message name
  1,  // number of fields
  sizeof(opennav_coverage_msgs__msg__Coordinates),
  false,  // has_any_key_member_
  opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_member_array,  // message members
  opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__Coordinates__get_type_hash,
  &opennav_coverage_msgs__msg__Coordinates__get_type_description,
  &opennav_coverage_msgs__msg__Coordinates__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, msg, Coordinates)() {
  opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, msg, Coordinate)();
  if (!opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__msg__Coordinates__rosidl_typesupport_introspection_c__Coordinates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
