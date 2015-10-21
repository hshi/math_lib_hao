#include "brents_fun.h"

using namespace std;

double fun1(double x)
{
  return -2.0*x+1;
}

double fun2(double x)
{
  return x*x-2.0*x-3;
}
void brents_fun_test()
{
     double eta=1e-8;
     double x;
     x=brents_fun(fun1,-1.0,5.0,eta);
     if(abs(x-0.5)<eta) cout<<"brents_fun passed quadratic order test!\n";
     else cout<<"Warning!!!!brents_fun failed quadratic order test!!\n";

     x=brents_fun(fun2,1.0,5.0,eta);
     if(abs(x-3.0)<eta) cout<<"brents_fun passed quadratic order test!\n";
     else cout<<"Warning!!!!brents_fun failed quadratic order test!!\n";

}
