// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:msg/SSSConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__BUILDER_HPP_
#define COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/msg/detail/sss_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace msg
{

namespace builder
{

class Init_SSSConfig_frequency
{
public:
  explicit Init_SSSConfig_frequency(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  ::cola2_msgs::msg::SSSConfig frequency(::cola2_msgs::msg::SSSConfig::_frequency_type arg)
  {
    msg_.frequency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_ping_rate
{
public:
  explicit Init_SSSConfig_ping_rate(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  Init_SSSConfig_frequency ping_rate(::cola2_msgs::msg::SSSConfig::_ping_rate_type arg)
  {
    msg_.ping_rate = std::move(arg);
    return Init_SSSConfig_frequency(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_speed_of_sound
{
public:
  explicit Init_SSSConfig_speed_of_sound(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  Init_SSSConfig_ping_rate speed_of_sound(::cola2_msgs::msg::SSSConfig::_speed_of_sound_type arg)
  {
    msg_.speed_of_sound = std::move(arg);
    return Init_SSSConfig_ping_rate(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_vertical_beam_angle
{
public:
  explicit Init_SSSConfig_vertical_beam_angle(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  Init_SSSConfig_speed_of_sound vertical_beam_angle(::cola2_msgs::msg::SSSConfig::_vertical_beam_angle_type arg)
  {
    msg_.vertical_beam_angle = std::move(arg);
    return Init_SSSConfig_speed_of_sound(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_horizontal_beam_angle
{
public:
  explicit Init_SSSConfig_horizontal_beam_angle(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  Init_SSSConfig_vertical_beam_angle horizontal_beam_angle(::cola2_msgs::msg::SSSConfig::_horizontal_beam_angle_type arg)
  {
    msg_.horizontal_beam_angle = std::move(arg);
    return Init_SSSConfig_vertical_beam_angle(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_range
{
public:
  explicit Init_SSSConfig_range(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  Init_SSSConfig_horizontal_beam_angle range(::cola2_msgs::msg::SSSConfig::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_SSSConfig_horizontal_beam_angle(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_range_delay
{
public:
  explicit Init_SSSConfig_range_delay(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  Init_SSSConfig_range range_delay(::cola2_msgs::msg::SSSConfig::_range_delay_type arg)
  {
    msg_.range_delay = std::move(arg);
    return Init_SSSConfig_range(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_samples_per_channel
{
public:
  explicit Init_SSSConfig_samples_per_channel(::cola2_msgs::msg::SSSConfig & msg)
  : msg_(msg)
  {}
  Init_SSSConfig_range_delay samples_per_channel(::cola2_msgs::msg::SSSConfig::_samples_per_channel_type arg)
  {
    msg_.samples_per_channel = std::move(arg);
    return Init_SSSConfig_range_delay(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

class Init_SSSConfig_header
{
public:
  Init_SSSConfig_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SSSConfig_samples_per_channel header(::cola2_msgs::msg::SSSConfig::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SSSConfig_samples_per_channel(msg_);
  }

private:
  ::cola2_msgs::msg::SSSConfig msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::msg::SSSConfig>()
{
  return cola2_msgs::msg::builder::Init_SSSConfig_header();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__BUILDER_HPP_
