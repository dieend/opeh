#include "inventory.h"
#include "../item/item.h"
#include <iostream>
using namespace std;


void Inventory :: addItem(int p, int jumlah)
{	
//	//Kamus Lokal
//	int i=0;//Iterator
//	Item r;//sebuah objek berkelas item
//	int total=0;//inisialisasi nilai variabel total=0
//
//	//Method
//	do{
//		if(r.getipeItem(slot[i])!=NULL){
//			if(r.gettipeItem(slot[i]) == r.gettipeItem(p){
//				total[i]=total[i]+jumlah;}
//			else{
//					i++;
//				}
//		}else{
//			slot[i]= r.gettipeItem(p);
//			total[i]=total[i]+jumlah;}
//	}while(i<=maxslot);
}
	
void Inventory :: deleteItem(int p, int jumlah)
{
//	//Kamus Lokal
//	int i=0;//Iterator
//	item r;//sebuah objek berkelas item
//	int total=0;//inisialisasi nilai variabel total=0
//
//	//Method
//	do{
//		if(r.gettipeItem(slot[i])!=NULL){
//			if(r.gettipeItem(slot[i]) == r.gettipeItem(p)){
//				total[i]=total[i]-jumlah;}
//			else{
//				i++;
//				}
//		}else{
//			slot[i]= r.gettipeItem(p);
//			total[i]=total[i]-jumlah;}
//	}while (i<=maxslot);
}

Item* Inventory::getSlot(int){
    
}
Inventory::Inventory(){
}
Inventory::~Inventory(){
}
Inventory& Inventory::operator=(const Inventory& apa) {
    return (*this);
}

void Inventory::listItem(){
}
bool Inventory::cekSlot(int) {
}
void Inventory::addItem(const string&, int jumlah){
}