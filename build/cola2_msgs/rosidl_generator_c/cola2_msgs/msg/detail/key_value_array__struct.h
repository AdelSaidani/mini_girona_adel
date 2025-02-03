// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cola2_msgs:msg/KeyValueArray.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__STRUCT_H_
#define COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'keyvalues'
#include "cola2_msgs/msg/detail/key_value__struct.h"

/// Struct defined in msg/KeyValueArray in the package cola2_msgs.
typedef struct cola2_msgs__msg__KeyValueArray
{
  cola2_msgs__msg__KeyValue__Sequence keyvalues;
} cola2_msgs__msg__KeyValueArray;

// Struct for a sequence of cola2_msgs__msg__KeyValueArray.
typedef struct cola2_msgs__msg__KeyValueArray__Sequence
{
  cola2_msgs__msg__KeyValueArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cola2_msgs__msg__KeyValueArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__STRUCT_H_
