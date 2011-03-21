#include "../grid/grid_lahan.h"
#include "../helper/util.h"
Grid_Lahan::Grid_Lahan()
{
}
Grid_Lahan::Grid_Lahan(ifstream& fin)
{
    fin.read((char*)(this),sizeof(Grid_Lahan));
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
    cout << "~gridlahan\n";
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
    if (GL->getFase()==PLOW) Utilities::getInstances().setBG(YELLOW);
    if (GL->getFase()==SPLOW) Utilities::getInstances().setBG(LYELLOW);
    if (GL->getFase()==LAND) Utilities::getInstances().setBG(GREEN);
    int xUL = GL->getPosisi().getX()*4+11;
    int yUL = GL->getPosisi().getY()*6+7;
    for (int i=xUL; i<xUL+3;i++){
        for (int j=yUL;j<yUL+5; j++) {
            Utilities::getInstances().gotoxy(j,i);
            c << (char)176;
        }
    }
    Utilities::getInstances().resetBG();
    return c;
}
void Grid_Lahan::grow(int a){
    setFase(LAND);
}
