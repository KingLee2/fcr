// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:action/ComputeCoveragePath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/action/compute_coverage_path.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_Goal_path_mode
{
public:
  explicit Init_ComputeCoveragePath_Goal_path_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal path_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_path_mode_type arg)
  {
    msg_.path_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_route_mode
{
public:
  explicit Init_ComputeCoveragePath_Goal_route_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_path_mode route_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_route_mode_type arg)
  {
    msg_.route_mode = std::move(arg);
    return Init_ComputeCoveragePath_Goal_path_mode(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_row_swath_mode
{
public:
  explicit Init_ComputeCoveragePath_Goal_row_swath_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_route_mode row_swath_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_row_swath_mode_type arg)
  {
    msg_.row_swath_mode = std::move(arg);
    return Init_ComputeCoveragePath_Goal_route_mode(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_swath_mode
{
public:
  explicit Init_ComputeCoveragePath_Goal_swath_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_row_swath_mode swath_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_swath_mode_type arg)
  {
    msg_.swath_mode = std::move(arg);
    return Init_ComputeCoveragePath_Goal_row_swath_mode(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_headland_mode
{
public:
  explicit Init_ComputeCoveragePath_Goal_headland_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_swath_mode headland_mode(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_headland_mode_type arg)
  {
    msg_.headland_mode = std::move(arg);
    return Init_ComputeCoveragePath_Goal_swath_mode(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_frame_id
{
public:
  explicit Init_ComputeCoveragePath_Goal_frame_id(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_headland_mode frame_id(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_ComputeCoveragePath_Goal_headland_mode(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_polygons
{
public:
  explicit Init_ComputeCoveragePath_Goal_polygons(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_frame_id polygons(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_polygons_type arg)
  {
    msg_.polygons = std::move(arg);
    return Init_ComputeCoveragePath_Goal_frame_id(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_gml_field
{
public:
  explicit Init_ComputeCoveragePath_Goal_gml_field(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_polygons gml_field(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_gml_field_type arg)
  {
    msg_.gml_field = std::move(arg);
    return Init_ComputeCoveragePath_Goal_polygons(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_use_gml_file
{
public:
  explicit Init_ComputeCoveragePath_Goal_use_gml_file(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_gml_field use_gml_file(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_use_gml_file_type arg)
  {
    msg_.use_gml_file = std::move(arg);
    return Init_ComputeCoveragePath_Goal_gml_field(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_generate_path
{
public:
  explicit Init_ComputeCoveragePath_Goal_generate_path(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_use_gml_file generate_path(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_generate_path_type arg)
  {
    msg_.generate_path = std::move(arg);
    return Init_ComputeCoveragePath_Goal_use_gml_file(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_generate_route
{
public:
  explicit Init_ComputeCoveragePath_Goal_generate_route(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Goal_generate_path generate_route(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_generate_route_type arg)
  {
    msg_.generate_route = std::move(arg);
    return Init_ComputeCoveragePath_Goal_generate_path(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

class Init_ComputeCoveragePath_Goal_generate_headland
{
public:
  Init_ComputeCoveragePath_Goal_generate_headland()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_Goal_generate_route generate_headland(::opennav_coverage_msgs::action::ComputeCoveragePath_Goal::_generate_headland_type arg)
  {
    msg_.generate_headland = std::move(arg);
    return Init_ComputeCoveragePath_Goal_generate_route(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_Goal>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_Goal_generate_headland();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_Result_error_code
{
public:
  explicit Init_ComputeCoveragePath_Result_error_code(::opennav_coverage_msgs::action::ComputeCoveragePath_Result & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Result error_code(::opennav_coverage_msgs::action::ComputeCoveragePath_Result::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Result msg_;
};

class Init_ComputeCoveragePath_Result_planning_time
{
public:
  explicit Init_ComputeCoveragePath_Result_planning_time(::opennav_coverage_msgs::action::ComputeCoveragePath_Result & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Result_error_code planning_time(::opennav_coverage_msgs::action::ComputeCoveragePath_Result::_planning_time_type arg)
  {
    msg_.planning_time = std::move(arg);
    return Init_ComputeCoveragePath_Result_error_code(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Result msg_;
};

class Init_ComputeCoveragePath_Result_coverage_path
{
public:
  explicit Init_ComputeCoveragePath_Result_coverage_path(::opennav_coverage_msgs::action::ComputeCoveragePath_Result & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_Result_planning_time coverage_path(::opennav_coverage_msgs::action::ComputeCoveragePath_Result::_coverage_path_type arg)
  {
    msg_.coverage_path = std::move(arg);
    return Init_ComputeCoveragePath_Result_planning_time(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Result msg_;
};

class Init_ComputeCoveragePath_Result_nav_path
{
public:
  Init_ComputeCoveragePath_Result_nav_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_Result_coverage_path nav_path(::opennav_coverage_msgs::action::ComputeCoveragePath_Result::_nav_path_type arg)
  {
    msg_.nav_path = std::move(arg);
    return Init_ComputeCoveragePath_Result_coverage_path(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_Result>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_Result_nav_path();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_Feedback>()
{
  return ::opennav_coverage_msgs::action::ComputeCoveragePath_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_SendGoal_Request_goal
{
public:
  explicit Init_ComputeCoveragePath_SendGoal_Request_goal(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request goal(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request msg_;
};

class Init_ComputeCoveragePath_SendGoal_Request_goal_id
{
public:
  Init_ComputeCoveragePath_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_SendGoal_Request_goal goal_id(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ComputeCoveragePath_SendGoal_Request_goal(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Request>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_SendGoal_Request_goal_id();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_SendGoal_Response_stamp
{
public:
  explicit Init_ComputeCoveragePath_SendGoal_Response_stamp(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response stamp(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response msg_;
};

class Init_ComputeCoveragePath_SendGoal_Response_accepted
{
public:
  Init_ComputeCoveragePath_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_SendGoal_Response_stamp accepted(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ComputeCoveragePath_SendGoal_Response_stamp(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Response>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_SendGoal_Response_accepted();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_SendGoal_Event_response
{
public:
  explicit Init_ComputeCoveragePath_SendGoal_Event_response(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event response(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event msg_;
};

class Init_ComputeCoveragePath_SendGoal_Event_request
{
public:
  explicit Init_ComputeCoveragePath_SendGoal_Event_request(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_SendGoal_Event_response request(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComputeCoveragePath_SendGoal_Event_response(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event msg_;
};

class Init_ComputeCoveragePath_SendGoal_Event_info
{
public:
  Init_ComputeCoveragePath_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_SendGoal_Event_request info(::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComputeCoveragePath_SendGoal_Event_request(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_SendGoal_Event>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_SendGoal_Event_info();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_GetResult_Request_goal_id
{
public:
  Init_ComputeCoveragePath_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request goal_id(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Request>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_GetResult_Request_goal_id();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_GetResult_Response_result
{
public:
  explicit Init_ComputeCoveragePath_GetResult_Response_result(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response result(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response msg_;
};

class Init_ComputeCoveragePath_GetResult_Response_status
{
public:
  Init_ComputeCoveragePath_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_GetResult_Response_result status(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ComputeCoveragePath_GetResult_Response_result(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Response>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_GetResult_Response_status();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_GetResult_Event_response
{
public:
  explicit Init_ComputeCoveragePath_GetResult_Event_response(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event response(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event msg_;
};

class Init_ComputeCoveragePath_GetResult_Event_request
{
public:
  explicit Init_ComputeCoveragePath_GetResult_Event_request(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_ComputeCoveragePath_GetResult_Event_response request(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComputeCoveragePath_GetResult_Event_response(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event msg_;
};

class Init_ComputeCoveragePath_GetResult_Event_info
{
public:
  Init_ComputeCoveragePath_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_GetResult_Event_request info(::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComputeCoveragePath_GetResult_Event_request(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_GetResult_Event>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_GetResult_Event_info();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_ComputeCoveragePath_FeedbackMessage_feedback
{
public:
  explicit Init_ComputeCoveragePath_FeedbackMessage_feedback(::opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage feedback(::opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage msg_;
};

class Init_ComputeCoveragePath_FeedbackMessage_goal_id
{
public:
  Init_ComputeCoveragePath_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeCoveragePath_FeedbackMessage_feedback goal_id(::opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ComputeCoveragePath_FeedbackMessage_feedback(msg_);
  }

private:
  ::opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::ComputeCoveragePath_FeedbackMessage>()
{
  return opennav_coverage_msgs::action::builder::Init_ComputeCoveragePath_FeedbackMessage_goal_id();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__BUILDER_HPP_
