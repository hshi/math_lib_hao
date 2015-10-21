#ifndef BRENTS_FUN_H
#define BRENTS_FUN_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

//f is the function, lower and upper is the bound, tol is the tolerance condition
double brents_fun(std::function<double (double)> f, double lower=-100.0, double upper=100.0,
                       double tol=0.0001, unsigned int max_iter=1000);

#endif
