// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_components.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'swaths'
#include "opennav_coverage_msgs/msg/detail/swath__struct.h"
// Member 'turns'
#include "nav_msgs/msg/detail/path__struct.h"

/// Struct defined in msg/PathComponents in the package opennav_coverage_msgs.
/**
  * An ordered set of swaths (if route generated) and turns (if path generated)
 */
typedef struct opennav_coverage_msgs__msg__PathComponents
{
  std_msgs__msg__Header header;
  opennav_coverage_msgs__msg__Swath__Sequence swaths;
  nav_msgs__msg__Path__Sequence turns;
  bool contains_turns;
  bool swaths_ordered;
} opennav_coverage_msgs__msg__PathComponents;

// Struct for a sequence of opennav_coverage_msgs__msg__PathComponents.
typedef struct opennav_coverage_msgs__msg__PathComponents__Sequence
{
  opennav_coverage_msgs__msg__PathComponents * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__PathComponents__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__STRUCT_H_
