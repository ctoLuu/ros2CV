// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from topic_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#ifndef TOPIC_INTERFACES__MSG__DETAIL__COORD__STRUCT_H_
#define TOPIC_INTERFACES__MSG__DETAIL__COORD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Coord in the package topic_interfaces.
typedef struct topic_interfaces__msg__Coord
{
  int32_t x;
  int32_t y;
  int32_t flag_servo;
} topic_interfaces__msg__Coord;

// Struct for a sequence of topic_interfaces__msg__Coord.
typedef struct topic_interfaces__msg__Coord__Sequence
{
  topic_interfaces__msg__Coord * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} topic_interfaces__msg__Coord__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOPIC_INTERFACES__MSG__DETAIL__COORD__STRUCT_H_
