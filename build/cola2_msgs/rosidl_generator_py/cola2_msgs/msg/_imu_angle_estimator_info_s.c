// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
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
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__struct.h"
#include "cola2_msgs/msg/detail/imu_angle_estimator_info__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cola2_msgs__msg__imu_angle_estimator_info__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
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
    assert(strncmp("cola2_msgs.msg._imu_angle_estimator_info.ImuAngleEstimatorInfo", full_classname_dest, 62) == 0);
  }
  cola2_msgs__msg__ImuAngleEstimatorInfo * ros_message = _ros_message;
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
  {  // period
    PyObject * field = PyObject_GetAttrString(_pymsg, "period");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->period = PyFloat_AS_DOUBLE(field);
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
  {  // tilt_roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rate_tilt_roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "rate_tilt_roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rate_tilt_roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rate_tilt_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "rate_tilt_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rate_tilt_pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rate_tilt_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "rate_tilt_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rate_tilt_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_angular_velocity_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_angular_velocity_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_angular_velocity_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_angular_velocity_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_angular_velocity_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_angular_velocity_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_angular_velocity_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_angular_velocity_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_angular_velocity_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bias_roll_from_this_iteration
    PyObject * field = PyObject_GetAttrString(_pymsg, "bias_roll_from_this_iteration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bias_roll_from_this_iteration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bias_pitch_from_this_iteration
    PyObject * field = PyObject_GetAttrString(_pymsg, "bias_pitch_from_this_iteration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bias_pitch_from_this_iteration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bias_yaw_from_this_iteration
    PyObject * field = PyObject_GetAttrString(_pymsg, "bias_yaw_from_this_iteration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bias_yaw_from_this_iteration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bias_roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "bias_roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bias_roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bias_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "bias_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bias_pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bias_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "bias_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bias_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bias_buffer_size
    PyObject * field = PyObject_GetAttrString(_pymsg, "bias_buffer_size");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->bias_buffer_size = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // merging_filter_coefficient
    PyObject * field = PyObject_GetAttrString(_pymsg, "merging_filter_coefficient");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->merging_filter_coefficient = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // corrected_angular_velocity_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "corrected_angular_velocity_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->corrected_angular_velocity_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // corrected_angular_velocity_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "corrected_angular_velocity_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->corrected_angular_velocity_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // corrected_angular_velocity_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "corrected_angular_velocity_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->corrected_angular_velocity_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_integrated_roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_integrated_roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_integrated_roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_integrated_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_integrated_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_integrated_pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_integrated_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_integrated_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_integrated_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_roll_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_roll_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_roll_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_pitch_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_pitch_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_pitch_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_yaw_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_yaw_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_yaw_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_roll_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_roll_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_roll_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_pitch_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_pitch_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_pitch_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_yaw_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_yaw_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_yaw_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // roll_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_innovation
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_innovation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_innovation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // merged_roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "merged_roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->merged_roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // merged_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "merged_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->merged_pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // merged_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "merged_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->merged_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // merged_minus_tilt_roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "merged_minus_tilt_roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->merged_minus_tilt_roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // merged_minus_tilt_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "merged_minus_tilt_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->merged_minus_tilt_pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // merged_minus_tilt_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "merged_minus_tilt_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->merged_minus_tilt_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // status
    PyObject * field = PyObject_GetAttrString(_pymsg, "status");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->status, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // filter_elapsed_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "filter_elapsed_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->filter_elapsed_time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cola2_msgs__msg__imu_angle_estimator_info__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ImuAngleEstimatorInfo */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cola2_msgs.msg._imu_angle_estimator_info");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ImuAngleEstimatorInfo");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cola2_msgs__msg__ImuAngleEstimatorInfo * ros_message = (cola2_msgs__msg__ImuAngleEstimatorInfo *)raw_ros_message;
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
  {  // period
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->period);
    {
      int rc = PyObject_SetAttrString(_pymessage, "period", field);
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
  {  // tilt_roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rate_tilt_roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rate_tilt_roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rate_tilt_roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rate_tilt_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rate_tilt_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rate_tilt_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rate_tilt_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rate_tilt_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rate_tilt_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_angular_velocity_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_angular_velocity_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_angular_velocity_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_angular_velocity_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_angular_velocity_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_angular_velocity_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_angular_velocity_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_angular_velocity_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_angular_velocity_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bias_roll_from_this_iteration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bias_roll_from_this_iteration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bias_roll_from_this_iteration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bias_pitch_from_this_iteration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bias_pitch_from_this_iteration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bias_pitch_from_this_iteration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bias_yaw_from_this_iteration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bias_yaw_from_this_iteration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bias_yaw_from_this_iteration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bias_roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bias_roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bias_roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bias_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bias_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bias_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bias_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bias_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bias_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bias_buffer_size
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->bias_buffer_size);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bias_buffer_size", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // merging_filter_coefficient
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->merging_filter_coefficient);
    {
      int rc = PyObject_SetAttrString(_pymessage, "merging_filter_coefficient", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // corrected_angular_velocity_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->corrected_angular_velocity_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "corrected_angular_velocity_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // corrected_angular_velocity_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->corrected_angular_velocity_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "corrected_angular_velocity_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // corrected_angular_velocity_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->corrected_angular_velocity_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "corrected_angular_velocity_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_integrated_roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_integrated_roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_integrated_roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_integrated_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_integrated_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_integrated_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_integrated_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_integrated_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_integrated_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_roll_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_roll_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_roll_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_pitch_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_pitch_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_pitch_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_yaw_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_yaw_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_yaw_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_roll_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_roll_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_roll_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_pitch_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_pitch_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_pitch_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_yaw_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_yaw_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_yaw_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_innovation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_innovation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_innovation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // merged_roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->merged_roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "merged_roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // merged_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->merged_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "merged_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // merged_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->merged_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "merged_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // merged_minus_tilt_roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->merged_minus_tilt_roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "merged_minus_tilt_roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // merged_minus_tilt_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->merged_minus_tilt_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "merged_minus_tilt_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // merged_minus_tilt_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->merged_minus_tilt_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "merged_minus_tilt_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // status
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->status.data,
      strlen(ros_message->status.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // filter_elapsed_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->filter_elapsed_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "filter_elapsed_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
