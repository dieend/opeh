all: marea

marea: marea.o world.o toko.o time.o point.o player.o item.o inventory.o grid.o game.o dwarf.o area.o grid_lahan.o grid_plant.o map.o util.o
	g++ marea.o world.o toko.o time.o point.o player.o item.o inventory.o grid.o game.o dwarf.o area.o grid_lahan.o grid_plant.o map.o util.o -o opeh -lwinmm 

marea.o: marea.cpp
	g++ -c -Wall -lwinmm marea.cpp 

world.o: ../world/world.cpp
	g++ -c -Wall -lwinmm ../world/world.cpp
	
toko.o: ../toko/toko.cpp
	g++ -c -Wall -lwinmm ../toko/toko.cpp
	
time.o: ../time/time.cpp
	g++ -c -Wall -lwinmm ../time/time.cpp
	
point.o: ../point/point.cpp
	g++ -c -Wall -lwinmm ../point/point.cpp
	
player.o: ../player/player.cpp
	g++ -c -Wall -lwinmm ../player/player.cpp
	
item.o: ../item/item.cpp
	g++ -c -Wall -lwinmm ../item/item.cpp
	
inventory.o: ../inventory/inventory.cpp
	g++ -c -Wall -lwinmm ../inventory/inventory.cpp
	
grid.o: ../grid/grid.cpp
	g++ -c -Wall -lwinmm ../grid/grid.cpp
	
game.o: ../game/game.cpp
	g++ -c -Wall -lwinmm ../game/game.cpp
	
dwarf.o: ../dwarf/dwarf.cpp
	g++ -c -Wall -lwinmm ../dwarf/dwarf.cpp
	
area.o: ../area/area.cpp
	g++ -c -Wall -lwinmm ../area/area.cpp
	
grid_plant.o: ../grid/grid_plant.cpp
	g++ -c -Wall -lwinmm ../grid/grid_plant.cpp
	
grid_lahan.o: ../grid/grid_lahan.cpp
	g++ -c -Wall -lwinmm ../grid/grid_lahan.cpp

map.o: ../dwarf/map.cpp
	g++ -c -Wall -lwinmm ../dwarf/map.cpp

util.o: ../helper/util.cpp
	g++ -c -Wall -lwinmm ../helper/util.cpp
	
clean:
	rm -rf *.o