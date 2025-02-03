// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/KeyValueArray.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cola2_msgs/msg/detail/key_value_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'keyvalues'
#include "cola2_msgs/msg/detail/key_value__traits.hpp"

namespace cola2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const KeyValueArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: keyvalues
  {
    if (msg.keyvalues.size() == 0) {
      out << "keyvalues: []";
    } else {
      out << "keyvalues: [";
      size_t pending_items = msg.keyvalues.size();
      for (auto item : msg.keyvalues) {
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
  const KeyValueArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: keyvalues
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.keyvalues.size() == 0) {
      out << "keyvalues: []\n";
    } else {
      out << "keyvalues:\n";
      for (auto item : msg.keyvalues) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KeyValueArray & msg, bool use_flow_style = false)
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
  const cola2_msgs::msg::KeyValueArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  cola2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cola2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cola2_msgs::msg::KeyValueArray & msg)
{
  return cola2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cola2_msgs::msg::KeyValueArray>()
{
  return "cola2_msgs::msg::KeyValueArray";
}

template<>
inline const char * name<cola2_msgs::msg::KeyValueArray>()
{
  return "cola2_msgs/msg/KeyValueArray";
}

template<>
struct has_fixed_size<cola2_msgs::msg::KeyValueArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cola2_msgs::msg::KeyValueArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cola2_msgs::msg::KeyValueArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__TRAITS_HPP_
