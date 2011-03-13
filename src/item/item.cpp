#include "item.h"

using namespace std;

Item :: Item()
{
	cout<<"ctor Item"<<endl;
}

Item :: ~Item()
{
	cout<<"dtor Item"<<endl;
}

int Item :: getCostBuy() const
{
    return costBuy;
}

int Item :: getCostSell() const
{
	if (bibit) {
		return costSellBibit;
	} else {
		return costSell;
	}
}

int Item :: getTipeBuah() const
{
	return typeBuah;
}

int Item :: getTipeTanaman() const
{
	return typeTanaman;
}

int Item::getEfekBuah() const
{
	return efekBuah;
}

int Item::getEfekTime() const
{
	return efekTime;
}

int Item::getIDitem() const{
    return IDitem;
}

bool Item::isBibit() {
    if (bibit) {
        return true;
    }
    else {
        return false;
    }
}


Item* Item::makeBibit(const string& name){
    Item * item = new Item();
    if(name == "kentang")	{item->setIDitem(0);item->setTypeTanaman(1);item->setTypeBuah(13);item->setEfekBuah(0);item->setEfekTime(0);item->setCostBuy(150);item->setCostSell(720);item->setCostSellBibit(75);item->setBibit(true);}
//    else if(name == "lobak")	{IDitem = 1;typeTanaman = 2;typeBuah = 14;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 540;costSellBibit = 60;bibit=true;}
//    else if(name == "timun")	{IDitem = 2;typeTanaman = 3;typeBuah = 15;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 900;costSellBibit = 100;bibit=true;}
//    else if(name == "kubis")	{IDitem = 3;typeTanaman = 4;typeBuah = 16;efekBuah = 0;efekTime = 0;costBuy = 500;costSell = 2250;costSellBibit = 250;bibit=true;}
//    else if(name == "jagung")	{IDitem = 4;typeTanaman = 5;typeBuah = 17;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 900;costSellBibit = 150;bibit=true;}
//    else if(name == "tomat")	{IDitem = 5;typeTanaman = 6;typeBuah = 18;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 540;costSellBibit = 100;bibit=true;}
//    else if(name == "bawang")	{IDitem = 6;typeTanaman = 7;typeBuah = 19;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 720;costSellBibit = 75;bibit=true;}
//    else if(name == "nanas")	{IDitem = 7;typeTanaman = 8;typeBuah = 20;efekBuah = 0;efekTime = 0;costBuy = 1000;costSell = 4500;costSellBibit = 500;bibit=true;}
//    else if(name == "wortel")	{IDitem = 8;typeTanaman = 9;typeBuah = 21;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;costSellBibit = 150;bibit=true;}
//    else if(name == "terong")	{IDitem = 9;typeTanaman = 10;typeBuah = 22;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 720;costSellBibit = 60;bibit=true;}
//    else if(name == "ubi")		{IDitem = 10;typeTanaman = 11;typeBuah = 23;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;costSellBibit = 150;bibit=true;}
//    else if(name == "paprika")	{IDitem = 11;typeTanaman = 12;typeBuah = 24;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 360;costSellBibit = 75;bibit=true;}
    return item;
}

Item* Item::makeBuah(const Grid_Plant* GP){
    Item* item = new Item();
    if (GP->getTypeTanaman() == 1) {item->setIDitem(12);item->setTypeTanaman(1);item->setTypeBuah(13);item->setEfekBuah(0);item->setEfekTime(0);item->setCostBuy(150);item->setCostSell(720);item->setCostSellBibit(75);item->setBibit(false);}
//    if(item == 1)		{IDitem = 12;typeTanaman = 1;typeBuah = 13;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 720;bibit = false;}
//    else if(item == 2)	{IDitem = 13;typeTanaman = 2;typeBuah = 14;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 540;bibit = false;}
//    else if(item == 3)	{IDitem = 14;typeTanaman = 3;typeBuah = 15;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 900;bibit = false;}
//    else if(item == 4)	{IDitem = 15;typeTanaman = 4;typeBuah = 16;efekBuah = 0;efekTime = 0;costBuy = 500;costSell = 2250;bibit = false;}
//    else if(item == 5)	{IDitem = 16;typeTanaman = 5;typeBuah = 17;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 900;bibit = false;}
//    else if(item == 6)	{IDitem = 17;typeTanaman = 6;typeBuah = 18;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 540;bibit = false;}
//    else if(item == 7)	{IDitem = 18;typeTanaman = 7;typeBuah = 19;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 720;bibit = false;}
//    else if(item == 8)	{IDitem = 19;typeTanaman = 8;typeBuah = 20;efekBuah = 0;efekTime = 0;costBuy = 1000;costSell = 4500;bibit = false;}
//    else if(item == 9)	{IDitem = 20;typeTanaman = 9;typeBuah = 21;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;bibit = false;}
//    else if(item == 10)	{IDitem = 21;typeTanaman = 10;typeBuah = 22;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 720;bibit = false;}
//    else if(item == 11)	{IDitem = 22;typeTanaman = 11;typeBuah = 23;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;bibit = false;}
//    else if(item == 12)	{IDitem = 23;typeTanaman = 12;typeBuah = 24;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 360;bibit = false;}
    return item;
}


void Item::setEfekBuah(int e) {
    efekBuah = e;
}
void Item::setEfekTime(int e){
    efekTime = e;
}
void Item::setCostBuy(int e){
    costBuy = e;
}
void Item::setCostSell(int e){
    costSell = e;
}
void Item::setCostSellBibit(int e){
    costSellBibit = e;
}
void Item::setTypeTanaman(int e){
    typeTanaman = e;
}
void Item::setTypeBuah(int e){
    typeBuah = e;
}
void Item::setIDitem(int e){
    IDitem = e;
}
void Item::setBibit(bool e){
    bibit = e;
}

bool Item::operator==(const Item& item){
    if (IDitem == item.getIDitem()) {
        return true;
    } else return false;
}
