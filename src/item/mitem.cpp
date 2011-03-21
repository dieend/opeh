#include <iostream>
#include "item.h"


int main(){
Item I;

Grid_Plant* GP = new Grid_Plant(1);
cout <<"---------------Bibit---------------"<<endl;
cout <<"Nama \t\t= \t"<<I.makeBibit("kentang")->getNama()<<endl;
cout <<"Harga Beli \t= \t"<<I.makeBibit("kentang")->getCostBuy()<<endl;
cout <<"Harga Jual \t= \t"<<I.makeBibit("kentang")->getCostSell()<<endl;
cout <<"Tipe Buah \t= \t"<<I.makeBibit("kentang")->getTipeBuah()<<endl;
cout <<"Tipe Tanaman \t= \t"<<I.makeBibit("kentang")->getTipeTanaman()<<endl;
cout <<"Efek Buah \t= \t"<<I.makeBibit("kentang")->getEfekBuah()<<endl;
cout <<"ID Item \t= \t"<<I.makeBibit("kentang")->getIDitem()<<endl;
cout <<"Is Bibit \t= \t"<<I.makeBibit("kentang")->isBibit()<<"\n"<<endl;

cout <<"---------------Buah---------------"<<endl;
cout <<"Nama \t\t= \t"<<I.makeBuah(GP)->getNama()<<endl;
cout <<"Harga Beli \t= \t"<<I.makeBuah(GP)->getCostBuy()<<endl;
cout <<"Harga Jual \t= \t"<<I.makeBuah(GP)->getCostSell()<<endl;
cout <<"Tipe Buah \t= \t"<<I.makeBuah(GP)->getTipeBuah()<<endl;
cout <<"Tipe Tanaman \t= \t"<<I.makeBuah(GP)->getTipeTanaman()<<endl;
cout <<"Efek Buah \t= \t"<<I.makeBuah(GP)->getEfekBuah()<<endl;
cout <<"ID Item \t= \t"<<I.makeBuah(GP)->getEfekBuah()<<endl;
cout <<"Is Bibit \t= \t"<<I.makeBuah(GP)->isBibit()<<endl; 

}
