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
	Maksud lu gini y din??
*/
	Grid* front;
	Point* p = new Point();
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
	//status = a;
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

//metode umum untuk Player
void Player::plow() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 0) {
		front->setFase(1);
	} else if (tipe == 5) {
		tanaman = (Plant*)front;
		if (tanaman->getFase() == 2) {
			tanaman->setType(0);
			tanaman->setFase(1);
		}
	}
}

void Player::slash() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (Plant*)front;
		if (tanaman->getFase() == 3) {
			tanaman->setFase(0);
			tanaman->setType(0);
		}
	}
}
	

void Player::water() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (Plant*)front;
		if (tanaman->isWatered() == 0) {
			tanaman->setSiram();
		}
	}
}

void Player::eat(int numInv) {
/*

*/
	Item item;
	int eff;
	if (inventory.cekSlot(numInv)) {
		item = inventory.slot[numInv];
		inventory.deleteItem(numInv,1);	
		eff = item.getEfekBuah();
	
	
	if (efTime == 0) {
	}
}

void Player::put(int noSlot,int jumlah) {
/*

*/
	int tipe;
	int fase;
	Grid* front = getFrontGrid();
	Plant* tanaman;
	Item item;
	
	tipe = front->getTipe();
	fase = front->getFase();
	if ((tipe == 0) && (fase == 1)) {
		front->setTipe(5);
		tanaman = (Plant*)front;
		tanaman->setFase(0);
		inventory.deleteItem(noSlot,jumlah);
	} else if (tipe == 8) {
		item = inventory.slot[noSlot];
		inventory.deleteItem(noSlot,jumlah);
		sellItem(item);
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
		} else //throw "Tidak bisa dilalui";
	} else {
		arahHadap = arah;
	}
}

void Player::harvest() {
/*

*/
	int tipe;
	int fase;
	Grid* front = getFrontGrid();
	Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (Plant*)front;
		fase = tanaman->getFase();
		if ((fase == 4) || (fase == 5)) {
			tanaman->setPanen();
		}
	}
}

void Player::sellItem(Item i) {
/*

*/
	money = money + i.getCost();
}

void Player::buyItem(Item i) {
/*

*/
	money = money - i.getCost();
}

void Player::teleport(Area destination) {
/*

*/
	(*curArea) = destination; //masih belum lengkap
}
