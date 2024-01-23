# Parallel Processing with MPI and CUDA

## Overview

This repository provides examples and resources for implementing parallel processing using Message Passing Interface (MPI) and Compute Unified Device Architecture (CUDA). MPI is a standard for parallel programming in distributed memory systems, while CUDA is a parallel computing platform and application programming interface model created by NVIDIA.


## Table of Contents

- [Prerequisites](#prerequisites)
- [MPI](#mpi)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Examples](#examples)

## Prerequisites

Before using the examples in this repository, make sure you have the following prerequisites installed:

- MPI implementation (e.g., OpenMPI, MPICH)
- NVIDIA GPU with CUDA support
- CUDA Toolkit

## MPI

### Installation

Follow the instructions provided by the MPI implementation you choose (e.g., OpenMPI, MPICH) to install MPI on your system.

### Usage

Compile MPI programs using the appropriate compiler (e.g., `mpicc` for C programs, `mpic++` for C++ programs). Run MPI programs using `mpiexec` or `mpirun`.

```bash
mpicc my_mpi_program.c -o my_mpi_program
mpiexec -n 4 ./my_mpi_program
