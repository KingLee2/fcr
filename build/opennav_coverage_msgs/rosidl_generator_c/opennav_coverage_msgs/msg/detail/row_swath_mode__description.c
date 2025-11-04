// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/RowSwathMode.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/row_swath_mode__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__RowSwathMode__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa6, 0xcc, 0x67, 0xe9, 0x2d, 0x1e, 0x49, 0x70,
      0x05, 0x44, 0x6e, 0x97, 0xd9, 0xda, 0x26, 0x43,
      0x62, 0x43, 0x73, 0xd7, 0x42, 0xd2, 0x02, 0x8a,
      0x7b, 0x3f, 0x92, 0xbd, 0x09, 0x66, 0xa1, 0x62,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char opennav_coverage_msgs__msg__RowSwathMode__TYPE_NAME[] = "opennav_coverage_msgs/msg/RowSwathMode";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__RowSwathMode__FIELD_NAME__mode[] = "mode";
static char opennav_coverage_msgs__msg__RowSwathMode__DEFAULT_VALUE__mode[] = "UNKNOWN";
static char opennav_coverage_msgs__msg__RowSwathMode__FIELD_NAME__skip_ids[] = "skip_ids";
static char opennav_coverage_msgs__msg__RowSwathMode__FIELD_NAME__offset[] = "offset";
static char opennav_coverage_msgs__msg__RowSwathMode__DEFAULT_VALUE__offset[] = "0.0";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__RowSwathMode__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__RowSwathMode__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__RowSwathMode__DEFAULT_VALUE__mode, 7, 7},
  },
  {
    {opennav_coverage_msgs__msg__RowSwathMode__FIELD_NAME__skip_ids, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {opennav_coverage_msgs__msg__RowSwathMode__FIELD_NAME__offset, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__RowSwathMode__DEFAULT_VALUE__offset, 3, 3},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__RowSwathMode__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__RowSwathMode__TYPE_NAME, 38, 38},
      {opennav_coverage_msgs__msg__RowSwathMode__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string mode \"UNKNOWN\"  # CENTER, OFFSET, ROWSARESWATHS\n"
  "int32[] skip_ids # The ids to skip\n"
  "\n"
  "# Specific mode settings\n"
  "float32 offset 0.0  # If mode=OFFSET for offset for swath relative to rows";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__RowSwathMode__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__RowSwathMode__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 191, 191},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__RowSwathMode__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__RowSwathMode__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
