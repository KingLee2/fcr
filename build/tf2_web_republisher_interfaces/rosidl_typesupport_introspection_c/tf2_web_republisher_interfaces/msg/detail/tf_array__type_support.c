// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tf2_web_republisher_interfaces:msg/TFArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tf2_web_republisher_interfaces/msg/detail/tf_array__rosidl_typesupport_introspection_c.h"
#include "tf2_web_republisher_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tf2_web_republisher_interfaces/msg/detail/tf_array__functions.h"
#include "tf2_web_republisher_interfaces/msg/detail/tf_array__struct.h"


// Include directives for member types
// Member `transforms`
#include "geometry_msgs/msg/transform_stamped.h"
// Member `transforms`
#include "geometry_msgs/msg/detail/transform_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tf2_web_republisher_interfaces__msg__TFArray__init(message_memory);
}

void tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_fini_function(void * message_memory)
{
  tf2_web_republisher_interfaces__msg__TFArray__fini(message_memory);
}

size_t tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__size_function__TFArray__transforms(
  const void * untyped_member)
{
  const geometry_msgs__msg__TransformStamped__Sequence * member =
    (const geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  return member->size;
}

const void * tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__get_const_function__TFArray__transforms(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__TransformStamped__Sequence * member =
    (const geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__get_function__TFArray__transforms(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__TransformStamped__Sequence * member =
    (geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__fetch_function__TFArray__transforms(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__TransformStamped * item =
    ((const geometry_msgs__msg__TransformStamped *)
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__get_const_function__TFArray__transforms(untyped_member, index));
  geometry_msgs__msg__TransformStamped * value =
    (geometry_msgs__msg__TransformStamped *)(untyped_value);
  *value = *item;
}

void tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__assign_function__TFArray__transforms(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__TransformStamped * item =
    ((geometry_msgs__msg__TransformStamped *)
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__get_function__TFArray__transforms(untyped_member, index));
  const geometry_msgs__msg__TransformStamped * value =
    (const geometry_msgs__msg__TransformStamped *)(untyped_value);
  *item = *value;
}

bool tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__resize_function__TFArray__transforms(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__TransformStamped__Sequence * member =
    (geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  geometry_msgs__msg__TransformStamped__Sequence__fini(member);
  return geometry_msgs__msg__TransformStamped__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_member_array[1] = {
  {
    "transforms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_web_republisher_interfaces__msg__TFArray, transforms),  // bytes offset in struct
    NULL,  // default value
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__size_function__TFArray__transforms,  // size() function pointer
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__get_const_function__TFArray__transforms,  // get_const(index) function pointer
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__get_function__TFArray__transforms,  // get(index) function pointer
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__fetch_function__TFArray__transforms,  // fetch(index, &value) function pointer
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__assign_function__TFArray__transforms,  // assign(index, value) function pointer
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__resize_function__TFArray__transforms  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_members = {
  "tf2_web_republisher_interfaces__msg",  // message namespace
  "TFArray",  // message name
  1,  // number of fields
  sizeof(tf2_web_republisher_interfaces__msg__TFArray),
  false,  // has_any_key_member_
  tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_member_array,  // message members
  tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_init_function,  // function to initialize message memory (memory has to be allocated)
  tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_type_support_handle = {
  0,
  &tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_members,
  get_message_typesupport_handle_function,
  &tf2_web_republisher_interfaces__msg__TFArray__get_type_hash,
  &tf2_web_republisher_interfaces__msg__TFArray__get_type_description,
  &tf2_web_republisher_interfaces__msg__TFArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_web_republisher_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_web_republisher_interfaces, msg, TFArray)() {
  tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, TransformStamped)();
  if (!tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_type_support_handle.typesupport_identifier) {
    tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tf2_web_republisher_interfaces__msg__TFArray__rosidl_typesupport_introspection_c__TFArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
