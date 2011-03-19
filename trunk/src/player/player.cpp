#include "player.h"
#include <string.h>

Player::Player () {
    
}

Player::Player (Area* area, int uang, string name) {
	curArea = area;
        curGrid = area->getGrid(4,3);
        curGrid->setType(GPLAYER);
	arahHadap = 1;
	money = uang;
	nama = name;
	inventory = new Inventory();
	
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
	if ((arahHadap == 1) && (p.getY() < 9)) {
		temp = p.getY();
		temp++;
		p.setY(temp);
		front = curArea->getGrid(p);
		return front;
	} else if ((arahHadap == 2) && (p.getX() < 9)) {
		temp = p.getX();
		temp++;
		p.setX(temp);
		front = curArea->getGrid(p);
		return front;
	} else if ((arahHadap == 3) && (p.getY() > 0)) {
		temp = p.getY();
		temp--;
		p.setY(temp);
		front = curArea->getGrid(p);
		return front;
	} else if ((arahHadap == 4) && (p.getX() > 0)) {
		temp = p.getX();
		temp--;
		p.setX(temp);
		front = curArea->getGrid(p);
		return front;
	} else {
		return NULL;
	}
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
	return  (inventory);
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
	Point p;
	
	if (front != NULL) {
		tipe = front->getType();
		p = front->getPosisi();
		cout << p << endl;
		if (tipe == GLAHAN) {
			lahan = (Grid_Lahan*)front;
			lahan->setCangkul();
		} else if (tipe == GTANAMAN) {
			tanaman = (Grid_Plant*)front;
			fase = tanaman->getFase();
			if ((fase == BIBIT) || (fase == SBIBIT)) {
				delete front;
				front = new Grid_Lahan(p,0,fase);
				curArea->setGrid(front);
			}
		}
	}
}

void Player::slash() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	Point p;
	
	if (front != NULL) {
		tipe = front->getType();
		p = front->getPosisi();
		if (tipe == GTANAMAN) {
			tanaman = (Grid_Plant*)front;
			if (tanaman->getFase() >= REMAJA) {
				delete front;
				front = new Grid_Lahan(p,GLAHAN,0);
				curArea->setGrid(front);
			}
		}
	}
}
	

void Player::water() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	Grid_Lahan* lahan;
	Point p;
	
	if (front != NULL) {
		tipe = front->getType();
		p = front->getPosisi();
		if (tipe == GLAHAN) {
                    cout << "LAHAN INI\n";
			lahan = (Grid_Lahan*)front;
			lahan->setSiram();
		} else if (tipe == GTANAMAN) {
                    cout << "TANAMAN INI \n";
			tanaman = (Grid_Plant*)front;
			if (!(tanaman->isWatered())) {
                                cout << "WAH BELUM DISIRAM";
				cout << "tes" << endl;
				tanaman->setSiram();
			}
		}
	}
        system("PAUSE");
}

int Player::eat(int numInv) {
/*

*/
	Item* item;
	int eff;
	if (inventory->cekSlot(numInv)){
            item = inventory->getSlot(numInv);
            inventory->deleteItem(numInv,1);
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
        Item* item = inventory->getSlot(noSlot);
	Grid_Lahan* lahan;
	Point p;
	
	if ((front != NULL) && (item != NULL)) {
		p = front->getPosisi();
		cout << p << endl;
		tipe = front->getType();
		if (tipe == GLAHAN) {
			lahan = (Grid_Lahan*)front;
			fase = lahan->getFase();
                        cout << fase << endl;
			if ((fase == PLOW) || (fase== SPLOW)) {
                            cout << "PLOWED";
				if (item->isBibit()) {
                                    cout<<"BIBIT";
					delete front;
					front = new Grid_Plant(p,GTANAMAN,fase,item->getTipeTanaman());
					curArea->setGrid(front);
					inventory->deleteItem(noSlot,jumlah);
				} else {
					inventory->deleteItem(noSlot,jumlah);
				}
			} else {
                            cout << "DELETED1";
				inventory->deleteItem(noSlot,jumlah);
			}
		} else if (tipe == GSELLINGBOX) {
                        sellItem(noSlot,jumlah);
			inventory->deleteItem(noSlot,jumlah);
		} else {
                    cout << "DELETED2";
			inventory->deleteItem(noSlot,jumlah);
		}
	}
        system("PAUSE");
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
	
	if ((front != NULL) && (arahHadap == arah)) {
            tipe = front->getType();
            if ((tipe == GLAHAN) || (tipe == GJALAN)) {
                tipeArea = curArea->getType();
                if (tipeArea == LAHAN) {
                        p = curGrid->getPosisi();
                    if (p.getX() < 3) {
                        curGrid->setType(GJALAN);
                    } else {
                        curGrid->setType(GLAHAN);
                    }
                } else {
                    curGrid->setType(GJALAN);
                }
                curGrid = front;
                curGrid->setType(GPLAYER);
            }
	} else {
            arahHadap = arah;
	}
}

void Player::harvest() {
	int tipe;
	int fase;
	int tipeTanaman;
	Grid* front = getFrontGrid();
	Grid_Plant* tanaman;
	Point p;	
	if (front != NULL) {
		tipe = front->getType();
		p = front->getPosisi();
		if (tipe == GTANAMAN) {
			tanaman = (Grid_Plant*)front;
			fase = tanaman->getFase();
			if ((fase == DEWASA) || (fase == SDEWASA)) {
				tanaman->setPanen();
				inventory->addItem(tanaman,1);
				if (tanaman->getFase() == MATI) {
					delete front;
					front = new Grid_Lahan(p,0,0);
					curArea->setGrid(front);
				}
			}
		}
	}
}

void Player::sellItem(int NoSlot, int Jumlah) {
	Item* item;
	if (inventory->cekSlot(NoSlot)) {
		item = inventory->getSlot(NoSlot);
		money = money + item->getCostSell() * Jumlah;
		inventory->deleteItem(NoSlot,Jumlah);
	} else {
		throw 2;
	}
}

void Player::buyItem(const string name,int Jumlah) {
/*

*/
	Item * dummyItem;
	dummyItem = Item::makeBibit(name);
        cout << dummyItem -> getIDitem() << endl;
	if (money >= (dummyItem->getCostBuy() * Jumlah)) {
		money = money - dummyItem->getCostBuy()* Jumlah;
                cout <<"OK";
		inventory->addItem(name,Jumlah);
	 } //else throw "Uang Tidak Mencukupi"
	 delete dummyItem;
}

void Player::teleport(Area * destination) {
/*

*/
	int area;
	Point p;
	int tipe;
	
	p = curGrid->getPosisi();
	if (curArea->getType() == LAHAN) {
		if (p.getX() >= 3) {
			curGrid->setType(0);
		} else {
			curGrid->setType(2);
		}
	} else {
		curGrid->setType(2);
	}
	curArea = destination;
	area = curArea->getType();
	if (area == RUMAH) {
		p.setX(8);
		p.setY(4);
		arahHadap = 4;
	} else if (area == LAHAN) {
		p.setX(1);
		p.setY(0);
		arahHadap = 1;
	} else {
		p.setX(3);
		p.setY(0);
		arahHadap = 1;
	}
	curGrid = curArea->getGrid(p);
	curGrid->setType(1);
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