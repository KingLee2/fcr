// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/Coordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/coordinate.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Coordinate in the package opennav_coverage_msgs.
/**
  * Can be GPS, Cartesian, or any other kind of coordinate system
 */
typedef struct opennav_coverage_msgs__msg__Coordinate
{
  float axis1;
  float axis2;
} opennav_coverage_msgs__msg__Coordinate;

// Struct for a sequence of opennav_coverage_msgs__msg__Coordinate.
typedef struct opennav_coverage_msgs__msg__Coordinate__Sequence
{
  opennav_coverage_msgs__msg__Coordinate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__Coordinate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__STRUCT_H_
