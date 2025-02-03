# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cola2_msgs:msg/SSSConfig.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SSSConfig(type):
    """Metaclass of message 'SSSConfig'."""

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
                'cola2_msgs.msg.SSSConfig')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sss_config
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sss_config
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sss_config
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sss_config
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sss_config

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


class SSSConfig(metaclass=Metaclass_SSSConfig):
    """Message class 'SSSConfig'."""

    __slots__ = [
        '_header',
        '_samples_per_channel',
        '_range_delay',
        '_range',
        '_horizontal_beam_angle',
        '_vertical_beam_angle',
        '_speed_of_sound',
        '_ping_rate',
        '_frequency',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'samples_per_channel': 'uint32',
        'range_delay': 'double',
        'range': 'double',
        'horizontal_beam_angle': 'double',
        'vertical_beam_angle': 'double',
        'speed_of_sound': 'double',
        'ping_rate': 'double',
        'frequency': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.samples_per_channel = kwargs.get('samples_per_channel', int())
        self.range_delay = kwargs.get('range_delay', float())
        self.range = kwargs.get('range', float())
        self.horizontal_beam_angle = kwargs.get('horizontal_beam_angle', float())
        self.vertical_beam_angle = kwargs.get('vertical_beam_angle', float())
        self.speed_of_sound = kwargs.get('speed_of_sound', float())
        self.ping_rate = kwargs.get('ping_rate', float())
        self.frequency = kwargs.get('frequency', float())

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
        if self.samples_per_channel != other.samples_per_channel:
            return False
        if self.range_delay != other.range_delay:
            return False
        if self.range != other.range:
            return False
        if self.horizontal_beam_angle != other.horizontal_beam_angle:
            return False
        if self.vertical_beam_angle != other.vertical_beam_angle:
            return False
        if self.speed_of_sound != other.speed_of_sound:
            return False
        if self.ping_rate != other.ping_rate:
            return False
        if self.frequency != other.frequency:
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
    def samples_per_channel(self):
        """Message field 'samples_per_channel'."""
        return self._samples_per_channel

    @samples_per_channel.setter
    def samples_per_channel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'samples_per_channel' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'samples_per_channel' field must be an unsigned integer in [0, 4294967295]"
        self._samples_per_channel = value

    @builtins.property
    def range_delay(self):
        """Message field 'range_delay'."""
        return self._range_delay

    @range_delay.setter
    def range_delay(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range_delay' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range_delay' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range_delay = value

    @builtins.property  # noqa: A003
    def range(self):  # noqa: A003
        """Message field 'range'."""
        return self._range

    @range.setter  # noqa: A003
    def range(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range = value

    @builtins.property
    def horizontal_beam_angle(self):
        """Message field 'horizontal_beam_angle'."""
        return self._horizontal_beam_angle

    @horizontal_beam_angle.setter
    def horizontal_beam_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'horizontal_beam_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'horizontal_beam_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._horizontal_beam_angle = value

    @builtins.property
    def vertical_beam_angle(self):
        """Message field 'vertical_beam_angle'."""
        return self._vertical_beam_angle

    @vertical_beam_angle.setter
    def vertical_beam_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vertical_beam_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vertical_beam_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vertical_beam_angle = value

    @builtins.property
    def speed_of_sound(self):
        """Message field 'speed_of_sound'."""
        return self._speed_of_sound

    @speed_of_sound.setter
    def speed_of_sound(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_of_sound' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_of_sound' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_of_sound = value

    @builtins.property
    def ping_rate(self):
        """Message field 'ping_rate'."""
        return self._ping_rate

    @ping_rate.setter
    def ping_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ping_rate' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ping_rate' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ping_rate = value

    @builtins.property
    def frequency(self):
        """Message field 'frequency'."""
        return self._frequency

    @frequency.setter
    def frequency(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'frequency' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'frequency' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._frequency = value
