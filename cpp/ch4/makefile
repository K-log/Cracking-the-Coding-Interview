CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean RouteBetween.o MinTree.o 

RouteBetween.o: ./src/routeBetween.cpp
	$(CXX) $(CXXFLAGS)  ./src/routeBetween.cpp -o RouteBetween

MinTree.o: ./src/minTree.cpp
	$(CXX) $(CXXFLAGS) ./src/minTree.cpp -o MinTree

clean:
	rm -f RouteBetween MinTree
