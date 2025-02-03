# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cola2_msgs:msg/ImageAcquisitionSettings.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ImageAcquisitionSettings(type):
    """Metaclass of message 'ImageAcquisitionSettings'."""

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
                'cola2_msgs.msg.ImageAcquisitionSettings')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__image_acquisition_settings
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__image_acquisition_settings
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__image_acquisition_settings
            cls._TYPE_SUPPORT = module.type_support_msg__msg__image_acquisition_settings
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__image_acquisition_settings

            from cola2_msgs.msg import KeyValue
            if KeyValue.__class__._TYPE_SUPPORT is None:
                KeyValue.__class__.__import_type_support__()

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


class ImageAcquisitionSettings(metaclass=Metaclass_ImageAcquisitionSettings):
    """Message class 'ImageAcquisitionSettings'."""

    __slots__ = [
        '_header',
        '_exposure_time',
        '_gain',
        '_blue_ratio',
        '_red_ratio',
        '_focus',
        '_aperture',
        '_focal_length',
        '_extra',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'exposure_time': 'uint32',
        'gain': 'double',
        'blue_ratio': 'double',
        'red_ratio': 'double',
        'focus': 'double',
        'aperture': 'double',
        'focal_length': 'double',
        'extra': 'sequence<cola2_msgs/KeyValue>',
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
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['cola2_msgs', 'msg'], 'KeyValue')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.exposure_time = kwargs.get('exposure_time', int())
        self.gain = kwargs.get('gain', float())
        self.blue_ratio = kwargs.get('blue_ratio', float())
        self.red_ratio = kwargs.get('red_ratio', float())
        self.focus = kwargs.get('focus', float())
        self.aperture = kwargs.get('aperture', float())
        self.focal_length = kwargs.get('focal_length', float())
        self.extra = kwargs.get('extra', [])

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
        if self.exposure_time != other.exposure_time:
            return False
        if self.gain != other.gain:
            return False
        if self.blue_ratio != other.blue_ratio:
            return False
        if self.red_ratio != other.red_ratio:
            return False
        if self.focus != other.focus:
            return False
        if self.aperture != other.aperture:
            return False
        if self.focal_length != other.focal_length:
            return False
        if self.extra != other.extra:
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
    def exposure_time(self):
        """Message field 'exposure_time'."""
        return self._exposure_time

    @exposure_time.setter
    def exposure_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'exposure_time' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'exposure_time' field must be an unsigned integer in [0, 4294967295]"
        self._exposure_time = value

    @builtins.property
    def gain(self):
        """Message field 'gain'."""
        return self._gain

    @gain.setter
    def gain(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gain' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gain' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gain = value

    @builtins.property
    def blue_ratio(self):
        """Message field 'blue_ratio'."""
        return self._blue_ratio

    @blue_ratio.setter
    def blue_ratio(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'blue_ratio' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'blue_ratio' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._blue_ratio = value

    @builtins.property
    def red_ratio(self):
        """Message field 'red_ratio'."""
        return self._red_ratio

    @red_ratio.setter
    def red_ratio(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'red_ratio' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'red_ratio' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._red_ratio = value

    @builtins.property
    def focus(self):
        """Message field 'focus'."""
        return self._focus

    @focus.setter
    def focus(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'focus' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'focus' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._focus = value

    @builtins.property
    def aperture(self):
        """Message field 'aperture'."""
        return self._aperture

    @aperture.setter
    def aperture(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'aperture' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'aperture' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._aperture = value

    @builtins.property
    def focal_length(self):
        """Message field 'focal_length'."""
        return self._focal_length

    @focal_length.setter
    def focal_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'focal_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'focal_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._focal_length = value

    @builtins.property
    def extra(self):
        """Message field 'extra'."""
        return self._extra

    @extra.setter
    def extra(self, value):
        if __debug__:
            from cola2_msgs.msg import KeyValue
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, KeyValue) for v in value) and
                 True), \
                "The 'extra' field must be a set or sequence and each value of type 'KeyValue'"
        self._extra = value
