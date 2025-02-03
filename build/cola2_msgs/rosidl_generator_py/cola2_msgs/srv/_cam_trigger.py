# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cola2_msgs:srv/CamTrigger.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CamTrigger_Request(type):
    """Metaclass of message 'CamTrigger_Request'."""

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
                'cola2_msgs.srv.CamTrigger_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cam_trigger__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cam_trigger__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cam_trigger__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cam_trigger__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cam_trigger__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CamTrigger_Request(metaclass=Metaclass_CamTrigger_Request):
    """Message class 'CamTrigger_Request'."""

    __slots__ = [
        '_intensity1',
        '_intensity2',
        '_cam1',
        '_cam2',
    ]

    _fields_and_field_types = {
        'intensity1': 'double',
        'intensity2': 'double',
        'cam1': 'boolean',
        'cam2': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.intensity1 = kwargs.get('intensity1', float())
        self.intensity2 = kwargs.get('intensity2', float())
        self.cam1 = kwargs.get('cam1', bool())
        self.cam2 = kwargs.get('cam2', bool())

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
        if self.intensity1 != other.intensity1:
            return False
        if self.intensity2 != other.intensity2:
            return False
        if self.cam1 != other.cam1:
            return False
        if self.cam2 != other.cam2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def intensity1(self):
        """Message field 'intensity1'."""
        return self._intensity1

    @intensity1.setter
    def intensity1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'intensity1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'intensity1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._intensity1 = value

    @builtins.property
    def intensity2(self):
        """Message field 'intensity2'."""
        return self._intensity2

    @intensity2.setter
    def intensity2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'intensity2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'intensity2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._intensity2 = value

    @builtins.property
    def cam1(self):
        """Message field 'cam1'."""
        return self._cam1

    @cam1.setter
    def cam1(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cam1' field must be of type 'bool'"
        self._cam1 = value

    @builtins.property
    def cam2(self):
        """Message field 'cam2'."""
        return self._cam2

    @cam2.setter
    def cam2(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cam2' field must be of type 'bool'"
        self._cam2 = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_CamTrigger_Response(type):
    """Metaclass of message 'CamTrigger_Response'."""

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
                'cola2_msgs.srv.CamTrigger_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cam_trigger__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cam_trigger__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cam_trigger__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cam_trigger__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cam_trigger__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CamTrigger_Response(metaclass=Metaclass_CamTrigger_Response):
    """Message class 'CamTrigger_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

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
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_CamTrigger(type):
    """Metaclass of service 'CamTrigger'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cola2_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cola2_msgs.srv.CamTrigger')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__cam_trigger

            from cola2_msgs.srv import _cam_trigger
            if _cam_trigger.Metaclass_CamTrigger_Request._TYPE_SUPPORT is None:
                _cam_trigger.Metaclass_CamTrigger_Request.__import_type_support__()
            if _cam_trigger.Metaclass_CamTrigger_Response._TYPE_SUPPORT is None:
                _cam_trigger.Metaclass_CamTrigger_Response.__import_type_support__()


class CamTrigger(metaclass=Metaclass_CamTrigger):
    from cola2_msgs.srv._cam_trigger import CamTrigger_Request as Request
    from cola2_msgs.srv._cam_trigger import CamTrigger_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
