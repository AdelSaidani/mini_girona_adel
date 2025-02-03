// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__BUILDER_HPP_
#define COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/msg/detail/imu_angle_estimator_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace msg
{

namespace builder
{

class Init_ImuAngleEstimatorInfo_filter_elapsed_time
{
public:
  explicit Init_ImuAngleEstimatorInfo_filter_elapsed_time(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  ::cola2_msgs::msg::ImuAngleEstimatorInfo filter_elapsed_time(::cola2_msgs::msg::ImuAngleEstimatorInfo::_filter_elapsed_time_type arg)
  {
    msg_.filter_elapsed_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_status
{
public:
  explicit Init_ImuAngleEstimatorInfo_status(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_filter_elapsed_time status(::cola2_msgs::msg::ImuAngleEstimatorInfo::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ImuAngleEstimatorInfo_filter_elapsed_time(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_merged_minus_tilt_yaw
{
public:
  explicit Init_ImuAngleEstimatorInfo_merged_minus_tilt_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_status merged_minus_tilt_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo::_merged_minus_tilt_yaw_type arg)
  {
    msg_.merged_minus_tilt_yaw = std::move(arg);
    return Init_ImuAngleEstimatorInfo_status(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_merged_minus_tilt_pitch
{
public:
  explicit Init_ImuAngleEstimatorInfo_merged_minus_tilt_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_merged_minus_tilt_yaw merged_minus_tilt_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo::_merged_minus_tilt_pitch_type arg)
  {
    msg_.merged_minus_tilt_pitch = std::move(arg);
    return Init_ImuAngleEstimatorInfo_merged_minus_tilt_yaw(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_merged_minus_tilt_roll
{
public:
  explicit Init_ImuAngleEstimatorInfo_merged_minus_tilt_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_merged_minus_tilt_pitch merged_minus_tilt_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo::_merged_minus_tilt_roll_type arg)
  {
    msg_.merged_minus_tilt_roll = std::move(arg);
    return Init_ImuAngleEstimatorInfo_merged_minus_tilt_pitch(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_merged_yaw
{
public:
  explicit Init_ImuAngleEstimatorInfo_merged_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_merged_minus_tilt_roll merged_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo::_merged_yaw_type arg)
  {
    msg_.merged_yaw = std::move(arg);
    return Init_ImuAngleEstimatorInfo_merged_minus_tilt_roll(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_merged_pitch
{
public:
  explicit Init_ImuAngleEstimatorInfo_merged_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_merged_yaw merged_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo::_merged_pitch_type arg)
  {
    msg_.merged_pitch = std::move(arg);
    return Init_ImuAngleEstimatorInfo_merged_yaw(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_merged_roll
{
public:
  explicit Init_ImuAngleEstimatorInfo_merged_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_merged_pitch merged_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo::_merged_roll_type arg)
  {
    msg_.merged_roll = std::move(arg);
    return Init_ImuAngleEstimatorInfo_merged_pitch(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_yaw_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_yaw_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_merged_roll yaw_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_yaw_innovation_type arg)
  {
    msg_.yaw_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_merged_roll(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_pitch_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_pitch_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_yaw_innovation pitch_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_pitch_innovation_type arg)
  {
    msg_.pitch_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_yaw_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_roll_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_roll_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_pitch_innovation roll_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_roll_innovation_type arg)
  {
    msg_.roll_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_pitch_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_yaw_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_yaw_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_roll_innovation tilt_yaw_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_yaw_innovation_type arg)
  {
    msg_.tilt_yaw_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_roll_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_pitch_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_pitch_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_yaw_innovation tilt_pitch_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_pitch_innovation_type arg)
  {
    msg_.tilt_pitch_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_yaw_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_roll_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_roll_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_pitch_innovation tilt_roll_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_roll_innovation_type arg)
  {
    msg_.tilt_roll_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_pitch_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gyro_yaw_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_gyro_yaw_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_roll_innovation gyro_yaw_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gyro_yaw_innovation_type arg)
  {
    msg_.gyro_yaw_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_roll_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gyro_pitch_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_gyro_pitch_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gyro_yaw_innovation gyro_pitch_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gyro_pitch_innovation_type arg)
  {
    msg_.gyro_pitch_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gyro_yaw_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gyro_roll_innovation
{
public:
  explicit Init_ImuAngleEstimatorInfo_gyro_roll_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gyro_pitch_innovation gyro_roll_innovation(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gyro_roll_innovation_type arg)
  {
    msg_.gyro_roll_innovation = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gyro_pitch_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gyro_integrated_yaw
{
public:
  explicit Init_ImuAngleEstimatorInfo_gyro_integrated_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gyro_roll_innovation gyro_integrated_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gyro_integrated_yaw_type arg)
  {
    msg_.gyro_integrated_yaw = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gyro_roll_innovation(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gyro_integrated_pitch
{
public:
  explicit Init_ImuAngleEstimatorInfo_gyro_integrated_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gyro_integrated_yaw gyro_integrated_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gyro_integrated_pitch_type arg)
  {
    msg_.gyro_integrated_pitch = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gyro_integrated_yaw(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gyro_integrated_roll
{
public:
  explicit Init_ImuAngleEstimatorInfo_gyro_integrated_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gyro_integrated_pitch gyro_integrated_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gyro_integrated_roll_type arg)
  {
    msg_.gyro_integrated_roll = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gyro_integrated_pitch(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_corrected_angular_velocity_z
{
public:
  explicit Init_ImuAngleEstimatorInfo_corrected_angular_velocity_z(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gyro_integrated_roll corrected_angular_velocity_z(::cola2_msgs::msg::ImuAngleEstimatorInfo::_corrected_angular_velocity_z_type arg)
  {
    msg_.corrected_angular_velocity_z = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gyro_integrated_roll(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_corrected_angular_velocity_y
{
public:
  explicit Init_ImuAngleEstimatorInfo_corrected_angular_velocity_y(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_corrected_angular_velocity_z corrected_angular_velocity_y(::cola2_msgs::msg::ImuAngleEstimatorInfo::_corrected_angular_velocity_y_type arg)
  {
    msg_.corrected_angular_velocity_y = std::move(arg);
    return Init_ImuAngleEstimatorInfo_corrected_angular_velocity_z(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_corrected_angular_velocity_x
{
public:
  explicit Init_ImuAngleEstimatorInfo_corrected_angular_velocity_x(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_corrected_angular_velocity_y corrected_angular_velocity_x(::cola2_msgs::msg::ImuAngleEstimatorInfo::_corrected_angular_velocity_x_type arg)
  {
    msg_.corrected_angular_velocity_x = std::move(arg);
    return Init_ImuAngleEstimatorInfo_corrected_angular_velocity_y(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_merging_filter_coefficient
{
public:
  explicit Init_ImuAngleEstimatorInfo_merging_filter_coefficient(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_corrected_angular_velocity_x merging_filter_coefficient(::cola2_msgs::msg::ImuAngleEstimatorInfo::_merging_filter_coefficient_type arg)
  {
    msg_.merging_filter_coefficient = std::move(arg);
    return Init_ImuAngleEstimatorInfo_corrected_angular_velocity_x(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_bias_buffer_size
{
public:
  explicit Init_ImuAngleEstimatorInfo_bias_buffer_size(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_merging_filter_coefficient bias_buffer_size(::cola2_msgs::msg::ImuAngleEstimatorInfo::_bias_buffer_size_type arg)
  {
    msg_.bias_buffer_size = std::move(arg);
    return Init_ImuAngleEstimatorInfo_merging_filter_coefficient(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_bias_yaw
{
public:
  explicit Init_ImuAngleEstimatorInfo_bias_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_bias_buffer_size bias_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo::_bias_yaw_type arg)
  {
    msg_.bias_yaw = std::move(arg);
    return Init_ImuAngleEstimatorInfo_bias_buffer_size(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_bias_pitch
{
public:
  explicit Init_ImuAngleEstimatorInfo_bias_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_bias_yaw bias_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo::_bias_pitch_type arg)
  {
    msg_.bias_pitch = std::move(arg);
    return Init_ImuAngleEstimatorInfo_bias_yaw(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_bias_roll
{
public:
  explicit Init_ImuAngleEstimatorInfo_bias_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_bias_pitch bias_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo::_bias_roll_type arg)
  {
    msg_.bias_roll = std::move(arg);
    return Init_ImuAngleEstimatorInfo_bias_pitch(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_bias_yaw_from_this_iteration
{
public:
  explicit Init_ImuAngleEstimatorInfo_bias_yaw_from_this_iteration(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_bias_roll bias_yaw_from_this_iteration(::cola2_msgs::msg::ImuAngleEstimatorInfo::_bias_yaw_from_this_iteration_type arg)
  {
    msg_.bias_yaw_from_this_iteration = std::move(arg);
    return Init_ImuAngleEstimatorInfo_bias_roll(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_bias_pitch_from_this_iteration
{
public:
  explicit Init_ImuAngleEstimatorInfo_bias_pitch_from_this_iteration(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_bias_yaw_from_this_iteration bias_pitch_from_this_iteration(::cola2_msgs::msg::ImuAngleEstimatorInfo::_bias_pitch_from_this_iteration_type arg)
  {
    msg_.bias_pitch_from_this_iteration = std::move(arg);
    return Init_ImuAngleEstimatorInfo_bias_yaw_from_this_iteration(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_bias_roll_from_this_iteration
{
public:
  explicit Init_ImuAngleEstimatorInfo_bias_roll_from_this_iteration(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_bias_pitch_from_this_iteration bias_roll_from_this_iteration(::cola2_msgs::msg::ImuAngleEstimatorInfo::_bias_roll_from_this_iteration_type arg)
  {
    msg_.bias_roll_from_this_iteration = std::move(arg);
    return Init_ImuAngleEstimatorInfo_bias_pitch_from_this_iteration(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_angular_velocity_z
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_angular_velocity_z(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_bias_roll_from_this_iteration tilt_angular_velocity_z(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_angular_velocity_z_type arg)
  {
    msg_.tilt_angular_velocity_z = std::move(arg);
    return Init_ImuAngleEstimatorInfo_bias_roll_from_this_iteration(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_angular_velocity_y
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_angular_velocity_y(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_angular_velocity_z tilt_angular_velocity_y(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_angular_velocity_y_type arg)
  {
    msg_.tilt_angular_velocity_y = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_angular_velocity_z(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_angular_velocity_x
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_angular_velocity_x(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_angular_velocity_y tilt_angular_velocity_x(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_angular_velocity_x_type arg)
  {
    msg_.tilt_angular_velocity_x = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_angular_velocity_y(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_rate_tilt_yaw
{
public:
  explicit Init_ImuAngleEstimatorInfo_rate_tilt_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_angular_velocity_x rate_tilt_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo::_rate_tilt_yaw_type arg)
  {
    msg_.rate_tilt_yaw = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_angular_velocity_x(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_rate_tilt_pitch
{
public:
  explicit Init_ImuAngleEstimatorInfo_rate_tilt_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_rate_tilt_yaw rate_tilt_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo::_rate_tilt_pitch_type arg)
  {
    msg_.rate_tilt_pitch = std::move(arg);
    return Init_ImuAngleEstimatorInfo_rate_tilt_yaw(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_rate_tilt_roll
{
public:
  explicit Init_ImuAngleEstimatorInfo_rate_tilt_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_rate_tilt_pitch rate_tilt_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo::_rate_tilt_roll_type arg)
  {
    msg_.rate_tilt_roll = std::move(arg);
    return Init_ImuAngleEstimatorInfo_rate_tilt_pitch(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_yaw
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_rate_tilt_roll tilt_yaw(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_yaw_type arg)
  {
    msg_.tilt_yaw = std::move(arg);
    return Init_ImuAngleEstimatorInfo_rate_tilt_roll(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_pitch
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_yaw tilt_pitch(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_pitch_type arg)
  {
    msg_.tilt_pitch = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_yaw(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_tilt_roll
{
public:
  explicit Init_ImuAngleEstimatorInfo_tilt_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_pitch tilt_roll(::cola2_msgs::msg::ImuAngleEstimatorInfo::_tilt_roll_type arg)
  {
    msg_.tilt_roll = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_pitch(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gz
{
public:
  explicit Init_ImuAngleEstimatorInfo_gz(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_tilt_roll gz(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gz_type arg)
  {
    msg_.gz = std::move(arg);
    return Init_ImuAngleEstimatorInfo_tilt_roll(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gy
{
public:
  explicit Init_ImuAngleEstimatorInfo_gy(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gz gy(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gy_type arg)
  {
    msg_.gy = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gz(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_gx
{
public:
  explicit Init_ImuAngleEstimatorInfo_gx(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gy gx(::cola2_msgs::msg::ImuAngleEstimatorInfo::_gx_type arg)
  {
    msg_.gx = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gy(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_mz
{
public:
  explicit Init_ImuAngleEstimatorInfo_mz(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_gx mz(::cola2_msgs::msg::ImuAngleEstimatorInfo::_mz_type arg)
  {
    msg_.mz = std::move(arg);
    return Init_ImuAngleEstimatorInfo_gx(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_my
{
public:
  explicit Init_ImuAngleEstimatorInfo_my(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_mz my(::cola2_msgs::msg::ImuAngleEstimatorInfo::_my_type arg)
  {
    msg_.my = std::move(arg);
    return Init_ImuAngleEstimatorInfo_mz(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_mx
{
public:
  explicit Init_ImuAngleEstimatorInfo_mx(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_my mx(::cola2_msgs::msg::ImuAngleEstimatorInfo::_mx_type arg)
  {
    msg_.mx = std::move(arg);
    return Init_ImuAngleEstimatorInfo_my(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_az
{
public:
  explicit Init_ImuAngleEstimatorInfo_az(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_mx az(::cola2_msgs::msg::ImuAngleEstimatorInfo::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_ImuAngleEstimatorInfo_mx(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_ay
{
public:
  explicit Init_ImuAngleEstimatorInfo_ay(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_az ay(::cola2_msgs::msg::ImuAngleEstimatorInfo::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_ImuAngleEstimatorInfo_az(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_ax
{
public:
  explicit Init_ImuAngleEstimatorInfo_ax(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_ay ax(::cola2_msgs::msg::ImuAngleEstimatorInfo::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_ImuAngleEstimatorInfo_ay(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_period
{
public:
  explicit Init_ImuAngleEstimatorInfo_period(::cola2_msgs::msg::ImuAngleEstimatorInfo & msg)
  : msg_(msg)
  {}
  Init_ImuAngleEstimatorInfo_ax period(::cola2_msgs::msg::ImuAngleEstimatorInfo::_period_type arg)
  {
    msg_.period = std::move(arg);
    return Init_ImuAngleEstimatorInfo_ax(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

class Init_ImuAngleEstimatorInfo_header
{
public:
  Init_ImuAngleEstimatorInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuAngleEstimatorInfo_period header(::cola2_msgs::msg::ImuAngleEstimatorInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ImuAngleEstimatorInfo_period(msg_);
  }

private:
  ::cola2_msgs::msg::ImuAngleEstimatorInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::msg::ImuAngleEstimatorInfo>()
{
  return cola2_msgs::msg::builder::Init_ImuAngleEstimatorInfo_header();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__BUILDER_HPP_
