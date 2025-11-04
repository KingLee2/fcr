// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from opennav_coverage_msgs:action/NavigateCompleteCoverage.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `field_filepath`
// Member `frame_id`
// Member `behavior_tree`
#include "rosidl_runtime_c/string_functions.h"
// Member `polygons`
#include "geometry_msgs/msg/detail/polygon__functions.h"

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // field_filepath
  if (!rosidl_runtime_c__String__init(&msg->field_filepath)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(msg);
    return false;
  }
  // polygons
  if (!geometry_msgs__msg__Polygon__Sequence__init(&msg->polygons, 0)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(msg);
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__init(&msg->frame_id)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->frame_id, "map");
    if (!success) {
      goto abort_init_0;
    }
  }
  // behavior_tree
  if (!rosidl_runtime_c__String__init(&msg->behavior_tree)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(msg);
    return false;
  }
  return true;
abort_init_0:
  return false;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * msg)
{
  if (!msg) {
    return;
  }
  // field_filepath
  rosidl_runtime_c__String__fini(&msg->field_filepath);
  // polygons
  geometry_msgs__msg__Polygon__Sequence__fini(&msg->polygons);
  // frame_id
  rosidl_runtime_c__String__fini(&msg->frame_id);
  // behavior_tree
  rosidl_runtime_c__String__fini(&msg->behavior_tree);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // field_filepath
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->field_filepath), &(rhs->field_filepath)))
  {
    return false;
  }
  // polygons
  if (!geometry_msgs__msg__Polygon__Sequence__are_equal(
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
  // behavior_tree
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->behavior_tree), &(rhs->behavior_tree)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // field_filepath
  if (!rosidl_runtime_c__String__copy(
      &(input->field_filepath), &(output->field_filepath)))
  {
    return false;
  }
  // polygons
  if (!geometry_msgs__msg__Polygon__Sequence__copy(
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
  // behavior_tree
  if (!rosidl_runtime_c__String__copy(
      &(input->behavior_tree), &(output->behavior_tree)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal *
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * msg)
{
  if (!msg) {
    return false;
  }
  // error_code
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * msg)
{
  if (!msg) {
    return;
  }
  // error_code
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // error_code
  output->error_code = input->error_code;
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_Result *
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Result *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Result *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `navigation_time`
// Member `estimated_time_remaining`
#include "builtin_interfaces/msg/detail/duration__functions.h"

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->current_pose)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(msg);
    return false;
  }
  // navigation_time
  if (!builtin_interfaces__msg__Duration__init(&msg->navigation_time)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(msg);
    return false;
  }
  // estimated_time_remaining
  if (!builtin_interfaces__msg__Duration__init(&msg->estimated_time_remaining)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(msg);
    return false;
  }
  // number_of_recoveries
  // distance_remaining
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->current_pose);
  // navigation_time
  builtin_interfaces__msg__Duration__fini(&msg->navigation_time);
  // estimated_time_remaining
  builtin_interfaces__msg__Duration__fini(&msg->estimated_time_remaining);
  // number_of_recoveries
  // distance_remaining
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->current_pose), &(rhs->current_pose)))
  {
    return false;
  }
  // navigation_time
  if (!builtin_interfaces__msg__Duration__are_equal(
      &(lhs->navigation_time), &(rhs->navigation_time)))
  {
    return false;
  }
  // estimated_time_remaining
  if (!builtin_interfaces__msg__Duration__are_equal(
      &(lhs->estimated_time_remaining), &(rhs->estimated_time_remaining)))
  {
    return false;
  }
  // number_of_recoveries
  if (lhs->number_of_recoveries != rhs->number_of_recoveries) {
    return false;
  }
  // distance_remaining
  if (lhs->distance_remaining != rhs->distance_remaining) {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->current_pose), &(output->current_pose)))
  {
    return false;
  }
  // navigation_time
  if (!builtin_interfaces__msg__Duration__copy(
      &(input->navigation_time), &(output->navigation_time)))
  {
    return false;
  }
  // estimated_time_remaining
  if (!builtin_interfaces__msg__Duration__copy(
      &(input->estimated_time_remaining), &(output->estimated_time_remaining)))
  {
    return false;
  }
  // number_of_recoveries
  output->number_of_recoveries = input->number_of_recoveries;
  // distance_remaining
  output->distance_remaining = input->distance_remaining;
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback *
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__copy(
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
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__init(&msg->goal)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__fini(&msg->goal);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * rhs)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * output)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__copy(
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * rhs)
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * output)
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__copy(
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
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * rhs)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * output)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event *
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__copy(
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * rhs)
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * output)
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__copy(
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
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__init(&msg->result)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__fini(&msg->result);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__copy(
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
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__init(&msg->request, 0)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__init(&msg->response, 0)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__fini(&msg->request);
  // response
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__fini(&msg->response);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * rhs)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * output)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event *
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__copy(
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
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__functions.h"

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__init(&msg->feedback)) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__fini(&msg->feedback);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * rhs)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * output)
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
  if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage *
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * msg = (opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage));
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__init(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(&data[i - 1]);
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
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__fini(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * array)
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
      opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(&array->data[i]);
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

opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence *
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * array = (opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__destroy(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__are_equal(const opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * lhs, const opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence__copy(
  const opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * input,
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * data =
      (opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
