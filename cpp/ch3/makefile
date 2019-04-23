CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean SetStacks.o

SetStacks.o: ./src/setStacks.cpp
	$(CXX) $(CXXFLAGS)  ./src/setStacks.cpp -o SetStacks

clean:
	rm -f SetStacks 
