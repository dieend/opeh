#ifndef AREA_H
#define AREA_H


class Area {
private:
	Grid grid[10][10];
	/*
		Merupakan array dari Grid yang berukuran 10x10.
	*/
	
public:
	Area(int& tipe);
	/*
		Constructor Area dengan menginstansiasi typeArea dengan tipe.
		0 rumah, 1 lahan, 2 toko
	*/
	
	Area();
	/*
		Default ctor. typeArea = 0
	*/
	virtual ~Area();
	/*
		virtual dtor
	*/
	Area& operator=(const Area&); // operator=

	const int typeArea;
	/*
		menandakan jenis Area;
	*/
	Grid* getGrid(Point);
	/*
		mengembalikan address grid yang diacu oleh Point
	*/
};
#endif
