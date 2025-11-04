// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_components.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__STRUCT_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__STRUCT_HPP_

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
// Member 'swaths'
#include "opennav_coverage_msgs/msg/detail/swath__struct.hpp"
// Member 'turns'
#include "nav_msgs/msg/detail/path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__msg__PathComponents __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__msg__PathComponents __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PathComponents_
{
  using Type = PathComponents_<ContainerAllocator>;

  explicit PathComponents_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->contains_turns = false;
      this->swaths_ordered = false;
    }
  }

  explicit PathComponents_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->contains_turns = false;
      this->swaths_ordered = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _swaths_type =
    std::vector<opennav_coverage_msgs::msg::Swath_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::msg::Swath_<ContainerAllocator>>>;
  _swaths_type swaths;
  using _turns_type =
    std::vector<nav_msgs::msg::Path_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_msgs::msg::Path_<ContainerAllocator>>>;
  _turns_type turns;
  using _contains_turns_type =
    bool;
  _contains_turns_type contains_turns;
  using _swaths_ordered_type =
    bool;
  _swaths_ordered_type swaths_ordered;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__swaths(
    const std::vector<opennav_coverage_msgs::msg::Swath_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::msg::Swath_<ContainerAllocator>>> & _arg)
  {
    this->swaths = _arg;
    return *this;
  }
  Type & set__turns(
    const std::vector<nav_msgs::msg::Path_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_msgs::msg::Path_<ContainerAllocator>>> & _arg)
  {
    this->turns = _arg;
    return *this;
  }
  Type & set__contains_turns(
    const bool & _arg)
  {
    this->contains_turns = _arg;
    return *this;
  }
  Type & set__swaths_ordered(
    const bool & _arg)
  {
    this->swaths_ordered = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__msg__PathComponents
    std::shared_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__msg__PathComponents
    std::shared_ptr<opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathComponents_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->swaths != other.swaths) {
      return false;
    }
    if (this->turns != other.turns) {
      return false;
    }
    if (this->contains_turns != other.contains_turns) {
      return false;
    }
    if (this->swaths_ordered != other.swaths_ordered) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathComponents_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathComponents_

// alias to use template instance with default allocator
using PathComponents =
  opennav_coverage_msgs::msg::PathComponents_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__STRUCT_HPP_
