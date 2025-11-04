// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from opennav_coverage_msgs:msg/PathComponents.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "opennav_coverage_msgs/msg/detail/path_components__struct.h"
#include "opennav_coverage_msgs/msg/detail/path_components__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "nav_msgs/msg/detail/path__functions.h"
#include "opennav_coverage_msgs/msg/detail/swath__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool opennav_coverage_msgs__msg__swath__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * opennav_coverage_msgs__msg__swath__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool nav_msgs__msg__path__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * nav_msgs__msg__path__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool opennav_coverage_msgs__msg__path_components__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("opennav_coverage_msgs.msg._path_components.PathComponents", full_classname_dest, 57) == 0);
  }
  opennav_coverage_msgs__msg__PathComponents * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // swaths
    PyObject * field = PyObject_GetAttrString(_pymsg, "swaths");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'swaths'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!opennav_coverage_msgs__msg__Swath__Sequence__init(&(ros_message->swaths), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create opennav_coverage_msgs__msg__Swath__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    opennav_coverage_msgs__msg__Swath * dest = ros_message->swaths.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!opennav_coverage_msgs__msg__swath__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // turns
    PyObject * field = PyObject_GetAttrString(_pymsg, "turns");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'turns'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!nav_msgs__msg__Path__Sequence__init(&(ros_message->turns), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create nav_msgs__msg__Path__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    nav_msgs__msg__Path * dest = ros_message->turns.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!nav_msgs__msg__path__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // contains_turns
    PyObject * field = PyObject_GetAttrString(_pymsg, "contains_turns");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->contains_turns = (Py_True == field);
    Py_DECREF(field);
  }
  {  // swaths_ordered
    PyObject * field = PyObject_GetAttrString(_pymsg, "swaths_ordered");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->swaths_ordered = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * opennav_coverage_msgs__msg__path_components__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PathComponents */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("opennav_coverage_msgs.msg._path_components");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PathComponents");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  opennav_coverage_msgs__msg__PathComponents * ros_message = (opennav_coverage_msgs__msg__PathComponents *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // swaths
    PyObject * field = NULL;
    size_t size = ros_message->swaths.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    opennav_coverage_msgs__msg__Swath * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->swaths.data[i]);
      PyObject * pyitem = opennav_coverage_msgs__msg__swath__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "swaths", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // turns
    PyObject * field = NULL;
    size_t size = ros_message->turns.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    nav_msgs__msg__Path * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->turns.data[i]);
      PyObject * pyitem = nav_msgs__msg__path__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "turns", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // contains_turns
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->contains_turns ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "contains_turns", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // swaths_ordered
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->swaths_ordered ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "swaths_ordered", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
