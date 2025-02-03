// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
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
#include "cola2_msgs/msg/detail/image_acquisition_settings__struct.h"
#include "cola2_msgs/msg/detail/image_acquisition_settings__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "cola2_msgs/msg/detail/key_value__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool cola2_msgs__msg__key_value__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * cola2_msgs__msg__key_value__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cola2_msgs__msg__image_acquisition_settings__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
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
    assert(strncmp("cola2_msgs.msg._image_acquisition_settings.ImageAcquisitionSettings", full_classname_dest, 67) == 0);
  }
  cola2_msgs__msg__ImageAcquisitionSettings * ros_message = _ros_message;
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
  {  // exposure_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "exposure_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->exposure_time = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "gain");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gain = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // blue_ratio
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_ratio");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->blue_ratio = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // red_ratio
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_ratio");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->red_ratio = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // focus
    PyObject * field = PyObject_GetAttrString(_pymsg, "focus");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->focus = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // aperture
    PyObject * field = PyObject_GetAttrString(_pymsg, "aperture");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->aperture = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // focal_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "focal_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->focal_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // extra
    PyObject * field = PyObject_GetAttrString(_pymsg, "extra");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'extra'");
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
    if (!cola2_msgs__msg__KeyValue__Sequence__init(&(ros_message->extra), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create cola2_msgs__msg__KeyValue__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    cola2_msgs__msg__KeyValue * dest = ros_message->extra.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!cola2_msgs__msg__key_value__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cola2_msgs__msg__image_acquisition_settings__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ImageAcquisitionSettings */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cola2_msgs.msg._image_acquisition_settings");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ImageAcquisitionSettings");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cola2_msgs__msg__ImageAcquisitionSettings * ros_message = (cola2_msgs__msg__ImageAcquisitionSettings *)raw_ros_message;
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
  {  // exposure_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->exposure_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "exposure_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gain
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_ratio
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->blue_ratio);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_ratio", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_ratio
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->red_ratio);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_ratio", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // focus
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->focus);
    {
      int rc = PyObject_SetAttrString(_pymessage, "focus", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aperture
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->aperture);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aperture", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // focal_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->focal_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "focal_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // extra
    PyObject * field = NULL;
    size_t size = ros_message->extra.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    cola2_msgs__msg__KeyValue * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->extra.data[i]);
      PyObject * pyitem = cola2_msgs__msg__key_value__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "extra", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
