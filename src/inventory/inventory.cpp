#include "inventory.h"
#include "../item/item.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

Inventory::Inventory(ifstream& fin)//konstruktor
{
    fin.read((char*)(this),sizeof(Inventory));
    cout << "item0" << fin.tellg() << endl;
    slot[0] = new Item(fin);
    if (slot[0]->getIDitem()==15) {
        cout << slot[0]->getIDitem();
        if (slot[0] != NULL)
        //delete slot[0];
        cout << "pass1";
        slot[0] = NULL;
    }
    cout << "item1" << fin.tellg() << endl;
    slot[1] = new Item(fin);
    if (slot[1]->getIDitem()==15) {
        //delete slot[1];
        slot[1] = NULL;
    }
    cout << "item2" << fin.tellg() << endl;
    slot[2] = new Item(fin);
    if (slot[2]->getIDitem()==15) {
        //delete slot[2];
        slot[2] = NULL;
    }
	maxslot = 3;
}
Inventory::Inventory(){
    slot[0] = NULL;
    slot[1] = NULL;
    slot[2] = NULL;
	maxslot = 3;
}

Inventory::Inventory(const Inventory& inventory)//copy konstruktor
{
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
}

/*int Inventory::listItem()
{
	cout << setw(10) << left << "Nama Item " <<endl; cout << setw(18)<< right << "Effect Buah " <<endl;cout << setw(18)<< right << "Harga Jual item" <<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Kentang" <<endl; cout << setw(18)<< right <<"0"<<endl; cout << setw(18)<< right <<"Rp 720"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Lobak" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 540"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Timun" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 900"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Kubis" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 2.250"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Jagung" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 900"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Tomat" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 540"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Bawang" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 720"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Nanas" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 4.500"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Wortel" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 1080"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Terong" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 720"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Ubi" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 1.080"<<endl;cout <<"\n"<<endl;
	cout << setw(10) << left << "Paprika" <<endl; cout << setw(18)<< right <<""<<endl; cout << setw(18)<< right <<"Rp 360"<<endl;;
return 0;
}
*/
void Inventory::addItem(const string& name, int jumlah)//melakukan penambahan item pada vector
{
    int i = 2; //iterator diinisialisasi = 1
    int temp = -1;
    bool found = false;
    Item * dummyItem = Item::makeBibit(name);
    while ((i >= 0) && (!found)) {
        if (slot[i] != NULL) {
            if((*(slot[i])) == (*dummyItem)) {
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
        slot[temp] = dummyItem;
        total[temp] = jumlah;
    } else {
        delete dummyItem;
    }
}

void Inventory::addItem(Grid_Plant* tanaman, int jumlah) {
    int i = 2;
    int temp = -1;
    bool found = false;

    Item * dummyItem = Item::makeBuah(tanaman);

    while ((i >= 0) && (!found)) {

        if (slot[i] != NULL) {
            if((*slot[i]) == (*dummyItem)) {
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
        slot[temp] = dummyItem;
        total[temp] = jumlah;
    } else {
        delete dummyItem;
    }
}

void Inventory::deleteItem(int noslot, int jumlah)//melakukan penghapusan item pada vector
{
	if (slot[noslot] != NULL) {
		if (total[noslot] > jumlah) {
			total[noslot] = total[noslot]-jumlah;
		} else if (total[noslot] == jumlah) {
			total[noslot] = 0;
			delete slot[noslot];
			slot[noslot] = NULL;
		}
		else {
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
	return (slot[noslot]);
}

int Inventory::getJumlah(int noslot){
    return (total[noslot]);
}

void Inventory::listDescription()//me-list setiap barang yang ada di inventory
{
    int i;
	system("cls");
	cout << endl << "PLAYER INVENTORY: " << endl;
	cout << char(201); for (int i = 1; i <= 11; i++) {cout << char(205);} cout << char(203); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(203); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(203); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(187) << endl;
	cout << char(186) << setw(11) << left << "Nomor Slot" << char(186) << "       1       " << char(186)<< "       2       " << char(186)<< "       3       " << char(186) << endl;
	cout << char(204); for (int i = 1; i <= 11; i++) {cout << char(205);} cout << char(206); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(206); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(206); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(185) << endl;
	cout << char(186) << setw(11) << left << "Nama" << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186) << endl;
	cout << char(199); for (int i = 1; i <= 11; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(182) << endl;
	cout << char(186) << setw(11) << left << "Jenis" << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186) << endl;
	cout << char(199); for (int i = 1; i <= 11; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(182) << endl;
	cout << char(186) << setw(11) << left << "Total" << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186) << endl;
	cout << char(199); for (int i = 1; i <= 11; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(182) << endl;
	cout << char(186) << setw(11) << left << "Musim" << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186) << endl;
	cout << char(199); for (int i = 1; i <= 11; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(182) << endl;
	cout << char(186) << setw(11) << left << "Harga Jual" << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186) << endl;
	cout << char(199); for (int i = 1; i <= 11; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(215); for (int i = 1; i <= 15; i++) {cout << char(196);} cout << char(182) << endl;
	cout << char(186) << setw(11) << left << "Efek Item" << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186); for (int i = 1; i <= 15; i++) {cout << " ";} cout << char(186) << endl;
	cout << char(200); for (int i = 1; i <= 11; i++) {cout << char(205);} cout << char(202); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(202); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(202); for (int i = 1; i <= 15; i++) {cout << char(205);} cout << char(188) << endl;
	for (i=0;i<maxslot;i++){
		if (cekSlot(i)) {
			Item* item = getSlot(i);
			Utilities::getInstances().gotoxy(14+i*16,5); cout << item->getNama();
			Utilities::getInstances().gotoxy(14+i*16,7); if (item->isBibit()) {cout << "BIBIT";} else {cout << "BUAH";}
			Utilities::getInstances().gotoxy(14+i*16,9); cout << total[i];
			Utilities::getInstances().gotoxy(14+i*16,11); if ((item->getIDitem() >= 0) && (item->getIDitem() <= 3)) {cout << "SPRING";} else if ((item->getIDitem() >= 4) && (item->getIDitem() <= 7)) { cout << "SUMMER";} else {cout << "FALL";}
			Utilities::getInstances().gotoxy(14+i*16,13); cout << item->getCostSell();
			Utilities::getInstances().gotoxy(14+i*16,15); cout << item->getEfekBuah();
		}
	}
	Utilities::getInstances().gotoxy(0,17);
	getch();
}
