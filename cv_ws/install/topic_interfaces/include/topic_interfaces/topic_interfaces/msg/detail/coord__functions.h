// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from topic_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#ifndef TOPIC_INTERFACES__MSG__DETAIL__COORD__FUNCTIONS_H_
#define TOPIC_INTERFACES__MSG__DETAIL__COORD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "topic_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "topic_interfaces/msg/detail/coord__struct.h"

/// Initialize msg/Coord message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * topic_interfaces__msg__Coord
 * )) before or use
 * topic_interfaces__msg__Coord__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
bool
topic_interfaces__msg__Coord__init(topic_interfaces__msg__Coord * msg);

/// Finalize msg/Coord message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
void
topic_interfaces__msg__Coord__fini(topic_interfaces__msg__Coord * msg);

/// Create msg/Coord message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * topic_interfaces__msg__Coord__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
topic_interfaces__msg__Coord *
topic_interfaces__msg__Coord__create();

/// Destroy msg/Coord message.
/**
 * It calls
 * topic_interfaces__msg__Coord__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
void
topic_interfaces__msg__Coord__destroy(topic_interfaces__msg__Coord * msg);

/// Check for msg/Coord message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
bool
topic_interfaces__msg__Coord__are_equal(const topic_interfaces__msg__Coord * lhs, const topic_interfaces__msg__Coord * rhs);

/// Copy a msg/Coord message.
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
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
bool
topic_interfaces__msg__Coord__copy(
  const topic_interfaces__msg__Coord * input,
  topic_interfaces__msg__Coord * output);

/// Initialize array of msg/Coord messages.
/**
 * It allocates the memory for the number of elements and calls
 * topic_interfaces__msg__Coord__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
bool
topic_interfaces__msg__Coord__Sequence__init(topic_interfaces__msg__Coord__Sequence * array, size_t size);

/// Finalize array of msg/Coord messages.
/**
 * It calls
 * topic_interfaces__msg__Coord__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
void
topic_interfaces__msg__Coord__Sequence__fini(topic_interfaces__msg__Coord__Sequence * array);

/// Create array of msg/Coord messages.
/**
 * It allocates the memory for the array and calls
 * topic_interfaces__msg__Coord__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
topic_interfaces__msg__Coord__Sequence *
topic_interfaces__msg__Coord__Sequence__create(size_t size);

/// Destroy array of msg/Coord messages.
/**
 * It calls
 * topic_interfaces__msg__Coord__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
void
topic_interfaces__msg__Coord__Sequence__destroy(topic_interfaces__msg__Coord__Sequence * array);

/// Check for msg/Coord message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
bool
topic_interfaces__msg__Coord__Sequence__are_equal(const topic_interfaces__msg__Coord__Sequence * lhs, const topic_interfaces__msg__Coord__Sequence * rhs);

/// Copy an array of msg/Coord messages.
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
ROSIDL_GENERATOR_C_PUBLIC_topic_interfaces
bool
topic_interfaces__msg__Coord__Sequence__copy(
  const topic_interfaces__msg__Coord__Sequence * input,
  topic_interfaces__msg__Coord__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TOPIC_INTERFACES__MSG__DETAIL__COORD__FUNCTIONS_H_
