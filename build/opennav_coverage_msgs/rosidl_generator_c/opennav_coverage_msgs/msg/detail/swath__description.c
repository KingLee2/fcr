// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice

#include "opennav_coverage_msgs/msg/detail/swath__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__Swath__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x25, 0xd8, 0x9c, 0x40, 0x43, 0x00, 0x0b, 0x73,
      0xe9, 0xfb, 0xbb, 0xee, 0xe1, 0xdb, 0xe3, 0xbb,
      0xdc, 0x61, 0x51, 0x62, 0x48, 0x75, 0x9d, 0x03,
      0x6f, 0xc3, 0xbd, 0x95, 0x91, 0xd5, 0x09, 0xb0,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point32__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point32__EXPECTED_HASH = {1, {
    0x2f, 0xc4, 0xdb, 0x7c, 0xae, 0x16, 0xa4, 0x58,
    0x2c, 0x79, 0xa5, 0x6b, 0x66, 0x17, 0x3a, 0x8d,
    0x48, 0xd5, 0x2c, 0x7d, 0xc5, 0x20, 0xdd, 0xc5,
    0x5a, 0x0d, 0x4b, 0xcf, 0x2a, 0x4b, 0xfd, 0xbc,
  }};
#endif

static char opennav_coverage_msgs__msg__Swath__TYPE_NAME[] = "opennav_coverage_msgs/msg/Swath";
static char geometry_msgs__msg__Point32__TYPE_NAME[] = "geometry_msgs/msg/Point32";

// Define type names, field names, and default values
static char opennav_coverage_msgs__msg__Swath__FIELD_NAME__start[] = "start";
static char opennav_coverage_msgs__msg__Swath__FIELD_NAME__end[] = "end";

static rosidl_runtime_c__type_description__Field opennav_coverage_msgs__msg__Swath__FIELDS[] = {
  {
    {opennav_coverage_msgs__msg__Swath__FIELD_NAME__start, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point32__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {opennav_coverage_msgs__msg__Swath__FIELD_NAME__end, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point32__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription opennav_coverage_msgs__msg__Swath__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point32__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__Swath__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {opennav_coverage_msgs__msg__Swath__TYPE_NAME, 31, 31},
      {opennav_coverage_msgs__msg__Swath__FIELDS, 2, 2},
    },
    {opennav_coverage_msgs__msg__Swath__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point32__EXPECTED_HASH, geometry_msgs__msg__Point32__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point32__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "geometry_msgs/Point32 start\n"
  "geometry_msgs/Point32 end";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__Swath__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {opennav_coverage_msgs__msg__Swath__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 54, 54},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__Swath__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *opennav_coverage_msgs__msg__Swath__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point32__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
