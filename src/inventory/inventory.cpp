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
	cout <<"cctro"<<endl;
}

Inventory& Inventory::operator=(const Inventory& inventory) {
	// maxslot = inventory.maxslot;
	//total[]

	//return (*this);
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
int i = 0; //iterator diinisialisasi = 1
for(i=0;i<=2;i++){
    if (slot[i]!=0){
        if(item == "Kentang"||"Lobak"||"Timun"||"Kubis"||"Jagung"||"Tomat"||"Bawang"||"Nanas"||"Wortel"||"Terong"||"Ubi"||"Paprika"){
            total[i] = total[i]+jumlah;}
}
for(i=0;i<=2;i++){
    if(slot[i]==0){
    slot[i] = new Item(item);
    total[i] = jumlah;
    }
}
}}

void Inventory::addItem(int item, int jumlah){
int i = 0; //iterator diinisialisasi = 1
for(i=0;i<=2;i++){
    if (slot[i]!=0){
        if(item == (1||2||3||4||5||6||7||8||9||10||11||12||13||14||15||16||17||18||19||20||21||22||23||24)){
            total[i] = total[i]+jumlah;}
}
}
for(i=0;i<=2;i++){
    if(slot[i]==0){
    slot[i] = new Item(item);
    total[i] = jumlah;
    }
}
}

void Inventory::deleteItem(int item, int jumlah)//melakukan penghapusan item pada vector
{
    int i = 0; //iterator diinisialisasi = 1
    for(i=0;i<=2;i++){
        if (slot[i]!=0){
            if(item == (1||2||3||4||5||6||7||8||9||10||11||12||13||14||15||16||17||18||19||20||21||22||23||24)){
                total[i] = total[i]-jumlah;}
        }
    }
}


bool Inventory::cekSlot(int noslot) {
	if(total[noslot] != (1||2||3||4||5||6||7||8||9||10||11||12||13||14||15||16||17||18||19||20||21||22||23||24))
	{return false;}
	else{
	return true;}
}

Item* Inventory::getSlot(int noslot){
	cout <<"Didalam slot ke-"<<noslot<<", tersimpan Item "<<slot[noslot]<<" sebanyak = "<<total[noslot]<<endl;
}
