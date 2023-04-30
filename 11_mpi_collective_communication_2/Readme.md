# MPI_Bcast()

One process sends the same data to all process in a communicator.

```
MPI_Bcast(
    void* data,
    int count,
    MPI_Datatype datatype,
    int root,
    MPI_Comm communicator)

```

Although the root process and receiver processes do different jobs, they all call the same MPI_Bcast function.
A use case is to pass user input to all processes.

[1] shows a tree-based communication algorithm that can use more of the available network links at once. It also compares the 
runtimes of the trivial implementation of broadcasting `my_bcast()` in `bcast.cc` vs `MPI_Bcast()` from MPI. 

# References
[1] https://mpitutorial.com/tutorials/mpi-broadcast-and-collective-communication/