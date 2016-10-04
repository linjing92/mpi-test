#include <iostream>
#include<cstdlib>
#include "mpi.h"
using namespace std;

int main()
{
    int w,k,j;
    int A[4]={0};
    int sum[4]={0};
    MPI::Init(argc,argv);
    id=MPI::COMM_WORLD.Get_rank();
    p=MPI::COMM_WORLD.Get_size();

    for(w=0;w<4;w++)
        for(j=0;j<10;j++)
        if(j==w+7)
        A[w]++;

    for(k=0;k<4;k++)
        MPI::COMM_WORLD.Reduce(&A[k],&sum[k],1,MPI::INT,MPI::SUM,0);

    MPI::Finalize();

    if(id==0)
        for(k=0;k<4;k++)
    cout << A[k] << endl;

}
