#include "item.h"
#include <iostream>
using namespace std;

Item :: Item()
{
	cout<<"ctor Item"<<endl;
}

Item :: Item(const Item&)
{
	cout<<"cctor Item"<<endl;
}

Item :: ~Item()
{
	cout<<"dtor Item"<<endl;
}

Item :: Item(int)
{
    return type;
}

int Item :: getCost()
{
    return cost;
}

int Item :: gettipeItem()
{
	//Kamus Lokal
    return type;
}