#include "grid_plant.h"

grid_plant::grid_plant()
{

}

grid_plant::grid_plant(int newTypeTanaman,int newCost,int newHappyMeter,int newTitikDewasa,int newTitikPanen,int newUmur,bool newPanenBerulang)
{
	typetanaman		= newTypeTanaman;
	cost			= newCost;
	happymeter		= newHappyMeter;
	titikdewasa		= newTitikDewasa;
	titikpanen		= newTitikPanen;
	umur			= newUmur;
	panenberulang	= newPanenBerulang;
}

grid_plant::grid_plant(const grid_plant& GP)
{
	typetanaman		= GP.getTypeTanaman();
	cost			= GP.getCost();
	happymeter		= GP.getHappyMeter();
	titikdewasa		= GP.getTitikDewasa();
	titikpanen		= GP.getTitikPanen();
	umur			= GP.getUmur();
	panenberulang	= GP.getPanenBerulang();
}

grid_plant::~grid_plant()
{

}

int	plant::getTypeTanaman() const
// mengeluarkan macam Tanaman.
{
	return typeTanaman;
}

int	plant::getHappyMeter() const
// mengeluarkan tingkat kebahagiaan tanaman.
{
	return happymeter;
}
	
int plant::getCost() const
// mengeluarkan harga tanaman.
{
	return cost;
}

int	plant::getDewasa() const
// mengeluarkan titik dewasa tanaman.
{
	return titikdewasa;
}

int	plant::getPanen() const
// mengeluarkan titik panen tanaman.
{
	return titikpanen;
}

int	plant::getUmur() const
// mengeluarkan umur tanaman.
{
	return umur;
}
	
bool	plant::isWatered() const
// mengeluarkan TRUE jika tanaman sudah disiram.
{
	if getFase()%2 == 1
		return true;
	else
		return false;
}

bool plant::isBibit() const
// mengeluarkan TRUE jika tanaman berupa bibit.
{
	if getFase() == 0 || getFase() == 1
		return true;
	else
		return false;
}

bool isDewasa() const
{
	if getFase() == 2 || getFase() == 3
		return true;
	else
		return false;
}

bool isPanen() const
{
	if getFase() == 4 || getFase() == 5
		return true;
	else
		return false;
}

boolean isPanenBerulang() const
// mengeluarkan TRUE jika tanaman
{
	return panenberulang;
}

void setTypeTanaman(int newTypeTanaman)
// mengeset macam tanaman.
{
	typetanaman		= newTypeTanaman;
}

void setCost(int newCost)
// mengeset harga tanaman.
{
	cost			= newCost;
}

void sethappyMeter(int newHappyMeter)
// mengeset tingkat kebahagiaan tanaman.
{
	happymeter		= newHappyMeter;
}
	
void setTitikDewasa(int newTitikDewasa)
// mengeset titik dewasa tanaman.
{
	titikdewasa		= newTitikDewasa;
}

void setTitikPanen(int newTitikPanen)
// mengeset titik panen tanaman.
{
	titikpanen		= newTitikPanen;
}
	
void setUmur(int newUmur)
// mengeset umur tanaman.
{
	umur			= newUmur;
}

void setPanenBerulang(bool newPanenBerulang)
// mengeset nilai panen berulang.
{
	panenberulang	= newPanenBerulang;
}