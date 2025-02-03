// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/msg/detail/imu_angle_estimator_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cola2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImuAngleEstimatorInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: period
  {
    out << "period: ";
    rosidl_generator_traits::value_to_yaml(msg.period, out);
    out << ", ";
  }

  // member: ax
  {
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << ", ";
  }

  // member: ay
  {
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << ", ";
  }

  // member: az
  {
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
    out << ", ";
  }

  // member: mx
  {
    out << "mx: ";
    rosidl_generator_traits::value_to_yaml(msg.mx, out);
    out << ", ";
  }

  // member: my
  {
    out << "my: ";
    rosidl_generator_traits::value_to_yaml(msg.my, out);
    out << ", ";
  }

  // member: mz
  {
    out << "mz: ";
    rosidl_generator_traits::value_to_yaml(msg.mz, out);
    out << ", ";
  }

  // member: gx
  {
    out << "gx: ";
    rosidl_generator_traits::value_to_yaml(msg.gx, out);
    out << ", ";
  }

  // member: gy
  {
    out << "gy: ";
    rosidl_generator_traits::value_to_yaml(msg.gy, out);
    out << ", ";
  }

  // member: gz
  {
    out << "gz: ";
    rosidl_generator_traits::value_to_yaml(msg.gz, out);
    out << ", ";
  }

  // member: tilt_roll
  {
    out << "tilt_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_roll, out);
    out << ", ";
  }

  // member: tilt_pitch
  {
    out << "tilt_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_pitch, out);
    out << ", ";
  }

  // member: tilt_yaw
  {
    out << "tilt_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_yaw, out);
    out << ", ";
  }

  // member: rate_tilt_roll
  {
    out << "rate_tilt_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.rate_tilt_roll, out);
    out << ", ";
  }

  // member: rate_tilt_pitch
  {
    out << "rate_tilt_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.rate_tilt_pitch, out);
    out << ", ";
  }

  // member: rate_tilt_yaw
  {
    out << "rate_tilt_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.rate_tilt_yaw, out);
    out << ", ";
  }

  // member: tilt_angular_velocity_x
  {
    out << "tilt_angular_velocity_x: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_angular_velocity_x, out);
    out << ", ";
  }

  // member: tilt_angular_velocity_y
  {
    out << "tilt_angular_velocity_y: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_angular_velocity_y, out);
    out << ", ";
  }

  // member: tilt_angular_velocity_z
  {
    out << "tilt_angular_velocity_z: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_angular_velocity_z, out);
    out << ", ";
  }

  // member: bias_roll_from_this_iteration
  {
    out << "bias_roll_from_this_iteration: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_roll_from_this_iteration, out);
    out << ", ";
  }

  // member: bias_pitch_from_this_iteration
  {
    out << "bias_pitch_from_this_iteration: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_pitch_from_this_iteration, out);
    out << ", ";
  }

  // member: bias_yaw_from_this_iteration
  {
    out << "bias_yaw_from_this_iteration: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_yaw_from_this_iteration, out);
    out << ", ";
  }

  // member: bias_roll
  {
    out << "bias_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_roll, out);
    out << ", ";
  }

  // member: bias_pitch
  {
    out << "bias_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_pitch, out);
    out << ", ";
  }

  // member: bias_yaw
  {
    out << "bias_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_yaw, out);
    out << ", ";
  }

  // member: bias_buffer_size
  {
    out << "bias_buffer_size: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_buffer_size, out);
    out << ", ";
  }

  // member: merging_filter_coefficient
  {
    out << "merging_filter_coefficient: ";
    rosidl_generator_traits::value_to_yaml(msg.merging_filter_coefficient, out);
    out << ", ";
  }

  // member: corrected_angular_velocity_x
  {
    out << "corrected_angular_velocity_x: ";
    rosidl_generator_traits::value_to_yaml(msg.corrected_angular_velocity_x, out);
    out << ", ";
  }

  // member: corrected_angular_velocity_y
  {
    out << "corrected_angular_velocity_y: ";
    rosidl_generator_traits::value_to_yaml(msg.corrected_angular_velocity_y, out);
    out << ", ";
  }

  // member: corrected_angular_velocity_z
  {
    out << "corrected_angular_velocity_z: ";
    rosidl_generator_traits::value_to_yaml(msg.corrected_angular_velocity_z, out);
    out << ", ";
  }

  // member: gyro_integrated_roll
  {
    out << "gyro_integrated_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_integrated_roll, out);
    out << ", ";
  }

  // member: gyro_integrated_pitch
  {
    out << "gyro_integrated_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_integrated_pitch, out);
    out << ", ";
  }

  // member: gyro_integrated_yaw
  {
    out << "gyro_integrated_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_integrated_yaw, out);
    out << ", ";
  }

  // member: gyro_roll_innovation
  {
    out << "gyro_roll_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_roll_innovation, out);
    out << ", ";
  }

  // member: gyro_pitch_innovation
  {
    out << "gyro_pitch_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_pitch_innovation, out);
    out << ", ";
  }

  // member: gyro_yaw_innovation
  {
    out << "gyro_yaw_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_yaw_innovation, out);
    out << ", ";
  }

  // member: tilt_roll_innovation
  {
    out << "tilt_roll_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_roll_innovation, out);
    out << ", ";
  }

  // member: tilt_pitch_innovation
  {
    out << "tilt_pitch_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_pitch_innovation, out);
    out << ", ";
  }

  // member: tilt_yaw_innovation
  {
    out << "tilt_yaw_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_yaw_innovation, out);
    out << ", ";
  }

  // member: roll_innovation
  {
    out << "roll_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_innovation, out);
    out << ", ";
  }

  // member: pitch_innovation
  {
    out << "pitch_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_innovation, out);
    out << ", ";
  }

  // member: yaw_innovation
  {
    out << "yaw_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_innovation, out);
    out << ", ";
  }

  // member: merged_roll
  {
    out << "merged_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_roll, out);
    out << ", ";
  }

  // member: merged_pitch
  {
    out << "merged_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_pitch, out);
    out << ", ";
  }

  // member: merged_yaw
  {
    out << "merged_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_yaw, out);
    out << ", ";
  }

  // member: merged_minus_tilt_roll
  {
    out << "merged_minus_tilt_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_minus_tilt_roll, out);
    out << ", ";
  }

  // member: merged_minus_tilt_pitch
  {
    out << "merged_minus_tilt_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_minus_tilt_pitch, out);
    out << ", ";
  }

  // member: merged_minus_tilt_yaw
  {
    out << "merged_minus_tilt_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_minus_tilt_yaw, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: filter_elapsed_time
  {
    out << "filter_elapsed_time: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_elapsed_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImuAngleEstimatorInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: period
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "period: ";
    rosidl_generator_traits::value_to_yaml(msg.period, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: ay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << "\n";
  }

  // member: az
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
    out << "\n";
  }

  // member: mx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mx: ";
    rosidl_generator_traits::value_to_yaml(msg.mx, out);
    out << "\n";
  }

  // member: my
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my: ";
    rosidl_generator_traits::value_to_yaml(msg.my, out);
    out << "\n";
  }

  // member: mz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mz: ";
    rosidl_generator_traits::value_to_yaml(msg.mz, out);
    out << "\n";
  }

  // member: gx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gx: ";
    rosidl_generator_traits::value_to_yaml(msg.gx, out);
    out << "\n";
  }

  // member: gy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gy: ";
    rosidl_generator_traits::value_to_yaml(msg.gy, out);
    out << "\n";
  }

  // member: gz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gz: ";
    rosidl_generator_traits::value_to_yaml(msg.gz, out);
    out << "\n";
  }

  // member: tilt_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_roll, out);
    out << "\n";
  }

  // member: tilt_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_pitch, out);
    out << "\n";
  }

  // member: tilt_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_yaw, out);
    out << "\n";
  }

  // member: rate_tilt_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rate_tilt_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.rate_tilt_roll, out);
    out << "\n";
  }

  // member: rate_tilt_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rate_tilt_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.rate_tilt_pitch, out);
    out << "\n";
  }

  // member: rate_tilt_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rate_tilt_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.rate_tilt_yaw, out);
    out << "\n";
  }

  // member: tilt_angular_velocity_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_angular_velocity_x: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_angular_velocity_x, out);
    out << "\n";
  }

  // member: tilt_angular_velocity_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_angular_velocity_y: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_angular_velocity_y, out);
    out << "\n";
  }

  // member: tilt_angular_velocity_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_angular_velocity_z: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_angular_velocity_z, out);
    out << "\n";
  }

  // member: bias_roll_from_this_iteration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bias_roll_from_this_iteration: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_roll_from_this_iteration, out);
    out << "\n";
  }

  // member: bias_pitch_from_this_iteration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bias_pitch_from_this_iteration: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_pitch_from_this_iteration, out);
    out << "\n";
  }

  // member: bias_yaw_from_this_iteration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bias_yaw_from_this_iteration: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_yaw_from_this_iteration, out);
    out << "\n";
  }

  // member: bias_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bias_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_roll, out);
    out << "\n";
  }

  // member: bias_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bias_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_pitch, out);
    out << "\n";
  }

  // member: bias_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bias_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_yaw, out);
    out << "\n";
  }

  // member: bias_buffer_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bias_buffer_size: ";
    rosidl_generator_traits::value_to_yaml(msg.bias_buffer_size, out);
    out << "\n";
  }

  // member: merging_filter_coefficient
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merging_filter_coefficient: ";
    rosidl_generator_traits::value_to_yaml(msg.merging_filter_coefficient, out);
    out << "\n";
  }

  // member: corrected_angular_velocity_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "corrected_angular_velocity_x: ";
    rosidl_generator_traits::value_to_yaml(msg.corrected_angular_velocity_x, out);
    out << "\n";
  }

  // member: corrected_angular_velocity_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "corrected_angular_velocity_y: ";
    rosidl_generator_traits::value_to_yaml(msg.corrected_angular_velocity_y, out);
    out << "\n";
  }

  // member: corrected_angular_velocity_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "corrected_angular_velocity_z: ";
    rosidl_generator_traits::value_to_yaml(msg.corrected_angular_velocity_z, out);
    out << "\n";
  }

  // member: gyro_integrated_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_integrated_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_integrated_roll, out);
    out << "\n";
  }

  // member: gyro_integrated_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_integrated_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_integrated_pitch, out);
    out << "\n";
  }

  // member: gyro_integrated_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_integrated_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_integrated_yaw, out);
    out << "\n";
  }

  // member: gyro_roll_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_roll_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_roll_innovation, out);
    out << "\n";
  }

  // member: gyro_pitch_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_pitch_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_pitch_innovation, out);
    out << "\n";
  }

  // member: gyro_yaw_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_yaw_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_yaw_innovation, out);
    out << "\n";
  }

  // member: tilt_roll_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_roll_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_roll_innovation, out);
    out << "\n";
  }

  // member: tilt_pitch_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_pitch_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_pitch_innovation, out);
    out << "\n";
  }

  // member: tilt_yaw_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_yaw_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_yaw_innovation, out);
    out << "\n";
  }

  // member: roll_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_innovation, out);
    out << "\n";
  }

  // member: pitch_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_innovation, out);
    out << "\n";
  }

  // member: yaw_innovation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_innovation: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_innovation, out);
    out << "\n";
  }

  // member: merged_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merged_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_roll, out);
    out << "\n";
  }

  // member: merged_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merged_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_pitch, out);
    out << "\n";
  }

  // member: merged_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merged_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_yaw, out);
    out << "\n";
  }

  // member: merged_minus_tilt_roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merged_minus_tilt_roll: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_minus_tilt_roll, out);
    out << "\n";
  }

  // member: merged_minus_tilt_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merged_minus_tilt_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_minus_tilt_pitch, out);
    out << "\n";
  }

  // member: merged_minus_tilt_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merged_minus_tilt_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.merged_minus_tilt_yaw, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: filter_elapsed_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filter_elapsed_time: ";
    rosidl_generator_traits::value_to_yaml(msg.filter_elapsed_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImuAngleEstimatorInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cola2_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cola2_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cola2_msgs::msg::ImuAngleEstimatorInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
{
  return cola2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::msg::ImuAngleEstimatorInfo>()
{
  return "cola2_msgs::msg::ImuAngleEstimatorInfo";
}

template<>
inline const char * name<cola2_msgs::msg::ImuAngleEstimatorInfo>()
{
  return "cola2_msgs/msg/ImuAngleEstimatorInfo";
}

template<>
struct has_fixed_size<cola2_msgs::msg::ImuAngleEstimatorInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cola2_msgs::msg::ImuAngleEstimatorInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cola2_msgs::msg::ImuAngleEstimatorInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__TRAITS_HPP_
