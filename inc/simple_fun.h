#ifndef SIMPLE_FUN_H
#define SIMPLE_FUN_H

#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>

/******************************************************/
/*solve the equation cosh(x)=exp(y), input y, return x*/
/******************************************************/
std::complex<double> coshx_eq_expy(double y);

/******************************************************/
/*solve the equation cos(x)=exp(y), input y, return x*/
/******************************************************/
std::complex<double> cosx_eq_expy(double y);
#endif
