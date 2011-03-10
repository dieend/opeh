#ifndef GRID_PLANT
#define GRID_PLANT

#include "grid.h"

class Grid_Plant : public Grid
// merupakan tanaman
{
	private :
	int	typeTanaman;
	// macam tanaman.
	int	cost;
	// harga tanaman
	int season;
	// jenis musim tanaman
	int	happyMeter;
	// tingkat kebahagiaan tanaman.
	int	titikDewasa;
	// titik dewasa tanaman.
	int	titikPanen;
	// titik panen tanaman.
	int	umur;
	// umur tanaman.
	bool panenBerulang;
	// bernilai TRUE jika merupakan tanaman jenis panen berulang.
	
	public :
	Grid_Plant();
        Grid_Plant(int);
	Grid_Plant(Point,int,int,int,int,int,int,int,int,int,bool);
	// constructor
	Grid_Plant(const Grid_Plant&);
	// copy constructor
	virtual ~Grid_Plant();
	// destructor
	int	getTypeTanaman() const;
	// mengeluarkan macam Tanaman.
	int getCost() const;
	// mengeluarkan harga tanaman.
	int	getHappyMeter() const;
	// mengeluarkan tingkat kebahagiaan tanaman.
	int	getTitikDewasa() const;
	// mengeluarkan titik dewasa tanaman.
	int	getTitikPanen() const;
	// mengeluarkan titik panen tanaman.
	int	getUmur() const;
	// mengeluarkan umur tanaman.
        int     getSeason() const;
        

	bool isWatered() const;
	// mengeluarkan TRUE jika tanaman sudah disiram.
	bool isBibit() const;
	// mengeluarkan TRUE jika tanaman berupa bibit.
	bool isDewasa() const;
	// mengeluarkan TRUE jika tanaman
	bool isPanen() const;
	// mengeluarkan TRUE jika tanaman
	bool isPanenBerulang() const;
	// mengeluarkan TRUE jika tanaman
	
	void setCangkul();
	void setSlash();
	void setSiram();
	// pengubah fase tanaman ketika disiram
	void setPanen();
	// pengubahan fase tanaman ketika dipanen
	void setTypeTanaman(int);
	// mengeset macam tanaman.
	void setHappyMeter(int);
	// mengeset tingkat kebahagiaan tanaman.
	void setCost(int);
	// mengeset harga tanaman;
	void setTitikDewasa(int);
	// mengeset titik dewasa tanaman.
	void setTitikPanen(int);
	// mengeset titik panen tanaman.
	void setUmur(int);
	// mengeset umur tanaman.
	void setPanenBerulang(bool);
	// mengeset nilai panen berulang.
	void grow();
	// mengubah fase pada pergantian hari
        friend ostream& operator<<(ostream&, Grid_Plant*);
};
#endif