#include "math_container.h"

using std::complex;

/******************************************************/
/*solve the equation cosh(x)=exp(y), input y, return x*/
/******************************************************/
complex<double> coshx_eq_expy(double y)
{
    complex<double> ey={exp(y),0};
    complex<double> gamma=log(ey-sqrt(ey*ey-1.0));

    //Since gamma is pure real or pure imaginary, set it:
    if( abs( gamma.real() ) < abs( gamma.imag() ) )  gamma=complex<double>( 0, gamma.imag() );
    else                                             gamma=complex<double>( gamma.real(), 0 );

    return gamma;
}
