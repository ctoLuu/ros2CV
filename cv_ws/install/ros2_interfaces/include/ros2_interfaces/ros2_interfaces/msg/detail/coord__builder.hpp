// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interfaces/msg/detail/coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coord_flag_servo
{
public:
  explicit Init_Coord_flag_servo(::ros2_interfaces::msg::Coord & msg)
  : msg_(msg)
  {}
  ::ros2_interfaces::msg::Coord flag_servo(::ros2_interfaces::msg::Coord::_flag_servo_type arg)
  {
    msg_.flag_servo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interfaces::msg::Coord msg_;
};

class Init_Coord_y
{
public:
  explicit Init_Coord_y(::ros2_interfaces::msg::Coord & msg)
  : msg_(msg)
  {}
  Init_Coord_flag_servo y(::ros2_interfaces::msg::Coord::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Coord_flag_servo(msg_);
  }

private:
  ::ros2_interfaces::msg::Coord msg_;
};

class Init_Coord_x
{
public:
  Init_Coord_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coord_y x(::ros2_interfaces::msg::Coord::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Coord_y(msg_);
  }

private:
  ::ros2_interfaces::msg::Coord msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interfaces::msg::Coord>()
{
  return ros2_interfaces::msg::builder::Init_Coord_x();
}

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
