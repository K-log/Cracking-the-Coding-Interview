CC= gcc
CXX= g++
CXXFLAGS= --std=c++11
INCLUDES=./src/LinkedList.cpp

all: clean RemDups.o KthToLast.o DelMid.o Partition.o SumLists.o IsPalin.o

RemDups.o: ./src/remDups.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/remDups.cpp -o RemDups

KthToLast.o: ./src/kthToLast.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/kthToLast.cpp -o KthToLast

DelMid.o: ./src/delMidNode.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/delMidNode.cpp -o DelMid

Partition.o: ./src/partition.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/partition.cpp -o Partition

SumLists.o: ./src/sumLists.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/sumLists.cpp -o SumLists

IsPalin.o: ./src/isPalin.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./src/isPalin.cpp -o IsPalin

clean:
	rm -f RemDups KthToLast DelMid Partition SumLists IsPalin 
