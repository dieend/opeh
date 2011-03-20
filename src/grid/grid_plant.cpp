#include "grid_plant.h"
#define SPRING 0
#define SUMMER 1
#define FALL 2

Grid_Plant::Grid_Plant()
{

}
Grid_Plant::Grid_Plant(Point p,int ntype,int nfase, int tanaman)
{
    setType(ntype);
    setPosisi(p);
    setFase(nfase);
    typeTanaman = tanaman;
    if (tanaman == 1) {
        season			   = SPRING;
        happyMeter		 = 0;
        titikDewasa		= 5;
        titikPanen		 = 8;
        umur			     = 10;
        panenBerulang  = false;
    } else if (tanaman == 2){
        season			   = SPRING;
	happyMeter		 = 0;
        titikDewasa		= 2;
        titikPanen		 = 5;
        umur			     = 8;
        panenBerulang  = false;
    } else if (tanaman == 3){
        season			   = SPRING;
	happyMeter		 = 0;
        titikDewasa		= 5;
        titikPanen		 = 10;
        umur			     = 25;
        panenBerulang  = true;
    } else if (tanaman == 4){
        season			   = SPRING;
	happyMeter		 = 0;
        titikDewasa		= 10;
        titikPanen		 = 15;
        umur			     = 20;
        panenBerulang  = false;
    } else if (tanaman == 5){
        season			   = SUMMER;
	happyMeter		 = 0;
        titikDewasa		= 12;
        titikPanen		 = 15;
        umur			     = 25;
        panenBerulang  = true;
    } else if (tanaman == 6){
        season			   = SUMMER;
	happyMeter		 = 0;
        titikDewasa		= 7;
        titikPanen		 = 10;
        umur			     = 20;
        panenBerulang  = true;
    } else if (tanaman == 7){
        season			   = SUMMER;
	happyMeter		 = 0;
        titikDewasa		= 5;
        titikPanen		 = 8;
        umur			     = 12;
        panenBerulang  = false;
    } else if (tanaman == 8){
        season			   = SUMMER;
	happyMeter		 = 0;
        titikDewasa		= 16;
        titikPanen		 = 21;
        umur			     = 30;
        panenBerulang  = true;
    } else if (tanaman == 9){
        season			   = FALL;
	happyMeter		 = 0;
        titikDewasa		= 5;
        titikPanen		 = 8;
        umur			     = 12;
        panenBerulang  = false;
    } else if (tanaman == 10){
        season			   = FALL;
	happyMeter		 = 0;
        titikDewasa		= 7;
        titikPanen		 = 10;
        umur			     = 20;
        panenBerulang  = true;
    } else if (tanaman == 11){
        season			   = FALL;
	happyMeter		 = 0;
        titikDewasa		= 3;
        titikPanen		 = 6;
        umur			     = 20;
        panenBerulang  = true;
    } else if (tanaman == 12){
        season			   = SUMMER;
	happyMeter		 = 0;
        titikDewasa		= 6;
        titikPanen		 = 8;
        umur			     = 20;
        panenBerulang  = true;
    }
}

//Grid_Plant::Grid_Plant(Point newPosisi,int newType,int newFase,int newTypeTanaman,int newCost,int newSeason,int newHappyMeter,int newTitikDewasa,int newTitikPanen,int newUmur,bool newPanenBerulang)
//{
//	setPosisi(newPosisi);
//	setType(newType);
//	setFase(newFase);
//	typeTanaman		= newTypeTanaman;
//	cost			= newCost;
//	season			= newSeason;
//	happyMeter		= newHappyMeter;
//	titikDewasa		= newTitikDewasa;
//	titikPanen		= newTitikPanen;
//	umur			= newUmur;
//	panenBerulang           = newPanenBerulang;
//}

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
	if (getFase() % 2 == 1) {
		return true;
	} else {
		return false;
	}
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
	if ((getFase() != MATI) && (!isWatered()))
		setFase(getFase()+1);
}

