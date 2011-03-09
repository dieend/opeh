#include "grid_plant.h"

Grid_Plant::Grid_Plant()
{

}

Grid_Plant::Grid_Plant(Point newPosisi,int newType,int newFase,int newTypeTanaman,int newCost,int newSeason,int newHappyMeter,int newTitikDewasa,int newTitikPanen,int newUmur,bool newPanenBerulang)
{
	setPosisi(newPosisi);
	setType(newType);
	setFase(newFase);
	typetanaman		= newTypeTanaman;
	cost			= newCost;
	season			= newSeason;
	happymeter		= newHappyMeter;
	titikdewasa		= newTitikDewasa;
	titikpanen		= newTitikPanen;
	umur			= newUmur;
	panenberulang	= newPanenBerulang;
}

Grid_Plant::Grid_Plant(const Grid_Plant& GP)
{
	setPosisi(GP.getPosisi());
	setType(GP.getType());
	setFase(G.getFase());
	typetanaman		= GP.getTypeTanaman();
	cost			= GP.getCost();
	season			= GP.getSeason();
	happymeter		= GP.getHappyMeter();
	titikdewasa		= GP.getTitikDewasa();
	titikpanen		= GP.getTitikPanen();
	umur			= GP.getUmur();
	panenberulang	= GP.getPanenBerulang();
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
	return happymeter;
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
	return titikdewasa;
}

int	Grid_Plant::getTitikPanen() const
// mengeluarkan titik panen tanaman.
{
	return titikpanen;
}

int	Grid_Plant::getUmur() const
// mengeluarkan umur tanaman.
{
	return umur;
}
	
bool Grid_Plant::isWatered() const
// mengeluarkan TRUE jika tanaman sudah disiram.
{
	if getFase()%2 == 1
		return true;
	else
		return false;
}

bool Grid_Plant::isBibit() const
// mengeluarkan TRUE jika tanaman berupa bibit.
{
	if getFase() == 0 || getFase() == 1
		return true;
	else
		return false;
}

bool Grid_Plant::isDewasa() const
{
	if getFase() == 2 || getFase() == 3
		return true;
	else
		return false;
}

bool Grid_Plant::isPanen() const
{
	if getFase() == 4 || getFase() == 5
		return true;
	else
		return false;
}

bool Grid_Plant::isPanenBerulang() const
// mengeluarkan TRUE jika tanaman yang dapat berbuah lagi
{
	return panenberulang;
}

void Grid_Plant::setCangkul();
void Grid_Plant::setSlash();

void Grid_Plant::setSiram()
// pengubahan fase tanaman ketika disiram
// instant change
{
	if getFase() != 6 && !isWatered()
		setFase(getFase()+1);
}

void Grid_Plant::setPanen()
// pengubahan fase tanaman ketika dipanen
// instant change
{
	if isPanenBerulang()
		{
		setFase(3);
		setHappyMeter(titikpanen);
		if titikdewasa + 1 != titikpanen
			setTitikPanen(titikpanen-1);
		}
	else
		setFase(6);
}

void Grid_Plant::grow()
// mengubah fase pada pergantian hari
// not instant change
{
	setUmur(umur-1);
	if isWatered
		setHappyMeter(happymeter+1);
	else
		setHappyMeter(happymeter-1);
	if umur == 0
		setFase(6);
	else
		{
		if isBibit()
			{
			if happymeter == titikdewasa
				setFase(getFase()+1);
			else
				setFase(getFase()-1);
			}
		else if isDewasa()
			{
			if happymeter == titikpanen
				setFase(getFase()+1);
			else
				setFase(getFase()-1);
			}
		}
}

void Grid_Plant::setTypeTanaman(int newTypeTanaman)
// mengeset macam tanaman.
{
	typetanaman		= newTypeTanaman;
}

void Grid_Plant::setCost(int newCost)
// mengeset harga tanaman.
{
	cost			= newCost;
}

void Grid_Plant::sethappyMeter(int newHappyMeter)
// mengeset tingkat kebahagiaan tanaman.
{
	happymeter		= newHappyMeter;
}
	
void Grid_Plant::setTitikDewasa(int newTitikDewasa)
// mengeset titik dewasa tanaman.
{
	titikdewasa		= newTitikDewasa;
}

void Grid_Plant::setTitikPanen(int newTitikPanen)
// mengeset titik panen tanaman.
{
	titikpanen		= newTitikPanen;
}
	
void Grid_Plant::setUmur(int newUmur)
// mengeset umur tanaman.
{
	umur			= newUmur;
}

void Grid_Plant::setPanenBerulang(bool newPanenBerulang)
// mengeset nilai panen berulang.
{
	panenberulang	= newPanenBerulang;
}