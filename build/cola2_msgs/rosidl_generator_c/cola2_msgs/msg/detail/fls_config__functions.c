// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cola2_msgs:msg/FlsConfig.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/fls_config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `beams_bearings`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
cola2_msgs__msg__FlsConfig__init(cola2_msgs__msg__FlsConfig * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cola2_msgs__msg__FlsConfig__fini(msg);
    return false;
  }
  // num_beams
  // num_samples
  // window_start
  // window_end
  // beams_bearings
  if (!rosidl_runtime_c__float__Sequence__init(&msg->beams_bearings, 0)) {
    cola2_msgs__msg__FlsConfig__fini(msg);
    return false;
  }
  // speed_of_sound
  // ping_rate
  // frequency
  return true;
}

void
cola2_msgs__msg__FlsConfig__fini(cola2_msgs__msg__FlsConfig * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // num_beams
  // num_samples
  // window_start
  // window_end
  // beams_bearings
  rosidl_runtime_c__float__Sequence__fini(&msg->beams_bearings);
  // speed_of_sound
  // ping_rate
  // frequency
}

bool
cola2_msgs__msg__FlsConfig__are_equal(const cola2_msgs__msg__FlsConfig * lhs, const cola2_msgs__msg__FlsConfig * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // num_beams
  if (lhs->num_beams != rhs->num_beams) {
    return false;
  }
  // num_samples
  if (lhs->num_samples != rhs->num_samples) {
    return false;
  }
  // window_start
  if (lhs->window_start != rhs->window_start) {
    return false;
  }
  // window_end
  if (lhs->window_end != rhs->window_end) {
    return false;
  }
  // beams_bearings
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->beams_bearings), &(rhs->beams_bearings)))
  {
    return false;
  }
  // speed_of_sound
  if (lhs->speed_of_sound != rhs->speed_of_sound) {
    return false;
  }
  // ping_rate
  if (lhs->ping_rate != rhs->ping_rate) {
    return false;
  }
  // frequency
  if (lhs->frequency != rhs->frequency) {
    return false;
  }
  return true;
}

bool
cola2_msgs__msg__FlsConfig__copy(
  const cola2_msgs__msg__FlsConfig * input,
  cola2_msgs__msg__FlsConfig * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // num_beams
  output->num_beams = input->num_beams;
  // num_samples
  output->num_samples = input->num_samples;
  // window_start
  output->window_start = input->window_start;
  // window_end
  output->window_end = input->window_end;
  // beams_bearings
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->beams_bearings), &(output->beams_bearings)))
  {
    return false;
  }
  // speed_of_sound
  output->speed_of_sound = input->speed_of_sound;
  // ping_rate
  output->ping_rate = input->ping_rate;
  // frequency
  output->frequency = input->frequency;
  return true;
}

cola2_msgs__msg__FlsConfig *
cola2_msgs__msg__FlsConfig__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__FlsConfig * msg = (cola2_msgs__msg__FlsConfig *)allocator.allocate(sizeof(cola2_msgs__msg__FlsConfig), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cola2_msgs__msg__FlsConfig));
  bool success = cola2_msgs__msg__FlsConfig__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cola2_msgs__msg__FlsConfig__destroy(cola2_msgs__msg__FlsConfig * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cola2_msgs__msg__FlsConfig__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cola2_msgs__msg__FlsConfig__Sequence__init(cola2_msgs__msg__FlsConfig__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__FlsConfig * data = NULL;

  if (size) {
    data = (cola2_msgs__msg__FlsConfig *)allocator.zero_allocate(size, sizeof(cola2_msgs__msg__FlsConfig), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cola2_msgs__msg__FlsConfig__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cola2_msgs__msg__FlsConfig__fini(&data[i - 1]);
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
cola2_msgs__msg__FlsConfig__Sequence__fini(cola2_msgs__msg__FlsConfig__Sequence * array)
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
      cola2_msgs__msg__FlsConfig__fini(&array->data[i]);
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

cola2_msgs__msg__FlsConfig__Sequence *
cola2_msgs__msg__FlsConfig__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__FlsConfig__Sequence * array = (cola2_msgs__msg__FlsConfig__Sequence *)allocator.allocate(sizeof(cola2_msgs__msg__FlsConfig__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cola2_msgs__msg__FlsConfig__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cola2_msgs__msg__FlsConfig__Sequence__destroy(cola2_msgs__msg__FlsConfig__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cola2_msgs__msg__FlsConfig__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cola2_msgs__msg__FlsConfig__Sequence__are_equal(const cola2_msgs__msg__FlsConfig__Sequence * lhs, const cola2_msgs__msg__FlsConfig__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cola2_msgs__msg__FlsConfig__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cola2_msgs__msg__FlsConfig__Sequence__copy(
  const cola2_msgs__msg__FlsConfig__Sequence * input,
  cola2_msgs__msg__FlsConfig__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cola2_msgs__msg__FlsConfig);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cola2_msgs__msg__FlsConfig * data =
      (cola2_msgs__msg__FlsConfig *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cola2_msgs__msg__FlsConfig__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cola2_msgs__msg__FlsConfig__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cola2_msgs__msg__FlsConfig__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
