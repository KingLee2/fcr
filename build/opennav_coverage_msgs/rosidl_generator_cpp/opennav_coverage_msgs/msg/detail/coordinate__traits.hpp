// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from opennav_coverage_msgs:msg/Coordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/coordinate.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__TRAITS_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "opennav_coverage_msgs/msg/detail/coordinate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace opennav_coverage_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Coordinate & msg,
  std::ostream & out)
{
  out << "{";
  // member: axis1
  {
    out << "axis1: ";
    rosidl_generator_traits::value_to_yaml(msg.axis1, out);
    out << ", ";
  }

  // member: axis2
  {
    out << "axis2: ";
    rosidl_generator_traits::value_to_yaml(msg.axis2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Coordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: axis1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis1: ";
    rosidl_generator_traits::value_to_yaml(msg.axis1, out);
    out << "\n";
  }

  // member: axis2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis2: ";
    rosidl_generator_traits::value_to_yaml(msg.axis2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Coordinate & msg, bool use_flow_style = false)
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
  const opennav_coverage_msgs::msg::Coordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::msg::Coordinate & msg)
{
  return opennav_coverage_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::msg::Coordinate>()
{
  return "opennav_coverage_msgs::msg::Coordinate";
}

template<>
inline const char * name<opennav_coverage_msgs::msg::Coordinate>()
{
  return "opennav_coverage_msgs/msg/Coordinate";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::msg::Coordinate>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::msg::Coordinate>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<opennav_coverage_msgs::msg::Coordinate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__COORDINATE__TRAITS_HPP_
