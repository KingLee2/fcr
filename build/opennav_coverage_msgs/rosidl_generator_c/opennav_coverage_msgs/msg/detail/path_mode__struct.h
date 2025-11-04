// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/PathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_mode.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__STRUCT_H_

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
// Member 'continuity_mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/PathMode in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__msg__PathMode
{
  /// DUBIN, REEDS_SHEPP
  rosidl_runtime_c__String mode;
  /// CONTINUOUS, DISCONTINUOUS
  rosidl_runtime_c__String continuity_mode;
  /// Distance between path points in non-swath turns
  float turn_point_distance;
} opennav_coverage_msgs__msg__PathMode;

// Struct for a sequence of opennav_coverage_msgs__msg__PathMode.
typedef struct opennav_coverage_msgs__msg__PathMode__Sequence
{
  opennav_coverage_msgs__msg__PathMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__PathMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__STRUCT_H_
