#ifndef item
#define item

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