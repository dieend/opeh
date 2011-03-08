#ifndef inventory
#define inventory
#include "item.h"

class inventory{
//untuk player saja
//deskripsi umum kelas inventory: kelas inventory digunakan untuk melakukan penambahan item, penghapusan item, dan pengecekan isi slot.


	private:
		int maxslot = 3;//maksimum slot yang dimiliki oleh player
		int slot[3];//array berisi jenis item berukuran maksimum 3
		int total[3];//array berisi jumlah item berukuran maksimum 3
		void listItem();
	public:
		inventory();//konstruktor
		inventory(const inventory&);//copy konstruktor
		inventory &operator=(const inventory&);//operator assignment
		virtual ~inventory();//destructor
		
		void addItem(item p, int jumlah);//melakukan penambahan item pada vector
		void deleteItem(item p, int jumlah);//melakukan penghapusan item pada vector
}
#endif