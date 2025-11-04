// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from opennav_coverage_msgs:msg/RowSwathMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__rosidl_typesupport_introspection_c.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__functions.h"
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__struct.h"


// Include directives for member types
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"
// Member `skip_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__msg__RowSwathMode__init(message_memory);
}

void opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_fini_function(void * message_memory)
{
  opennav_coverage_msgs__msg__RowSwathMode__fini(message_memory);
}

size_t opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__size_function__RowSwathMode__skip_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__get_const_function__RowSwathMode__skip_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__get_function__RowSwathMode__skip_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__fetch_function__RowSwathMode__skip_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__get_const_function__RowSwathMode__skip_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__assign_function__RowSwathMode__skip_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__get_function__RowSwathMode__skip_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__resize_function__RowSwathMode__skip_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_member_array[3] = {
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__RowSwathMode, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "skip_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__RowSwathMode, skip_ids),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__size_function__RowSwathMode__skip_ids,  // size() function pointer
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__get_const_function__RowSwathMode__skip_ids,  // get_const(index) function pointer
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__get_function__RowSwathMode__skip_ids,  // get(index) function pointer
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__fetch_function__RowSwathMode__skip_ids,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__assign_function__RowSwathMode__skip_ids,  // assign(index, value) function pointer
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__resize_function__RowSwathMode__skip_ids  // resize(index) function pointer
  },
  {
    "offset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__msg__RowSwathMode, offset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_members = {
  "opennav_coverage_msgs__msg",  // message namespace
  "RowSwathMode",  // message name
  3,  // number of fields
  sizeof(opennav_coverage_msgs__msg__RowSwathMode),
  false,  // has_any_key_member_
  opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_member_array,  // message members
  opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__msg__RowSwathMode__get_type_hash,
  &opennav_coverage_msgs__msg__RowSwathMode__get_type_description,
  &opennav_coverage_msgs__msg__RowSwathMode__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, msg, RowSwathMode)() {
  if (!opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__msg__RowSwathMode__rosidl_typesupport_introspection_c__RowSwathMode_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
