// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/InterpolateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct InterpolateTrajectory_Request_
{
  using Type = InterpolateTrajectory_Request_<ContainerAllocator>;

  explicit InterpolateTrajectory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_position = 0.0;
      this->target_position = 0.0;
      this->mean_speed = 0.0;
      this->points = 0ll;
      this->interpolation_type = "";
    }
  }

  explicit InterpolateTrajectory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : interpolation_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_position = 0.0;
      this->target_position = 0.0;
      this->mean_speed = 0.0;
      this->points = 0ll;
      this->interpolation_type = "";
    }
  }

  // field types and members
  using _current_position_type =
    double;
  _current_position_type current_position;
  using _target_position_type =
    double;
  _target_position_type target_position;
  using _mean_speed_type =
    double;
  _mean_speed_type mean_speed;
  using _points_type =
    int64_t;
  _points_type points;
  using _interpolation_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _interpolation_type_type interpolation_type;

  // setters for named parameter idiom
  Type & set__current_position(
    const double & _arg)
  {
    this->current_position = _arg;
    return *this;
  }
  Type & set__target_position(
    const double & _arg)
  {
    this->target_position = _arg;
    return *this;
  }
  Type & set__mean_speed(
    const double & _arg)
  {
    this->mean_speed = _arg;
    return *this;
  }
  Type & set__points(
    const int64_t & _arg)
  {
    this->points = _arg;
    return *this;
  }
  Type & set__interpolation_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->interpolation_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Request
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Request
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InterpolateTrajectory_Request_ & other) const
  {
    if (this->current_position != other.current_position) {
      return false;
    }
    if (this->target_position != other.target_position) {
      return false;
    }
    if (this->mean_speed != other.mean_speed) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    if (this->interpolation_type != other.interpolation_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const InterpolateTrajectory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InterpolateTrajectory_Request_

// alias to use template instance with default allocator
using InterpolateTrajectory_Request =
  custom_interfaces::srv::InterpolateTrajectory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct InterpolateTrajectory_Response_
{
  using Type = InterpolateTrajectory_Response_<ContainerAllocator>;

  explicit InterpolateTrajectory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit InterpolateTrajectory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _positions_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positions_type positions;
  using _times_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _times_type times;

  // setters for named parameter idiom
  Type & set__positions(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positions = _arg;
    return *this;
  }
  Type & set__times(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->times = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Response
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__InterpolateTrajectory_Response
    std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InterpolateTrajectory_Response_ & other) const
  {
    if (this->positions != other.positions) {
      return false;
    }
    if (this->times != other.times) {
      return false;
    }
    return true;
  }
  bool operator!=(const InterpolateTrajectory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InterpolateTrajectory_Response_

// alias to use template instance with default allocator
using InterpolateTrajectory_Response =
  custom_interfaces::srv::InterpolateTrajectory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct InterpolateTrajectory
{
  using Request = custom_interfaces::srv::InterpolateTrajectory_Request;
  using Response = custom_interfaces::srv::InterpolateTrajectory_Response;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__STRUCT_HPP_
