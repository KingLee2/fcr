// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from opennav_coverage_msgs:msg/PathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__TRAITS_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "opennav_coverage_msgs/msg/detail/path_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace opennav_coverage_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PathMode & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: continuity_mode
  {
    out << "continuity_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.continuity_mode, out);
    out << ", ";
  }

  // member: turn_point_distance
  {
    out << "turn_point_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.turn_point_distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PathMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: continuity_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "continuity_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.continuity_mode, out);
    out << "\n";
  }

  // member: turn_point_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "turn_point_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.turn_point_distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PathMode & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::msg::PathMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::msg::PathMode & msg)
{
  return opennav_coverage_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::msg::PathMode>()
{
  return "opennav_coverage_msgs::msg::PathMode";
}

template<>
inline const char * name<opennav_coverage_msgs::msg::PathMode>()
{
  return "opennav_coverage_msgs/msg/PathMode";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::msg::PathMode>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::msg::PathMode>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<opennav_coverage_msgs::msg::PathMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_MODE__TRAITS_HPP_
