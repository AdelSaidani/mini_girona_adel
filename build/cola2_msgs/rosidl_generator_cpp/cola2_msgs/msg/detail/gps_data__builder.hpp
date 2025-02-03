// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__GPS_DATA__BUILDER_HPP_
#define COLA2_MSGS__MSG__DETAIL__GPS_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/msg/detail/gps_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace msg
{

namespace builder
{

class Init_GPSData_raw_gpgst
{
public:
  explicit Init_GPSData_raw_gpgst(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  ::cola2_msgs::msg::GPSData raw_gpgst(::cola2_msgs::msg::GPSData::_raw_gpgst_type arg)
  {
    msg_.raw_gpgst = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_raw_gphdt
{
public:
  explicit Init_GPSData_raw_gphdt(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_raw_gpgst raw_gphdt(::cola2_msgs::msg::GPSData::_raw_gphdt_type arg)
  {
    msg_.raw_gphdt = std::move(arg);
    return Init_GPSData_raw_gpgst(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_raw_gpgga
{
public:
  explicit Init_GPSData_raw_gpgga(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_raw_gphdt raw_gpgga(::cola2_msgs::msg::GPSData::_raw_gpgga_type arg)
  {
    msg_.raw_gpgga = std::move(arg);
    return Init_GPSData_raw_gphdt(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_altitude_stdev
{
public:
  explicit Init_GPSData_altitude_stdev(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_raw_gpgga altitude_stdev(::cola2_msgs::msg::GPSData::_altitude_stdev_type arg)
  {
    msg_.altitude_stdev = std::move(arg);
    return Init_GPSData_raw_gpgga(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_longitude_stdev
{
public:
  explicit Init_GPSData_longitude_stdev(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_altitude_stdev longitude_stdev(::cola2_msgs::msg::GPSData::_longitude_stdev_type arg)
  {
    msg_.longitude_stdev = std::move(arg);
    return Init_GPSData_altitude_stdev(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_latitude_stdev
{
public:
  explicit Init_GPSData_latitude_stdev(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_longitude_stdev latitude_stdev(::cola2_msgs::msg::GPSData::_latitude_stdev_type arg)
  {
    msg_.latitude_stdev = std::move(arg);
    return Init_GPSData_longitude_stdev(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_heading
{
public:
  explicit Init_GPSData_heading(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_latitude_stdev heading(::cola2_msgs::msg::GPSData::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_GPSData_latitude_stdev(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_geoidal_separation
{
public:
  explicit Init_GPSData_geoidal_separation(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_heading geoidal_separation(::cola2_msgs::msg::GPSData::_geoidal_separation_type arg)
  {
    msg_.geoidal_separation = std::move(arg);
    return Init_GPSData_heading(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_altitude
{
public:
  explicit Init_GPSData_altitude(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_geoidal_separation altitude(::cola2_msgs::msg::GPSData::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_GPSData_geoidal_separation(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_hdop
{
public:
  explicit Init_GPSData_hdop(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_altitude hdop(::cola2_msgs::msg::GPSData::_hdop_type arg)
  {
    msg_.hdop = std::move(arg);
    return Init_GPSData_altitude(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_number_of_satellites
{
public:
  explicit Init_GPSData_number_of_satellites(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_hdop number_of_satellites(::cola2_msgs::msg::GPSData::_number_of_satellites_type arg)
  {
    msg_.number_of_satellites = std::move(arg);
    return Init_GPSData_hdop(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_fix_quality
{
public:
  explicit Init_GPSData_fix_quality(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_number_of_satellites fix_quality(::cola2_msgs::msg::GPSData::_fix_quality_type arg)
  {
    msg_.fix_quality = std::move(arg);
    return Init_GPSData_number_of_satellites(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_longitude
{
public:
  explicit Init_GPSData_longitude(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_fix_quality longitude(::cola2_msgs::msg::GPSData::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_GPSData_fix_quality(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_latitude
{
public:
  explicit Init_GPSData_latitude(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_longitude latitude(::cola2_msgs::msg::GPSData::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_GPSData_longitude(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_time_utc
{
public:
  explicit Init_GPSData_time_utc(::cola2_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_latitude time_utc(::cola2_msgs::msg::GPSData::_time_utc_type arg)
  {
    msg_.time_utc = std::move(arg);
    return Init_GPSData_latitude(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

class Init_GPSData_header
{
public:
  Init_GPSData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GPSData_time_utc header(::cola2_msgs::msg::GPSData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GPSData_time_utc(msg_);
  }

private:
  ::cola2_msgs::msg::GPSData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::msg::GPSData>()
{
  return cola2_msgs::msg::builder::Init_GPSData_header();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__GPS_DATA__BUILDER_HPP_
