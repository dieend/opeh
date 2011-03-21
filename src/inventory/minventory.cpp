#include <iostream>
#include "inventory.h"
using namespace std;

int main(){
Inventory I;
Grid_Plant* GP = new Grid_Plant(1);


I.addItem("kentang", 3);
I.addItem("lobak", 2);
I.addItem("timun", 1);

I.listDescription();

I.deleteItem(0,3);
cout <<"Penambahan Item ke dalam Inventory.\nIsi inventory adalah: "<<endl;
cout <<"Slot-1: "<<I.getJumlah(0)<<endl;
cout <<"Slot-2: "<<I.getJumlah(1)<<endl;
cout <<"Slot-3: "<<I.getJumlah(2)<<"\n"<<endl;

cout <<"Isi slot kosong atau berisi?"<<endl;
cout <<I.cekSlot(0)<<endl;
cout <<I.cekSlot(1)<<endl;
cout <<I.cekSlot(2)<<"\n"<<endl;

cout<<"Penambahan Item: "<<endl;
I.addItem(GP, 10);
cout<<I.getJumlah(0)<<endl;
cout <<"\n"<<endl;

cout <<"-----------Cek Isi Slot----------"<<endl;
cout <<"Nama \t\t= \t"<<I.getSlot(1)->getNama()<<endl;
cout <<"Harga Beli \t= \t"<<I.getSlot(1)->getCostBuy()<<endl;
cout <<"Harga Jual \t= \t"<<I.getSlot(1)->getCostSell()<<endl;
cout <<"Tipe Buah \t= \t"<<I.getSlot(1)->getTipeBuah()<<endl;
cout <<"Tipe Tanaman \t= \t"<<I.getSlot(1)->getTipeTanaman()<<endl;
cout <<"EfekBuah \t= \t"<<I.getSlot(1)->getEfekBuah()<<endl;
cout <<"ID Item \t= \t"<<I.getSlot(1)->getIDitem()<<endl;
cout <<"is Bibit \t= \t"<<I.getSlot(1)->isBibit()<<endl;

}
