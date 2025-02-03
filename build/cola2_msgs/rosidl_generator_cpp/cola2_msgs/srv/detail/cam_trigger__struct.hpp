// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:srv/CamTrigger.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__STRUCT_HPP_
#define COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cola2_msgs__srv__CamTrigger_Request __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__srv__CamTrigger_Request __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CamTrigger_Request_
{
  using Type = CamTrigger_Request_<ContainerAllocator>;

  explicit CamTrigger_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->intensity1 = 0.0;
      this->intensity2 = 0.0;
      this->cam1 = false;
      this->cam2 = false;
    }
  }

  explicit CamTrigger_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->intensity1 = 0.0;
      this->intensity2 = 0.0;
      this->cam1 = false;
      this->cam2 = false;
    }
  }

  // field types and members
  using _intensity1_type =
    double;
  _intensity1_type intensity1;
  using _intensity2_type =
    double;
  _intensity2_type intensity2;
  using _cam1_type =
    bool;
  _cam1_type cam1;
  using _cam2_type =
    bool;
  _cam2_type cam2;

  // setters for named parameter idiom
  Type & set__intensity1(
    const double & _arg)
  {
    this->intensity1 = _arg;
    return *this;
  }
  Type & set__intensity2(
    const double & _arg)
  {
    this->intensity2 = _arg;
    return *this;
  }
  Type & set__cam1(
    const bool & _arg)
  {
    this->cam1 = _arg;
    return *this;
  }
  Type & set__cam2(
    const bool & _arg)
  {
    this->cam2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__srv__CamTrigger_Request
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__srv__CamTrigger_Request
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CamTrigger_Request_ & other) const
  {
    if (this->intensity1 != other.intensity1) {
      return false;
    }
    if (this->intensity2 != other.intensity2) {
      return false;
    }
    if (this->cam1 != other.cam1) {
      return false;
    }
    if (this->cam2 != other.cam2) {
      return false;
    }
    return true;
  }
  bool operator!=(const CamTrigger_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CamTrigger_Request_

// alias to use template instance with default allocator
using CamTrigger_Request =
  cola2_msgs::srv::CamTrigger_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cola2_msgs


#ifndef _WIN32
# define DEPRECATED__cola2_msgs__srv__CamTrigger_Response __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__srv__CamTrigger_Response __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CamTrigger_Response_
{
  using Type = CamTrigger_Response_<ContainerAllocator>;

  explicit CamTrigger_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit CamTrigger_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__srv__CamTrigger_Response
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__srv__CamTrigger_Response
    std::shared_ptr<cola2_msgs::srv::CamTrigger_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CamTrigger_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const CamTrigger_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CamTrigger_Response_

// alias to use template instance with default allocator
using CamTrigger_Response =
  cola2_msgs::srv::CamTrigger_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cola2_msgs

namespace cola2_msgs
{

namespace srv
{

struct CamTrigger
{
  using Request = cola2_msgs::srv::CamTrigger_Request;
  using Response = cola2_msgs::srv::CamTrigger_Response;
};

}  // namespace srv

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__SRV__DETAIL__CAM_TRIGGER__STRUCT_HPP_
