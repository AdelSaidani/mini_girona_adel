// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:msg/KeyValueArray.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__BUILDER_HPP_
#define COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/msg/detail/key_value_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace msg
{

namespace builder
{

class Init_KeyValueArray_keyvalues
{
public:
  Init_KeyValueArray_keyvalues()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cola2_msgs::msg::KeyValueArray keyvalues(::cola2_msgs::msg::KeyValueArray::_keyvalues_type arg)
  {
    msg_.keyvalues = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::msg::KeyValueArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::msg::KeyValueArray>()
{
  return cola2_msgs::msg::builder::Init_KeyValueArray_keyvalues();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__BUILDER_HPP_
