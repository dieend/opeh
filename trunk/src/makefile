all: opeh

opeh: main.o world.o toko.o time.o point.o player.o item.o inventory.o grid.o game.o dwarf.o area.o grid_lahan.o grid_plant.o
	g++ main.o world.o toko.o time.o point.o player.o item.o inventory.o grid.o game.o dwarf.o area.o grid_lahan.o grid_plant.o -o opeh

main.o: main.cpp
	g++ -c -Wall main.cpp

world.o: world/world.cpp
	g++ -c -Wall world/world.cpp
	
toko.o: toko/toko.cpp
	g++ -c -Wall toko/toko.cpp
	
time.o: time/time.cpp
	g++ -c -Wall time/time.cpp
	
point.o: point/point.cpp
	g++ -c -Wall point/point.cpp
	
player.o: player/player.cpp
	g++ -c -Wall player/player.cpp
	
item.o: item/item.cpp
	g++ -c -Wall item/item.cpp
	
inventory.o: inventory/inventory.cpp
	g++ -c -Wall inventory/inventory.cpp
	
grid.o: grid/grid.cpp
	g++ -c -Wall grid/grid.cpp
	
game.o: game/game.cpp
	g++ -c -Wall game/game.cpp
	
dwarf.o: dwarf/dwarf.cpp
	g++ -c -Wall dwarf/dwarf.cpp
	
area.o: area/area.cpp
	g++ -c -Wall area/area.cpp
	
grid_plant.o: grid/grid_plant.cpp
	g++ -c -Wall grid/grid_plant.cpp
	
grid_lahan.o: grid/grid_lahan.cpp
	g++ -c -Wall grid/grid_lahan.cpp

clean:
	rm -rf *.o