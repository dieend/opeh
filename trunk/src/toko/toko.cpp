#include "toko.h"
#include <iostream>
using namespace std;

Toko :: Toko()//konstruktor
{
	cout<<"ctor Toko"<<endl;
}

Toko :: Toko(const Toko&)//copy konstruktor
{
	cout<<"cctor Toko"<<endl;
}

Toko :: ~Toko() //destruktor
{
	cout<<"dtor Toko"<<endl;
}


void Toko::listItem()
{
	cout << "Nama Item \t" << "Harga Beli item \t" << "Harga Jual item \t" <<"\n";
	cout << "Kentang\t" <<"Rp 150\t"<<"Rp 720\t"<<"\n";
	cout << "Lobak\t" <<"Rp 120\t"<<"Rp 540\t"<<"\n";
	cout << "Timun\t" <<"Rp 200\t"<<"Rp 900\t"<<"\n";
	cout << "Kubis\t" <<"Rp 500\t"<<"Rp 2.250\t"<<"\n";
	cout << "Jagung\t" <<"Rp 300\t"<<"Rp 900\t"<<"\n";
	cout << "Tomat\t" <<"Rp 200\t"<<"Rp 540\t"<<"\n";
	cout << "Bawang\t" <<"Rp 150\t"<<"Rp 720\t"<<"\n";
	cout << "Nanas\t" <<"Rp 1.000\t"<<"Rp 4.500\t"<<"\n";
	cout << "Wortel\t" <<"Rp 300\t"<<"Rp 1080\t"<<"\n";
	cout << "Terong\t" <<"Rp 120\t"<<"Rp 720\t"<<"\n";
	cout << "Ubi\t" <<"Rp 300\t"<<"Rp 1.080\t"<<"\n";
	cout << "Paprika\t" <<"Rp 150\t"<<"Rp 360\t\n";
}