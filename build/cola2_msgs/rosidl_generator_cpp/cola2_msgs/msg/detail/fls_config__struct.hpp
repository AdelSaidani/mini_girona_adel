// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:msg/FlsConfig.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__STRUCT_HPP_
#define COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__STRUCT_HPP_

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
# define DEPRECATED__cola2_msgs__msg__FlsConfig __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__msg__FlsConfig __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FlsConfig_
{
  using Type = FlsConfig_<ContainerAllocator>;

  explicit FlsConfig_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_beams = 0ul;
      this->num_samples = 0ul;
      this->window_start = 0.0;
      this->window_end = 0.0;
      this->speed_of_sound = 0.0;
      this->ping_rate = 0.0;
      this->frequency = 0.0;
    }
  }

  explicit FlsConfig_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_beams = 0ul;
      this->num_samples = 0ul;
      this->window_start = 0.0;
      this->window_end = 0.0;
      this->speed_of_sound = 0.0;
      this->ping_rate = 0.0;
      this->frequency = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _num_beams_type =
    uint32_t;
  _num_beams_type num_beams;
  using _num_samples_type =
    uint32_t;
  _num_samples_type num_samples;
  using _window_start_type =
    double;
  _window_start_type window_start;
  using _window_end_type =
    double;
  _window_end_type window_end;
  using _beams_bearings_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _beams_bearings_type beams_bearings;
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
  Type & set__num_beams(
    const uint32_t & _arg)
  {
    this->num_beams = _arg;
    return *this;
  }
  Type & set__num_samples(
    const uint32_t & _arg)
  {
    this->num_samples = _arg;
    return *this;
  }
  Type & set__window_start(
    const double & _arg)
  {
    this->window_start = _arg;
    return *this;
  }
  Type & set__window_end(
    const double & _arg)
  {
    this->window_end = _arg;
    return *this;
  }
  Type & set__beams_bearings(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->beams_bearings = _arg;
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
    cola2_msgs::msg::FlsConfig_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::msg::FlsConfig_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::FlsConfig_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::FlsConfig_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__msg__FlsConfig
    std::shared_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__msg__FlsConfig
    std::shared_ptr<cola2_msgs::msg::FlsConfig_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FlsConfig_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->num_beams != other.num_beams) {
      return false;
    }
    if (this->num_samples != other.num_samples) {
      return false;
    }
    if (this->window_start != other.window_start) {
      return false;
    }
    if (this->window_end != other.window_end) {
      return false;
    }
    if (this->beams_bearings != other.beams_bearings) {
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
  bool operator!=(const FlsConfig_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FlsConfig_

// alias to use template instance with default allocator
using FlsConfig =
  cola2_msgs::msg::FlsConfig_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__FLS_CONFIG__STRUCT_HPP_
