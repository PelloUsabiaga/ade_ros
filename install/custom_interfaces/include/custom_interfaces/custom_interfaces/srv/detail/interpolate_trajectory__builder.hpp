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

class Init_InterpolateTrajectory_Request_current_position
{
public:
  explicit Init_InterpolateTrajectory_Request_current_position(::custom_interfaces::srv::InterpolateTrajectory_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::InterpolateTrajectory_Request current_position(::custom_interfaces::srv::InterpolateTrajectory_Request::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Request msg_;
};

class Init_InterpolateTrajectory_Request_speed
{
public:
  explicit Init_InterpolateTrajectory_Request_speed(::custom_interfaces::srv::InterpolateTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_InterpolateTrajectory_Request_current_position speed(::custom_interfaces::srv::InterpolateTrajectory_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_InterpolateTrajectory_Request_current_position(msg_);
  }

private:
  ::custom_interfaces::srv::InterpolateTrajectory_Request msg_;
};

class Init_InterpolateTrajectory_Request_position
{
public:
  Init_InterpolateTrajectory_Request_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InterpolateTrajectory_Request_speed position(::custom_interfaces::srv::InterpolateTrajectory_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_InterpolateTrajectory_Request_speed(msg_);
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
  return custom_interfaces::srv::builder::Init_InterpolateTrajectory_Request_position();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_InterpolateTrajectory_Response_status
{
public:
  Init_InterpolateTrajectory_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::InterpolateTrajectory_Response status(::custom_interfaces::srv::InterpolateTrajectory_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
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
  return custom_interfaces::srv::builder::Init_InterpolateTrajectory_Response_status();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__BUILDER_HPP_
