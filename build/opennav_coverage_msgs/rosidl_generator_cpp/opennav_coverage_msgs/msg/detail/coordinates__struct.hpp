// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from opennav_coverage_msgs:msg/Coordinates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/coordinates.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__STRUCT_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'coordinates'
#include "opennav_coverage_msgs/msg/detail/coordinate__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__msg__Coordinates __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__msg__Coordinates __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Coordinates_
{
  using Type = Coordinates_<ContainerAllocator>;

  explicit Coordinates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Coordinates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _coordinates_type =
    std::vector<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>>>;
  _coordinates_type coordinates;

  // setters for named parameter idiom
  Type & set__coordinates(
    const std::vector<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::msg::Coordinate_<ContainerAllocator>>> & _arg)
  {
    this->coordinates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__msg__Coordinates
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__msg__Coordinates
    std::shared_ptr<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coordinates_ & other) const
  {
    if (this->coordinates != other.coordinates) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coordinates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coordinates_

// alias to use template instance with default allocator
using Coordinates =
  opennav_coverage_msgs::msg::Coordinates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATES__STRUCT_HPP_
