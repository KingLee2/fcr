// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/swath.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'start'
// Member 'end'
#include "geometry_msgs/msg/detail/point32__struct.h"

/// Struct defined in msg/Swath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__msg__Swath
{
  geometry_msgs__msg__Point32 start;
  geometry_msgs__msg__Point32 end;
} opennav_coverage_msgs__msg__Swath;

// Struct for a sequence of opennav_coverage_msgs__msg__Swath.
typedef struct opennav_coverage_msgs__msg__Swath__Sequence
{
  opennav_coverage_msgs__msg__Swath * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__Swath__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__STRUCT_H_
