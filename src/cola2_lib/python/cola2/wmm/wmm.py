# -*- coding: utf-8 -*-
# Copyright (c) 2023 Iqua Robotics SL - All Rights Reserved
#
# This file is subject to the terms and conditions defined in file
# 'LICENSE.txt', which is part of this source code package.

"""
Module that contains functions related to the World Magnetic Model.
"""

import ctypes as ct


libwmm = None


def raise_according_to_error(error):
    """
    This function raises an Exception according to the provided error.

    :param error: Error.
    :type error: int
    """
    if error == -1:  # TODO: find a way to get this from the c code to avoid duplication
        raise Exception('WMM_LATITUDE_OUT_OF_RANGE')
    elif error == -2:
        raise Exception('WMM_LONGITUDE_OUT_OF_RANGE')
    elif error == -3:
        raise Exception('WMM_COF_DATA_NOT_FOUND')
    elif error == -4:
        raise Exception('WMM_BAD_ALLOCATION')
    elif error == -5:
        raise Exception('WMM_INVALID_DATE')
    elif error == -6:
        raise Exception('WMM_INVALID_YEAR')


def compute_magnetic_declination(latitude, longitude, year, month, day):
    """
    This function returns the magnetic declination in radians given the latitude and longitude in radians,
    and the date. Geoid height is assumed.

    :param latitude: Latitude in radians [-PI/2, PI/2].
    :type latitude: float
    :param longitude: Longitude in radians [-PI, PI].
    :type longitude: float
    :param year: Year (must match the available years of the magnetic model).
    :type year: int
    :param month: Month [1, 12].
    :type month: int
    :param day: Day (range according to month and year, first day of the month is 1).
    :type day: int

    :return: Returns the magnetic declination in radians.
    :rtype: float
    """
    global libwmm
    if libwmm is None:
        libwmm = ct.cdll.LoadLibrary('/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so')
    libwmm.computeMagneticDeclination.restype = ct.c_int
    declination = ct.c_double(0.0)
    error = libwmm.computeMagneticDeclination(ct.byref(declination),
                                              ct.c_double(latitude),
                                              ct.c_double(longitude),
                                              ct.c_int(year),
                                              ct.c_int(month),
                                              ct.c_int(day))
    raise_according_to_error(error)
    return float(declination.value)


def compute_horizontal_magnetic_field_strength(latitude, longitude, year, month, day):
    """
    This function returns the horizontal magnetic field strength in Gauss given the latitude and longitude in radians,
    and the date. Geoid height is assumed.

    :param latitude: Latitude in radians [-PI/2, PI/2].
    :type latitude: float
    :param longitude: Longitude in radians [-PI, PI].
    :type longitude: float
    :param year: Year (must match the available years of the magnetic model).
    :type year: int
    :param month: Month [1, 12].
    :type month: int
    :param day: Day (range according to month and year, first day of the month is 1).
    :type day: int

    :return: Returns the horizontal magnetic field strength in Gauss.
    :rtype: float
    """
    global libwmm
    if libwmm is None:
        libwmm = ct.cdll.LoadLibrary('/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so')
    libwmm.computeHorizontalMagneticFieldStrength.restype = ct.c_int
    horizontal_magnetic_field_strength = ct.c_double(0.0)
    error = libwmm.computeHorizontalMagneticFieldStrength(ct.byref(horizontal_magnetic_field_strength),
                                                          ct.c_double(latitude),
                                                          ct.c_double(longitude),
                                                          ct.c_int(year),
                                                          ct.c_int(month),
                                                          ct.c_int(day))
    raise_according_to_error(error)
    return float(horizontal_magnetic_field_strength.value)


def compute_vertical_magnetic_field_strength(latitude, longitude, year, month, day):
    """
    This function returns the vertical magnetic field strength in Gauss given the latitude and longitude in radians,
    and the date. Geoid height is assumed.

    :param latitude: Latitude in radians [-PI/2, PI/2].
    :type latitude: float
    :param longitude: Longitude in radians [-PI, PI].
    :type longitude: float
    :param year: Year (must match the available years of the magnetic model).
    :type year: int
    :param month: Month [1, 12].
    :type month: int
    :param day: Day (range according to month and year, first day of the month is 1).
    :type day: int

    :return: Returns the vertical magnetic field strength in Gauss.
    :rtype: float
    """
    global libwmm
    if libwmm is None:
        libwmm = ct.cdll.LoadLibrary('/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so')
    libwmm.computeVerticalMagneticFieldStrength.restype = ct.c_int
    vertical_magnetic_field_strength = ct.c_double(0.0)
    error = libwmm.computeVerticalMagneticFieldStrength(ct.byref(vertical_magnetic_field_strength),
                                                        ct.c_double(latitude),
                                                        ct.c_double(longitude),
                                                        ct.c_int(year),
                                                        ct.c_int(month),
                                                        ct.c_int(day))
    raise_according_to_error(error)
    return float(vertical_magnetic_field_strength.value)
