// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cola2_msgs:msg/FlsConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__STRUCT_H_
#define COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__STRUCT_H_

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
// Member 'beams_bearings'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/FlsConfig in the package cola2_msgs.
/**
  * This message must be tied to a sensor_msgs/Image message that contains the corresponding polar image. The header 
  * timestamp of both messages must be exactly the same.
  * The polar image's first row must correspond to the farthest return sample, with the last row being the closest return
  * sample.
  * The polar image's first column must correspond to the leftmost beam from the POV of the FLS sensor (negative angle 
  * value), with the last column being the rightmost beam (positive angle value).
 */
typedef struct cola2_msgs__msg__FlsConfig
{
  std_msgs__msg__Header header;
  uint32_t num_beams;
  uint32_t num_samples;
  /// In meters.
  double window_start;
  /// In meters
  double window_end;
  /// In radians
  rosidl_runtime_c__float__Sequence beams_bearings;
  /// In m/s
  double speed_of_sound;
  /// In Hz
  double ping_rate;
  /// In Hz
  double frequency;
} cola2_msgs__msg__FlsConfig;

// Struct for a sequence of cola2_msgs__msg__FlsConfig.
typedef struct cola2_msgs__msg__FlsConfig__Sequence
{
  cola2_msgs__msg__FlsConfig * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cola2_msgs__msg__FlsConfig__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__STRUCT_H_
