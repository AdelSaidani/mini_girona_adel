// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
cola2_msgs__msg__ImuAngleEstimatorInfo__init(cola2_msgs__msg__ImuAngleEstimatorInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cola2_msgs__msg__ImuAngleEstimatorInfo__fini(msg);
    return false;
  }
  // period
  // ax
  // ay
  // az
  // mx
  // my
  // mz
  // gx
  // gy
  // gz
  // tilt_roll
  // tilt_pitch
  // tilt_yaw
  // rate_tilt_roll
  // rate_tilt_pitch
  // rate_tilt_yaw
  // tilt_angular_velocity_x
  // tilt_angular_velocity_y
  // tilt_angular_velocity_z
  // bias_roll_from_this_iteration
  // bias_pitch_from_this_iteration
  // bias_yaw_from_this_iteration
  // bias_roll
  // bias_pitch
  // bias_yaw
  // bias_buffer_size
  // merging_filter_coefficient
  // corrected_angular_velocity_x
  // corrected_angular_velocity_y
  // corrected_angular_velocity_z
  // gyro_integrated_roll
  // gyro_integrated_pitch
  // gyro_integrated_yaw
  // gyro_roll_innovation
  // gyro_pitch_innovation
  // gyro_yaw_innovation
  // tilt_roll_innovation
  // tilt_pitch_innovation
  // tilt_yaw_innovation
  // roll_innovation
  // pitch_innovation
  // yaw_innovation
  // merged_roll
  // merged_pitch
  // merged_yaw
  // merged_minus_tilt_roll
  // merged_minus_tilt_pitch
  // merged_minus_tilt_yaw
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    cola2_msgs__msg__ImuAngleEstimatorInfo__fini(msg);
    return false;
  }
  // filter_elapsed_time
  return true;
}

void
cola2_msgs__msg__ImuAngleEstimatorInfo__fini(cola2_msgs__msg__ImuAngleEstimatorInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // period
  // ax
  // ay
  // az
  // mx
  // my
  // mz
  // gx
  // gy
  // gz
  // tilt_roll
  // tilt_pitch
  // tilt_yaw
  // rate_tilt_roll
  // rate_tilt_pitch
  // rate_tilt_yaw
  // tilt_angular_velocity_x
  // tilt_angular_velocity_y
  // tilt_angular_velocity_z
  // bias_roll_from_this_iteration
  // bias_pitch_from_this_iteration
  // bias_yaw_from_this_iteration
  // bias_roll
  // bias_pitch
  // bias_yaw
  // bias_buffer_size
  // merging_filter_coefficient
  // corrected_angular_velocity_x
  // corrected_angular_velocity_y
  // corrected_angular_velocity_z
  // gyro_integrated_roll
  // gyro_integrated_pitch
  // gyro_integrated_yaw
  // gyro_roll_innovation
  // gyro_pitch_innovation
  // gyro_yaw_innovation
  // tilt_roll_innovation
  // tilt_pitch_innovation
  // tilt_yaw_innovation
  // roll_innovation
  // pitch_innovation
  // yaw_innovation
  // merged_roll
  // merged_pitch
  // merged_yaw
  // merged_minus_tilt_roll
  // merged_minus_tilt_pitch
  // merged_minus_tilt_yaw
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // filter_elapsed_time
}

