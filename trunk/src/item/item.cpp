#include "item.h"
#include <iostream>
#include <string>
using namespace std;

Item :: Item()
{
	cout<<"ctor Item"<<endl;
}

Item :: Item(const string& item)
{
	if(item == "Kentang")		{typeTanaman = 1;typeBibit = 1;typeBuah = 2;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 720;}
	else if(item == "Lobak")	{typeTanaman = 2;typeBibit = 3;typeBuah = 4;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 540;}
	else if(item == "Timun")	{typeTanaman = 3;typeBibit = 5;typeBuah = 6;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 900;}
	else if(item == "Kubis")	{typeTanaman = 4;typeBibit = 7;typeBuah = 8;efekBuah = 0;efekTime = 0;costBuy = 500;costSell = 2250;}
	else if(item == "Jagung")	{typeTanaman = 5;typeBibit = 9;typeBuah = 10;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 900;}
	else if(item == "Tomat")	{typeTanaman = 6;typeBibit = 11;typeBuah = 12;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 540;}
	else if(item == "Bawang")	{typeTanaman = 7;typeBibit = 13;typeBuah = 14;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 720;}
	else if(item == "Nanas")	{typeTanaman = 8;typeBibit = 15;typeBuah = 16;efekBuah = 0;efekTime = 0;costBuy = 1000;costSell = 4500;}
	else if(item == "Wortel")	{typeTanaman = 9;typeBibit = 17;typeBuah = 18;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;}
	else if(item == "Terong")	{typeTanaman = 10;typeBibit = 19;typeBuah = 20;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 720;}
	else if(item == "Ubi")		{typeTanaman = 11;typeBibit = 21;typeBuah = 22;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;}
	else if(item == "Paprika")	{typeTanaman = 12;typeBibit = 23;typeBuah = 24;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 360;}
}

Item :: Item(const Item& item)//copy konstruktor
{
	typeBuah = item.typeBuah;
	typeTanaman = item.typeTanaman;
	typeBibit = item.typeBibit;
	efekBuah = item.efekBuah;
	efekTime = item.efekTime;
	costBuy = item.costBuy;
	costSell = item.costSell;
}

Item :: ~Item()
{
	cout<<"dtor Item"<<endl;
}

Item :: Item(int item)//untuk mementukan jenis buah
{
	if(item == 1)		{typeTanaman = 1;typeBibit = 1;typeBuah = 2;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 720;}
	else if(item == 2)	{typeTanaman = 2;typeBibit = 3;typeBuah = 4;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 540;}
	else if(item == 3)	{typeTanaman = 3;typeBibit = 5;typeBuah = 6;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 900;}
	else if(item == 4)	{typeTanaman = 4;typeBibit = 7;typeBuah = 8;efekBuah = 0;efekTime = 0;costBuy = 500;costSell = 2250;}
	else if(item == 5)	{typeTanaman = 5;typeBibit = 9;typeBuah = 10;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 900;}
	else if(item == 6)	{typeTanaman = 6;typeBibit = 11;typeBuah = 12;efekBuah = 0;efekTime = 0;costBuy = 200;costSell = 540;}
	else if(item == 7)	{typeTanaman = 7;typeBibit = 13;typeBuah = 14;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 720;}
	else if(item == 8)	{typeTanaman = 8;typeBibit = 15;typeBuah = 16;efekBuah = 0;efekTime = 0;costBuy = 1000;costSell = 4500;}
	else if(item == 9)	{typeTanaman = 9;typeBibit = 17;typeBuah = 18;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;}
	else if(item == 10)	{typeTanaman = 10;typeBibit = 19;typeBuah = 20;efekBuah = 0;efekTime = 0;costBuy = 120;costSell = 720;}
	else if(item == 11)	{typeTanaman = 11;typeBibit = 21;typeBuah = 22;efekBuah = 0;efekTime = 0;costBuy = 300;costSell = 1080;}
	else if(item == 12)	{typeTanaman = 12;typeBibit = 23;typeBuah = 24;efekBuah = 0;efekTime = 0;costBuy = 150;costSell = 360;}
}

int Item :: getCostBuy()
{
    return costBuy;
}

int Item :: getCostSell()
{
	return costSell;
}

int Item :: getTipeBibit()
{
	return typeBibit;
}

int Item :: getTipeBuah()
{
	return typeBuah;
}

int Item :: getTipeTanaman()
{
	return typeTanaman;
}

int Item::getEfekBuah()
{
	return efekBuah;
}

int Item::getEfekTime()
{
	return efekTime;
}

bool Item::isBibit() {
	if(Item :: getTipeBibit() == 1||3||5||7||9||11||13||15||17||19||21||23){
    return true;}
}
