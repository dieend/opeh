#include "toko.h"
#include <iostream>
#include <iomanip>
using namespace std;

Toko :: Toko()//konstruktor
{
}

Toko :: Toko(const Toko&)//copy konstruktor
{
}

Toko :: ~Toko() //destruktor
{
    cout << "~toko";
}

void Toko::listItem()
{
	cout << char(201); for (int i = 1; i <= 10; i++) {cout << char(205);} cout << char(203); for (int i = 1; i <= 16; i++) {cout << char(205);} cout << char(203); for (int i = 1; i <= 16; i++) {cout << char(205);} cout << char(187) << endl;
	cout << char(186) << setw(10) << left << "Nama Item"; cout << char(186) << setw(16)<< right << "Harga Beli item";cout << char(186) << setw(16)<< right << "Harga Jual item" << char(186) << endl;
	cout << char(204); for (int i = 1; i <= 10; i++) {cout << char(205);} cout << char(206); for (int i = 1; i <= 16; i++) {cout << char(205);} cout << char(206); for (int i = 1; i <= 16; i++) {cout << char(205);} cout << char(185) << endl;
	cout << char(186) << setw(10) << left << "Kentang"; cout << char(186) << setw(16)<< right <<"Rp 150"; cout << char(186) << setw(16)<< right <<"Rp 720"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Lobak"; cout << char(186) << setw(16)<< right <<"Rp 120"; cout << char(186) << setw(16)<< right <<"Rp 540"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Timun"; cout << char(186) << setw(16)<< right <<"Rp 200"; cout << char(186) << setw(16)<< right <<"Rp 900"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Kubis"; cout << char(186) << setw(16)<< right <<"Rp 500"; cout << char(186) << setw(16)<< right <<"Rp 2.250"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Jagung"; cout << char(186) << setw(16)<< right <<"Rp 300"; cout << char(186) << setw(16)<< right <<"Rp 900"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Tomat"; cout << char(186) << setw(16)<< right <<"Rp 200"; cout << char(186) << setw(16)<< right <<"Rp 540"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Bawang"; cout << char(186) << setw(16)<< right <<"Rp 150"; cout << char(186) << setw(16)<< right <<"Rp 720"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Nanas"; cout << char(186) << setw(16)<< right <<"Rp 1.000"; cout << char(186) << setw(16)<< right <<"Rp 4.500"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Wortel"; cout << char(186) << setw(16)<< right <<"Rp 300"; cout << char(186) << setw(16)<< right <<"Rp 1080"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Terong"; cout << char(186) << setw(16)<< right <<"Rp 120"; cout << char(186) << setw(16)<< right <<"Rp 720"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Ubi"; cout << char(186) << setw(16)<< right <<"Rp 300"; cout << char(186) << setw(16)<< right <<"Rp 1.080"<<char(186) << endl;
	cout << char(186) << setw(10) << left << "Paprika"; cout << char(186) << setw(16)<< right <<"Rp 150"; cout << char(186) << setw(16)<< right <<"Rp 360"<<char(186) << endl;
	cout << char(200); for (int i = 1; i <= 10; i++) {cout << char(205);} cout << char(202); for (int i = 1; i <= 16; i++) {cout << char(205);} cout << char(202); for (int i = 1; i <= 16; i++) {cout << char(205);} cout << char(188) << endl;
}
