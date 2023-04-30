# MPI_Barrier()

A synchronization call. It will block untill all processes in the 
communicator have reached this routine. 

def:
```
int MPI_Barrier(MPI_Comm comm)
```