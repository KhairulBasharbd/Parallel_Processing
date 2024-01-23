# Parallel Processing with MPI and CUDA

## Overview

This repository provides examples and resources for implementing parallel processing using Message Passing Interface (MPI) and Compute Unified Device Architecture (CUDA). MPI is a standard for parallel programming in distributed memory systems, while CUDA is a parallel computing platform and application programming interface model created by NVIDIA.
## The problem list is--------

#1. Write a program to multiply K different matrices A of dimension MxN with matrices B of dimension NxP dimension matrices. Where K is the number of matrices. K <= 3000; M,N,P <= 16
-(a). Using MPI
-(b). Using CUDA
-Input: K, M, N, P
-Output: Time taken for multiplication
-#2. Write a program to count the words in a file and sort it in descending order of frequency of words i.e., highest occurring word must come first and the least occurring word must
come last.
-(a). Using MPI
-(b). Using CUDA
-Input: No. of processes, (Text input from file)
-Output: Total time, top 10 occurrences
-#3. A phonebook is given as a file. Write a program to search for all the contacts matching a name.
-(a). Using MPI
-(b). Using CUDA
-Input: No. of processes, (phonebook from file)
-Output: Total time, Matching names and contact numbers
-#4. Given a paragraph and a pattern like %x%, write a program to find out the number occurrences of the given pattern inside the text.
-(a). Using MPI
-(b). Using CUDA
-Input: No. of processes, (paragraph from file)
-Output: Total time, No. of occurrences of the pattern





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
