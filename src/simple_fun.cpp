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
    if( std::abs(c) < 1e-60 )
    {
        a = exp(a); b = exp(b); c = 0.0;
        return;
    }

    double abs_c = std::abs(c);
    double arg_c = std::arg(c);

    double d0, d1;
    complex<double> v00, v01, v10, v11;
    complex<double> im(0.0,1.0);

    if( std::abs(a-b) < 1e-60 )
    {
        double norm = 1.0/sqrt(2.0);

        //Exp of Eigenvalues
        d0 = exp( -abs_c + a ); 
        d1 = exp(  abs_c + b );

        //Eigenvectors
        v00 = -norm;
        v10 =  norm * exp( im*arg_c );
        v01 =  norm;
        v11 =  norm * exp( im*arg_c );
    }
    else
    {
        double xi    = 0.5*atan( 2.0*abs_c/(a-b) );

        //Exp of Eigenvalues
        d0 =exp(  0.5*cos(2.0*xi)*(a-b) + sin(2.0*xi)*abs_c + (a+b)*0.5 );
        d1 =exp( -0.5*cos(2.0*xi)*(a-b) - sin(2.0*xi)*abs_c + (a+b)*0.5 );

        //Eigenvectors
        v00 =  exp(-im*arg_c*0.5 ) * cos(xi);
        v10 =  exp( im*arg_c*0.5 ) * sin(xi);
        v01 = -exp(-im*arg_c*0.5 ) * sin(xi);
        v11 =  exp( im*arg_c*0.5 ) * cos(xi);
    }

    //Calculate v.d.v^{+}
    a = ( d0*v00*conj(v00) + d1*v01*conj(v01) ).real();
    b = ( d0*v10*conj(v10) + d1*v11*conj(v11) ).real();
    c = d0*v10*conj(v00) + d1*v11*conj(v01);
}


/***************************************************************/
/* Input matrix is:                                            */
/* (a , c*)                                                    */
/* (c , b )                                                    */
/* Output eigenvalues and eigenvectors                         */
/***************************************************************/
void eigen_matrix(double a, double b, complex<double> c, double* eig, complex<double>* vec)
{
    if( std::abs(c) < 1e-60 )
    {
        eig[0] = a; eig[1] = b;
        vec[0] = 1.0; vec[1] = 0.0; vec[2] = 0.0; vec[3] = 1.0;
        return; 
    }

    double abs_c = std::abs(c);
    double arg_c = std::arg(c);
    complex<double> im(0.0,1.0);

    if( std::abs(a-b) < 1e-60 )
    {
        double norm = 1.0/sqrt(2.0);

        eig[0] = -abs_c + a; eig[1] = abs_c + b;
        vec[0] = -norm; vec[1] =  norm * exp( im*arg_c ); vec[2] =  norm;  vec[3] =  norm * exp( im*arg_c );
    }
    else
    {
        double xi    = 0.5*atan( 2.0*abs_c/(a-b) );

        //Eigenvalues
        eig[0] = 0.5*cos(2.0*xi)*(a-b) + sin(2.0*xi)*abs_c + (a+b)*0.5;
        eig[1] =-0.5*cos(2.0*xi)*(a-b) - sin(2.0*xi)*abs_c + (a+b)*0.5;

        //Eigenvectors
        vec[0] =  exp(-im*arg_c*0.5 ) * cos(xi);
        vec[1] =  exp( im*arg_c*0.5 ) * sin(xi);
        vec[2] = -exp(-im*arg_c*0.5 ) * sin(xi);
        vec[3] =  exp( im*arg_c*0.5 ) * cos(xi);
    }
}
