CXX = g++
CXXFLAGS = -Wall -Wextra -fopenmp

all: sch_by_env

sch_by_env: sch_by_env.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f sch_by_env *.o* *.e*