from setuptools import find_packages
from setuptools import setup

setup(
    name='tf2_web_republisher_interfaces',
    version='1.0.0',
    packages=find_packages(
        include=('tf2_web_republisher_interfaces', 'tf2_web_republisher_interfaces.*')),
)
