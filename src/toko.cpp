#include "toko.h"
#include <iostream>
using namespace std;

toko :: toko()
{
	cout<<"ctor item"<<endl; 
}
	
toko :: toko(const toko&)
{
	cout<<"cctor item"<<endl;
}
	
virtual toko :: ~toko();
{
	cout<<"dtor item""<<endl;
}

int toko :: listItem()
{
	//Kamus Lokal

	//Algoritma
	cout<<"Barang yang dijual di toko adalah\n"<<endl;
	cout<<"Barang"<<tipeItem[0]<<",harganya adalah "<<cost[0]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[1]<<",harganya adalah "<<cost[1]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[2]<<",harganya adalah "<<cost[2]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[3]<<",harganya adalah "<<cost[3]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[4]<<",harganya adalah "<<cost[4]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[5]<<",harganya adalah "<<cost[5]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[6]<<",harganya adalah "<<cost[6]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[7]<<",harganya adalah "<<cost[7]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[8]<<",harganya adalah "<<cost[8]<<"\n"<<endl;
	cout<<"Barang"<<tipeItem[9]<<",harganya adalah "<<cost[9]<<endl;
	
	return 0;
}