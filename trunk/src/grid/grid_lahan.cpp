#include "../grid/grid_lahan.h"
#include "../helper/util.h"
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
	if (getFase() == LAND)
		setFase(0);
}

void Grid_Lahan::setSiram()
// pengubahan fase lahan setelah disiram
{
	if (getFase() == PLOW)
		setFase(1);
}

void Grid_Lahan::setPut(){
// pengubahan fase lahan setelah ditanam bibit
}

ostream& operator<<(ostream& c, Grid_Lahan* GL){
    if (GL->getFase()==PLOW) Utilities::getInstances().setBackground(YELLOW);
    if (GL->getFase()==SPLOW) Utilities::getInstances().setBackground(LYELLOW);
    if (GL->getFase()==LAND) Utilities::getInstances().setBackground(GREEN);
    c << " ";
    return c;
}
void Grid_Lahan::grow(){
    setFase(LAND);
}
