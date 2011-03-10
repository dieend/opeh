#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item{
//deskripsi umum kelas item: kelas item digunakan untuk memberikan harga dari item dan tipe dari item.
	//Kamus Global
	private:
		int efekBuah;//efek dari buah yang dimakan player
		int efekTime;//lama nya efek dari buah yang dimakan player
        int costBuy;
		int costSell;
        int typeTanaman;
		int typeBibit;
		int typeBuah;
        bool bibit;
	public :
		Item (); //konstruktor
        Item(const string&);
		Item(const Item&);//copy konstruktor
        Item(int);
		virtual ~Item (); //destructor

		int getCostBuy();
		int getCostSell();
		int getTipeBibit();
		int getTipeBuah();
        int getTipeTanaman();
        int getEfekBuah();
        int getEfekTime();
        bool isBibit();
};
#endif
