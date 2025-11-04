// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from opennav_coverage_msgs:action/ComputeCoveragePath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/action/compute_coverage_path.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__STRUCT_HPP_
#define OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'polygons'
#include "opennav_coverage_msgs/msg/detail/coordinates__struct.hpp"
// Member 'headland_mode'
#include "opennav_coverage_msgs/msg/detail/headland_mode__struct.hpp"
// Member 'swath_mode'
#include "opennav_coverage_msgs/msg/detail/swath_mode__struct.hpp"
// Member 'row_swath_mode'
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__struct.hpp"
// Member 'route_mode'
#include "opennav_coverage_msgs/msg/detail/route_mode__struct.hpp"
// Member 'path_mode'
#include "opennav_coverage_msgs/msg/detail/path_mode__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Goal __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Goal __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_Goal_
{
  using Type = ComputeCoveragePath_Goal_<ContainerAllocator>;

  explicit ComputeCoveragePath_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : headland_mode(_init),
    swath_mode(_init),
    row_swath_mode(_init),
    route_mode(_init),
    path_mode(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->generate_headland = true;
      this->generate_route = true;
      this->generate_path = true;
      this->use_gml_file = false;
      this->frame_id = "map";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->generate_headland = false;
      this->generate_route = false;
      this->generate_path = false;
      this->use_gml_file = false;
      this->gml_field = "";
      this->frame_id = "";
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gml_field = "";
    }
  }

  explicit ComputeCoveragePath_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gml_field(_alloc),
    frame_id(_alloc),
    headland_mode(_alloc, _init),
    swath_mode(_alloc, _init),
    row_swath_mode(_alloc, _init),
    route_mode(_alloc, _init),
    path_mode(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->generate_headland = true;
      this->generate_route = true;
      this->generate_path = true;
      this->use_gml_file = false;
      this->frame_id = "map";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->generate_headland = false;
      this->generate_route = false;
      this->generate_path = false;
      this->use_gml_file = false;
      this->gml_field = "";
      this->frame_id = "";
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gml_field = "";
    }
  }

  // field types and members
  using _generate_headland_type =
    bool;
  _generate_headland_type generate_headland;
  using _generate_route_type =
    bool;
  _generate_route_type generate_route;
  using _generate_path_type =
    bool;
  _generate_path_type generate_path;
  using _use_gml_file_type =
    bool;
  _use_gml_file_type use_gml_file;
  using _gml_field_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _gml_field_type gml_field;
  using _polygons_type =
    std::vector<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>>>;
  _polygons_type polygons;
  using _frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _frame_id_type frame_id;
  using _headland_mode_type =
    opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator>;
  _headland_mode_type headland_mode;
  using _swath_mode_type =
    opennav_coverage_msgs::msg::SwathMode_<ContainerAllocator>;
  _swath_mode_type swath_mode;
  using _row_swath_mode_type =
    opennav_coverage_msgs::msg::RowSwathMode_<ContainerAllocator>;
  _row_swath_mode_type row_swath_mode;
  using _route_mode_type =
    opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator>;
  _route_mode_type route_mode;
  using _path_mode_type =
    opennav_coverage_msgs::msg::PathMode_<ContainerAllocator>;
  _path_mode_type path_mode;

  // setters for named parameter idiom
  Type & set__generate_headland(
    const bool & _arg)
  {
    this->generate_headland = _arg;
    return *this;
  }
  Type & set__generate_route(
    const bool & _arg)
  {
    this->generate_route = _arg;
    return *this;
  }
  Type & set__generate_path(
    const bool & _arg)
  {
    this->generate_path = _arg;
    return *this;
  }
  Type & set__use_gml_file(
    const bool & _arg)
  {
    this->use_gml_file = _arg;
    return *this;
  }
  Type & set__gml_field(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->gml_field = _arg;
    return *this;
  }
  Type & set__polygons(
    const std::vector<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::msg::Coordinates_<ContainerAllocator>>> & _arg)
  {
    this->polygons = _arg;
    return *this;
  }
  Type & set__frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }
  Type & set__headland_mode(
    const opennav_coverage_msgs::msg::HeadlandMode_<ContainerAllocator> & _arg)
  {
    this->headland_mode = _arg;
    return *this;
  }
  Type & set__swath_mode(
    const opennav_coverage_msgs::msg::SwathMode_<ContainerAllocator> & _arg)
  {
    this->swath_mode = _arg;
    return *this;
  }
  Type & set__row_swath_mode(
    const opennav_coverage_msgs::msg::RowSwathMode_<ContainerAllocator> & _arg)
  {
    this->row_swath_mode = _arg;
    return *this;
  }
  Type & set__route_mode(
    const opennav_coverage_msgs::msg::RouteMode_<ContainerAllocator> & _arg)
  {
    this->route_mode = _arg;
    return *this;
  }
  Type & set__path_mode(
    const opennav_coverage_msgs::msg::PathMode_<ContainerAllocator> & _arg)
  {
    this->path_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Goal
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Goal
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_Goal_ & other) const
  {
    if (this->generate_headland != other.generate_headland) {
      return false;
    }
    if (this->generate_route != other.generate_route) {
      return false;
    }
    if (this->generate_path != other.generate_path) {
      return false;
    }
    if (this->use_gml_file != other.use_gml_file) {
      return false;
    }
    if (this->gml_field != other.gml_field) {
      return false;
    }
    if (this->polygons != other.polygons) {
      return false;
    }
    if (this->frame_id != other.frame_id) {
      return false;
    }
    if (this->headland_mode != other.headland_mode) {
      return false;
    }
    if (this->swath_mode != other.swath_mode) {
      return false;
    }
    if (this->row_swath_mode != other.row_swath_mode) {
      return false;
    }
    if (this->route_mode != other.route_mode) {
      return false;
    }
    if (this->path_mode != other.path_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_Goal_

// alias to use template instance with default allocator
using ComputeCoveragePath_Goal =
  opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'nav_path'
#include "nav_msgs/msg/detail/path__struct.hpp"
// Member 'coverage_path'
#include "opennav_coverage_msgs/msg/detail/path_components__struct.hpp"
// Member 'planning_time'
#include "builtin_interfaces/msg/detail/duration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Result __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Result __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_Result_
{
  using Type = ComputeCoveragePath_Result_<ContainerAllocator>;

  explicit ComputeCoveragePath_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nav_path(_init),
    coverage_path(_init),
    planning_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error_code = 0;
    }
  }

  explicit ComputeCoveragePath_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nav_path(_alloc, _init),
    coverage_path(_alloc, _init),
    planning_time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error_code = 0;
    }
  }

  // field types and members
  using _nav_path_type =
    nav_msgs::msg::Path_<ContainerAllocator>;
  _nav_path_type nav_path;
  using _coverage_path_type =
    opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator>;
  _coverage_path_type coverage_path;
  using _planning_time_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _planning_time_type planning_time;
  using _error_code_type =
    uint16_t;
  _error_code_type error_code;

  // setters for named parameter idiom
  Type & set__nav_path(
    const nav_msgs::msg::Path_<ContainerAllocator> & _arg)
  {
    this->nav_path = _arg;
    return *this;
  }
  Type & set__coverage_path(
    const opennav_coverage_msgs::msg::PathComponents_<ContainerAllocator> & _arg)
  {
    this->coverage_path = _arg;
    return *this;
  }
  Type & set__planning_time(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->planning_time = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint16_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint16_t NONE =
    0u;
  static constexpr uint16_t INTERNAL_F2C_ERROR =
    801u;
  static constexpr uint16_t INVALID_MODE_SET =
    802u;
  static constexpr uint16_t INVALID_REQUEST =
    803u;
  static constexpr uint16_t INVALID_COORDS =
    803u;

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Result
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Result
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_Result_ & other) const
  {
    if (this->nav_path != other.nav_path) {
      return false;
    }
    if (this->coverage_path != other.coverage_path) {
      return false;
    }
    if (this->planning_time != other.planning_time) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_Result_

// alias to use template instance with default allocator
using ComputeCoveragePath_Result =
  opennav_coverage_msgs::action::ComputeCoveragePath_Result_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t ComputeCoveragePath_Result_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t ComputeCoveragePath_Result_<ContainerAllocator>::INTERNAL_F2C_ERROR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t ComputeCoveragePath_Result_<ContainerAllocator>::INVALID_MODE_SET;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t ComputeCoveragePath_Result_<ContainerAllocator>::INVALID_REQUEST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t ComputeCoveragePath_Result_<ContainerAllocator>::INVALID_COORDS;
#endif  // __cplusplus < 201703L

}  // namespace action

}  // namespace opennav_coverage_msgs


