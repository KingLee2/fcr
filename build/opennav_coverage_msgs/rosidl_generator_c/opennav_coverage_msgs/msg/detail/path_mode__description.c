// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/PathMode.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/path_mode__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__PathMode__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf9, 0x6a, 0xe8, 0x92, 0xa7, 0x5e, 0x03, 0xbe,
      0x23, 0x31, 0x1c, 0x15, 0xd1, 0x5d, 0x20, 0xe2,
      0x55, 0xd4, 0xfa, 0xf1, 0xfc, 0x47, 0x99, 0x2c,
      0x78, 0x8a, 0x54, 0xd1, 0x02, 0x23, 0xe1, 0xd3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char opennav_coverage_msgs__msg__PathMode__TYPE_NAME[] = "opennav_coverage_msgs/msg/PathMode";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__PathMode__FIELD_NAME__mode[] = "mode";
static char opennav_coverage_msgs__msg__PathMode__DEFAULT_VALUE__mode[] = "UNKNOWN";
static char opennav_coverage_msgs__msg__PathMode__FIELD_NAME__continuity_mode[] = "continuity_mode";
static char opennav_coverage_msgs__msg__PathMode__DEFAULT_VALUE__continuity_mode[] = "UNKNOWN";
static char opennav_coverage_msgs__msg__PathMode__FIELD_NAME__turn_point_distance[] = "turn_point_distance";
static char opennav_coverage_msgs__msg__PathMode__DEFAULT_VALUE__turn_point_distance[] = "0.1";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__PathMode__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__PathMode__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__PathMode__DEFAULT_VALUE__mode, 7, 7},
  },
  {
    {opennav_coverage_msgs__msg__PathMode__FIELD_NAME__continuity_mode, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__PathMode__DEFAULT_VALUE__continuity_mode, 7, 7},
  },
  {
    {opennav_coverage_msgs__msg__PathMode__FIELD_NAME__turn_point_distance, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__PathMode__DEFAULT_VALUE__turn_point_distance, 3, 3},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__PathMode__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__PathMode__TYPE_NAME, 34, 34},
      {opennav_coverage_msgs__msg__PathMode__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string mode \"UNKNOWN\"  # DUBIN, REEDS_SHEPP\n"
  "string continuity_mode \"UNKNOWN\"  # CONTINUOUS, DISCONTINUOUS\n"
  "float32 turn_point_distance 0.1  # Distance between path points in non-swath turns";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__PathMode__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__PathMode__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 189, 189},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__PathMode__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__PathMode__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
