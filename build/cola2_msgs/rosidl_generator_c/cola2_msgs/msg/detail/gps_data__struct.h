// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cola2_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_H_
#define COLA2_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_H_

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
// Member 'time_utc'
// Member 'raw_gpgga'
// Member 'raw_gphdt'
// Member 'raw_gpgst'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GPSData in the package cola2_msgs.
typedef struct cola2_msgs__msg__GPSData
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String time_utc;
  double latitude;
  double longitude;
  int32_t fix_quality;
  int32_t number_of_satellites;
  float hdop;
  float altitude;
  float geoidal_separation;
  float heading;
  float latitude_stdev;
  float longitude_stdev;
  float altitude_stdev;
  rosidl_runtime_c__String raw_gpgga;
  rosidl_runtime_c__String raw_gphdt;
  rosidl_runtime_c__String raw_gpgst;
} cola2_msgs__msg__GPSData;

// Struct for a sequence of cola2_msgs__msg__GPSData.
typedef struct cola2_msgs__msg__GPSData__Sequence
{
  cola2_msgs__msg__GPSData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cola2_msgs__msg__GPSData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COLA2_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_H_
