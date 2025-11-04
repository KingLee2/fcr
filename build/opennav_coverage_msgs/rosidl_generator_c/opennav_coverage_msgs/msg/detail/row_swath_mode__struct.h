// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:msg/RowSwathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/row_swath_mode.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__STRUCT_H_

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
// Member 'skip_ids'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RowSwathMode in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__msg__RowSwathMode
{
  /// CENTER, OFFSET, ROWSARESWATHS
  rosidl_runtime_c__String mode;
  /// The ids to skip
  rosidl_runtime_c__int32__Sequence skip_ids;
  /// Specific mode settings
  /// If mode=OFFSET for offset for swath relative to rows
  float offset;
} opennav_coverage_msgs__msg__RowSwathMode;

// Struct for a sequence of opennav_coverage_msgs__msg__RowSwathMode.
typedef struct opennav_coverage_msgs__msg__RowSwathMode__Sequence
{
  opennav_coverage_msgs__msg__RowSwathMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__msg__RowSwathMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__STRUCT_H_
