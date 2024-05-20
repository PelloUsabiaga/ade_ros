// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/PointsToSerial.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/points_to_serial__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_PointsToSerial_Request_n_points
{
public:
  explicit Init_PointsToSerial_Request_n_points(::custom_interfaces::srv::PointsToSerial_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::PointsToSerial_Request n_points(::custom_interfaces::srv::PointsToSerial_Request::_n_points_type arg)
  {
    msg_.n_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::PointsToSerial_Request msg_;
};

class Init_PointsToSerial_Request_times
{
public:
  explicit Init_PointsToSerial_Request_times(::custom_interfaces::srv::PointsToSerial_Request & msg)
  : msg_(msg)
  {}
  Init_PointsToSerial_Request_n_points times(::custom_interfaces::srv::PointsToSerial_Request::_times_type arg)
  {
    msg_.times = std::move(arg);
    return Init_PointsToSerial_Request_n_points(msg_);
  }

private:
  ::custom_interfaces::srv::PointsToSerial_Request msg_;
};

class Init_PointsToSerial_Request_positions
{
public:
  Init_PointsToSerial_Request_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointsToSerial_Request_times positions(::custom_interfaces::srv::PointsToSerial_Request::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return Init_PointsToSerial_Request_times(msg_);
  }

private:
  ::custom_interfaces::srv::PointsToSerial_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::PointsToSerial_Request>()
{
  return custom_interfaces::srv::builder::Init_PointsToSerial_Request_positions();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_PointsToSerial_Response_status
{
public:
  Init_PointsToSerial_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::PointsToSerial_Response status(::custom_interfaces::srv::PointsToSerial_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::PointsToSerial_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::PointsToSerial_Response>()
{
  return custom_interfaces::srv::builder::Init_PointsToSerial_Response_status();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__BUILDER_HPP_
