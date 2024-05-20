// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/PointsToSerial.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/points_to_serial__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PointsToSerial_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: positions
  {
    if (msg.positions.size() == 0) {
      out << "positions: []";
    } else {
      out << "positions: [";
      size_t pending_items = msg.positions.size();
      for (auto item : msg.positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: times
  {
    if (msg.times.size() == 0) {
      out << "times: []";
    } else {
      out << "times: [";
      size_t pending_items = msg.times.size();
      for (auto item : msg.times) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: n_points
  {
    out << "n_points: ";
    rosidl_generator_traits::value_to_yaml(msg.n_points, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PointsToSerial_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: times
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.times.size() == 0) {
      out << "times: []\n";
    } else {
      out << "times:\n";
      for (auto item : msg.times) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: n_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "n_points: ";
    rosidl_generator_traits::value_to_yaml(msg.n_points, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PointsToSerial_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::PointsToSerial_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::PointsToSerial_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::PointsToSerial_Request>()
{
  return "custom_interfaces::srv::PointsToSerial_Request";
}

template<>
inline const char * name<custom_interfaces::srv::PointsToSerial_Request>()
{
  return "custom_interfaces/srv/PointsToSerial_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::PointsToSerial_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::PointsToSerial_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::PointsToSerial_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PointsToSerial_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PointsToSerial_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PointsToSerial_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::PointsToSerial_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::PointsToSerial_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::PointsToSerial_Response>()
{
  return "custom_interfaces::srv::PointsToSerial_Response";
}

template<>
inline const char * name<custom_interfaces::srv::PointsToSerial_Response>()
{
  return "custom_interfaces/srv/PointsToSerial_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::PointsToSerial_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::PointsToSerial_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::PointsToSerial_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::PointsToSerial>()
{
  return "custom_interfaces::srv::PointsToSerial";
}

template<>
inline const char * name<custom_interfaces::srv::PointsToSerial>()
{
  return "custom_interfaces/srv/PointsToSerial";
}

template<>
struct has_fixed_size<custom_interfaces::srv::PointsToSerial>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::PointsToSerial_Request>::value &&
    has_fixed_size<custom_interfaces::srv::PointsToSerial_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::PointsToSerial>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::PointsToSerial_Request>::value &&
    has_bounded_size<custom_interfaces::srv::PointsToSerial_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::PointsToSerial>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::PointsToSerial_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::PointsToSerial_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__TRAITS_HPP_
