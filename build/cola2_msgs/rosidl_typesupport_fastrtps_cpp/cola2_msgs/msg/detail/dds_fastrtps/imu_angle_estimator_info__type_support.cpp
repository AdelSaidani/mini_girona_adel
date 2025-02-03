// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace cola2_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cola2_msgs
cdr_serialize(
  const cola2_msgs::msg::ImuAngleEstimatorInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: period
  cdr << ros_message.period;
  // Member: ax
  cdr << ros_message.ax;
  // Member: ay
  cdr << ros_message.ay;
  // Member: az
  cdr << ros_message.az;
  // Member: mx
  cdr << ros_message.mx;
  // Member: my
  cdr << ros_message.my;
  // Member: mz
  cdr << ros_message.mz;
  // Member: gx
  cdr << ros_message.gx;
  // Member: gy
  cdr << ros_message.gy;
  // Member: gz
  cdr << ros_message.gz;
  // Member: tilt_roll
  cdr << ros_message.tilt_roll;
  // Member: tilt_pitch
  cdr << ros_message.tilt_pitch;
  // Member: tilt_yaw
  cdr << ros_message.tilt_yaw;
  // Member: rate_tilt_roll
  cdr << ros_message.rate_tilt_roll;
  // Member: rate_tilt_pitch
  cdr << ros_message.rate_tilt_pitch;
  // Member: rate_tilt_yaw
  cdr << ros_message.rate_tilt_yaw;
  // Member: tilt_angular_velocity_x
  cdr << ros_message.tilt_angular_velocity_x;
  // Member: tilt_angular_velocity_y
  cdr << ros_message.tilt_angular_velocity_y;
  // Member: tilt_angular_velocity_z
  cdr << ros_message.tilt_angular_velocity_z;
  // Member: bias_roll_from_this_iteration
  cdr << ros_message.bias_roll_from_this_iteration;
  // Member: bias_pitch_from_this_iteration
  cdr << ros_message.bias_pitch_from_this_iteration;
  // Member: bias_yaw_from_this_iteration
  cdr << ros_message.bias_yaw_from_this_iteration;
  // Member: bias_roll
  cdr << ros_message.bias_roll;
  // Member: bias_pitch
  cdr << ros_message.bias_pitch;
  // Member: bias_yaw
  cdr << ros_message.bias_yaw;
  // Member: bias_buffer_size
  cdr << ros_message.bias_buffer_size;
  // Member: merging_filter_coefficient
  cdr << ros_message.merging_filter_coefficient;
  // Member: corrected_angular_velocity_x
  cdr << ros_message.corrected_angular_velocity_x;
  // Member: corrected_angular_velocity_y
  cdr << ros_message.corrected_angular_velocity_y;
  // Member: corrected_angular_velocity_z
  cdr << ros_message.corrected_angular_velocity_z;
  // Member: gyro_integrated_roll
  cdr << ros_message.gyro_integrated_roll;
  // Member: gyro_integrated_pitch
  cdr << ros_message.gyro_integrated_pitch;
  // Member: gyro_integrated_yaw
  cdr << ros_message.gyro_integrated_yaw;
  // Member: gyro_roll_innovation
  cdr << ros_message.gyro_roll_innovation;
  // Member: gyro_pitch_innovation
  cdr << ros_message.gyro_pitch_innovation;
  // Member: gyro_yaw_innovation
  cdr << ros_message.gyro_yaw_innovation;
  // Member: tilt_roll_innovation
  cdr << ros_message.tilt_roll_innovation;
  // Member: tilt_pitch_innovation
  cdr << ros_message.tilt_pitch_innovation;
  // Member: tilt_yaw_innovation
  cdr << ros_message.tilt_yaw_innovation;
  // Member: roll_innovation
  cdr << ros_message.roll_innovation;
  // Member: pitch_innovation
  cdr << ros_message.pitch_innovation;
  // Member: yaw_innovation
  cdr << ros_message.yaw_innovation;
  // Member: merged_roll
  cdr << ros_message.merged_roll;
  // Member: merged_pitch
  cdr << ros_message.merged_pitch;
  // Member: merged_yaw
  cdr << ros_message.merged_yaw;
  // Member: merged_minus_tilt_roll
  cdr << ros_message.merged_minus_tilt_roll;
  // Member: merged_minus_tilt_pitch
  cdr << ros_message.merged_minus_tilt_pitch;
  // Member: merged_minus_tilt_yaw
  cdr << ros_message.merged_minus_tilt_yaw;
  // Member: status
  cdr << ros_message.status;
  // Member: filter_elapsed_time
  cdr << ros_message.filter_elapsed_time;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cola2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cola2_msgs::msg::ImuAngleEstimatorInfo & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: period
  cdr >> ros_message.period;

  // Member: ax
  cdr >> ros_message.ax;

  // Member: ay
  cdr >> ros_message.ay;

  // Member: az
  cdr >> ros_message.az;

  // Member: mx
  cdr >> ros_message.mx;

  // Member: my
  cdr >> ros_message.my;

  // Member: mz
  cdr >> ros_message.mz;

  // Member: gx
  cdr >> ros_message.gx;

  // Member: gy
  cdr >> ros_message.gy;

  // Member: gz
  cdr >> ros_message.gz;

  // Member: tilt_roll
  cdr >> ros_message.tilt_roll;

  // Member: tilt_pitch
  cdr >> ros_message.tilt_pitch;

  // Member: tilt_yaw
  cdr >> ros_message.tilt_yaw;

  // Member: rate_tilt_roll
  cdr >> ros_message.rate_tilt_roll;

  // Member: rate_tilt_pitch
  cdr >> ros_message.rate_tilt_pitch;

  // Member: rate_tilt_yaw
  cdr >> ros_message.rate_tilt_yaw;

  // Member: tilt_angular_velocity_x
  cdr >> ros_message.tilt_angular_velocity_x;

  // Member: tilt_angular_velocity_y
  cdr >> ros_message.tilt_angular_velocity_y;

  // Member: tilt_angular_velocity_z
  cdr >> ros_message.tilt_angular_velocity_z;

  // Member: bias_roll_from_this_iteration
  cdr >> ros_message.bias_roll_from_this_iteration;

  // Member: bias_pitch_from_this_iteration
  cdr >> ros_message.bias_pitch_from_this_iteration;

  // Member: bias_yaw_from_this_iteration
  cdr >> ros_message.bias_yaw_from_this_iteration;

  // Member: bias_roll
  cdr >> ros_message.bias_roll;

  // Member: bias_pitch
  cdr >> ros_message.bias_pitch;

  // Member: bias_yaw
  cdr >> ros_message.bias_yaw;

  // Member: bias_buffer_size
  cdr >> ros_message.bias_buffer_size;

  // Member: merging_filter_coefficient
  cdr >> ros_message.merging_filter_coefficient;

  // Member: corrected_angular_velocity_x
  cdr >> ros_message.corrected_angular_velocity_x;

  // Member: corrected_angular_velocity_y
  cdr >> ros_message.corrected_angular_velocity_y;

  // Member: corrected_angular_velocity_z
  cdr >> ros_message.corrected_angular_velocity_z;

  // Member: gyro_integrated_roll
  cdr >> ros_message.gyro_integrated_roll;

  // Member: gyro_integrated_pitch
  cdr >> ros_message.gyro_integrated_pitch;

  // Member: gyro_integrated_yaw
  cdr >> ros_message.gyro_integrated_yaw;

  // Member: gyro_roll_innovation
  cdr >> ros_message.gyro_roll_innovation;

  // Member: gyro_pitch_innovation
  cdr >> ros_message.gyro_pitch_innovation;

  // Member: gyro_yaw_innovation
  cdr >> ros_message.gyro_yaw_innovation;

  // Member: tilt_roll_innovation
  cdr >> ros_message.tilt_roll_innovation;

  // Member: tilt_pitch_innovation
  cdr >> ros_message.tilt_pitch_innovation;

  // Member: tilt_yaw_innovation
  cdr >> ros_message.tilt_yaw_innovation;

  // Member: roll_innovation
  cdr >> ros_message.roll_innovation;

  // Member: pitch_innovation
  cdr >> ros_message.pitch_innovation;

  // Member: yaw_innovation
  cdr >> ros_message.yaw_innovation;

  // Member: merged_roll
  cdr >> ros_message.merged_roll;

  // Member: merged_pitch
  cdr >> ros_message.merged_pitch;

  // Member: merged_yaw
  cdr >> ros_message.merged_yaw;

  // Member: merged_minus_tilt_roll
  cdr >> ros_message.merged_minus_tilt_roll;

  // Member: merged_minus_tilt_pitch
  cdr >> ros_message.merged_minus_tilt_pitch;

  // Member: merged_minus_tilt_yaw
  cdr >> ros_message.merged_minus_tilt_yaw;

  // Member: status
  cdr >> ros_message.status;

  // Member: filter_elapsed_time
  cdr >> ros_message.filter_elapsed_time;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cola2_msgs
get_serialized_size(
  const cola2_msgs::msg::ImuAngleEstimatorInfo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: period
  {
    size_t item_size = sizeof(ros_message.period);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ax
  {
    size_t item_size = sizeof(ros_message.ax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ay
  {
    size_t item_size = sizeof(ros_message.ay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: az
  {
    size_t item_size = sizeof(ros_message.az);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mx
  {
    size_t item_size = sizeof(ros_message.mx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: my
  {
    size_t item_size = sizeof(ros_message.my);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mz
  {
    size_t item_size = sizeof(ros_message.mz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gx
  {
    size_t item_size = sizeof(ros_message.gx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gy
  {
    size_t item_size = sizeof(ros_message.gy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gz
  {
    size_t item_size = sizeof(ros_message.gz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_roll
  {
    size_t item_size = sizeof(ros_message.tilt_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_pitch
  {
    size_t item_size = sizeof(ros_message.tilt_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_yaw
  {
    size_t item_size = sizeof(ros_message.tilt_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rate_tilt_roll
  {
    size_t item_size = sizeof(ros_message.rate_tilt_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rate_tilt_pitch
  {
    size_t item_size = sizeof(ros_message.rate_tilt_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rate_tilt_yaw
  {
    size_t item_size = sizeof(ros_message.rate_tilt_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_angular_velocity_x
  {
    size_t item_size = sizeof(ros_message.tilt_angular_velocity_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_angular_velocity_y
  {
    size_t item_size = sizeof(ros_message.tilt_angular_velocity_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_angular_velocity_z
  {
    size_t item_size = sizeof(ros_message.tilt_angular_velocity_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bias_roll_from_this_iteration
  {
    size_t item_size = sizeof(ros_message.bias_roll_from_this_iteration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bias_pitch_from_this_iteration
  {
    size_t item_size = sizeof(ros_message.bias_pitch_from_this_iteration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bias_yaw_from_this_iteration
  {
    size_t item_size = sizeof(ros_message.bias_yaw_from_this_iteration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bias_roll
  {
    size_t item_size = sizeof(ros_message.bias_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bias_pitch
  {
    size_t item_size = sizeof(ros_message.bias_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bias_yaw
  {
    size_t item_size = sizeof(ros_message.bias_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bias_buffer_size
  {
    size_t item_size = sizeof(ros_message.bias_buffer_size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: merging_filter_coefficient
  {
    size_t item_size = sizeof(ros_message.merging_filter_coefficient);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: corrected_angular_velocity_x
  {
    size_t item_size = sizeof(ros_message.corrected_angular_velocity_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: corrected_angular_velocity_y
  {
    size_t item_size = sizeof(ros_message.corrected_angular_velocity_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: corrected_angular_velocity_z
  {
    size_t item_size = sizeof(ros_message.corrected_angular_velocity_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_integrated_roll
  {
    size_t item_size = sizeof(ros_message.gyro_integrated_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_integrated_pitch
  {
    size_t item_size = sizeof(ros_message.gyro_integrated_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_integrated_yaw
  {
    size_t item_size = sizeof(ros_message.gyro_integrated_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_roll_innovation
  {
    size_t item_size = sizeof(ros_message.gyro_roll_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_pitch_innovation
  {
    size_t item_size = sizeof(ros_message.gyro_pitch_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_yaw_innovation
  {
    size_t item_size = sizeof(ros_message.gyro_yaw_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_roll_innovation
  {
    size_t item_size = sizeof(ros_message.tilt_roll_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_pitch_innovation
  {
    size_t item_size = sizeof(ros_message.tilt_pitch_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tilt_yaw_innovation
  {
    size_t item_size = sizeof(ros_message.tilt_yaw_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: roll_innovation
  {
    size_t item_size = sizeof(ros_message.roll_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pitch_innovation
  {
    size_t item_size = sizeof(ros_message.pitch_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yaw_innovation
  {
    size_t item_size = sizeof(ros_message.yaw_innovation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: merged_roll
  {
    size_t item_size = sizeof(ros_message.merged_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: merged_pitch
  {
    size_t item_size = sizeof(ros_message.merged_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: merged_yaw
  {
    size_t item_size = sizeof(ros_message.merged_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: merged_minus_tilt_roll
  {
    size_t item_size = sizeof(ros_message.merged_minus_tilt_roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: merged_minus_tilt_pitch
  {
    size_t item_size = sizeof(ros_message.merged_minus_tilt_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: merged_minus_tilt_yaw
  {
    size_t item_size = sizeof(ros_message.merged_minus_tilt_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.status.size() + 1);
  // Member: filter_elapsed_time
  {
    size_t item_size = sizeof(ros_message.filter_elapsed_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cola2_msgs
max_serialized_size_ImuAngleEstimatorInfo(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: period
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ay
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: az
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: my
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mz
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gz
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: rate_tilt_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: rate_tilt_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: rate_tilt_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_angular_velocity_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_angular_velocity_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_angular_velocity_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bias_roll_from_this_iteration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bias_pitch_from_this_iteration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bias_yaw_from_this_iteration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bias_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bias_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bias_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bias_buffer_size
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: merging_filter_coefficient
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: corrected_angular_velocity_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: corrected_angular_velocity_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: corrected_angular_velocity_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gyro_integrated_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gyro_integrated_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gyro_integrated_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gyro_roll_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gyro_pitch_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gyro_yaw_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_roll_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_pitch_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tilt_yaw_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: roll_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pitch_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: yaw_innovation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: merged_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: merged_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: merged_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: merged_minus_tilt_roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: merged_minus_tilt_pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: merged_minus_tilt_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: status
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

  // Member: filter_elapsed_time
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
    using DataType = cola2_msgs::msg::ImuAngleEstimatorInfo;
    is_plain =
      (
      offsetof(DataType, filter_elapsed_time) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ImuAngleEstimatorInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cola2_msgs::msg::ImuAngleEstimatorInfo *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ImuAngleEstimatorInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cola2_msgs::msg::ImuAngleEstimatorInfo *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ImuAngleEstimatorInfo__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cola2_msgs::msg::ImuAngleEstimatorInfo *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ImuAngleEstimatorInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ImuAngleEstimatorInfo(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ImuAngleEstimatorInfo__callbacks = {
  "cola2_msgs::msg",
  "ImuAngleEstimatorInfo",
  _ImuAngleEstimatorInfo__cdr_serialize,
  _ImuAngleEstimatorInfo__cdr_deserialize,
  _ImuAngleEstimatorInfo__get_serialized_size,
  _ImuAngleEstimatorInfo__max_serialized_size
};

static rosidl_message_type_support_t _ImuAngleEstimatorInfo__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ImuAngleEstimatorInfo__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace cola2_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cola2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<cola2_msgs::msg::ImuAngleEstimatorInfo>()
{
  return &cola2_msgs::msg::typesupport_fastrtps_cpp::_ImuAngleEstimatorInfo__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cola2_msgs, msg, ImuAngleEstimatorInfo)() {
  return &cola2_msgs::msg::typesupport_fastrtps_cpp::_ImuAngleEstimatorInfo__handle;
}

#ifdef __cplusplus
}
#endif
