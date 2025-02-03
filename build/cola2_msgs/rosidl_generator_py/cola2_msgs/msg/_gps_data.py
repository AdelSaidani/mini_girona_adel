# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cola2_msgs:msg/GPSData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GPSData(type):
    """Metaclass of message 'GPSData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cola2_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cola2_msgs.msg.GPSData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gps_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gps_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gps_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gps_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gps_data

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GPSData(metaclass=Metaclass_GPSData):
    """Message class 'GPSData'."""

    __slots__ = [
        '_header',
        '_time_utc',
        '_latitude',
        '_longitude',
        '_fix_quality',
        '_number_of_satellites',
        '_hdop',
        '_altitude',
        '_geoidal_separation',
        '_heading',
        '_latitude_stdev',
        '_longitude_stdev',
        '_altitude_stdev',
        '_raw_gpgga',
        '_raw_gphdt',
        '_raw_gpgst',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'time_utc': 'string',
        'latitude': 'double',
        'longitude': 'double',
        'fix_quality': 'int32',
        'number_of_satellites': 'int32',
        'hdop': 'float',
        'altitude': 'float',
        'geoidal_separation': 'float',
        'heading': 'float',
        'latitude_stdev': 'float',
        'longitude_stdev': 'float',
        'altitude_stdev': 'float',
        'raw_gpgga': 'string',
        'raw_gphdt': 'string',
        'raw_gpgst': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.time_utc = kwargs.get('time_utc', str())
        self.latitude = kwargs.get('latitude', float())
        self.longitude = kwargs.get('longitude', float())
        self.fix_quality = kwargs.get('fix_quality', int())
        self.number_of_satellites = kwargs.get('number_of_satellites', int())
        self.hdop = kwargs.get('hdop', float())
        self.altitude = kwargs.get('altitude', float())
        self.geoidal_separation = kwargs.get('geoidal_separation', float())
        self.heading = kwargs.get('heading', float())
        self.latitude_stdev = kwargs.get('latitude_stdev', float())
        self.longitude_stdev = kwargs.get('longitude_stdev', float())
        self.altitude_stdev = kwargs.get('altitude_stdev', float())
        self.raw_gpgga = kwargs.get('raw_gpgga', str())
        self.raw_gphdt = kwargs.get('raw_gphdt', str())
        self.raw_gpgst = kwargs.get('raw_gpgst', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.time_utc != other.time_utc:
            return False
        if self.latitude != other.latitude:
            return False
        if self.longitude != other.longitude:
            return False
        if self.fix_quality != other.fix_quality:
            return False
        if self.number_of_satellites != other.number_of_satellites:
            return False
        if self.hdop != other.hdop:
            return False
        if self.altitude != other.altitude:
            return False
        if self.geoidal_separation != other.geoidal_separation:
            return False
        if self.heading != other.heading:
            return False
        if self.latitude_stdev != other.latitude_stdev:
            return False
        if self.longitude_stdev != other.longitude_stdev:
            return False
        if self.altitude_stdev != other.altitude_stdev:
            return False
        if self.raw_gpgga != other.raw_gpgga:
            return False
        if self.raw_gphdt != other.raw_gphdt:
            return False
        if self.raw_gpgst != other.raw_gpgst:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def time_utc(self):
        """Message field 'time_utc'."""
        return self._time_utc

    @time_utc.setter
    def time_utc(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'time_utc' field must be of type 'str'"
        self._time_utc = value

    @builtins.property
    def latitude(self):
        """Message field 'latitude'."""
        return self._latitude

    @latitude.setter
    def latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'latitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._latitude = value

    @builtins.property
    def longitude(self):
        """Message field 'longitude'."""
        return self._longitude

    @longitude.setter
    def longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'longitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._longitude = value

    @builtins.property
    def fix_quality(self):
        """Message field 'fix_quality'."""
        return self._fix_quality

    @fix_quality.setter
    def fix_quality(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fix_quality' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'fix_quality' field must be an integer in [-2147483648, 2147483647]"
        self._fix_quality = value

    @builtins.property
    def number_of_satellites(self):
        """Message field 'number_of_satellites'."""
        return self._number_of_satellites

    @number_of_satellites.setter
    def number_of_satellites(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'number_of_satellites' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'number_of_satellites' field must be an integer in [-2147483648, 2147483647]"
        self._number_of_satellites = value

    @builtins.property
    def hdop(self):
        """Message field 'hdop'."""
        return self._hdop

    @hdop.setter
    def hdop(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hdop' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'hdop' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._hdop = value

    @builtins.property
    def altitude(self):
        """Message field 'altitude'."""
        return self._altitude

    @altitude.setter
    def altitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'altitude' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'altitude' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._altitude = value

    @builtins.property
    def geoidal_separation(self):
        """Message field 'geoidal_separation'."""
        return self._geoidal_separation

    @geoidal_separation.setter
    def geoidal_separation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'geoidal_separation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'geoidal_separation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._geoidal_separation = value

    @builtins.property
    def heading(self):
        """Message field 'heading'."""
        return self._heading

    @heading.setter
    def heading(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heading' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heading = value

    @builtins.property
    def latitude_stdev(self):
        """Message field 'latitude_stdev'."""
        return self._latitude_stdev

    @latitude_stdev.setter
    def latitude_stdev(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude_stdev' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'latitude_stdev' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._latitude_stdev = value

    @builtins.property
    def longitude_stdev(self):
        """Message field 'longitude_stdev'."""
        return self._longitude_stdev

    @longitude_stdev.setter
    def longitude_stdev(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude_stdev' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'longitude_stdev' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._longitude_stdev = value

    @builtins.property
    def altitude_stdev(self):
        """Message field 'altitude_stdev'."""
        return self._altitude_stdev

    @altitude_stdev.setter
    def altitude_stdev(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'altitude_stdev' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'altitude_stdev' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._altitude_stdev = value

    @builtins.property
    def raw_gpgga(self):
        """Message field 'raw_gpgga'."""
        return self._raw_gpgga

    @raw_gpgga.setter
    def raw_gpgga(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'raw_gpgga' field must be of type 'str'"
        self._raw_gpgga = value

    @builtins.property
    def raw_gphdt(self):
        """Message field 'raw_gphdt'."""
        return self._raw_gphdt

    @raw_gphdt.setter
    def raw_gphdt(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'raw_gphdt' field must be of type 'str'"
        self._raw_gphdt = value

    @builtins.property
    def raw_gpgst(self):
        """Message field 'raw_gpgst'."""
        return self._raw_gpgst

    @raw_gpgst.setter
    def raw_gpgst(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'raw_gpgst' field must be of type 'str'"
        self._raw_gpgst = value
