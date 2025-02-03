// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_HPP_
#define COLA2_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_HPP_

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
# define DEPRECATED__cola2_msgs__msg__GPSData __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__msg__GPSData __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GPSData_
{
  using Type = GPSData_<ContainerAllocator>;

  explicit GPSData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_utc = "";
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->fix_quality = 0l;
      this->number_of_satellites = 0l;
      this->hdop = 0.0f;
      this->altitude = 0.0f;
      this->geoidal_separation = 0.0f;
      this->heading = 0.0f;
      this->latitude_stdev = 0.0f;
      this->longitude_stdev = 0.0f;
      this->altitude_stdev = 0.0f;
      this->raw_gpgga = "";
      this->raw_gphdt = "";
      this->raw_gpgst = "";
    }
  }

  explicit GPSData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    time_utc(_alloc),
    raw_gpgga(_alloc),
    raw_gphdt(_alloc),
    raw_gpgst(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_utc = "";
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->fix_quality = 0l;
      this->number_of_satellites = 0l;
      this->hdop = 0.0f;
      this->altitude = 0.0f;
      this->geoidal_separation = 0.0f;
      this->heading = 0.0f;
      this->latitude_stdev = 0.0f;
      this->longitude_stdev = 0.0f;
      this->altitude_stdev = 0.0f;
      this->raw_gpgga = "";
      this->raw_gphdt = "";
      this->raw_gpgst = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_utc_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _time_utc_type time_utc;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _fix_quality_type =
    int32_t;
  _fix_quality_type fix_quality;
  using _number_of_satellites_type =
    int32_t;
  _number_of_satellites_type number_of_satellites;
  using _hdop_type =
    float;
  _hdop_type hdop;
  using _altitude_type =
    float;
  _altitude_type altitude;
  using _geoidal_separation_type =
    float;
  _geoidal_separation_type geoidal_separation;
  using _heading_type =
    float;
  _heading_type heading;
  using _latitude_stdev_type =
    float;
  _latitude_stdev_type latitude_stdev;
  using _longitude_stdev_type =
    float;
  _longitude_stdev_type longitude_stdev;
  using _altitude_stdev_type =
    float;
  _altitude_stdev_type altitude_stdev;
  using _raw_gpgga_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _raw_gpgga_type raw_gpgga;
  using _raw_gphdt_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _raw_gphdt_type raw_gphdt;
  using _raw_gpgst_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _raw_gpgst_type raw_gpgst;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__time_utc(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->time_utc = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__fix_quality(
    const int32_t & _arg)
  {
    this->fix_quality = _arg;
    return *this;
  }
  Type & set__number_of_satellites(
    const int32_t & _arg)
  {
    this->number_of_satellites = _arg;
    return *this;
  }
  Type & set__hdop(
    const float & _arg)
  {
    this->hdop = _arg;
    return *this;
  }
  Type & set__altitude(
    const float & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__geoidal_separation(
    const float & _arg)
  {
    this->geoidal_separation = _arg;
    return *this;
  }
  Type & set__heading(
    const float & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__latitude_stdev(
    const float & _arg)
  {
    this->latitude_stdev = _arg;
    return *this;
  }
  Type & set__longitude_stdev(
    const float & _arg)
  {
    this->longitude_stdev = _arg;
    return *this;
  }
  Type & set__altitude_stdev(
    const float & _arg)
  {
    this->altitude_stdev = _arg;
    return *this;
  }
  Type & set__raw_gpgga(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->raw_gpgga = _arg;
    return *this;
  }
  Type & set__raw_gphdt(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->raw_gphdt = _arg;
    return *this;
  }
  Type & set__raw_gpgst(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->raw_gpgst = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::msg::GPSData_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::msg::GPSData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::GPSData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::GPSData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__msg__GPSData
    std::shared_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__msg__GPSData
    std::shared_ptr<cola2_msgs::msg::GPSData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GPSData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time_utc != other.time_utc) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->fix_quality != other.fix_quality) {
      return false;
    }
    if (this->number_of_satellites != other.number_of_satellites) {
      return false;
    }
    if (this->hdop != other.hdop) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->geoidal_separation != other.geoidal_separation) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->latitude_stdev != other.latitude_stdev) {
      return false;
    }
    if (this->longitude_stdev != other.longitude_stdev) {
      return false;
    }
    if (this->altitude_stdev != other.altitude_stdev) {
      return false;
    }
    if (this->raw_gpgga != other.raw_gpgga) {
      return false;
    }
    if (this->raw_gphdt != other.raw_gphdt) {
      return false;
    }
    if (this->raw_gpgst != other.raw_gpgst) {
      return false;
    }
    return true;
  }
  bool operator!=(const GPSData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GPSData_

// alias to use template instance with default allocator
using GPSData =
  cola2_msgs::msg::GPSData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_HPP_
