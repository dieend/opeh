#include "player.h"
#include <string.h>

Player::Player (Area* area) {
    curArea = area;
    curGrid = area->getGrid(8,4);
    curGrid->setType(1);
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
//	delete curGrid;
//	delete curArea;
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
	Point p;
	int temp;
	
	
	p = curGrid->getPosisi();
	
	if (arahHadap == 1) {
		temp = p.getY();
		temp++;
		p.setY(temp);
	} else if (arahHadap == 2) {
		temp = p.getX();
		temp++;
		p.setX(temp);
	} else if (arahHadap == 3) {
		temp = p.getY();
		temp--;
		p.setY(temp);
	} else {
		temp = p.getX();
		temp--;
		p.setX(temp);
	}
	
    front = curArea->getGrid(p);
	return front;
}

void Player::setStatus(Item a) {
/*

*/
	int stat = a.getEfekBuah();
	
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
	baca punya onta untuk nentuin bibit sudah disiram dan belum disiram
*/
	int tipe;
	int fase;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	Grid_Lahan* lahan;
	
	tipe = front->getType();
	if (tipe == 0) {
		lahan = (Grid_Lahan*)front;
		lahan->setCangkul();
	} else if (tipe == 5) {
		tanaman = (Grid_Plant*)front;
		fase = tanaman->getFase();
		if ((fase == 1) || (fase == 2)) {
			delete front;
			front = new Grid_Lahan();
			front->setType(0);
			front->setFase(fase);
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
	if (inventory.cekSlot(numInv)){
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
	validasi bibit
*/
	int tipe;
	int fase;
	Grid* front = getFrontGrid();
	Grid_Lahan* lahan;
	Item* item;
	
	tipe = front->getType();
	if (tipe == 0) {
		lahan = (Grid_Lahan*)front;
		fase = lahan->getFase();
		if (fase == 1) {
			item = inventory.getSlot(noSlot);
			if (item->isBibit()) {
				delete front;
				front = new Grid_Plant();
				front->setType(5);
				front->setFase(0);
				inventory.deleteItem(noSlot,jumlah);
				setFrontGrid(front);
			} else {
				inventory.deleteItem(noSlot,jumlah);
			}
		} else {
			inventory.deleteItem(noSlot,jumlah);
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
	tambahkan setting type menjadi 1 jika bergerak
*/
	int tipe;
	int tipeArea;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	Point p;
	
	tipe = front->getType();
	if (arahHadap == arah) {
		if ((tipe == 0) || (tipe == 2)) {
				tipeArea = curArea->getType();
			if (tipeArea == 1) {
				p = curGrid->getPosisi();
				if (p.getX() < 3) {
					curGrid->setType(2);
				} else {
					curGrid->setType(0);
				}
			} else {
				curGrid->setType(2);
			}
			curGrid = front;
			curGrid->setType(1);
		}
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
	Grid_Plant* tanaman;
	
	tipe = front->getType();
	if (tipe == 5) {
		tanaman = (Grid_Plant*)front;
		fase = tanaman->getFase();
		if ((fase == 4) || (fase == 5)) {
			tanaman->setPanen();
			tipeTanaman = tanaman->getTypeTanaman();
			inventory.addItem(tipeTanaman,1);
			if (tanaman->getFase() == 6) {
				delete front;
				front = new Grid_Lahan();
				front->setType(0);
				front->setFase(0);
			}
		}
	}
}

void Player::sellItem(int NoSlot, int Jumlah) {
/*

*/
	Item* item;
	item = inventory.getSlot(NoSlot);
	money = money + item->getCostSell() * Jumlah;
	inventory.deleteItem(NoSlot,Jumlah);
}

void Player::buyItem(string name,int Jumlah) {
/*

*/
	Item * dummyItem;
	
	dummyItem = new Item(name);
	if (money > (dummyItem->getCostBuy() * Jumlah)) {
		money = money - dummyItem->getCostBuy()* Jumlah;
		inventory.addItem(name,Jumlah);
	 } //else throw "Uang Tidak Mencukupi"
	 delete dummyItem;
}

void Player::teleport(Area * destination) {
/*

*/
	int area;
	Point p;
	
	curArea = destination; //masih belum lengkap
	area = curArea->getType();
	if (area == 0) {
		p.setX(8);
		p.setY(4);
	} else if (area == 1) {
		p.setX(1);
		p.setY(0);
	} else {
		p.setX(3);
		p.setY(0);
	}
	curGrid = curArea->getGrid(p);
	curGrid->setType(1);
	arahHadap = 1;
}

ostream& operator<<(ostream& c, Player* p){
    if (p->arahHadap == 1) {
		c << (char) 272;
	} else if (p->arahHadap == 2) {
		c << (char) 287;
	} else if (p->arahHadap == 3) {
		c << (char) 273;
	} else {
		c << (char) 286;
	}
    return c;
}

Grid * Player::getCurGrid(){
    return curGrid;
}