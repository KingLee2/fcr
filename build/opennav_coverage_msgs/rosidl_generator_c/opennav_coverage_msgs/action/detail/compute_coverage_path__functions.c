// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from opennav_coverage_msgs:action/ComputeCoveragePath.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/action/detail/compute_coverage_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `gml_field`
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `polygons`
#include "opennav_coverage_msgs/msg/detail/coordinates__functions.h"
// Member `headland_mode`
#include "opennav_coverage_msgs/msg/detail/headland_mode__functions.h"
// Member `swath_mode`
#include "opennav_coverage_msgs/msg/detail/swath_mode__functions.h"
// Member `row_swath_mode`
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__functions.h"
// Member `route_mode`
#include "opennav_coverage_msgs/msg/detail/route_mode__functions.h"
// Member `path_mode`
#include "opennav_coverage_msgs/msg/detail/path_mode__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__init(opennav_coverage_msgs__action__ComputeCoveragePath_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // generate_headland
  msg->generate_headland = true;
  // generate_route
  msg->generate_route = true;
  // generate_path
  msg->generate_path = true;
  // use_gml_file
  msg->use_gml_file = false;
  // gml_field
  if (!rosidl_runtime_c__String__init(&msg->gml_field)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  // polygons
  if (!opennav_coverage_msgs__msg__Coordinates__Sequence__init(&msg->polygons, 0)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__init(&msg->frame_id)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->frame_id, "map");
    if (!success) {
      goto abort_init_0;
    }
  }
  // headland_mode
  if (!opennav_coverage_msgs__msg__HeadlandMode__init(&msg->headland_mode)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  // swath_mode
  if (!opennav_coverage_msgs__msg__SwathMode__init(&msg->swath_mode)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  // row_swath_mode
  if (!opennav_coverage_msgs__msg__RowSwathMode__init(&msg->row_swath_mode)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  // route_mode
  if (!opennav_coverage_msgs__msg__RouteMode__init(&msg->route_mode)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  // path_mode
  if (!opennav_coverage_msgs__msg__PathMode__init(&msg->path_mode)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
    return false;
  }
  return true;
abort_init_0:
  return false;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(opennav_coverage_msgs__action__ComputeCoveragePath_Goal * msg)
{
  if (!msg) {
    return;
  }
  // generate_headland
  // generate_route
  // generate_path
  // use_gml_file
  // gml_field
  rosidl_runtime_c__String__fini(&msg->gml_field);
  // polygons
  opennav_coverage_msgs__msg__Coordinates__Sequence__fini(&msg->polygons);
  // frame_id
  rosidl_runtime_c__String__fini(&msg->frame_id);
  // headland_mode
  opennav_coverage_msgs__msg__HeadlandMode__fini(&msg->headland_mode);
  // swath_mode
  opennav_coverage_msgs__msg__SwathMode__fini(&msg->swath_mode);
  // row_swath_mode
  opennav_coverage_msgs__msg__RowSwathMode__fini(&msg->row_swath_mode);
  // route_mode
  opennav_coverage_msgs__msg__RouteMode__fini(&msg->route_mode);
  // path_mode
  opennav_coverage_msgs__msg__PathMode__fini(&msg->path_mode);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_Goal * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // generate_headland
  if (lhs->generate_headland != rhs->generate_headland) {
    return false;
  }
  // generate_route
  if (lhs->generate_route != rhs->generate_route) {
    return false;
  }
  // generate_path
  if (lhs->generate_path != rhs->generate_path) {
    return false;
  }
  // use_gml_file
  if (lhs->use_gml_file != rhs->use_gml_file) {
    return false;
  }
  // gml_field
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->gml_field), &(rhs->gml_field)))
  {
    return false;
  }
  // polygons
  if (!opennav_coverage_msgs__msg__Coordinates__Sequence__are_equal(
      &(lhs->polygons), &(rhs->polygons)))
  {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_id), &(rhs->frame_id)))
  {
    return false;
  }
  // headland_mode
  if (!opennav_coverage_msgs__msg__HeadlandMode__are_equal(
      &(lhs->headland_mode), &(rhs->headland_mode)))
  {
    return false;
  }
  // swath_mode
  if (!opennav_coverage_msgs__msg__SwathMode__are_equal(
      &(lhs->swath_mode), &(rhs->swath_mode)))
  {
    return false;
  }
  // row_swath_mode
  if (!opennav_coverage_msgs__msg__RowSwathMode__are_equal(
      &(lhs->row_swath_mode), &(rhs->row_swath_mode)))
  {
    return false;
  }
  // route_mode
  if (!opennav_coverage_msgs__msg__RouteMode__are_equal(
      &(lhs->route_mode), &(rhs->route_mode)))
  {
    return false;
  }
  // path_mode
  if (!opennav_coverage_msgs__msg__PathMode__are_equal(
      &(lhs->path_mode), &(rhs->path_mode)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_Goal * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // generate_headland
  output->generate_headland = input->generate_headland;
  // generate_route
  output->generate_route = input->generate_route;
  // generate_path
  output->generate_path = input->generate_path;
  // use_gml_file
  output->use_gml_file = input->use_gml_file;
  // gml_field
  if (!rosidl_runtime_c__String__copy(
      &(input->gml_field), &(output->gml_field)))
  {
    return false;
  }
  // polygons
  if (!opennav_coverage_msgs__msg__Coordinates__Sequence__copy(
      &(input->polygons), &(output->polygons)))
  {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_id), &(output->frame_id)))
  {
    return false;
  }
  // headland_mode
  if (!opennav_coverage_msgs__msg__HeadlandMode__copy(
      &(input->headland_mode), &(output->headland_mode)))
  {
    return false;
  }
  // swath_mode
  if (!opennav_coverage_msgs__msg__SwathMode__copy(
      &(input->swath_mode), &(output->swath_mode)))
  {
    return false;
  }
  // row_swath_mode
  if (!opennav_coverage_msgs__msg__RowSwathMode__copy(
      &(input->row_swath_mode), &(output->row_swath_mode)))
  {
    return false;
  }
  // route_mode
  if (!opennav_coverage_msgs__msg__RouteMode__copy(
      &(input->route_mode), &(output->route_mode)))
  {
    return false;
  }
  // path_mode
  if (!opennav_coverage_msgs__msg__PathMode__copy(
      &(input->path_mode), &(output->path_mode)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_Goal *
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_Goal *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Goal));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_Goal *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_Goal * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `nav_path`
#include "nav_msgs/msg/detail/path__functions.h"
// Member `coverage_path`
#include "opennav_coverage_msgs/msg/detail/path_components__functions.h"
// Member `planning_time`
#include "builtin_interfaces/msg/detail/duration__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Result__init(opennav_coverage_msgs__action__ComputeCoveragePath_Result * msg)
{
  if (!msg) {
    return false;
  }
  // nav_path
  if (!nav_msgs__msg__Path__init(&msg->nav_path)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(msg);
    return false;
  }
  // coverage_path
  if (!opennav_coverage_msgs__msg__PathComponents__init(&msg->coverage_path)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(msg);
    return false;
  }
  // planning_time
  if (!builtin_interfaces__msg__Duration__init(&msg->planning_time)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(msg);
    return false;
  }
  // error_code
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(opennav_coverage_msgs__action__ComputeCoveragePath_Result * msg)
{
  if (!msg) {
    return;
  }
  // nav_path
  nav_msgs__msg__Path__fini(&msg->nav_path);
  // coverage_path
  opennav_coverage_msgs__msg__PathComponents__fini(&msg->coverage_path);
  // planning_time
  builtin_interfaces__msg__Duration__fini(&msg->planning_time);
  // error_code
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Result__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_Result * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // nav_path
  if (!nav_msgs__msg__Path__are_equal(
      &(lhs->nav_path), &(rhs->nav_path)))
  {
    return false;
  }
  // coverage_path
  if (!opennav_coverage_msgs__msg__PathComponents__are_equal(
      &(lhs->coverage_path), &(rhs->coverage_path)))
  {
    return false;
  }
  // planning_time
  if (!builtin_interfaces__msg__Duration__are_equal(
      &(lhs->planning_time), &(rhs->planning_time)))
  {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Result__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_Result * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // nav_path
  if (!nav_msgs__msg__Path__copy(
      &(input->nav_path), &(output->nav_path)))
  {
    return false;
  }
  // coverage_path
  if (!opennav_coverage_msgs__msg__PathComponents__copy(
      &(input->coverage_path), &(output->coverage_path)))
  {
    return false;
  }
  // planning_time
  if (!builtin_interfaces__msg__Duration__copy(
      &(input->planning_time), &(output->planning_time)))
  {
    return false;
  }
  // error_code
  output->error_code = input->error_code;
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_Result *
opennav_coverage_msgs__action__ComputeCoveragePath_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Result * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_Result *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Result));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Result__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Result * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_Result *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_Result * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__init(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__fini(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_Feedback *
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_Feedback *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_Feedback *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__init(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Goal__init(&msg->goal)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__fini(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal__fini(&msg->goal);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request *
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__init(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__fini(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response *
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__init(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event *
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__init(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__fini(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request *
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__init(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Result__init(&msg->result)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__fini(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__fini(&msg->result);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response *
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__init(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__init(&msg->request, 0)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__init(&msg->response, 0)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__fini(&msg->request);
  // response
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__fini(&msg->response);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event *
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__functions.h"

bool
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__init(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__init(&msg->feedback)) {
    opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__fini(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__fini(&msg->feedback);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage *
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * msg = (opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage));
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__init(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__fini(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence *
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * array = (opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__destroy(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__are_equal(const opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * lhs, const opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence__copy(
  const opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * input,
  opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * data =
      (opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
