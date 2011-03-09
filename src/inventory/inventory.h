#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include "../item/item.h"
using namespace std;

class Inventory{
//untuk player saja
//deskripsi umum kelas inventory: kelas inventory digunakan untuk melakukan penambahan item, penghapusan item, dan pengecekan isi slot.
    private:
	int maxslot;//maksimum slot yang dimiliki oleh player
	Item* slot[3];//array berisi jenis item berukuran maksimum 3
	int total[3];//array berisi jumlah item berukuran maksimum 3
    public:
	Inventory();//konstruktor
	Inventory(const Inventory&);//copy konstruktor
	Inventory& operator= (const Inventory&);//operator assignment
	virtual ~Inventory();//destructor
        
	void listItem();
        void addItem(string, int jumlah);//melakukan penambahan item pada vector
        void addItem(int p, int jumlah);//melakukan penambahan item pada vector
        void deleteItem(int, int jumlah);//melakukan penghapusan item pada vector
        bool cekSlot(int); // ngecek apakah di slot tersebut ada item apa gak.
        Item* getSlot(int);
};
#endif
