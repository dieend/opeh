#include "area.h"

Area::Area():typeArea(0) {
}

Area::Area(const Area& area): typeArea(area.typeArea) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			grid[i][j] = area.grid[i][j];
		}
	}	
}

Area::~Area(){
}

Area::Area(int& tipe)
	: typeArea(tipe) {
}

Area Area::factory(int tipe){
	Area* result = new Area(tipe);
	if (tipe == 0) {
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				result->grid[i][j] = 0;
			}
		}
	} else if (tipe == 1) {
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				result->grid[i][j] = 1;
			}
		}
	} else if (tipe == 2) {
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				result->grid[i][j] = 9;
			}
		}
	}
	return (*result);
}

Area& Area::operator=(const Area& area){
	typeArea = area.typeArea;
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			grid[i][j] = area.grid[i][j];
		}
	}
	return (*this);
}
