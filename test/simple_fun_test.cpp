#include <random>
#include "simple_fun.h"
#ifdef MPI_HAO
#include <mpi.h>
#endif

using namespace std;

void coshx_eq_expy_test()
{
    vector<double> v={-5.0,-3.3,-1.2,0.0,1.1,2.0,3.0,4.0};
    complex<double> gamma;
    size_t flag=0;
    for (auto i: v)
    {
        gamma=coshx_eq_expy(i);
        //cout<<abs(cosh(gamma)-exp(i))<<endl;
        if(abs(cosh(gamma)-exp(i))>1e-10) flag++;
    }
    if(flag==0) cout<<"PASSED! Coshx_eq_expy passed the test!"<<endl;
    else cout<<"Warning!!!!Coshx_eq_expy failed the test!"<<endl;
}


void cosx_eq_expy_test()
{
    vector<double> v={-5.0,-3.3,-1.2,0.0,1.1,2.0,3.0,4.0};
    complex<double> gamma;
    size_t flag=0;
    for (auto i: v)
    {
        gamma=cosx_eq_expy(i);
        //cout<<abs(cos(gamma)-exp(i))<<endl;
        if(abs(cos(gamma)-exp(i))>1e-10) flag++;
    }
    if(flag==0) cout<<"PASSED! Cosx_eq_expy passed the test!"<<endl;
    else cout<<"Warning!!!!Cosx_eq_expy failed the test!"<<endl;
}

void exp_matrix_test()
{
    double          a ( 1.2 );
    double          b (-2.0 );
    complex<double> c ( 3.0, -2.0);

    double a_exact ( 24.33957375963294  );
    double b_exact ( 10.299809224500716 );
    complex<double> c_exact (13.162279251686476, -8.774852834457649);

    exp_matrix(a,b,c);

    int flag=0;
    if( abs( a_exact-a ) >1e-12 ) flag++;
    if( abs( b_exact-b ) >1e-12 ) flag++;
    if( abs( c_exact-c ) >1e-12 ) flag++;
    if(flag==0) cout<<"PASSED! Exp_matrix passed the test!"<<endl;
    else cout<<"Warning!!!! Exp_matrix failed the test!"<<endl;
}


void ground_eigen_test()
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-2.0,2.0);

    int flag=0;
    double  a, b; complex<double> c;
    double d0, d0_exact; complex<double> v0, v1;
    for(int i=0; i<20; i++)
    {
        a = distribution(generator);
        b = distribution(generator);
        c = complex<double>( distribution(generator), distribution(generator) );

        d0 = ground_eigen(a, b, c, v0, v1);
        d0_exact = ( a + b -sqrt( (a-b)*(a-b)+ 4*std::abs(c)*std::abs(c) ) ) * 0.5;

        if( std::abs( a*v0+conj(c)*v1 - d0*v0 ) > 1e-12 ) flag++;
        if( std::abs( c*v0+b*v1 - d0*v1 ) > 1e-12 ) flag++;
        if( std::abs( d0_exact-d0 ) > 1e-12 ) flag++;
    }
    if(flag==0) cout<<"PASSED! Ground_eigen passed the test!"<<endl;
    else cout<<"Warning!!!! Ground_eigen failed the test!"<<endl;
}

void simple_fun_test()
{
    int rank=0;
#ifdef MPI_HAO
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        coshx_eq_expy_test();
        cosx_eq_expy_test();
        exp_matrix_test();
        ground_eigen_test();
    }

    if(rank==0) cout<<" "<<endl;
} 