#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Feedback __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_Feedback_
{
  using Type = ComputeCoveragePath_Feedback_<ContainerAllocator>;

  explicit ComputeCoveragePath_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ComputeCoveragePath_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Feedback
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_Feedback
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_Feedback_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_Feedback_

// alias to use template instance with default allocator
using ComputeCoveragePath_Feedback =
  opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_SendGoal_Request_
{
  using Type = ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>;

  explicit ComputeCoveragePath_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit ComputeCoveragePath_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const opennav_coverage_msgs::action::ComputeCoveragePath_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_SendGoal_Request_

// alias to use template instance with default allocator
using ComputeCoveragePath_SendGoal_Request =
  opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_SendGoal_Response_
{
  using Type = ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>;

  explicit ComputeCoveragePath_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit ComputeCoveragePath_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_SendGoal_Response_

// alias to use template instance with default allocator
using ComputeCoveragePath_SendGoal_Response =
  opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_SendGoal_Event_
{
  using Type = ComputeCoveragePath_SendGoal_Event_<ContainerAllocator>;

  explicit ComputeCoveragePath_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ComputeCoveragePath_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_SendGoal_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_SendGoal_Event_

// alias to use template instance with default allocator
using ComputeCoveragePath_SendGoal_Event =
  opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace opennav_coverage_msgs
{

namespace action
{

struct ComputeCoveragePath_SendGoal
{
  using Request = opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request;
  using Response = opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response;
  using Event = opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event;
};

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_GetResult_Request_
{
  using Type = ComputeCoveragePath_GetResult_Request_<ContainerAllocator>;

  explicit ComputeCoveragePath_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit ComputeCoveragePath_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_GetResult_Request_

// alias to use template instance with default allocator
using ComputeCoveragePath_GetResult_Request =
  opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_GetResult_Response_
{
  using Type = ComputeCoveragePath_GetResult_Response_<ContainerAllocator>;

  explicit ComputeCoveragePath_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit ComputeCoveragePath_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const opennav_coverage_msgs::action::ComputeCoveragePath_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_GetResult_Response_

// alias to use template instance with default allocator
using ComputeCoveragePath_GetResult_Response =
  opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_GetResult_Event_
{
  using Type = ComputeCoveragePath_GetResult_Event_<ContainerAllocator>;

  explicit ComputeCoveragePath_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ComputeCoveragePath_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_GetResult_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_GetResult_Event_

// alias to use template instance with default allocator
using ComputeCoveragePath_GetResult_Event =
  opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace opennav_coverage_msgs
{

namespace action
{

struct ComputeCoveragePath_GetResult
{
  using Request = opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request;
  using Response = opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response;
  using Event = opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event;
};

}  // namespace action

}  // namespace opennav_coverage_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage __declspec(deprecated)
#endif

namespace opennav_coverage_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ComputeCoveragePath_FeedbackMessage_
{
  using Type = ComputeCoveragePath_FeedbackMessage_<ContainerAllocator>;

  explicit ComputeCoveragePath_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit ComputeCoveragePath_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const opennav_coverage_msgs::action::ComputeCoveragePath_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage
    std::shared_ptr<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputeCoveragePath_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputeCoveragePath_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputeCoveragePath_FeedbackMessage_

// alias to use template instance with default allocator
using ComputeCoveragePath_FeedbackMessage =
  opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace opennav_coverage_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

struct ComputeCoveragePath
{
  /// The goal message defined in the action definition.
  using Goal = opennav_coverage_msgs::action::ComputeCoveragePath_Goal;
  /// The result message defined in the action definition.
  using Result = opennav_coverage_msgs::action::ComputeCoveragePath_Result;
  /// The feedback message defined in the action definition.
  using Feedback = opennav_coverage_msgs::action::ComputeCoveragePath_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = opennav_coverage_msgs::action::ComputeCoveragePath_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct ComputeCoveragePath ComputeCoveragePath;

}  // namespace action

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__STRUCT_HPP_
