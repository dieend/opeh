#include "grid_lahan.h"

grid_lahan::grid_lahan()
{

}

grid_lahan::grid_lahan(point newPosisi,int newType,int newFase)
{
	setPosisi(newPosisi);
	setType(newType);
	setFase(newFase);
}

grid_lahan::grid_lahan(const grid& GL)
{
	setPosisi(G.getPosisi());
	setType(G.getType());
	setFase(G.getFase());
}

grid_lahan::~grid_lahan()
{

}

void grid_lahan::setCangkul()
// pengubahan fase lahan setelah dicangkul
{
	if getFase() == 0
		setFase(1);
}

void grid_lahan::setSiram();
// pengubahan fase lahan setelah disiram
{
	if getFase() == 1
		setFase(2);
}

void grid_lahan::setPut();
// pengubahan fase lahan setelah ditanam bibit