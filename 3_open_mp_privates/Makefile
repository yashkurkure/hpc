CXX = g++
CXXFLAGS = -Wall -Wextra -fopenmp

all: omp_privates

omp_privates: omp_privates.cc
	$(CXX) $(CXXFLAGS) $< -o $@

omp_privates2: omp_privates2.cc
	$(CXX) $(CXXFLAGS) $< -o omp_privates

omp_privates3: omp_privates3.cc
	$(CXX) $(CXXFLAGS) $< -o omp_privates

clean:
	rm -f omp_privates *.o* *.e*