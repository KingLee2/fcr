# generated from rosidl_generator_py/resource/_idl.py.em
# with input from opennav_coverage_msgs:action/ComputeCoveragePath.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ComputeCoveragePath_Goal(type):
    """Metaclass of message 'ComputeCoveragePath_Goal'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__goal

            from opennav_coverage_msgs.msg import Coordinates
            if Coordinates.__class__._TYPE_SUPPORT is None:
                Coordinates.__class__.__import_type_support__()

            from opennav_coverage_msgs.msg import HeadlandMode
            if HeadlandMode.__class__._TYPE_SUPPORT is None:
                HeadlandMode.__class__.__import_type_support__()

            from opennav_coverage_msgs.msg import PathMode
            if PathMode.__class__._TYPE_SUPPORT is None:
                PathMode.__class__.__import_type_support__()

            from opennav_coverage_msgs.msg import RouteMode
            if RouteMode.__class__._TYPE_SUPPORT is None:
                RouteMode.__class__.__import_type_support__()

            from opennav_coverage_msgs.msg import RowSwathMode
            if RowSwathMode.__class__._TYPE_SUPPORT is None:
                RowSwathMode.__class__.__import_type_support__()

            from opennav_coverage_msgs.msg import SwathMode
            if SwathMode.__class__._TYPE_SUPPORT is None:
                SwathMode.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'GENERATE_HEADLAND__DEFAULT': True,
            'GENERATE_ROUTE__DEFAULT': True,
            'GENERATE_PATH__DEFAULT': True,
            'USE_GML_FILE__DEFAULT': False,
            'FRAME_ID__DEFAULT': 'map',
        }

    @property
    def GENERATE_HEADLAND__DEFAULT(cls):
        """Return default value for message field 'generate_headland'."""
        return True

    @property
    def GENERATE_ROUTE__DEFAULT(cls):
        """Return default value for message field 'generate_route'."""
        return True

    @property
    def GENERATE_PATH__DEFAULT(cls):
        """Return default value for message field 'generate_path'."""
        return True

    @property
    def USE_GML_FILE__DEFAULT(cls):
        """Return default value for message field 'use_gml_file'."""
        return False

    @property
    def FRAME_ID__DEFAULT(cls):
        """Return default value for message field 'frame_id'."""
        return 'map'


class ComputeCoveragePath_Goal(metaclass=Metaclass_ComputeCoveragePath_Goal):
    """Message class 'ComputeCoveragePath_Goal'."""

    __slots__ = [
        '_generate_headland',
        '_generate_route',
        '_generate_path',
        '_use_gml_file',
        '_gml_field',
        '_polygons',
        '_frame_id',
        '_headland_mode',
        '_swath_mode',
        '_row_swath_mode',
        '_route_mode',
        '_path_mode',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'generate_headland': 'boolean',
        'generate_route': 'boolean',
        'generate_path': 'boolean',
        'use_gml_file': 'boolean',
        'gml_field': 'string',
        'polygons': 'sequence<opennav_coverage_msgs/Coordinates>',
        'frame_id': 'string',
        'headland_mode': 'opennav_coverage_msgs/HeadlandMode',
        'swath_mode': 'opennav_coverage_msgs/SwathMode',
        'row_swath_mode': 'opennav_coverage_msgs/RowSwathMode',
        'route_mode': 'opennav_coverage_msgs/RouteMode',
        'path_mode': 'opennav_coverage_msgs/PathMode',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'Coordinates')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'HeadlandMode'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'SwathMode'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'RowSwathMode'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'RouteMode'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'PathMode'),  # noqa: E501
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
        self.generate_headland = kwargs.get(
            'generate_headland', ComputeCoveragePath_Goal.GENERATE_HEADLAND__DEFAULT)
        self.generate_route = kwargs.get(
            'generate_route', ComputeCoveragePath_Goal.GENERATE_ROUTE__DEFAULT)
        self.generate_path = kwargs.get(
            'generate_path', ComputeCoveragePath_Goal.GENERATE_PATH__DEFAULT)
        self.use_gml_file = kwargs.get(
            'use_gml_file', ComputeCoveragePath_Goal.USE_GML_FILE__DEFAULT)
        self.gml_field = kwargs.get('gml_field', str())
        self.polygons = kwargs.get('polygons', [])
        self.frame_id = kwargs.get(
            'frame_id', ComputeCoveragePath_Goal.FRAME_ID__DEFAULT)
        from opennav_coverage_msgs.msg import HeadlandMode
        self.headland_mode = kwargs.get('headland_mode', HeadlandMode())
        from opennav_coverage_msgs.msg import SwathMode
        self.swath_mode = kwargs.get('swath_mode', SwathMode())
        from opennav_coverage_msgs.msg import RowSwathMode
        self.row_swath_mode = kwargs.get('row_swath_mode', RowSwathMode())
        from opennav_coverage_msgs.msg import RouteMode
        self.route_mode = kwargs.get('route_mode', RouteMode())
        from opennav_coverage_msgs.msg import PathMode
        self.path_mode = kwargs.get('path_mode', PathMode())

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
        if self.generate_headland != other.generate_headland:
            return False
        if self.generate_route != other.generate_route:
            return False
        if self.generate_path != other.generate_path:
            return False
        if self.use_gml_file != other.use_gml_file:
            return False
        if self.gml_field != other.gml_field:
            return False
        if self.polygons != other.polygons:
            return False
        if self.frame_id != other.frame_id:
            return False
        if self.headland_mode != other.headland_mode:
            return False
        if self.swath_mode != other.swath_mode:
            return False
        if self.row_swath_mode != other.row_swath_mode:
            return False
        if self.route_mode != other.route_mode:
            return False
        if self.path_mode != other.path_mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def generate_headland(self):
        """Message field 'generate_headland'."""
        return self._generate_headland

    @generate_headland.setter
    def generate_headland(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'generate_headland' field must be of type 'bool'"
        self._generate_headland = value

    @builtins.property
    def generate_route(self):
        """Message field 'generate_route'."""
        return self._generate_route

    @generate_route.setter
    def generate_route(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'generate_route' field must be of type 'bool'"
        self._generate_route = value

    @builtins.property
    def generate_path(self):
        """Message field 'generate_path'."""
        return self._generate_path

    @generate_path.setter
    def generate_path(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'generate_path' field must be of type 'bool'"
        self._generate_path = value

    @builtins.property
    def use_gml_file(self):
        """Message field 'use_gml_file'."""
        return self._use_gml_file

    @use_gml_file.setter
    def use_gml_file(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'use_gml_file' field must be of type 'bool'"
        self._use_gml_file = value

    @builtins.property
    def gml_field(self):
        """Message field 'gml_field'."""
        return self._gml_field

    @gml_field.setter
    def gml_field(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'gml_field' field must be of type 'str'"
        self._gml_field = value

    @builtins.property
    def polygons(self):
        """Message field 'polygons'."""
        return self._polygons

    @polygons.setter
    def polygons(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import Coordinates
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
                 all(isinstance(v, Coordinates) for v in value) and
                 True), \
                "The 'polygons' field must be a set or sequence and each value of type 'Coordinates'"
        self._polygons = value

    @builtins.property
    def frame_id(self):
        """Message field 'frame_id'."""
        return self._frame_id

    @frame_id.setter
    def frame_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'frame_id' field must be of type 'str'"
        self._frame_id = value

    @builtins.property
    def headland_mode(self):
        """Message field 'headland_mode'."""
        return self._headland_mode

    @headland_mode.setter
    def headland_mode(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import HeadlandMode
            assert \
                isinstance(value, HeadlandMode), \
                "The 'headland_mode' field must be a sub message of type 'HeadlandMode'"
        self._headland_mode = value

    @builtins.property
    def swath_mode(self):
        """Message field 'swath_mode'."""
        return self._swath_mode

    @swath_mode.setter
    def swath_mode(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import SwathMode
            assert \
                isinstance(value, SwathMode), \
                "The 'swath_mode' field must be a sub message of type 'SwathMode'"
        self._swath_mode = value

    @builtins.property
    def row_swath_mode(self):
        """Message field 'row_swath_mode'."""
        return self._row_swath_mode

    @row_swath_mode.setter
    def row_swath_mode(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import RowSwathMode
            assert \
                isinstance(value, RowSwathMode), \
                "The 'row_swath_mode' field must be a sub message of type 'RowSwathMode'"
        self._row_swath_mode = value

    @builtins.property
    def route_mode(self):
        """Message field 'route_mode'."""
        return self._route_mode

    @route_mode.setter
    def route_mode(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import RouteMode
            assert \
                isinstance(value, RouteMode), \
                "The 'route_mode' field must be a sub message of type 'RouteMode'"
        self._route_mode = value

    @builtins.property
    def path_mode(self):
        """Message field 'path_mode'."""
        return self._path_mode

    @path_mode.setter
    def path_mode(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import PathMode
            assert \
                isinstance(value, PathMode), \
                "The 'path_mode' field must be a sub message of type 'PathMode'"
        self._path_mode = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_Result(type):
    """Metaclass of message 'ComputeCoveragePath_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NONE': 0,
        'INTERNAL_F2C_ERROR': 801,
        'INVALID_MODE_SET': 802,
        'INVALID_REQUEST': 803,
        'INVALID_COORDS': 803,
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
                'opennav_coverage_msgs.action.ComputeCoveragePath_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__result

            from builtin_interfaces.msg import Duration
            if Duration.__class__._TYPE_SUPPORT is None:
                Duration.__class__.__import_type_support__()

            from nav_msgs.msg import Path
            if Path.__class__._TYPE_SUPPORT is None:
                Path.__class__.__import_type_support__()

            from opennav_coverage_msgs.msg import PathComponents
            if PathComponents.__class__._TYPE_SUPPORT is None:
                PathComponents.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NONE': cls.__constants['NONE'],
            'INTERNAL_F2C_ERROR': cls.__constants['INTERNAL_F2C_ERROR'],
            'INVALID_MODE_SET': cls.__constants['INVALID_MODE_SET'],
            'INVALID_REQUEST': cls.__constants['INVALID_REQUEST'],
            'INVALID_COORDS': cls.__constants['INVALID_COORDS'],
        }

    @property
    def NONE(self):
        """Message constant 'NONE'."""
        return Metaclass_ComputeCoveragePath_Result.__constants['NONE']

    @property
    def INTERNAL_F2C_ERROR(self):
        """Message constant 'INTERNAL_F2C_ERROR'."""
        return Metaclass_ComputeCoveragePath_Result.__constants['INTERNAL_F2C_ERROR']

    @property
    def INVALID_MODE_SET(self):
        """Message constant 'INVALID_MODE_SET'."""
        return Metaclass_ComputeCoveragePath_Result.__constants['INVALID_MODE_SET']

    @property
    def INVALID_REQUEST(self):
        """Message constant 'INVALID_REQUEST'."""
        return Metaclass_ComputeCoveragePath_Result.__constants['INVALID_REQUEST']

    @property
    def INVALID_COORDS(self):
        """Message constant 'INVALID_COORDS'."""
        return Metaclass_ComputeCoveragePath_Result.__constants['INVALID_COORDS']


