#include <mpi.h>
#include <iostream>
#include <cstring>


using namespace std;

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);

	int rank, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	/* All ranks other than 0*/
	if(rank != 0) {
		/* Create message */
		char * message = new char[100];
		sprintf(message, "Greetings from process %d", rank);
		int dest = 0;
		MPI_Send(message, 100, MPI_CHAR, dest, 0, MPI_COMM_WORLD);
		delete[] message;
	} 
	/* Rank 0*/
	else {

		for(int source = 1; source < size; source++) {
			char * message = new char[100];;
			MPI_Recv(message, 100, MPI_CHAR, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%s\n", message);
			delete[] message;
		}

		printf("Greetings from process* %d\n", rank);
	}



	MPI_Finalize();
	return 0;
}