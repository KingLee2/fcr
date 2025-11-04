// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from opennav_coverage_msgs:msg/Coordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/coordinate.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__STRUCT_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__msg__Coordinate __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__msg__Coordinate __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Coordinate_
{
  using Type = Coordinate_<ContainerAllocator>;

  explicit Coordinate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->axis1 = 0.0f;
      this->axis2 = 0.0f;
    }
  }

  explicit Coordinate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->axis1 = 0.0f;
      this->axis2 = 0.0f;
    }
  }

  // field types and members
  using _axis1_type =
    float;
  _axis1_type axis1;
  using _axis2_type =
    float;
  _axis2_type axis2;

  // setters for named parameter idiom
  Type & set__axis1(
    const float & _arg)
  {
    this->axis1 = _arg;
    return *this;
  }
  Type & set__axis2(
    const float & _arg)
  {
    this->axis2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__msg__Coordinate
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__msg__Coordinate
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coordinate_ & other) const
  {
    if (this->axis1 != other.axis1) {
      return false;
    }
    if (this->axis2 != other.axis2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coordinate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coordinate_

// alias to use template instance with default allocator
using Coordinate =
  opennav_coverage_msgs::msg::Coordinate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__STRUCT_HPP_
