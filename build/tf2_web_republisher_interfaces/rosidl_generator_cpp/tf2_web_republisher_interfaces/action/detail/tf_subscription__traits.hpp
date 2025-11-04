// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tf2_web_republisher_interfaces:action/TFSubscription.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tf2_web_republisher_interfaces/action/tf_subscription.hpp"


#ifndef TF2_WEB_REPUBLISHER_INTERFACES__ACTION__DETAIL__TF_SUBSCRIPTION__TRAITS_HPP_
#define TF2_WEB_REPUBLISHER_INTERFACES__ACTION__DETAIL__TF_SUBSCRIPTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tf2_web_republisher_interfaces/action/detail/tf_subscription__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: source_frames
  {
    if (msg.source_frames.size() == 0) {
      out << "source_frames: []";
    } else {
      out << "source_frames: [";
      size_t pending_items = msg.source_frames.size();
      for (auto item : msg.source_frames) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: target_frame
  {
    out << "target_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.target_frame, out);
    out << ", ";
  }

  // member: angular_thres
  {
    out << "angular_thres: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_thres, out);
    out << ", ";
  }

  // member: trans_thres
  {
    out << "trans_thres: ";
    rosidl_generator_traits::value_to_yaml(msg.trans_thres, out);
    out << ", ";
  }

  // member: rate
  {
    out << "rate: ";
    rosidl_generator_traits::value_to_yaml(msg.rate, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TFSubscription_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: source_frames
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.source_frames.size() == 0) {
      out << "source_frames: []\n";
    } else {
      out << "source_frames:\n";
      for (auto item : msg.source_frames) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: target_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.target_frame, out);
    out << "\n";
  }

  // member: angular_thres
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_thres: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_thres, out);
    out << "\n";
  }

  // member: trans_thres
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trans_thres: ";
    rosidl_generator_traits::value_to_yaml(msg.trans_thres, out);
    out << "\n";
  }

  // member: rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rate: ";
    rosidl_generator_traits::value_to_yaml(msg.rate, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TFSubscription_Goal & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_Goal & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_Goal>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_Goal";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_Goal>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_Goal";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_Result & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TFSubscription_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TFSubscription_Result & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_Result & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_Result>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_Result";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_Result>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_Result";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'transforms'
#include "geometry_msgs/msg/detail/transform_stamped__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_Feedback & msg,
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
  const TFSubscription_Feedback & msg,
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

inline std::string to_yaml(const TFSubscription_Feedback & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_Feedback & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_Feedback";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_Feedback";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "tf2_web_republisher_interfaces/action/detail/tf_subscription__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_SendGoal_Request & msg,
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
  const TFSubscription_SendGoal_Request & msg,
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

inline std::string to_yaml(const TFSubscription_SendGoal_Request & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_SendGoal_Request";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_SendGoal_Response & msg,
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
  const TFSubscription_SendGoal_Response & msg,
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

inline std::string to_yaml(const TFSubscription_SendGoal_Response & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_SendGoal_Response";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_SendGoal_Event & msg,
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
  const TFSubscription_SendGoal_Event & msg,
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

inline std::string to_yaml(const TFSubscription_SendGoal_Event & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_SendGoal_Event";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>::value && has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>::value> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_SendGoal";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_SendGoal";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>::value &&
    has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>::value &&
    has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tf2_web_republisher_interfaces::action::TFSubscription_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_GetResult_Request & msg,
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
  const TFSubscription_GetResult_Request & msg,
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

inline std::string to_yaml(const TFSubscription_GetResult_Request & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_GetResult_Request";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "tf2_web_republisher_interfaces/action/detail/tf_subscription__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_GetResult_Response & msg,
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
  const TFSubscription_GetResult_Response & msg,
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

inline std::string to_yaml(const TFSubscription_GetResult_Response & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_GetResult_Response";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_Result>::value> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_Result>::value> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_GetResult_Event & msg,
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
  const TFSubscription_GetResult_Event & msg,
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

inline std::string to_yaml(const TFSubscription_GetResult_Event & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_GetResult_Event";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>::value && has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>::value> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_GetResult>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_GetResult";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_GetResult>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_GetResult";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>::value &&
    has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>::value &&
    has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>::value
  >
{
};

template<>
struct is_service<tf2_web_republisher_interfaces::action::TFSubscription_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tf2_web_republisher_interfaces::action::TFSubscription_GetResult_Response>
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
// #include "tf2_web_republisher_interfaces/action/detail/tf_subscription__traits.hpp"

namespace tf2_web_republisher_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const TFSubscription_FeedbackMessage & msg,
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
  const TFSubscription_FeedbackMessage & msg,
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

inline std::string to_yaml(const TFSubscription_FeedbackMessage & msg, bool use_flow_style = false)
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

}  // namespace tf2_web_republisher_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tf2_web_republisher_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  tf2_web_republisher_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tf2_web_republisher_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage & msg)
{
  return tf2_web_republisher_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage>()
{
  return "tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage";
}

template<>
inline const char * name<tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage>()
{
  return "tf2_web_republisher_interfaces/action/TFSubscription_FeedbackMessage";
}

template<>
struct has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<tf2_web_republisher_interfaces::action::TFSubscription_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<tf2_web_republisher_interfaces::action::TFSubscription>
  : std::true_type
{
};

template<>
struct is_action_goal<tf2_web_republisher_interfaces::action::TFSubscription_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<tf2_web_republisher_interfaces::action::TFSubscription_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<tf2_web_republisher_interfaces::action::TFSubscription_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TF2_WEB_REPUBLISHER_INTERFACES__ACTION__DETAIL__TF_SUBSCRIPTION__TRAITS_HPP_
