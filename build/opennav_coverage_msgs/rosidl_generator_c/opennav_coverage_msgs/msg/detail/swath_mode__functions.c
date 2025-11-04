// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from opennav_coverage_msgs:msg/SwathMode.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/swath_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `objective`
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
opennav_coverage_msgs__msg__SwathMode__init(opennav_coverage_msgs__msg__SwathMode * msg)
{
  if (!msg) {
    return false;
  }
  // objective
  if (!rosidl_runtime_c__String__init(&msg->objective)) {
    opennav_coverage_msgs__msg__SwathMode__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->objective, "UNKNOWN");
    if (!success) {
      goto abort_init_0;
    }
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    opennav_coverage_msgs__msg__SwathMode__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->mode, "UNKNOWN");
    if (!success) {
      goto abort_init_1;
    }
  }
  // best_angle
  msg->best_angle = 0.0f;
  // step_angle
  msg->step_angle = 0.017453f;
  return true;
abort_init_1:
  rosidl_runtime_c__String__fini(&msg->objective);
abort_init_0:
  return false;
}

void
opennav_coverage_msgs__msg__SwathMode__fini(opennav_coverage_msgs__msg__SwathMode * msg)
{
  if (!msg) {
    return;
  }
  // objective
  rosidl_runtime_c__String__fini(&msg->objective);
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // best_angle
  // step_angle
}

bool
opennav_coverage_msgs__msg__SwathMode__are_equal(const opennav_coverage_msgs__msg__SwathMode * lhs, const opennav_coverage_msgs__msg__SwathMode * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // objective
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->objective), &(rhs->objective)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // best_angle
  if (lhs->best_angle != rhs->best_angle) {
    return false;
  }
  // step_angle
  if (lhs->step_angle != rhs->step_angle) {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__msg__SwathMode__copy(
  const opennav_coverage_msgs__msg__SwathMode * input,
  opennav_coverage_msgs__msg__SwathMode * output)
{
  if (!input || !output) {
    return false;
  }
  // objective
  if (!rosidl_runtime_c__String__copy(
      &(input->objective), &(output->objective)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // best_angle
  output->best_angle = input->best_angle;
  // step_angle
  output->step_angle = input->step_angle;
  return true;
}

opennav_coverage_msgs__msg__SwathMode *
opennav_coverage_msgs__msg__SwathMode__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__SwathMode * msg = (opennav_coverage_msgs__msg__SwathMode *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__SwathMode), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__msg__SwathMode));
  bool success = opennav_coverage_msgs__msg__SwathMode__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__msg__SwathMode__destroy(opennav_coverage_msgs__msg__SwathMode * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__msg__SwathMode__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__msg__SwathMode__Sequence__init(opennav_coverage_msgs__msg__SwathMode__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__SwathMode * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__msg__SwathMode *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__msg__SwathMode), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__msg__SwathMode__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__msg__SwathMode__fini(&data[i - 1]);
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
opennav_coverage_msgs__msg__SwathMode__Sequence__fini(opennav_coverage_msgs__msg__SwathMode__Sequence * array)
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
      opennav_coverage_msgs__msg__SwathMode__fini(&array->data[i]);
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

opennav_coverage_msgs__msg__SwathMode__Sequence *
opennav_coverage_msgs__msg__SwathMode__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__SwathMode__Sequence * array = (opennav_coverage_msgs__msg__SwathMode__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__SwathMode__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__msg__SwathMode__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__msg__SwathMode__Sequence__destroy(opennav_coverage_msgs__msg__SwathMode__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__msg__SwathMode__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__msg__SwathMode__Sequence__are_equal(const opennav_coverage_msgs__msg__SwathMode__Sequence * lhs, const opennav_coverage_msgs__msg__SwathMode__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__msg__SwathMode__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__msg__SwathMode__Sequence__copy(
  const opennav_coverage_msgs__msg__SwathMode__Sequence * input,
  opennav_coverage_msgs__msg__SwathMode__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__msg__SwathMode);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__msg__SwathMode * data =
      (opennav_coverage_msgs__msg__SwathMode *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__msg__SwathMode__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__msg__SwathMode__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__msg__SwathMode__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
