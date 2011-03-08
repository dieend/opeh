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

int item :: getcost(int i)
{
	//Kamus Lokal
	int j;
	//Method
	int tipecost[10] = {2,2,3,4,3,1,1,1,1,1};
	if(i = 1){j=tipecost[0];}
	if(i = 2){j=tipecost[1];}
	if(i = 3){j=tipecost[2];}
	if(i = 4){j=tipecost[3];}
	if(i = 5){j=tipecost[4];}
	if(i = 6){j=tipecost[5];}
	if(i = 7){j=tipecost[6];}
	if(i = 8){j=tipecost[7];}
	if(i = 9){j=tipecost[8];}
	if(i = 10){j=tipecost[9];}
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

	return j;
}

int item :: gettipeItem(int i)
{
	//Kamus Lokal
	int i;
	//Method
	int tipeItem[10] ={1,2,3,4,5,6,7,8,9,10}
	if(i = 1){j=tipeItem[0];}
	if(i = 2){j=tipeItem[1];}
	if(i = 3){j=tipeItem[2];}
	if(i = 4){j=tipeItem[3];}
	if(i = 5){j=tipeItem[4];}
	if(i = 6){j=tipeItem[5];}
	if(i = 7){j=tipeItem[6];}
	if(i = 8){j=tipeItem[7];}
	if(i = 9){j=tipeItem[8];}
	if(i = 10){j=tipeItem[9];}
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
	
	return j;
}