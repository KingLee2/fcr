// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tf2_web_republisher_interfaces:msg/TFArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tf2_web_republisher_interfaces/msg/tf_array.hpp"


#ifndef TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__BUILDER_HPP_
#define TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tf2_web_republisher_interfaces/msg/detail/tf_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tf2_web_republisher_interfaces
{

namespace msg
{

namespace builder
{

class Init_TFArray_transforms
{
public:
  Init_TFArray_transforms()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tf2_web_republisher_interfaces::msg::TFArray transforms(::tf2_web_republisher_interfaces::msg::TFArray::_transforms_type arg)
  {
    msg_.transforms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tf2_web_republisher_interfaces::msg::TFArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tf2_web_republisher_interfaces::msg::TFArray>()
{
  return tf2_web_republisher_interfaces::msg::builder::Init_TFArray_transforms();
}

}  // namespace tf2_web_republisher_interfaces

#endif  // TF2_WEB_REPUBLISHER_INTERFACES__MSG__DETAIL__TF_ARRAY__BUILDER_HPP_
