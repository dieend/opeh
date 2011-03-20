all: mplant

mplant: mplant.o grid.o grid_plant.o util.o point.o
	g++ mplant.o grid.o grid_plant.o util.o point.o -o mplant

mplant.o: mplant.cpp
	g++ -c -Wall mplant.cpp

point.o: ../point/point.cpp
	g++ -c -Wall ../point/point.cpp
	
grid_plant.o: grid_plant.cpp
	g++ -c -Wall grid_plant.cpp

grid.o: grid.cpp
	g++ -c -Wall grid.cpp
	
util.o: ../helper/util.cpp
	g++ -c -Wall ../helper/util.cpp

	

clean:
	rm -rf *.o