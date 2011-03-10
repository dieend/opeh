#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item{
//deskripsi umum kelas item: kelas item digunakan untuk memberikan harga dari item dan tipe dari item.
	//Kamus Global
	private:
		int efekbuah;//efek dari buah yang dimakan player
		int efektime;//lama nya efek dari buah yang dimakan player
        int costbuy;
		int costsell;
        int typetanaman;
		int typebibit;
		int typebuah;
	public :
		Item (); //konstruktor
        Item(const string&);
		Item(const Item&);//copy konstruktor
        Item(int);
		virtual ~Item (); //destructor

		int getcostBuy();
		int getcostSell();
		int gettipeBibit();
		int gettipeBuah();
        int gettipeTanaman();
        int getEfekBuah();
        int getEfekTime();
};
#endif
