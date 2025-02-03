// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/image_acquisition_settings__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `extra`
#include "cola2_msgs/msg/detail/key_value__functions.h"

bool
cola2_msgs__msg__ImageAcquisitionSettings__init(cola2_msgs__msg__ImageAcquisitionSettings * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cola2_msgs__msg__ImageAcquisitionSettings__fini(msg);
    return false;
  }
  // exposure_time
  // gain
  // blue_ratio
  // red_ratio
  // focus
  // aperture
  // focal_length
  // extra
  if (!cola2_msgs__msg__KeyValue__Sequence__init(&msg->extra, 0)) {
    cola2_msgs__msg__ImageAcquisitionSettings__fini(msg);
    return false;
  }
  return true;
}

void
cola2_msgs__msg__ImageAcquisitionSettings__fini(cola2_msgs__msg__ImageAcquisitionSettings * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // exposure_time
  // gain
  // blue_ratio
  // red_ratio
  // focus
  // aperture
  // focal_length
  // extra
  cola2_msgs__msg__KeyValue__Sequence__fini(&msg->extra);
}

bool
cola2_msgs__msg__ImageAcquisitionSettings__are_equal(const cola2_msgs__msg__ImageAcquisitionSettings * lhs, const cola2_msgs__msg__ImageAcquisitionSettings * rhs)
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
  // exposure_time
  if (lhs->exposure_time != rhs->exposure_time) {
    return false;
  }
  // gain
  if (lhs->gain != rhs->gain) {
    return false;
  }
  // blue_ratio
  if (lhs->blue_ratio != rhs->blue_ratio) {
    return false;
  }
  // red_ratio
  if (lhs->red_ratio != rhs->red_ratio) {
    return false;
  }
  // focus
  if (lhs->focus != rhs->focus) {
    return false;
  }
  // aperture
  if (lhs->aperture != rhs->aperture) {
    return false;
  }
  // focal_length
  if (lhs->focal_length != rhs->focal_length) {
    return false;
  }
  // extra
  if (!cola2_msgs__msg__KeyValue__Sequence__are_equal(
      &(lhs->extra), &(rhs->extra)))
  {
    return false;
  }
  return true;
}

bool
cola2_msgs__msg__ImageAcquisitionSettings__copy(
  const cola2_msgs__msg__ImageAcquisitionSettings * input,
  cola2_msgs__msg__ImageAcquisitionSettings * output)
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
  // exposure_time
  output->exposure_time = input->exposure_time;
  // gain
  output->gain = input->gain;
  // blue_ratio
  output->blue_ratio = input->blue_ratio;
  // red_ratio
  output->red_ratio = input->red_ratio;
  // focus
  output->focus = input->focus;
  // aperture
  output->aperture = input->aperture;
  // focal_length
  output->focal_length = input->focal_length;
  // extra
  if (!cola2_msgs__msg__KeyValue__Sequence__copy(
      &(input->extra), &(output->extra)))
  {
    return false;
  }
  return true;
}

cola2_msgs__msg__ImageAcquisitionSettings *
cola2_msgs__msg__ImageAcquisitionSettings__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__ImageAcquisitionSettings * msg = (cola2_msgs__msg__ImageAcquisitionSettings *)allocator.allocate(sizeof(cola2_msgs__msg__ImageAcquisitionSettings), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cola2_msgs__msg__ImageAcquisitionSettings));
  bool success = cola2_msgs__msg__ImageAcquisitionSettings__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cola2_msgs__msg__ImageAcquisitionSettings__destroy(cola2_msgs__msg__ImageAcquisitionSettings * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cola2_msgs__msg__ImageAcquisitionSettings__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cola2_msgs__msg__ImageAcquisitionSettings__Sequence__init(cola2_msgs__msg__ImageAcquisitionSettings__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__ImageAcquisitionSettings * data = NULL;

  if (size) {
    data = (cola2_msgs__msg__ImageAcquisitionSettings *)allocator.zero_allocate(size, sizeof(cola2_msgs__msg__ImageAcquisitionSettings), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cola2_msgs__msg__ImageAcquisitionSettings__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cola2_msgs__msg__ImageAcquisitionSettings__fini(&data[i - 1]);
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
cola2_msgs__msg__ImageAcquisitionSettings__Sequence__fini(cola2_msgs__msg__ImageAcquisitionSettings__Sequence * array)
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
      cola2_msgs__msg__ImageAcquisitionSettings__fini(&array->data[i]);
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

cola2_msgs__msg__ImageAcquisitionSettings__Sequence *
cola2_msgs__msg__ImageAcquisitionSettings__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__ImageAcquisitionSettings__Sequence * array = (cola2_msgs__msg__ImageAcquisitionSettings__Sequence *)allocator.allocate(sizeof(cola2_msgs__msg__ImageAcquisitionSettings__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cola2_msgs__msg__ImageAcquisitionSettings__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cola2_msgs__msg__ImageAcquisitionSettings__Sequence__destroy(cola2_msgs__msg__ImageAcquisitionSettings__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cola2_msgs__msg__ImageAcquisitionSettings__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cola2_msgs__msg__ImageAcquisitionSettings__Sequence__are_equal(const cola2_msgs__msg__ImageAcquisitionSettings__Sequence * lhs, const cola2_msgs__msg__ImageAcquisitionSettings__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cola2_msgs__msg__ImageAcquisitionSettings__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cola2_msgs__msg__ImageAcquisitionSettings__Sequence__copy(
  const cola2_msgs__msg__ImageAcquisitionSettings__Sequence * input,
  cola2_msgs__msg__ImageAcquisitionSettings__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cola2_msgs__msg__ImageAcquisitionSettings);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cola2_msgs__msg__ImageAcquisitionSettings * data =
      (cola2_msgs__msg__ImageAcquisitionSettings *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cola2_msgs__msg__ImageAcquisitionSettings__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cola2_msgs__msg__ImageAcquisitionSettings__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cola2_msgs__msg__ImageAcquisitionSettings__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
