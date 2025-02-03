from setuptools import setup

setup(
    name='cola2_control',
    version='0.0.1',
    packages=['cola2_control'],
    package_dir={'': 'src'},
    install_requires=['setuptools', 'rclpy', 'std_msgs'],
    zip_safe=True,
)
