// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:msg/AdisImu.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__ADIS_IMU__STRUCT_HPP_
#define COLA2_MSGS__MSG__DETAIL__ADIS_IMU__STRUCT_HPP_

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
# define DEPRECATED__cola2_msgs__msg__AdisImu __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__msg__AdisImu __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AdisImu_
{
  using Type = AdisImu_<ContainerAllocator>;

  explicit AdisImu_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw = "";
      this->mx = 0.0;
      this->my = 0.0;
      this->mz = 0.0;
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->t = 0.0;
      this->b = 0.0;
      this->f = "";
      this->e = 0.0;
      this->w = 0.0;
    }
  }

  explicit AdisImu_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    raw(_alloc),
    f(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw = "";
      this->mx = 0.0;
      this->my = 0.0;
      this->mz = 0.0;
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->t = 0.0;
      this->b = 0.0;
      this->f = "";
      this->e = 0.0;
      this->w = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _raw_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _raw_type raw;
  using _mx_type =
    double;
  _mx_type mx;
  using _my_type =
    double;
  _my_type my;
  using _mz_type =
    double;
  _mz_type mz;
  using _gx_type =
    double;
  _gx_type gx;
  using _gy_type =
    double;
  _gy_type gy;
  using _gz_type =
    double;
  _gz_type gz;
  using _ax_type =
    double;
  _ax_type ax;
  using _ay_type =
    double;
  _ay_type ay;
  using _az_type =
    double;
  _az_type az;
  using _t_type =
    double;
  _t_type t;
  using _b_type =
    double;
  _b_type b;
  using _f_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _f_type f;
  using _e_type =
    double;
  _e_type e;
  using _w_type =
    double;
  _w_type w;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__raw(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->raw = _arg;
    return *this;
  }
  Type & set__mx(
    const double & _arg)
  {
    this->mx = _arg;
    return *this;
  }
  Type & set__my(
    const double & _arg)
  {
    this->my = _arg;
    return *this;
  }
  Type & set__mz(
    const double & _arg)
  {
    this->mz = _arg;
    return *this;
  }
  Type & set__gx(
    const double & _arg)
  {
    this->gx = _arg;
    return *this;
  }
  Type & set__gy(
    const double & _arg)
  {
    this->gy = _arg;
    return *this;
  }
  Type & set__gz(
    const double & _arg)
  {
    this->gz = _arg;
    return *this;
  }
  Type & set__ax(
    const double & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__ay(
    const double & _arg)
  {
    this->ay = _arg;
    return *this;
  }
  Type & set__az(
    const double & _arg)
  {
    this->az = _arg;
    return *this;
  }
  Type & set__t(
    const double & _arg)
  {
    this->t = _arg;
    return *this;
  }
  Type & set__b(
    const double & _arg)
  {
    this->b = _arg;
    return *this;
  }
  Type & set__f(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->f = _arg;
    return *this;
  }
  Type & set__e(
    const double & _arg)
  {
    this->e = _arg;
    return *this;
  }
  Type & set__w(
    const double & _arg)
  {
    this->w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::msg::AdisImu_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::msg::AdisImu_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::AdisImu_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::AdisImu_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__msg__AdisImu
    std::shared_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__msg__AdisImu
    std::shared_ptr<cola2_msgs::msg::AdisImu_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AdisImu_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->raw != other.raw) {
      return false;
    }
    if (this->mx != other.mx) {
      return false;
    }
    if (this->my != other.my) {
      return false;
    }
    if (this->mz != other.mz) {
      return false;
    }
    if (this->gx != other.gx) {
      return false;
    }
    if (this->gy != other.gy) {
      return false;
    }
    if (this->gz != other.gz) {
      return false;
    }
    if (this->ax != other.ax) {
      return false;
    }
    if (this->ay != other.ay) {
      return false;
    }
    if (this->az != other.az) {
      return false;
    }
    if (this->t != other.t) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->f != other.f) {
      return false;
    }
    if (this->e != other.e) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    return true;
  }
  bool operator!=(const AdisImu_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AdisImu_

// alias to use template instance with default allocator
using AdisImu =
  cola2_msgs::msg::AdisImu_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__ADIS_IMU__STRUCT_HPP_
