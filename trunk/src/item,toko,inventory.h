#ifndef item
#define item


class item{
//desktripsi umum kelas item: kelas item digunakan untuk memberikan harga dari item dan tipe dari item.
	//Kamus Global
	private:
		int cost;//harga dari item
		int tipeItem;//tipe dari item
		int efekbuah;//efek dari buah yang dimakan player
		int efektime;//lama nya efek dari buah yang dimakan player
		
	public :
		item (); //konstruktor
		item(const item&);//copy konstruktor
		item &operator=(const item&);//operator assignment
		virtual ~item (); //destructor
		
		int getcost();//memberikan harga dari item
		int gettipeItem();//memberikan tipe dari item
}

class toko{
//deskripsi umum kelas toko: kelas toko digunakan untuk menampilkan vector yang berisi listItem yang dijual di toko 
	friend class item;
	//Kamus Global
	private:
		vector<item> tampil;
		
	public :
		toko();//konstruktor
		toko(const toko&);//copy konstruktor
		toko &operator=(const toko&);//operator assignment
		virtual ~toko();
		
		void listItem();//menampilkan isi dari vector 
}

class inventory//untuk player saja
//deskripsi umum kelas inventory: kelas inventory digunakan untuk melakukan penambahan item, penghapusan item, dan pengecekan isi slot.
	friend class item;
	//Kamus Global
	private:
		int maxslot;//maksimum slot yang bisa diisi oleh player
		vector<int> jumlah;//vector yang berisi list jumlah item yang berada di inventory
		vector<item> slot;//vector yang berisi list jenis item yang berada di inventory
	
	public:
		inventory();//konstruktor
		inventory(const inventory&);//copy konstruktor
		inventory &operator=(const inventory&);//operator assignment
		virtual ~inventory();//destructor
		
		void addItem(item p, int jumlah);//melakukan penambahan item pada vector
		void deleteItem(item p, int jumlah);//melakukan penghapusan item pada vector
		int cekslot(int nomorslot);//mengecek isi dari vector, apakah kosong, berisi atau penuh 
}
#endif