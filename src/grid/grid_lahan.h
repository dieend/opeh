#ifndef _GRID_LAHAN_H
#define	_GRID_LAHAN_H



#endif	/* _GRID_LAHAN_H */

class Grid_Lahan : public Grid
{
	public :
	Grid_Lahan();
	Grid_Lahan(Point,int,int);
	// constructor
	Grid_Lahan(const Grid_Lahan&);
	// copy constructor
	virtual ~Grid_Lahan();
	// destructor

	isWatered();

	void setCangkul();
	// pengubahan fase lahan setelah dicangkul
	void setSiram();
	// pengubahan fase lahan setelah disiram
	void setPut();
	// pengubahan fase lahan setelah ditanam bibit
};
#endif