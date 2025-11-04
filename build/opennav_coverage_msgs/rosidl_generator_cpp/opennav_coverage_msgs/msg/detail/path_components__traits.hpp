// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/path_components.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__TRAITS_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "opennav_coverage_msgs/msg/detail/path_components__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'swaths'
#include "opennav_coverage_msgs/msg/detail/swath__traits.hpp"
// Member 'turns'
#include "nav_msgs/msg/detail/path__traits.hpp"

namespace opennav_coverage_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PathComponents & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: swaths
  {
    if (msg.swaths.size() == 0) {
      out << "swaths: []";
    } else {
      out << "swaths: [";
      size_t pending_items = msg.swaths.size();
      for (auto item : msg.swaths) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: turns
  {
    if (msg.turns.size() == 0) {
      out << "turns: []";
    } else {
      out << "turns: [";
      size_t pending_items = msg.turns.size();
      for (auto item : msg.turns) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: contains_turns
  {
    out << "contains_turns: ";
    rosidl_generator_traits::value_to_yaml(msg.contains_turns, out);
    out << ", ";
  }

  // member: swaths_ordered
  {
    out << "swaths_ordered: ";
    rosidl_generator_traits::value_to_yaml(msg.swaths_ordered, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PathComponents & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: swaths
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.swaths.size() == 0) {
      out << "swaths: []\n";
    } else {
      out << "swaths:\n";
      for (auto item : msg.swaths) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: turns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.turns.size() == 0) {
      out << "turns: []\n";
    } else {
      out << "turns:\n";
      for (auto item : msg.turns) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: contains_turns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "contains_turns: ";
    rosidl_generator_traits::value_to_yaml(msg.contains_turns, out);
    out << "\n";
  }

  // member: swaths_ordered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "swaths_ordered: ";
    rosidl_generator_traits::value_to_yaml(msg.swaths_ordered, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PathComponents & msg, bool use_flow_style = false)
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
  const opennav_coverage_msgs::msg::PathComponents & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::msg::PathComponents & msg)
{
  return opennav_coverage_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::msg::PathComponents>()
{
  return "opennav_coverage_msgs::msg::PathComponents";
}

template<>
inline const char * name<opennav_coverage_msgs::msg::PathComponents>()
{
  return "opennav_coverage_msgs/msg/PathComponents";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::msg::PathComponents>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::msg::PathComponents>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<opennav_coverage_msgs::msg::PathComponents>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__PATH_COMPONENTS__TRAITS_HPP_
