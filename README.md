# Parallel Processing with MPI and CUDA

## Overview

This repository provides examples and resources for implementing parallel processing using Message Passing Interface (MPI) and Compute Unified Device Architecture (CUDA). MPI is a standard for parallel programming in distributed memory systems, while CUDA is a parallel computing platform and application programming interface model created by NVIDIA.

[Problem Assignment](lab problem list/Parallel Processing Lab Experiments.pdf)

```bash
mpicc my_mpi_program.c -o my_mpi_program
mpiexec -n 4 ./my_mpi_program
