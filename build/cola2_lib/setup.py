from distutils.core import setup

setup(name='cola2',
      version='24.1.1',
      description='Cola 2 library for python',
      author='Iqua Robotics',
      author_email='software@iquarobotics.com',
      package_dir={'':'/home/adel/ros2_ws/src/cola2_lib/python'},
      packages=['cola2','cola2.io','cola2.mission','cola2.utils','cola2.comms','cola2.wmm'],
      )
