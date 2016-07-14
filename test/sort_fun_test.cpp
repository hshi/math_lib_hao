#include "sort_fun.h"
#ifdef MPI_HAO
#include <mpi.h>
#endif

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
    if(flag==0) cout<<"PASSED! Sort_indexes passed the test!"<<endl;
    else cout<<"Warning!!!!Sort_indexes failed the test!"<<endl;
}


void sort_fun_test()
{
    int rank=0;
#ifdef MPI_HAO
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        sort_indexes_test();
    }

    if(rank==0) cout<<" "<<endl;
}
