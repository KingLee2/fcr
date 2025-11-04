// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/path_components__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `swaths`
#include "opennav_coverage_msgs/msg/detail/swath__functions.h"
// Member `turns`
#include "nav_msgs/msg/detail/path__functions.h"

bool
opennav_coverage_msgs__msg__PathComponents__init(opennav_coverage_msgs__msg__PathComponents * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    opennav_coverage_msgs__msg__PathComponents__fini(msg);
    return false;
  }
  // swaths
  if (!opennav_coverage_msgs__msg__Swath__Sequence__init(&msg->swaths, 0)) {
    opennav_coverage_msgs__msg__PathComponents__fini(msg);
    return false;
  }
  // turns
  if (!nav_msgs__msg__Path__Sequence__init(&msg->turns, 0)) {
    opennav_coverage_msgs__msg__PathComponents__fini(msg);
    return false;
  }
  // contains_turns
  // swaths_ordered
  return true;
}

void
opennav_coverage_msgs__msg__PathComponents__fini(opennav_coverage_msgs__msg__PathComponents * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // swaths
  opennav_coverage_msgs__msg__Swath__Sequence__fini(&msg->swaths);
  // turns
  nav_msgs__msg__Path__Sequence__fini(&msg->turns);
  // contains_turns
  // swaths_ordered
}

bool
opennav_coverage_msgs__msg__PathComponents__are_equal(const opennav_coverage_msgs__msg__PathComponents * lhs, const opennav_coverage_msgs__msg__PathComponents * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // swaths
  if (!opennav_coverage_msgs__msg__Swath__Sequence__are_equal(
      &(lhs->swaths), &(rhs->swaths)))
  {
    return false;
  }
  // turns
  if (!nav_msgs__msg__Path__Sequence__are_equal(
      &(lhs->turns), &(rhs->turns)))
  {
    return false;
  }
  // contains_turns
  if (lhs->contains_turns != rhs->contains_turns) {
    return false;
  }
  // swaths_ordered
  if (lhs->swaths_ordered != rhs->swaths_ordered) {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__msg__PathComponents__copy(
  const opennav_coverage_msgs__msg__PathComponents * input,
  opennav_coverage_msgs__msg__PathComponents * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // swaths
  if (!opennav_coverage_msgs__msg__Swath__Sequence__copy(
      &(input->swaths), &(output->swaths)))
  {
    return false;
  }
  // turns
  if (!nav_msgs__msg__Path__Sequence__copy(
      &(input->turns), &(output->turns)))
  {
    return false;
  }
  // contains_turns
  output->contains_turns = input->contains_turns;
  // swaths_ordered
  output->swaths_ordered = input->swaths_ordered;
  return true;
}

opennav_coverage_msgs__msg__PathComponents *
opennav_coverage_msgs__msg__PathComponents__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__PathComponents * msg = (opennav_coverage_msgs__msg__PathComponents *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__PathComponents), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__msg__PathComponents));
  bool success = opennav_coverage_msgs__msg__PathComponents__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__msg__PathComponents__destroy(opennav_coverage_msgs__msg__PathComponents * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__msg__PathComponents__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__msg__PathComponents__Sequence__init(opennav_coverage_msgs__msg__PathComponents__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__PathComponents * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__msg__PathComponents *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__msg__PathComponents), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__msg__PathComponents__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__msg__PathComponents__fini(&data[i - 1]);
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
opennav_coverage_msgs__msg__PathComponents__Sequence__fini(opennav_coverage_msgs__msg__PathComponents__Sequence * array)
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
      opennav_coverage_msgs__msg__PathComponents__fini(&array->data[i]);
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

opennav_coverage_msgs__msg__PathComponents__Sequence *
opennav_coverage_msgs__msg__PathComponents__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__PathComponents__Sequence * array = (opennav_coverage_msgs__msg__PathComponents__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__PathComponents__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__msg__PathComponents__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__msg__PathComponents__Sequence__destroy(opennav_coverage_msgs__msg__PathComponents__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__msg__PathComponents__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__msg__PathComponents__Sequence__are_equal(const opennav_coverage_msgs__msg__PathComponents__Sequence * lhs, const opennav_coverage_msgs__msg__PathComponents__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__msg__PathComponents__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__msg__PathComponents__Sequence__copy(
  const opennav_coverage_msgs__msg__PathComponents__Sequence * input,
  opennav_coverage_msgs__msg__PathComponents__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__msg__PathComponents);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__msg__PathComponents * data =
      (opennav_coverage_msgs__msg__PathComponents *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__msg__PathComponents__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__msg__PathComponents__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__msg__PathComponents__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
