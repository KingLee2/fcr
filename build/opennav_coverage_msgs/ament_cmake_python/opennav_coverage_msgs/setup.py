from setuptools import find_packages
from setuptools import setup

setup(
    name='opennav_coverage_msgs',
    version='0.0.1',
    packages=find_packages(
        include=('opennav_coverage_msgs', 'opennav_coverage_msgs.*')),
)
