# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.12
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info >= (2, 7, 0):
    def swig_import_helper():
        import importlib
        pkg = __name__.rpartition('.')[0]
        mname = '.'.join((pkg, '_vmc')).lstrip('.')
        try:
            return importlib.import_module(mname)
        except ImportError:
            return importlib.import_module('_vmc')
    _vmc = swig_import_helper()
    del swig_import_helper
elif _swig_python_version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_vmc', [dirname(__file__)])
        except ImportError:
            import _vmc
            return _vmc
        try:
            _mod = imp.load_module('_vmc', fp, pathname, description)
        finally:
            if fp is not None:
                fp.close()
        return _mod
    _vmc = swig_import_helper()
    del swig_import_helper
else:
    import _vmc
del _swig_python_version_info

try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        if _newclass:
            object.__setattr__(self, name, value)
        else:
            self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr(self, class_type, name):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    raise AttributeError("'%s' object has no attribute '%s'" % (class_type.__name__, name))


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except __builtin__.Exception:
    class _object:
        pass
    _newclass = 0

class SwigPyIterator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SwigPyIterator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SwigPyIterator, name)

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _vmc.delete_SwigPyIterator
    __del__ = lambda self: None

    def value(self):
        return _vmc.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _vmc.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _vmc.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _vmc.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _vmc.SwigPyIterator_equal(self, x)

    def copy(self):
        return _vmc.SwigPyIterator_copy(self)

    def next(self):
        return _vmc.SwigPyIterator_next(self)

    def __next__(self):
        return _vmc.SwigPyIterator___next__(self)

    def previous(self):
        return _vmc.SwigPyIterator_previous(self)

    def advance(self, n):
        return _vmc.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _vmc.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _vmc.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _vmc.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _vmc.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _vmc.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _vmc.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self
SwigPyIterator_swigregister = _vmc.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)

class vector_double(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, vector_double, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, vector_double, name)
    __repr__ = _swig_repr

    def iterator(self):
        return _vmc.vector_double_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _vmc.vector_double___nonzero__(self)

    def __bool__(self):
        return _vmc.vector_double___bool__(self)

    def __len__(self):
        return _vmc.vector_double___len__(self)

    def __getslice__(self, i, j):
        return _vmc.vector_double___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _vmc.vector_double___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _vmc.vector_double___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _vmc.vector_double___delitem__(self, *args)

    def __getitem__(self, *args):
        return _vmc.vector_double___getitem__(self, *args)

    def __setitem__(self, *args):
        return _vmc.vector_double___setitem__(self, *args)

    def pop(self):
        return _vmc.vector_double_pop(self)

    def append(self, x):
        return _vmc.vector_double_append(self, x)

    def empty(self):
        return _vmc.vector_double_empty(self)

    def size(self):
        return _vmc.vector_double_size(self)

    def swap(self, v):
        return _vmc.vector_double_swap(self, v)

    def begin(self):
        return _vmc.vector_double_begin(self)

    def end(self):
        return _vmc.vector_double_end(self)

    def rbegin(self):
        return _vmc.vector_double_rbegin(self)

    def rend(self):
        return _vmc.vector_double_rend(self)

    def clear(self):
        return _vmc.vector_double_clear(self)

    def get_allocator(self):
        return _vmc.vector_double_get_allocator(self)

    def pop_back(self):
        return _vmc.vector_double_pop_back(self)

    def erase(self, *args):
        return _vmc.vector_double_erase(self, *args)

    def __init__(self, *args):
        this = _vmc.new_vector_double(*args)
        try:
            self.this.append(this)
        except __builtin__.Exception:
            self.this = this

    def push_back(self, x):
        return _vmc.vector_double_push_back(self, x)

    def front(self):
        return _vmc.vector_double_front(self)

    def back(self):
        return _vmc.vector_double_back(self)

    def assign(self, n, x):
        return _vmc.vector_double_assign(self, n, x)

    def resize(self, *args):
        return _vmc.vector_double_resize(self, *args)

    def insert(self, *args):
        return _vmc.vector_double_insert(self, *args)

    def reserve(self, n):
        return _vmc.vector_double_reserve(self, n)

    def capacity(self):
        return _vmc.vector_double_capacity(self)
    __swig_destroy__ = _vmc.delete_vector_double
    __del__ = lambda self: None
