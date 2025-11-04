// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from opennav_coverage_msgs:action/ComputeCoveragePath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/action/compute_coverage_path.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__TRAITS_HPP_
#define OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'polygons'
#include "opennav_coverage_msgs/msg/detail/coordinates__traits.hpp"
// Member 'headland_mode'
#include "opennav_coverage_msgs/msg/detail/headland_mode__traits.hpp"
// Member 'swath_mode'
#include "opennav_coverage_msgs/msg/detail/swath_mode__traits.hpp"
// Member 'row_swath_mode'
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__traits.hpp"
// Member 'route_mode'
#include "opennav_coverage_msgs/msg/detail/route_mode__traits.hpp"
// Member 'path_mode'
#include "opennav_coverage_msgs/msg/detail/path_mode__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: generate_headland
  {
    out << "generate_headland: ";
    rosidl_generator_traits::value_to_yaml(msg.generate_headland, out);
    out << ", ";
  }

  // member: generate_route
  {
    out << "generate_route: ";
    rosidl_generator_traits::value_to_yaml(msg.generate_route, out);
    out << ", ";
  }

  // member: generate_path
  {
    out << "generate_path: ";
    rosidl_generator_traits::value_to_yaml(msg.generate_path, out);
    out << ", ";
  }

  // member: use_gml_file
  {
    out << "use_gml_file: ";
    rosidl_generator_traits::value_to_yaml(msg.use_gml_file, out);
    out << ", ";
  }

  // member: gml_field
  {
    out << "gml_field: ";
    rosidl_generator_traits::value_to_yaml(msg.gml_field, out);
    out << ", ";
  }

  // member: polygons
  {
    if (msg.polygons.size() == 0) {
      out << "polygons: []";
    } else {
      out << "polygons: [";
      size_t pending_items = msg.polygons.size();
      for (auto item : msg.polygons) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << ", ";
  }

  // member: headland_mode
  {
    out << "headland_mode: ";
    to_flow_style_yaml(msg.headland_mode, out);
    out << ", ";
  }

  // member: swath_mode
  {
    out << "swath_mode: ";
    to_flow_style_yaml(msg.swath_mode, out);
    out << ", ";
  }

  // member: row_swath_mode
  {
    out << "row_swath_mode: ";
    to_flow_style_yaml(msg.row_swath_mode, out);
    out << ", ";
  }

  // member: route_mode
  {
    out << "route_mode: ";
    to_flow_style_yaml(msg.route_mode, out);
    out << ", ";
  }

  // member: path_mode
  {
    out << "path_mode: ";
    to_flow_style_yaml(msg.path_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: generate_headland
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "generate_headland: ";
    rosidl_generator_traits::value_to_yaml(msg.generate_headland, out);
    out << "\n";
  }

  // member: generate_route
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "generate_route: ";
    rosidl_generator_traits::value_to_yaml(msg.generate_route, out);
    out << "\n";
  }

  // member: generate_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "generate_path: ";
    rosidl_generator_traits::value_to_yaml(msg.generate_path, out);
    out << "\n";
  }

  // member: use_gml_file
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_gml_file: ";
    rosidl_generator_traits::value_to_yaml(msg.use_gml_file, out);
    out << "\n";
  }

  // member: gml_field
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gml_field: ";
    rosidl_generator_traits::value_to_yaml(msg.gml_field, out);
    out << "\n";
  }

  // member: polygons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.polygons.size() == 0) {
      out << "polygons: []\n";
    } else {
      out << "polygons:\n";
      for (auto item : msg.polygons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }

  // member: headland_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "headland_mode:\n";
    to_block_style_yaml(msg.headland_mode, out, indentation + 2);
  }

  // member: swath_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "swath_mode:\n";
    to_block_style_yaml(msg.swath_mode, out, indentation + 2);
  }

  // member: row_swath_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "row_swath_mode:\n";
    to_block_style_yaml(msg.row_swath_mode, out, indentation + 2);
  }

  // member: route_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "route_mode:\n";
    to_block_style_yaml(msg.route_mode, out, indentation + 2);
  }

  // member: path_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_mode:\n";
    to_block_style_yaml(msg.path_mode, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_Goal";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_Goal";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'nav_path'
#include "nav_msgs/msg/detail/path__traits.hpp"
// Member 'coverage_path'
#include "opennav_coverage_msgs/msg/detail/path_components__traits.hpp"
// Member 'planning_time'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: nav_path
  {
    out << "nav_path: ";
    to_flow_style_yaml(msg.nav_path, out);
    out << ", ";
  }

  // member: coverage_path
  {
    out << "coverage_path: ";
    to_flow_style_yaml(msg.coverage_path, out);
    out << ", ";
  }

  // member: planning_time
  {
    out << "planning_time: ";
    to_flow_style_yaml(msg.planning_time, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: nav_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nav_path:\n";
    to_block_style_yaml(msg.nav_path, out, indentation + 2);
  }

  // member: coverage_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coverage_path:\n";
    to_block_style_yaml(msg.coverage_path, out, indentation + 2);
  }

  // member: planning_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "planning_time:\n";
    to_block_style_yaml(msg.planning_time, out, indentation + 2);
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_Result & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_Result>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_Result";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_Result>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_Result";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_Result>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Duration>::value && has_fixed_size<nav_msgs::msg::Path>::value && has_fixed_size<opennav_coverage_msgs::msg::PathComponents>::value> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_Result>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Duration>::value && has_bounded_size<nav_msgs::msg::Path>::value && has_bounded_size<opennav_coverage_msgs::msg::PathComponents>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_Feedback & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_Feedback & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_Feedback";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_Feedback";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "opennav_coverage_msgs/action/detail/compute_coverage_path__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_SendGoal_Request";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_SendGoal_Response";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
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
  const ComputeCoveragePath_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_SendGoal_Event";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>::value && has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_SendGoal";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>::value &&
    has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>::value &&
    has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_GetResult_Request";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_GetResult_Response";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_Result>::value> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_Result>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
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
  const ComputeCoveragePath_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_GetResult_Event";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>::value && has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_GetResult";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_GetResult";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>::value &&
    has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>::value &&
    has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>::value
  >
{
};

template<>
struct is_service<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__traits.hpp"

namespace opennav_coverage_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const ComputeCoveragePath_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputeCoveragePath_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputeCoveragePath_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace opennav_coverage_msgs

namespace rosidl_generator_traits
{

[[deprecated("use opennav_coverage_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  opennav_coverage_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use opennav_coverage_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage & msg)
{
  return opennav_coverage_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage>()
{
  return "opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage";
}

template<>
inline const char * name<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage>()
{
  return "opennav_coverage_msgs/action/ComputeCoveragePath_FeedbackMessage";
}

template<>
struct has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<opennav_coverage_msgs::action::ComputeCoveragePath>
  : std::true_type
{
};

template<>
struct is_action_goal<opennav_coverage_msgs::action::ComputeCoveragePath_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<opennav_coverage_msgs::action::ComputeCoveragePath_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__TRAITS_HPP_
