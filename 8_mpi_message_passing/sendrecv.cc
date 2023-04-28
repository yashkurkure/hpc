#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);

	int rank, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size != 2) {
		cout << "This program requires exactly 2 processes, found: " << size <<endl;
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	if (rank == 0) {
		// send message to process 1
		int msg = 42;
		MPI_Send(&msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else {
		int msg;
		MPI_Recv(&msg, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "Process 1 received message: " << msg << endl;
	}

	MPI_Finalize();
	return 0;
}