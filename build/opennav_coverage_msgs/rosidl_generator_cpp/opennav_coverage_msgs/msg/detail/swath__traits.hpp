// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from opennav_coverage_msgs:msg/Swath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/swath.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__TRAITS_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "opennav_coverage_msgs/msg/detail/swath__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'start'
// Member 'end'
#include "geometry_msgs/msg/detail/point32__traits.hpp"

namespace opennav_coverage_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Swath & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    to_flow_style_yaml(msg.start, out);
    out << ", ";
  }

  // member: end
  {
    out << "end: ";
    to_flow_style_yaml(msg.end, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Swath & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start:\n";
    to_block_style_yaml(msg.start, out, indentation + 2);
  }

  // member: end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end:\n";
    to_block_style_yaml(msg.end, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Swath & msg, bool use_flow_style = false)
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
  const opennav_coverage_msgs::msg::Swath & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::msg::Swath & msg)
{
  return opennav_coverage_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::msg::Swath>()
{
  return "opennav_coverage_msgs::msg::Swath";
}

template<>
inline const char * name<opennav_coverage_msgs::msg::Swath>()
{
  return "opennav_coverage_msgs/msg/Swath";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::msg::Swath>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::msg::Swath>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct is_message<opennav_coverage_msgs::msg::Swath>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__SWATH__TRAITS_HPP_
