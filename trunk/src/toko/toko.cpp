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
	cout << "Nama Item \t" <<endl; cout << "Harga Beli item \t" <<endl;cout << "Harga Jual item \t" <<endl;cout <<"\n"<<endl;
	cout << "Kentang\t" <<endl; cout <<"Rp 150\t"<<endl; cout <<"Rp 720\t"<<endl;cout <<"\n"<<endl;
	cout << "Lobak\t" <<endl; cout <<"Rp 120\t"<<endl; cout <<"Rp 540\t"<<endl;cout <<"\n"<<endl;
	cout << "Timun\t" <<endl; cout <<"Rp 200\t"<<endl; cout <<"Rp 900\t"<<endl;cout <<"\n"<<endl;
	cout << "Kubis\t" <<endl; cout <<"Rp 500\t"<<endl; cout <<"Rp 2.250\t"<<endl;cout <<"\n"<<endl;
	cout << "Jagung\t" <<endl; cout <<"Rp 300\t"<<endl; cout <<"Rp 900\t"<<endl;cout <<"\n"<<endl;
	cout << "Tomat\t" <<endl; cout <<"Rp 200\t"<<endl; cout <<"Rp 540\t"<<endl;cout <<"\n"<<endl;
	cout << "Bawang\t" <<endl; cout <<"Rp 150\t"<<endl; cout <<"Rp 720\t"<<endl;cout <<"\n"<<endl;
	cout << "Nanas\t" <<endl; cout <<"Rp 1.000\t"<<endl; cout <<"Rp 4.500\t"<<endl;cout <<"\n"<<endl;
	cout << "Wortel\t" <<endl; cout <<"Rp 300\t"<<endl; cout <<"Rp 1080\t"<<endl;cout <<"\n"<<endl;
	cout << "Terong\t" <<endl; cout <<"Rp 120\t"<<endl; cout <<"Rp 720\t"<<endl;cout <<"\n"<<endl;
	cout << "Ubi\t" <<endl; cout <<"Rp 300\t"<<endl; cout <<"Rp 1.080\t"<<endl;cout <<"\n"<<endl;
	cout << "Paprika\t" <<endl; cout <<"Rp 150\t"<<endl; cout <<"Rp 360\t"<<endl;;
}