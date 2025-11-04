// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/Coordinate.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/coordinate__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__Coordinate__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf2, 0x44, 0xab, 0x3c, 0xaa, 0xe5, 0x03, 0x4d,
      0xca, 0x7c, 0x7f, 0x89, 0x9b, 0x4b, 0xbe, 0xb8,
      0xc5, 0x0f, 0x75, 0x83, 0x74, 0xdc, 0x38, 0xc7,
      0x03, 0xda, 0x94, 0xef, 0x91, 0xa2, 0x3f, 0x6b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char opennav_coverage_msgs__msg__Coordinate__TYPE_NAME[] = "opennav_coverage_msgs/msg/Coordinate";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__Coordinate__FIELD_NAME__axis1[] = "axis1";
static char opennav_coverage_msgs__msg__Coordinate__FIELD_NAME__axis2[] = "axis2";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__Coordinate__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__Coordinate__FIELD_NAME__axis1, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {opennav_coverage_msgs__msg__Coordinate__FIELD_NAME__axis2, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__Coordinate__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__Coordinate__TYPE_NAME, 36, 36},
      {opennav_coverage_msgs__msg__Coordinate__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Can be GPS, Cartesian, or any other kind of coordinate system\n"
  "float32 axis1\n"
  "float32 axis2";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__Coordinate__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__Coordinate__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 91, 91},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__Coordinate__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__Coordinate__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
