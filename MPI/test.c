#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>



int main(int argc, char** argv){

    int id,size;

    int m,n,p;
    int count;

    int *m_a, *m_b, *m_c;
    int *l_a, *l_b, *l_c;



    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;

    if(id == 0){

        scanf("%d",&count);
        scanf("%d %d %d",&m, &n,&p);

        m_a =(int *) malloc(count * m * n * sizeof(int));
        m_b = (int*) malloc(count * n * p * sizeof(int));
        m_c = (int*) malloc(count * m * p * sizeof(int));

        for(int i=0; i<count * m * n ; i++){
            m_a[i] = 1;
        }

        for(int i=0; i<count * n * p ; i++){
            m_b[i] = 1;
        }

         for (int i = 0; i < size; i++) {
            MPI_Send(&count, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&m, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
            MPI_Send(&n, 1, MPI_INT, i, 2, MPI_COMM_WORLD);
            MPI_Send(&p, 1, MPI_INT, i, 3, MPI_COMM_WORLD);
        }
    }else{

        MPI_Recv(&count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&m, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(&n, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
        MPI_Recv(&p, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
    }



    int l_count = count / size;

    l_a = (int *)malloc(l_count * m * n * sizeof(int));
    l_b = (int *)malloc(l_count * n * p * sizeof(int));
    l_c = (int *)malloc(l_count * m * p * sizeof(int));

    MPI_Scatter(&m_a, l_count * m * n, MPI_INT, &l_a, l_count * m * n, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(&m_b, l_count * n * p, MPI_INT, &l_b, l_count * m * n, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    int d3_a[l_count][m][n];
    int d3_b[l_count][n][p];
    int d3_c[l_count][m][p];

    int idx=0;
    for(int c=0; c<l_count; c++){
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                d3_a[c][i][j] = l_a[idx++];
            }
        }
    }

    idx=0;
    for(int c=0; c<l_count; c++){
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                d3_b[c][i][j] = l_b[idx++];
            }
        }
    }

    int start_t = MPI_Wtime();
    // Matrix multiplication
    for(int c=0; c<l_count; c++){
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                d3_c[c][i][j] = 0;
                for(int k=0; k<p; k++){
                    d3_c[c][i][j] += d3_a[c][i][k] * d3_b[c][k][j];
                }
            }
        }
    }
    int end_t = MPI_Wtime();

    int t  = end_t - start_t;

    printf("PID : %d Execution time %f ",id,t);
    MPI_Finalize();

    free(l_a);
    free(l_b);
    free(l_c);
    // the memory allocated for global matrices (mat_a, mat_b, mat_c) is only freed by the process with rank 0
    if (id == 0) {
        free(m_a);
        free(m_b);
        free(m_c);
    }
    return 0;
}