bool
cola2_msgs__msg__ImuAngleEstimatorInfo__are_equal(const cola2_msgs__msg__ImuAngleEstimatorInfo * lhs, const cola2_msgs__msg__ImuAngleEstimatorInfo * rhs)
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
  // period
  if (lhs->period != rhs->period) {
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
  // tilt_roll
  if (lhs->tilt_roll != rhs->tilt_roll) {
    return false;
  }
  // tilt_pitch
  if (lhs->tilt_pitch != rhs->tilt_pitch) {
    return false;
  }
  // tilt_yaw
  if (lhs->tilt_yaw != rhs->tilt_yaw) {
    return false;
  }
  // rate_tilt_roll
  if (lhs->rate_tilt_roll != rhs->rate_tilt_roll) {
    return false;
  }
  // rate_tilt_pitch
  if (lhs->rate_tilt_pitch != rhs->rate_tilt_pitch) {
    return false;
  }
  // rate_tilt_yaw
  if (lhs->rate_tilt_yaw != rhs->rate_tilt_yaw) {
    return false;
  }
  // tilt_angular_velocity_x
  if (lhs->tilt_angular_velocity_x != rhs->tilt_angular_velocity_x) {
    return false;
  }
  // tilt_angular_velocity_y
  if (lhs->tilt_angular_velocity_y != rhs->tilt_angular_velocity_y) {
    return false;
  }
  // tilt_angular_velocity_z
  if (lhs->tilt_angular_velocity_z != rhs->tilt_angular_velocity_z) {
    return false;
  }
  // bias_roll_from_this_iteration
  if (lhs->bias_roll_from_this_iteration != rhs->bias_roll_from_this_iteration) {
    return false;
  }
  // bias_pitch_from_this_iteration
  if (lhs->bias_pitch_from_this_iteration != rhs->bias_pitch_from_this_iteration) {
    return false;
  }
  // bias_yaw_from_this_iteration
  if (lhs->bias_yaw_from_this_iteration != rhs->bias_yaw_from_this_iteration) {
    return false;
  }
  // bias_roll
  if (lhs->bias_roll != rhs->bias_roll) {
    return false;
  }
  // bias_pitch
  if (lhs->bias_pitch != rhs->bias_pitch) {
    return false;
  }
  // bias_yaw
  if (lhs->bias_yaw != rhs->bias_yaw) {
    return false;
  }
  // bias_buffer_size
  if (lhs->bias_buffer_size != rhs->bias_buffer_size) {
    return false;
  }
  // merging_filter_coefficient
  if (lhs->merging_filter_coefficient != rhs->merging_filter_coefficient) {
    return false;
  }
  // corrected_angular_velocity_x
  if (lhs->corrected_angular_velocity_x != rhs->corrected_angular_velocity_x) {
    return false;
  }
  // corrected_angular_velocity_y
  if (lhs->corrected_angular_velocity_y != rhs->corrected_angular_velocity_y) {
    return false;
  }
  // corrected_angular_velocity_z
  if (lhs->corrected_angular_velocity_z != rhs->corrected_angular_velocity_z) {
    return false;
  }
  // gyro_integrated_roll
  if (lhs->gyro_integrated_roll != rhs->gyro_integrated_roll) {
    return false;
  }
  // gyro_integrated_pitch
  if (lhs->gyro_integrated_pitch != rhs->gyro_integrated_pitch) {
    return false;
  }
  // gyro_integrated_yaw
  if (lhs->gyro_integrated_yaw != rhs->gyro_integrated_yaw) {
    return false;
  }
  // gyro_roll_innovation
  if (lhs->gyro_roll_innovation != rhs->gyro_roll_innovation) {
    return false;
  }
  // gyro_pitch_innovation
  if (lhs->gyro_pitch_innovation != rhs->gyro_pitch_innovation) {
    return false;
  }
  // gyro_yaw_innovation
  if (lhs->gyro_yaw_innovation != rhs->gyro_yaw_innovation) {
    return false;
  }
  // tilt_roll_innovation
  if (lhs->tilt_roll_innovation != rhs->tilt_roll_innovation) {
    return false;
  }
  // tilt_pitch_innovation
  if (lhs->tilt_pitch_innovation != rhs->tilt_pitch_innovation) {
    return false;
  }
  // tilt_yaw_innovation
  if (lhs->tilt_yaw_innovation != rhs->tilt_yaw_innovation) {
    return false;
  }
  // roll_innovation
  if (lhs->roll_innovation != rhs->roll_innovation) {
    return false;
  }
  // pitch_innovation
  if (lhs->pitch_innovation != rhs->pitch_innovation) {
    return false;
  }
  // yaw_innovation
  if (lhs->yaw_innovation != rhs->yaw_innovation) {
    return false;
  }
  // merged_roll
  if (lhs->merged_roll != rhs->merged_roll) {
    return false;
  }
  // merged_pitch
  if (lhs->merged_pitch != rhs->merged_pitch) {
    return false;
  }
  // merged_yaw
  if (lhs->merged_yaw != rhs->merged_yaw) {
    return false;
  }
  // merged_minus_tilt_roll
  if (lhs->merged_minus_tilt_roll != rhs->merged_minus_tilt_roll) {
    return false;
  }
  // merged_minus_tilt_pitch
  if (lhs->merged_minus_tilt_pitch != rhs->merged_minus_tilt_pitch) {
    return false;
  }
  // merged_minus_tilt_yaw
  if (lhs->merged_minus_tilt_yaw != rhs->merged_minus_tilt_yaw) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // filter_elapsed_time
  if (lhs->filter_elapsed_time != rhs->filter_elapsed_time) {
    return false;
  }
  return true;
}

