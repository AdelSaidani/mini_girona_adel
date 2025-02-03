// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cola2_msgs:msg/SSSConfig.idl
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
#include "cola2_msgs/msg/detail/sss_config__struct.h"
#include "cola2_msgs/msg/detail/sss_config__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cola2_msgs__msg__sss_config__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("cola2_msgs.msg._sss_config.SSSConfig", full_classname_dest, 36) == 0);
  }
  cola2_msgs__msg__SSSConfig * ros_message = _ros_message;
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
  {  // samples_per_channel
    PyObject * field = PyObject_GetAttrString(_pymsg, "samples_per_channel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->samples_per_channel = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // range_delay
    PyObject * field = PyObject_GetAttrString(_pymsg, "range_delay");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range_delay = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // range
    PyObject * field = PyObject_GetAttrString(_pymsg, "range");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // horizontal_beam_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "horizontal_beam_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->horizontal_beam_angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vertical_beam_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "vertical_beam_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vertical_beam_angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_of_sound
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_of_sound");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_of_sound = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ping_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "ping_rate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ping_rate = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // frequency
    PyObject * field = PyObject_GetAttrString(_pymsg, "frequency");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->frequency = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cola2_msgs__msg__sss_config__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SSSConfig */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cola2_msgs.msg._sss_config");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SSSConfig");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cola2_msgs__msg__SSSConfig * ros_message = (cola2_msgs__msg__SSSConfig *)raw_ros_message;
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
  {  // samples_per_channel
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->samples_per_channel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "samples_per_channel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range_delay
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range_delay);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range_delay", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // horizontal_beam_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->horizontal_beam_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "horizontal_beam_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vertical_beam_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vertical_beam_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vertical_beam_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_of_sound
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_of_sound);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_of_sound", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ping_rate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ping_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ping_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frequency
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->frequency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frequency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
