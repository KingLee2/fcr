// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:action/NavigateCompleteCoverage.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/action/navigate_complete_coverage.h"


#ifndef OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__NAVIGATE_COMPLETE_COVERAGE__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__NAVIGATE_COMPLETE_COVERAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'field_filepath'
// Member 'frame_id'
// Member 'behavior_tree'
#include "rosidl_runtime_c/string.h"
// Member 'polygons'
#include "geometry_msgs/msg/detail/polygon__struct.h"

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal
{
  /// Define the field as either a filepath to a GML file or as a vector of polygons
  /// Whereas the first polygon is the outer field and subsequent polygons are internal voids.
  /// When both are specified, the file is used in ComputeCoveragePath BT Node.
  rosidl_runtime_c__String field_filepath;
  geometry_msgs__msg__Polygon__Sequence polygons;
  /// Specify the frame of reference of the polygon field
  rosidl_runtime_c__String frame_id;
  rosidl_runtime_c__String behavior_tree;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal__Sequence;

// Constants defined in the message

/// Constant 'NONE'.
/**
  * Error codes
  * Note: The expected priority order of the errors should match the message order
 */
enum
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__NONE = 0
};

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_Result
{
  uint16_t error_code;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_Result;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_Result.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'navigation_time'
// Member 'estimated_time_remaining'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback
{
  geometry_msgs__msg__PoseStamped current_pose;
  builtin_interfaces__msg__Duration navigation_time;
  builtin_interfaces__msg__Duration estimated_time_remaining;
  int16_t number_of_recoveries;
  float distance_remaining;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Goal goal;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Request__Sequence request;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Response__Sequence response;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response
{
  int8_t status;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Result result;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Request__Sequence request;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Response__Sequence response;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "opennav_coverage_msgs/action/detail/navigate_complete_coverage__struct.h"

/// Struct defined in action/NavigateCompleteCoverage in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  opennav_coverage_msgs__action__NavigateCompleteCoverage_Feedback feedback;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage;

// Struct for a sequence of opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage.
typedef struct opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence
{
  opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__NavigateCompleteCoverage_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__NAVIGATE_COMPLETE_COVERAGE__STRUCT_H_
