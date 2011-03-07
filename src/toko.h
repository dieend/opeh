#ifndef toko
#define toko
#include "item.h"

class toko{
//deskripsi umum kelas toko: kelas toko digunakan untuk menampilkan vector yang berisi listItem yang dijual di toko 
	//Kamus Global
	
	//Method yang dipakai
	public :
		toko();//konstruktor
		toko(const toko&);//copy konstruktor
		//toko &operator=(const toko&);//operator assignment
		virtual ~toko();
		
		void listItem();//menampilkan isi dari vector 
}

#endif