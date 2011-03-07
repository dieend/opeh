#ifndef GRID
#define GRID

#include "point.h"

class grid
// merupakan kotak-kotak pembentuk area
{
	private :
	point posisi;
	// posisi grid.
	int	type;
	// macam-macam grid.
	// 0 = lahan
	// 1 = dwarf atau player
	// 2 = jalan
	// 3 = toko
	// 4 = tanaman
	// 5 = bed
	// 6 = save
	// 7 = selling box
	// 8 = inventory box
	// 9 = unstepable (meja,dinding,barang2)
	int	fase;
	// fase grid.
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
	grid();
	grid(point,int,int);
	// constructor
	grid(int,int,int);
	// copy constructor dengan parameter x,y, dan tipe. fase dibuat 0.
	grid(const grid&);
	// copy constructor
	virtual ~grid();
	// destructor
	
	point getPosisi() const;
	// mengeluarkan posisi grid.
	int	getType() const;
	// mengeluarkan type grid.
	int	getFase() const;
	// mengeluarkan fase gird.
	boolean	isPlantable() const;
	// mengeluarkan nilai kebenaran apakah grid dapat ditanami atau tidak.
	
	
	void setType(int);
	// mengeset type grid.
	void setFase(int);
	// mengeset fase grid.
	void setPosisi(point);
	// mengeset posisi grid.
};
#endif

