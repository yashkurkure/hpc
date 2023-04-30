#include "mpi.h"
#include <iostream>
#include <string>
#include <vector>

const int MAX_TITLE_LENGTH = 256;

struct Book {
  int id;
  char title[MAX_TITLE_LENGTH];
};

int main(int argc, char *argv[]){
  MPI_Init(&argc, &argv);

  std::vector<Book> books(343);

  MPI_Datatype BookType;
  MPI_Datatype type[2] = { MPI_INTEGER, MPI_CHAR };
  int blocklen[2] = { 1, MAX_TITLE_LENGTH };

  MPI_Aint offsets[2];
  offsets[0] = 0;
  offsets[1] = sizeof(int);
  MPI_Type_create_struct(2, blocklen, offsets, type, &BookType);
  MPI_Type_commit(&BookType);

  int myrank;
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

  if (myrank == 0) {
    books[3].id = 4;
    MPI_Send(books.data(), 343, BookType, 1, 123, MPI_COMM_WORLD);
  } else if (myrank == 1) {
    MPI_Status status;
	std::cout<<books[3].id<<std::endl;
    MPI_Recv(books.data(), 343, BookType, 0, 123, MPI_COMM_WORLD, &status);
    std::cout<<books[3].id<<std::endl;
  }
  MPI_Finalize();
  return 0;
}