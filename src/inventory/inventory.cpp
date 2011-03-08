#include "inventory.h"
#include <iostream>
using namespace std;


void inventory :: addItem(int p, int jumlah)
{	
	//Kamus Lokal
	int i=0;//Iterator
	item r;//sebuah objek berkelas item
	int total=0;//inisialisasi nilai variabel total=0
	
	//Method
	do{
		if(r.gettipeItem(slot[i])!=NULL){
			if(r.gettipeItem(slot[i]) == r.gettipeItem(p){
				total[i]=total[i]+jumlah;}
			else{
					i++;
				}
		}else{
			slot[i]= r.gettipeItem(p);
			total[i]=total[i]+jumlah;}
	}while(i<=maxslot);
}
	
void inventory :: deleteItem(int p, int jumlah)
{
	//Kamus Lokal
	int i=0;//Iterator
	item r;//sebuah objek berkelas item
	int total=0;//inisialisasi nilai variabel total=0
	
	//Method
	do{
		if(r.gettipeItem(slot[i])!=NULL){
			if(r.gettipeItem(slot[i]) == r.gettipeItem(p)){
				total[i]=total[i]-jumlah;}
			else{
				i++;
				}
		}else{
			slot[i]= r.gettipeItem(p);
			total[i]=total[i]-jumlah;}
	}while (i<=maxslot);
}