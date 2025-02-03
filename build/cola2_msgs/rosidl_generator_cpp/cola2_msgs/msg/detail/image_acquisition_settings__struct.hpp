// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__STRUCT_HPP_
#define COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__STRUCT_HPP_

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
// Member 'extra'
#include "cola2_msgs/msg/detail/key_value__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cola2_msgs__msg__ImageAcquisitionSettings __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__msg__ImageAcquisitionSettings __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImageAcquisitionSettings_
{
  using Type = ImageAcquisitionSettings_<ContainerAllocator>;

  explicit ImageAcquisitionSettings_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->exposure_time = 0ul;
      this->gain = 0.0;
      this->blue_ratio = 0.0;
      this->red_ratio = 0.0;
      this->focus = 0.0;
      this->aperture = 0.0;
      this->focal_length = 0.0;
    }
  }

  explicit ImageAcquisitionSettings_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->exposure_time = 0ul;
      this->gain = 0.0;
      this->blue_ratio = 0.0;
      this->red_ratio = 0.0;
      this->focus = 0.0;
      this->aperture = 0.0;
      this->focal_length = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _exposure_time_type =
    uint32_t;
  _exposure_time_type exposure_time;
  using _gain_type =
    double;
  _gain_type gain;
  using _blue_ratio_type =
    double;
  _blue_ratio_type blue_ratio;
  using _red_ratio_type =
    double;
  _red_ratio_type red_ratio;
  using _focus_type =
    double;
  _focus_type focus;
  using _aperture_type =
    double;
  _aperture_type aperture;
  using _focal_length_type =
    double;
  _focal_length_type focal_length;
  using _extra_type =
    std::vector<cola2_msgs::msg::KeyValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cola2_msgs::msg::KeyValue_<ContainerAllocator>>>;
  _extra_type extra;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__exposure_time(
    const uint32_t & _arg)
  {
    this->exposure_time = _arg;
    return *this;
  }
  Type & set__gain(
    const double & _arg)
  {
    this->gain = _arg;
    return *this;
  }
  Type & set__blue_ratio(
    const double & _arg)
  {
    this->blue_ratio = _arg;
    return *this;
  }
  Type & set__red_ratio(
    const double & _arg)
  {
    this->red_ratio = _arg;
    return *this;
  }
  Type & set__focus(
    const double & _arg)
  {
    this->focus = _arg;
    return *this;
  }
  Type & set__aperture(
    const double & _arg)
  {
    this->aperture = _arg;
    return *this;
  }
  Type & set__focal_length(
    const double & _arg)
  {
    this->focal_length = _arg;
    return *this;
  }
  Type & set__extra(
    const std::vector<cola2_msgs::msg::KeyValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cola2_msgs::msg::KeyValue_<ContainerAllocator>>> & _arg)
  {
    this->extra = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__msg__ImageAcquisitionSettings
    std::shared_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__msg__ImageAcquisitionSettings
    std::shared_ptr<cola2_msgs::msg::ImageAcquisitionSettings_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageAcquisitionSettings_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->exposure_time != other.exposure_time) {
      return false;
    }
    if (this->gain != other.gain) {
      return false;
    }
    if (this->blue_ratio != other.blue_ratio) {
      return false;
    }
    if (this->red_ratio != other.red_ratio) {
      return false;
    }
    if (this->focus != other.focus) {
      return false;
    }
    if (this->aperture != other.aperture) {
      return false;
    }
    if (this->focal_length != other.focal_length) {
      return false;
    }
    if (this->extra != other.extra) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageAcquisitionSettings_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageAcquisitionSettings_

// alias to use template instance with default allocator
using ImageAcquisitionSettings =
  cola2_msgs::msg::ImageAcquisitionSettings_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__STRUCT_HPP_
