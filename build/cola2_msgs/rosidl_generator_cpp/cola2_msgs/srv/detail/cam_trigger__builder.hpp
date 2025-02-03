// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cola2_msgs:srv/CamTrigger.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__BUILDER_HPP_
#define COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cola2_msgs/srv/detail/cam_trigger__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cola2_msgs
{

namespace srv
{

namespace builder
{

class Init_CamTrigger_Request_cam2
{
public:
  explicit Init_CamTrigger_Request_cam2(::cola2_msgs::srv::CamTrigger_Request & msg)
  : msg_(msg)
  {}
  ::cola2_msgs::srv::CamTrigger_Request cam2(::cola2_msgs::srv::CamTrigger_Request::_cam2_type arg)
  {
    msg_.cam2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::srv::CamTrigger_Request msg_;
};

class Init_CamTrigger_Request_cam1
{
public:
  explicit Init_CamTrigger_Request_cam1(::cola2_msgs::srv::CamTrigger_Request & msg)
  : msg_(msg)
  {}
  Init_CamTrigger_Request_cam2 cam1(::cola2_msgs::srv::CamTrigger_Request::_cam1_type arg)
  {
    msg_.cam1 = std::move(arg);
    return Init_CamTrigger_Request_cam2(msg_);
  }

private:
  ::cola2_msgs::srv::CamTrigger_Request msg_;
};

class Init_CamTrigger_Request_intensity2
{
public:
  explicit Init_CamTrigger_Request_intensity2(::cola2_msgs::srv::CamTrigger_Request & msg)
  : msg_(msg)
  {}
  Init_CamTrigger_Request_cam1 intensity2(::cola2_msgs::srv::CamTrigger_Request::_intensity2_type arg)
  {
    msg_.intensity2 = std::move(arg);
    return Init_CamTrigger_Request_cam1(msg_);
  }

private:
  ::cola2_msgs::srv::CamTrigger_Request msg_;
};

class Init_CamTrigger_Request_intensity1
{
public:
  Init_CamTrigger_Request_intensity1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CamTrigger_Request_intensity2 intensity1(::cola2_msgs::srv::CamTrigger_Request::_intensity1_type arg)
  {
    msg_.intensity1 = std::move(arg);
    return Init_CamTrigger_Request_intensity2(msg_);
  }

private:
  ::cola2_msgs::srv::CamTrigger_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::srv::CamTrigger_Request>()
{
  return cola2_msgs::srv::builder::Init_CamTrigger_Request_intensity1();
}

}  // namespace cola2_msgs


namespace cola2_msgs
{

namespace srv
{

namespace builder
{

class Init_CamTrigger_Response_success
{
public:
  Init_CamTrigger_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cola2_msgs::srv::CamTrigger_Response success(::cola2_msgs::srv::CamTrigger_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cola2_msgs::srv::CamTrigger_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cola2_msgs::srv::CamTrigger_Response>()
{
  return cola2_msgs::srv::builder::Init_CamTrigger_Response_success();
}

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__BUILDER_HPP_
