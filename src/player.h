#ifndef _PLAYA_H
#define _PLAYA_H

#include <iostream>
#include <string.h>
using namespace std;

class Player {
	public :
	
	//ctor
	Player();
	Player(Inventory,int);
	
	cctor
	Player(const & Player);
	
	//dtor
	virtual ~Player();
	
	//operator=
	
	//metode get dan set
	void setMoney();
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
	
	void eat(int);
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
	
	void move(int,int);
	/*
	Prosedur untuk pergerakan dari player dimana jika sedang menghadap atas dan ke kiri,
	maka prosedur akan membuat arah menjadi ke kiri dulu dengan mengurangi gerakan, baru
	bergerak ke kiri
	*/
	
	void harvest();
	/*
	Prosedur untuk mengambil tanaman yang telah mencapai titik panen jika frontGrid merupakan
	tanaman dan telah mencapai titik panen. Tanaman kemudian akan menyesuaikan dengan tipe tanaman
	apakah langsung hilang atau bisa dipanen ulang. Jika bisa dipanen ulang, maka tanaman akan
	kembali ke fase tanaman dewasa. Jika tidak bisa, maka fase akan berubah menjadi 0, dan tipe
	grid akan menjadi lahan
	*/
	
	void sellItem(Item);
	/*
	Prosedur untuk menjual item, dimana uang akan bertambah sesuai
	dengan penjualan dan jenis barang yang dijual
	*/
	
	void buyItem(Item);
	/*
	Prosedur untuk membeli item, dimana uang akan berkurang sesuai
	dengan jumlah dan jenis barang yang dibeli
	*/
	
	void teleport(Area);
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
	Player player; //
	int arahHadap; //arah hadap player, 1 = atas, 2 = kanan, 3 = bawah, 4 = kiri
	int status; //status player akibat makanan yang dimakan
	string nama; //nama dari player
};

#endif