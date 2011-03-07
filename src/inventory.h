#ifndef item
#define item

class inventory//untuk player saja
//deskripsi umum kelas inventory: kelas inventory digunakan untuk melakukan penambahan item, penghapusan item, dan pengecekan isi slot.
	friend class item;
	//Kamus Global
	private:
		int maxslot = 3;//maksimum slot yang dimiliki oleh player
		int slot[];//array berisi jenis item berukuran maksimum 3
		int total[];//array berisi jumlah item berukuran maksimum 3
	
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