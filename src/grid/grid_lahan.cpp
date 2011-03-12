#include "../grid/grid_lahan.h"
#include "../helper/color.h"
Grid_Lahan::Grid_Lahan()
{

}

Grid_Lahan::Grid_Lahan(Point newPosisi,int newType,int newFase)
{
	setPosisi(newPosisi);
	setType(newType);
	setFase(newFase);
}

Grid_Lahan::Grid_Lahan(const Grid_Lahan& GL)
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

ostream& operator<<(ostream& c, Grid_Lahan* GL){
    if (GL->getFase()==0) c<<lahan;
    if (GL->getFase()==1) c<<lahan_plowed;
    if (GL->getFase()==2) c<<lahan_watered;
    c << ".";
    c<< white;
    return c;
}
void Grid_Lahan::grow(){
    setFase(0);
}