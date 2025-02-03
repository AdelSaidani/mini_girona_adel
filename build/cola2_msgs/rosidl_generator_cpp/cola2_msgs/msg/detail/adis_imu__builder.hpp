// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:msg/AdisImu.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__ADIS_IMU__BUILDER_HPP_
#define COLA2_MSGS__MSG__DETAIL__ADIS_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/msg/detail/adis_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace msg
{

namespace builder
{

class Init_AdisImu_w
{
public:
  explicit Init_AdisImu_w(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  ::cola2_msgs::msg::AdisImu w(::cola2_msgs::msg::AdisImu::_w_type arg)
  {
    msg_.w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_e
{
public:
  explicit Init_AdisImu_e(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_w e(::cola2_msgs::msg::AdisImu::_e_type arg)
  {
    msg_.e = std::move(arg);
    return Init_AdisImu_w(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_f
{
public:
  explicit Init_AdisImu_f(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_e f(::cola2_msgs::msg::AdisImu::_f_type arg)
  {
    msg_.f = std::move(arg);
    return Init_AdisImu_e(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_b
{
public:
  explicit Init_AdisImu_b(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_f b(::cola2_msgs::msg::AdisImu::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_AdisImu_f(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_t
{
public:
  explicit Init_AdisImu_t(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_b t(::cola2_msgs::msg::AdisImu::_t_type arg)
  {
    msg_.t = std::move(arg);
    return Init_AdisImu_b(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_az
{
public:
  explicit Init_AdisImu_az(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_t az(::cola2_msgs::msg::AdisImu::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_AdisImu_t(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_ay
{
public:
  explicit Init_AdisImu_ay(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_az ay(::cola2_msgs::msg::AdisImu::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_AdisImu_az(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_ax
{
public:
  explicit Init_AdisImu_ax(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_ay ax(::cola2_msgs::msg::AdisImu::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_AdisImu_ay(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_gz
{
public:
  explicit Init_AdisImu_gz(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_ax gz(::cola2_msgs::msg::AdisImu::_gz_type arg)
  {
    msg_.gz = std::move(arg);
    return Init_AdisImu_ax(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_gy
{
public:
  explicit Init_AdisImu_gy(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_gz gy(::cola2_msgs::msg::AdisImu::_gy_type arg)
  {
    msg_.gy = std::move(arg);
    return Init_AdisImu_gz(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_gx
{
public:
  explicit Init_AdisImu_gx(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_gy gx(::cola2_msgs::msg::AdisImu::_gx_type arg)
  {
    msg_.gx = std::move(arg);
    return Init_AdisImu_gy(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_mz
{
public:
  explicit Init_AdisImu_mz(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_gx mz(::cola2_msgs::msg::AdisImu::_mz_type arg)
  {
    msg_.mz = std::move(arg);
    return Init_AdisImu_gx(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_my
{
public:
  explicit Init_AdisImu_my(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_mz my(::cola2_msgs::msg::AdisImu::_my_type arg)
  {
    msg_.my = std::move(arg);
    return Init_AdisImu_mz(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_mx
{
public:
  explicit Init_AdisImu_mx(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_my mx(::cola2_msgs::msg::AdisImu::_mx_type arg)
  {
    msg_.mx = std::move(arg);
    return Init_AdisImu_my(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_raw
{
public:
  explicit Init_AdisImu_raw(::cola2_msgs::msg::AdisImu & msg)
  : msg_(msg)
  {}
  Init_AdisImu_mx raw(::cola2_msgs::msg::AdisImu::_raw_type arg)
  {
    msg_.raw = std::move(arg);
    return Init_AdisImu_mx(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

class Init_AdisImu_header
{
public:
  Init_AdisImu_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AdisImu_raw header(::cola2_msgs::msg::AdisImu::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AdisImu_raw(msg_);
  }

private:
  ::cola2_msgs::msg::AdisImu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::msg::AdisImu>()
{
  return cola2_msgs::msg::builder::Init_AdisImu_header();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__ADIS_IMU__BUILDER_HPP_
