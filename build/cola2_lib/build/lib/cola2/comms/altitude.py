#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2020 Iqua Robotics SL - All Rights Reserved
#
# This file is subject to the terms and conditions defined in file
# 'LICENSE.txt', which is part of this source code package.

"""
Python wrapper to C++ encode/decode altitude values to uint8.
"""

import ctypes as ct


def encode(altitude):
    """
    Encode altitude data as uint8.

    :param altitude: Altitude value.
    :type altitude: float

    :return: Altitude encoded as uint8.
    :rtype: int
    """
    libcomms = ct.cdll.LoadLibrary("/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    libcomms.altitudeEncode.restype = ct.c_uint8
    return libcomms.altitudeEncode(ct.c_double(altitude))


def is_maximum(encoded):
    """
    Check if encoded value is maximum altitude defined.

    :param encoded: Encoded altitude.
    :type encoded: int

    :return: Encoded value is maximum.
    :rtype: bool
    """
    libcomms = ct.cdll.LoadLibrary("/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    libcomms.altitudeIsMaximum.restype = ct.c_bool
    return libcomms.altitudeIsMaximum(ct.c_uint8(encoded))


def is_invalid(encoded):
    """
    Check if encoded value is invalid.

    :param encoded: Encoded altitude.
    :type encoded: int

    :return: Encoded value is invalid.
    :rtype: bool
    """
    libcomms = ct.cdll.LoadLibrary("/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    libcomms.altitudeIsInvalid.restype = ct.c_bool
    return libcomms.altitudeIsInvalid(ct.c_uint8(encoded))


def is_encoding_error(encoded):
    """
    Check if encoded value is an encoding error.

    :param encoded: Encoded altitude.
    :type encoded: int

    :return: Encoded value is an encoding error.
    :rtype: bool
    """
    libcomms = ct.cdll.LoadLibrary("/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    libcomms.altitudeIsEncodingError.restype = ct.c_bool
    return libcomms.altitudeIsEncodingError(ct.c_uint8(encoded))


def decode(encoded):
    """
    Decode altitude value from uint8.

    :param encoded: Encoded altitude value.
    :type encoded: int
    :return: Altitude value.
    :rtype: float
    """
    libcomms = ct.cdll.LoadLibrary("/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    libcomms.altitudeDecode.restype = ct.c_double
    return libcomms.altitudeDecode(ct.c_uint8(encoded))
