CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean SortedMerge SearchRotArr

SortedMerge.o: ./src/sortedMerge.cpp
	$(CXX) $(CXXFLAGS) ./src/sortedMerge.cpp -o SortedMerge

GroupAnagrams.o: ./src/GroupAnagrams.cpp
	$(CXX) $(CXXFLAGS) ./src/groupAnagrams.cpp -o GroupAnagrams

SearchRotArr.o: ./src/searchRotArr.cpp
	$(CXX) $(CXXFLAGS) ./src/searchRotArr.cpp -o SearchRotArr

clean:
	rm -f SortedMerge SearchRotArr

