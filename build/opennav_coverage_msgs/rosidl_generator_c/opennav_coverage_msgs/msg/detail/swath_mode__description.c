// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/SwathMode.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/swath_mode__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__SwathMode__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaa, 0x63, 0x91, 0x5b, 0x56, 0x4d, 0xb2, 0xcf,
      0x5e, 0x58, 0xcd, 0xbe, 0x23, 0x13, 0xe7, 0x3b,
      0xb8, 0x49, 0xf2, 0xea, 0xea, 0x4e, 0x9c, 0xb4,
      0xce, 0xe1, 0x67, 0xa7, 0x31, 0x47, 0x83, 0x52,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char opennav_coverage_msgs__msg__SwathMode__TYPE_NAME[] = "opennav_coverage_msgs/msg/SwathMode";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__objective[] = "objective";
static char opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__objective[] = "UNKNOWN";
static char opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__mode[] = "mode";
static char opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__mode[] = "UNKNOWN";
static char opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__best_angle[] = "best_angle";
static char opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__best_angle[] = "0.0";
static char opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__step_angle[] = "step_angle";
static char opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__step_angle[] = "0.017453";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__SwathMode__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__objective, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__objective, 7, 7},
  },
  {
    {opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__mode, 7, 7},
  },
  {
    {opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__best_angle, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__best_angle, 3, 3},
  },
  {
    {opennav_coverage_msgs__msg__SwathMode__FIELD_NAME__step_angle, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__SwathMode__DEFAULT_VALUE__step_angle, 8, 8},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__SwathMode__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__SwathMode__TYPE_NAME, 35, 35},
      {opennav_coverage_msgs__msg__SwathMode__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string objective \"UNKNOWN\"  # LENGTH, NUMBER, or COVERAGE\n"
  "string mode \"UNKNOWN\"  # BRUTE_FORCE, SET_ANGLE\n"
  "\n"
  "# Specific mode settings\n"
  "float32 best_angle 0.0  # If mode=SET_ANGLE for angle to generate swaths based on\n"
  "float32 step_angle 1.7453e-2 # If mode=BRUTE_FORCE, angular step to search";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__SwathMode__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__SwathMode__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 289, 289},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__SwathMode__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__SwathMode__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
