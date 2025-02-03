/*
 * Copyright (c) 2023 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

#include "cola2_lib/wmm/wmm.h"

#include <stdexcept>

#include "cola2_lib/wmmc/wmm.h"

static void throwAccordingToError(const int error)
{
  if (error == WMM_LATITUDE_OUT_OF_RANGE)
    throw std::runtime_error("WMM_LATITUDE_OUT_OF_RANGE");
  else if (error == WMM_LONGITUDE_OUT_OF_RANGE)
    throw std::runtime_error("WMM_LONGITUDE_OUT_OF_RANGE");
  else if (error == WMM_COF_DATA_NOT_FOUND)
    throw std::runtime_error("WMM_COF_DATA_NOT_FOUND");
  else if (error == WMM_BAD_ALLOCATION)
    throw std::runtime_error("WMM_BAD_ALLOCATION");
  else if (error == WMM_INVALID_DATE)
    throw std::runtime_error("WMM_INVALID_DATE");
  else if (error == WMM_INVALID_YEAR)
    throw std::runtime_error("WMM_INVALID_YEAR");
}

double computeMagneticDeclination(const double latitude, const double longitude, const int year, const int month,
                                  const int day)
{
  double declination;
  const int error = computeMagneticDeclination(&declination, latitude, longitude, year, month, day);
  throwAccordingToError(error);
  return declination;
}

double computeHorizontalMagneticFieldStrength(const double latitude, const double longitude, const int year,
                                              const int month, const int day)
{
  double horizontal_field_strength;
  const int error =
      computeHorizontalMagneticFieldStrength(&horizontal_field_strength, latitude, longitude, year, month, day);
  throwAccordingToError(error);
  return horizontal_field_strength;
}

double computeVerticalMagneticFieldStrength(const double latitude, const double longitude, const int year,
                                            const int month, const int day)
{
  double vertical_field_strength;
  const int error =
      computeVerticalMagneticFieldStrength(&vertical_field_strength, latitude, longitude, year, month, day);
  throwAccordingToError(error);
  return vertical_field_strength;
}
