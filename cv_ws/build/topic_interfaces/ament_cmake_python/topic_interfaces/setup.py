from setuptools import find_packages
from setuptools import setup

setup(
    name='topic_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('topic_interfaces', 'topic_interfaces.*')),
)
