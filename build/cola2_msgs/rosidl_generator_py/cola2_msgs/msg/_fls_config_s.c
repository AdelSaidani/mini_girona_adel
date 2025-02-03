// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cola2_msgs:msg/FlsConfig.idl
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
#include "cola2_msgs/msg/detail/fls_config__struct.h"
#include "cola2_msgs/msg/detail/fls_config__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cola2_msgs__msg__fls_config__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("cola2_msgs.msg._fls_config.FlsConfig", full_classname_dest, 36) == 0);
  }
  cola2_msgs__msg__FlsConfig * ros_message = _ros_message;
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
  {  // num_beams
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_beams");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_beams = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // num_samples
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_samples");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_samples = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // window_start
    PyObject * field = PyObject_GetAttrString(_pymsg, "window_start");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->window_start = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // window_end
    PyObject * field = PyObject_GetAttrString(_pymsg, "window_end");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->window_end = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // beams_bearings
    PyObject * field = PyObject_GetAttrString(_pymsg, "beams_bearings");
    if (!field) {
      return false;
    }
    if (PyObject_CheckBuffer(field)) {
      // Optimization for converting arrays of primitives
      Py_buffer view;
      int rc = PyObject_GetBuffer(field, &view, PyBUF_SIMPLE);
      if (rc < 0) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = view.len / sizeof(float);
      if (!rosidl_runtime_c__float__Sequence__init(&(ros_message->beams_bearings), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create float__Sequence ros_message");
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      float * dest = ros_message->beams_bearings.data;
      rc = PyBuffer_ToContiguous(dest, &view, view.len, 'C');
      if (rc < 0) {
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      PyBuffer_Release(&view);
    } else {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'beams_bearings'");
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
      if (!rosidl_runtime_c__float__Sequence__init(&(ros_message->beams_bearings), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create float__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      float * dest = ros_message->beams_bearings.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyFloat_Check(item));
        float tmp = (float)PyFloat_AS_DOUBLE(item);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
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
PyObject * cola2_msgs__msg__fls_config__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FlsConfig */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cola2_msgs.msg._fls_config");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FlsConfig");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cola2_msgs__msg__FlsConfig * ros_message = (cola2_msgs__msg__FlsConfig *)raw_ros_message;
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
  {  // num_beams
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_beams);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_beams", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_samples
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_samples);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_samples", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // window_start
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->window_start);
    {
      int rc = PyObject_SetAttrString(_pymessage, "window_start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // window_end
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->window_end);
    {
      int rc = PyObject_SetAttrString(_pymessage, "window_end", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // beams_bearings
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "beams_bearings");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "array.array") == 0);
    // ensure that itemsize matches the sizeof of the ROS message field
    PyObject * itemsize_attr = PyObject_GetAttrString(field, "itemsize");
    assert(itemsize_attr != NULL);
    size_t itemsize = PyLong_AsSize_t(itemsize_attr);
    Py_DECREF(itemsize_attr);
    if (itemsize != sizeof(float)) {
      PyErr_SetString(PyExc_RuntimeError, "itemsize doesn't match expectation");
      Py_DECREF(field);
      return NULL;
    }
    // clear the array, poor approach to remove potential default values
    Py_ssize_t length = PyObject_Length(field);
    if (-1 == length) {
      Py_DECREF(field);
      return NULL;
    }
    if (length > 0) {
      PyObject * pop = PyObject_GetAttrString(field, "pop");
      assert(pop != NULL);
      for (Py_ssize_t i = 0; i < length; ++i) {
        PyObject * ret = PyObject_CallFunctionObjArgs(pop, NULL);
        if (!ret) {
          Py_DECREF(pop);
          Py_DECREF(field);
          return NULL;
        }
        Py_DECREF(ret);
      }
      Py_DECREF(pop);
    }
    if (ros_message->beams_bearings.size > 0) {
      // populating the array.array using the frombytes method
      PyObject * frombytes = PyObject_GetAttrString(field, "frombytes");
      assert(frombytes != NULL);
      float * src = &(ros_message->beams_bearings.data[0]);
      PyObject * data = PyBytes_FromStringAndSize((const char *)src, ros_message->beams_bearings.size * sizeof(float));
      assert(data != NULL);
      PyObject * ret = PyObject_CallFunctionObjArgs(frombytes, data, NULL);
      Py_DECREF(data);
      Py_DECREF(frombytes);
      if (!ret) {
        Py_DECREF(field);
        return NULL;
      }
      Py_DECREF(ret);
    }
    Py_DECREF(field);
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
