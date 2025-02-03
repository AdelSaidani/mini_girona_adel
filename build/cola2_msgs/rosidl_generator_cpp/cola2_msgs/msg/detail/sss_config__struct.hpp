// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:msg/SSSConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__STRUCT_HPP_
#define COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cola2_msgs__msg__SSSConfig __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__msg__SSSConfig __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SSSConfig_
{
  using Type = SSSConfig_<ContainerAllocator>;

  explicit SSSConfig_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->samples_per_channel = 0ul;
      this->range_delay = 0.0;
      this->range = 0.0;
      this->horizontal_beam_angle = 0.0;
      this->vertical_beam_angle = 0.0;
      this->speed_of_sound = 0.0;
      this->ping_rate = 0.0;
      this->frequency = 0.0;
    }
  }

  explicit SSSConfig_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->samples_per_channel = 0ul;
      this->range_delay = 0.0;
      this->range = 0.0;
      this->horizontal_beam_angle = 0.0;
      this->vertical_beam_angle = 0.0;
      this->speed_of_sound = 0.0;
      this->ping_rate = 0.0;
      this->frequency = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _samples_per_channel_type =
    uint32_t;
  _samples_per_channel_type samples_per_channel;
  using _range_delay_type =
    double;
  _range_delay_type range_delay;
  using _range_type =
    double;
  _range_type range;
  using _horizontal_beam_angle_type =
    double;
  _horizontal_beam_angle_type horizontal_beam_angle;
  using _vertical_beam_angle_type =
    double;
  _vertical_beam_angle_type vertical_beam_angle;
  using _speed_of_sound_type =
    double;
  _speed_of_sound_type speed_of_sound;
  using _ping_rate_type =
    double;
  _ping_rate_type ping_rate;
  using _frequency_type =
    double;
  _frequency_type frequency;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__samples_per_channel(
    const uint32_t & _arg)
  {
    this->samples_per_channel = _arg;
    return *this;
  }
  Type & set__range_delay(
    const double & _arg)
  {
    this->range_delay = _arg;
    return *this;
  }
  Type & set__range(
    const double & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__horizontal_beam_angle(
    const double & _arg)
  {
    this->horizontal_beam_angle = _arg;
    return *this;
  }
  Type & set__vertical_beam_angle(
    const double & _arg)
  {
    this->vertical_beam_angle = _arg;
    return *this;
  }
  Type & set__speed_of_sound(
    const double & _arg)
  {
    this->speed_of_sound = _arg;
    return *this;
  }
  Type & set__ping_rate(
    const double & _arg)
  {
    this->ping_rate = _arg;
    return *this;
  }
  Type & set__frequency(
    const double & _arg)
  {
    this->frequency = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::msg::SSSConfig_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::msg::SSSConfig_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::SSSConfig_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::SSSConfig_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__msg__SSSConfig
    std::shared_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__msg__SSSConfig
    std::shared_ptr<cola2_msgs::msg::SSSConfig_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SSSConfig_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->samples_per_channel != other.samples_per_channel) {
      return false;
    }
    if (this->range_delay != other.range_delay) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    if (this->horizontal_beam_angle != other.horizontal_beam_angle) {
      return false;
    }
    if (this->vertical_beam_angle != other.vertical_beam_angle) {
      return false;
    }
    if (this->speed_of_sound != other.speed_of_sound) {
      return false;
    }
    if (this->ping_rate != other.ping_rate) {
      return false;
    }
    if (this->frequency != other.frequency) {
      return false;
    }
    return true;
  }
  bool operator!=(const SSSConfig_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SSSConfig_

// alias to use template instance with default allocator
using SSSConfig =
  cola2_msgs::msg::SSSConfig_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__SSS_CONFIG__STRUCT_HPP_
