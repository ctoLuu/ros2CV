// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from topic_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "topic_interfaces/msg/detail/coord__rosidl_typesupport_introspection_c.h"
#include "topic_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "topic_interfaces/msg/detail/coord__functions.h"
#include "topic_interfaces/msg/detail/coord__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  topic_interfaces__msg__Coord__init(message_memory);
}

void topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_fini_function(void * message_memory)
{
  topic_interfaces__msg__Coord__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(topic_interfaces__msg__Coord, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(topic_interfaces__msg__Coord, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flag_servo",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(topic_interfaces__msg__Coord, flag_servo),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_members = {
  "topic_interfaces__msg",  // message namespace
  "Coord",  // message name
  3,  // number of fields
  sizeof(topic_interfaces__msg__Coord),
  topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_member_array,  // message members
  topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_init_function,  // function to initialize message memory (memory has to be allocated)
  topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_type_support_handle = {
  0,
  &topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_topic_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, topic_interfaces, msg, Coord)() {
  if (!topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_type_support_handle.typesupport_identifier) {
    topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &topic_interfaces__msg__Coord__rosidl_typesupport_introspection_c__Coord_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
