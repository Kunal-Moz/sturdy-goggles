#!/usr/bin/env python

"""
setup.py file for SWIG ising
"""

from distutils.core import setup, Extension


ising3d_module = Extension('_ising3d',
                           sources=['swig/ising3d_wrap.cxx', 'ising3d.cpp'],
                           extra_compile_args=["-I./", "-std=c++11", "-O3"],
                           )

setup (name = 'ising3d',
       version = '0.1',
       author      = "SWIG Docs",
       description = """Implementation of the 3-d Ising model""",
       ext_modules = [ising3d_module],
       py_modules = ["ising3d"],
       )
