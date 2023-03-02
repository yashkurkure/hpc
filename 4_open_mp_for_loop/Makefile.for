CXX = g++
CXXFLAGS = -Wall -Wextra -fopenmp

all: for_example

for_example: for_example.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f for_example *.o* *.e*
