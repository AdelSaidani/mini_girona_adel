// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cola2_msgs:msg/AdisImu.idl
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
#include "cola2_msgs/msg/detail/adis_imu__struct.h"
#include "cola2_msgs/msg/detail/adis_imu__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cola2_msgs__msg__adis_imu__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
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
    assert(strncmp("cola2_msgs.msg._adis_imu.AdisImu", full_classname_dest, 32) == 0);
  }
  cola2_msgs__msg__AdisImu * ros_message = _ros_message;
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
  {  // raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->raw, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // mx
    PyObject * field = PyObject_GetAttrString(_pymsg, "mx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // my
    PyObject * field = PyObject_GetAttrString(_pymsg, "my");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->my = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mz
    PyObject * field = PyObject_GetAttrString(_pymsg, "mz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gx
    PyObject * field = PyObject_GetAttrString(_pymsg, "gx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gy
    PyObject * field = PyObject_GetAttrString(_pymsg, "gy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gy = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gz
    PyObject * field = PyObject_GetAttrString(_pymsg, "gz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ax
    PyObject * field = PyObject_GetAttrString(_pymsg, "ax");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ax = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ay
    PyObject * field = PyObject_GetAttrString(_pymsg, "ay");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ay = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // az
    PyObject * field = PyObject_GetAttrString(_pymsg, "az");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->az = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // t
    PyObject * field = PyObject_GetAttrString(_pymsg, "t");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->t = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // b
    PyObject * field = PyObject_GetAttrString(_pymsg, "b");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->b = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f
    PyObject * field = PyObject_GetAttrString(_pymsg, "f");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->f, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // e
    PyObject * field = PyObject_GetAttrString(_pymsg, "e");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->e = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // w
    PyObject * field = PyObject_GetAttrString(_pymsg, "w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cola2_msgs__msg__adis_imu__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AdisImu */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cola2_msgs.msg._adis_imu");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AdisImu");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cola2_msgs__msg__AdisImu * ros_message = (cola2_msgs__msg__AdisImu *)raw_ros_message;
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
  {  // raw
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->raw.data,
      strlen(ros_message->raw.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // my
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->my);
    {
      int rc = PyObject_SetAttrString(_pymessage, "my", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ax
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ay
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ay);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ay", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // az
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->az);
    {
      int rc = PyObject_SetAttrString(_pymessage, "az", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // t
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->t);
    {
      int rc = PyObject_SetAttrString(_pymessage, "t", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // b
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->f.data,
      strlen(ros_message->f.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "f", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // e
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->e);
    {
      int rc = PyObject_SetAttrString(_pymessage, "e", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
