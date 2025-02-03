/*
 * Copyright (c) 2023 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @file
 * @brief This file contains C++ functions related to the World Magnetic Model.
 * @addtogroup wmm
 * @{
 */

#pragma once

/**
 * @brief This function returns the magnetic declination in radians given the latitude and longitude in radians,
 * and the date. Geoid height is assumed.
 *
 * @param latitude Latitude in radians [-PI/2, PI/2].
 * @param longitude Longitude in radians [-PI, PI].
 * @param year Year (must match the available years of the magnetic model).
 * @param month Month [1, 12].
 * @param day Day (range according to month and year, first day of the month is 1).
 * @return Returns the magnetic declination in radians.
 */
double computeMagneticDeclination(const double latitude, const double longitude, const int year, const int month,
                                  const int day);

/**
 * @brief This function returns the horizontal magnetic field strength in Gauss given the latitude and longitude in
 * radians, and the date. Geoid height is assumed.
 *
 * @param latitude Latitude in radians [-PI/2, PI/2].
 * @param longitude Longitude in radians [-PI, PI].
 * @param year Year (must match the available years of the magnetic model).
 * @param month Month [1, 12].
 * @param day Day (range according to month and year, first day of the month is 1).
 * @return Returns the horizontal magnetic field strength in Gauss.
 */
double computeHorizontalMagneticFieldStrength(const double latitude, const double longitude, const int year,
                                              const int month, const int day);

/**
 * @brief This function returns the vertical magnetic field strength in Gauss given the latitude and longitude in
 * radians, and the date. Geoid height is assumed.
 *
 * @param latitude Latitude in radians [-PI/2, PI/2].
 * @param longitude Longitude in radians [-PI, PI].
 * @param year Year (must match the available years of the magnetic model).
 * @param month Month [1, 12].
 * @param day Day (range according to month and year, first day of the month is 1).
 * @return Returns the vertical magnetic field strength in Gauss.
 */
double computeVerticalMagneticFieldStrength(const double latitude, const double longitude, const int year,
                                            const int month, const int day);

/** @} */
