// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from topic_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#ifndef TOPIC_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
#define TOPIC_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "topic_interfaces/msg/detail/coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace topic_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coord_flag_servo
{
public:
  explicit Init_Coord_flag_servo(::topic_interfaces::msg::Coord & msg)
  : msg_(msg)
  {}
  ::topic_interfaces::msg::Coord flag_servo(::topic_interfaces::msg::Coord::_flag_servo_type arg)
  {
    msg_.flag_servo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::topic_interfaces::msg::Coord msg_;
};

class Init_Coord_y
{
public:
  explicit Init_Coord_y(::topic_interfaces::msg::Coord & msg)
  : msg_(msg)
  {}
  Init_Coord_flag_servo y(::topic_interfaces::msg::Coord::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Coord_flag_servo(msg_);
  }

private:
  ::topic_interfaces::msg::Coord msg_;
};

class Init_Coord_x
{
public:
  Init_Coord_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coord_y x(::topic_interfaces::msg::Coord::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Coord_y(msg_);
  }

private:
  ::topic_interfaces::msg::Coord msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::topic_interfaces::msg::Coord>()
{
  return topic_interfaces::msg::builder::Init_Coord_x();
}

}  // namespace topic_interfaces

#endif  // TOPIC_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
