CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean RouteBetween.o MinTree.o ListOfDepth.o

RouteBetween.o: ./src/routeBetween.cpp
	$(CXX) $(CXXFLAGS)  ./src/routeBetween.cpp -o RouteBetween

MinTree.o: ./src/minTree.cpp
	$(CXX) $(CXXFLAGS) ./src/minTree.cpp -o MinTree

ListOfDepth.o: ./src/listOfDepth.cpp
	$(CXX) $(CXXFLAGS) ./src/listOfDepth.cpp -o ListOfDepth

clean:
	rm -f RouteBetween MinTree ListOfDepth
