// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:msg/FlsConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__BUILDER_HPP_
#define COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/msg/detail/fls_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace msg
{

namespace builder
{

class Init_FlsConfig_frequency
{
public:
  explicit Init_FlsConfig_frequency(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  ::cola2_msgs::msg::FlsConfig frequency(::cola2_msgs::msg::FlsConfig::_frequency_type arg)
  {
    msg_.frequency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_ping_rate
{
public:
  explicit Init_FlsConfig_ping_rate(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  Init_FlsConfig_frequency ping_rate(::cola2_msgs::msg::FlsConfig::_ping_rate_type arg)
  {
    msg_.ping_rate = std::move(arg);
    return Init_FlsConfig_frequency(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_speed_of_sound
{
public:
  explicit Init_FlsConfig_speed_of_sound(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  Init_FlsConfig_ping_rate speed_of_sound(::cola2_msgs::msg::FlsConfig::_speed_of_sound_type arg)
  {
    msg_.speed_of_sound = std::move(arg);
    return Init_FlsConfig_ping_rate(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_beams_bearings
{
public:
  explicit Init_FlsConfig_beams_bearings(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  Init_FlsConfig_speed_of_sound beams_bearings(::cola2_msgs::msg::FlsConfig::_beams_bearings_type arg)
  {
    msg_.beams_bearings = std::move(arg);
    return Init_FlsConfig_speed_of_sound(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_window_end
{
public:
  explicit Init_FlsConfig_window_end(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  Init_FlsConfig_beams_bearings window_end(::cola2_msgs::msg::FlsConfig::_window_end_type arg)
  {
    msg_.window_end = std::move(arg);
    return Init_FlsConfig_beams_bearings(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_window_start
{
public:
  explicit Init_FlsConfig_window_start(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  Init_FlsConfig_window_end window_start(::cola2_msgs::msg::FlsConfig::_window_start_type arg)
  {
    msg_.window_start = std::move(arg);
    return Init_FlsConfig_window_end(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_num_samples
{
public:
  explicit Init_FlsConfig_num_samples(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  Init_FlsConfig_window_start num_samples(::cola2_msgs::msg::FlsConfig::_num_samples_type arg)
  {
    msg_.num_samples = std::move(arg);
    return Init_FlsConfig_window_start(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_num_beams
{
public:
  explicit Init_FlsConfig_num_beams(::cola2_msgs::msg::FlsConfig & msg)
  : msg_(msg)
  {}
  Init_FlsConfig_num_samples num_beams(::cola2_msgs::msg::FlsConfig::_num_beams_type arg)
  {
    msg_.num_beams = std::move(arg);
    return Init_FlsConfig_num_samples(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

class Init_FlsConfig_header
{
public:
  Init_FlsConfig_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FlsConfig_num_beams header(::cola2_msgs::msg::FlsConfig::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FlsConfig_num_beams(msg_);
  }

private:
  ::cola2_msgs::msg::FlsConfig msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::msg::FlsConfig>()
{
  return cola2_msgs::msg::builder::Init_FlsConfig_header();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__BUILDER_HPP_
