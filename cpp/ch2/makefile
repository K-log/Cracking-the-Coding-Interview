CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean RemDup.o

RemDup.o: ./src/remDup.cpp
	$(CXX) $(CXXFLAGS) ./src/remDup.cpp -o RemDup

clean:
	rm -f RemDup 
