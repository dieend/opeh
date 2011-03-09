#include "grid_plant.h"

Grid_Plant::Grid_Plant()
{

}

Grid_Plant::Grid_Plant(Point newPosisi,int newType,int newFase,int newTypeTanaman,int newCost,int newSeason,int newHappyMeter,int newTitikDewasa,int newTitikPanen,int newUmur,bool newPanenBerulang)
{
	setPosisi(newPosisi);
	setType(newType);
	setFase(newFase);
	typeTanaman		= newTypeTanaman;
	cost			= newCost;
	season			= newSeason;
	happyMeter		= newHappyMeter;
	titikDewasa		= newTitikDewasa;
	titikPanen		= newTitikPanen;
	umur			= newUmur;
	panenBerulang	= newPanenBerulang;
}

Grid_Plant::Grid_Plant(const Grid_Plant& GP)
{
	setPosisi(GP.getPosisi());
	setType(GP.getType());
	setFase(GP.getFase());
	typeTanaman		= GP.getTypeTanaman();
	cost			= GP.getCost();
	season			= GP.getSeason();
	happyMeter		= GP.getHappyMeter();
	titikDewasa		= GP.getTitikDewasa();
	titikPanen		= GP.getTitikPanen();
	umur			= GP.getUmur();
	panenBerulang	= GP.isPanenBerulang();
}

Grid_Plant::~Grid_Plant()
{

}

int	Grid_Plant::getTypeTanaman() const
// mengeluarkan macam Tanaman.
{
	return typeTanaman;
}

int	Grid_Plant::getHappyMeter() const
// mengeluarkan tingkat kebahagiaan tanaman.
{
	return happyMeter;
}

int Grid_Plant::getCost() const
// mengeluarkan harga tanaman.
{
	return cost;
}

int Grid_Plant::getSeason() const
// mengeluarkan musim tanaman
{
	return season;
}
int	Grid_Plant::getTitikDewasa() const
// mengeluarkan titik dewasa tanaman.
{
	return titikDewasa;
}

int	Grid_Plant::getTitikPanen() const
// mengeluarkan titik panen tanaman.
{
	return titikPanen;
}

int	Grid_Plant::getUmur() const
// mengeluarkan umur tanaman.
{
	return umur;
}

bool Grid_Plant::isWatered() const
// mengeluarkan TRUE jika tanaman sudah disiram.
{
	if (getFase()%2 == 1)
		return true;
	else
		return false;
}

bool Grid_Plant::isBibit() const
// mengeluarkan TRUE jika tanaman berupa bibit.
{
	if (getFase() == 0 || getFase() == 1)
		return true;
	else
		return false;
}

bool Grid_Plant::isDewasa() const
{
	if (getFase() == 2 || getFase() == 3)
		return true;
	else
		return false;
}

bool Grid_Plant::isPanen() const
{
	if (getFase() == 4 || getFase() == 5)
		return true;
	else
		return false;
}

bool Grid_Plant::isPanenBerulang() const
// mengeluarkan TRUE jika tanaman yang dapat berbuah lagi
{
	return panenBerulang;
}


void Grid_Plant::setSiram()
// pengubahan fase tanaman ketika disiram
// instant change
{
	if (getFase() != 6 && !isWatered())
		setFase(getFase()+1);
}

void Grid_Plant::setPanen()
// pengubahan fase tanaman ketika dipanen
// instant change
{
	if (isPanenBerulang())
		{
		setFase(3);
		setHappyMeter(titikPanen);
		if (titikDewasa + 1 != titikPanen)
			setTitikPanen(titikPanen-1);
		}
	else
		setFase(6);
}

void Grid_Plant::grow()
// mengubah fase pada pergantian hari
// not instant change
{
	setUmur(umur-1);
	if (isWatered())
		setHappyMeter(happyMeter+1);
	else
		setHappyMeter(happyMeter-1);
	if (umur == 0)
		setFase(6);
	else
		{
		if (isBibit())
			{
			if (happyMeter == titikDewasa)
				setFase(getFase()+1);
			else
				setFase(getFase()-1);
			}
		else if (isDewasa())
			{
			if (happyMeter == titikPanen)
				setFase(getFase()+1);
			else
				setFase(getFase()-1);
			}
		}
}

void Grid_Plant::setTypeTanaman(int newTypeTanaman)
// mengeset macam tanaman.
{
	typeTanaman		= newTypeTanaman;
}

void Grid_Plant::setCost(int newCost)
// mengeset harga tanaman.
{
	cost			= newCost;
}

void Grid_Plant::setHappyMeter(int newHappyMeter)
// mengeset tingkat kebahagiaan tanaman.
{
	happyMeter		= newHappyMeter;
}

void Grid_Plant::setTitikDewasa(int newTitikDewasa)
// mengeset titik dewasa tanaman.
{
	titikDewasa		= newTitikDewasa;
}

void Grid_Plant::setTitikPanen(int newTitikPanen)
// mengeset titik panen tanaman.
{
	titikPanen		= newTitikPanen;
}

void Grid_Plant::setUmur(int newUmur)
// mengeset umur tanaman.
{
	umur			= newUmur;
}

void Grid_Plant::setPanenBerulang(bool newPanenBerulang)
// mengeset nilai panen berulang.
{
	panenBerulang	= newPanenBerulang;
}