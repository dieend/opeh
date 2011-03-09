#ifndef AREA_H
#define AREA_H
#include "../helper/color.h"
#include "../grid/grid.h"
#include "../point/point.h"
#include <iostream>
#include <string>
using namespace std;

class Area {
private:
	Grid * grid[10][10];
	/* Merupakan array dari Grid yang berukuran 10x10.
	*/
public:
	const int typeArea;
	/* menandakan jenis Area;
	*/
        int getType();
	Area(int tipe);
	/*  Constructor Area dengan menginstansiasi typeArea dengan tipe.
		0 rumah, 1 lahan, 2 toko
		juga menginstansiasi grid dengan tipe jalan.
	*/
	// Area(const Area&);
	Area();
	/* Default ctor. typeArea = 0
	*/
	virtual ~Area();
	/* virtual dtor
	*/
	Grid* getGrid(Point);
	/* mengembalikan address grid yang diacu oleh Point
	*/
	Grid* getGrid(int,int);
	friend ostream& operator<<(ostream&,Area&);
	
};
#endif
