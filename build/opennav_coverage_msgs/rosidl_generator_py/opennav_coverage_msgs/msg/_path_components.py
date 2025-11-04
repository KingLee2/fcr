# generated from rosidl_generator_py/resource/_idl.py.em
# with input from opennav_coverage_msgs:msg/PathComponents.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PathComponents(type):
    """Metaclass of message 'PathComponents'."""

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
                'opennav_coverage_msgs.msg.PathComponents')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__path_components
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__path_components
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__path_components
            cls._TYPE_SUPPORT = module.type_support_msg__msg__path_components
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__path_components

            from nav_msgs.msg import Path
            if Path.__class__._TYPE_SUPPORT is None:
                Path.__class__.__import_type_support__()

            from opennav_coverage_msgs.msg import Swath
            if Swath.__class__._TYPE_SUPPORT is None:
                Swath.__class__.__import_type_support__()

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


class PathComponents(metaclass=Metaclass_PathComponents):
    """Message class 'PathComponents'."""

    __slots__ = [
        '_header',
        '_swaths',
        '_turns',
        '_contains_turns',
        '_swaths_ordered',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'swaths': 'sequence<opennav_coverage_msgs/Swath>',
        'turns': 'sequence<nav_msgs/Path>',
        'contains_turns': 'boolean',
        'swaths_ordered': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'Swath')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['nav_msgs', 'msg'], 'Path')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.swaths = kwargs.get('swaths', [])
        self.turns = kwargs.get('turns', [])
        self.contains_turns = kwargs.get('contains_turns', bool())
        self.swaths_ordered = kwargs.get('swaths_ordered', bool())

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
        if self.header != other.header:
            return False
        if self.swaths != other.swaths:
            return False
        if self.turns != other.turns:
            return False
        if self.contains_turns != other.contains_turns:
            return False
        if self.swaths_ordered != other.swaths_ordered:
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
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def swaths(self):
        """Message field 'swaths'."""
        return self._swaths

    @swaths.setter
    def swaths(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import Swath
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
                 all(isinstance(v, Swath) for v in value) and
                 True), \
                "The 'swaths' field must be a set or sequence and each value of type 'Swath'"
        self._swaths = value

    @builtins.property
    def turns(self):
        """Message field 'turns'."""
        return self._turns

    @turns.setter
    def turns(self, value):
        if self._check_fields:
            from nav_msgs.msg import Path
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
                 all(isinstance(v, Path) for v in value) and
                 True), \
                "The 'turns' field must be a set or sequence and each value of type 'Path'"
        self._turns = value

    @builtins.property
    def contains_turns(self):
        """Message field 'contains_turns'."""
        return self._contains_turns

    @contains_turns.setter
    def contains_turns(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'contains_turns' field must be of type 'bool'"
        self._contains_turns = value

    @builtins.property
    def swaths_ordered(self):
        """Message field 'swaths_ordered'."""
        return self._swaths_ordered

    @swaths_ordered.setter
    def swaths_ordered(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'swaths_ordered' field must be of type 'bool'"
        self._swaths_ordered = value
