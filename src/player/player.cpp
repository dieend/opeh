#include "player.h"
#include <string>

Player::Player (ifstream& fin, Area* rumah) {
    fin.read((char*)(this),sizeof(Player));
    curArea = rumah;
    curGrid = rumah->getGrid(6,4);
    curGrid->setType(GPLAYER);
    cout << "inventory:" << fin.tellg() << endl;
    inventory = new Inventory(fin);
}

Player::Player (Area* area, int uang, string name) {
	curArea = area;
	curGrid = area->getGrid(6,4);
	curGrid->setType(GPLAYER);
	arahHadap = 1;
	money = uang;
        copy(name.begin(),name.end(),nama);
        nama[name.size()]='\0';
	inventory = new Inventory();
	status = 0;
	
}

//cctor
Player::Player(const Player & chara) {
    copy(chara.nama,chara.nama+32,nama);
	money = chara.money;
	inventory = chara.inventory;
	curGrid = chara.curGrid;
	curArea = chara.curArea;
	status = chara.status;
	arahHadap = chara.arahHadap;
}

Player::~Player () {
}

Player& Player::operator= (const Player& chara) {
        copy(chara.nama,chara.nama+32,nama);
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
	status = a.getEfekBuah();
}

void Player::setStatus(int a) {
	status = a;
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
        copy(as.begin(),as.end(),nama);
        nama[as.size()]=0;
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

void Player::setCurGrid(Grid * a) {
	curGrid = a;
}

void Player::setArah(int a) {
	arahHadap = a;
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
			} else if (fase == DBIBIT) {
				delete front;
				front = new Grid_Lahan(p,0,LAND);
				curArea->setGrid(front);
			}
		}
	} else {
		throw "Front Grid can't be plowed";
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
			if ((tanaman->getFase() >= REMAJA) && (tanaman->getFase() < DBIBIT )) {
				delete front;
				front = new Grid_Lahan(p,GLAHAN,0);
				curArea->setGrid(front);
			}
		}
	} else {
		throw "Front Grid can't be slashed";
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
			lahan = (Grid_Lahan*)front;
			lahan->setSiram();
		} else if (tipe == GTANAMAN) {
			tanaman = (Grid_Plant*)front;
			if (!(tanaman->isWatered())) {
				tanaman->setSiram();
			}
		}
	} else {
            string kata = "Front Grid can't be watered";
            throw kata.c_str();
	}
}

void Player::eat(int numInv) {
/*

*/
	Item* item;
//	int eff;
	if (inventory->cekSlot(numInv)){
            item = inventory->getSlot(numInv);
            setStatus (*item);
			inventory->deleteItem(numInv,1);
	} else {
		throw "There is no item in slot ";
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
		tipe = front->getType();
		if (tipe == GLAHAN) {
			lahan = (Grid_Lahan*)front;
			fase = lahan->getFase();
			if ((fase == PLOW) || (fase== SPLOW)) {
				if (item->isBibit()) {
					delete front;
					front = new Grid_Plant(p,GTANAMAN,fase,item->getTipeTanaman());
					curArea->setGrid(front);
					inventory->deleteItem(noSlot,jumlah);
				} else {
					inventory->deleteItem(noSlot,jumlah);
				}
			} else {
				inventory->deleteItem(noSlot,jumlah);
			}
		} else if (tipe == GSELLINGBOX) {
			sellItem(noSlot,jumlah);
		} else {
			inventory->deleteItem(noSlot,jumlah);
		}
	} else if (front == NULL) {
		throw "Front Grid can't be used to put item";
	} else {
		throw "There is no item in slot";
        }
}

void Player::move(int arah) {
/*
	tambahkan setting type menjadi 1 jika bergerak
*/
	int tipe;
	int tipeArea;
	Grid* front = getFrontGrid();
	
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
            } else throw "You can't go through it";
	} else {
            arahHadap = arah;
	}
}

void Player::harvest() {
	int tipe;
	int fase;
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
				// if (tanaman->getFase() == MATI) {
					// delete front;
					// front = new Grid_Lahan(p,0,0);
					// curArea->setGrid(front);
				// }
			}
		} else {
			throw "Front Grid can't be harvested";
		}
	} else {
		throw "Front Grid can't be harvested";
	}
}

void Player::sellItem(int NoSlot, int Jumlah) {
	Item* item;
	if (Jumlah > 0) {
		if (inventory->cekSlot(NoSlot)) {
			item = inventory->getSlot(NoSlot);
			money = money + item->getCostSell() * Jumlah;
			inventory->deleteItem(NoSlot,Jumlah);
		} else throw "You don't have any item in slot ";
	} else {
		throw "You don't have enough item in the slot";
	}
}

void Player::buyItem(const string name,int Jumlah) {
/*

*/
	Item * dummyItem;
	dummyItem = Item::makeBibit(name);
	if (dummyItem != NULL) {
		if (Jumlah > 0) {
			if (money >= (dummyItem->getCostBuy() * Jumlah)) {
				money = money - dummyItem->getCostBuy()* Jumlah;
				inventory->addItem(name,Jumlah);
			 } else throw "You do not have money enough to do this transaction. Please try again.";
		} else throw "You can't buy negative number of item";
	}
	 delete dummyItem;
}

void Player::teleport(Area * destination) {
/*

*/
	int area;
	Point p;
		
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
		p.setX(9);
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
    Utilities::getInstances().setFG(BLACK);
    int xUL = p->getCurGrid()->getPosisi().getX()*4+11;
    int yUL = p->getCurGrid()->getPosisi().getY()*6+7;
    if (p->arahHadap == 1) {
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " |\\  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " | > ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " |/  ";	
    } else if (p->arahHadap == 2) {
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << " ___ ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " \\ / ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  v  ";
    } else if (p->arahHadap == 3) {
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  /| ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " < | ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << "  \\| ";
    } else {
			Utilities::getInstances().gotoxy(yUL,xUL);
            c << "  ^  ";
			Utilities::getInstances().gotoxy(yUL,xUL+1);
			c << " / \\ ";
			Utilities::getInstances().gotoxy(yUL,xUL+2);
			c << " --- ";
    }
    Utilities::getInstances().resetFG();
    return c;
}

Grid * Player::getCurGrid(){
    return curGrid;
}

