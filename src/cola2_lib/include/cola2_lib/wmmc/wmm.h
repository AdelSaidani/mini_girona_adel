/*
 * Copyright (c) 2023 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @file
 * @brief This file contains C functions related to the World Magnetic Model.
 * @addtogroup wmm
 * @{
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * @brief Possible errors.
   */
  enum
  {
    WMM_OK = 0,
    WMM_LATITUDE_OUT_OF_RANGE = -1,
    WMM_LONGITUDE_OUT_OF_RANGE = -2,
    WMM_COF_DATA_NOT_FOUND = -3,
    WMM_BAD_ALLOCATION = -4,
    WMM_INVALID_DATE = -5,
    WMM_INVALID_YEAR = -6
  };

  /**
   * @brief This function returns the magnetic declination in radians given the latitude and longitude in radians,
   * and the date. Geoid height is assumed.
   *
   * @param declination Magnetic declination in radians.
   * @param latitude Latitude in radians [-PI/2, PI/2].
   * @param longitude Longitude in radians [-PI, PI].
   * @param year Year (must match the available years of the magnetic model).
   * @param month Month [1, 12].
   * @param day Day (range according to month and year, first day of the month is 1).
   * @return Returns the error code.
   */
  int computeMagneticDeclination(double *declination, const double latitude, const double longitude, const int year,
                                 const int month, const int day);

  /**
   * @brief This function returns the horizontal magnetic field strength in Gauss given the latitude and longitude in
   * radians, and the date. Geoid height is assumed.
   *
   * @param horizontal_magnetic_field_strength Horizontal magnetic field strength in Gauss.
   * @param latitude Latitude in radians [-PI/2, PI/2].
   * @param longitude Longitude in radians [-PI, PI].
   * @param year Year (must match the available years of the magnetic model).
   * @param month Month [1, 12].
   * @param day Day (range according to month and year, first day of the month is 1).
   * @return Returns the error code.
   */
  int computeHorizontalMagneticFieldStrength(double *horizontal_magnetic_field_strength, const double latitude,
                                             const double longitude, const int year, const int month, const int day);

  /**
   * @brief This function returns the vertical magnetic field strength in Gauss given the latitude and longitude in
   * radians, and the date. Geoid height is assumed.
   *
   * @param vertical_magnetic_field_strength Vertical magnetic field strength in Gauss.
   * @param latitude Latitude in radians [-PI/2, PI/2].
   * @param longitude Longitude in radians [-PI, PI].
   * @param year Year (must match the available years of the magnetic model).
   * @param month Month [1, 12].
   * @param day Day (range according to month and year, first day of the month is 1).
   * @return Returns the error code.
   */
  int computeVerticalMagneticFieldStrength(double *vertical_magnetic_field_strength, const double latitude,
                                           const double longitude, const int year, const int month, const int day);
#ifdef __cplusplus
}
#endif

/** @} */
