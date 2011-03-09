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

Area * Player::getCurArea() {
/*

*/
	return curArea;
}

Inventory * Player::getInventory() {
/*

*/
	return &inventory;
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
	
	tipe = front->getType();
	if (tipe == 0) {
		front->setFase(1);
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
	grid_plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (grid_plant*)front;
		if (tanaman->getFase() == 3) {
			delete tanaman;
			tanaman = new grid_lahan();
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
	grid_plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (grid_plant*)front;
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
	
	tipe = front->getTipe();
	fase = front->getFase();
	if ((tipe == 0) && (fase == 1)) {
		front->setTipe(5);
		tanaman = (Plant*)front;
		tanaman->setFase(0);
		inventory.deleteItem(noSlot,jumlah);
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

void Player::sellItem(int NoSlot, int Jumlah) {
/*

*/
	money = money + i.getCost();
}

void Player::buyItem(string name,int Jumlah) {
/*

*/
	money = money - i.getCost();
}

void Player::teleport(Area destination) {
/*

*/
	(*curArea) = destination; //masih belum lengkap
}
