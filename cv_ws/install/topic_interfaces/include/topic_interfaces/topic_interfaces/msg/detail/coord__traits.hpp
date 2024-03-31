// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from topic_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#ifndef TOPIC_INTERFACES__MSG__DETAIL__COORD__TRAITS_HPP_
#define TOPIC_INTERFACES__MSG__DETAIL__COORD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "topic_interfaces/msg/detail/coord__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace topic_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Coord & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: flag_servo
  {
    out << "flag_servo: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_servo, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Coord & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: flag_servo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag_servo: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_servo, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Coord & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace topic_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use topic_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const topic_interfaces::msg::Coord & msg,
  std::ostream & out, size_t indentation = 0)
{
  topic_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use topic_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const topic_interfaces::msg::Coord & msg)
{
  return topic_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<topic_interfaces::msg::Coord>()
{
  return "topic_interfaces::msg::Coord";
}

template<>
inline const char * name<topic_interfaces::msg::Coord>()
{
  return "topic_interfaces/msg/Coord";
}

template<>
struct has_fixed_size<topic_interfaces::msg::Coord>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<topic_interfaces::msg::Coord>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<topic_interfaces::msg::Coord>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TOPIC_INTERFACES__MSG__DETAIL__COORD__TRAITS_HPP_
