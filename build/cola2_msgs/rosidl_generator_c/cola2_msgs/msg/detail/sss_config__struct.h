// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cola2_msgs:msg/SSSConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__STRUCT_H_
#define COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__STRUCT_H_

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

/// Struct defined in msg/SSSConfig in the package cola2_msgs.
typedef struct cola2_msgs__msg__SSSConfig
{
  std_msgs__msg__Header header;
  uint32_t samples_per_channel;
  /// In meters
  double range_delay;
  /// In meters
  double range;
  /// Radians Set to 0 if unknown.
  double horizontal_beam_angle;
  /// Radians Set to 0 if unknown.
  double vertical_beam_angle;
  /// In m/s
  double speed_of_sound;
  /// In Hz
  double ping_rate;
  /// In Hz
  double frequency;
} cola2_msgs__msg__SSSConfig;

// Struct for a sequence of cola2_msgs__msg__SSSConfig.
typedef struct cola2_msgs__msg__SSSConfig__Sequence
{
  cola2_msgs__msg__SSSConfig * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cola2_msgs__msg__SSSConfig__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__STRUCT_H_