class ComputeCoveragePath_Result(metaclass=Metaclass_ComputeCoveragePath_Result):
    """
    Message class 'ComputeCoveragePath_Result'.

    Constants:
      NONE
      INTERNAL_F2C_ERROR
      INVALID_MODE_SET
      INVALID_REQUEST
      INVALID_COORDS
    """

    __slots__ = [
        '_nav_path',
        '_coverage_path',
        '_planning_time',
        '_error_code',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'nav_path': 'nav_msgs/Path',
        'coverage_path': 'opennav_coverage_msgs/PathComponents',
        'planning_time': 'builtin_interfaces/Duration',
        'error_code': 'uint16',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['nav_msgs', 'msg'], 'Path'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'msg'], 'PathComponents'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Duration'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
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
        from nav_msgs.msg import Path
        self.nav_path = kwargs.get('nav_path', Path())
        from opennav_coverage_msgs.msg import PathComponents
        self.coverage_path = kwargs.get('coverage_path', PathComponents())
        from builtin_interfaces.msg import Duration
        self.planning_time = kwargs.get('planning_time', Duration())
        self.error_code = kwargs.get('error_code', int())

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
        if self.nav_path != other.nav_path:
            return False
        if self.coverage_path != other.coverage_path:
            return False
        if self.planning_time != other.planning_time:
            return False
        if self.error_code != other.error_code:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nav_path(self):
        """Message field 'nav_path'."""
        return self._nav_path

    @nav_path.setter
    def nav_path(self, value):
        if self._check_fields:
            from nav_msgs.msg import Path
            assert \
                isinstance(value, Path), \
                "The 'nav_path' field must be a sub message of type 'Path'"
        self._nav_path = value

    @builtins.property
    def coverage_path(self):
        """Message field 'coverage_path'."""
        return self._coverage_path

    @coverage_path.setter
    def coverage_path(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.msg import PathComponents
            assert \
                isinstance(value, PathComponents), \
                "The 'coverage_path' field must be a sub message of type 'PathComponents'"
        self._coverage_path = value

    @builtins.property
    def planning_time(self):
        """Message field 'planning_time'."""
        return self._planning_time

    @planning_time.setter
    def planning_time(self, value):
        if self._check_fields:
            from builtin_interfaces.msg import Duration
            assert \
                isinstance(value, Duration), \
                "The 'planning_time' field must be a sub message of type 'Duration'"
        self._planning_time = value

    @builtins.property
    def error_code(self):
        """Message field 'error_code'."""
        return self._error_code

    @error_code.setter
    def error_code(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'error_code' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'error_code' field must be an unsigned integer in [0, 65535]"
        self._error_code = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_Feedback(type):
    """Metaclass of message 'ComputeCoveragePath_Feedback'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_Feedback(metaclass=Metaclass_ComputeCoveragePath_Feedback):
    """Message class 'ComputeCoveragePath_Feedback'."""

    __slots__ = [
        '_check_fields',
    ]

    _fields_and_field_types = {
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_SendGoal_Request(type):
    """Metaclass of message 'ComputeCoveragePath_SendGoal_Request'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__send_goal__request

            from opennav_coverage_msgs.action import ComputeCoveragePath
            if ComputeCoveragePath.Goal.__class__._TYPE_SUPPORT is None:
                ComputeCoveragePath.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_SendGoal_Request(metaclass=Metaclass_ComputeCoveragePath_SendGoal_Request):
    """Message class 'ComputeCoveragePath_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'opennav_coverage_msgs/ComputeCoveragePath_Goal',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'action'], 'ComputeCoveragePath_Goal'),  # noqa: E501
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
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Goal
        self.goal = kwargs.get('goal', ComputeCoveragePath_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if self._check_fields:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Goal
            assert \
                isinstance(value, ComputeCoveragePath_Goal), \
                "The 'goal' field must be a sub message of type 'ComputeCoveragePath_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_SendGoal_Response(type):
    """Metaclass of message 'ComputeCoveragePath_SendGoal_Response'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_SendGoal_Response(metaclass=Metaclass_ComputeCoveragePath_SendGoal_Response):
    """Message class 'ComputeCoveragePath_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
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
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if self._check_fields:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_SendGoal_Event(type):
    """Metaclass of message 'ComputeCoveragePath_SendGoal_Event'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_SendGoal_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__send_goal__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__send_goal__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__send_goal__event
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__send_goal__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__send_goal__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_SendGoal_Event(metaclass=Metaclass_ComputeCoveragePath_SendGoal_Event):
    """Message class 'ComputeCoveragePath_SendGoal_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<opennav_coverage_msgs/ComputeCoveragePath_SendGoal_Request, 1>',
        'response': 'sequence<opennav_coverage_msgs/ComputeCoveragePath_SendGoal_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'action'], 'ComputeCoveragePath_SendGoal_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'action'], 'ComputeCoveragePath_SendGoal_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.action import ComputeCoveragePath_SendGoal_Request
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
                 len(value) <= 1 and
                 all(isinstance(v, ComputeCoveragePath_SendGoal_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ComputeCoveragePath_SendGoal_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.action import ComputeCoveragePath_SendGoal_Response
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
                 len(value) <= 1 and
                 all(isinstance(v, ComputeCoveragePath_SendGoal_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ComputeCoveragePath_SendGoal_Response'"
        self._response = value


class Metaclass_ComputeCoveragePath_SendGoal(type):
    """Metaclass of service 'ComputeCoveragePath_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('opennav_coverage_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'opennav_coverage_msgs.action.ComputeCoveragePath_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__compute_coverage_path__send_goal

            from opennav_coverage_msgs.action import _compute_coverage_path
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal_Request._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal_Request.__import_type_support__()
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal_Response._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal_Response.__import_type_support__()
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal_Event._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal_Event.__import_type_support__()


class ComputeCoveragePath_SendGoal(metaclass=Metaclass_ComputeCoveragePath_SendGoal):
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_SendGoal_Request as Request
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_SendGoal_Response as Response
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_SendGoal_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_GetResult_Request(type):
    """Metaclass of message 'ComputeCoveragePath_GetResult_Request'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_GetResult_Request(metaclass=Metaclass_ComputeCoveragePath_GetResult_Request):
    """Message class 'ComputeCoveragePath_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
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
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if self._check_fields:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_GetResult_Response(type):
    """Metaclass of message 'ComputeCoveragePath_GetResult_Response'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__get_result__response

            from opennav_coverage_msgs.action import ComputeCoveragePath
            if ComputeCoveragePath.Result.__class__._TYPE_SUPPORT is None:
                ComputeCoveragePath.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_GetResult_Response(metaclass=Metaclass_ComputeCoveragePath_GetResult_Response):
    """Message class 'ComputeCoveragePath_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'opennav_coverage_msgs/ComputeCoveragePath_Result',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'action'], 'ComputeCoveragePath_Result'),  # noqa: E501
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
        self.status = kwargs.get('status', int())
        from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Result
        self.result = kwargs.get('result', ComputeCoveragePath_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Result
            assert \
                isinstance(value, ComputeCoveragePath_Result), \
                "The 'result' field must be a sub message of type 'ComputeCoveragePath_Result'"
        self._result = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_GetResult_Event(type):
    """Metaclass of message 'ComputeCoveragePath_GetResult_Event'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_GetResult_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__get_result__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__get_result__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__get_result__event
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__get_result__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__get_result__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_GetResult_Event(metaclass=Metaclass_ComputeCoveragePath_GetResult_Event):
    """Message class 'ComputeCoveragePath_GetResult_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<opennav_coverage_msgs/ComputeCoveragePath_GetResult_Request, 1>',
        'response': 'sequence<opennav_coverage_msgs/ComputeCoveragePath_GetResult_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'action'], 'ComputeCoveragePath_GetResult_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'action'], 'ComputeCoveragePath_GetResult_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.action import ComputeCoveragePath_GetResult_Request
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
                 len(value) <= 1 and
                 all(isinstance(v, ComputeCoveragePath_GetResult_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ComputeCoveragePath_GetResult_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.action import ComputeCoveragePath_GetResult_Response
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
                 len(value) <= 1 and
                 all(isinstance(v, ComputeCoveragePath_GetResult_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ComputeCoveragePath_GetResult_Response'"
        self._response = value


class Metaclass_ComputeCoveragePath_GetResult(type):
    """Metaclass of service 'ComputeCoveragePath_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('opennav_coverage_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'opennav_coverage_msgs.action.ComputeCoveragePath_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__compute_coverage_path__get_result

            from opennav_coverage_msgs.action import _compute_coverage_path
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult_Request._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult_Request.__import_type_support__()
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult_Response._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult_Response.__import_type_support__()
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult_Event._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult_Event.__import_type_support__()


class ComputeCoveragePath_GetResult(metaclass=Metaclass_ComputeCoveragePath_GetResult):
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_GetResult_Request as Request
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_GetResult_Response as Response
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_GetResult_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputeCoveragePath_FeedbackMessage(type):
    """Metaclass of message 'ComputeCoveragePath_FeedbackMessage'."""

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
                'opennav_coverage_msgs.action.ComputeCoveragePath_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__compute_coverage_path__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__compute_coverage_path__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__compute_coverage_path__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__compute_coverage_path__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__compute_coverage_path__feedback_message

            from opennav_coverage_msgs.action import ComputeCoveragePath
            if ComputeCoveragePath.Feedback.__class__._TYPE_SUPPORT is None:
                ComputeCoveragePath.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputeCoveragePath_FeedbackMessage(metaclass=Metaclass_ComputeCoveragePath_FeedbackMessage):
    """Message class 'ComputeCoveragePath_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'opennav_coverage_msgs/ComputeCoveragePath_Feedback',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['opennav_coverage_msgs', 'action'], 'ComputeCoveragePath_Feedback'),  # noqa: E501
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
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Feedback
        self.feedback = kwargs.get('feedback', ComputeCoveragePath_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if self._check_fields:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if self._check_fields:
            from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Feedback
            assert \
                isinstance(value, ComputeCoveragePath_Feedback), \
                "The 'feedback' field must be a sub message of type 'ComputeCoveragePath_Feedback'"
        self._feedback = value


class Metaclass_ComputeCoveragePath(type):
    """Metaclass of action 'ComputeCoveragePath'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('opennav_coverage_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'opennav_coverage_msgs.action.ComputeCoveragePath')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__compute_coverage_path

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from opennav_coverage_msgs.action import _compute_coverage_path
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_SendGoal.__import_type_support__()
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_GetResult.__import_type_support__()
            if _compute_coverage_path.Metaclass_ComputeCoveragePath_FeedbackMessage._TYPE_SUPPORT is None:
                _compute_coverage_path.Metaclass_ComputeCoveragePath_FeedbackMessage.__import_type_support__()


class ComputeCoveragePath(metaclass=Metaclass_ComputeCoveragePath):

    # The goal message defined in the action definition.
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Goal as Goal
    # The result message defined in the action definition.
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Result as Result
    # The feedback message defined in the action definition.
    from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from opennav_coverage_msgs.action._compute_coverage_path import ComputeCoveragePath_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
