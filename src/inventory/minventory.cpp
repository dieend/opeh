#include <iostream>
#include "inventory.h"
using namespace std;

int main(){
Inventory I;
Grid_Plant* GP = new Grid_Plant(1);


I.addItem("kentang", 3);
I.addItem("lobak", 2);
I.addItem("timun", 1);
cout <<"\n"<<endl;
I.listDescription();

I.deleteItem(0,3);
cout <<"\n"<<endl;
cout <<"Penambahan Item. Isi slot adalah: "<<endl;
cout <<I.getJumlah(0)<<endl;
cout <<I.getJumlah(1)<<endl;
cout <<I.getJumlah(2)<<"\n"<<endl;

cout <<"Isi slot kosong atau berisi?"<<endl;
cout <<I.cekSlot(0)<<endl;
cout <<I.cekSlot(1)<<endl;
cout <<I.cekSlot(2)<<"\n"<<endl;

cout<<"Penambahan Item: "<<endl;
I.addItem(GP, 10);
cout<<I.getJumlah(0)<<endl;

cout <<"Nama = "<<I.getSlot(1)->getNama()<<endl;
cout <<"Harga Beli = "<<I.getSlot(1)->getCostBuy()<<endl;
cout <<"Harga Jual = "<<I.getSlot(1)->getCostSell()<<endl;
cout <<"Tipe Buah = "<<I.getSlot(1)->getTipeBuah()<<endl;
cout <<"Tipe Tanaman = "<<I.getSlot(1)->getTipeTanaman()<<endl;
cout <<"EfekBuah = "<<I.getSlot(1)->getEfekBuah()<<endl;
cout <<"ID Item = "<<I.getSlot(1)->getIDitem()<<endl;
cout <<"is Bibit = "<<I.getSlot(1)->isBibit()<<endl;

}
