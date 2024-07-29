%module ising3d
/* First: Include your own code.*/
%{
#define SWIG_FILE_WITH_INIT
#include "ising3d.h"
%}

%include "std_vector.i"

namespace std {
   %template(vector_double) vector<double>;
};

%include "ising3d.h"


