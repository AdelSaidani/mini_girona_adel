from setuptools import find_packages
from setuptools import setup

setup(
    name='cola2_control',
    version='24.1.4',
    packages=find_packages(
        include=('cola2_control', 'cola2_control.*')),
)
