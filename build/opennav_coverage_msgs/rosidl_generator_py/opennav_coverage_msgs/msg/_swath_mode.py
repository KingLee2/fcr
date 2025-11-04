# generated from rosidl_generator_py/resource/_idl.py.em
# with input from opennav_coverage_msgs:msg/SwathMode.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SwathMode(type):
    """Metaclass of message 'SwathMode'."""

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
            module = import_type_support('opennav_coverage_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'opennav_coverage_msgs.msg.SwathMode')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__swath_mode
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__swath_mode
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__swath_mode
            cls._TYPE_SUPPORT = module.type_support_msg__msg__swath_mode
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__swath_mode

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'OBJECTIVE__DEFAULT': 'UNKNOWN',
            'MODE__DEFAULT': 'UNKNOWN',
            'BEST_ANGLE__DEFAULT': 0.0,
            'STEP_ANGLE__DEFAULT': 0.017453,
        }

    @property
    def OBJECTIVE__DEFAULT(cls):
        """Return default value for message field 'objective'."""
        return 'UNKNOWN'

    @property
    def MODE__DEFAULT(cls):
        """Return default value for message field 'mode'."""
        return 'UNKNOWN'

    @property
    def BEST_ANGLE__DEFAULT(cls):
        """Return default value for message field 'best_angle'."""
        return 0.0

    @property
    def STEP_ANGLE__DEFAULT(cls):
        """Return default value for message field 'step_angle'."""
        return 0.017453


class SwathMode(metaclass=Metaclass_SwathMode):
    """Message class 'SwathMode'."""

    __slots__ = [
        '_objective',
        '_mode',
        '_best_angle',
        '_step_angle',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'objective': 'string',
        'mode': 'string',
        'best_angle': 'float',
        'step_angle': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.objective = kwargs.get(
            'objective', SwathMode.OBJECTIVE__DEFAULT)
        self.mode = kwargs.get(
            'mode', SwathMode.MODE__DEFAULT)
        self.best_angle = kwargs.get(
            'best_angle', SwathMode.BEST_ANGLE__DEFAULT)
        self.step_angle = kwargs.get(
            'step_angle', SwathMode.STEP_ANGLE__DEFAULT)

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
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
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.objective != other.objective:
            return False
        if self.mode != other.mode:
            return False
        if self.best_angle != other.best_angle:
            return False
        if self.step_angle != other.step_angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def objective(self):
        """Message field 'objective'."""
        return self._objective

    @objective.setter
    def objective(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'objective' field must be of type 'str'"
        self._objective = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'mode' field must be of type 'str'"
        self._mode = value

    @builtins.property
    def best_angle(self):
        """Message field 'best_angle'."""
        return self._best_angle

    @best_angle.setter
    def best_angle(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'best_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'best_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._best_angle = value

    @builtins.property
    def step_angle(self):
        """Message field 'step_angle'."""
        return self._step_angle

    @step_angle.setter
    def step_angle(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'step_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'step_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._step_angle = value
