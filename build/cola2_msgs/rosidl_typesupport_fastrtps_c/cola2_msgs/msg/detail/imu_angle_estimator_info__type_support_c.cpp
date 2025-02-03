// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "cola2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__struct.h"
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // status
#include "rosidl_runtime_c/string_functions.h"  // status
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_cola2_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_cola2_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_cola2_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _ImuAngleEstimatorInfo__ros_msg_type = cola2_msgs__msg__ImuAngleEstimatorInfo;

static bool _ImuAngleEstimatorInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImuAngleEstimatorInfo__ros_msg_type * ros_message = static_cast<const _ImuAngleEstimatorInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: period
  {
    cdr << ros_message->period;
  }

  // Field name: ax
  {
    cdr << ros_message->ax;
  }

  // Field name: ay
  {
    cdr << ros_message->ay;
  }

  // Field name: az
  {
    cdr << ros_message->az;
  }

  // Field name: mx
  {
    cdr << ros_message->mx;
  }

  // Field name: my
  {
    cdr << ros_message->my;
  }

  // Field name: mz
  {
    cdr << ros_message->mz;
  }

  // Field name: gx
  {
    cdr << ros_message->gx;
  }

  // Field name: gy
  {
    cdr << ros_message->gy;
  }

  // Field name: gz
  {
    cdr << ros_message->gz;
  }

  // Field name: tilt_roll
  {
    cdr << ros_message->tilt_roll;
  }

  // Field name: tilt_pitch
  {
    cdr << ros_message->tilt_pitch;
  }

  // Field name: tilt_yaw
  {
    cdr << ros_message->tilt_yaw;
  }

  // Field name: rate_tilt_roll
  {
    cdr << ros_message->rate_tilt_roll;
  }

  // Field name: rate_tilt_pitch
  {
    cdr << ros_message->rate_tilt_pitch;
  }

  // Field name: rate_tilt_yaw
  {
    cdr << ros_message->rate_tilt_yaw;
  }

  // Field name: tilt_angular_velocity_x
  {
    cdr << ros_message->tilt_angular_velocity_x;
  }

  // Field name: tilt_angular_velocity_y
  {
    cdr << ros_message->tilt_angular_velocity_y;
  }

  // Field name: tilt_angular_velocity_z
  {
    cdr << ros_message->tilt_angular_velocity_z;
  }

  // Field name: bias_roll_from_this_iteration
  {
    cdr << ros_message->bias_roll_from_this_iteration;
  }

  // Field name: bias_pitch_from_this_iteration
  {
    cdr << ros_message->bias_pitch_from_this_iteration;
  }

  // Field name: bias_yaw_from_this_iteration
  {
    cdr << ros_message->bias_yaw_from_this_iteration;
  }

  // Field name: bias_roll
  {
    cdr << ros_message->bias_roll;
  }

  // Field name: bias_pitch
  {
    cdr << ros_message->bias_pitch;
  }

  // Field name: bias_yaw
  {
    cdr << ros_message->bias_yaw;
  }

  // Field name: bias_buffer_size
  {
    cdr << ros_message->bias_buffer_size;
  }

  // Field name: merging_filter_coefficient
  {
    cdr << ros_message->merging_filter_coefficient;
  }

  // Field name: corrected_angular_velocity_x
  {
    cdr << ros_message->corrected_angular_velocity_x;
  }

  // Field name: corrected_angular_velocity_y
  {
    cdr << ros_message->corrected_angular_velocity_y;
  }

  // Field name: corrected_angular_velocity_z
  {
    cdr << ros_message->corrected_angular_velocity_z;
  }

  // Field name: gyro_integrated_roll
  {
    cdr << ros_message->gyro_integrated_roll;
  }

  // Field name: gyro_integrated_pitch
  {
    cdr << ros_message->gyro_integrated_pitch;
  }

  // Field name: gyro_integrated_yaw
  {
    cdr << ros_message->gyro_integrated_yaw;
  }

  // Field name: gyro_roll_innovation
  {
    cdr << ros_message->gyro_roll_innovation;
  }

  // Field name: gyro_pitch_innovation
  {
    cdr << ros_message->gyro_pitch_innovation;
  }

  // Field name: gyro_yaw_innovation
  {
    cdr << ros_message->gyro_yaw_innovation;
  }

  // Field name: tilt_roll_innovation
  {
    cdr << ros_message->tilt_roll_innovation;
  }

  // Field name: tilt_pitch_innovation
  {
    cdr << ros_message->tilt_pitch_innovation;
  }

  // Field name: tilt_yaw_innovation
  {
    cdr << ros_message->tilt_yaw_innovation;
  }

  // Field name: roll_innovation
  {
    cdr << ros_message->roll_innovation;
  }

  // Field name: pitch_innovation
  {
    cdr << ros_message->pitch_innovation;
  }

  // Field name: yaw_innovation
  {
    cdr << ros_message->yaw_innovation;
  }

  // Field name: merged_roll
  {
    cdr << ros_message->merged_roll;
  }

  // Field name: merged_pitch
  {
    cdr << ros_message->merged_pitch;
  }

  // Field name: merged_yaw
  {
    cdr << ros_message->merged_yaw;
  }

  // Field name: merged_minus_tilt_roll
  {
    cdr << ros_message->merged_minus_tilt_roll;
  }

  // Field name: merged_minus_tilt_pitch
  {
    cdr << ros_message->merged_minus_tilt_pitch;
  }

  // Field name: merged_minus_tilt_yaw
  {
    cdr << ros_message->merged_minus_tilt_yaw;
  }

  // Field name: status
  {
    const rosidl_runtime_c__String * str = &ros_message->status;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: filter_elapsed_time
  {
    cdr << ros_message->filter_elapsed_time;
  }

  return true;
}

