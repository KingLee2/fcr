// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from opennav_coverage_msgs:msg/RowSwathMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/msg/row_swath_mode.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__TRAITS_HPP_
#define OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "opennav_coverage_msgs/msg/detail/row_swath_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace opennav_coverage_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RowSwathMode & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: skip_ids
  {
    if (msg.skip_ids.size() == 0) {
      out << "skip_ids: []";
    } else {
      out << "skip_ids: [";
      size_t pending_items = msg.skip_ids.size();
      for (auto item : msg.skip_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: offset
  {
    out << "offset: ";
    rosidl_generator_traits::value_to_yaml(msg.offset, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RowSwathMode & msg,
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

  // member: skip_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.skip_ids.size() == 0) {
      out << "skip_ids: []\n";
    } else {
      out << "skip_ids:\n";
      for (auto item : msg.skip_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset: ";
    rosidl_generator_traits::value_to_yaml(msg.offset, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RowSwathMode & msg, bool use_flow_style = false)
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
  const opennav_coverage_msgs::msg::RowSwathMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::msg::RowSwathMode & msg)
{
  return opennav_coverage_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::msg::RowSwathMode>()
{
  return "opennav_coverage_msgs::msg::RowSwathMode";
}

template<>
inline const char * name<opennav_coverage_msgs::msg::RowSwathMode>()
{
  return "opennav_coverage_msgs/msg/RowSwathMode";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::msg::RowSwathMode>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::msg::RowSwathMode>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<opennav_coverage_msgs::msg::RowSwathMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPENNAV_COVERAGE_MSGS__MSG__DETAIL__ROW_SWATH_MODE__TRAITS_HPP_
