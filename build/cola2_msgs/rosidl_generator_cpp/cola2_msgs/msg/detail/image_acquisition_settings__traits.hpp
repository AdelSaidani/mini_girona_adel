// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/msg/detail/image_acquisition_settings__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'extra'
#include "cola2_msgs/msg/detail/key_value__traits.hpp"

namespace cola2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImageAcquisitionSettings & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: exposure_time
  {
    out << "exposure_time: ";
    rosidl_generator_traits::value_to_yaml(msg.exposure_time, out);
    out << ", ";
  }

  // member: gain
  {
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << ", ";
  }

  // member: blue_ratio
  {
    out << "blue_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.blue_ratio, out);
    out << ", ";
  }

  // member: red_ratio
  {
    out << "red_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.red_ratio, out);
    out << ", ";
  }

  // member: focus
  {
    out << "focus: ";
    rosidl_generator_traits::value_to_yaml(msg.focus, out);
    out << ", ";
  }

  // member: aperture
  {
    out << "aperture: ";
    rosidl_generator_traits::value_to_yaml(msg.aperture, out);
    out << ", ";
  }

  // member: focal_length
  {
    out << "focal_length: ";
    rosidl_generator_traits::value_to_yaml(msg.focal_length, out);
    out << ", ";
  }

  // member: extra
  {
    if (msg.extra.size() == 0) {
      out << "extra: []";
    } else {
      out << "extra: [";
      size_t pending_items = msg.extra.size();
      for (auto item : msg.extra) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImageAcquisitionSettings & msg,
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

  // member: exposure_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "exposure_time: ";
    rosidl_generator_traits::value_to_yaml(msg.exposure_time, out);
    out << "\n";
  }

  // member: gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << "\n";
  }

  // member: blue_ratio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blue_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.blue_ratio, out);
    out << "\n";
  }

  // member: red_ratio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.red_ratio, out);
    out << "\n";
  }

  // member: focus
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "focus: ";
    rosidl_generator_traits::value_to_yaml(msg.focus, out);
    out << "\n";
  }

  // member: aperture
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aperture: ";
    rosidl_generator_traits::value_to_yaml(msg.aperture, out);
    out << "\n";
  }

  // member: focal_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "focal_length: ";
    rosidl_generator_traits::value_to_yaml(msg.focal_length, out);
    out << "\n";
  }

  // member: extra
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.extra.size() == 0) {
      out << "extra: []\n";
    } else {
      out << "extra:\n";
      for (auto item : msg.extra) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImageAcquisitionSettings & msg, bool use_flow_style = false)
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
  const cola2_msgs::msg::ImageAcquisitionSettings & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::msg::ImageAcquisitionSettings & msg)
{
  return cola2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::msg::ImageAcquisitionSettings>()
{
  return "cola2_msgs::msg::ImageAcquisitionSettings";
}

template<>
inline const char * name<cola2_msgs::msg::ImageAcquisitionSettings>()
{
  return "cola2_msgs/msg/ImageAcquisitionSettings";
}

template<>
struct has_fixed_size<cola2_msgs::msg::ImageAcquisitionSettings>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cola2_msgs::msg::ImageAcquisitionSettings>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cola2_msgs::msg::ImageAcquisitionSettings>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__TRAITS_HPP_
