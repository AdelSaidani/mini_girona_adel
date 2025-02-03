// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/AdisImu.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__ADIS_IMU__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__ADIS_IMU__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/msg/detail/adis_imu__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cola2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AdisImu & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: raw
  {
    out << "raw: ";
    rosidl_generator_traits::value_to_yaml(msg.raw, out);
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

  // member: t
  {
    out << "t: ";
    rosidl_generator_traits::value_to_yaml(msg.t, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: f
  {
    out << "f: ";
    rosidl_generator_traits::value_to_yaml(msg.f, out);
    out << ", ";
  }

  // member: e
  {
    out << "e: ";
    rosidl_generator_traits::value_to_yaml(msg.e, out);
    out << ", ";
  }

  // member: w
  {
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AdisImu & msg,
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

  // member: raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw: ";
    rosidl_generator_traits::value_to_yaml(msg.raw, out);
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

  // member: t
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t: ";
    rosidl_generator_traits::value_to_yaml(msg.t, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: f
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f: ";
    rosidl_generator_traits::value_to_yaml(msg.f, out);
    out << "\n";
  }

  // member: e
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "e: ";
    rosidl_generator_traits::value_to_yaml(msg.e, out);
    out << "\n";
  }

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AdisImu & msg, bool use_flow_style = false)
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
  const cola2_msgs::msg::AdisImu & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::msg::AdisImu & msg)
{
  return cola2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::msg::AdisImu>()
{
  return "cola2_msgs::msg::AdisImu";
}

template<>
inline const char * name<cola2_msgs::msg::AdisImu>()
{
  return "cola2_msgs/msg/AdisImu";
}

template<>
struct has_fixed_size<cola2_msgs::msg::AdisImu>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cola2_msgs::msg::AdisImu>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cola2_msgs::msg::AdisImu>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__ADIS_IMU__TRAITS_HPP_
