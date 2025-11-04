// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from opennav_coverage_msgs:msg/RowSwathMode.idl
// generated code does not contain a copyright notice
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"
// Member `skip_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
opennav_coverage_msgs__msg__RowSwathMode__init(opennav_coverage_msgs__msg__RowSwathMode * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    opennav_coverage_msgs__msg__RowSwathMode__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->mode, "UNKNOWN");
    if (!success) {
      goto abort_init_0;
    }
  }
  // skip_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->skip_ids, 0)) {
    opennav_coverage_msgs__msg__RowSwathMode__fini(msg);
    return false;
  }
  // offset
  msg->offset = 0.0f;
  return true;
abort_init_0:
  return false;
}

void
opennav_coverage_msgs__msg__RowSwathMode__fini(opennav_coverage_msgs__msg__RowSwathMode * msg)
{
  if (!msg) {
    return;
  }
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // skip_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->skip_ids);
  // offset
}

bool
opennav_coverage_msgs__msg__RowSwathMode__are_equal(const opennav_coverage_msgs__msg__RowSwathMode * lhs, const opennav_coverage_msgs__msg__RowSwathMode * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // skip_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->skip_ids), &(rhs->skip_ids)))
  {
    return false;
  }
  // offset
  if (lhs->offset != rhs->offset) {
    return false;
  }
  return true;
}

bool
opennav_coverage_msgs__msg__RowSwathMode__copy(
  const opennav_coverage_msgs__msg__RowSwathMode * input,
  opennav_coverage_msgs__msg__RowSwathMode * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // skip_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->skip_ids), &(output->skip_ids)))
  {
    return false;
  }
  // offset
  output->offset = input->offset;
  return true;
}

opennav_coverage_msgs__msg__RowSwathMode *
opennav_coverage_msgs__msg__RowSwathMode__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__RowSwathMode * msg = (opennav_coverage_msgs__msg__RowSwathMode *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__RowSwathMode), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(opennav_coverage_msgs__msg__RowSwathMode));
  bool success = opennav_coverage_msgs__msg__RowSwathMode__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
opennav_coverage_msgs__msg__RowSwathMode__destroy(opennav_coverage_msgs__msg__RowSwathMode * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    opennav_coverage_msgs__msg__RowSwathMode__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
opennav_coverage_msgs__msg__RowSwathMode__Sequence__init(opennav_coverage_msgs__msg__RowSwathMode__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__RowSwathMode * data = NULL;

  if (size) {
    data = (opennav_coverage_msgs__msg__RowSwathMode *)allocator.zero_allocate(size, sizeof(opennav_coverage_msgs__msg__RowSwathMode), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = opennav_coverage_msgs__msg__RowSwathMode__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        opennav_coverage_msgs__msg__RowSwathMode__fini(&data[i - 1]);
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
opennav_coverage_msgs__msg__RowSwathMode__Sequence__fini(opennav_coverage_msgs__msg__RowSwathMode__Sequence * array)
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
      opennav_coverage_msgs__msg__RowSwathMode__fini(&array->data[i]);
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

opennav_coverage_msgs__msg__RowSwathMode__Sequence *
opennav_coverage_msgs__msg__RowSwathMode__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  opennav_coverage_msgs__msg__RowSwathMode__Sequence * array = (opennav_coverage_msgs__msg__RowSwathMode__Sequence *)allocator.allocate(sizeof(opennav_coverage_msgs__msg__RowSwathMode__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = opennav_coverage_msgs__msg__RowSwathMode__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
opennav_coverage_msgs__msg__RowSwathMode__Sequence__destroy(opennav_coverage_msgs__msg__RowSwathMode__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    opennav_coverage_msgs__msg__RowSwathMode__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
opennav_coverage_msgs__msg__RowSwathMode__Sequence__are_equal(const opennav_coverage_msgs__msg__RowSwathMode__Sequence * lhs, const opennav_coverage_msgs__msg__RowSwathMode__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!opennav_coverage_msgs__msg__RowSwathMode__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
opennav_coverage_msgs__msg__RowSwathMode__Sequence__copy(
  const opennav_coverage_msgs__msg__RowSwathMode__Sequence * input,
  opennav_coverage_msgs__msg__RowSwathMode__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(opennav_coverage_msgs__msg__RowSwathMode);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    opennav_coverage_msgs__msg__RowSwathMode * data =
      (opennav_coverage_msgs__msg__RowSwathMode *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!opennav_coverage_msgs__msg__RowSwathMode__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          opennav_coverage_msgs__msg__RowSwathMode__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!opennav_coverage_msgs__msg__RowSwathMode__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
