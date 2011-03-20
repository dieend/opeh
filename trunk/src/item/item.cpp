#include "item.h"
#include <iomanip>
#include <iostream>
using namespace std;


using namespace std;

Item :: Item()
{
}

Item :: ~Item()
{
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
    item->setNama(name);
    if(name == "kentang")	{item->setIDitem(0);item->setTypeTanaman(1);item->setTypeBuah(13);item->setEfekBuah(1);item->setCostBuy(150);item->setCostSell(720);item->setCostSellBibit(75);item->setBibit(true);}
    else if(name == "lobak")	{item->setIDitem(1);item->setTypeTanaman(2);item->setTypeBuah(14);item->setEfekBuah(2);item->setCostBuy(120);item->setCostSell(540);item->setCostSellBibit(60);item->setBibit(true);}
    else if(name == "timun")	{item->setIDitem(2);item->setTypeTanaman(3);item->setTypeBuah(15);item->setEfekBuah(1);item->setCostBuy(200);item->setCostSell(900);item->setCostSellBibit(100);item->setBibit(true);}
    else if(name == "kubis")	{item->setIDitem(3);item->setTypeTanaman(4);item->setTypeBuah(16);item->setEfekBuah(4);item->setCostBuy(500);item->setCostSell(2250);item->setCostSellBibit(250);item->setBibit(true);}
    else if(name == "jagung")	{item->setIDitem(4);item->setTypeTanaman(5);item->setTypeBuah(17);item->setEfekBuah(1);item->setCostBuy(300);item->setCostSell(900);item->setCostSellBibit(150);item->setBibit(true);}
    else if(name == "tomat")	{item->setIDitem(5);item->setTypeTanaman(6);item->setTypeBuah(18);item->setEfekBuah(1);item->setCostBuy(200);item->setCostSell(540);item->setCostSellBibit(100);item->setBibit(true);}
    else if(name == "bawang")	{item->setIDitem(6);item->setTypeTanaman(7);item->setTypeBuah(19);item->setEfekBuah(2);item->setCostBuy(150);item->setCostSell(720);item->setCostSellBibit(75);item->setBibit(true);}
    else if(name == "nanas")	{item->setIDitem(7);item->setTypeTanaman(8);item->setTypeBuah(20);item->setEfekBuah(4);item->setCostBuy(1000);item->setCostSell(4500);item->setCostSellBibit(500);item->setBibit(true);}
    else if(name == "wortel")	{item->setIDitem(8);item->setTypeTanaman(9);item->setTypeBuah(21);item->setEfekBuah(1);item->setCostBuy(300);item->setCostSell(1080);item->setCostSellBibit(150);item->setBibit(true);}
    else if(name == "terong")	{item->setIDitem(9);item->setTypeTanaman(10);item->setTypeBuah(22);item->setEfekBuah(4);item->setCostBuy(120);item->setCostSell(720);item->setCostSellBibit(60);item->setBibit(true);}
    else if(name == "ubi")	{item->setIDitem(10);item->setTypeTanaman(11);item->setTypeBuah(23);item->setEfekBuah(2);item->setCostBuy(300);item->setCostSell(1080);item->setCostSellBibit(150);item->setBibit(true);}
    else if(name == "paprika")	{item->setIDitem(11);item->setTypeTanaman(12);item->setTypeBuah(24);item->setEfekBuah(4);item->setCostBuy(150);item->setCostSell(360);item->setCostSellBibit(75);item->setBibit(true);}
    else {item = NULL;}
	return item;
}

Item* Item::makeBuah(const Grid_Plant* GP){
    Item* item = new Item();
    if (GP->getTypeTanaman() == 1)	{item->setIDitem(12);item->setTypeTanaman(1);item->setTypeBuah(13);item->setEfekBuah(2);item->setCostBuy(150);item->setCostSell(720);item->setCostSellBibit(75);item->setBibit(false);item->setNama("kentang");}
    else if(GP->getTypeTanaman() == 2)	{item->setIDitem(13);item->setTypeTanaman(2);item->setTypeBuah(14);item->setEfekBuah(0);item->setCostBuy(120);item->setCostSell(540);item->setCostSellBibit(60);item->setBibit(false);item->setNama("lobak");}
    else if(GP->getTypeTanaman() == 3)	{item->setIDitem(14);item->setTypeTanaman(3);item->setTypeBuah(15);item->setEfekBuah(1);item->setCostBuy(200);item->setCostSell(900);item->setCostSellBibit(100);item->setBibit(false);item->setNama("timun");}
    else if(GP->getTypeTanaman() == 4)	{item->setIDitem(15);item->setTypeTanaman(4);item->setTypeBuah(16);item->setEfekBuah(3);item->setCostBuy(500);item->setCostSell(2250);item->setCostSellBibit(250);item->setBibit(false);item->setNama("kubis");}
    else if(GP->getTypeTanaman() == 5)	{item->setIDitem(16);item->setTypeTanaman(5);item->setTypeBuah(17);item->setEfekBuah(0);item->setCostBuy(300);item->setCostSell(900);item->setCostSellBibit(150);item->setBibit(false);item->setNama("jagung");}
    else if(GP->getTypeTanaman() == 6)	{item->setIDitem(17);item->setTypeTanaman(6);item->setTypeBuah(18);item->setEfekBuah(0);item->setCostBuy(200);item->setCostSell(540);item->setCostSellBibit(100);item->setBibit(false);item->setNama("tomat");}
    else if(GP->getTypeTanaman() == 7)	{item->setIDitem(18);item->setTypeTanaman(7);item->setTypeBuah(19);item->setEfekBuah(2);item->setCostBuy(150);item->setCostSell(720);item->setCostSellBibit(75);item->setBibit(false);item->setNama("bawang");}
    else if(GP->getTypeTanaman() == 8)	{item->setIDitem(19);item->setTypeTanaman(8);item->setTypeBuah(20);item->setEfekBuah(3);item->setCostBuy(1000);item->setCostSell(4500);item->setCostSellBibit(500);item->setBibit(false);item->setNama("nanas");}
    else if(GP->getTypeTanaman() == 9)	{item->setIDitem(20);item->setTypeTanaman(9);item->setTypeBuah(21);item->setEfekBuah(0);item->setCostBuy(300);item->setCostSell(1080);item->setCostSellBibit(150);item->setBibit(false);item->setNama("wortel");}
    else if(GP->getTypeTanaman() == 10)	{item->setIDitem(21);item->setTypeTanaman(10);item->setTypeBuah(22);item->setEfekBuah(4);item->setCostBuy(120);item->setCostSell(720);item->setCostSellBibit(60);item->setBibit(false);item->setNama("terong");}
    else if(GP->getTypeTanaman() == 11)	{item->setIDitem(22);item->setTypeTanaman(11);item->setTypeBuah(23);item->setEfekBuah(0);item->setCostBuy(300);item->setCostSell(1080);item->setCostSellBibit(150);item->setBibit(false);item->setNama("ubi");}
    else if(GP->getTypeTanaman() == 12)	{item->setIDitem(23);item->setTypeTanaman(12);item->setTypeBuah(24);item->setEfekBuah(4);item->setCostBuy(150);item->setCostSell(360);item->setCostSellBibit(75);item->setBibit(false);item->setNama("paprika");}
    return item;
}


void Item::setEfekBuah(int e) {
    efekBuah = e;
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

void Item::setNama(string newName){
    copy(newName.begin(),newName.end(),nama);
}