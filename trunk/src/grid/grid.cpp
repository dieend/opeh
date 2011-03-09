#include "Grid.h"

Grid::Grid()
{

}

Grid::Grid(Point newPosisi,int newType,int newFase)
{
	posisi 	= newPosisi;
	type 	= newType;
	fase	= newFase;
}

Grid::Grid(const Grid& G)
{
	posisi	= G.getPosisi();
	type	= G.getType();
	fase	= G.getFase();
}

Grid::~Grid()
{

}

Point Grid::getPosisi() const
{
	return posisi;
}
	
int	Grid::getFase() const
{
	return fase;
}

int	Grid::getType() const
{
	return type;
}

bool Grid::isPlantable() const
{
	if (type == 0) return true;	// lahan diwakilkan oleh int 0
	else return false;
}

void Grid::setType(int newType)
{
	type = newType;
}
void Grid::setFase(int newFase)
{
	fase = newFase;
}
void Grid::setPosisi(Point newPosisi)
{
	posisi = newPosisi;
}

Grid::Grid(int,int,int){
}