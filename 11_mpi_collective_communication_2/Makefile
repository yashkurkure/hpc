SHELL := /bin/bash

# Set the C++ compiler
CXX = mpic++

# Set the compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Werror -g

all: bcast

bcast: bcast.cc
	# @if ! command -v $(CXX) &> /dev/null; then \
	# 	echo "Error: $(CXX) not found. Please load an appropriate MPI module (e.g. OpenMPI or MPICH)." >&2; \
	# 	exit 1; \
	# fi
	@echo "Compiling bcast.cc..."
	module load OpenMPI; \
	$(CXX) $(CXXFLAGS) -o bcast bcast.cc
	@echo "Done."

clean:
	@echo "Cleaning up..."
	rm bcast
	@echo "Done."

cleanout:
	@echo "Cleaning up outputs..."
	rm *.out *.err
	@echo "Done."
