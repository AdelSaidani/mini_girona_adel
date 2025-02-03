// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cola2_msgs:msg/AdisImu.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__ADIS_IMU__STRUCT_H_
#define COLA2_MSGS__MSG__DETAIL__ADIS_IMU__STRUCT_H_

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
// Member 'raw'
// Member 'f'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AdisImu in the package cola2_msgs.
typedef struct cola2_msgs__msg__AdisImu
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String raw;
  double mx;
  double my;
  double mz;
  double gx;
  double gy;
  double gz;
  double ax;
  double ay;
  double az;
  double t;
  double b;
  rosidl_runtime_c__String f;
  double e;
  double w;
} cola2_msgs__msg__AdisImu;

// Struct for a sequence of cola2_msgs__msg__AdisImu.
typedef struct cola2_msgs__msg__AdisImu__Sequence
{
  cola2_msgs__msg__AdisImu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cola2_msgs__msg__AdisImu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COLA2_MSGS__MSG__DETAIL__ADIS_IMU__STRUCT_H_
