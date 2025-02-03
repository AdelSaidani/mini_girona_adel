// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cola2_msgs:msg/SSSConfig.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/sss_config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
cola2_msgs__msg__SSSConfig__init(cola2_msgs__msg__SSSConfig * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cola2_msgs__msg__SSSConfig__fini(msg);
    return false;
  }
  // samples_per_channel
  // range_delay
  // range
  // horizontal_beam_angle
  // vertical_beam_angle
  // speed_of_sound
  // ping_rate
  // frequency
  return true;
}

void
cola2_msgs__msg__SSSConfig__fini(cola2_msgs__msg__SSSConfig * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // samples_per_channel
  // range_delay
  // range
  // horizontal_beam_angle
  // vertical_beam_angle
  // speed_of_sound
  // ping_rate
  // frequency
}

bool
cola2_msgs__msg__SSSConfig__are_equal(const cola2_msgs__msg__SSSConfig * lhs, const cola2_msgs__msg__SSSConfig * rhs)
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
  // samples_per_channel
  if (lhs->samples_per_channel != rhs->samples_per_channel) {
    return false;
  }
  // range_delay
  if (lhs->range_delay != rhs->range_delay) {
    return false;
  }
  // range
  if (lhs->range != rhs->range) {
    return false;
  }
  // horizontal_beam_angle
  if (lhs->horizontal_beam_angle != rhs->horizontal_beam_angle) {
    return false;
  }
  // vertical_beam_angle
  if (lhs->vertical_beam_angle != rhs->vertical_beam_angle) {
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
cola2_msgs__msg__SSSConfig__copy(
  const cola2_msgs__msg__SSSConfig * input,
  cola2_msgs__msg__SSSConfig * output)
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
  // samples_per_channel
  output->samples_per_channel = input->samples_per_channel;
  // range_delay
  output->range_delay = input->range_delay;
  // range
  output->range = input->range;
  // horizontal_beam_angle
  output->horizontal_beam_angle = input->horizontal_beam_angle;
  // vertical_beam_angle
  output->vertical_beam_angle = input->vertical_beam_angle;
  // speed_of_sound
  output->speed_of_sound = input->speed_of_sound;
  // ping_rate
  output->ping_rate = input->ping_rate;
  // frequency
  output->frequency = input->frequency;
  return true;
}

cola2_msgs__msg__SSSConfig *
cola2_msgs__msg__SSSConfig__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__SSSConfig * msg = (cola2_msgs__msg__SSSConfig *)allocator.allocate(sizeof(cola2_msgs__msg__SSSConfig), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cola2_msgs__msg__SSSConfig));
  bool success = cola2_msgs__msg__SSSConfig__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cola2_msgs__msg__SSSConfig__destroy(cola2_msgs__msg__SSSConfig * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cola2_msgs__msg__SSSConfig__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cola2_msgs__msg__SSSConfig__Sequence__init(cola2_msgs__msg__SSSConfig__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__SSSConfig * data = NULL;

  if (size) {
    data = (cola2_msgs__msg__SSSConfig *)allocator.zero_allocate(size, sizeof(cola2_msgs__msg__SSSConfig), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cola2_msgs__msg__SSSConfig__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cola2_msgs__msg__SSSConfig__fini(&data[i - 1]);
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
cola2_msgs__msg__SSSConfig__Sequence__fini(cola2_msgs__msg__SSSConfig__Sequence * array)
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
      cola2_msgs__msg__SSSConfig__fini(&array->data[i]);
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

cola2_msgs__msg__SSSConfig__Sequence *
cola2_msgs__msg__SSSConfig__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__SSSConfig__Sequence * array = (cola2_msgs__msg__SSSConfig__Sequence *)allocator.allocate(sizeof(cola2_msgs__msg__SSSConfig__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cola2_msgs__msg__SSSConfig__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cola2_msgs__msg__SSSConfig__Sequence__destroy(cola2_msgs__msg__SSSConfig__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cola2_msgs__msg__SSSConfig__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cola2_msgs__msg__SSSConfig__Sequence__are_equal(const cola2_msgs__msg__SSSConfig__Sequence * lhs, const cola2_msgs__msg__SSSConfig__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cola2_msgs__msg__SSSConfig__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cola2_msgs__msg__SSSConfig__Sequence__copy(
  const cola2_msgs__msg__SSSConfig__Sequence * input,
  cola2_msgs__msg__SSSConfig__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cola2_msgs__msg__SSSConfig);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cola2_msgs__msg__SSSConfig * data =
      (cola2_msgs__msg__SSSConfig *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cola2_msgs__msg__SSSConfig__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cola2_msgs__msg__SSSConfig__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cola2_msgs__msg__SSSConfig__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
