// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tf2_web_republisher_interfaces:srv/RepublishTFs.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__rosidl_typesupport_introspection_c.h"
#include "tf2_web_republisher_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__functions.h"
#include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__struct.h"


// Include directives for member types
// Member `source_frames`
// Member `target_frame`
#include "rosidl_runtime_c/string_functions.h"
// Member `timeout`
#include "builtin_interfaces/msg/duration.h"
// Member `timeout`
#include "builtin_interfaces/msg/detail/duration__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__init(message_memory);
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_fini_function(void * message_memory)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__fini(message_memory);
}

size_t tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__size_function__RepublishTFs_Request__source_frames(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Request__source_frames(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Request__source_frames(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__fetch_function__RepublishTFs_Request__source_frames(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Request__source_frames(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__assign_function__RepublishTFs_Request__source_frames(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Request__source_frames(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__resize_function__RepublishTFs_Request__source_frames(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_member_array[6] = {
  {
    "source_frames",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Request, source_frames),  // bytes offset in struct
    NULL,  // default value
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__size_function__RepublishTFs_Request__source_frames,  // size() function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Request__source_frames,  // get_const(index) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Request__source_frames,  // get(index) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__fetch_function__RepublishTFs_Request__source_frames,  // fetch(index, &value) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__assign_function__RepublishTFs_Request__source_frames,  // assign(index, value) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__resize_function__RepublishTFs_Request__source_frames  // resize(index) function pointer
  },
  {
    "target_frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Request, target_frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_thres",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Request, angular_thres),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trans_thres",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Request, trans_thres),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Request, rate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timeout",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Request, timeout),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_members = {
  "tf2_web_republisher_interfaces__srv",  // message namespace
  "RepublishTFs_Request",  // message name
  6,  // number of fields
  sizeof(tf2_web_republisher_interfaces__srv__RepublishTFs_Request),
  false,  // has_any_key_member_
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_member_array,  // message members
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_type_support_handle = {
  0,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_members,
  get_message_typesupport_handle_function,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Request__get_type_hash,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Request__get_type_description,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_web_republisher_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Request)() {
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Duration)();
  if (!tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_type_support_handle.typesupport_identifier) {
    tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tf2_web_republisher_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__functions.h"
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__struct.h"


// Include directives for member types
// Member `topic_name`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__init(message_memory);
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_fini_function(void * message_memory)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_member_array[1] = {
  {
    "topic_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Response, topic_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_members = {
  "tf2_web_republisher_interfaces__srv",  // message namespace
  "RepublishTFs_Response",  // message name
  1,  // number of fields
  sizeof(tf2_web_republisher_interfaces__srv__RepublishTFs_Response),
  false,  // has_any_key_member_
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_member_array,  // message members
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_type_support_handle = {
  0,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_members,
  get_message_typesupport_handle_function,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Response__get_type_hash,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Response__get_type_description,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_web_republisher_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Response)() {
  if (!tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_type_support_handle.typesupport_identifier) {
    tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tf2_web_republisher_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__functions.h"
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "tf2_web_republisher_interfaces/srv/republish_t_fs.h"
// Member `request`
// Member `response`
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__init(message_memory);
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_fini_function(void * message_memory)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__fini(message_memory);
}

size_t tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__size_function__RepublishTFs_Event__request(
  const void * untyped_member)
{
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence * member =
    (const tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Event__request(
  const void * untyped_member, size_t index)
{
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence * member =
    (const tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Event__request(
  void * untyped_member, size_t index)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence * member =
    (tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__fetch_function__RepublishTFs_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Request * item =
    ((const tf2_web_republisher_interfaces__srv__RepublishTFs_Request *)
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Event__request(untyped_member, index));
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request * value =
    (tf2_web_republisher_interfaces__srv__RepublishTFs_Request *)(untyped_value);
  *value = *item;
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__assign_function__RepublishTFs_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request * item =
    ((tf2_web_republisher_interfaces__srv__RepublishTFs_Request *)
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Event__request(untyped_member, index));
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Request * value =
    (const tf2_web_republisher_interfaces__srv__RepublishTFs_Request *)(untyped_value);
  *item = *value;
}

bool tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__resize_function__RepublishTFs_Event__request(
  void * untyped_member, size_t size)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence * member =
    (tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence *)(untyped_member);
  tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence__fini(member);
  return tf2_web_republisher_interfaces__srv__RepublishTFs_Request__Sequence__init(member, size);
}

size_t tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__size_function__RepublishTFs_Event__response(
  const void * untyped_member)
{
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence * member =
    (const tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Event__response(
  const void * untyped_member, size_t index)
{
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence * member =
    (const tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Event__response(
  void * untyped_member, size_t index)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence * member =
    (tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__fetch_function__RepublishTFs_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Response * item =
    ((const tf2_web_republisher_interfaces__srv__RepublishTFs_Response *)
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Event__response(untyped_member, index));
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response * value =
    (tf2_web_republisher_interfaces__srv__RepublishTFs_Response *)(untyped_value);
  *value = *item;
}

void tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__assign_function__RepublishTFs_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response * item =
    ((tf2_web_republisher_interfaces__srv__RepublishTFs_Response *)
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Event__response(untyped_member, index));
  const tf2_web_republisher_interfaces__srv__RepublishTFs_Response * value =
    (const tf2_web_republisher_interfaces__srv__RepublishTFs_Response *)(untyped_value);
  *item = *value;
}

bool tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__resize_function__RepublishTFs_Event__response(
  void * untyped_member, size_t size)
{
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence * member =
    (tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence *)(untyped_member);
  tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence__fini(member);
  return tf2_web_republisher_interfaces__srv__RepublishTFs_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Event, info),  // bytes offset in struct
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
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Event, request),  // bytes offset in struct
    NULL,  // default value
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__size_function__RepublishTFs_Event__request,  // size() function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Event__request,  // get_const(index) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Event__request,  // get(index) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__fetch_function__RepublishTFs_Event__request,  // fetch(index, &value) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__assign_function__RepublishTFs_Event__request,  // assign(index, value) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__resize_function__RepublishTFs_Event__request  // resize(index) function pointer
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
    offsetof(tf2_web_republisher_interfaces__srv__RepublishTFs_Event, response),  // bytes offset in struct
    NULL,  // default value
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__size_function__RepublishTFs_Event__response,  // size() function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_const_function__RepublishTFs_Event__response,  // get_const(index) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__get_function__RepublishTFs_Event__response,  // get(index) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__fetch_function__RepublishTFs_Event__response,  // fetch(index, &value) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__assign_function__RepublishTFs_Event__response,  // assign(index, value) function pointer
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__resize_function__RepublishTFs_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_members = {
  "tf2_web_republisher_interfaces__srv",  // message namespace
  "RepublishTFs_Event",  // message name
  3,  // number of fields
  sizeof(tf2_web_republisher_interfaces__srv__RepublishTFs_Event),
  false,  // has_any_key_member_
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_member_array,  // message members
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_type_support_handle = {
  0,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_members,
  get_message_typesupport_handle_function,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Event__get_type_hash,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Event__get_type_description,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_web_republisher_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Event)() {
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Request)();
  tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Response)();
  if (!tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_type_support_handle.typesupport_identifier) {
    tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tf2_web_republisher_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_service_members = {
  "tf2_web_republisher_interfaces__srv",  // service namespace
  "RepublishTFs",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_type_support_handle,
  NULL,  // response message
  // tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_type_support_handle
  NULL  // event_message
  // tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_type_support_handle
};


static rosidl_service_type_support_t tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_service_type_support_handle = {
  0,
  &tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_service_members,
  get_service_typesupport_handle_function,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Request__rosidl_typesupport_introspection_c__RepublishTFs_Request_message_type_support_handle,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Response__rosidl_typesupport_introspection_c__RepublishTFs_Response_message_type_support_handle,
  &tf2_web_republisher_interfaces__srv__RepublishTFs_Event__rosidl_typesupport_introspection_c__RepublishTFs_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tf2_web_republisher_interfaces,
    srv,
    RepublishTFs
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tf2_web_republisher_interfaces,
    srv,
    RepublishTFs
  ),
  &tf2_web_republisher_interfaces__srv__RepublishTFs__get_type_hash,
  &tf2_web_republisher_interfaces__srv__RepublishTFs__get_type_description,
  &tf2_web_republisher_interfaces__srv__RepublishTFs__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_web_republisher_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs)(void) {
  if (!tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_service_type_support_handle.typesupport_identifier) {
    tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, srv, RepublishTFs_Event)()->data;
  }

  return &tf2_web_republisher_interfaces__srv__detail__republish_t_fs__rosidl_typesupport_introspection_c__RepublishTFs_service_type_support_handle;
}
