// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/SSSConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/msg/detail/sss_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cola2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SSSConfig & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: samples_per_channel
  {
    out << "samples_per_channel: ";
    rosidl_generator_traits::value_to_yaml(msg.samples_per_channel, out);
    out << ", ";
  }

  // member: range_delay
  {
    out << "range_delay: ";
    rosidl_generator_traits::value_to_yaml(msg.range_delay, out);
    out << ", ";
  }

  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << ", ";
  }

  // member: horizontal_beam_angle
  {
    out << "horizontal_beam_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.horizontal_beam_angle, out);
    out << ", ";
  }

  // member: vertical_beam_angle
  {
    out << "vertical_beam_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.vertical_beam_angle, out);
    out << ", ";
  }

  // member: speed_of_sound
  {
    out << "speed_of_sound: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_of_sound, out);
    out << ", ";
  }

  // member: ping_rate
  {
    out << "ping_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.ping_rate, out);
    out << ", ";
  }

  // member: frequency
  {
    out << "frequency: ";
    rosidl_generator_traits::value_to_yaml(msg.frequency, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SSSConfig & msg,
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

  // member: samples_per_channel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "samples_per_channel: ";
    rosidl_generator_traits::value_to_yaml(msg.samples_per_channel, out);
    out << "\n";
  }

  // member: range_delay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_delay: ";
    rosidl_generator_traits::value_to_yaml(msg.range_delay, out);
    out << "\n";
  }

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << "\n";
  }

  // member: horizontal_beam_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "horizontal_beam_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.horizontal_beam_angle, out);
    out << "\n";
  }

  // member: vertical_beam_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vertical_beam_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.vertical_beam_angle, out);
    out << "\n";
  }

  // member: speed_of_sound
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_of_sound: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_of_sound, out);
    out << "\n";
  }

  // member: ping_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ping_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.ping_rate, out);
    out << "\n";
  }

  // member: frequency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frequency: ";
    rosidl_generator_traits::value_to_yaml(msg.frequency, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SSSConfig & msg, bool use_flow_style = false)
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
  const cola2_msgs::msg::SSSConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::msg::SSSConfig & msg)
{
  return cola2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::msg::SSSConfig>()
{
  return "cola2_msgs::msg::SSSConfig";
}

template<>
inline const char * name<cola2_msgs::msg::SSSConfig>()
{
  return "cola2_msgs/msg/SSSConfig";
}

template<>
struct has_fixed_size<cola2_msgs::msg::SSSConfig>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cola2_msgs::msg::SSSConfig>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cola2_msgs::msg::SSSConfig>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__TRAITS_HPP_
