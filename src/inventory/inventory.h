#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <fstream>
#include "../item/item.h"
using namespace std;

class Inventory{
//untuk player saja
//deskripsi umum kelas inventory: kelas inventory digunakan untuk melakukan penambahan item, penghapusan item, dan pengecekan isi slot.
private:
    int maxslot;//maksimum slot yang dimiliki oleh player
    int temp;//jumlah barang di dalam array
    Item* slot[3];//array berisi jenis item berukuran maksimum 3
    int total[3];//array berisi jumlah item berukuran maksimum 3

public:
    Inventory(ifstream&);//konstruktor
    Inventory();
    Inventory(const Inventory&);//copy konstruktor
    Inventory& operator= (const Inventory&);//operator assignment
    virtual ~Inventory();//destructor

    int listItem();
    void addItem(const string& name, int jumlah);
    void addItem(Grid_Plant* tanaman, int jumlah);
    void deleteItem(int, int);//melakukan penghapusan item pada vector
    bool cekSlot(int); // ngecek apakah di slot tersebut ada item apa gak. Mengembaikan true jika kosong.
    Item* getSlot(int);
    int getJumlah(int noslot);
    void listDescription();//me-list setiap barang yang ada di inventory
	
};
#endif
