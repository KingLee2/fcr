// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/HeadlandMode.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/headland_mode__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__HeadlandMode__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x11, 0x5d, 0xe2, 0x5c, 0x24, 0xaf, 0x0e, 0x42,
      0x54, 0x72, 0x6f, 0xda, 0x73, 0xe9, 0x35, 0xe1,
      0x75, 0xc2, 0x4e, 0xc4, 0x26, 0x63, 0x91, 0x9b,
      0xfd, 0x9a, 0x0e, 0xcb, 0xc5, 0x28, 0x95, 0xee,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char opennav_coverage_msgs__msg__HeadlandMode__TYPE_NAME[] = "opennav_coverage_msgs/msg/HeadlandMode";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__HeadlandMode__FIELD_NAME__mode[] = "mode";
static char opennav_coverage_msgs__msg__HeadlandMode__DEFAULT_VALUE__mode[] = "UNKNOWN";
static char opennav_coverage_msgs__msg__HeadlandMode__FIELD_NAME__width[] = "width";
static char opennav_coverage_msgs__msg__HeadlandMode__DEFAULT_VALUE__width[] = "2.0";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__HeadlandMode__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__HeadlandMode__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__HeadlandMode__DEFAULT_VALUE__mode, 7, 7},
  },
  {
    {opennav_coverage_msgs__msg__HeadlandMode__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__HeadlandMode__DEFAULT_VALUE__width, 3, 3},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__HeadlandMode__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__HeadlandMode__TYPE_NAME, 38, 38},
      {opennav_coverage_msgs__msg__HeadlandMode__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string mode \"UNKNOWN\"\n"
  "\n"
  "# Specific mode setting\n"
  "float32 width 2.0  # width of headland around field";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__HeadlandMode__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__HeadlandMode__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 99, 99},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__HeadlandMode__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__HeadlandMode__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
