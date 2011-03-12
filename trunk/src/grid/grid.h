#ifndef GRID_H
#define GRID_H
#include "../point/point.h"
#include <iostream>
#define GLAHAN 0
#define GPLAYER 1
#define GJALAN 2
#define GSTORE 3
#define GTANAMAN 4
#define GBED 5
#define GSAVE 6
#define GSELLINGBOX 7
#define GINVBOX 8
#define GUNSTEP 9

	// 1 = dwarf atau player
	// 2 = jalan
	// 3 = toko
	// 4 = tanaman
	// 5 = bed
	// 6 = save
	// 7 = selling box
	// 8 = inventory box
	// 9 = unstepable (meja,dinding,barang2)
using namespace std;

class Grid
// merupakan kotak-kotak pembentuk area
{
	Point posisi;
	// posisi Grid.
	int	type;
	// macam-macam Grid.
	
	int	fase;
	// fase Grid.
	// lahan kosong
	// 0 = belum dicangkul
	// 1 = sudah dicangkul
	// 2 = sudah dicangkul sudah disiram
	// tanaman
	// 0 = bibit belum disiram
	// 1 = bibit sudah disiram
	// 2 = tanaman dewasa belum disiram
	// 3 = tanaman dewasa sudah disiram
	// 4 = tanaman panen belum disiram
	// 5 = tanaman panen sudah disiram
	// 6 = tanaman mati atau habis panen
	
	
	public :
	Grid();
	Grid(Point,int,int);
	// constructor
	Grid(int,int,int);
	// copy constructor dengan parameter x,y, dan tipe. fase dibuat 0.
	Grid(const Grid&);
	// copy constructor
	virtual ~Grid();
	// destructor
	
	Point getPosisi() const;
	// mengeluarkan posisi Grid.
	int	getType() const;
	// mengeluarkan type Grid.
	int	getFase() const;
	// mengeluarkan fase gird.
	bool isPlantable() const;
	// mengeluarkan nilai kebenaran apakah Grid dapat ditanami atau tidak.
	
        virtual void grow();
	void setType(int);
	// mengeset type Grid.
	void setFase(int);
	// mengeset fase Grid.
	void setPosisi(Point);
	// mengeset posisi Grid.
};
#endif

