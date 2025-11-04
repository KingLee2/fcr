// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from opennav_coverage_msgs:msg/RouteMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/route_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__STRUCT_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__msg__RouteMode __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__msg__RouteMode __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RouteMode_
{
  using Type = RouteMode_<ContainerAllocator>;

  explicit RouteMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = "UNKNOWN";
      this->spiral_n = 4;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = "";
      this->spiral_n = 0;
    }
  }

  explicit RouteMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = "UNKNOWN";
      this->spiral_n = 4;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = "";
      this->spiral_n = 0;
    }
  }

  // field types and members
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _spiral_n_type =
    uint16_t;
  _spiral_n_type spiral_n;
  using _custom_order_type =
    std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>>;
  _custom_order_type custom_order;

  // setters for named parameter idiom
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__spiral_n(
    const uint16_t & _arg)
  {
    this->spiral_n = _arg;
    return *this;
  }
  Type & set__custom_order(
    const std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>> & _arg)
  {
    this->custom_order = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__msg__RouteMode
    std::shared_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__msg__RouteMode
    std::shared_ptr<opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RouteMode_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->spiral_n != other.spiral_n) {
      return false;
    }
    if (this->custom_order != other.custom_order) {
      return false;
    }
    return true;
  }
  bool operator!=(const RouteMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RouteMode_

// alias to use template instance with default allocator
using RouteMode =
  opennav_coverage_msgs::msg::RouteMode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROUTE_MODE__STRUCT_HPP_
