// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/SwathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/swath_mode.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH_MODE__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'objective'
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SwathMode in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__msg__SwathMode
{
  /// LENGTH, NUMBER, or COVERAGE
  rosidl_runtime_c__String objective;
  /// BRUTE_FORCE, SET_ANGLE
  rosidl_runtime_c__String mode;
  /// Specific mode settings
  /// If mode=SET_ANGLE for angle to generate swaths based on
  float best_angle;
  /// If mode=BRUTE_FORCE, angular step to search
  float step_angle;
} opennav_coverage_msgs__msg__SwathMode;

// Struct for a sequence of opennav_coverage_msgs__msg__SwathMode.
typedef struct opennav_coverage_msgs__msg__SwathMode__Sequence
{
  opennav_coverage_msgs__msg__SwathMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__SwathMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH_MODE__STRUCT_H_