void Grid_Plant::setPanen()
// pengubahan fase tanaman ketika dipanen
// instant change
{
	if (isPanenBerulang()) {
		if (getFase() == SDEWASA) {
			setFase(SREMAJA);
		} else {
			setFase(REMAJA);
		}
		setHappyMeter(titikDewasa);
		if (happyMeter + 1 != titikPanen) {
				setTitikPanen(titikPanen-1);
		}
	} else {
		setFase(6);
    }
}

void Grid_Plant::grow(int newCurrentSeason)
// mengubah fase pada pergantian hari
// not instant change
{
	setUmur(umur-1);
	if (isWatered())
		setHappyMeter(happyMeter+1);
	else
		setHappyMeter(happyMeter-1);
	if (umur == 0)
		{
		if (isBibit())
			setFase(DBIBIT);
		else
			setFase(MATI);
		}
            else if (newCurrentSeason != season)
		{
		if (isBibit())
			setFase(DBIBIT);
		else
			setFase(MATI);
		}
	else
		{
		if (isBibit())
			{
			if (happyMeter == titikDewasa)
				setFase(REMAJA);
			else
				setFase(BIBIT);
			}
		else if (isDewasa())
			{
			if (happyMeter == titikPanen)
				setFase(DEWASA);
			else
				setFase(REMAJA);
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

ostream& operator<<(ostream& c, Grid_Plant* GP)
{
	int xUL = GP->getPosisi().getX()*4+10;
	int yUL = GP->getPosisi().getY()*6+7;
    if (GP->getFase() == BIBIT)
		{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " ... ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " ... ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " ... ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
        }
	else if (GP->getFase() == SBIBIT) 
		{
			Utilities::getInstances().setFG(LYELLOW);
            Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " ... ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " ... ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " ... ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().setFG(LYELLOW);
        }
	else if (GP->getFase() == DBIBIT) 
		{
			Utilities::getInstances().setBG(BLACK);
            Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " ... ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " ... ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " ... ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
        }
	else if (GP->getTypeTanaman() == 1)
		{
        if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " (o) ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " (o) ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "sssss";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "((o))";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "sssss";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "((o))";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "sssss";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "((o))";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 2)
		{
        if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " |_| ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " \\ / ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " |_| ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " \\ / ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " \\ / ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  -  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " \\ /";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  -  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " \\ / ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  -  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 3)
		{
        if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "II II";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "II II";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "__ __";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "II II";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "II II";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "__ __";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "II II";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "II II";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "__ __";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "II II";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "II II";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 4)
		{
	
    if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " dOb ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "     ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " dOb ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "     ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  Q  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " QOQ ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  Q  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  Q  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " QOQ ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  Q  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  Q  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " QOQ ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  Q  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 5)
		{		
		if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  0  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  0  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "~(0)~";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "~(0)~";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "~(0)~";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 6)
		{
        if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " (_) ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " (_) ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " _|_ ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "(___)";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " _|_ ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "(___)";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (0) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "~(0)~";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		}
	else if (GP->getTypeTanaman() == 7)
		{
        if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "  i  ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "()-()";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "  i  ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "()-()";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (_) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "(___)";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (_) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "(___)";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (_) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "(___)";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 8)
		{
        if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "|(_)|";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "|---|";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "|(_)|";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "|---|";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " ___ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "||_||";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " --- ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " ___ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "||_||";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " --- ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " ___ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "||_||";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " --- ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 9)
		{
        if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "\\___/";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " \\_/ ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "     ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "\\___/";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " \\_/ ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "\\___/";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " \\_/ ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "\\___/";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " \\_/ ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "|___|";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "\\___/";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " \\_/ ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 10)
		{
		if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " | | ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " (_) ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " | | ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " (_) ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  &  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "!| |!";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "((_))";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  &  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "!| |!";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "((_))";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  &  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "!| |!";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "((_))";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
	else if (GP->getTypeTanaman() == 11)
		{
		if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  /\\ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " | | ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  _  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  /\\ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " | | ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  _  ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  /\\ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "d| |b";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " i_i ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  /\\ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "d| |b";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " i_i ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  /\\ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "d| |b";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " i_i ";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
    else if (GP->getTypeTanaman() == 12)
		{
		if (GP->getFase() == REMAJA)
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (_) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "()_()";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SREMAJA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (_) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "()_()";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == DEWASA) 
			{
			Utilities::getInstances().setBG(YELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " (_) ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "()_()";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == SDEWASA) 
			{
			Utilities::getInstances().setBG(LYELLOW);
			Utilities::getInstances().setFG(GREEN);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "{(_)} ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "{)_(}";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}
		else if (GP->getFase() == MATI) 
			{
			Utilities::getInstances().setBG(BLACK);
			Utilities::getInstances().setFG(BLACK);
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  _  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << "{(_)} ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "{)_(}";
			Utilities::getInstances().resetFG();
			Utilities::getInstances().resetBG();
			}		
	    }
}
Grid_Plant::Grid_Plant(int newTypeItem)
{
	if (newTypeItem == 1)
		{
		//	nama			: Kentang
		//	type tanaman	: 1
		//  type bibit		: 1
		//	cost buy		: 150
		//  cost sell		: 720
		//	season			: 1
		//	happymeter		: 0
		//	titikdewasa		: 5
		//	titikpanen		: 8
		//	umur			: 10
		//	panenberulang	: false
		setType(4);
		setFase(0);
		typeTanaman		= 1;
		cost			= 720;
		season			= 1;
		happyMeter		= 0;
		titikDewasa		= 5;
		titikPanen		= 8;
		umur			= 10;
		panenBerulang	= false;
		}
	else if (newTypeItem == 3)
		{
		//	nama			: Lobak
		//	type tanaman	: 2
		//  type bibit		: 3
		//  cost sell		: 540
		//	season			: 1
		//	happymeter		: 0
		//	titikdewasa		: 2
		//	titikpanen		: 5
		//	umur			: 8
		//	panenberulang	: false
		setType(4);
		setFase(0);
		typeTanaman		= 2;
		cost			= 540;
		season			= 1;
		happyMeter		= 0;
		titikDewasa		= 2;
		titikPanen		= 5;
		umur			= 8;
		panenBerulang	= false;
		}
	else if (newTypeItem == 5)
		{
		//	nama			: Timun
		//	type tanaman	: 3
		//  type bibit		: 5
		//  cost sell		: 900
		//	season			: 1
		//	happymeter		: 0
		//	titikdewasa		: 5
		//	titikpanen		: 10
		//	umur			: 25
		//	panenberulang	: true
		setType(4);
		setFase(0);
		typeTanaman		= 3;
		cost			= 900;
		season			= 1;
		happyMeter		= 0;
		titikDewasa		= 5;
		titikPanen		= 10;
		umur			= 25;
		panenBerulang	= true;
		}
	else if (newTypeItem == 7)
		{
		//	nama			: Kubis
		//	type tanaman	: 4
		//  type bibit		: 7
		//  cost sell		: 2250
		//	season			: 1
		//	happymeter		: 0
		//	titikdewasa		: 10
		//	titikpanen		: 15
		//	umur			: 20
		//	panenberulang	: false
		setType(4);
		setFase(0);
		typeTanaman		= 4;
		cost			= 2250;
		season			= 1;
		happyMeter		= 0;
		titikDewasa		= 10;
		titikPanen		= 15;
		umur			= 20;
		panenBerulang	= false;
		}
	else if (newTypeItem == 9)
		{
		//	nama			: Jagung
		//	type tanaman	: 5
		//  type bibit		: 9
		//  cost sell		: 900
		//	season			: 2
		//	happymeter		: 0
		//	titikdewasa		: 12
		//	titikpanen		: 15
		//	umur			: 25
		//	panenberulang	: true
		setType(4);
		setFase(0);
		typeTanaman		= 5;
		cost			= 900;
		season			= 2;
		happyMeter		= 0;
		titikDewasa		= 12;
		titikPanen		= 15;
		umur			= 25;
		panenBerulang	= true;
		}
	else if (newTypeItem == 11)
		{
		//	nama			: Tomat
		//	type tanaman	: 6
		//  type bibit		: 11
		//  cost sell		: 540
		//	season			: 2
		//	happymeter		: 0
		//	titikdewasa		: 7
		//	titikpanen		: 10
		//	umur			: 20
		//	panenberulang	: true
		setType(4);
		setFase(0);
		typeTanaman		= 6;
		cost			= 540;
		season			= 2;
		happyMeter		= 0;
		titikDewasa		= 7;
		titikPanen		= 10;
		umur			= 20;
		panenBerulang	= true;
		}
	else if (newTypeItem == 13)
		{
		//	nama			: Bawang
		//	type tanaman	: 7
		//  type bibit		: 13
		//  cost sell		: 720
		//	season			: 2
		//	happymeter		: 0
		//	titikdewasa		: 5
		//	titikpanen		: 8
		//	umur			: 12
		//	panenberulang	: false
		setType(4);
		setFase(0);
		typeTanaman		= 7;
		cost			= 720;
		season			= 2;
		happyMeter		= 0;
		titikDewasa		= 5;
		titikPanen		= 8;
		umur			= 12;
		panenBerulang	= false;
		}
	else if (newTypeItem == 15)
		{
		//	nama			: Nanas
		//	type tanaman	: 8
		//  type bibit		: 15
		//  cost sell		: 4500
		//	season			: 2
		//	happymeter		: 0
		//	titikdewasa		: 16
		//	titikpanen		: 21
		//	umur			: 30
		//	panenberulang	: true
		setType(4);
		setFase(0);
		typeTanaman		= 8;
		cost			= 4500;
		season			= 1;
		happyMeter		= 0;
		titikDewasa		= 16;
		titikPanen		= 21;
		umur			= 30;
		panenBerulang	= true;
		}
	else if (newTypeItem == 17)
		{
		//	nama			: Wortel
		//	type tanaman	: 9
		//  type bibit		: 17
		//  cost sell		: 1080
		//	season			: 3
		//	happymeter		: 0
		//	titikdewasa		: 5
		//	titikpanen		: 8
		//	umur			: 12
		//	panenberulang	: false
		setType(4);
		setFase(0);
		typeTanaman		= 9;
		cost			= 1080;
		season			= 3;
		happyMeter		= 0;
		titikDewasa		= 5;
		titikPanen		= 6;
		umur			= 12;
		panenBerulang	= false;
		}
	else if (newTypeItem == 19)
		{
		//	nama			: Terong
		//	type tanaman	: 10
		//  type bibit		: 19
		//  cost sell		: 720
		//	season			: 3
		//	happymeter		: 0
		//	titikdewasa		: 7
		//	titikpanen		: 10
		//	umur			: 20
		//	panenberulang	: true
		setType(4);
		setFase(0);
		typeTanaman		= 10;
		cost			= 720;
		season			= 3;
		happyMeter		= 0;
		titikDewasa		= 7;
		titikPanen		= 10;
		umur			= 20;
		panenBerulang	= true;
		}
	else if (newTypeItem == 21)
		{
		//	nama			: Ubi
		//	type tanaman	: 11
		//  type bibit		: 21
		//  cost sell		: 1080
		//	season			: 3
		//	happymeter		: 0
		//	titikdewasa		: 3
		//	titikpanen		: 6
		//	umur			: 20
		//	panenberulang	: true
		setType(4);
		setFase(0);
		typeTanaman		= 11;
		cost			= 1080;
		season			= 3;
		happyMeter		= 0;
		titikDewasa		= 3;
		titikPanen		= 6;
		umur			= 20;
		panenBerulang	= true;
		}
	else if (newTypeItem == 23)
		{
		//	nama			: Paprika
		//	type tanaman	: 12
		//  type bibit		: 23
		//  cost sell		: 360
		//	season			: 3
		//	happymeter		: 0
		//	titikdewasa		: 6
		//	titikpanen		: 8
		//	umur			: 20
		//	panenberulang	: true
		setType(4);
		setFase(0);
		typeTanaman		= 12;
		cost			= 360;
		season			= 3;
		happyMeter		= 0;
		titikDewasa		= 6;
		titikPanen		= 8;
		umur			= 20;
		panenBerulang	= true;
		}
}
