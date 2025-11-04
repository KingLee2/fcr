import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/mvibot/floorCleaningRobot_ws/install/opennav_coverage_demo'
