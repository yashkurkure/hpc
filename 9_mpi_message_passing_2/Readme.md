# MPI message passing

Point to Point communication: Mechanism of a pair of processes where one send data and the other receives it.

Functions: MPI_Send() and MPI_Recv()

The message consists of:

- The envelope
	- rank of the receiver: desitnation
	- rank of the sender: source
	- tag: user specified int that can be used to distinguish messages from a single process
	- communicator: MPI Communicator

- The data


# MPI_Send()

def:
```
int MPI_Send(
	void* message,				// The message
	int count,					// Number of instances of the datatype
	MPI_Datatype datatype,		// MPI type datatype
	int dest,					// Rank of the destination process
	int tag,					// User specified to distinguish messages
	MPI_Comm comm				// Communicator group
)

// Example
int data = 42
MPI_Send(&data, 1, MPI_INT, dest, tag, MPI_COMM_WORLD)

```


# MPI Data Types

MPI_CHAR			signed char
MPI_SHORT			signed short int
MPI_INT				int
MPI_LONG			signed long int
MPI_UNSIGNED		unsigned int
MPI_UNSIGNED_LONG	unsigned long
MPI_FLOAT			float
MPI_DOUBLE			double
MPI_LONG_DOUBLE		long double
MPI_BYTE

MPI allows the user to define their own data types (derived datatypes) in the form of C/C++ structs or an array of structs.


# MPI_Recv()

def:
```
int MPI_Recv(
	void* message,				// The message
	int count,					// Number of instances of the datatype
	MPI_Datatype datatype,		// MPI type datatype
	int dest,					// Rank of the destination process
	int tag,					// User specified to distinguish messages
	MPI_Comm comm				// Communicator group
	MPI_Status *status			// Information on the data received
)

// Example
int data = 42
MPI_Send(&data, 1, MPI_INT, dest, tag, MPI_COMM_WORLD)

```