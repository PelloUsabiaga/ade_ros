// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:srv/InterpolateTrajectory.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/srv/detail/interpolate_trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `interpolation_type`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_interfaces__srv__InterpolateTrajectory_Request__init(custom_interfaces__srv__InterpolateTrajectory_Request * msg)
{
  if (!msg) {
    return false;
  }
  // current_position
  // target_position
  // mean_speed
  // points
  // interpolation_type
  if (!rosidl_runtime_c__String__init(&msg->interpolation_type)) {
    custom_interfaces__srv__InterpolateTrajectory_Request__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__srv__InterpolateTrajectory_Request__fini(custom_interfaces__srv__InterpolateTrajectory_Request * msg)
{
  if (!msg) {
    return;
  }
  // current_position
  // target_position
  // mean_speed
  // points
  // interpolation_type
  rosidl_runtime_c__String__fini(&msg->interpolation_type);
}

bool
custom_interfaces__srv__InterpolateTrajectory_Request__are_equal(const custom_interfaces__srv__InterpolateTrajectory_Request * lhs, const custom_interfaces__srv__InterpolateTrajectory_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_position
  if (lhs->current_position != rhs->current_position) {
    return false;
  }
  // target_position
  if (lhs->target_position != rhs->target_position) {
    return false;
  }
  // mean_speed
  if (lhs->mean_speed != rhs->mean_speed) {
    return false;
  }
  // points
  if (lhs->points != rhs->points) {
    return false;
  }
  // interpolation_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->interpolation_type), &(rhs->interpolation_type)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__srv__InterpolateTrajectory_Request__copy(
  const custom_interfaces__srv__InterpolateTrajectory_Request * input,
  custom_interfaces__srv__InterpolateTrajectory_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // current_position
  output->current_position = input->current_position;
  // target_position
  output->target_position = input->target_position;
  // mean_speed
  output->mean_speed = input->mean_speed;
  // points
  output->points = input->points;
  // interpolation_type
  if (!rosidl_runtime_c__String__copy(
      &(input->interpolation_type), &(output->interpolation_type)))
  {
    return false;
  }
  return true;
}

custom_interfaces__srv__InterpolateTrajectory_Request *
custom_interfaces__srv__InterpolateTrajectory_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InterpolateTrajectory_Request * msg = (custom_interfaces__srv__InterpolateTrajectory_Request *)allocator.allocate(sizeof(custom_interfaces__srv__InterpolateTrajectory_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__srv__InterpolateTrajectory_Request));
  bool success = custom_interfaces__srv__InterpolateTrajectory_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__srv__InterpolateTrajectory_Request__destroy(custom_interfaces__srv__InterpolateTrajectory_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__srv__InterpolateTrajectory_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__init(custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InterpolateTrajectory_Request * data = NULL;

  if (size) {
    data = (custom_interfaces__srv__InterpolateTrajectory_Request *)allocator.zero_allocate(size, sizeof(custom_interfaces__srv__InterpolateTrajectory_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__srv__InterpolateTrajectory_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__srv__InterpolateTrajectory_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__fini(custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__srv__InterpolateTrajectory_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__srv__InterpolateTrajectory_Request__Sequence *
custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * array = (custom_interfaces__srv__InterpolateTrajectory_Request__Sequence *)allocator.allocate(sizeof(custom_interfaces__srv__InterpolateTrajectory_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__destroy(custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__are_equal(const custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * lhs, const custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__srv__InterpolateTrajectory_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__srv__InterpolateTrajectory_Request__Sequence__copy(
  const custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * input,
  custom_interfaces__srv__InterpolateTrajectory_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__srv__InterpolateTrajectory_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__srv__InterpolateTrajectory_Request * data =
      (custom_interfaces__srv__InterpolateTrajectory_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__srv__InterpolateTrajectory_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__srv__InterpolateTrajectory_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__srv__InterpolateTrajectory_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `positions`
// Member `times`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_interfaces__srv__InterpolateTrajectory_Response__init(custom_interfaces__srv__InterpolateTrajectory_Response * msg)
{
  if (!msg) {
    return false;
  }
  // positions
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positions, 0)) {
    custom_interfaces__srv__InterpolateTrajectory_Response__fini(msg);
    return false;
  }
  // times
  if (!rosidl_runtime_c__double__Sequence__init(&msg->times, 0)) {
    custom_interfaces__srv__InterpolateTrajectory_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__srv__InterpolateTrajectory_Response__fini(custom_interfaces__srv__InterpolateTrajectory_Response * msg)
{
  if (!msg) {
    return;
  }
  // positions
  rosidl_runtime_c__double__Sequence__fini(&msg->positions);
  // times
  rosidl_runtime_c__double__Sequence__fini(&msg->times);
}

bool
custom_interfaces__srv__InterpolateTrajectory_Response__are_equal(const custom_interfaces__srv__InterpolateTrajectory_Response * lhs, const custom_interfaces__srv__InterpolateTrajectory_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // positions
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positions), &(rhs->positions)))
  {
    return false;
  }
  // times
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->times), &(rhs->times)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__srv__InterpolateTrajectory_Response__copy(
  const custom_interfaces__srv__InterpolateTrajectory_Response * input,
  custom_interfaces__srv__InterpolateTrajectory_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // positions
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positions), &(output->positions)))
  {
    return false;
  }
  // times
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->times), &(output->times)))
  {
    return false;
  }
  return true;
}

custom_interfaces__srv__InterpolateTrajectory_Response *
custom_interfaces__srv__InterpolateTrajectory_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InterpolateTrajectory_Response * msg = (custom_interfaces__srv__InterpolateTrajectory_Response *)allocator.allocate(sizeof(custom_interfaces__srv__InterpolateTrajectory_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__srv__InterpolateTrajectory_Response));
  bool success = custom_interfaces__srv__InterpolateTrajectory_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__srv__InterpolateTrajectory_Response__destroy(custom_interfaces__srv__InterpolateTrajectory_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__srv__InterpolateTrajectory_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__init(custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InterpolateTrajectory_Response * data = NULL;

  if (size) {
    data = (custom_interfaces__srv__InterpolateTrajectory_Response *)allocator.zero_allocate(size, sizeof(custom_interfaces__srv__InterpolateTrajectory_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__srv__InterpolateTrajectory_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__srv__InterpolateTrajectory_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__fini(custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__srv__InterpolateTrajectory_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__srv__InterpolateTrajectory_Response__Sequence *
custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * array = (custom_interfaces__srv__InterpolateTrajectory_Response__Sequence *)allocator.allocate(sizeof(custom_interfaces__srv__InterpolateTrajectory_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__destroy(custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__are_equal(const custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * lhs, const custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__srv__InterpolateTrajectory_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__srv__InterpolateTrajectory_Response__Sequence__copy(
  const custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * input,
  custom_interfaces__srv__InterpolateTrajectory_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__srv__InterpolateTrajectory_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__srv__InterpolateTrajectory_Response * data =
      (custom_interfaces__srv__InterpolateTrajectory_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__srv__InterpolateTrajectory_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__srv__InterpolateTrajectory_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__srv__InterpolateTrajectory_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
