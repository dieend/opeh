#ifndef inventory
#define inventory
#include "../item/item.h"

class Inventory{
//untuk player saja
//deskripsi umum kelas inventory: kelas inventory digunakan untuk melakukan penambahan item, penghapusan item, dan pengecekan isi slot.
    private:
	int maxslot = 3;//maksimum slot yang dimiliki oleh player
	int slot[3];//array berisi jenis item berukuran maksimum 3
	int total[3];//array berisi jumlah item berukuran maksimum 3
    public:
	Inventory();//konstruktor
	Inventory(const Inventory&);//copy konstruktor
	Inventory &operator=(const Inventory&);//operator assignment
	virtual ~Inventory();//destructor
        
	void listItem();
        void addItem(Item p, int jumlah);//melakukan penambahan item pada vector
        void deleteItem(Item p, int jumlah);//melakukan penghapusan item pada vector
};
#endif