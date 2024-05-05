// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/InterpolateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/InterpolateTrajectory in the package custom_interfaces.
typedef struct custom_interfaces__srv__InterpolateTrajectory_Request
{
  int64_t a;
  int64_t b;
} custom_interfaces__srv__InterpolateTrajectory_Request;

// Struct for a sequence of custom_interfaces__srv__InterpolateTrajectory_Request.
typedef struct custom_interfaces__srv__InterpolateTrajectory_Request__Sequence
{
  custom_interfaces__srv__InterpolateTrajectory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__InterpolateTrajectory_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/InterpolateTrajectory in the package custom_interfaces.
typedef struct custom_interfaces__srv__InterpolateTrajectory_Response
{
  int64_t sum;
} custom_interfaces__srv__InterpolateTrajectory_Response;

// Struct for a sequence of custom_interfaces__srv__InterpolateTrajectory_Response.
typedef struct custom_interfaces__srv__InterpolateTrajectory_Response__Sequence
{
  custom_interfaces__srv__InterpolateTrajectory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__InterpolateTrajectory_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__INTERPOLATE_TRAJECTORY__STRUCT_H_
