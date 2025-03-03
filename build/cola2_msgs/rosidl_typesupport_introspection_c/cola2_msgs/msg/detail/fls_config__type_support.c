// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cola2_msgs:msg/FlsConfig.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cola2_msgs/msg/detail/fls_config__rosidl_typesupport_introspection_c.h"
#include "cola2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cola2_msgs/msg/detail/fls_config__functions.h"
#include "cola2_msgs/msg/detail/fls_config__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `beams_bearings`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cola2_msgs__msg__FlsConfig__init(message_memory);
}

void cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_fini_function(void * message_memory)
{
  cola2_msgs__msg__FlsConfig__fini(message_memory);
}

size_t cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__size_function__FlsConfig__beams_bearings(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__get_const_function__FlsConfig__beams_bearings(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__get_function__FlsConfig__beams_bearings(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__fetch_function__FlsConfig__beams_bearings(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__get_const_function__FlsConfig__beams_bearings(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__assign_function__FlsConfig__beams_bearings(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__get_function__FlsConfig__beams_bearings(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__resize_function__FlsConfig__beams_bearings(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_member_array[9] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_beams",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, num_beams),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_samples",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, num_samples),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "window_start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, window_start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "window_end",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, window_end),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "beams_bearings",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, beams_bearings),  // bytes offset in struct
    NULL,  // default value
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__size_function__FlsConfig__beams_bearings,  // size() function pointer
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__get_const_function__FlsConfig__beams_bearings,  // get_const(index) function pointer
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__get_function__FlsConfig__beams_bearings,  // get(index) function pointer
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__fetch_function__FlsConfig__beams_bearings,  // fetch(index, &value) function pointer
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__assign_function__FlsConfig__beams_bearings,  // assign(index, value) function pointer
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__resize_function__FlsConfig__beams_bearings  // resize(index) function pointer
  },
  {
    "speed_of_sound",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, speed_of_sound),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ping_rate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, ping_rate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frequency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs__msg__FlsConfig, frequency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_members = {
  "cola2_msgs__msg",  // message namespace
  "FlsConfig",  // message name
  9,  // number of fields
  sizeof(cola2_msgs__msg__FlsConfig),
  cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_member_array,  // message members
  cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_init_function,  // function to initialize message memory (memory has to be allocated)
  cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_type_support_handle = {
  0,
  &cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cola2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cola2_msgs, msg, FlsConfig)() {
  cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_type_support_handle.typesupport_identifier) {
    cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cola2_msgs__msg__FlsConfig__rosidl_typesupport_introspection_c__FlsConfig_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
