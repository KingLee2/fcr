// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from opennav_coverage_msgs:action/NavigateCompleteCoverage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/action/navigate_complete_coverage.hpp"


#ifndef OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__NAVIGATE_COMPLETE_COVERAGE__BUILDER_HPP_
#define OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__NAVIGATE_COMPLETE_COVERAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_Goal_behavior_tree
{
public:
  explicit Init_NavigateCompleteCoverage_Goal_behavior_tree(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal behavior_tree(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal::_behavior_tree_type arg)
  {
    msg_.behavior_tree = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal msg_;
};

class Init_NavigateCompleteCoverage_Goal_frame_id
{
public:
  explicit Init_NavigateCompleteCoverage_Goal_frame_id(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal & msg)
  : msg_(msg)
  {}
  Init_NavigateCompleteCoverage_Goal_behavior_tree frame_id(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_NavigateCompleteCoverage_Goal_behavior_tree(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal msg_;
};

class Init_NavigateCompleteCoverage_Goal_polygons
{
public:
  explicit Init_NavigateCompleteCoverage_Goal_polygons(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal & msg)
  : msg_(msg)
  {}
  Init_NavigateCompleteCoverage_Goal_frame_id polygons(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal::_polygons_type arg)
  {
    msg_.polygons = std::move(arg);
    return Init_NavigateCompleteCoverage_Goal_frame_id(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal msg_;
};

class Init_NavigateCompleteCoverage_Goal_field_filepath
{
public:
  Init_NavigateCompleteCoverage_Goal_field_filepath()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_Goal_polygons field_filepath(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal::_field_filepath_type arg)
  {
    msg_.field_filepath = std::move(arg);
    return Init_NavigateCompleteCoverage_Goal_polygons(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_Goal>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_Goal_field_filepath();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_Result_error_code
{
public:
  Init_NavigateCompleteCoverage_Result_error_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Result error_code(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Result::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_Result>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_Result_error_code();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_Feedback_distance_remaining
{
public:
  explicit Init_NavigateCompleteCoverage_Feedback_distance_remaining(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback distance_remaining(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback::_distance_remaining_type arg)
  {
    msg_.distance_remaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback msg_;
};

class Init_NavigateCompleteCoverage_Feedback_number_of_recoveries
{
public:
  explicit Init_NavigateCompleteCoverage_Feedback_number_of_recoveries(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback & msg)
  : msg_(msg)
  {}
  Init_NavigateCompleteCoverage_Feedback_distance_remaining number_of_recoveries(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback::_number_of_recoveries_type arg)
  {
    msg_.number_of_recoveries = std::move(arg);
    return Init_NavigateCompleteCoverage_Feedback_distance_remaining(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback msg_;
};

class Init_NavigateCompleteCoverage_Feedback_estimated_time_remaining
{
public:
  explicit Init_NavigateCompleteCoverage_Feedback_estimated_time_remaining(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback & msg)
  : msg_(msg)
  {}
  Init_NavigateCompleteCoverage_Feedback_number_of_recoveries estimated_time_remaining(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback::_estimated_time_remaining_type arg)
  {
    msg_.estimated_time_remaining = std::move(arg);
    return Init_NavigateCompleteCoverage_Feedback_number_of_recoveries(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback msg_;
};

class Init_NavigateCompleteCoverage_Feedback_navigation_time
{
public:
  explicit Init_NavigateCompleteCoverage_Feedback_navigation_time(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback & msg)
  : msg_(msg)
  {}
  Init_NavigateCompleteCoverage_Feedback_estimated_time_remaining navigation_time(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback::_navigation_time_type arg)
  {
    msg_.navigation_time = std::move(arg);
    return Init_NavigateCompleteCoverage_Feedback_estimated_time_remaining(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback msg_;
};

class Init_NavigateCompleteCoverage_Feedback_current_pose
{
public:
  Init_NavigateCompleteCoverage_Feedback_current_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_Feedback_navigation_time current_pose(::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_NavigateCompleteCoverage_Feedback_navigation_time(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_Feedback>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_Feedback_current_pose();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_SendGoal_Request_goal
{
public:
  explicit Init_NavigateCompleteCoverage_SendGoal_Request_goal(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Request goal(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Request msg_;
};

class Init_NavigateCompleteCoverage_SendGoal_Request_goal_id
{
public:
  Init_NavigateCompleteCoverage_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_SendGoal_Request_goal goal_id(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateCompleteCoverage_SendGoal_Request_goal(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Request>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_SendGoal_Request_goal_id();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_SendGoal_Response_stamp
{
public:
  explicit Init_NavigateCompleteCoverage_SendGoal_Response_stamp(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Response stamp(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Response msg_;
};

class Init_NavigateCompleteCoverage_SendGoal_Response_accepted
{
public:
  Init_NavigateCompleteCoverage_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_SendGoal_Response_stamp accepted(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavigateCompleteCoverage_SendGoal_Response_stamp(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Response>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_SendGoal_Response_accepted();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_SendGoal_Event_response
{
public:
  explicit Init_NavigateCompleteCoverage_SendGoal_Event_response(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event response(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event msg_;
};

class Init_NavigateCompleteCoverage_SendGoal_Event_request
{
public:
  explicit Init_NavigateCompleteCoverage_SendGoal_Event_request(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_NavigateCompleteCoverage_SendGoal_Event_response request(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigateCompleteCoverage_SendGoal_Event_response(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event msg_;
};

class Init_NavigateCompleteCoverage_SendGoal_Event_info
{
public:
  Init_NavigateCompleteCoverage_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_SendGoal_Event_request info(::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigateCompleteCoverage_SendGoal_Event_request(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_SendGoal_Event>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_SendGoal_Event_info();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_GetResult_Request_goal_id
{
public:
  Init_NavigateCompleteCoverage_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Request goal_id(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Request>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_GetResult_Request_goal_id();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_GetResult_Response_result
{
public:
  explicit Init_NavigateCompleteCoverage_GetResult_Response_result(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Response result(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Response msg_;
};

class Init_NavigateCompleteCoverage_GetResult_Response_status
{
public:
  Init_NavigateCompleteCoverage_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_GetResult_Response_result status(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavigateCompleteCoverage_GetResult_Response_result(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Response>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_GetResult_Response_status();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_GetResult_Event_response
{
public:
  explicit Init_NavigateCompleteCoverage_GetResult_Event_response(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event response(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event msg_;
};

class Init_NavigateCompleteCoverage_GetResult_Event_request
{
public:
  explicit Init_NavigateCompleteCoverage_GetResult_Event_request(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_NavigateCompleteCoverage_GetResult_Event_response request(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigateCompleteCoverage_GetResult_Event_response(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event msg_;
};

class Init_NavigateCompleteCoverage_GetResult_Event_info
{
public:
  Init_NavigateCompleteCoverage_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_GetResult_Event_request info(::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigateCompleteCoverage_GetResult_Event_request(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_GetResult_Event>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_GetResult_Event_info();
}

}  // namespace opennav_coverage_msgs


namespace opennav_coverage_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateCompleteCoverage_FeedbackMessage_feedback
{
public:
  explicit Init_NavigateCompleteCoverage_FeedbackMessage_feedback(::opennav_coverage_msgs::action::NavigateCompleteCoverage_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_FeedbackMessage feedback(::opennav_coverage_msgs::action::NavigateCompleteCoverage_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_FeedbackMessage msg_;
};

class Init_NavigateCompleteCoverage_FeedbackMessage_goal_id
{
public:
  Init_NavigateCompleteCoverage_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateCompleteCoverage_FeedbackMessage_feedback goal_id(::opennav_coverage_msgs::action::NavigateCompleteCoverage_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateCompleteCoverage_FeedbackMessage_feedback(msg_);
  }

private:
  ::opennav_coverage_msgs::action::NavigateCompleteCoverage_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::opennav_coverage_msgs::action::NavigateCompleteCoverage_FeedbackMessage>()
{
  return opennav_coverage_msgs::action::builder::Init_NavigateCompleteCoverage_FeedbackMessage_goal_id();
}

}  // namespace opennav_coverage_msgs

#endif  // OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__NAVIGATE_COMPLETE_COVERAGE__BUILDER_HPP_
