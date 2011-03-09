#include "player.h"
#include <string.h>

Player::Player () {
}

Player::Player (Inventory i, int uang, string name) {
	inventory = i;
	money = uang;
	nama = name;
	
}

//cctor
Player::Player(const Player & chara) {
	nama = chara.nama;
	money = chara.money;
	inventory = chara.inventory;
	curGrid = chara.curGrid;
	curArea = chara.curArea;
	status = chara.status;
	arahHadap = chara.arahHadap;
}

Player::~Player () {
}

//operator=
Player& Player::operator= (const Player& chara) {
	nama = chara.nama;
	money = chara.money;
	inventory = chara.inventory;
	curGrid = chara.curGrid;
	curArea = chara.curArea;
	status = chara.status;
	arahHadap = chara.arahHadap;
	
	return (*this);
}
	

void Player::setMoney(int x)	{
	/*
	
	*/
	money = x;
}

int Player::getMoney() {
/*

*/
	return money;
}

Grid * Player::getFrontGrid() {
/*
	
*/
	Grid* front;
	Point* p;
	int temp;
	
	
	(*p) = curGrid->getPosisi();
	
	if (arahHadap == 1) {
		temp = (*p).getY();
		temp++;
		(*p).setY(temp);
	} else if (arahHadap == 2) {
		temp = (*p).getX();
		temp++;
		(*p).setX(temp);
	} else if (arahHadap == 3) {
		temp = (*p).getY();
		temp--;
		(*p).setY(temp);
	} else {
		temp = (*p).getX();
		temp--;
		(*p).setX(temp);
	}
	
	front = curArea->getGrid(*p);
	return front;
}

void Player::setStatus(Item a) {
/*

*/
	int stat = a.getEfekBuah();
	
	if stat
}

int Player::getStatus() {
/*

*/
	return status;
}

void Player::setName(string as) {
/*
Mengisi nama dari player
*/
	nama = as;
}
	
string Player::getName() {
/*
Mengambil nama dari player
*/
	return nama;
}

Area * Player::getCurArea() {
/*

*/
	return curArea;
}

Inventory * Player::getInventory() {
/*

*/
	return  (& inventory);
}

void Player::setFrontGrid(Grid * front) {
/*

*/
	Grid* frontp = getFrontGrid();
	frontp = front;
}

//metode umum untuk Player
void Player::plow() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	Grid_Lahan* lahan;
	
	tipe = front->getType();
	if (tipe == 0) {
		lahan = (Grid_Lahan*)front;
		lahan->setFase(1);
	} else if (tipe == 5) {
		tanaman = (Grid_Plant*)front;
		if (tanaman->getFase() == 2) {
			delete front;
			front = new Grid_Lahan();
			front->setType(0);
			front->setFase(1);
			setFrontGrid(front);
		}
	}
}

void Player::slash() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (Grid_Plant*)front;
		if (tanaman->getFase() == 3) {
			delete front;
			front = new Grid_Lahan();
			tanaman->setFase(0);
			tanaman->setType(0);
			setFrontGrid(front);
		}
	}
}
	

void Player::water() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (Grid_Plant*)front;
		if (tanaman->isWatered() == 0) {
			tanaman->setSiram();
		}
	}
}

int Player::eat(int numInv) {
/*

*/
	Item* item;
	int eff;
	if (inventory.cekSlot(numInv)) {
		item = inventory.getSlot(numInv);
		inventory.deleteItem(numInv,1);	
		setStatus (*item);
		return item->getEfekTime();
	} else {
		return 0;
	}
}

void Player::put(int noSlot,int jumlah) {
/*

*/
	int tipe;
	int fase;
	Grid* front = getFrontGrid();
	Grid_Lahan* lahan;
	
	tipe = front->getTipe();
	if (tipe == 0) {
		lahan = (Grid_Lahan*)front;
		fase = lahan->getFase();
		if (fase == 1) {
			lahan->setTipe(5);
			delete front;
			front = new Grid_Plant();
			front->setFase(0);
			inventory.deleteItem(noSlot,jumlah);
			setFrontGrid(front);
		}
	} else if (tipe == 8) {
		inventory.deleteItem(noSlot,jumlah);
		sellItem(noSlot,jumlah);
	} else {
		inventory.deleteItem(noSlot,jumlah);
	}
}

void Player::move(int arah) {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Plant* tanaman;
	
	tipe = front->getType();
	if (arahHadap == arah) {
		if ((tipe == 0) || (tipe == 3)) {
			curGrid = front;
		} //else throw "Tidak bisa dilalui";
	} else {
		arahHadap = arah;
	}
}

void Player::harvest() {
/*

*/
	int tipe;
	int fase;
	int tipeTanaman;
	Grid* front = getFrontGrid();
	Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (Plant*)front;
		fase = tanaman->getFase();
		if ((fase == 4) || (fase == 5)) {
			tanaman->setPanen();
			tipeTanaman = tanaman->getTypeTanaman();
			inventory.addItem(tipeTanaman,1);
			if (tanaman->getFase() == 6) {
				delete front;
				front = new Grid_Lahan();
				front->setTipe(0);
				front->setFase(0);
			}
		}
	}
}

void Player::sellItem(int NoSlot, int Jumlah) {
/*

*/
	Item* item;
	item = inventory.slot[NoSlot];
	money = money + item->getCost() * Jumlah;
	inventory.deleteItem(NoSlot,Jumlah);
}

void Player::buyItem(string name,int Jumlah) {
/*

*/
	Item * dummyItem;
	
	dummyItem = new Item(name);
	if (money > (dummyItem->getCost() * Jumlah)) {
		money = money - dummyItem->getCost() * Jumlah;
		inventory.addItem(name,jumlah);
	 } //else throw "Uang Tidak Mencukupi"
	 delete dummyItem;
}

void Player::teleport(Area destination) {
/*

*/
	(*curArea) = destination; //masih belum lengkap
}
