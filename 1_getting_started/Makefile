CXXFLAGS = -Wall -Wextra -Werror -std=c++11
OPTFLAGS = -O3

prime: prime.cc
	$(CXX) $(CXXFLAGS) $< -o $@

optimusprime: prime.cc
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) $< -o $@

.PHONY: all clean
all:
	make prime
	make optimusprime
	
clean:
	rm -f prime optimusprime prime.csv optimusprime.csv *.o*
