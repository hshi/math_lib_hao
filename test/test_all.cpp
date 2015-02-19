#include "math_container.h"
#include <iostream>

#ifdef MPI_HAO
#include <mpi.h>
#endif

using namespace std;
void math_container_test();

int main(int argc, char** argv)
{
    int rank=0;

#ifdef MPI_HAO
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        cout<<"\n\n\n=======Testing======="<<endl;
        math_container_test();
    }


#ifdef MPI_HAO
    MPI_Finalize();
#endif

    return 0;
}
