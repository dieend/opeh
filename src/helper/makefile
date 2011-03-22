all: tes

tes: util.o testcolor.o
	g++ util.o testcolor.o -o opeh

util.o: util.cpp
	g++ -c util.cpp

testcolor.o: testcolor.cpp
	g++ -c testcolor.cpp