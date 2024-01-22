#include<stdio.h>
#include<mpi.h>

int main(int argc, char** argv){

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("size : %d  rank : %d : Hellow",size,rank);

    MPI_Finalize();
}