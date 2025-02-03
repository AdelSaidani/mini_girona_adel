// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cola2_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/gps_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `time_utc`
// Member `raw_gpgga`
// Member `raw_gphdt`
// Member `raw_gpgst`
#include "rosidl_runtime_c/string_functions.h"

bool
cola2_msgs__msg__GPSData__init(cola2_msgs__msg__GPSData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cola2_msgs__msg__GPSData__fini(msg);
    return false;
  }
  // time_utc
  if (!rosidl_runtime_c__String__init(&msg->time_utc)) {
    cola2_msgs__msg__GPSData__fini(msg);
    return false;
  }
  // latitude
  // longitude
  // fix_quality
  // number_of_satellites
  // hdop
  // altitude
  // geoidal_separation
  // heading
  // latitude_stdev
  // longitude_stdev
  // altitude_stdev
  // raw_gpgga
  if (!rosidl_runtime_c__String__init(&msg->raw_gpgga)) {
    cola2_msgs__msg__GPSData__fini(msg);
    return false;
  }
  // raw_gphdt
  if (!rosidl_runtime_c__String__init(&msg->raw_gphdt)) {
    cola2_msgs__msg__GPSData__fini(msg);
    return false;
  }
  // raw_gpgst
  if (!rosidl_runtime_c__String__init(&msg->raw_gpgst)) {
    cola2_msgs__msg__GPSData__fini(msg);
    return false;
  }
  return true;
}

void
cola2_msgs__msg__GPSData__fini(cola2_msgs__msg__GPSData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time_utc
  rosidl_runtime_c__String__fini(&msg->time_utc);
  // latitude
  // longitude
  // fix_quality
  // number_of_satellites
  // hdop
  // altitude
  // geoidal_separation
  // heading
  // latitude_stdev
  // longitude_stdev
  // altitude_stdev
  // raw_gpgga
  rosidl_runtime_c__String__fini(&msg->raw_gpgga);
  // raw_gphdt
  rosidl_runtime_c__String__fini(&msg->raw_gphdt);
  // raw_gpgst
  rosidl_runtime_c__String__fini(&msg->raw_gpgst);
}

bool
cola2_msgs__msg__GPSData__are_equal(const cola2_msgs__msg__GPSData * lhs, const cola2_msgs__msg__GPSData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // time_utc
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->time_utc), &(rhs->time_utc)))
  {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // fix_quality
  if (lhs->fix_quality != rhs->fix_quality) {
    return false;
  }
  // number_of_satellites
  if (lhs->number_of_satellites != rhs->number_of_satellites) {
    return false;
  }
  // hdop
  if (lhs->hdop != rhs->hdop) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // geoidal_separation
  if (lhs->geoidal_separation != rhs->geoidal_separation) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  // latitude_stdev
  if (lhs->latitude_stdev != rhs->latitude_stdev) {
    return false;
  }
  // longitude_stdev
  if (lhs->longitude_stdev != rhs->longitude_stdev) {
    return false;
  }
  // altitude_stdev
  if (lhs->altitude_stdev != rhs->altitude_stdev) {
    return false;
  }
  // raw_gpgga
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->raw_gpgga), &(rhs->raw_gpgga)))
  {
    return false;
  }
  // raw_gphdt
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->raw_gphdt), &(rhs->raw_gphdt)))
  {
    return false;
  }
  // raw_gpgst
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->raw_gpgst), &(rhs->raw_gpgst)))
  {
    return false;
  }
  return true;
}

bool
cola2_msgs__msg__GPSData__copy(
  const cola2_msgs__msg__GPSData * input,
  cola2_msgs__msg__GPSData * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // time_utc
  if (!rosidl_runtime_c__String__copy(
      &(input->time_utc), &(output->time_utc)))
  {
    return false;
  }
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // fix_quality
  output->fix_quality = input->fix_quality;
  // number_of_satellites
  output->number_of_satellites = input->number_of_satellites;
  // hdop
  output->hdop = input->hdop;
  // altitude
  output->altitude = input->altitude;
  // geoidal_separation
  output->geoidal_separation = input->geoidal_separation;
  // heading
  output->heading = input->heading;
  // latitude_stdev
  output->latitude_stdev = input->latitude_stdev;
  // longitude_stdev
  output->longitude_stdev = input->longitude_stdev;
  // altitude_stdev
  output->altitude_stdev = input->altitude_stdev;
  // raw_gpgga
  if (!rosidl_runtime_c__String__copy(
      &(input->raw_gpgga), &(output->raw_gpgga)))
  {
    return false;
  }
  // raw_gphdt
  if (!rosidl_runtime_c__String__copy(
      &(input->raw_gphdt), &(output->raw_gphdt)))
  {
    return false;
  }
  // raw_gpgst
  if (!rosidl_runtime_c__String__copy(
      &(input->raw_gpgst), &(output->raw_gpgst)))
  {
    return false;
  }
  return true;
}

cola2_msgs__msg__GPSData *
cola2_msgs__msg__GPSData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__GPSData * msg = (cola2_msgs__msg__GPSData *)allocator.allocate(sizeof(cola2_msgs__msg__GPSData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cola2_msgs__msg__GPSData));
  bool success = cola2_msgs__msg__GPSData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cola2_msgs__msg__GPSData__destroy(cola2_msgs__msg__GPSData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cola2_msgs__msg__GPSData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cola2_msgs__msg__GPSData__Sequence__init(cola2_msgs__msg__GPSData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__GPSData * data = NULL;

  if (size) {
    data = (cola2_msgs__msg__GPSData *)allocator.zero_allocate(size, sizeof(cola2_msgs__msg__GPSData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cola2_msgs__msg__GPSData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cola2_msgs__msg__GPSData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cola2_msgs__msg__GPSData__Sequence__fini(cola2_msgs__msg__GPSData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cola2_msgs__msg__GPSData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cola2_msgs__msg__GPSData__Sequence *
cola2_msgs__msg__GPSData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cola2_msgs__msg__GPSData__Sequence * array = (cola2_msgs__msg__GPSData__Sequence *)allocator.allocate(sizeof(cola2_msgs__msg__GPSData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cola2_msgs__msg__GPSData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cola2_msgs__msg__GPSData__Sequence__destroy(cola2_msgs__msg__GPSData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cola2_msgs__msg__GPSData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cola2_msgs__msg__GPSData__Sequence__are_equal(const cola2_msgs__msg__GPSData__Sequence * lhs, const cola2_msgs__msg__GPSData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cola2_msgs__msg__GPSData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cola2_msgs__msg__GPSData__Sequence__copy(
  const cola2_msgs__msg__GPSData__Sequence * input,
  cola2_msgs__msg__GPSData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cola2_msgs__msg__GPSData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cola2_msgs__msg__GPSData * data =
      (cola2_msgs__msg__GPSData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cola2_msgs__msg__GPSData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cola2_msgs__msg__GPSData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cola2_msgs__msg__GPSData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
