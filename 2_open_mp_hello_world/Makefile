CXX = g++
CXXFLAGS = -Wall -Wextra -fopenmp

all: hello_world

hello_world: hello_world.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f hello_world *.o* *.e*