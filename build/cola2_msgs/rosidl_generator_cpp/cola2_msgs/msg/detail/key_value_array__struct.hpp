// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cola2_msgs:msg/KeyValueArray.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__STRUCT_HPP_
#define COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'keyvalues'
#include "cola2_msgs/msg/detail/key_value__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cola2_msgs__msg__KeyValueArray __attribute__((deprecated))
#else
# define DEPRECATED__cola2_msgs__msg__KeyValueArray __declspec(deprecated)
#endif

namespace cola2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KeyValueArray_
{
  using Type = KeyValueArray_<ContainerAllocator>;

  explicit KeyValueArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit KeyValueArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _keyvalues_type =
    std::vector<cola2_msgs::msg::KeyValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cola2_msgs::msg::KeyValue_<ContainerAllocator>>>;
  _keyvalues_type keyvalues;

  // setters for named parameter idiom
  Type & set__keyvalues(
    const std::vector<cola2_msgs::msg::KeyValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cola2_msgs::msg::KeyValue_<ContainerAllocator>>> & _arg)
  {
    this->keyvalues = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cola2_msgs::msg::KeyValueArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const cola2_msgs::msg::KeyValueArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::KeyValueArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cola2_msgs::msg::KeyValueArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cola2_msgs__msg__KeyValueArray
    std::shared_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cola2_msgs__msg__KeyValueArray
    std::shared_ptr<cola2_msgs::msg::KeyValueArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyValueArray_ & other) const
  {
    if (this->keyvalues != other.keyvalues) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyValueArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyValueArray_

// alias to use template instance with default allocator
using KeyValueArray =
  cola2_msgs::msg::KeyValueArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cola2_msgs

#endif  // COLA2_MSGS__MSG__DETAIL__KEY_VALUE_ARRAY__STRUCT_HPP_
