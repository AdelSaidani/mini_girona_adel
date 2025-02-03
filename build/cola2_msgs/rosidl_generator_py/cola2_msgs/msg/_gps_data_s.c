// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cola2_msgs:msg/GPSData.idl
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
#include "cola2_msgs/msg/detail/gps_data__struct.h"
#include "cola2_msgs/msg/detail/gps_data__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cola2_msgs__msg__gps_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("cola2_msgs.msg._gps_data.GPSData", full_classname_dest, 32) == 0);
  }
  cola2_msgs__msg__GPSData * ros_message = _ros_message;
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
  {  // time_utc
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_utc");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->time_utc, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // latitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "latitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->latitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // longitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "longitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->longitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fix_quality
    PyObject * field = PyObject_GetAttrString(_pymsg, "fix_quality");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fix_quality = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // number_of_satellites
    PyObject * field = PyObject_GetAttrString(_pymsg, "number_of_satellites");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->number_of_satellites = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // hdop
    PyObject * field = PyObject_GetAttrString(_pymsg, "hdop");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hdop = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // altitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "altitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->altitude = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // geoidal_separation
    PyObject * field = PyObject_GetAttrString(_pymsg, "geoidal_separation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->geoidal_separation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heading = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // latitude_stdev
    PyObject * field = PyObject_GetAttrString(_pymsg, "latitude_stdev");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->latitude_stdev = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // longitude_stdev
    PyObject * field = PyObject_GetAttrString(_pymsg, "longitude_stdev");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->longitude_stdev = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // altitude_stdev
    PyObject * field = PyObject_GetAttrString(_pymsg, "altitude_stdev");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->altitude_stdev = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_gpgga
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_gpgga");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->raw_gpgga, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // raw_gphdt
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_gphdt");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->raw_gphdt, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // raw_gpgst
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_gpgst");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->raw_gpgst, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cola2_msgs__msg__gps_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GPSData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cola2_msgs.msg._gps_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GPSData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cola2_msgs__msg__GPSData * ros_message = (cola2_msgs__msg__GPSData *)raw_ros_message;
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
  {  // time_utc
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->time_utc.data,
      strlen(ros_message->time_utc.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_utc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // latitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->latitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "latitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // longitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->longitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "longitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fix_quality
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->fix_quality);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fix_quality", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // number_of_satellites
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->number_of_satellites);
    {
      int rc = PyObject_SetAttrString(_pymessage, "number_of_satellites", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hdop
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hdop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hdop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // altitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->altitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "altitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // geoidal_separation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->geoidal_separation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "geoidal_separation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // latitude_stdev
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->latitude_stdev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "latitude_stdev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // longitude_stdev
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->longitude_stdev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "longitude_stdev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // altitude_stdev
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->altitude_stdev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "altitude_stdev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_gpgga
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->raw_gpgga.data,
      strlen(ros_message->raw_gpgga.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_gpgga", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_gphdt
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->raw_gphdt.data,
      strlen(ros_message->raw_gphdt.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_gphdt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_gpgst
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->raw_gpgst.data,
      strlen(ros_message->raw_gpgst.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_gpgst", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
