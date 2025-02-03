# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cola2_msgs:msg/ImuAngleEstimatorInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ImuAngleEstimatorInfo(type):
    """Metaclass of message 'ImuAngleEstimatorInfo'."""

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
                'cola2_msgs.msg.ImuAngleEstimatorInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__imu_angle_estimator_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__imu_angle_estimator_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__imu_angle_estimator_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__imu_angle_estimator_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__imu_angle_estimator_info

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


class ImuAngleEstimatorInfo(metaclass=Metaclass_ImuAngleEstimatorInfo):
    """Message class 'ImuAngleEstimatorInfo'."""

    __slots__ = [
        '_header',
        '_period',
        '_ax',
        '_ay',
        '_az',
        '_mx',
        '_my',
        '_mz',
        '_gx',
        '_gy',
        '_gz',
        '_tilt_roll',
        '_tilt_pitch',
        '_tilt_yaw',
        '_rate_tilt_roll',
        '_rate_tilt_pitch',
        '_rate_tilt_yaw',
        '_tilt_angular_velocity_x',
        '_tilt_angular_velocity_y',
        '_tilt_angular_velocity_z',
        '_bias_roll_from_this_iteration',
        '_bias_pitch_from_this_iteration',
        '_bias_yaw_from_this_iteration',
        '_bias_roll',
        '_bias_pitch',
        '_bias_yaw',
        '_bias_buffer_size',
        '_merging_filter_coefficient',
        '_corrected_angular_velocity_x',
        '_corrected_angular_velocity_y',
        '_corrected_angular_velocity_z',
        '_gyro_integrated_roll',
        '_gyro_integrated_pitch',
        '_gyro_integrated_yaw',
        '_gyro_roll_innovation',
        '_gyro_pitch_innovation',
        '_gyro_yaw_innovation',
        '_tilt_roll_innovation',
        '_tilt_pitch_innovation',
        '_tilt_yaw_innovation',
        '_roll_innovation',
        '_pitch_innovation',
        '_yaw_innovation',
        '_merged_roll',
        '_merged_pitch',
        '_merged_yaw',
        '_merged_minus_tilt_roll',
        '_merged_minus_tilt_pitch',
        '_merged_minus_tilt_yaw',
        '_status',
        '_filter_elapsed_time',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'period': 'double',
        'ax': 'double',
        'ay': 'double',
        'az': 'double',
        'mx': 'double',
        'my': 'double',
        'mz': 'double',
        'gx': 'double',
        'gy': 'double',
        'gz': 'double',
        'tilt_roll': 'double',
        'tilt_pitch': 'double',
        'tilt_yaw': 'double',
        'rate_tilt_roll': 'double',
        'rate_tilt_pitch': 'double',
        'rate_tilt_yaw': 'double',
        'tilt_angular_velocity_x': 'double',
        'tilt_angular_velocity_y': 'double',
        'tilt_angular_velocity_z': 'double',
        'bias_roll_from_this_iteration': 'double',
        'bias_pitch_from_this_iteration': 'double',
        'bias_yaw_from_this_iteration': 'double',
        'bias_roll': 'double',
        'bias_pitch': 'double',
        'bias_yaw': 'double',
        'bias_buffer_size': 'int32',
        'merging_filter_coefficient': 'double',
        'corrected_angular_velocity_x': 'double',
        'corrected_angular_velocity_y': 'double',
        'corrected_angular_velocity_z': 'double',
        'gyro_integrated_roll': 'double',
        'gyro_integrated_pitch': 'double',
        'gyro_integrated_yaw': 'double',
        'gyro_roll_innovation': 'double',
        'gyro_pitch_innovation': 'double',
        'gyro_yaw_innovation': 'double',
        'tilt_roll_innovation': 'double',
        'tilt_pitch_innovation': 'double',
        'tilt_yaw_innovation': 'double',
        'roll_innovation': 'double',
        'pitch_innovation': 'double',
        'yaw_innovation': 'double',
        'merged_roll': 'double',
        'merged_pitch': 'double',
        'merged_yaw': 'double',
        'merged_minus_tilt_roll': 'double',
        'merged_minus_tilt_pitch': 'double',
        'merged_minus_tilt_yaw': 'double',
        'status': 'string',
        'filter_elapsed_time': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.period = kwargs.get('period', float())
        self.ax = kwargs.get('ax', float())
        self.ay = kwargs.get('ay', float())
        self.az = kwargs.get('az', float())
        self.mx = kwargs.get('mx', float())
        self.my = kwargs.get('my', float())
        self.mz = kwargs.get('mz', float())
        self.gx = kwargs.get('gx', float())
        self.gy = kwargs.get('gy', float())
        self.gz = kwargs.get('gz', float())
        self.tilt_roll = kwargs.get('tilt_roll', float())
        self.tilt_pitch = kwargs.get('tilt_pitch', float())
        self.tilt_yaw = kwargs.get('tilt_yaw', float())
        self.rate_tilt_roll = kwargs.get('rate_tilt_roll', float())
        self.rate_tilt_pitch = kwargs.get('rate_tilt_pitch', float())
        self.rate_tilt_yaw = kwargs.get('rate_tilt_yaw', float())
        self.tilt_angular_velocity_x = kwargs.get('tilt_angular_velocity_x', float())
        self.tilt_angular_velocity_y = kwargs.get('tilt_angular_velocity_y', float())
        self.tilt_angular_velocity_z = kwargs.get('tilt_angular_velocity_z', float())
        self.bias_roll_from_this_iteration = kwargs.get('bias_roll_from_this_iteration', float())
        self.bias_pitch_from_this_iteration = kwargs.get('bias_pitch_from_this_iteration', float())
        self.bias_yaw_from_this_iteration = kwargs.get('bias_yaw_from_this_iteration', float())
        self.bias_roll = kwargs.get('bias_roll', float())
        self.bias_pitch = kwargs.get('bias_pitch', float())
        self.bias_yaw = kwargs.get('bias_yaw', float())
        self.bias_buffer_size = kwargs.get('bias_buffer_size', int())
        self.merging_filter_coefficient = kwargs.get('merging_filter_coefficient', float())
        self.corrected_angular_velocity_x = kwargs.get('corrected_angular_velocity_x', float())
        self.corrected_angular_velocity_y = kwargs.get('corrected_angular_velocity_y', float())
        self.corrected_angular_velocity_z = kwargs.get('corrected_angular_velocity_z', float())
        self.gyro_integrated_roll = kwargs.get('gyro_integrated_roll', float())
        self.gyro_integrated_pitch = kwargs.get('gyro_integrated_pitch', float())
        self.gyro_integrated_yaw = kwargs.get('gyro_integrated_yaw', float())
        self.gyro_roll_innovation = kwargs.get('gyro_roll_innovation', float())
        self.gyro_pitch_innovation = kwargs.get('gyro_pitch_innovation', float())
        self.gyro_yaw_innovation = kwargs.get('gyro_yaw_innovation', float())
        self.tilt_roll_innovation = kwargs.get('tilt_roll_innovation', float())
        self.tilt_pitch_innovation = kwargs.get('tilt_pitch_innovation', float())
        self.tilt_yaw_innovation = kwargs.get('tilt_yaw_innovation', float())
        self.roll_innovation = kwargs.get('roll_innovation', float())
        self.pitch_innovation = kwargs.get('pitch_innovation', float())
        self.yaw_innovation = kwargs.get('yaw_innovation', float())
        self.merged_roll = kwargs.get('merged_roll', float())
        self.merged_pitch = kwargs.get('merged_pitch', float())
        self.merged_yaw = kwargs.get('merged_yaw', float())
        self.merged_minus_tilt_roll = kwargs.get('merged_minus_tilt_roll', float())
        self.merged_minus_tilt_pitch = kwargs.get('merged_minus_tilt_pitch', float())
        self.merged_minus_tilt_yaw = kwargs.get('merged_minus_tilt_yaw', float())
        self.status = kwargs.get('status', str())
        self.filter_elapsed_time = kwargs.get('filter_elapsed_time', float())

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
        if self.period != other.period:
            return False
        if self.ax != other.ax:
            return False
        if self.ay != other.ay:
            return False
        if self.az != other.az:
            return False
        if self.mx != other.mx:
            return False
        if self.my != other.my:
            return False
        if self.mz != other.mz:
            return False
        if self.gx != other.gx:
            return False
        if self.gy != other.gy:
            return False
        if self.gz != other.gz:
            return False
        if self.tilt_roll != other.tilt_roll:
            return False
        if self.tilt_pitch != other.tilt_pitch:
            return False
        if self.tilt_yaw != other.tilt_yaw:
            return False
        if self.rate_tilt_roll != other.rate_tilt_roll:
            return False
        if self.rate_tilt_pitch != other.rate_tilt_pitch:
            return False
        if self.rate_tilt_yaw != other.rate_tilt_yaw:
            return False
        if self.tilt_angular_velocity_x != other.tilt_angular_velocity_x:
            return False
        if self.tilt_angular_velocity_y != other.tilt_angular_velocity_y:
            return False
        if self.tilt_angular_velocity_z != other.tilt_angular_velocity_z:
            return False
        if self.bias_roll_from_this_iteration != other.bias_roll_from_this_iteration:
            return False
        if self.bias_pitch_from_this_iteration != other.bias_pitch_from_this_iteration:
            return False
        if self.bias_yaw_from_this_iteration != other.bias_yaw_from_this_iteration:
            return False
        if self.bias_roll != other.bias_roll:
            return False
        if self.bias_pitch != other.bias_pitch:
            return False
        if self.bias_yaw != other.bias_yaw:
            return False
        if self.bias_buffer_size != other.bias_buffer_size:
            return False
        if self.merging_filter_coefficient != other.merging_filter_coefficient:
            return False
        if self.corrected_angular_velocity_x != other.corrected_angular_velocity_x:
            return False
        if self.corrected_angular_velocity_y != other.corrected_angular_velocity_y:
            return False
        if self.corrected_angular_velocity_z != other.corrected_angular_velocity_z:
            return False
        if self.gyro_integrated_roll != other.gyro_integrated_roll:
            return False
        if self.gyro_integrated_pitch != other.gyro_integrated_pitch:
            return False
        if self.gyro_integrated_yaw != other.gyro_integrated_yaw:
            return False
        if self.gyro_roll_innovation != other.gyro_roll_innovation:
            return False
        if self.gyro_pitch_innovation != other.gyro_pitch_innovation:
            return False
        if self.gyro_yaw_innovation != other.gyro_yaw_innovation:
            return False
        if self.tilt_roll_innovation != other.tilt_roll_innovation:
            return False
        if self.tilt_pitch_innovation != other.tilt_pitch_innovation:
            return False
        if self.tilt_yaw_innovation != other.tilt_yaw_innovation:
            return False
        if self.roll_innovation != other.roll_innovation:
            return False
        if self.pitch_innovation != other.pitch_innovation:
            return False
        if self.yaw_innovation != other.yaw_innovation:
            return False
        if self.merged_roll != other.merged_roll:
            return False
        if self.merged_pitch != other.merged_pitch:
            return False
        if self.merged_yaw != other.merged_yaw:
            return False
        if self.merged_minus_tilt_roll != other.merged_minus_tilt_roll:
            return False
        if self.merged_minus_tilt_pitch != other.merged_minus_tilt_pitch:
            return False
        if self.merged_minus_tilt_yaw != other.merged_minus_tilt_yaw:
            return False
        if self.status != other.status:
            return False
        if self.filter_elapsed_time != other.filter_elapsed_time:
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
    def period(self):
        """Message field 'period'."""
        return self._period

    @period.setter
    def period(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'period' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'period' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._period = value

    @builtins.property
    def ax(self):
        """Message field 'ax'."""
        return self._ax

    @ax.setter
    def ax(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ax' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ax' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ax = value

    @builtins.property
    def ay(self):
        """Message field 'ay'."""
        return self._ay

    @ay.setter
    def ay(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ay' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ay' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ay = value

    @builtins.property
    def az(self):
        """Message field 'az'."""
        return self._az

    @az.setter
    def az(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'az' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'az' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._az = value

    @builtins.property
    def mx(self):
        """Message field 'mx'."""
        return self._mx

    @mx.setter
    def mx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mx' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mx' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mx = value

    @builtins.property
    def my(self):
        """Message field 'my'."""
        return self._my

    @my.setter
    def my(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'my' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'my' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._my = value

    @builtins.property
    def mz(self):
        """Message field 'mz'."""
        return self._mz

    @mz.setter
    def mz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mz' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mz' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mz = value

    @builtins.property
    def gx(self):
        """Message field 'gx'."""
        return self._gx

    @gx.setter
    def gx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gx' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gx' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gx = value

    @builtins.property
    def gy(self):
        """Message field 'gy'."""
        return self._gy

    @gy.setter
    def gy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gy' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gy' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gy = value

    @builtins.property
    def gz(self):
        """Message field 'gz'."""
        return self._gz

    @gz.setter
    def gz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gz' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gz' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gz = value

    @builtins.property
    def tilt_roll(self):
        """Message field 'tilt_roll'."""
        return self._tilt_roll

    @tilt_roll.setter
    def tilt_roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_roll' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_roll' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_roll = value

    @builtins.property
    def tilt_pitch(self):
        """Message field 'tilt_pitch'."""
        return self._tilt_pitch

    @tilt_pitch.setter
    def tilt_pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_pitch' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_pitch' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_pitch = value

    @builtins.property
    def tilt_yaw(self):
        """Message field 'tilt_yaw'."""
        return self._tilt_yaw

    @tilt_yaw.setter
    def tilt_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_yaw = value

    @builtins.property
    def rate_tilt_roll(self):
        """Message field 'rate_tilt_roll'."""
        return self._rate_tilt_roll

    @rate_tilt_roll.setter
    def rate_tilt_roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rate_tilt_roll' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rate_tilt_roll' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rate_tilt_roll = value

    @builtins.property
    def rate_tilt_pitch(self):
        """Message field 'rate_tilt_pitch'."""
        return self._rate_tilt_pitch

    @rate_tilt_pitch.setter
    def rate_tilt_pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rate_tilt_pitch' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rate_tilt_pitch' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rate_tilt_pitch = value

    @builtins.property
    def rate_tilt_yaw(self):
        """Message field 'rate_tilt_yaw'."""
        return self._rate_tilt_yaw

    @rate_tilt_yaw.setter
    def rate_tilt_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rate_tilt_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rate_tilt_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rate_tilt_yaw = value

    @builtins.property
    def tilt_angular_velocity_x(self):
        """Message field 'tilt_angular_velocity_x'."""
        return self._tilt_angular_velocity_x

    @tilt_angular_velocity_x.setter
    def tilt_angular_velocity_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_angular_velocity_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_angular_velocity_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_angular_velocity_x = value

    @builtins.property
    def tilt_angular_velocity_y(self):
        """Message field 'tilt_angular_velocity_y'."""
        return self._tilt_angular_velocity_y

    @tilt_angular_velocity_y.setter
    def tilt_angular_velocity_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_angular_velocity_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_angular_velocity_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_angular_velocity_y = value

    @builtins.property
    def tilt_angular_velocity_z(self):
        """Message field 'tilt_angular_velocity_z'."""
        return self._tilt_angular_velocity_z

    @tilt_angular_velocity_z.setter
    def tilt_angular_velocity_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_angular_velocity_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_angular_velocity_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_angular_velocity_z = value

    @builtins.property
    def bias_roll_from_this_iteration(self):
        """Message field 'bias_roll_from_this_iteration'."""
        return self._bias_roll_from_this_iteration

    @bias_roll_from_this_iteration.setter
    def bias_roll_from_this_iteration(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bias_roll_from_this_iteration' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bias_roll_from_this_iteration' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bias_roll_from_this_iteration = value

    @builtins.property
    def bias_pitch_from_this_iteration(self):
        """Message field 'bias_pitch_from_this_iteration'."""
        return self._bias_pitch_from_this_iteration

    @bias_pitch_from_this_iteration.setter
    def bias_pitch_from_this_iteration(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bias_pitch_from_this_iteration' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bias_pitch_from_this_iteration' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bias_pitch_from_this_iteration = value

    @builtins.property
    def bias_yaw_from_this_iteration(self):
        """Message field 'bias_yaw_from_this_iteration'."""
        return self._bias_yaw_from_this_iteration

    @bias_yaw_from_this_iteration.setter
    def bias_yaw_from_this_iteration(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bias_yaw_from_this_iteration' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bias_yaw_from_this_iteration' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bias_yaw_from_this_iteration = value

    @builtins.property
    def bias_roll(self):
        """Message field 'bias_roll'."""
        return self._bias_roll

    @bias_roll.setter
    def bias_roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bias_roll' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bias_roll' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bias_roll = value

    @builtins.property
    def bias_pitch(self):
        """Message field 'bias_pitch'."""
        return self._bias_pitch

    @bias_pitch.setter
    def bias_pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bias_pitch' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bias_pitch' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bias_pitch = value

    @builtins.property
    def bias_yaw(self):
        """Message field 'bias_yaw'."""
        return self._bias_yaw

    @bias_yaw.setter
    def bias_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bias_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bias_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bias_yaw = value

    @builtins.property
    def bias_buffer_size(self):
        """Message field 'bias_buffer_size'."""
        return self._bias_buffer_size

    @bias_buffer_size.setter
    def bias_buffer_size(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'bias_buffer_size' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'bias_buffer_size' field must be an integer in [-2147483648, 2147483647]"
        self._bias_buffer_size = value

    @builtins.property
    def merging_filter_coefficient(self):
        """Message field 'merging_filter_coefficient'."""
        return self._merging_filter_coefficient

    @merging_filter_coefficient.setter
    def merging_filter_coefficient(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'merging_filter_coefficient' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'merging_filter_coefficient' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._merging_filter_coefficient = value

    @builtins.property
    def corrected_angular_velocity_x(self):
        """Message field 'corrected_angular_velocity_x'."""
        return self._corrected_angular_velocity_x

    @corrected_angular_velocity_x.setter
    def corrected_angular_velocity_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'corrected_angular_velocity_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'corrected_angular_velocity_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._corrected_angular_velocity_x = value

    @builtins.property
    def corrected_angular_velocity_y(self):
        """Message field 'corrected_angular_velocity_y'."""
        return self._corrected_angular_velocity_y

    @corrected_angular_velocity_y.setter
    def corrected_angular_velocity_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'corrected_angular_velocity_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'corrected_angular_velocity_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._corrected_angular_velocity_y = value

    @builtins.property
    def corrected_angular_velocity_z(self):
        """Message field 'corrected_angular_velocity_z'."""
        return self._corrected_angular_velocity_z

    @corrected_angular_velocity_z.setter
    def corrected_angular_velocity_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'corrected_angular_velocity_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'corrected_angular_velocity_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._corrected_angular_velocity_z = value

    @builtins.property
    def gyro_integrated_roll(self):
        """Message field 'gyro_integrated_roll'."""
        return self._gyro_integrated_roll

    @gyro_integrated_roll.setter
    def gyro_integrated_roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_integrated_roll' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_integrated_roll' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_integrated_roll = value

    @builtins.property
    def gyro_integrated_pitch(self):
        """Message field 'gyro_integrated_pitch'."""
        return self._gyro_integrated_pitch

    @gyro_integrated_pitch.setter
    def gyro_integrated_pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_integrated_pitch' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_integrated_pitch' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_integrated_pitch = value

    @builtins.property
    def gyro_integrated_yaw(self):
        """Message field 'gyro_integrated_yaw'."""
        return self._gyro_integrated_yaw

    @gyro_integrated_yaw.setter
    def gyro_integrated_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_integrated_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_integrated_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_integrated_yaw = value

    @builtins.property
    def gyro_roll_innovation(self):
        """Message field 'gyro_roll_innovation'."""
        return self._gyro_roll_innovation

    @gyro_roll_innovation.setter
    def gyro_roll_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_roll_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_roll_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_roll_innovation = value

    @builtins.property
    def gyro_pitch_innovation(self):
        """Message field 'gyro_pitch_innovation'."""
        return self._gyro_pitch_innovation

    @gyro_pitch_innovation.setter
    def gyro_pitch_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_pitch_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_pitch_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_pitch_innovation = value

    @builtins.property
    def gyro_yaw_innovation(self):
        """Message field 'gyro_yaw_innovation'."""
        return self._gyro_yaw_innovation

    @gyro_yaw_innovation.setter
    def gyro_yaw_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyro_yaw_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gyro_yaw_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gyro_yaw_innovation = value

    @builtins.property
    def tilt_roll_innovation(self):
        """Message field 'tilt_roll_innovation'."""
        return self._tilt_roll_innovation

    @tilt_roll_innovation.setter
    def tilt_roll_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_roll_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_roll_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_roll_innovation = value

    @builtins.property
    def tilt_pitch_innovation(self):
        """Message field 'tilt_pitch_innovation'."""
        return self._tilt_pitch_innovation

    @tilt_pitch_innovation.setter
    def tilt_pitch_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_pitch_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_pitch_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_pitch_innovation = value

    @builtins.property
    def tilt_yaw_innovation(self):
        """Message field 'tilt_yaw_innovation'."""
        return self._tilt_yaw_innovation

    @tilt_yaw_innovation.setter
    def tilt_yaw_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_yaw_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_yaw_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_yaw_innovation = value

    @builtins.property
    def roll_innovation(self):
        """Message field 'roll_innovation'."""
        return self._roll_innovation

    @roll_innovation.setter
    def roll_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'roll_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'roll_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._roll_innovation = value

    @builtins.property
    def pitch_innovation(self):
        """Message field 'pitch_innovation'."""
        return self._pitch_innovation

    @pitch_innovation.setter
    def pitch_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pitch_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pitch_innovation = value

    @builtins.property
    def yaw_innovation(self):
        """Message field 'yaw_innovation'."""
        return self._yaw_innovation

    @yaw_innovation.setter
    def yaw_innovation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_innovation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'yaw_innovation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._yaw_innovation = value

    @builtins.property
    def merged_roll(self):
        """Message field 'merged_roll'."""
        return self._merged_roll

    @merged_roll.setter
    def merged_roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'merged_roll' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'merged_roll' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._merged_roll = value

    @builtins.property
    def merged_pitch(self):
        """Message field 'merged_pitch'."""
        return self._merged_pitch

    @merged_pitch.setter
    def merged_pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'merged_pitch' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'merged_pitch' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._merged_pitch = value

    @builtins.property
    def merged_yaw(self):
        """Message field 'merged_yaw'."""
        return self._merged_yaw

    @merged_yaw.setter
    def merged_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'merged_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'merged_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._merged_yaw = value

    @builtins.property
    def merged_minus_tilt_roll(self):
        """Message field 'merged_minus_tilt_roll'."""
        return self._merged_minus_tilt_roll

    @merged_minus_tilt_roll.setter
    def merged_minus_tilt_roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'merged_minus_tilt_roll' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'merged_minus_tilt_roll' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._merged_minus_tilt_roll = value

    @builtins.property
    def merged_minus_tilt_pitch(self):
        """Message field 'merged_minus_tilt_pitch'."""
        return self._merged_minus_tilt_pitch

    @merged_minus_tilt_pitch.setter
    def merged_minus_tilt_pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'merged_minus_tilt_pitch' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'merged_minus_tilt_pitch' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._merged_minus_tilt_pitch = value

    @builtins.property
    def merged_minus_tilt_yaw(self):
        """Message field 'merged_minus_tilt_yaw'."""
        return self._merged_minus_tilt_yaw

    @merged_minus_tilt_yaw.setter
    def merged_minus_tilt_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'merged_minus_tilt_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'merged_minus_tilt_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._merged_minus_tilt_yaw = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value

    @builtins.property
    def filter_elapsed_time(self):
        """Message field 'filter_elapsed_time'."""
        return self._filter_elapsed_time

    @filter_elapsed_time.setter
    def filter_elapsed_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'filter_elapsed_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'filter_elapsed_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._filter_elapsed_time = value
