#include <mpi.h>
#include <iostream>
#include <cstring>
#include <stdio.h>

int main (int argc, char** argv) {

	int rank = -1, size = -1 , len = -1;
	
	char name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);
	MPI_Barrier(MPI_COMM_WORLD);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Get_processor_name(name, &len);

	MPI_Barrier(MPI_COMM_WORLD);

	printf("Hello world! Process %d of %d on %s\n", rank, size, name);

	MPI_Finalize();

	return 0;
}