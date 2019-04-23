CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean SetStacks.o StackQueue.o AnimShelter.o

SetStacks.o: ./src/setStacks.cpp
	$(CXX) $(CXXFLAGS)  ./src/setStacks.cpp -o SetStacks

StackQueue.o: ./src/stackQueue.cpp
	$(CXX) $(CXXFLAGS) ./src/stackQueue.cpp -o StackQueue

AnimShelter.o: ./src/animShelter.cpp
	$(CXX) $(CXXFLAGS) ./src/animShelter.cpp -o AnimShelter

clean:
	rm -f SetStacks StackQueue AnimShelter 
