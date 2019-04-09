CC= gcc
CXX= g++
CXXFLAGS= --std=c++11

all: clean IsUnique.o CheckPerm.o Urlify.o FindPalins.o OneAway.o StrCompress.o RotMatrix.o ZeroMatrix.o RotString.o

IsUnique.o: ./src/isUnique.cpp
	$(CXX) $(CXXFLAGS) ./src/isUnique.cpp -o IsUnique

CheckPerm.o: ./src/checkPerm.cpp
	$(CXX) $(CXXFLAGS) ./src/checkPerm.cpp -o CheckPerm

Urlify.o: ./src/urlify.cpp
	$(CXX) $(CXXFLAGS) ./src/urlify.cpp -o Urlify

FindPalins.o: ./src/findPalins.cpp
	$(CXX) $(CXXFLAGS) ./src/findPalins.cpp -o FindPalins

OneAway.o: ./src/oneAway.cpp
	$(CXX) $(CXXFLAGS) ./src/oneAway.cpp -o OneAway

StrCompress.o: ./src/strCompress.cpp
	$(CXX) $(CXXFLAGS) ./src/strCompress.cpp -o StrCompress

RotMatrix.o: ./src/rotMatrix.cpp
	$(CXX) $(CXXFLAGS) ./src/rotMatrix.cpp -o RotMatrix

ZeroMatrix.o: ./src/zeroMatrix.cpp
	$(CXX) $(CXXFLAGS) ./src/zeroMatrix.cpp -o ZeroMatrix

RotString.o: ./src/rotString.cpp
	$(CXX) $(CXXFLAGS) ./src/rotString.cpp -o RotString

clean:
	rm -f IsUnique CheckPerm Urlify FindPalins OneAway StrCompress

