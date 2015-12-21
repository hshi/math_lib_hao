#include "math_container.h"
#include <iostream>

#ifdef MPI_HAO
#include <mpi.h>
#endif

using namespace std;

void simple_fun_test();
void sort_fun_test();
void brents_fun_test();

int main(int argc, char** argv)
{
    int rank=0;

#ifdef MPI_HAO
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0) cout<<"\n\n\n=======Testing======="<<endl;
    simple_fun_test();
    sort_fun_test();
    brents_fun_test();

#ifdef MPI_HAO
    MPI_Finalize();
#endif

    return 0;
}
