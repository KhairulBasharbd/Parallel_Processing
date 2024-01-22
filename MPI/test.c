#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define M 3
#define N 3
#define P 3



void printMatrix(int matrix[M][P]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int A[M][N], B[N][P], C[M][P];
    int submatrix[M/size][P];

    if (rank == 0) {
        // Initialize matrices A and B
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = i + j;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                B[i][j] = i - j;
            }
        }

        printf("Matrix A:\n");
        printMatrix(A);

        printf("\nMatrix B:\n");
        printMatrix(B);
    }

    // Scatter rows of A to all processes
    MPI_Scatter(A, (M/size)*N, MPI_INT, submatrix, (M/size)*P, MPI_INT, 0, MPI_COMM_WORLD);

    // Broadcast matrix B to all processes
    MPI_Bcast(B, N*P, MPI_INT, 0, MPI_COMM_WORLD);

    // Perform local matrix multiplication
    for (int i = 0; i < M/size; i++) {
        for (int j = 0; j < P; j++) {
            submatrix[i][j] = 0;
            for (int k = 0; k < N; k++) {
                submatrix[i][j] += A[i + rank*(M/size)][k] * B[k][j];
            }
        }
    }

    // Gather results from all processes
    MPI_Gather(submatrix, (M/size)*P, MPI_INT, C, (M/size)*P, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("\nMatrix C (Result of Matrix Multiplication AxB):\n");
        printMatrix(C);
    }

    MPI_Finalize();

    return 0;
}
