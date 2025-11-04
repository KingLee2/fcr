// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/RouteMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/route_mode.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'mode'
#include "rosidl_runtime_c/string.h"
// Member 'custom_order'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RouteMode in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__msg__RouteMode
{
  /// BOUSTROPHEDON, SNAKE, SPIRAL, CUSTOM
  rosidl_runtime_c__String mode;
  /// Specific mode setting
  /// If mode=SPIRAL, this is the number of swaths to spiral
  uint16_t spiral_n;
  /// If mode=CUSTOM, this is the order of swaths to set. Must be specified.
  rosidl_runtime_c__uint16__Sequence custom_order;
} opennav_coverage_msgs__msg__RouteMode;

// Struct for a sequence of opennav_coverage_msgs__msg__RouteMode.
typedef struct opennav_coverage_msgs__msg__RouteMode__Sequence
{
  opennav_coverage_msgs__msg__RouteMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__RouteMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__STRUCT_H_
