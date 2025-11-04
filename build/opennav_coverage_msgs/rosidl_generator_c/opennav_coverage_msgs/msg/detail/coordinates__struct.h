// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/Coordinates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/coordinates.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'coordinates'
#include "opennav_coverage_msgs/msg/detail/coordinate__struct.h"

/// Struct defined in msg/Coordinates in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__msg__Coordinates
{
  opennav_coverage_msgs__msg__Coordinate__Sequence coordinates;
} opennav_coverage_msgs__msg__Coordinates;

// Struct for a sequence of opennav_coverage_msgs__msg__Coordinates.
typedef struct opennav_coverage_msgs__msg__Coordinates__Sequence
{
  opennav_coverage_msgs__msg__Coordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__Coordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__STRUCT_H_
