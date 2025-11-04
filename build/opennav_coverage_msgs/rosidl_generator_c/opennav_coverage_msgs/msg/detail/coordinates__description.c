// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/Coordinates.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/coordinates__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__Coordinates__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfd, 0xf0, 0x46, 0x3a, 0x97, 0x90, 0xc8, 0xf1,
      0x50, 0x2f, 0x80, 0x69, 0x39, 0xb8, 0xb5, 0xad,
      0xe2, 0xae, 0x0a, 0x9f, 0xdb, 0x20, 0x05, 0x97,
      0xcc, 0xe3, 0x10, 0x3a, 0x99, 0xaa, 0x9f, 0xb2,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "opennav_coverage_msgs/msg/detail/coordinate__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t opennav_coverage_msgs__msg__Coordinate__EXPECTED_HASH = {1, {
    0xf2, 0x44, 0xab, 0x3c, 0xaa, 0xe5, 0x03, 0x4d,
    0xca, 0x7c, 0x7f, 0x89, 0x9b, 0x4b, 0xbe, 0xb8,
    0xc5, 0x0f, 0x75, 0x83, 0x74, 0xdc, 0x38, 0xc7,
    0x03, 0xda, 0x94, 0xef, 0x91, 0xa2, 0x3f, 0x6b,
  }};
#endif

static char opennav_coverage_msgs__msg__Coordinates__TYPE_NAME[] = "opennav_coverage_msgs/msg/Coordinates";
static char opennav_coverage_msgs__msg__Coordinate__TYPE_NAME[] = "opennav_coverage_msgs/msg/Coordinate";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__Coordinates__FIELD_NAME__coordinates[] = "coordinates";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__Coordinates__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__Coordinates__FIELD_NAME__coordinates, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {opennav_coverage_msgs__msg__Coordinate__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription opennav_coverage_msgs__msg__Coordinates__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {opennav_coverage_msgs__msg__Coordinate__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__Coordinates__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__Coordinates__TYPE_NAME, 37, 37},
      {opennav_coverage_msgs__msg__Coordinates__FIELDS, 1, 1},
    },
    {opennav_coverage_msgs__msg__Coordinates__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&opennav_coverage_msgs__msg__Coordinate__EXPECTED_HASH, opennav_coverage_msgs__msg__Coordinate__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = opennav_coverage_msgs__msg__Coordinate__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "opennav_coverage_msgs/Coordinate[] coordinates";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__Coordinates__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__Coordinates__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 47, 47},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__Coordinates__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__Coordinates__get_individual_type_description_source(NULL),
    sources[1] = *opennav_coverage_msgs__msg__Coordinate__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
