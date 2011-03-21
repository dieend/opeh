#include <iostream>
#include "item.h"


int main(){
Item I;

Grid_Plant* GP = new Grid_Plant(1);
cout <<"Nama = "<<I.makeBibit("kentang")->getNama()<<endl;
cout <<"Harga Beli= "<<I.makeBibit("kentang")->getCostBuy()<<endl;
cout <<"Harga Jual = "<<I.makeBibit("kentang")->getCostSell()<<endl;
cout <<"Tipe Buah = "<<I.makeBibit("kentang")->getTipeBuah()<<endl;
cout <<"Tipe Tanaman = "<<I.makeBibit("kentang")->getTipeTanaman()<<endl;
cout <<"Efek Buah = "<<I.makeBibit("kentang")->getEfekBuah()<<endl;
cout <<"ID Item = "<<I.makeBibit("kentang")->getIDitem()<<endl;
cout <<"Is Bibit = "<<I.makeBibit("kentang")->isBibit()<<"\n"<<endl;


cout <<"Nama = "<<I.makeBuah(GP)->getNama()<<endl;
cout <<"Harga Beli= "<<I.makeBuah(GP)->getCostBuy()<<endl;
cout <<"Harga Jual = "<<I.makeBuah(GP)->getCostSell()<<endl;
cout <<"Tipe Buah = "<<I.makeBuah(GP)->getTipeBuah()<<endl;
cout <<"Tipe Tanaman = "<<I.makeBuah(GP)->getTipeTanaman()<<endl;
cout <<"Efek Buah = "<<I.makeBuah(GP)->getEfekBuah()<<endl;
cout <<"ID Item = "<<I.makeBuah(GP)->getEfekBuah()<<endl;
cout <<"Is Bibit = "<<I.makeBuah(GP)->isBibit()<<endl; 

}