#include "math_container.h"

using std::complex;

/******************************************************/
/*solve the equation cosh(x)=exp(y), input y, return x*/
/******************************************************/
complex<double> coshx_eq_expy(double y)
{
    complex<double> ey={exp(y),0};
    return log(ey-sqrt(ey*ey-1.0));
}
