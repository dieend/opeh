#include "grid_plant.h"

grid_plant::grid_plant()
{

}

grid_plant::grid_plant(point newPosisi,int newType,int newFase,int newTypeTanaman,int newCost,int newHappyMeter,int newTitikDewasa,int newTitikPanen,int newUmur,bool newPanenBerulang)
{
	setPosisi(newPosisi);
	setType(newType);
	setFase(newFase);
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
	setPosisi(GP.getPosisi());
	setType(GP.getType());
	setFase(G.getFase());
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

int	plant::getTitikDewasa() const
// mengeluarkan titik dewasa tanaman.
{
	return titikdewasa;
}

int	plant::getTitikPanen() const
// mengeluarkan titik panen tanaman.
{
	return titikpanen;
}

int	plant::getUmur() const
// mengeluarkan umur tanaman.
{
	return umur;
}
	
bool plant::isWatered() const
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

bool isPanenBerulang() const
// mengeluarkan TRUE jika tanaman yang dapat berbuah lagi
{
	return panenberulang;
}

void grid_plant::setCangkul();
void grid_plant::setSlash();

void grid_pant::setSiram()
// pengubahan fase tanaman ketika disiram
// instant change
{
	if getFase() != 6 && !isWatered()
		setFase(getFase()+1);
}

void grid_plant::setPanen()
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

void grid_plant::grow()
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

void grid_plant::setTypeTanaman(int newTypeTanaman)
// mengeset macam tanaman.
{
	typetanaman		= newTypeTanaman;
}

void grid_plant::setCost(int newCost)
// mengeset harga tanaman.
{
	cost			= newCost;
}

void grid_plant::sethappyMeter(int newHappyMeter)
// mengeset tingkat kebahagiaan tanaman.
{
	happymeter		= newHappyMeter;
}
	
void grid_plant::setTitikDewasa(int newTitikDewasa)
// mengeset titik dewasa tanaman.
{
	titikdewasa		= newTitikDewasa;
}

void grid_plant::setTitikPanen(int newTitikPanen)
// mengeset titik panen tanaman.
{
	titikpanen		= newTitikPanen;
}
	
void grid_plant::setUmur(int newUmur)
// mengeset umur tanaman.
{
	umur			= newUmur;
}

void grid_plant::setPanenBerulang(bool newPanenBerulang)
// mengeset nilai panen berulang.
{
	panenberulang	= newPanenBerulang;
}