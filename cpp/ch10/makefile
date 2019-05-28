CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean SortedMerge 

SortedMerge.o: ./src/sortedMerge.cpp
	$(CXX) $(CXXFLAGS) ./src/sortedMerge.cpp -o SortedMerge

GroupAnagrams.o: ./src/GroupAnagrams.cpp
	$(CXX) $(CXXFLAGS) ./src/groupAnagrams.cpp -o GroupAnagrams

clean:
	rm -f SortedMerge GroupAnagrams 
