#ifndef GRID_LAHAN
#define GRID_LAHAN

#include "grid.h"

class grid_lahan : public grid
{
	public :
	grid_lahan();
	grid_lahan(point,int,int);
	// constructor
	grid_plant(const grid_lahan&);
	// copy constructor
	virtual ~grid_lahan();
	// destructor
	
	isWatered();
	
	void setCangkul();
	// pengubahan fase lahan setelah dicangkul
	void setSiram();
	// pengubahan fase lahan setelah disiram
	void setPut();
	// pengubahan fase lahan setelah ditanam bibit
}