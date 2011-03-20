#include "grid_plant.h"
#include "../point/point.h"


int main() {
	Point P(0,0);
	Utilities::getInstances().setColor(GREEN,GRAY);
	Grid_Plant* GL = new Grid_Plant(P,GTANAMAN, DEWASA,5);
	cout << GL;
	delete GL;
	Utilities::getInstances().resetColor();
	return 0;
}