// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from opennav_coverage_msgs:msg/HeadlandMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/headland_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__HEADLAND_MODE__STRUCT_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__HEADLAND_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__msg__HeadlandMode __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__msg__HeadlandMode __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HeadlandMode_
{
  using Type = HeadlandMode_<ContainerAllocator>;

  explicit HeadlandMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = "UNKNOWN";
      this->width = 2.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = "";
      this->width = 0.0f;
    }
  }

  explicit HeadlandMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = "UNKNOWN";
      this->width = 2.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = "";
      this->width = 0.0f;
    }
  }

  // field types and members
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _width_type =
    float;
  _width_type width;

  // setters for named parameter idiom
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__msg__HeadlandMode
    std::shared_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__msg__HeadlandMode
    std::shared_ptr<opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HeadlandMode_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    return true;
  }
  bool operator!=(const HeadlandMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HeadlandMode_

// alias to use template instance with default allocator
using HeadlandMode =
  opennav_coverage_msgs::msg::HeadlandMode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__HEADLAND_MODE__STRUCT_HPP_
