// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/swath__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `start`
// Member `end`
#include "geometry_msgs/msg/detail/point32__functions.h"

bool
opennav_coverage_msgs__msg__Swath__init(opennav_coverage_msgs__msg__Swath * msg)
{
  if (!msg) {
    return false;
  }
  // start
  if (!geometry_msgs__msg__Point32__init(&msg->start)) {
    opennav_coverage_msgs__msg__Swath__fini(msg);
    return false;
  }
  // end
  if (!geometry_msgs__msg__Point32__init(&msg->end)) {
    opennav_coverage_msgs__msg__Swath__fini(msg);
    return false;
  }
  return true;
}

void
opennav_coverage_msgs__msg__Swath__fini(opennav_coverage_msgs__msg__Swath * msg)
{
  if (!msg) {
    return;
  }
  // start
  geometry_msgs__msg__Point32__fini(&msg->start);
  // end
  geometry_msgs__msg__Point32__fini(&msg->end);
}

bool
opennav_coverage_msgs__msg__Swath__are_equal(const opennav_coverage_msgs__msg__Swath * lhs, const opennav_coverage_msgs__msg__Swath * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start
  if (!geometry_msgs__msg__Point32__are_equal(
      &(lhs->start), &(rhs->start)))
  {
    return false;
  }
  // end
  if (!geometry_msgs__msg__Point32__are_equal(
      &(lhs->end), &(rhs->end)))
  {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__msg__Swath__copy(
  const opennav_coverage_msgs__msg__Swath * input,
  opennav_coverage_msgs__msg__Swath * output)
{
  if (!input || !output) {
    return false;
  }
  // start
  if (!geometry_msgs__msg__Point32__copy(
      &(input->start), &(output->start)))
  {
    return false;
  }
  // end
  if (!geometry_msgs__msg__Point32__copy(
      &(input->end), &(output->end)))
  {
    return false;
  }
  return true;
}

opennav_coverage_msgs__msg__Swath *
opennav_coverage_msgs__msg__Swath__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__Swath * msg = (opennav_coverage_msgs__msg__Swath *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__Swath), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__msg__Swath));
  bool success = opennav_coverage_msgs__msg__Swath__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__msg__Swath__destroy(opennav_coverage_msgs__msg__Swath * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__msg__Swath__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__msg__Swath__Sequence__init(opennav_coverage_msgs__msg__Swath__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__Swath * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__msg__Swath *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__msg__Swath), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__msg__Swath__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__msg__Swath__fini(&data[i - 1]);
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
opennav_coverage_msgs__msg__Swath__Sequence__fini(opennav_coverage_msgs__msg__Swath__Sequence * array)
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
      opennav_coverage_msgs__msg__Swath__fini(&array->data[i]);
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

opennav_coverage_msgs__msg__Swath__Sequence *
opennav_coverage_msgs__msg__Swath__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__Swath__Sequence * array = (opennav_coverage_msgs__msg__Swath__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__Swath__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__msg__Swath__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__msg__Swath__Sequence__destroy(opennav_coverage_msgs__msg__Swath__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__msg__Swath__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__msg__Swath__Sequence__are_equal(const opennav_coverage_msgs__msg__Swath__Sequence * lhs, const opennav_coverage_msgs__msg__Swath__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__msg__Swath__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__msg__Swath__Sequence__copy(
  const opennav_coverage_msgs__msg__Swath__Sequence * input,
  opennav_coverage_msgs__msg__Swath__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__msg__Swath);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__msg__Swath * data =
      (opennav_coverage_msgs__msg__Swath *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__msg__Swath__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__msg__Swath__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__msg__Swath__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
