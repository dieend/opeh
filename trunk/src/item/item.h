#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "../grid/grid_plant.h"
using namespace std;

class Item{
//deskripsi umum kelas item: kelas item digunakan untuk memberikan harga dari item dan tipe dari item.
	//Kamus Global
	private:
        int efekBuah;//efek dari buah yang dimakan player
        int costBuy;
        int costSell;
		int costSellBibit;
        int typeTanaman;
        int typeBuah;
        int IDitem;
        bool bibit;
	char nama[32];
	public :
            Item(ifstream&);
        Item (); //konstruktor
        virtual ~Item (); //destructor
        static Item* makeBibit(const string&);
        static Item* makeBuah(const Grid_Plant*);
        bool operator==(const Item&);
        int getCostBuy() const;
        int getCostSell()const;
        int getTipeBuah() const;
        int getTipeTanaman() const;
        int getEfekBuah() const;
        int getIDitem() const;
        string getNama() const;//untuk melakukan deskripsi tiap item
        bool isBibit();
        void setEfekBuah(int);
        void setCostBuy(int);
        void setCostSell(int);
		void setCostSellBibit(int);
        void setTypeTanaman(int);
        void setTypeBuah(int);
        void setIDitem(int);
        void setBibit(bool);
		void setNama(string);
};
#endif
