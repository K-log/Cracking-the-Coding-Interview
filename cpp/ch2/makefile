CC= gcc
CXX= g++
CXXFLAGS= --std=c++11
INCLUDES=./src/LinkedList.cpp

all: clean RemDup.o

RemDup.o: ./src/remDup.cpp
	$(CXX) $(CXXFLAGS) ./src/remDup.cpp -o RemDup

KthToLast.o: ./src/kthToLast.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/kthToLast.cpp -o KthToLast

clean:
	rm -f RemDup 
