// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/RouteMode.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/route_mode__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__RouteMode__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6c, 0xa2, 0xf7, 0xe3, 0xd2, 0xa5, 0x05, 0x2a,
      0x85, 0xd2, 0x9a, 0xf3, 0x99, 0x64, 0x8b, 0x00,
      0x9d, 0xec, 0xa3, 0xdf, 0x1e, 0xbc, 0x27, 0x96,
      0xfb, 0xd0, 0xc8, 0x02, 0xb1, 0xf5, 0xa5, 0x0f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char opennav_coverage_msgs__msg__RouteMode__TYPE_NAME[] = "opennav_coverage_msgs/msg/RouteMode";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__RouteMode__FIELD_NAME__mode[] = "mode";
static char opennav_coverage_msgs__msg__RouteMode__DEFAULT_VALUE__mode[] = "UNKNOWN";
static char opennav_coverage_msgs__msg__RouteMode__FIELD_NAME__spiral_n[] = "spiral_n";
static char opennav_coverage_msgs__msg__RouteMode__DEFAULT_VALUE__spiral_n[] = "4";
static char opennav_coverage_msgs__msg__RouteMode__FIELD_NAME__custom_order[] = "custom_order";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__RouteMode__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__RouteMode__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__RouteMode__DEFAULT_VALUE__mode, 7, 7},
  },
  {
    {opennav_coverage_msgs__msg__RouteMode__FIELD_NAME__spiral_n, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {opennav_coverage_msgs__msg__RouteMode__DEFAULT_VALUE__spiral_n, 1, 1},
  },
  {
    {opennav_coverage_msgs__msg__RouteMode__FIELD_NAME__custom_order, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__RouteMode__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__RouteMode__TYPE_NAME, 35, 35},
      {opennav_coverage_msgs__msg__RouteMode__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string mode \"UNKNOWN\"  # BOUSTROPHEDON, SNAKE, SPIRAL, CUSTOM\n"
  "\n"
  "# Specific mode setting\n"
  "uint16 spiral_n 4  # If mode=SPIRAL, this is the number of swaths to spiral\n"
  "uint16[] custom_order  # If mode=CUSTOM, this is the order of swaths to set. Must be specified.";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__RouteMode__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__RouteMode__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 259, 259},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__RouteMode__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__RouteMode__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
