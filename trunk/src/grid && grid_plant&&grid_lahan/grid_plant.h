#ifndef GRID_PLANT
#define GRID_PLANT

#include "grid.h"

class grid_plant : public grid
// merupakan tanaman
{
	private :
	int	typetanaman;
	// macam tanaman.
	int	cost;
	// harga tanaman
	int	happymeter;
	// tingkat kebahagiaan tanaman.
	int	titikdewasa;
	// titik dewasa tanaman.
	int	titikpanen;
	// titik panen tanaman.
	int	umur;
	// umur tanaman.
	bool panenberulang;
	// bernilai TRUE jika merupakan tanaman jenis panen berulang.
	
	public :
	grid_plant();
	grid_plant(point,int,int,int,int,int,int,int,int,bool);
	// constructor
	grid_plant(const grid_plant&);
	// copy constructor
	virtual ~grid_plant();
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
	void setPanen()
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
	void setPanenBerulang(boolean);
	// mengeset nilai panen berulang.
	void grow();
	// mengubah fase pada pergantian hari
}
#endif