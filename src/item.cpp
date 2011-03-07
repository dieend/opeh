#include "item.h"
#include <iostream>
using namespace std;

item :: item()
{
	cout<<"ctor item"<<endl; 
}

item :: item(const item&)
{
	cout<<"cctor item"<<endl;
}

virtual item :: ~item()
{
	cout<<"dtor item""<<endl;
}

item :: item(int ,int ,int ,int)
{
	
}

int item :: getcost()
{
	
	//harga mangga		= 2
	//harga apel		= 2
	//harga pepaya		= 3
	//harga anggur		= 4	
	//harga markisa		= 3
	//harga bibit mangga= 1
	//harga bibit apel	= 1
	//harga bibit pepaya= 1
	//harga bibit anggur= 1
	//harga bibit markisa=1
	int tipecost[10] = {2,2,3,4,3,1,1,1,1,1};

	return 0;
}

int item :: gettipeItem()
{
	
	//mangga 		= 1
	//apel 			= 2
	//pepaya		= 3
	//anggur		= 4
	//markisa		= 5
	//bibit mangga	= 6
	//bibit apel	= 7
	//bibit pepaya	= 8
	//bibit anggur	= 9
	//bibit markisa	= 10
	int tipeItem[10] ={1,2,3,4,5,6,7,8,9,10}
	
	return 0;
}