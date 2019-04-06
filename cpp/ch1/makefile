CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean isUnique.o checkPerm.o urlify.o findPalins.o oneAway.o strCompr

isUnique.o: ./src/IsUnique.cpp
	$(CXX) $(CXXFLAGS) ./src/IsUnique.cpp -o isUnique

checkPerm.o: ./src/CheckPerm.cpp
	$(CXX) $(CXXFLAGS) ./src/CheckPerm.cpp -o checkPerm

urlify.o: ./src/Urlify.cpp
	$(CXX) $(CXXFLAGS) ./src/Urlify.cpp -o urlify

findPalins.o: ./src/FindPalins.cpp
	$(CXX) $(CXXFLAGS) ./src/FindPalins.cpp -o findPalins

oneAway.o: ./src/OneAway.cpp
	$(CXX) $(CXXFLAGS) ./src/OneAway.cpp -o oneAway

strCompr.o: ./src/StrCompr.cpp
	$(CXX) $(CXXFLASGS) ./src/StrCompr.cpp -o strCompr

clean:
	rm -f isUnique checkPerm urlify findPalins oneAway strCompr