vector_double_swigregister = _vmc.vector_double_swigregister
vector_double_swigregister(vector_double)

class He(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, He, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, He, name)
    __repr__ = _swig_repr

    def __init__(self, Nin, alphain, MCStepsin):
        this = _vmc.new_He(Nin, alphain, MCStepsin)
        try:
            self.this.append(this)
        except __builtin__.Exception:
            self.this = this

    def zeroAccumulators(self):
        return _vmc.He_zeroAccumulators(self)

    def p(self, xTrial, x):
        return _vmc.He_p(self, xTrial, x)

    def eLocal(self, xi):
        return _vmc.He_eLocal(self, xi)

    def MetropolisStep(self):
        return _vmc.He_MetropolisStep(self)

    def oneMonteCarloStep(self):
        return _vmc.He_oneMonteCarloStep(self)

    def adjustStep(self):
        return _vmc.He_adjustStep(self)

    def doProductionSteps(self):
        return _vmc.He_doProductionSteps(self)

    def printout(self):
        return _vmc.He_printout(self)

    def normPsi(self):
        return _vmc.He_normPsi(self)

    def get_psiSqd(self):
        return _vmc.He_get_psiSqd(self)

    def get_eAve(self):
        return _vmc.He_get_eAve(self)

    def get_eVar(self):
        return _vmc.He_get_eVar(self)

    def get_rMin(self):
        return _vmc.He_get_rMin(self)

    def get_rMax(self):
        return _vmc.He_get_rMax(self)

    def get_dr(self):
        return _vmc.He_get_dr(self)
    __swig_destroy__ = _vmc.delete_He
    __del__ = lambda self: None
He_swigregister = _vmc.He_swigregister
He_swigregister(He)

class Vector3d(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Vector3d, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Vector3d, name)
    __repr__ = _swig_repr

    def __init__(self, ix, iy, iz):
        this = _vmc.new_Vector3d(ix, iy, iz)
        try:
            self.this.append(this)
        except __builtin__.Exception:
            self.this = this

    def x(self):
        return _vmc.Vector3d_x(self)

    def y(self):
        return _vmc.Vector3d_y(self)

    def z(self):
        return _vmc.Vector3d_z(self)

    def perp(self):
        return _vmc.Vector3d_perp(self)

    def perp2(self):
        return _vmc.Vector3d_perp2(self)

    def r2(self):
        return _vmc.Vector3d_r2(self)

    def r(self):
        return _vmc.Vector3d_r(self)

    def phi(self):
        return _vmc.Vector3d_phi(self)

    def theta(self):
        return _vmc.Vector3d_theta(self)

    def cosTheta(self):
        return _vmc.Vector3d_cosTheta(self)

    def PrintXYZ(self):
        return _vmc.Vector3d_PrintXYZ(self)

    def Print(self):
        return _vmc.Vector3d_Print(self)

    def __add__(self, right):
        return _vmc.Vector3d___add__(self, right)

    def __sub__(self, right):
        return _vmc.Vector3d___sub__(self, right)

    def __mul__(self, right):
        return _vmc.Vector3d___mul__(self, right)
    __swig_destroy__ = _vmc.delete_Vector3d
    __del__ = lambda self: None
Vector3d_swigregister = _vmc.Vector3d_swigregister
Vector3d_swigregister(Vector3d)


def testVector3ds():
    return _vmc.testVector3ds()
testVector3ds = _vmc.testVector3ds
# This file is compatible with both classic and new-style classes.


