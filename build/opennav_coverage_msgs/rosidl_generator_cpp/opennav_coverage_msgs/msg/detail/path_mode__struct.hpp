// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from opennav_coverage_msgs:msg/PathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__STRUCT_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__msg__PathMode __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__msg__PathMode __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PathMode_
{
  using Type = PathMode_<ContainerAllocator>;

  explicit PathMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = "UNKNOWN";
      this->continuity_mode = "UNKNOWN";
      this->turn_point_distance = 0.1f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = "";
      this->continuity_mode = "";
      this->turn_point_distance = 0.0f;
    }
  }

  explicit PathMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mode(_alloc),
    continuity_mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = "UNKNOWN";
      this->continuity_mode = "UNKNOWN";
      this->turn_point_distance = 0.1f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = "";
      this->continuity_mode = "";
      this->turn_point_distance = 0.0f;
    }
  }

  // field types and members
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _continuity_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _continuity_mode_type continuity_mode;
  using _turn_point_distance_type =
    float;
  _turn_point_distance_type turn_point_distance;

  // setters for named parameter idiom
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__continuity_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->continuity_mode = _arg;
    return *this;
  }
  Type & set__turn_point_distance(
    const float & _arg)
  {
    this->turn_point_distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::msg::PathMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::msg::PathMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::PathMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::PathMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__msg__PathMode
    std::shared_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__msg__PathMode
    std::shared_ptr<opennav_coverage_msgs::msg::PathMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathMode_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->continuity_mode != other.continuity_mode) {
      return false;
    }
    if (this->turn_point_distance != other.turn_point_distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathMode_

// alias to use template instance with default allocator
using PathMode =
  opennav_coverage_msgs::msg::PathMode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__STRUCT_HPP_
