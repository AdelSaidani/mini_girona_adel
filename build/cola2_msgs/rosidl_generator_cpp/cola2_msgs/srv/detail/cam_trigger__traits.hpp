// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:srv/CamTrigger.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__TRAITS_HPP_
#define COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/srv/detail/cam_trigger__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cola2_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CamTrigger_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: intensity1
  {
    out << "intensity1: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity1, out);
    out << ", ";
  }

  // member: intensity2
  {
    out << "intensity2: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity2, out);
    out << ", ";
  }

  // member: cam1
  {
    out << "cam1: ";
    rosidl_generator_traits::value_to_yaml(msg.cam1, out);
    out << ", ";
  }

  // member: cam2
  {
    out << "cam2: ";
    rosidl_generator_traits::value_to_yaml(msg.cam2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CamTrigger_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: intensity1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "intensity1: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity1, out);
    out << "\n";
  }

  // member: intensity2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "intensity2: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity2, out);
    out << "\n";
  }

  // member: cam1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam1: ";
    rosidl_generator_traits::value_to_yaml(msg.cam1, out);
    out << "\n";
  }

  // member: cam2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam2: ";
    rosidl_generator_traits::value_to_yaml(msg.cam2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CamTrigger_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cola2_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cola2_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cola2_msgs::srv::CamTrigger_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::srv::CamTrigger_Request & msg)
{
  return cola2_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::srv::CamTrigger_Request>()
{
  return "cola2_msgs::srv::CamTrigger_Request";
}

template<>
inline const char * name<cola2_msgs::srv::CamTrigger_Request>()
{
  return "cola2_msgs/srv/CamTrigger_Request";
}

template<>
struct has_fixed_size<cola2_msgs::srv::CamTrigger_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cola2_msgs::srv::CamTrigger_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cola2_msgs::srv::CamTrigger_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cola2_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CamTrigger_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CamTrigger_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CamTrigger_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cola2_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cola2_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cola2_msgs::srv::CamTrigger_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::srv::CamTrigger_Response & msg)
{
  return cola2_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::srv::CamTrigger_Response>()
{
  return "cola2_msgs::srv::CamTrigger_Response";
}

template<>
inline const char * name<cola2_msgs::srv::CamTrigger_Response>()
{
  return "cola2_msgs/srv/CamTrigger_Response";
}

template<>
struct has_fixed_size<cola2_msgs::srv::CamTrigger_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cola2_msgs::srv::CamTrigger_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cola2_msgs::srv::CamTrigger_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cola2_msgs::srv::CamTrigger>()
{
  return "cola2_msgs::srv::CamTrigger";
}

template<>
inline const char * name<cola2_msgs::srv::CamTrigger>()
{
  return "cola2_msgs/srv/CamTrigger";
}

template<>
struct has_fixed_size<cola2_msgs::srv::CamTrigger>
  : std::integral_constant<
    bool,
    has_fixed_size<cola2_msgs::srv::CamTrigger_Request>::value &&
    has_fixed_size<cola2_msgs::srv::CamTrigger_Response>::value
  >
{
};

template<>
struct has_bounded_size<cola2_msgs::srv::CamTrigger>
  : std::integral_constant<
    bool,
    has_bounded_size<cola2_msgs::srv::CamTrigger_Request>::value &&
    has_bounded_size<cola2_msgs::srv::CamTrigger_Response>::value
  >
{
};

template<>
struct is_service<cola2_msgs::srv::CamTrigger>
  : std::true_type
{
};

template<>
struct is_service_request<cola2_msgs::srv::CamTrigger_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cola2_msgs::srv::CamTrigger_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__TRAITS_HPP_
