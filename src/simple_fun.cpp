#include "simple_fun.h"
using namespace std;

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


/******************************************************/
/*solve the equation cos(x)=exp(y), input y, return x*/
/******************************************************/
complex<double> cosx_eq_expy(double y)
{
    complex<double> ey={exp(y),0};
    complex<double> gamma=acos(ey);

    //Since gamma is pure real or pure imaginary, set it:
    if( abs( gamma.real() ) < abs( gamma.imag() ) )  gamma=complex<double>( 0, gamma.imag() );
    else                                             gamma=complex<double>( gamma.real(), 0 );

    return gamma;
}


/***************************************************************/
/* Input matrix is:                                            */
/* (a , c*)                                                    */
/* (c , b )                                                    */
/* Output exp of this matrix                                   */
/* Similiar to diagonalize BCS matrix, see my note for details */
/***************************************************************/
void exp_matrix(double& a, double& b, complex<double>& c)
{
    double abs_c = std::abs(c);
    double arg_c = std::arg(c);
    double xi    = 0.5*atan( 2.0*abs_c/(a-b) );

    //Eigenvalues
    double d0 = 0.5*cos(2.0*xi)*(a-b) + sin(2.0*xi)*abs_c + (a+b)*0.5;
    double d1 =-0.5*cos(2.0*xi)*(a-b) - sin(2.0*xi)*abs_c + (a+b)*0.5;

    d0 = exp(d0);
    d1 = exp(d1);

    //Eigenvectors
    complex<double> im(0.0,1.0);
    complex<double> v00 =  exp(-im*arg_c*0.5 ) * cos(xi);
    complex<double> v10 =  exp( im*arg_c*0.5 ) * sin(xi);
    complex<double> v01 = -exp(-im*arg_c*0.5 ) * sin(xi);
    complex<double> v11 =  exp( im*arg_c*0.5 ) * cos(xi);

    //Calculate v.d.v^{+}
    a = ( d0*v00*conj(v00) + d1*v01*conj(v01) ).real();
    b = ( d0*v10*conj(v10) + d1*v11*conj(v11) ).real();
    c = d0*v10*conj(v00) + d1*v11*conj(v01);
}


/***************************************************************/
/* Input matrix is:                                            */
/* (a , c*)                                                    */
/* (c , b )                                                    */
/* Output lowest eigenvalue and eigenvector                    */
/***************************************************************/
double ground_eigen(double a, double b, complex<double> c, complex<double>& vec0, complex<double>& vec1)
{
    double abs_c = std::abs(c);
    double arg_c = std::arg(c);
    double xi    = 0.5*atan( 2.0*abs_c/(a-b) );

    //Eigenvalues
    double d0 = 0.5*cos(2.0*xi)*(a-b) + sin(2.0*xi)*abs_c + (a+b)*0.5;
    double d1 =-0.5*cos(2.0*xi)*(a-b) - sin(2.0*xi)*abs_c + (a+b)*0.5;

    //Lowest eigenvector
    complex<double> im(0.0,1.0);
    if( d0 < d1 ) 
    {
        vec0 = exp(-im*arg_c*0.5 ) * cos(xi);
        vec1 = exp( im*arg_c*0.5 ) * sin(xi);
        return d0; 
    }
    else
    {
        vec0 = -exp(-im*arg_c*0.5 ) * sin(xi);
        vec1 =  exp( im*arg_c*0.5 ) * cos(xi);
        return d1;
    }   
}
