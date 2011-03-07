#ifndef item
#define item

class toko{
//deskripsi umum kelas toko: kelas toko digunakan untuk menampilkan vector yang berisi listItem yang dijual di toko 
	friend class item;
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