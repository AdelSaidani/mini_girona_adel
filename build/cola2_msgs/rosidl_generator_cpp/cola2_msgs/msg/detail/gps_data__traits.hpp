// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__GPS_DATA__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__GPS_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/msg/detail/gps_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cola2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GPSData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: time_utc
  {
    out << "time_utc: ";
    rosidl_generator_traits::value_to_yaml(msg.time_utc, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: fix_quality
  {
    out << "fix_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.fix_quality, out);
    out << ", ";
  }

  // member: number_of_satellites
  {
    out << "number_of_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.number_of_satellites, out);
    out << ", ";
  }

  // member: hdop
  {
    out << "hdop: ";
    rosidl_generator_traits::value_to_yaml(msg.hdop, out);
    out << ", ";
  }

  // member: altitude
  {
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << ", ";
  }

  // member: geoidal_separation
  {
    out << "geoidal_separation: ";
    rosidl_generator_traits::value_to_yaml(msg.geoidal_separation, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << ", ";
  }

  // member: latitude_stdev
  {
    out << "latitude_stdev: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude_stdev, out);
    out << ", ";
  }

  // member: longitude_stdev
  {
    out << "longitude_stdev: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude_stdev, out);
    out << ", ";
  }

  // member: altitude_stdev
  {
    out << "altitude_stdev: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_stdev, out);
    out << ", ";
  }

  // member: raw_gpgga
  {
    out << "raw_gpgga: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_gpgga, out);
    out << ", ";
  }

  // member: raw_gphdt
  {
    out << "raw_gphdt: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_gphdt, out);
    out << ", ";
  }

  // member: raw_gpgst
  {
    out << "raw_gpgst: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_gpgst, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GPSData & msg,
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

  // member: time_utc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_utc: ";
    rosidl_generator_traits::value_to_yaml(msg.time_utc, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: fix_quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fix_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.fix_quality, out);
    out << "\n";
  }

  // member: number_of_satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "number_of_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.number_of_satellites, out);
    out << "\n";
  }

  // member: hdop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hdop: ";
    rosidl_generator_traits::value_to_yaml(msg.hdop, out);
    out << "\n";
  }

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << "\n";
  }

  // member: geoidal_separation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "geoidal_separation: ";
    rosidl_generator_traits::value_to_yaml(msg.geoidal_separation, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }

  // member: latitude_stdev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude_stdev: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude_stdev, out);
    out << "\n";
  }

  // member: longitude_stdev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude_stdev: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude_stdev, out);
    out << "\n";
  }

  // member: altitude_stdev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude_stdev: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_stdev, out);
    out << "\n";
  }

  // member: raw_gpgga
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_gpgga: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_gpgga, out);
    out << "\n";
  }

  // member: raw_gphdt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_gphdt: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_gphdt, out);
    out << "\n";
  }

  // member: raw_gpgst
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_gpgst: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_gpgst, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GPSData & msg, bool use_flow_style = false)
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
  const cola2_msgs::msg::GPSData & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::msg::GPSData & msg)
{
  return cola2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::msg::GPSData>()
{
  return "cola2_msgs::msg::GPSData";
}

template<>
inline const char * name<cola2_msgs::msg::GPSData>()
{
  return "cola2_msgs/msg/GPSData";
}

template<>
struct has_fixed_size<cola2_msgs::msg::GPSData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cola2_msgs::msg::GPSData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cola2_msgs::msg::GPSData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__GPS_DATA__TRAITS_HPP_
