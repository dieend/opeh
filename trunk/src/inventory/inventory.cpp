#include "inventory.h"
#include "../item/item.h"
#include <iostream>
using namespace std;

Inventory::Inventory()//konstruktor
{
    cout<<"ctor Inventory"<<endl;
}

Inventory::Inventory(const Inventory& inventory)//copy konstruktor
{
    maxslot = inventory.maxslot;
    slot[3] = inventory.;
    slot[3] = inventory.;
    total[3] = inventory.temp;
}

Inventory::~Inventory()//destructor
{
	cout<<"dtor Item"<<endl;
}

void Inventory::addItem(const string& item, int jumlah)//melakukan penambahan item pada vector
{
	int temp = 0; //inisialisasi nilai temporary = 0
	int i = 1; //iterator diinisialisasi = 1

	do{
		if(Inventory::cekSlot(i)== true ){//artinya slot kosong
			Item::getTipeBuah() = item;
			temp = temp + jumlah;
		}
		else if(Item::getTipeBuah() == item){//isi slot sama dengan item yang akan ditambahkan
			temp = temp + jumlah;}
		else{ //isi slot tidak sama dengan item yang ingin ditambahkan
			i++;
		}
	}while(i<=3); //looping
}

void Inventory::addItem(int item, int jumlah)//melakukan penambahan item dengan type dan jumlah tertentu
{
	int temp = 0; //inisialisasi nilai temporary = 0
	int i = 1; //iterator diinisialisasi = 1

	do{
		if(Inventory::cekSlot(i)== true ){//artinya slot kosong
			Item::getTipeBuah() = item;
			temp = temp + jumlah;
		}
		else if(Item::getTipeBuah() == item){//isi slot sama dengan item yang akan ditambahkan
			temp = temp + jumlah;}
		else{ //isi slot tidak sama dengan item yang ingin ditambahkan
			i++;
		}
	}while(i<=3); //looping
}

void Inventory::listItem()
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
}

Item* Inventory::getSlot(int){

}


Inventory& Inventory::operator=(const Inventory& inventory) {
    maxslot = inventory.maxslot;
	total[]

	return (*this);
}


bool Inventory::cekSlot(int) {
}

