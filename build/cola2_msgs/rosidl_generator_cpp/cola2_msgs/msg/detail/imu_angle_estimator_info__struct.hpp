// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__STRUCT_HPP_
#define COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__STRUCT_HPP_

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
# define DEPRECATED__cola2_msgs__msg__ImuAngleEstimatorInfo __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__msg__ImuAngleEstimatorInfo __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImuAngleEstimatorInfo_
{
  using Type = ImuAngleEstimatorInfo_<ContainerAllocator>;

  explicit ImuAngleEstimatorInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->period = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->mx = 0.0;
      this->my = 0.0;
      this->mz = 0.0;
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->tilt_roll = 0.0;
      this->tilt_pitch = 0.0;
      this->tilt_yaw = 0.0;
      this->rate_tilt_roll = 0.0;
      this->rate_tilt_pitch = 0.0;
      this->rate_tilt_yaw = 0.0;
      this->tilt_angular_velocity_x = 0.0;
      this->tilt_angular_velocity_y = 0.0;
      this->tilt_angular_velocity_z = 0.0;
      this->bias_roll_from_this_iteration = 0.0;
      this->bias_pitch_from_this_iteration = 0.0;
      this->bias_yaw_from_this_iteration = 0.0;
      this->bias_roll = 0.0;
      this->bias_pitch = 0.0;
      this->bias_yaw = 0.0;
      this->bias_buffer_size = 0l;
      this->merging_filter_coefficient = 0.0;
      this->corrected_angular_velocity_x = 0.0;
      this->corrected_angular_velocity_y = 0.0;
      this->corrected_angular_velocity_z = 0.0;
      this->gyro_integrated_roll = 0.0;
      this->gyro_integrated_pitch = 0.0;
      this->gyro_integrated_yaw = 0.0;
      this->gyro_roll_innovation = 0.0;
      this->gyro_pitch_innovation = 0.0;
      this->gyro_yaw_innovation = 0.0;
      this->tilt_roll_innovation = 0.0;
      this->tilt_pitch_innovation = 0.0;
      this->tilt_yaw_innovation = 0.0;
      this->roll_innovation = 0.0;
      this->pitch_innovation = 0.0;
      this->yaw_innovation = 0.0;
      this->merged_roll = 0.0;
      this->merged_pitch = 0.0;
      this->merged_yaw = 0.0;
      this->merged_minus_tilt_roll = 0.0;
      this->merged_minus_tilt_pitch = 0.0;
      this->merged_minus_tilt_yaw = 0.0;
      this->status = "";
      this->filter_elapsed_time = 0.0;
    }
  }

  explicit ImuAngleEstimatorInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->period = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->mx = 0.0;
      this->my = 0.0;
      this->mz = 0.0;
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->tilt_roll = 0.0;
      this->tilt_pitch = 0.0;
      this->tilt_yaw = 0.0;
      this->rate_tilt_roll = 0.0;
      this->rate_tilt_pitch = 0.0;
      this->rate_tilt_yaw = 0.0;
      this->tilt_angular_velocity_x = 0.0;
      this->tilt_angular_velocity_y = 0.0;
      this->tilt_angular_velocity_z = 0.0;
      this->bias_roll_from_this_iteration = 0.0;
      this->bias_pitch_from_this_iteration = 0.0;
      this->bias_yaw_from_this_iteration = 0.0;
      this->bias_roll = 0.0;
      this->bias_pitch = 0.0;
      this->bias_yaw = 0.0;
      this->bias_buffer_size = 0l;
      this->merging_filter_coefficient = 0.0;
      this->corrected_angular_velocity_x = 0.0;
      this->corrected_angular_velocity_y = 0.0;
      this->corrected_angular_velocity_z = 0.0;
      this->gyro_integrated_roll = 0.0;
      this->gyro_integrated_pitch = 0.0;
      this->gyro_integrated_yaw = 0.0;
      this->gyro_roll_innovation = 0.0;
      this->gyro_pitch_innovation = 0.0;
      this->gyro_yaw_innovation = 0.0;
      this->tilt_roll_innovation = 0.0;
      this->tilt_pitch_innovation = 0.0;
      this->tilt_yaw_innovation = 0.0;
      this->roll_innovation = 0.0;
      this->pitch_innovation = 0.0;
      this->yaw_innovation = 0.0;
      this->merged_roll = 0.0;
      this->merged_pitch = 0.0;
      this->merged_yaw = 0.0;
      this->merged_minus_tilt_roll = 0.0;
      this->merged_minus_tilt_pitch = 0.0;
      this->merged_minus_tilt_yaw = 0.0;
      this->status = "";
      this->filter_elapsed_time = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _period_type =
    double;
  _period_type period;
  using _ax_type =
    double;
  _ax_type ax;
  using _ay_type =
    double;
  _ay_type ay;
  using _az_type =
    double;
  _az_type az;
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
  using _tilt_roll_type =
    double;
  _tilt_roll_type tilt_roll;
  using _tilt_pitch_type =
    double;
  _tilt_pitch_type tilt_pitch;
  using _tilt_yaw_type =
    double;
  _tilt_yaw_type tilt_yaw;
  using _rate_tilt_roll_type =
    double;
  _rate_tilt_roll_type rate_tilt_roll;
  using _rate_tilt_pitch_type =
    double;
  _rate_tilt_pitch_type rate_tilt_pitch;
  using _rate_tilt_yaw_type =
    double;
  _rate_tilt_yaw_type rate_tilt_yaw;
  using _tilt_angular_velocity_x_type =
    double;
  _tilt_angular_velocity_x_type tilt_angular_velocity_x;
  using _tilt_angular_velocity_y_type =
    double;
  _tilt_angular_velocity_y_type tilt_angular_velocity_y;
  using _tilt_angular_velocity_z_type =
    double;
  _tilt_angular_velocity_z_type tilt_angular_velocity_z;
  using _bias_roll_from_this_iteration_type =
    double;
  _bias_roll_from_this_iteration_type bias_roll_from_this_iteration;
  using _bias_pitch_from_this_iteration_type =
    double;
  _bias_pitch_from_this_iteration_type bias_pitch_from_this_iteration;
  using _bias_yaw_from_this_iteration_type =
    double;
  _bias_yaw_from_this_iteration_type bias_yaw_from_this_iteration;
  using _bias_roll_type =
    double;
  _bias_roll_type bias_roll;
  using _bias_pitch_type =
    double;
  _bias_pitch_type bias_pitch;
  using _bias_yaw_type =
    double;
  _bias_yaw_type bias_yaw;
  using _bias_buffer_size_type =
    int32_t;
  _bias_buffer_size_type bias_buffer_size;
  using _merging_filter_coefficient_type =
    double;
  _merging_filter_coefficient_type merging_filter_coefficient;
  using _corrected_angular_velocity_x_type =
    double;
  _corrected_angular_velocity_x_type corrected_angular_velocity_x;
  using _corrected_angular_velocity_y_type =
    double;
  _corrected_angular_velocity_y_type corrected_angular_velocity_y;
  using _corrected_angular_velocity_z_type =
    double;
  _corrected_angular_velocity_z_type corrected_angular_velocity_z;
  using _gyro_integrated_roll_type =
    double;
  _gyro_integrated_roll_type gyro_integrated_roll;
  using _gyro_integrated_pitch_type =
    double;
  _gyro_integrated_pitch_type gyro_integrated_pitch;
  using _gyro_integrated_yaw_type =
    double;
  _gyro_integrated_yaw_type gyro_integrated_yaw;
  using _gyro_roll_innovation_type =
    double;
  _gyro_roll_innovation_type gyro_roll_innovation;
  using _gyro_pitch_innovation_type =
    double;
  _gyro_pitch_innovation_type gyro_pitch_innovation;
  using _gyro_yaw_innovation_type =
    double;
  _gyro_yaw_innovation_type gyro_yaw_innovation;
  using _tilt_roll_innovation_type =
    double;
  _tilt_roll_innovation_type tilt_roll_innovation;
  using _tilt_pitch_innovation_type =
    double;
  _tilt_pitch_innovation_type tilt_pitch_innovation;
  using _tilt_yaw_innovation_type =
    double;
  _tilt_yaw_innovation_type tilt_yaw_innovation;
  using _roll_innovation_type =
    double;
  _roll_innovation_type roll_innovation;
  using _pitch_innovation_type =
    double;
  _pitch_innovation_type pitch_innovation;
  using _yaw_innovation_type =
    double;
  _yaw_innovation_type yaw_innovation;
  using _merged_roll_type =
    double;
  _merged_roll_type merged_roll;
  using _merged_pitch_type =
    double;
  _merged_pitch_type merged_pitch;
  using _merged_yaw_type =
    double;
  _merged_yaw_type merged_yaw;
  using _merged_minus_tilt_roll_type =
    double;
  _merged_minus_tilt_roll_type merged_minus_tilt_roll;
  using _merged_minus_tilt_pitch_type =
    double;
  _merged_minus_tilt_pitch_type merged_minus_tilt_pitch;
  using _merged_minus_tilt_yaw_type =
    double;
  _merged_minus_tilt_yaw_type merged_minus_tilt_yaw;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _filter_elapsed_time_type =
    double;
  _filter_elapsed_time_type filter_elapsed_time;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__period(
    const double & _arg)
  {
    this->period = _arg;
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
  Type & set__tilt_roll(
    const double & _arg)
  {
    this->tilt_roll = _arg;
    return *this;
  }
  Type & set__tilt_pitch(
    const double & _arg)
  {
    this->tilt_pitch = _arg;
    return *this;
  }
  Type & set__tilt_yaw(
    const double & _arg)
  {
    this->tilt_yaw = _arg;
    return *this;
  }
  Type & set__rate_tilt_roll(
    const double & _arg)
  {
    this->rate_tilt_roll = _arg;
    return *this;
  }
  Type & set__rate_tilt_pitch(
    const double & _arg)
  {
    this->rate_tilt_pitch = _arg;
    return *this;
  }
  Type & set__rate_tilt_yaw(
    const double & _arg)
  {
    this->rate_tilt_yaw = _arg;
    return *this;
  }
  Type & set__tilt_angular_velocity_x(
    const double & _arg)
  {
    this->tilt_angular_velocity_x = _arg;
    return *this;
  }
  Type & set__tilt_angular_velocity_y(
    const double & _arg)
  {
    this->tilt_angular_velocity_y = _arg;
    return *this;
  }
  Type & set__tilt_angular_velocity_z(
    const double & _arg)
  {
    this->tilt_angular_velocity_z = _arg;
    return *this;
  }
  Type & set__bias_roll_from_this_iteration(
    const double & _arg)
  {
    this->bias_roll_from_this_iteration = _arg;
    return *this;
  }
  Type & set__bias_pitch_from_this_iteration(
    const double & _arg)
  {
    this->bias_pitch_from_this_iteration = _arg;
    return *this;
  }
  Type & set__bias_yaw_from_this_iteration(
    const double & _arg)
  {
    this->bias_yaw_from_this_iteration = _arg;
    return *this;
  }
  Type & set__bias_roll(
    const double & _arg)
  {
    this->bias_roll = _arg;
    return *this;
  }
  Type & set__bias_pitch(
    const double & _arg)
  {
    this->bias_pitch = _arg;
    return *this;
  }
  Type & set__bias_yaw(
    const double & _arg)
  {
    this->bias_yaw = _arg;
    return *this;
  }
  Type & set__bias_buffer_size(
    const int32_t & _arg)
  {
    this->bias_buffer_size = _arg;
    return *this;
  }
  Type & set__merging_filter_coefficient(
    const double & _arg)
  {
    this->merging_filter_coefficient = _arg;
    return *this;
  }
  Type & set__corrected_angular_velocity_x(
    const double & _arg)
  {
    this->corrected_angular_velocity_x = _arg;
    return *this;
  }
  Type & set__corrected_angular_velocity_y(
    const double & _arg)
  {
    this->corrected_angular_velocity_y = _arg;
    return *this;
  }
  Type & set__corrected_angular_velocity_z(
    const double & _arg)
  {
    this->corrected_angular_velocity_z = _arg;
    return *this;
  }
  Type & set__gyro_integrated_roll(
    const double & _arg)
  {
    this->gyro_integrated_roll = _arg;
    return *this;
  }
  Type & set__gyro_integrated_pitch(
    const double & _arg)
  {
    this->gyro_integrated_pitch = _arg;
    return *this;
  }
  Type & set__gyro_integrated_yaw(
    const double & _arg)
  {
    this->gyro_integrated_yaw = _arg;
    return *this;
  }
  Type & set__gyro_roll_innovation(
    const double & _arg)
  {
    this->gyro_roll_innovation = _arg;
    return *this;
  }
  Type & set__gyro_pitch_innovation(
    const double & _arg)
  {
    this->gyro_pitch_innovation = _arg;
    return *this;
  }
  Type & set__gyro_yaw_innovation(
    const double & _arg)
  {
    this->gyro_yaw_innovation = _arg;
    return *this;
  }
  Type & set__tilt_roll_innovation(
    const double & _arg)
  {
    this->tilt_roll_innovation = _arg;
    return *this;
  }
  Type & set__tilt_pitch_innovation(
    const double & _arg)
  {
    this->tilt_pitch_innovation = _arg;
    return *this;
  }
  Type & set__tilt_yaw_innovation(
    const double & _arg)
  {
    this->tilt_yaw_innovation = _arg;
    return *this;
  }
  Type & set__roll_innovation(
    const double & _arg)
  {
    this->roll_innovation = _arg;
    return *this;
  }
  Type & set__pitch_innovation(
    const double & _arg)
  {
    this->pitch_innovation = _arg;
    return *this;
  }
  Type & set__yaw_innovation(
    const double & _arg)
  {
    this->yaw_innovation = _arg;
    return *this;
  }
  Type & set__merged_roll(
    const double & _arg)
  {
    this->merged_roll = _arg;
    return *this;
  }
  Type & set__merged_pitch(
    const double & _arg)
  {
    this->merged_pitch = _arg;
    return *this;
  }
  Type & set__merged_yaw(
    const double & _arg)
  {
    this->merged_yaw = _arg;
    return *this;
  }
  Type & set__merged_minus_tilt_roll(
    const double & _arg)
  {
    this->merged_minus_tilt_roll = _arg;
    return *this;
  }
  Type & set__merged_minus_tilt_pitch(
    const double & _arg)
  {
    this->merged_minus_tilt_pitch = _arg;
    return *this;
  }
  Type & set__merged_minus_tilt_yaw(
    const double & _arg)
  {
    this->merged_minus_tilt_yaw = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__filter_elapsed_time(
    const double & _arg)
  {
    this->filter_elapsed_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__msg__ImuAngleEstimatorInfo
    std::shared_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__msg__ImuAngleEstimatorInfo
    std::shared_ptr<cola2_msgs::msg::ImuAngleEstimatorInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImuAngleEstimatorInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->period != other.period) {
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
    if (this->tilt_roll != other.tilt_roll) {
      return false;
    }
    if (this->tilt_pitch != other.tilt_pitch) {
      return false;
    }
    if (this->tilt_yaw != other.tilt_yaw) {
      return false;
    }
    if (this->rate_tilt_roll != other.rate_tilt_roll) {
      return false;
    }
    if (this->rate_tilt_pitch != other.rate_tilt_pitch) {
      return false;
    }
    if (this->rate_tilt_yaw != other.rate_tilt_yaw) {
      return false;
    }
    if (this->tilt_angular_velocity_x != other.tilt_angular_velocity_x) {
      return false;
    }
    if (this->tilt_angular_velocity_y != other.tilt_angular_velocity_y) {
      return false;
    }
    if (this->tilt_angular_velocity_z != other.tilt_angular_velocity_z) {
      return false;
    }
    if (this->bias_roll_from_this_iteration != other.bias_roll_from_this_iteration) {
      return false;
    }
    if (this->bias_pitch_from_this_iteration != other.bias_pitch_from_this_iteration) {
      return false;
    }
    if (this->bias_yaw_from_this_iteration != other.bias_yaw_from_this_iteration) {
      return false;
    }
    if (this->bias_roll != other.bias_roll) {
      return false;
    }
    if (this->bias_pitch != other.bias_pitch) {
      return false;
    }
    if (this->bias_yaw != other.bias_yaw) {
      return false;
    }
    if (this->bias_buffer_size != other.bias_buffer_size) {
      return false;
    }
    if (this->merging_filter_coefficient != other.merging_filter_coefficient) {
      return false;
    }
    if (this->corrected_angular_velocity_x != other.corrected_angular_velocity_x) {
      return false;
    }
    if (this->corrected_angular_velocity_y != other.corrected_angular_velocity_y) {
      return false;
    }
    if (this->corrected_angular_velocity_z != other.corrected_angular_velocity_z) {
      return false;
    }
    if (this->gyro_integrated_roll != other.gyro_integrated_roll) {
      return false;
    }
    if (this->gyro_integrated_pitch != other.gyro_integrated_pitch) {
      return false;
    }
    if (this->gyro_integrated_yaw != other.gyro_integrated_yaw) {
      return false;
    }
    if (this->gyro_roll_innovation != other.gyro_roll_innovation) {
      return false;
    }
    if (this->gyro_pitch_innovation != other.gyro_pitch_innovation) {
      return false;
    }
    if (this->gyro_yaw_innovation != other.gyro_yaw_innovation) {
      return false;
    }
    if (this->tilt_roll_innovation != other.tilt_roll_innovation) {
      return false;
    }
    if (this->tilt_pitch_innovation != other.tilt_pitch_innovation) {
      return false;
    }
    if (this->tilt_yaw_innovation != other.tilt_yaw_innovation) {
      return false;
    }
    if (this->roll_innovation != other.roll_innovation) {
      return false;
    }
    if (this->pitch_innovation != other.pitch_innovation) {
      return false;
    }
    if (this->yaw_innovation != other.yaw_innovation) {
      return false;
    }
    if (this->merged_roll != other.merged_roll) {
      return false;
    }
    if (this->merged_pitch != other.merged_pitch) {
      return false;
    }
    if (this->merged_yaw != other.merged_yaw) {
      return false;
    }
    if (this->merged_minus_tilt_roll != other.merged_minus_tilt_roll) {
      return false;
    }
    if (this->merged_minus_tilt_pitch != other.merged_minus_tilt_pitch) {
      return false;
    }
    if (this->merged_minus_tilt_yaw != other.merged_minus_tilt_yaw) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->filter_elapsed_time != other.filter_elapsed_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImuAngleEstimatorInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImuAngleEstimatorInfo_

// alias to use template instance with default allocator
using ImuAngleEstimatorInfo =
  cola2_msgs::msg::ImuAngleEstimatorInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__IMU_ANGLE_ESTIMATOR_INFO__STRUCT_HPP_
