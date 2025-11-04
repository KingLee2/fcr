// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from opennav_coverage_msgs:action/ComputeCoveragePath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "opennav_coverage_msgs/action/compute_coverage_path.h"


#ifndef OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__STRUCT_H_
#define OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'gml_field'
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"
// Member 'polygons'
#include "opennav_coverage_msgs/msg/detail/coordinates__struct.h"
// Member 'headland_mode'
#include "opennav_coverage_msgs/msg/detail/headland_mode__struct.h"
// Member 'swath_mode'
#include "opennav_coverage_msgs/msg/detail/swath_mode__struct.h"
// Member 'row_swath_mode'
#include "opennav_coverage_msgs/msg/detail/row_swath_mode__struct.h"
// Member 'route_mode'
#include "opennav_coverage_msgs/msg/detail/route_mode__struct.h"
// Member 'path_mode'
#include "opennav_coverage_msgs/msg/detail/path_mode__struct.h"

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_Goal
{
  /// Whether to perform all 4 stages: Headlands, Swath (Required), Route, Path
  bool generate_headland;
  bool generate_route;
  bool generate_path;
  /// The field specification to use.
  /// If using polygons, bounding polygon must be first, followed by inner cutouts
  /// Both must specify if the data is cartesian or GPS coordinates
  /// If using Row Coverage Server, must use gml field.
  bool use_gml_file;
  rosidl_runtime_c__String gml_field;
  opennav_coverage_msgs__msg__Coordinates__Sequence polygons;
  rosidl_runtime_c__String frame_id;
  /// Modes of operation of each stage, if used
  opennav_coverage_msgs__msg__HeadlandMode headland_mode;
  opennav_coverage_msgs__msg__SwathMode swath_mode;
  opennav_coverage_msgs__msg__RowSwathMode row_swath_mode;
  opennav_coverage_msgs__msg__RouteMode route_mode;
  opennav_coverage_msgs__msg__PathMode path_mode;
} opennav_coverage_msgs__action__ComputeCoveragePath_Goal;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_Goal.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_Goal__Sequence;

// Constants defined in the message

/// Constant 'NONE'.
/**
  * Error codes
  * Note: The expected priority order of the errors should match the message order
 */
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__NONE = 0
};

/// Constant 'INTERNAL_F2C_ERROR'.
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__INTERNAL_F2C_ERROR = 801
};

/// Constant 'INVALID_MODE_SET'.
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__INVALID_MODE_SET = 802
};

/// Constant 'INVALID_REQUEST'.
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__INVALID_REQUEST = 803
};

/// Constant 'INVALID_COORDS'.
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Result__INVALID_COORDS = 803
};

// Include directives for member types
// Member 'nav_path'
#include "nav_msgs/msg/detail/path__struct.h"
// Member 'coverage_path'
#include "opennav_coverage_msgs/msg/detail/path_components__struct.h"
// Member 'planning_time'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_Result
{
  nav_msgs__msg__Path nav_path;
  opennav_coverage_msgs__msg__PathComponents coverage_path;
  builtin_interfaces__msg__Duration planning_time;
  uint16_t error_code;
} opennav_coverage_msgs__action__ComputeCoveragePath_Result;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_Result.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} opennav_coverage_msgs__action__ComputeCoveragePath_Feedback;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_Feedback.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.h"

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  opennav_coverage_msgs__action__ComputeCoveragePath_Goal goal;
} opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Request__Sequence request;
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Response__Sequence response;
} opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.h"

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response
{
  int8_t status;
  opennav_coverage_msgs__action__ComputeCoveragePath_Result result;
} opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Request__Sequence request;
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Response__Sequence response;
} opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "opennav_coverage_msgs/action/detail/compute_coverage_path__struct.h"

/// Struct defined in action/ComputeCoveragePath in the package opennav_coverage_msgs.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  opennav_coverage_msgs__action__ComputeCoveragePath_Feedback feedback;
} opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage;

// Struct for a sequence of opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage.
typedef struct opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence
{
  opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} opennav_coverage_msgs__action__ComputeCoveragePath_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPENNAV_COVERAGE_MSGS__ACTION__DETAIL__COMPUTE_COVERAGE_PATH__STRUCT_H_
