CC= gcc
CXX= g++
CXXFLAGS= --std=c++11
INCLUDES=./src/LinkedList.cpp

all: clean RemDups.o KthToLast.o

RemDups.o: ./src/remDups.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/remDups.cpp -o RemDups

KthToLast.o: ./src/kthToLast.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/kthToLast.cpp -o KthToLast

clean:
	rm -f RemDups KthToLast 
