#ifndef AREA_H
#define AREA_H


class Area {
public:
	int grid[10][10]; // ini harusnya class Grid
	Area(int& tipe);
	Area(const Area&);
	Area();
	~Area();
	Area& operator=(const Area&);
	static Area factory(int);
	int typeArea;
};
#endif
