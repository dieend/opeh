#include "../grid/grid_lahan.h"

Grid_Lahan::Grid_Lahan()
{

}

Grid_Lahan::Grid_Lahan(Point newPosisi,int newType,int newFase)
{
	setPosisi(newPosisi);
	setType(newType);
	setFase(newFase);
}

Grid_Lahan::Grid_Lahan(const Grid& GL)
{
	setPosisi(GL.getPosisi());
	setType(GL.getType());
	setFase(GL.getFase());
}

Grid_Lahan::~Grid_Lahan()
{

}

void Grid_Lahan::setCangkul()
// pengubahan fase lahan setelah dicangkul
{
	if (getFase() == 0)
		setFase(1);
}

void Grid_Lahan::setSiram()
// pengubahan fase lahan setelah disiram
{
	if (getFase() == 1)
		setFase(2);
}

void Grid_Lahan::setPut(){
// pengubahan fase lahan setelah ditanam bibit
}