// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from opennav_coverage_msgs:action/NavigateCompleteCoverage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
#include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
#include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `field_filepath`
// Member `frame_id`
// Member `behavior_tree`
#include "rosidl_runtime_c/string_functions.h"
// Member `polygons`
#include "geometry_msgs/msg/polygon.h"
// Member `polygons`
#include "geometry_msgs/msg/detail/polygon__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(message_memory);
}

size_t opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_Goal__polygons(
  const void * untyped_member)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_Goal__polygons(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_Goal__polygons(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_Goal__polygons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Polygon * item =
    ((const geometry_msgs__msg__Polygon *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_Goal__polygons(untyped_member, index));
  geometry_msgs__msg__Polygon * value =
    (geometry_msgs__msg__Polygon *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_Goal__polygons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Polygon * item =
    ((geometry_msgs__msg__Polygon *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_Goal__polygons(untyped_member, index));
  const geometry_msgs__msg__Polygon * value =
    (const geometry_msgs__msg__Polygon *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_Goal__polygons(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  geometry_msgs__msg__Polygon__Sequence__fini(member);
  return geometry_msgs__msg__Polygon__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_member_array[4] = {
  {
    "field_filepath",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal, field_filepath),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "polygons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal, polygons),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_Goal__polygons,  // size() function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_Goal__polygons,  // get_const(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_Goal__polygons,  // get(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_Goal__polygons,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_Goal__polygons,  // assign(index, value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_Goal__polygons  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "behavior_tree",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal, behavior_tree),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_Goal",  // message name
  4,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_Goal)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_member_array[1] = {
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result, error_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_Result",  // message name
  1,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_Result)() {
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `current_pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"
// Member `navigation_time`
// Member `estimated_time_remaining`
#include "builtin_interfaces/msg/duration.h"
// Member `navigation_time`
// Member `estimated_time_remaining`
#include "builtin_interfaces/msg/detail/duration__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_member_array[5] = {
  {
    "current_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback, current_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "navigation_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback, navigation_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "estimated_time_remaining",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback, estimated_time_remaining),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "number_of_recoveries",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback, number_of_recoveries),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_remaining",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback, distance_remaining),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_Feedback",  // message name
  5,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_Feedback)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Duration)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Duration)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "opennav_coverage_msgs/action/navigate_complete_coverage.h"
// Member `goal`
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Request)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_Goal)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Response)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "opennav_coverage_msgs/action/navigate_complete_coverage.h"
// Member `request`
// Member `response`
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(message_memory);
}

size_t opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_SendGoal_Event__request(
  const void * untyped_member)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_SendGoal_Event__request(
  const void * untyped_member, size_t index)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_SendGoal_Event__request(
  void * untyped_member, size_t index)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_SendGoal_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * item =
    ((const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_SendGoal_Event__request(untyped_member, index));
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * value =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_SendGoal_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * item =
    ((opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_SendGoal_Event__request(untyped_member, index));
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * value =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_SendGoal_Event__request(
  void * untyped_member, size_t size)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence *)(untyped_member);
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__fini(member);
  return opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__init(member, size);
}

size_t opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_SendGoal_Event__response(
  const void * untyped_member)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_SendGoal_Event__response(
  const void * untyped_member, size_t index)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_SendGoal_Event__response(
  void * untyped_member, size_t index)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_SendGoal_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * item =
    ((const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_SendGoal_Event__response(untyped_member, index));
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * value =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_SendGoal_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * item =
    ((opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_SendGoal_Event__response(untyped_member, index));
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * value =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_SendGoal_Event__response(
  void * untyped_member, size_t size)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence *)(untyped_member);
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__fini(member);
  return opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event, request),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_SendGoal_Event__request,  // size() function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_SendGoal_Event__request,  // get_const(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_SendGoal_Event__request,  // get(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_SendGoal_Event__request,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_SendGoal_Event__request,  // assign(index, value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_SendGoal_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event, response),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_SendGoal_Event__response,  // size() function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_SendGoal_Event__response,  // get_const(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_SendGoal_Event__response,  // get(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_SendGoal_Event__response,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_SendGoal_Event__response,  // assign(index, value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_SendGoal_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_SendGoal_Event",  // message name
  3,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Event)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Request)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Response)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_service_members = {
  "opennav_coverage_msgs__action",  // service namespace
  "NavigateCompleteCoverage_SendGoal",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_type_support_handle,
  NULL,  // response message
  // opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_type_support_handle
  NULL  // event_message
  // opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_type_support_handle
};


static rosidl_service_type_support_t opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_service_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_service_members,
  get_service_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Request_message_type_support_handle,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Response_message_type_support_handle,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    opennav_coverage_msgs,
    action,
    NavigateCompleteCoverage_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    opennav_coverage_msgs,
    action,
    NavigateCompleteCoverage_SendGoal
  ),
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal)(void) {
  if (!opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_service_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_SendGoal_Event)()->data;
  }

  return &opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Request)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "opennav_coverage_msgs/action/navigate_complete_coverage.h"
// Member `result`
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Response)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_Result)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/service_event_info.h"
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "opennav_coverage_msgs/action/navigate_complete_coverage.h"
// Member `request`
// Member `response`
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(message_memory);
}

size_t opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_GetResult_Event__request(
  const void * untyped_member)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_GetResult_Event__request(
  const void * untyped_member, size_t index)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_GetResult_Event__request(
  void * untyped_member, size_t index)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_GetResult_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * item =
    ((const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_GetResult_Event__request(untyped_member, index));
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * value =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_GetResult_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * item =
    ((opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_GetResult_Event__request(untyped_member, index));
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * value =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_GetResult_Event__request(
  void * untyped_member, size_t size)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence *)(untyped_member);
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__fini(member);
  return opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__init(member, size);
}

size_t opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_GetResult_Event__response(
  const void * untyped_member)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_GetResult_Event__response(
  const void * untyped_member, size_t index)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * member =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_GetResult_Event__response(
  void * untyped_member, size_t index)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_GetResult_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * item =
    ((const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_GetResult_Event__response(untyped_member, index));
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * value =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *)(untyped_value);
  *value = *item;
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_GetResult_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * item =
    ((opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *)
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_GetResult_Event__response(untyped_member, index));
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * value =
    (const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *)(untyped_value);
  *item = *value;
}

bool opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_GetResult_Event__response(
  void * untyped_member, size_t size)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * member =
    (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence *)(untyped_member);
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__fini(member);
  return opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event, request),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_GetResult_Event__request,  // size() function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_GetResult_Event__request,  // get_const(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_GetResult_Event__request,  // get(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_GetResult_Event__request,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_GetResult_Event__request,  // assign(index, value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_GetResult_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event, response),  // bytes offset in struct
    NULL,  // default value
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__size_function__NavigateCompleteCoverage_GetResult_Event__response,  // size() function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__NavigateCompleteCoverage_GetResult_Event__response,  // get_const(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__get_function__NavigateCompleteCoverage_GetResult_Event__response,  // get(index) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__NavigateCompleteCoverage_GetResult_Event__response,  // fetch(index, &value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__NavigateCompleteCoverage_GetResult_Event__response,  // assign(index, value) function pointer
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__NavigateCompleteCoverage_GetResult_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_GetResult_Event",  // message name
  3,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Event)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Request)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Response)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_service_members = {
  "opennav_coverage_msgs__action",  // service namespace
  "NavigateCompleteCoverage_GetResult",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_type_support_handle,
  NULL,  // response message
  // opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_type_support_handle
  NULL  // event_message
  // opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_type_support_handle
};


static rosidl_service_type_support_t opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_service_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_service_members,
  get_service_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Request_message_type_support_handle,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Response_message_type_support_handle,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    opennav_coverage_msgs,
    action,
    NavigateCompleteCoverage_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    opennav_coverage_msgs,
    action,
    NavigateCompleteCoverage_GetResult
  ),
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult)(void) {
  if (!opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_service_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_GetResult_Event)()->data;
  }

  return &opennav_coverage_msgs__action__detail__navigate_complete_coverage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"
// already included above
// #include "opennav_coverage_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "opennav_coverage_msgs/action/navigate_complete_coverage.h"
// Member `feedback`
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__init(message_memory);
}

void opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_fini_function(void * message_memory)
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_members = {
  "opennav_coverage_msgs__action",  // message namespace
  "NavigateCompleteCoverage_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage),
  false,  // has_any_key_member_
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_member_array,  // message members
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_type_support_handle = {
  0,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__get_type_hash,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__get_type_description,
  &opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_opennav_coverage_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_FeedbackMessage)() {
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, opennav_coverage_msgs, action, NavigateCompleteCoverage_Feedback)();
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__rosidl_typesupport_introspection_c__NavigateCompleteCoverage_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
