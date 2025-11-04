// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tf2_web_republisher_interfaces:srv/RepublishTFs.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tf2_web_republisher_interfaces/srv/republish_t_fs.hpp"


#ifndef TF2_WEB_REPUBLISHER_INTERFACES__SRV__DETAIL__REPUBLISH_T_FS__BUILDER_HPP_
#define TF2_WEB_REPUBLISHER_INTERFACES__SRV__DETAIL__REPUBLISH_T_FS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tf2_web_republisher_interfaces/srv/detail/republish_t_fs__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tf2_web_republisher_interfaces
{

namespace srv
{

namespace builder
{

class Init_RepublishTFs_Request_timeout
{
public:
  explicit Init_RepublishTFs_Request_timeout(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request & msg)
  : msg_(msg)
  {}
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Request timeout(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request::_timeout_type arg)
  {
    msg_.timeout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Request msg_;
};

class Init_RepublishTFs_Request_rate
{
public:
  explicit Init_RepublishTFs_Request_rate(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request & msg)
  : msg_(msg)
  {}
  Init_RepublishTFs_Request_timeout rate(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request::_rate_type arg)
  {
    msg_.rate = std::move(arg);
    return Init_RepublishTFs_Request_timeout(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Request msg_;
};

class Init_RepublishTFs_Request_trans_thres
{
public:
  explicit Init_RepublishTFs_Request_trans_thres(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request & msg)
  : msg_(msg)
  {}
  Init_RepublishTFs_Request_rate trans_thres(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request::_trans_thres_type arg)
  {
    msg_.trans_thres = std::move(arg);
    return Init_RepublishTFs_Request_rate(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Request msg_;
};

class Init_RepublishTFs_Request_angular_thres
{
public:
  explicit Init_RepublishTFs_Request_angular_thres(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request & msg)
  : msg_(msg)
  {}
  Init_RepublishTFs_Request_trans_thres angular_thres(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request::_angular_thres_type arg)
  {
    msg_.angular_thres = std::move(arg);
    return Init_RepublishTFs_Request_trans_thres(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Request msg_;
};

class Init_RepublishTFs_Request_target_frame
{
public:
  explicit Init_RepublishTFs_Request_target_frame(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request & msg)
  : msg_(msg)
  {}
  Init_RepublishTFs_Request_angular_thres target_frame(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request::_target_frame_type arg)
  {
    msg_.target_frame = std::move(arg);
    return Init_RepublishTFs_Request_angular_thres(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Request msg_;
};

class Init_RepublishTFs_Request_source_frames
{
public:
  Init_RepublishTFs_Request_source_frames()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RepublishTFs_Request_target_frame source_frames(::tf2_web_republisher_interfaces::srv::RepublishTFs_Request::_source_frames_type arg)
  {
    msg_.source_frames = std::move(arg);
    return Init_RepublishTFs_Request_target_frame(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tf2_web_republisher_interfaces::srv::RepublishTFs_Request>()
{
  return tf2_web_republisher_interfaces::srv::builder::Init_RepublishTFs_Request_source_frames();
}

}  // namespace tf2_web_republisher_interfaces


namespace tf2_web_republisher_interfaces
{

namespace srv
{

namespace builder
{

class Init_RepublishTFs_Response_topic_name
{
public:
  Init_RepublishTFs_Response_topic_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Response topic_name(::tf2_web_republisher_interfaces::srv::RepublishTFs_Response::_topic_name_type arg)
  {
    msg_.topic_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tf2_web_republisher_interfaces::srv::RepublishTFs_Response>()
{
  return tf2_web_republisher_interfaces::srv::builder::Init_RepublishTFs_Response_topic_name();
}

}  // namespace tf2_web_republisher_interfaces


namespace tf2_web_republisher_interfaces
{

namespace srv
{

namespace builder
{

class Init_RepublishTFs_Event_response
{
public:
  explicit Init_RepublishTFs_Event_response(::tf2_web_republisher_interfaces::srv::RepublishTFs_Event & msg)
  : msg_(msg)
  {}
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Event response(::tf2_web_republisher_interfaces::srv::RepublishTFs_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Event msg_;
};

class Init_RepublishTFs_Event_request
{
public:
  explicit Init_RepublishTFs_Event_request(::tf2_web_republisher_interfaces::srv::RepublishTFs_Event & msg)
  : msg_(msg)
  {}
  Init_RepublishTFs_Event_response request(::tf2_web_republisher_interfaces::srv::RepublishTFs_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RepublishTFs_Event_response(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Event msg_;
};

class Init_RepublishTFs_Event_info
{
public:
  Init_RepublishTFs_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RepublishTFs_Event_request info(::tf2_web_republisher_interfaces::srv::RepublishTFs_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RepublishTFs_Event_request(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::srv::RepublishTFs_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tf2_web_republisher_interfaces::srv::RepublishTFs_Event>()
{
  return tf2_web_republisher_interfaces::srv::builder::Init_RepublishTFs_Event_info();
}

}  // namespace tf2_web_republisher_interfaces

#endif  // TF2_WEB_REPUBLISHER_INTERFACES__SRV__DETAIL__REPUBLISH_T_FS__BUILDER_HPP_
