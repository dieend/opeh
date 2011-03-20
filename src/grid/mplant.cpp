#include "grid_plant.h"
#include "../point/point.h"


int main() {
	Point P(0,0);
	Grid_Plant* GL = new Grid_Plant(P,GTANAMAN, BIBIT,1);
	cout << GL;
	delete GL;
	return 0;
}