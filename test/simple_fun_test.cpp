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
    double a, b, a_exact, b_exact;
    complex<double> c, c_exact;

    a =  1.2; b = -2.0; c = complex<double>( 3.0, -2.0 );
    exp_matrix(a,b,c);
    a_exact = 24.33957375963294;
    b_exact = 10.299809224500716;
    c_exact = complex<double>(13.162279251686476, -8.774852834457649);

    int flag=0;
    if( abs( a_exact-a ) >1e-12 ) flag++;
    if( abs( b_exact-b ) >1e-12 ) flag++;
    if( abs( c_exact-c ) >1e-12 ) flag++;


    a = 0.0; b = 0.0; c = complex<double> (3.0, 2.0);
    exp_matrix(a,b,c);
    a_exact = 18.414569374170224;
    b_exact = 18.414569374170224;
    c_exact = complex<double>( 15.299239013566734, 10.199492675711154 );
    if( abs( a_exact-a ) >1e-12 ) flag++;
    if( abs( b_exact-b ) >1e-12 ) flag++;
    if( abs( c_exact-c ) >1e-12 ) flag++;

    a = 1.0; b = 2.0; c = 0.0;
    exp_matrix(a,b,c);
    a_exact = exp(1.0); b_exact = exp(2.0); c_exact = 0.0;
    if( abs( a_exact-a ) >1e-12 ) flag++;
    if( abs( b_exact-b ) >1e-12 ) flag++;
    if( abs( c_exact-c ) >1e-12 ) flag++;

    if(flag==0) cout<<"PASSED! Exp_matrix passed the test!"<<endl;
    else cout<<"Warning!!!! Exp_matrix failed the test!"<<endl;
}


void eigen_matrix_test()
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-2.0,2.0);

    int flag=0;
    double a, b; complex<double> c;
    double eig[2]; complex<double> vec[4];

    for(int i=0; i<20; i++)
    {
        a = distribution(generator);
        b = distribution(generator);
        c = complex<double>( distribution(generator), distribution(generator) );

        eigen_matrix(a, b, c, eig, vec);

        if( std::abs( a*vec[0]+conj(c)*vec[1] - eig[0]*vec[0] ) > 1e-12 ) flag++;
        if( std::abs( c*vec[0]+b*vec[1] - eig[0]*vec[1] ) > 1e-12 ) flag++;
        if( std::abs( a*vec[2]+conj(c)*vec[3] - eig[1]*vec[2] ) > 1e-12 ) flag++;
        if( std::abs( c*vec[2]+b*vec[3] - eig[1]*vec[3] ) > 1e-12 ) flag++;
    }

    for(int i=0; i<20; i++)
    {
        a = 0.0;
        b = 0.0;
        c = complex<double>( distribution(generator), distribution(generator) );

        eigen_matrix(a, b, c, eig, vec);

        if( std::abs( a*vec[0]+conj(c)*vec[1] - eig[0]*vec[0] ) > 1e-12 ) flag++;
        if( std::abs( c*vec[0]+b*vec[1] - eig[0]*vec[1] ) > 1e-12 ) flag++;
        if( std::abs( a*vec[2]+conj(c)*vec[3] - eig[1]*vec[2] ) > 1e-12 ) flag++;
        if( std::abs( c*vec[2]+b*vec[3] - eig[1]*vec[3] ) > 1e-12 ) flag++;
    }

    for(int i=0; i<20; i++)
    {
        a = distribution(generator);
        b = distribution(generator);
        c = 0.0;

        eigen_matrix(a, b, c, eig, vec);

        if( std::abs( a*vec[0]+conj(c)*vec[1] - eig[0]*vec[0] ) > 1e-12 ) flag++;
        if( std::abs( c*vec[0]+b*vec[1] - eig[0]*vec[1] ) > 1e-12 ) flag++;
        if( std::abs( a*vec[2]+conj(c)*vec[3] - eig[1]*vec[2] ) > 1e-12 ) flag++;
        if( std::abs( c*vec[2]+b*vec[3] - eig[1]*vec[3] ) > 1e-12 ) flag++;
    }

    if(flag==0) cout<<"PASSED! Eigen_matrix passed the test!"<<endl;
    else cout<<"Warning!!!! eigen_matrix failed the test!"<<endl;
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
        eigen_matrix_test();
    }

    if(rank==0) cout<<" "<<endl;
} 
