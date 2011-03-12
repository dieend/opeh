#include "inventory.h"
#include "../item/item.h"
#include <iostream>
using namespace std;

Inventory::Inventory()//konstruktor
{
	slot[0] = NULL;
	slot[1] = NULL;
	slot[2] = NULL;
}

Inventory::Inventory(const Inventory& inventory)//copy konstruktor
{
	cout <<"cctro"<<endl;
}

Inventory& Inventory::operator= (const Inventory& inventory) {
	maxslot = inventory.maxslot;
	total[0] = 0;
	total[1] = 0;
	total[2] = 0;
	return (*this);
}

Inventory::~Inventory()//destructor
{
	cout<<"dtor Item"<<endl;
}

int Inventory::listItem()
{
	cout << "Nama Item \t" <<endl; cout << "Harga Beli item \t" <<endl;cout << "Harga Jual item \t" <<endl;cout <<"\n"<<endl;
	cout << "Kentang\t" <<endl; cout <<"Rp 150\t"<<endl; cout <<"Rp 720\t"<<endl;cout <<"\n"<<endl;
	cout << "Lobak\t" <<endl; cout <<"Rp 120\t"<<endl; cout <<"Rp 540\t"<<endl;cout <<"\n"<<endl;
	cout << "Timun\t" <<endl; cout <<"Rp 200\t"<<endl; cout <<"Rp 900\t"<<endl;cout <<"\n"<<endl;
	cout << "Kubis\t" <<endl; cout <<"Rp 500\t"<<endl; cout <<"Rp 2.250\t"<<endl;cout <<"\n"<<endl;
	cout << "Jagung\t" <<endl; cout <<"Rp 300\t"<<endl; cout <<"Rp 900\t"<<endl;cout <<"\n"<<endl;
	cout << "Tomat\t" <<endl; cout <<"Rp 200\t"<<endl; cout <<"Rp 540\t"<<endl;cout <<"\n"<<endl;
	cout << "Bawang\t" <<endl; cout <<"Rp 150\t"<<endl; cout <<"Rp 720\t"<<endl;cout <<"\n"<<endl;
	cout << "Nanas\t" <<endl; cout <<"Rp 1.000\t"<<endl; cout <<"Rp 4.500\t"<<endl;cout <<"\n"<<endl;
	cout << "Wortel\t" <<endl; cout <<"Rp 300\t"<<endl; cout <<"Rp 1080\t"<<endl;cout <<"\n"<<endl;
	cout << "Terong\t" <<endl; cout <<"Rp 120\t"<<endl; cout <<"Rp 720\t"<<endl;cout <<"\n"<<endl;
	cout << "Ubi\t" <<endl; cout <<"Rp 300\t"<<endl; cout <<"Rp 1.080\t"<<endl;cout <<"\n"<<endl;
	cout << "Paprika\t" <<endl; cout <<"Rp 150\t"<<endl; cout <<"Rp 360\t"<<endl;;
return 0;
}

void Inventory::addItem(const string& item, int jumlah)//melakukan penambahan item pada vector
{
	int i = 2; //iterator diinisialisasi = 1
	int temp = -1;
	bool found = false;
	Item * dummyItem = new Item(item);
	
	cout << "tes7" << endl;
    while ((i >= 0) && (!found)) {
		if (slot[i] != NULL) {
			if(slot[i]->getTipeBibit() == dummyItem->getTipeBibit()) {
				cout << "tes" << endl;
				total[i] = total[i]+jumlah;
				found = true;
			} else {
				cout << "tes2" << endl;
				i--;
			}
		} else {
			cout << "tes3" << endl;
			temp = i;
			i--;
		}
	}
	if ((!found) && (temp >= 0)) {
		cout << "tes4" << endl;
		slot[temp] = dummyItem;
		total[temp] = jumlah;
	} else {
		cout << "tes5" << endl;
		delete dummyItem;
	}
}

void Inventory::addItem(int item, int jumlah) {
	int i = 2; //iterator diinisialisasi = 1
	int temp = -1;
	bool found = false;
	
    while ((i >= 0) && (!found)) {
		if (slot[i] != NULL) {
			if(slot[i]->getTipeTanaman() == item) {
				total[i] = total[i]+jumlah;
				found = true;
			} else {
				i--;
			}
		} else {
			temp = i;
			i--;
		}
	}
	if ((!found) && (temp >= 0)) {
		slot[temp] = new Item(item);
		total[temp] = jumlah;
	}
}

void Inventory::deleteItem(int item, int jumlah)//melakukan penghapusan item pada vector
{
	if (slot[item] != NULL) {
		if (total[item] > jumlah) {
			total[item] = total[item]-jumlah;
		} else if (total[item] == jumlah) {
			total[item] = 0;
			delete slot[item];
			slot[item] = NULL;
			cout << "tesss" << endl;
		} else {
			throw 2;
		}
	}
}


bool Inventory::cekSlot(int noslot) {
	if(slot[noslot] != NULL)
	{return true;}
	else{
	return false;}
}

Item* Inventory::getSlot(int noslot){
	//cout <<"Didalam slot ke-"<<noslot<<", tersimpan Item "<<slot[noslot]<<" sebanyak = "<<total[noslot]<<endl;
	return (slot[noslot]);
}
