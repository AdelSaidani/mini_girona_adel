// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/FlsConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/msg/detail/fls_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cola2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FlsConfig & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: num_beams
  {
    out << "num_beams: ";
    rosidl_generator_traits::value_to_yaml(msg.num_beams, out);
    out << ", ";
  }

  // member: num_samples
  {
    out << "num_samples: ";
    rosidl_generator_traits::value_to_yaml(msg.num_samples, out);
    out << ", ";
  }

  // member: window_start
  {
    out << "window_start: ";
    rosidl_generator_traits::value_to_yaml(msg.window_start, out);
    out << ", ";
  }

  // member: window_end
  {
    out << "window_end: ";
    rosidl_generator_traits::value_to_yaml(msg.window_end, out);
    out << ", ";
  }

  // member: beams_bearings
  {
    if (msg.beams_bearings.size() == 0) {
      out << "beams_bearings: []";
    } else {
      out << "beams_bearings: [";
      size_t pending_items = msg.beams_bearings.size();
      for (auto item : msg.beams_bearings) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
  const FlsConfig & msg,
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

  // member: num_beams
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_beams: ";
    rosidl_generator_traits::value_to_yaml(msg.num_beams, out);
    out << "\n";
  }

  // member: num_samples
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_samples: ";
    rosidl_generator_traits::value_to_yaml(msg.num_samples, out);
    out << "\n";
  }

  // member: window_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "window_start: ";
    rosidl_generator_traits::value_to_yaml(msg.window_start, out);
    out << "\n";
  }

  // member: window_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "window_end: ";
    rosidl_generator_traits::value_to_yaml(msg.window_end, out);
    out << "\n";
  }

  // member: beams_bearings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.beams_bearings.size() == 0) {
      out << "beams_bearings: []\n";
    } else {
      out << "beams_bearings:\n";
      for (auto item : msg.beams_bearings) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

inline std::string to_yaml(const FlsConfig & msg, bool use_flow_style = false)
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
  const cola2_msgs::msg::FlsConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::msg::FlsConfig & msg)
{
  return cola2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::msg::FlsConfig>()
{
  return "cola2_msgs::msg::FlsConfig";
}

template<>
inline const char * name<cola2_msgs::msg::FlsConfig>()
{
  return "cola2_msgs/msg/FlsConfig";
}

template<>
struct has_fixed_size<cola2_msgs::msg::FlsConfig>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cola2_msgs::msg::FlsConfig>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cola2_msgs::msg::FlsConfig>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__TRAITS_HPP_
