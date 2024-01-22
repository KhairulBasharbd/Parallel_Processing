#include<stdio.h>
#include<mpi.h>

int main(int argc, char** argv){
    int rank,size;

    int arr[8] = {1,2,3,4,5,6,7,8};
    int sum, scatter_data[2];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    MPI_Scatter(&arr,2,MPI_INT,&scatter_data,2,MPI_INT,0,MPI_COMM_WORLD);
    sum = scatter_data[0] + scatter_data[1];

    printf("From process %d, has %d, %d, the sum is %d\n", rank,scatter_data[0],scatter_data[1], sum);



    MPI_Finalize();
    return 0;
}