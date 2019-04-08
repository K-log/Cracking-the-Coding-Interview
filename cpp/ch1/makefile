CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean isUnique.o checkPerm.o urlify.o findPalins.o oneAway.o strCompress.o

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

strCompress.o: ./src/StrCompress.cpp
	$(CXX) $(CXXFLASGS) ./src/StrCompress.cpp -o strCompress

clean:
	rm -f isUnique checkPerm urlify findPalins oneAway strCompress

