#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "time.h"
#include "area.h"
#include "player.h"
using namespace std;

class World{
private:
	Time* time;
	/*
		pointer ke objek Time
	*/
	Player* player;
	/*
		pointer ke objek Player yang telah diinstansiasi
	*/
	Area* area[3];
	/*
		Array yang berisikan pointer yang menunjuk ke objek Area
	*/
	Kurcaci* kurcaci[3];
	/*
		Array yang berisi pointer ke objek kurcaci
	*/
	int weather;
	/*
		Merupakan jenis cuaca yang ada pada hari itu. Diupdate setiap nextday()
	*/
	void doWeather();
	/*
		melakukan efek cuaca pada hari itu. dilakukan saat setWeather dilakukan dan berdasarkan
		tipe cuaca yang ditentukan attribute weather.
	*/
	
public:
	World(); // ctor
	World(World&); // cctor
	virtual ~World(); // dtor
	World& operator=(const World&); // operator =
	friend ostream& operator<<(ostream&,const World&);
	/* Stream operator untuk cout. Bakal menampilkan area secara keseluruhan. Dengan meng-cout World
		maka user dapat melihat keadaan seluruh grid pada area player berada saat tersebut.
	*/
	static void save(const string&,const World&); 
	/* Procedure static yang menyimpan world direference di parameter ke file dengan string pathFile
	*/
	static World* load(const string&);  
	/* Procedure yang mengembalikan address world yang udah diinstansiasi dan 
		sama seperti file yang diload
	*/
	void setWeather();
	/* Merandom cuaca untuk hari itu. Kemudian melakukan efeknya dengan method doWeather()
	*/
	Area* getArea(int);
	/* Mengembalikan pointer yang menunjuk ke area sesuai parameter. 
		0 untuk rumah, 1 untuk lahan, 2 untuk toko
	*/
	Kurcaci* getKurcaci(int);
	/* Mengembalikan pointer ke kurcaci sesuai parameter
		0 kurcaci water, 1 kurcaci harvest, 2 kurcaci slash
	*/
	Time* getTime();
	Player* getPlayer();
	void kurcaciWork();
	/* Membuat kurcaci melakukan pekerjaan yang dilakukan setiap action player terjadi
	*/
};
#endif
