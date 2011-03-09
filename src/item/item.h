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
                int cost;
                int type;
                bool bibit;
	public :
		Item (); //konstruktor
		Item(const Item&);//copy konstruktor
                Item(int);
                Item(string);
		Item &operator=(const Item&);//operator assignment
		virtual ~Item (); //destructor
		int getcost(int );//memberikan harga dari item
		int gettipeItem(int );//memberikan tipe dari item
                int getEfekBuah(int);
                int getEfekTime(int);
                ostream& operator<<();
                bool isBibit();
                int getCost;
};
#endif
