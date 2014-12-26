#include "math_container.h"

using namespace std;
void sort_indexes_test()
{
 vector<double> v={2.0,1.1,3.0,4.0,0.0,1.1};
 vector<size_t> idx=sort_indexes(v);
 //for (auto i: idx) cout<<i<<" "<<v[i]<<endl;
 
 size_t flag=0;
 for(size_t i=0; i<(idx.size()-1); i++) 
 {
  if(v[idx[i]]>v[idx[i+1]]) flag++;
  //cout<<v[idx[i]]<<" "<<v[idx[i+1]]<<endl;;
 }
 if(flag==0) cout<<"Sort_indexes passed the test!\n";
 else cout<<"Warning!!!!Sort_indexes failed the test!\n";
}

void coshx_eq_expy_test()
{
 vector<double> v={2.0,1.1,3.0,4.0,0.0,-1.2,-3.3};
 complex<double> gamma;
 size_t flag=0;
 for (auto i: v)
 {
  gamma=coshx_eq_expy(i);
  //cout<<abs(cosh(gamma)-exp(i))<<endl;
  if(abs(cosh(gamma)-exp(i))>1e-10) flag++;
 }
 if(flag==0) cout<<"Coshx_eq_expy passed the test!\n";
 else cout<<"Warning!!!!Coshx_eq_expy failed the test!\n";
}

void math_container_test()
{
 sort_indexes_test();
 coshx_eq_expy_test();
}
