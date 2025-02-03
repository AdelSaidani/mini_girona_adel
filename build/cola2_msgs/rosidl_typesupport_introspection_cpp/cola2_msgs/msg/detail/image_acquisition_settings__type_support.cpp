// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cola2_msgs/msg/detail/image_acquisition_settings__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cola2_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ImageAcquisitionSettings_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cola2_msgs::msg::ImageAcquisitionSettings(_init);
}

void ImageAcquisitionSettings_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cola2_msgs::msg::ImageAcquisitionSettings *>(message_memory);
  typed_message->~ImageAcquisitionSettings();
}

size_t size_function__ImageAcquisitionSettings__extra(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<cola2_msgs::msg::KeyValue> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ImageAcquisitionSettings__extra(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<cola2_msgs::msg::KeyValue> *>(untyped_member);
  return &member[index];
}

void * get_function__ImageAcquisitionSettings__extra(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<cola2_msgs::msg::KeyValue> *>(untyped_member);
  return &member[index];
}

void fetch_function__ImageAcquisitionSettings__extra(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const cola2_msgs::msg::KeyValue *>(
    get_const_function__ImageAcquisitionSettings__extra(untyped_member, index));
  auto & value = *reinterpret_cast<cola2_msgs::msg::KeyValue *>(untyped_value);
  value = item;
}

void assign_function__ImageAcquisitionSettings__extra(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<cola2_msgs::msg::KeyValue *>(
    get_function__ImageAcquisitionSettings__extra(untyped_member, index));
  const auto & value = *reinterpret_cast<const cola2_msgs::msg::KeyValue *>(untyped_value);
  item = value;
}

void resize_function__ImageAcquisitionSettings__extra(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<cola2_msgs::msg::KeyValue> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ImageAcquisitionSettings_message_member_array[9] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "exposure_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, exposure_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gain",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, gain),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "blue_ratio",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, blue_ratio),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "red_ratio",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, red_ratio),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "focus",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, focus),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "aperture",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, aperture),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "focal_length",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, focal_length),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "extra",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<cola2_msgs::msg::KeyValue>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cola2_msgs::msg::ImageAcquisitionSettings, extra),  // bytes offset in struct
    nullptr,  // default value
    size_function__ImageAcquisitionSettings__extra,  // size() function pointer
    get_const_function__ImageAcquisitionSettings__extra,  // get_const(index) function pointer
    get_function__ImageAcquisitionSettings__extra,  // get(index) function pointer
    fetch_function__ImageAcquisitionSettings__extra,  // fetch(index, &value) function pointer
    assign_function__ImageAcquisitionSettings__extra,  // assign(index, value) function pointer
    resize_function__ImageAcquisitionSettings__extra  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ImageAcquisitionSettings_message_members = {
  "cola2_msgs::msg",  // message namespace
  "ImageAcquisitionSettings",  // message name
  9,  // number of fields
  sizeof(cola2_msgs::msg::ImageAcquisitionSettings),
  ImageAcquisitionSettings_message_member_array,  // message members
  ImageAcquisitionSettings_init_function,  // function to initialize message memory (memory has to be allocated)
  ImageAcquisitionSettings_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ImageAcquisitionSettings_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ImageAcquisitionSettings_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cola2_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cola2_msgs::msg::ImageAcquisitionSettings>()
{
  return &::cola2_msgs::msg::rosidl_typesupport_introspection_cpp::ImageAcquisitionSettings_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cola2_msgs, msg, ImageAcquisitionSettings)() {
  return &::cola2_msgs::msg::rosidl_typesupport_introspection_cpp::ImageAcquisitionSettings_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
