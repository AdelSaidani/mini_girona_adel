// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cola2_msgs:msg/AdisImu.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/adis_imu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `raw`
// Member `f`
#include "rosidl_runtime_c/string_functions.h"

bool
cola2_msgs__msg__AdisImu__init(cola2_msgs__msg__AdisImu * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cola2_msgs__msg__AdisImu__fini(msg);
    return false;
  }
  // raw
  if (!rosidl_runtime_c__String__init(&msg->raw)) {
    cola2_msgs__msg__AdisImu__fini(msg);
    return false;
  }
  // mx
  // my
  // mz
  // gx
  // gy
  // gz
  // ax
  // ay
  // az
  // t
  // b
  // f
  if (!rosidl_runtime_c__String__init(&msg->f)) {
    cola2_msgs__msg__AdisImu__fini(msg);
    return false;
  }
  // e
  // w
  return true;
}

void
cola2_msgs__msg__AdisImu__fini(cola2_msgs__msg__AdisImu * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // raw
  rosidl_runtime_c__String__fini(&msg->raw);
  // mx
  // my
  // mz
  // gx
  // gy
  // gz
  // ax
  // ay
  // az
  // t
  // b
  // f
  rosidl_runtime_c__String__fini(&msg->f);
  // e
  // w
}

bool
cola2_msgs__msg__AdisImu__are_equal(const cola2_msgs__msg__AdisImu * lhs, const cola2_msgs__msg__AdisImu * rhs)
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
  // raw
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->raw), &(rhs->raw)))
  {
    return false;
  }
  // mx
  if (lhs->mx != rhs->mx) {
    return false;
  }
  // my
  if (lhs->my != rhs->my) {
    return false;
  }
  // mz
  if (lhs->mz != rhs->mz) {
    return false;
  }
  // gx
  if (lhs->gx != rhs->gx) {
    return false;
  }
  // gy
  if (lhs->gy != rhs->gy) {
    return false;
  }
  // gz
  if (lhs->gz != rhs->gz) {
    return false;
  }
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  // t
  if (lhs->t != rhs->t) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  // f
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->f), &(rhs->f)))
  {
    return false;
  }
  // e
  if (lhs->e != rhs->e) {
    return false;
  }
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  return true;
}

bool
cola2_msgs__msg__AdisImu__copy(
  const cola2_msgs__msg__AdisImu * input,
  cola2_msgs__msg__AdisImu * output)
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
  // raw
  if (!rosidl_runtime_c__String__copy(
      &(input->raw), &(output->raw)))
  {
    return false;
  }
  // mx
  output->mx = input->mx;
  // my
  output->my = input->my;
  // mz
  output->mz = input->mz;
  // gx
  output->gx = input->gx;
  // gy
  output->gy = input->gy;
  // gz
  output->gz = input->gz;
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  // t
  output->t = input->t;
  // b
  output->b = input->b;
  // f
  if (!rosidl_runtime_c__String__copy(
      &(input->f), &(output->f)))
  {
    return false;
  }
  // e
  output->e = input->e;
  // w
  output->w = input->w;
  return true;
}

cola2_msgs__msg__AdisImu *
cola2_msgs__msg__AdisImu__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__AdisImu * msg = (cola2_msgs__msg__AdisImu *)allocator.allocate(sizeof(cola2_msgs__msg__AdisImu), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cola2_msgs__msg__AdisImu));
  bool success = cola2_msgs__msg__AdisImu__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cola2_msgs__msg__AdisImu__destroy(cola2_msgs__msg__AdisImu * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cola2_msgs__msg__AdisImu__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cola2_msgs__msg__AdisImu__Sequence__init(cola2_msgs__msg__AdisImu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__AdisImu * data = NULL;

  if (size) {
    data = (cola2_msgs__msg__AdisImu *)allocator.zero_allocate(size, sizeof(cola2_msgs__msg__AdisImu), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cola2_msgs__msg__AdisImu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cola2_msgs__msg__AdisImu__fini(&data[i - 1]);
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
cola2_msgs__msg__AdisImu__Sequence__fini(cola2_msgs__msg__AdisImu__Sequence * array)
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
      cola2_msgs__msg__AdisImu__fini(&array->data[i]);
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

cola2_msgs__msg__AdisImu__Sequence *
cola2_msgs__msg__AdisImu__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__AdisImu__Sequence * array = (cola2_msgs__msg__AdisImu__Sequence *)allocator.allocate(sizeof(cola2_msgs__msg__AdisImu__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cola2_msgs__msg__AdisImu__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cola2_msgs__msg__AdisImu__Sequence__destroy(cola2_msgs__msg__AdisImu__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cola2_msgs__msg__AdisImu__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cola2_msgs__msg__AdisImu__Sequence__are_equal(const cola2_msgs__msg__AdisImu__Sequence * lhs, const cola2_msgs__msg__AdisImu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cola2_msgs__msg__AdisImu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cola2_msgs__msg__AdisImu__Sequence__copy(
  const cola2_msgs__msg__AdisImu__Sequence * input,
  cola2_msgs__msg__AdisImu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cola2_msgs__msg__AdisImu);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cola2_msgs__msg__AdisImu * data =
      (cola2_msgs__msg__AdisImu *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cola2_msgs__msg__AdisImu__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cola2_msgs__msg__AdisImu__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cola2_msgs__msg__AdisImu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
