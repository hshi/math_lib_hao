#include "brents_fun.h"
#ifdef MPI_HAO
#include <mpi.h>
#endif

using namespace std;

double fun1(double x)
{
  return -2.0*x+1;
}

double fun2(double x)
{
  return x*x-2.0*x-3;
}

double fun3(double x,double y)
{
  return x*x-2.0*x-1.0-y;
}

void brents_test()
{
     double eta=1e-8;
     double x;
     brents_fun(fun1,x,-1.0,5.0,eta);
     if(abs(x-0.5)<eta) cout<<"PASSED! brents_fun passed quadratic order test!"<<endl;
     else cout<<"Warning!!!!brents_fun failed quadratic order test!!"<<endl;

     brents_fun(fun2,x,1.0,5.0,eta);
     if(abs(x-3.0)<eta) cout<<"PASSED! brents_fun passed quadratic order test!"<<endl;
     else cout<<"Warning!!!!brents_fun failed quadratic order test!!"<<endl;

     brents_fun([](double x) { return fun3(x, 7.0); },x,0.0,5.0,eta);
     if(abs(x-4.0)<eta) cout<<"PASSED! brents_fun passed partially function quadratic order test!"<<endl;
     else cout<<"Warning!!!!brents_fun failed partially function quadratic order test!!"<<endl;

     brents_fun( bind(fun3, placeholders::_1, 7.0),x, 0.0, 5.0,eta);
     if(abs(x-4.0)<eta) cout<<"PASSED! brents_fun passed partially function (bind) quadratic order test!"<<endl;
     else cout<<"Warning!!!!brents_fun failed partially function (bind) quadratic order test!!"<<endl;
}


void brents_fun_test()
{
    int rank=0;
#ifdef MPI_HAO
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        brents_test();
    }

    if(rank==0) cout<<" "<<endl;
} 
