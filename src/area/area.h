#ifndef AREA_H
#define AREA_H
#include "../helper/util.h"
#include "../grid/grid.h"
#include "../point/point.h"
#include "../player/player.h"
#include "../dwarf/dwarf.h"
#include <iostream>
#include <string>
#define MAXROW 10
#define MAXCOLUMN 10
#define RUMAH 0
#define LAHAN 1
#define TOKO 2
#define G(i,j,n) grid[(i)][(j)]=new Grid((i),(j),(n))

using namespace std;

class Player;
class Dwarf;
class Area {
private:
	Grid * grid[10][10];
        Player* player;
        Dwarf* dwarf[3];
//        Player* player();
	/* Merupakan array dari Grid yang berukuran 10x10.
	*/
public:
	const int typeArea;
	/* menandakan jenis Area;
	*/
        Player* getPlayer();
        Dwarf* getDwarf(int);
        void setPlayer(Player*);
        void setDwarf(int, Dwarf*);
        int getType();
	Area(int tipe);
	/*  Constructor Area dengan menginstansiasi typeArea dengan tipe.
		0 rumah, 1 lahan, 2 toko
		juga menginstansiasi grid dengan tipe jalan.
	*/
	// Area(const Area&);
	Area();
//        Player* getPlayer();
//        void setPlayer(Player* p);
	/* Default ctor. typeArea = 0
	*/
	virtual ~Area();
	/* virtual dtor
	*/
	Grid* getGrid(Point);
	/* mengembalikan address grid yang diacu oleh Point
	*/
	Grid* getGrid(int,int);
        virtual void setGrid(Grid*);
	friend ostream& operator<<(ostream&, Area*);
};


#endif