bool
cola2_msgs__msg__ImuAngleEstimatorInfo__copy(
  const cola2_msgs__msg__ImuAngleEstimatorInfo * input,
  cola2_msgs__msg__ImuAngleEstimatorInfo * output)
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
  // period
  output->period = input->period;
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
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
  // tilt_roll
  output->tilt_roll = input->tilt_roll;
  // tilt_pitch
  output->tilt_pitch = input->tilt_pitch;
  // tilt_yaw
  output->tilt_yaw = input->tilt_yaw;
  // rate_tilt_roll
  output->rate_tilt_roll = input->rate_tilt_roll;
  // rate_tilt_pitch
  output->rate_tilt_pitch = input->rate_tilt_pitch;
  // rate_tilt_yaw
  output->rate_tilt_yaw = input->rate_tilt_yaw;
  // tilt_angular_velocity_x
  output->tilt_angular_velocity_x = input->tilt_angular_velocity_x;
  // tilt_angular_velocity_y
  output->tilt_angular_velocity_y = input->tilt_angular_velocity_y;
  // tilt_angular_velocity_z
  output->tilt_angular_velocity_z = input->tilt_angular_velocity_z;
  // bias_roll_from_this_iteration
  output->bias_roll_from_this_iteration = input->bias_roll_from_this_iteration;
  // bias_pitch_from_this_iteration
  output->bias_pitch_from_this_iteration = input->bias_pitch_from_this_iteration;
  // bias_yaw_from_this_iteration
  output->bias_yaw_from_this_iteration = input->bias_yaw_from_this_iteration;
  // bias_roll
  output->bias_roll = input->bias_roll;
  // bias_pitch
  output->bias_pitch = input->bias_pitch;
  // bias_yaw
  output->bias_yaw = input->bias_yaw;
  // bias_buffer_size
  output->bias_buffer_size = input->bias_buffer_size;
  // merging_filter_coefficient
  output->merging_filter_coefficient = input->merging_filter_coefficient;
  // corrected_angular_velocity_x
  output->corrected_angular_velocity_x = input->corrected_angular_velocity_x;
  // corrected_angular_velocity_y
  output->corrected_angular_velocity_y = input->corrected_angular_velocity_y;
  // corrected_angular_velocity_z
  output->corrected_angular_velocity_z = input->corrected_angular_velocity_z;
  // gyro_integrated_roll
  output->gyro_integrated_roll = input->gyro_integrated_roll;
  // gyro_integrated_pitch
  output->gyro_integrated_pitch = input->gyro_integrated_pitch;
  // gyro_integrated_yaw
  output->gyro_integrated_yaw = input->gyro_integrated_yaw;
  // gyro_roll_innovation
  output->gyro_roll_innovation = input->gyro_roll_innovation;
  // gyro_pitch_innovation
  output->gyro_pitch_innovation = input->gyro_pitch_innovation;
  // gyro_yaw_innovation
  output->gyro_yaw_innovation = input->gyro_yaw_innovation;
  // tilt_roll_innovation
  output->tilt_roll_innovation = input->tilt_roll_innovation;
  // tilt_pitch_innovation
  output->tilt_pitch_innovation = input->tilt_pitch_innovation;
  // tilt_yaw_innovation
  output->tilt_yaw_innovation = input->tilt_yaw_innovation;
  // roll_innovation
  output->roll_innovation = input->roll_innovation;
  // pitch_innovation
  output->pitch_innovation = input->pitch_innovation;
  // yaw_innovation
  output->yaw_innovation = input->yaw_innovation;
  // merged_roll
  output->merged_roll = input->merged_roll;
  // merged_pitch
  output->merged_pitch = input->merged_pitch;
  // merged_yaw
  output->merged_yaw = input->merged_yaw;
  // merged_minus_tilt_roll
  output->merged_minus_tilt_roll = input->merged_minus_tilt_roll;
  // merged_minus_tilt_pitch
  output->merged_minus_tilt_pitch = input->merged_minus_tilt_pitch;
  // merged_minus_tilt_yaw
  output->merged_minus_tilt_yaw = input->merged_minus_tilt_yaw;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // filter_elapsed_time
  output->filter_elapsed_time = input->filter_elapsed_time;
  return true;
}

cola2_msgs__msg__ImuAngleEstimatorInfo *
cola2_msgs__msg__ImuAngleEstimatorInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__ImuAngleEstimatorInfo * msg = (cola2_msgs__msg__ImuAngleEstimatorInfo *)allocator.allocate(sizeof(cola2_msgs__msg__ImuAngleEstimatorInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cola2_msgs__msg__ImuAngleEstimatorInfo));
  bool success = cola2_msgs__msg__ImuAngleEstimatorInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cola2_msgs__msg__ImuAngleEstimatorInfo__destroy(cola2_msgs__msg__ImuAngleEstimatorInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cola2_msgs__msg__ImuAngleEstimatorInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__init(cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__ImuAngleEstimatorInfo * data = NULL;

  if (size) {
    data = (cola2_msgs__msg__ImuAngleEstimatorInfo *)allocator.zero_allocate(size, sizeof(cola2_msgs__msg__ImuAngleEstimatorInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cola2_msgs__msg__ImuAngleEstimatorInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cola2_msgs__msg__ImuAngleEstimatorInfo__fini(&data[i - 1]);
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
cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__fini(cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * array)
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
      cola2_msgs__msg__ImuAngleEstimatorInfo__fini(&array->data[i]);
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

cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence *
cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * array = (cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence *)allocator.allocate(sizeof(cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__destroy(cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__are_equal(const cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * lhs, const cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cola2_msgs__msg__ImuAngleEstimatorInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence__copy(
  const cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * input,
  cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cola2_msgs__msg__ImuAngleEstimatorInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cola2_msgs__msg__ImuAngleEstimatorInfo * data =
      (cola2_msgs__msg__ImuAngleEstimatorInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cola2_msgs__msg__ImuAngleEstimatorInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cola2_msgs__msg__ImuAngleEstimatorInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cola2_msgs__msg__ImuAngleEstimatorInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
