#ifndef _PLAYA_H
#define _PLAYA_H

#include <iostream>
#include <string.h>
#include "../inventory/inventory.h"
#include "../area/area.h"
#include "../grid/grid.h"
#include "../grid/grid_plant.h"
#include "../grid/grid_lahan.h"
#include "../item/item.h"
using namespace std;

class Player {
	public :
	
	//ctor
	Player();
	Player(Inventory,int,string);
	
	//cctor
	Player(const Player &);
	
	//dtor
	virtual ~Player();
	
	//operator=
	Player& operator= (const Player&);
	
	//metode get dan set
	void setMoney(int);
	/*
	Mengisi uang untuk player
	*/
	
	int getMoney();
	/*
	Mengambil nilai money pada Player
	*/
	
	Grid * getFrontGrid();
	/*
	Mengambil grid di depan pemain dihitung dari curGrid dan arahHadap
	*/
	
	void setStatus(Item);
	/*
	Mengisi jenis status pada item
	*/
	
	int getStatus();
	/*
	Memeroleh informasi status dari player
	*/
	
	void setName(string);
	/*
	Mengisi nama dari player
	*/
	
	string getName();
	/*
	Mengambil nama dari player
	*/
	
	Area * getCurArea();
	/*
	
	*/
	
	Inventory * getInventory();
	/*
	
	*/
	
	void setFrontGrid(Grid*);
	/*
	
	*/
	
	//metode umum untuk Player
	void plow();
	/*
	Prosedur mencangkul dengan proses memeroleh frontGrid Player, kemudian
	mengecek tipenya apakah merupakan lahan plantable, jika iya, maka fase
	akan berubah menjadi sudah dicangkul, jika tipe lahan plant, maka jika
	masih pada fase bibit, bibit akan hilang
	*/
	
	void slash();
	/*
	Prosedur memotong dengan proses memeroleh frontGrid Player, kemudian
	mengecek tipenya apakah merupakan tanaman, jika iya, maka tipe grid akan 
	berubah menjadi lahan kosong, dan fase akan berubah menjadi tidak ada.
	*/
	
	void water();
	/*
	Prosedur menyiram dengan proses memeroleh frontGrid Player, kemudian
	mengecek tipenya apakah merupakan tanaman, jika iya, maka fase
	akan berubah menjadi sudah disiram
	*/
	
	int eat(int);
	/*
	Prosedur memakan item yang ada pada inventory dengan slot tertentu, kemudian
	mengecek efek yang terjadi, dan memberikan status pada player, serta melakukan
	perubahan aksi sesuai status yang dialami player
	*/
	
	void put(int,int);
	/*
	Prosedur untuk meletakkan barang dengan proses memeroleh frontGrid Player,
	kemudian mengecek tipenya apakah lahan atau selling box atau yang lain. Jika lahan,
	jumlah hanya bisa bernilai 1 dan tipe akan berubah menjadi tanaman, dan fase juga
	akan berubah menjadi bibit. Jika selling box, maka akan dipanggil prosedur sell
	yang artinya terjadi penjualan barang. Jika di grid selain tipe di atas, maka
	item akan hilang sesuai jumlah
	*/
	
	void move(int);
	/*
	Prosedur untuk pergerakan dari player dimana jika sedang menghadap atas dan ke kiri,
	maka prosedur akan membuat arah menjadi ke kiri dulu , baru bergerak ke kiri, dan jika
	sudah pada arah yang benar, maka player akan bergerak ke grid di depannya dengan pengecekan
	apakah grid bisa dilalui.
	*/
	
	void harvest();
	/*
	Prosedur untuk mengambil tanaman yang telah mencapai titik panen jika frontGrid merupakan
	tanaman dan telah mencapai titik panen. Tanaman kemudian akan menyesuaikan dengan tipe tanaman
	apakah langsung hilang atau bisa dipanen ulang. Jika bisa dipanen ulang, maka tanaman akan
	kembali ke fase tanaman dewasa. Jika tidak bisa, maka fase akan berubah menjadi 0, dan tipe
	grid akan menjadi lahan
	*/
	
	void sellItem(int,int);
	/*
	Prosedur untuk menjual item, dimana uang akan bertambah sesuai
	dengan penjualan dan jenis barang yang dijual
	*/
	
	void buyItem(string,int);
	/*
	Prosedur untuk membeli item, dimana uang akan berkurang sesuai
	dengan jumlah dan jenis barang yang dibeli
	*/
	
	void teleport(Area*);
	/*
	Prosedur untuk berpindah area dari area yang satu ke area yang
	lain dengan ketentuan Rumah -> Lahan -> Toko dan sebaliknya
	Toko -> Lahan -> Rumah
	*/
	
	private :
	Grid * curGrid; //grid player berada
	Area * curArea; //area player berada
	Inventory inventory; //inventory dari player
	int money; //jumlah uang
	int arahHadap; //arah hadap player, 1 = atas, 2 = kanan, 3 = bawah, 4 = kiri
	int status; //status player akibat makanan yang dimakan
	string nama; //nama dari player
};

#endif