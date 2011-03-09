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
                Item(const string&);
		Item(const Item&);//copy konstruktor
                Item(int);
		Item &operator=(const Item&);//operator assignment
		virtual ~Item (); //destructor
		int getCost();//memberikan harga dari item
		int gettipeItem();//memberikan tipe dari item
                int getEfekBuah();
                int getEfekTime();
                ostream& operator<<(ostream&);
                bool isBibit();
};
#endif
