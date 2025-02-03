// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__BUILDER_HPP_
#define COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/msg/detail/image_acquisition_settings__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace msg
{

namespace builder
{

class Init_ImageAcquisitionSettings_extra
{
public:
  explicit Init_ImageAcquisitionSettings_extra(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  ::cola2_msgs::msg::ImageAcquisitionSettings extra(::cola2_msgs::msg::ImageAcquisitionSettings::_extra_type arg)
  {
    msg_.extra = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_focal_length
{
public:
  explicit Init_ImageAcquisitionSettings_focal_length(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  Init_ImageAcquisitionSettings_extra focal_length(::cola2_msgs::msg::ImageAcquisitionSettings::_focal_length_type arg)
  {
    msg_.focal_length = std::move(arg);
    return Init_ImageAcquisitionSettings_extra(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_aperture
{
public:
  explicit Init_ImageAcquisitionSettings_aperture(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  Init_ImageAcquisitionSettings_focal_length aperture(::cola2_msgs::msg::ImageAcquisitionSettings::_aperture_type arg)
  {
    msg_.aperture = std::move(arg);
    return Init_ImageAcquisitionSettings_focal_length(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_focus
{
public:
  explicit Init_ImageAcquisitionSettings_focus(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  Init_ImageAcquisitionSettings_aperture focus(::cola2_msgs::msg::ImageAcquisitionSettings::_focus_type arg)
  {
    msg_.focus = std::move(arg);
    return Init_ImageAcquisitionSettings_aperture(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_red_ratio
{
public:
  explicit Init_ImageAcquisitionSettings_red_ratio(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  Init_ImageAcquisitionSettings_focus red_ratio(::cola2_msgs::msg::ImageAcquisitionSettings::_red_ratio_type arg)
  {
    msg_.red_ratio = std::move(arg);
    return Init_ImageAcquisitionSettings_focus(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_blue_ratio
{
public:
  explicit Init_ImageAcquisitionSettings_blue_ratio(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  Init_ImageAcquisitionSettings_red_ratio blue_ratio(::cola2_msgs::msg::ImageAcquisitionSettings::_blue_ratio_type arg)
  {
    msg_.blue_ratio = std::move(arg);
    return Init_ImageAcquisitionSettings_red_ratio(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_gain
{
public:
  explicit Init_ImageAcquisitionSettings_gain(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  Init_ImageAcquisitionSettings_blue_ratio gain(::cola2_msgs::msg::ImageAcquisitionSettings::_gain_type arg)
  {
    msg_.gain = std::move(arg);
    return Init_ImageAcquisitionSettings_blue_ratio(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_exposure_time
{
public:
  explicit Init_ImageAcquisitionSettings_exposure_time(::cola2_msgs::msg::ImageAcquisitionSettings & msg)
  : msg_(msg)
  {}
  Init_ImageAcquisitionSettings_gain exposure_time(::cola2_msgs::msg::ImageAcquisitionSettings::_exposure_time_type arg)
  {
    msg_.exposure_time = std::move(arg);
    return Init_ImageAcquisitionSettings_gain(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

class Init_ImageAcquisitionSettings_header
{
public:
  Init_ImageAcquisitionSettings_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageAcquisitionSettings_exposure_time header(::cola2_msgs::msg::ImageAcquisitionSettings::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ImageAcquisitionSettings_exposure_time(msg_);
  }

private:
  ::cola2_msgs::msg::ImageAcquisitionSettings msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::msg::ImageAcquisitionSettings>()
{
  return cola2_msgs::msg::builder::Init_ImageAcquisitionSettings_header();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__IMAGE_ACQUISITION_SETTINGS__BUILDER_HPP_
