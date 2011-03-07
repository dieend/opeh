#include "grid.h"

grid::grid()
{

}

grid::grid(point newPosisi,int newType,int newFase)
{
	posisi 	= newPosisi;
	type 	= newType;
	fase	= newFase;
}

grid::grid(const grid& G)
{
	posisi	= G.getPosisi();
	type	= G.getType();
	fase	= G.getFase();
}

grid::~grid()
{

}

point grid::getPosisi() const
{
	return posisi;
}
	
int	grid::getFase() const
{
	return fase;
}

int	grid::getType() const
{
	return type;
}

boolean grid::isPlantable() const
{
	if type == 0
		return true;
	// lahan diwakilkan oleh int 0
	else
		return false;
}

void grid::setType(int newType)
{
	type = NewType;
}
void grid::setFase(int newFase)
{
	fase = newFase;
}
void setPosisi(point newPosisi)
{
	posisi = newPosisi;
}	