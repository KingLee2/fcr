// generated from
// rosidl_typesupport_fastrtps_c/resource/rosidl_typesupport_fastrtps_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef TF2_WEB_REPUBLISHER_INTERFACES__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
#define TF2_WEB_REPUBLISHER_INTERFACES__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_tf2_web_republisher_interfaces __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tf2_web_republisher_interfaces __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_tf2_web_republisher_interfaces __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tf2_web_republisher_interfaces __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_C_BUILDING_DLL_tf2_web_republisher_interfaces
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_tf2_web_republisher_interfaces
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tf2_web_republisher_interfaces
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_tf2_web_republisher_interfaces __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tf2_web_republisher_interfaces
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tf2_web_republisher_interfaces
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // TF2_WEB_REPUBLISHER_INTERFACES__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
