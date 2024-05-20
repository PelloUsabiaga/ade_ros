// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/PointsToSerial.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'positions'
// Member 'times'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/PointsToSerial in the package custom_interfaces.
typedef struct custom_interfaces__srv__PointsToSerial_Request
{
  rosidl_runtime_c__double__Sequence positions;
  rosidl_runtime_c__double__Sequence times;
  double n_points;
} custom_interfaces__srv__PointsToSerial_Request;

// Struct for a sequence of custom_interfaces__srv__PointsToSerial_Request.
typedef struct custom_interfaces__srv__PointsToSerial_Request__Sequence
{
  custom_interfaces__srv__PointsToSerial_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__PointsToSerial_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/PointsToSerial in the package custom_interfaces.
typedef struct custom_interfaces__srv__PointsToSerial_Response
{
  rosidl_runtime_c__String status;
} custom_interfaces__srv__PointsToSerial_Response;

// Struct for a sequence of custom_interfaces__srv__PointsToSerial_Response.
typedef struct custom_interfaces__srv__PointsToSerial_Response__Sequence
{
  custom_interfaces__srv__PointsToSerial_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__PointsToSerial_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__POINTS_TO_SERIAL__STRUCT_H_
