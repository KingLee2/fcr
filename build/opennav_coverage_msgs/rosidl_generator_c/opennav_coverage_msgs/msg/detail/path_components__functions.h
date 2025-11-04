// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_components.h"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__FUNCTIONS_H_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "opennav_coverage_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "opennav_coverage_msgs/msg/detail/path_components__struct.h"

/// Initialize msg/PathComponents message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * opennav_coverage_msgs__msg__PathComponents
 * )) before or use
 * opennav_coverage_msgs__msg__PathComponents__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
bool
opennav_coverage_msgs__msg__PathComponents__init(opennav_coverage_msgs__msg__PathComponents * msg);

/// Finalize msg/PathComponents message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
void
opennav_coverage_msgs__msg__PathComponents__fini(opennav_coverage_msgs__msg__PathComponents * msg);

/// Create msg/PathComponents message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * opennav_coverage_msgs__msg__PathComponents__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
opennav_coverage_msgs__msg__PathComponents *
opennav_coverage_msgs__msg__PathComponents__create(void);

/// Destroy msg/PathComponents message.
/**
 * It calls
 * opennav_coverage_msgs__msg__PathComponents__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
void
opennav_coverage_msgs__msg__PathComponents__destroy(opennav_coverage_msgs__msg__PathComponents * msg);

/// Check for msg/PathComponents message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
bool
opennav_coverage_msgs__msg__PathComponents__are_equal(const opennav_coverage_msgs__msg__PathComponents * lhs, const opennav_coverage_msgs__msg__PathComponents * rhs);

/// Copy a msg/PathComponents message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
bool
opennav_coverage_msgs__msg__PathComponents__copy(
  const opennav_coverage_msgs__msg__PathComponents * input,
  opennav_coverage_msgs__msg__PathComponents * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_type_hash_t *
opennav_coverage_msgs__msg__PathComponents__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_runtime_c__type_description__TypeDescription *
opennav_coverage_msgs__msg__PathComponents__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_runtime_c__type_description__TypeSource *
opennav_coverage_msgs__msg__PathComponents__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
opennav_coverage_msgs__msg__PathComponents__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/PathComponents messages.
/**
 * It allocates the memory for the number of elements and calls
 * opennav_coverage_msgs__msg__PathComponents__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
bool
opennav_coverage_msgs__msg__PathComponents__Sequence__init(opennav_coverage_msgs__msg__PathComponents__Sequence * array, size_t size);

/// Finalize array of msg/PathComponents messages.
/**
 * It calls
 * opennav_coverage_msgs__msg__PathComponents__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
void
opennav_coverage_msgs__msg__PathComponents__Sequence__fini(opennav_coverage_msgs__msg__PathComponents__Sequence * array);

/// Create array of msg/PathComponents messages.
/**
 * It allocates the memory for the array and calls
 * opennav_coverage_msgs__msg__PathComponents__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
opennav_coverage_msgs__msg__PathComponents__Sequence *
opennav_coverage_msgs__msg__PathComponents__Sequence__create(size_t size);

/// Destroy array of msg/PathComponents messages.
/**
 * It calls
 * opennav_coverage_msgs__msg__PathComponents__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
void
opennav_coverage_msgs__msg__PathComponents__Sequence__destroy(opennav_coverage_msgs__msg__PathComponents__Sequence * array);

/// Check for msg/PathComponents message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
bool
opennav_coverage_msgs__msg__PathComponents__Sequence__are_equal(const opennav_coverage_msgs__msg__PathComponents__Sequence * lhs, const opennav_coverage_msgs__msg__PathComponents__Sequence * rhs);

/// Copy an array of msg/PathComponents messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_opennav_coverage_msgs
bool
opennav_coverage_msgs__msg__PathComponents__Sequence__copy(
  const opennav_coverage_msgs__msg__PathComponents__Sequence * input,
  opennav_coverage_msgs__msg__PathComponents__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__FUNCTIONS_H_
