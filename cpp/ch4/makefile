CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean RouteBetween.o MinTree.o ListOfDepth.o CheckBalanced.o ValidBST.o

RouteBetween.o: ./src/routeBetween.cpp
	$(CXX) $(CXXFLAGS)  ./src/routeBetween.cpp -o RouteBetween

MinTree.o: ./src/minTree.cpp
	$(CXX) $(CXXFLAGS) ./src/minTree.cpp -o MinTree

ListOfDepth.o: ./src/listOfDepth.cpp
	$(CXX) $(CXXFLAGS) ./src/listOfDepth.cpp -o ListOfDepth

CheckBalanced.o: ./src/checkBalanced.cpp
	$(CXX) $(CXXFLAGS) ./src/checkBalanced.cpp -o CheckBalanced

ValidBST.o: ./src/validBST.cpp
	$(CXX) $(CXXFLAGS) ./src/validBST.cpp -o ValidBST

clean:
	rm -f RouteBetween MinTree ListOfDepth CheckBalanced