static bool _ImuAngleEstimatorInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImuAngleEstimatorInfo__ros_msg_type * ros_message = static_cast<_ImuAngleEstimatorInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: period
  {
    cdr >> ros_message->period;
  }

  // Field name: ax
  {
    cdr >> ros_message->ax;
  }

  // Field name: ay
  {
    cdr >> ros_message->ay;
  }

  // Field name: az
  {
    cdr >> ros_message->az;
  }

  // Field name: mx
  {
    cdr >> ros_message->mx;
  }

  // Field name: my
  {
    cdr >> ros_message->my;
  }

  // Field name: mz
  {
    cdr >> ros_message->mz;
  }

  // Field name: gx
  {
    cdr >> ros_message->gx;
  }

  // Field name: gy
  {
    cdr >> ros_message->gy;
  }

  // Field name: gz
  {
    cdr >> ros_message->gz;
  }

  // Field name: tilt_roll
  {
    cdr >> ros_message->tilt_roll;
  }

  // Field name: tilt_pitch
  {
    cdr >> ros_message->tilt_pitch;
  }

  // Field name: tilt_yaw
  {
    cdr >> ros_message->tilt_yaw;
  }

  // Field name: rate_tilt_roll
  {
    cdr >> ros_message->rate_tilt_roll;
  }

  // Field name: rate_tilt_pitch
  {
    cdr >> ros_message->rate_tilt_pitch;
  }

  // Field name: rate_tilt_yaw
  {
    cdr >> ros_message->rate_tilt_yaw;
  }

  // Field name: tilt_angular_velocity_x
  {
    cdr >> ros_message->tilt_angular_velocity_x;
  }

  // Field name: tilt_angular_velocity_y
  {
    cdr >> ros_message->tilt_angular_velocity_y;
  }

  // Field name: tilt_angular_velocity_z
  {
    cdr >> ros_message->tilt_angular_velocity_z;
  }

  // Field name: bias_roll_from_this_iteration
  {
    cdr >> ros_message->bias_roll_from_this_iteration;
  }

  // Field name: bias_pitch_from_this_iteration
  {
    cdr >> ros_message->bias_pitch_from_this_iteration;
  }

  // Field name: bias_yaw_from_this_iteration
  {
    cdr >> ros_message->bias_yaw_from_this_iteration;
  }

  // Field name: bias_roll
  {
    cdr >> ros_message->bias_roll;
  }

  // Field name: bias_pitch
  {
    cdr >> ros_message->bias_pitch;
  }

  // Field name: bias_yaw
  {
    cdr >> ros_message->bias_yaw;
  }

  // Field name: bias_buffer_size
  {
    cdr >> ros_message->bias_buffer_size;
  }

  // Field name: merging_filter_coefficient
  {
    cdr >> ros_message->merging_filter_coefficient;
  }

  // Field name: corrected_angular_velocity_x
  {
    cdr >> ros_message->corrected_angular_velocity_x;
  }

  // Field name: corrected_angular_velocity_y
  {
    cdr >> ros_message->corrected_angular_velocity_y;
  }

  // Field name: corrected_angular_velocity_z
  {
    cdr >> ros_message->corrected_angular_velocity_z;
  }

  // Field name: gyro_integrated_roll
  {
    cdr >> ros_message->gyro_integrated_roll;
  }

  // Field name: gyro_integrated_pitch
  {
    cdr >> ros_message->gyro_integrated_pitch;
  }

  // Field name: gyro_integrated_yaw
  {
    cdr >> ros_message->gyro_integrated_yaw;
  }

  // Field name: gyro_roll_innovation
  {
    cdr >> ros_message->gyro_roll_innovation;
  }

  // Field name: gyro_pitch_innovation
  {
    cdr >> ros_message->gyro_pitch_innovation;
  }

  // Field name: gyro_yaw_innovation
  {
    cdr >> ros_message->gyro_yaw_innovation;
  }

  // Field name: tilt_roll_innovation
  {
    cdr >> ros_message->tilt_roll_innovation;
  }

  // Field name: tilt_pitch_innovation
  {
    cdr >> ros_message->tilt_pitch_innovation;
  }

  // Field name: tilt_yaw_innovation
  {
    cdr >> ros_message->tilt_yaw_innovation;
  }

  // Field name: roll_innovation
  {
    cdr >> ros_message->roll_innovation;
  }

  // Field name: pitch_innovation
  {
    cdr >> ros_message->pitch_innovation;
  }

  // Field name: yaw_innovation
  {
    cdr >> ros_message->yaw_innovation;
  }

  // Field name: merged_roll
  {
    cdr >> ros_message->merged_roll;
  }

  // Field name: merged_pitch
  {
    cdr >> ros_message->merged_pitch;
  }

  // Field name: merged_yaw
  {
    cdr >> ros_message->merged_yaw;
  }

  // Field name: merged_minus_tilt_roll
  {
    cdr >> ros_message->merged_minus_tilt_roll;
  }

  // Field name: merged_minus_tilt_pitch
  {
    cdr >> ros_message->merged_minus_tilt_pitch;
  }

  // Field name: merged_minus_tilt_yaw
  {
    cdr >> ros_message->merged_minus_tilt_yaw;
  }

  // Field name: status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->status.data) {
      rosidl_runtime_c__String__init(&ros_message->status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'status'\n");
      return false;
    }
  }

  // Field name: filter_elapsed_time
  {
    cdr >> ros_message->filter_elapsed_time;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cola2_msgs
size_t get_serialized_size_cola2_msgs__msg__ImuAngleEstimatorInfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImuAngleEstimatorInfo__ros_msg_type * ros_message = static_cast<const _ImuAngleEstimatorInfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name period
  {
    size_t item_size = sizeof(ros_message->period);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ax
  {
    size_t item_size = sizeof(ros_message->ax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ay
  {
    size_t item_size = sizeof(ros_message->ay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name az
  {
    size_t item_size = sizeof(ros_message->az);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mx
  {
    size_t item_size = sizeof(ros_message->mx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name my
  {
    size_t item_size = sizeof(ros_message->my);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mz
  {
    size_t item_size = sizeof(ros_message->mz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gx
  {
    size_t item_size = sizeof(ros_message->gx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gy
  {
    size_t item_size = sizeof(ros_message->gy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gz
  {
    size_t item_size = sizeof(ros_message->gz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_roll
  {
    size_t item_size = sizeof(ros_message->tilt_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_pitch
  {
    size_t item_size = sizeof(ros_message->tilt_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_yaw
  {
    size_t item_size = sizeof(ros_message->tilt_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rate_tilt_roll
  {
    size_t item_size = sizeof(ros_message->rate_tilt_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rate_tilt_pitch
  {
    size_t item_size = sizeof(ros_message->rate_tilt_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rate_tilt_yaw
  {
    size_t item_size = sizeof(ros_message->rate_tilt_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_angular_velocity_x
  {
    size_t item_size = sizeof(ros_message->tilt_angular_velocity_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_angular_velocity_y
  {
    size_t item_size = sizeof(ros_message->tilt_angular_velocity_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_angular_velocity_z
  {
    size_t item_size = sizeof(ros_message->tilt_angular_velocity_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bias_roll_from_this_iteration
  {
    size_t item_size = sizeof(ros_message->bias_roll_from_this_iteration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bias_pitch_from_this_iteration
  {
    size_t item_size = sizeof(ros_message->bias_pitch_from_this_iteration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bias_yaw_from_this_iteration
  {
    size_t item_size = sizeof(ros_message->bias_yaw_from_this_iteration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bias_roll
  {
    size_t item_size = sizeof(ros_message->bias_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bias_pitch
  {
    size_t item_size = sizeof(ros_message->bias_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bias_yaw
  {
    size_t item_size = sizeof(ros_message->bias_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bias_buffer_size
  {
    size_t item_size = sizeof(ros_message->bias_buffer_size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name merging_filter_coefficient
  {
    size_t item_size = sizeof(ros_message->merging_filter_coefficient);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name corrected_angular_velocity_x
  {
    size_t item_size = sizeof(ros_message->corrected_angular_velocity_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name corrected_angular_velocity_y
  {
    size_t item_size = sizeof(ros_message->corrected_angular_velocity_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name corrected_angular_velocity_z
  {
    size_t item_size = sizeof(ros_message->corrected_angular_velocity_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_integrated_roll
  {
    size_t item_size = sizeof(ros_message->gyro_integrated_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_integrated_pitch
  {
    size_t item_size = sizeof(ros_message->gyro_integrated_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_integrated_yaw
  {
    size_t item_size = sizeof(ros_message->gyro_integrated_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_roll_innovation
  {
    size_t item_size = sizeof(ros_message->gyro_roll_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_pitch_innovation
  {
    size_t item_size = sizeof(ros_message->gyro_pitch_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_yaw_innovation
  {
    size_t item_size = sizeof(ros_message->gyro_yaw_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_roll_innovation
  {
    size_t item_size = sizeof(ros_message->tilt_roll_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_pitch_innovation
  {
    size_t item_size = sizeof(ros_message->tilt_pitch_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tilt_yaw_innovation
  {
    size_t item_size = sizeof(ros_message->tilt_yaw_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name roll_innovation
  {
    size_t item_size = sizeof(ros_message->roll_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_innovation
  {
    size_t item_size = sizeof(ros_message->pitch_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_innovation
  {
    size_t item_size = sizeof(ros_message->yaw_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name merged_roll
  {
    size_t item_size = sizeof(ros_message->merged_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name merged_pitch
  {
    size_t item_size = sizeof(ros_message->merged_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name merged_yaw
  {
    size_t item_size = sizeof(ros_message->merged_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name merged_minus_tilt_roll
  {
    size_t item_size = sizeof(ros_message->merged_minus_tilt_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name merged_minus_tilt_pitch
  {
    size_t item_size = sizeof(ros_message->merged_minus_tilt_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name merged_minus_tilt_yaw
  {
    size_t item_size = sizeof(ros_message->merged_minus_tilt_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->status.size + 1);
  // field.name filter_elapsed_time
  {
    size_t item_size = sizeof(ros_message->filter_elapsed_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ImuAngleEstimatorInfo__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cola2_msgs__msg__ImuAngleEstimatorInfo(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cola2_msgs
size_t max_serialized_size_cola2_msgs__msg__ImuAngleEstimatorInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: period
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ay
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: az
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: mx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: my
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: mz
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gz
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rate_tilt_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rate_tilt_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rate_tilt_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_angular_velocity_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_angular_velocity_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_angular_velocity_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bias_roll_from_this_iteration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bias_pitch_from_this_iteration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bias_yaw_from_this_iteration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bias_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bias_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bias_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bias_buffer_size
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: merging_filter_coefficient
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: corrected_angular_velocity_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: corrected_angular_velocity_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: corrected_angular_velocity_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyro_integrated_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyro_integrated_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyro_integrated_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyro_roll_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyro_pitch_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyro_yaw_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_roll_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_pitch_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tilt_yaw_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: roll_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: pitch_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: yaw_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: merged_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: merged_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: merged_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: merged_minus_tilt_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: merged_minus_tilt_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: merged_minus_tilt_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: status
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: filter_elapsed_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = cola2_msgs__msg__ImuAngleEstimatorInfo;
    is_plain =
      (
      offsetof(DataType, filter_elapsed_time) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ImuAngleEstimatorInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cola2_msgs__msg__ImuAngleEstimatorInfo(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ImuAngleEstimatorInfo = {
  "cola2_msgs::msg",
  "ImuAngleEstimatorInfo",
  _ImuAngleEstimatorInfo__cdr_serialize,
  _ImuAngleEstimatorInfo__cdr_deserialize,
  _ImuAngleEstimatorInfo__get_serialized_size,
  _ImuAngleEstimatorInfo__max_serialized_size
};

static rosidl_message_type_support_t _ImuAngleEstimatorInfo__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImuAngleEstimatorInfo,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cola2_msgs, msg, ImuAngleEstimatorInfo)() {
  return &_ImuAngleEstimatorInfo__type_support;
}

#if defined(__cplusplus)
}
#endif
