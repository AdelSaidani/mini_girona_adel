// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__STRUCT_H_
#define COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ImuAngleEstimatorInfo in the package cola2_msgs.
typedef struct cola2_msgs__msg__ImuAngleEstimatorInfo
{
  std_msgs__msg__Header header;
  double period;
  double ax;
  double ay;
  double az;
  double mx;
  double my;
  double mz;
  double gx;
  double gy;
  double gz;
  double tilt_roll;
  double tilt_pitch;
  double tilt_yaw;
  double rate_tilt_roll;
  double rate_tilt_pitch;
  double rate_tilt_yaw;
  double tilt_angular_velocity_x;
  double tilt_angular_velocity_y;
  double tilt_angular_velocity_z;
  double bias_roll_from_this_iteration;
  double bias_pitch_from_this_iteration;
  double bias_yaw_from_this_iteration;
  double bias_roll;
  double bias_pitch;
  double bias_yaw;
  int32_t bias_buffer_size;
  double merging_filter_coefficient;
  double corrected_angular_velocity_x;
  double corrected_angular_velocity_y;
  double corrected_angular_velocity_z;
  double gyro_integrated_roll;
  double gyro_integrated_pitch;
  double gyro_integrated_yaw;
  double gyro_roll_innovation;
  double gyro_pitch_innovation;
  double gyro_yaw_innovation;
  double tilt_roll_innovation;
  double tilt_pitch_innovation;
  double tilt_yaw_innovation;
  double roll_innovation;
  double pitch_innovation;
  double yaw_innovation;
  double merged_roll;
  double merged_pitch;
  double merged_yaw;
  double merged_minus_tilt_roll;
  double merged_minus_tilt_pitch;
  double merged_minus_tilt_yaw;
  rosidl_runtime_c__String status;
  double filter_elapsed_time;
} cola2_msgs__msg__ImuAngleEstimatorInfo;

// Struct for a sequence of cola2_msgs__msg__ImuAngleEstimatorInfo.
typedef struct cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence
{
  cola2_msgs__msg__ImuAngleEstimatorInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cola2_msgs__msg__ImuAngleEstimatorInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__STRUCT_H_
