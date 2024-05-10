// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/InterpolateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/interpolate_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_InterpolateTrajectory_Request_points
{
public:
  explicit Init_InterpolateTrajectory_Request_points(::custom_interfaces::srv::InterpolateTrajectory_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::InterpolateTrajectory_Request points(::custom_interfaces::srv::InterpolateTrajectory_Request::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Request msg_;
};

class Init_InterpolateTrajectory_Request_mean_speed
{
public:
  explicit Init_InterpolateTrajectory_Request_mean_speed(::custom_interfaces::srv::InterpolateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_InterpolateTrajectory_Request_points mean_speed(::custom_interfaces::srv::InterpolateTrajectory_Request::_mean_speed_type arg)
  {
    msg_.mean_speed = std::move(arg);
    return Init_InterpolateTrajectory_Request_points(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Request msg_;
};

class Init_InterpolateTrajectory_Request_target_position
{
public:
  explicit Init_InterpolateTrajectory_Request_target_position(::custom_interfaces::srv::InterpolateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_InterpolateTrajectory_Request_mean_speed target_position(::custom_interfaces::srv::InterpolateTrajectory_Request::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return Init_InterpolateTrajectory_Request_mean_speed(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Request msg_;
};

class Init_InterpolateTrajectory_Request_current_position
{
public:
  Init_InterpolateTrajectory_Request_current_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InterpolateTrajectory_Request_target_position current_position(::custom_interfaces::srv::InterpolateTrajectory_Request::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return Init_InterpolateTrajectory_Request_target_position(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::InterpolateTrajectory_Request>()
{
  return custom_interfaces::srv::builder::Init_InterpolateTrajectory_Request_current_position();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_InterpolateTrajectory_Response_times
{
public:
  explicit Init_InterpolateTrajectory_Response_times(::custom_interfaces::srv::InterpolateTrajectory_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::InterpolateTrajectory_Response times(::custom_interfaces::srv::InterpolateTrajectory_Response::_times_type arg)
  {
    msg_.times = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Response msg_;
};

class Init_InterpolateTrajectory_Response_positions
{
public:
  Init_InterpolateTrajectory_Response_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InterpolateTrajectory_Response_times positions(::custom_interfaces::srv::InterpolateTrajectory_Response::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return Init_InterpolateTrajectory_Response_times(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::InterpolateTrajectory_Response>()
{
  return custom_interfaces::srv::builder::Init_InterpolateTrajectory_Response_positions();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__BUILDER_HPP_
