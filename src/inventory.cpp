#include "inventory.h"
#include <iostream>
using namespace std;


void inventory :: addItem(item p, int jumlah)
{	
	//Kamus Lokal
	int i=0;//Iterator
	
	//Method
	do{
		if(p::gettipeItem(slot[i])!=NULL){
			if(p::gettipeItem(slot[i]) == p::gettipeItem(int tipeItem[])){
				total[i]=total[i]+jumlah;}
				i++;
		}else{
			slot[i]= p::gettipeItem(int tipeItem[];
			total[i]=total[i]+jumlah;
			i++;}
	}while (i<=maxslot);
}
	
void inventory :: deleteItem(item p, int jumlah)
{
	//Kamus Lokal
	int j=0;//Iterator
	
	//Method
	do{
		if(p::gettipeItem(slot[j])!=NULL){
			if(p::gettipeItem(slot[j]) == p::gettipeItem(int tipeItem[])){
				total[j]=total[j]-jumlah;}
				i++;
		}else{
			slot[i]= p::gettipeItem(int tipeItem[];
			total[i]=total[i]-jumlah;
			i++;}
	}while (i<=maxslot);
}