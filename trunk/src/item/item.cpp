#include "item.h"
#include <iostream>
#include <string>
using namespace std;

Item :: Item()
{
	cout<<"ctor Item"<<endl;
}

Item:: Item(const string& item)
{
	if(item == "Kentang")		{typetanaman = 1;typebibit = 1;typebuah = 2;efekbuah = 0;efektime = 0;costbuy = 150;costsell = 720;}
	else if(item == "Lobak")	{typetanaman = 2;typebibit = 3;typebuah = 4;efekbuah = 0;efektime = 0;costbuy = 120;costsell = 540;}
	else if(item == "Timun")	{typetanaman = 3;typebibit = 5;typebuah = 6;efekbuah = 0;efektime = 0;costbuy = 200;costsell = 900;}
	else if(item == "Kubis")	{typetanaman = 4;typebibit = 7;typebuah = 8;efekbuah = 0;efektime = 0;costbuy = 500;costsell = 2250;}
	else if(item == "Jagung")	{typetanaman = 5;typebibit = 9;typebuah = 10;efekbuah = 0;efektime = 0;costbuy = 300;costsell = 900;}
	else if(item == "Tomat")	{typetanaman = 6;typebibit = 11;typebuah = 12;efekbuah = 0;efektime = 0;costbuy = 200;costsell = 540;}
	else if(item == "Bawang")	{typetanaman = 7;typebibit = 13;typebuah = 14;efekbuah = 0;efektime = 0;costbuy = 150;costsell = 720;}
	else if(item == "Nanas")	{typetanaman = 8;typebibit = 15;typebuah = 16;efekbuah = 0;efektime = 0;costbuy = 1000;costsell = 4500;}
	else if(item == "Wortel")	{typetanaman = 9;typebibit = 17;typebuah = 18;efekbuah = 0;efektime = 0;costbuy = 300;costsell = 1080;}
	else if(item == "Terong")	{typetanaman = 10;typebibit = 19;typebuah = 20;efekbuah = 0;efektime = 0;costbuy = 120;costsell = 720;}
	else if(item == "Ubi")		{typetanaman = 11;typebibit = 21;typebuah = 22;efekbuah = 0;efektime = 0;costbuy = 300;costsell = 1080;}
	else if(item == "Paprika")	{typetanaman = 12;typebibit = 23;typebuah = 24;efekbuah = 0;efektime = 0;costbuy = 150;costsell = 360;}
}

Item :: Item(const Item&)
{
	cout<<"cctor Item"<<endl;
}

Item :: ~Item()
{
	cout<<"dtor Item"<<endl;
}

Item :: Item(int item)//untuk mementukan jenis buah
{
	if(item == 1)		{typetanaman = 1;typebibit = 1;typebuah = 2;efekbuah = 0;efektime = 0;costbuy = 150;costsell = 720;}
	else if(item == 2)	{typetanaman = 2;typebibit = 3;typebuah = 4;efekbuah = 0;efektime = 0;costbuy = 120;costsell = 540;}
	else if(item == 3)	{typetanaman = 3;typebibit = 5;typebuah = 6;efekbuah = 0;efektime = 0;costbuy = 200;costsell = 900;}
	else if(item == 4)	{typetanaman = 4;typebibit = 7;typebuah = 8;efekbuah = 0;efektime = 0;costbuy = 500;costsell = 2250;}
	else if(item == 5)	{typetanaman = 5;typebibit = 9;typebuah = 10;efekbuah = 0;efektime = 0;costbuy = 300;costsell = 900;}
	else if(item == 6)	{typetanaman = 6;typebibit = 11;typebuah = 12;efekbuah = 0;efektime = 0;costbuy = 200;costsell = 540;}
	else if(item == 7)	{typetanaman = 7;typebibit = 13;typebuah = 14;efekbuah = 0;efektime = 0;costbuy = 150;costsell = 720;}
	else if(item == 8)	{typetanaman = 8;typebibit = 15;typebuah = 16;efekbuah = 0;efektime = 0;costbuy = 1000;costsell = 4500;}
	else if(item == 9)	{typetanaman = 9;typebibit = 17;typebuah = 18;efekbuah = 0;efektime = 0;costbuy = 300;costsell = 1080;}
	else if(item == 10)	{typetanaman = 10;typebibit = 19;typebuah = 20;efekbuah = 0;efektime = 0;costbuy = 120;costsell = 720;}
	else if(item == 11)	{typetanaman = 11;typebibit = 21;typebuah = 22;efekbuah = 0;efektime = 0;costbuy = 300;costsell = 1080;}
	else if(item == 12)	{typetanaman = 12;typebibit = 23;typebuah = 24;efekbuah = 0;efektime = 0;costbuy = 150;costsell = 360;}
}

int Item :: getcostBuy()
{
    return costbuy;
}

int Item :: getcostSell()
{
	return costsell;
}

int Item :: gettipeBibit()
{
	return typebibit;
}

int Item :: gettipeBuah()
{
	return typebuah;
}

int Item :: gettipeTanaman()
{
	return typetanaman;
}

int Item::getEfekBuah()
{
	return efekbuah;
}

int Item::getEfekTime()
{
	return efektime;
}


