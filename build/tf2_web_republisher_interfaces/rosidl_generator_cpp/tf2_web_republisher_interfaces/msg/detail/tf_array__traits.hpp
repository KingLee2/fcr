// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tf2_web_republisher_interfaces:msg/TFArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tf2_web_republisher_interfaces/msg/tf_array.hpp"


#ifndef TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__TRAITS_HPP_
#define TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tf2_web_republisher_interfaces/msg/detail/tf_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'transforms'
#include "geometry_msgs/msg/detail/transform_stamped__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TFArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: transforms
  {
    if (msg.transforms.size() == 0) {
      out << "transforms: []";
    } else {
      out << "transforms: [";
      size_t pending_items = msg.transforms.size();
      for (auto item : msg.transforms) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TFArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: transforms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.transforms.size() == 0) {
      out << "transforms: []\n";
    } else {
      out << "transforms:\n";
      for (auto item : msg.transforms) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TFArray & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::msg::TFArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::msg::TFArray & msg)
{
  return tf2_web_republisher_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::msg::TFArray>()
{
  return "tf2_web_republisher_interfaces::msg::TFArray";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::msg::TFArray>()
{
  return "tf2_web_republisher_interfaces/msg/TFArray";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::msg::TFArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::msg::TFArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tf2_web_republisher_interfaces::msg::TFArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__TRAITS_HPP_
