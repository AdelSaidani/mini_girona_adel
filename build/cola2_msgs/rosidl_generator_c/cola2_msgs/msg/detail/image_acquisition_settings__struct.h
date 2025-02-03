// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__STRUCT_H_
#define COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__STRUCT_H_

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
// Member 'extra'
#include "cola2_msgs/msg/detail/key_value__struct.h"

/// Struct defined in msg/ImageAcquisitionSettings in the package cola2_msgs.
typedef struct cola2_msgs__msg__ImageAcquisitionSettings
{
  std_msgs__msg__Header header;
  /// Exposure time in us (microseonds)
  uint32_t exposure_time;
  /// Gain in dB
  double gain;
  /// White balance blue ratio
  double blue_ratio;
  /// White balance red ratio
  double red_ratio;
  /// Focus distance (m)
  double focus;
  /// Aperture (f/#)
  double aperture;
  /// Focal length according to lens manufacturer (mm)
  double focal_length;
  /// Extra information
  cola2_msgs__msg__KeyValue__Sequence extra;
} cola2_msgs__msg__ImageAcquisitionSettings;

// Struct for a sequence of cola2_msgs__msg__ImageAcquisitionSettings.
typedef struct cola2_msgs__msg__ImageAcquisitionSettings__Sequence
{
  cola2_msgs__msg__ImageAcquisitionSettings * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cola2_msgs__msg__ImageAcquisitionSettings__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__STRUCT_H_
