#include "player.h"

Player::Player () {
}

Player::Player (Inventory i, int uang) {
}

Player::~Player () {
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
	
	front = curArea->getGrid(*p);
	return front;
}

void Player::setStatus(Item a) {
/*

*/
	status = a;
}

int Player::getStatus() {
/*

*/
	return status;
}

//metode umum untuk Player
void Player::plow() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	
	tipe = front.getType();
	if (tipe == 0) {
		front.setFase(1);
	} else if (tipe == 5) {
		if (front.getFase() == 2) {
			front.setType(0);
			front.setFase(1);
		}
	}
}

void Player::slash() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	
	tipe = front.getType();
	if (tipe == 5) {
		if (front.getFase() == 3) {
			front.setFase(0);
			front.setType(0);
		}
	}
}
	

void Player::water() {
/*

*/
	int tipe;
	Grid* front = getFrontGrid();
	
	tipe = front.getType();
	if (tipe == 5) {
		if (front.isWatered() == 0) {
			front.setSiram();
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

void Player::put(int noSlot,int jumlah) {
/*

*/
	int tipe;
	int fase;
	Grid* front = getFrontGrid();
	Item item;
	
	tipe = front.getTipe();
	if (tipe == 0) {
		fase = front.getFase();
		front.setTipe(5);
		front.setFase(fase);
		inventory.deleteItem(noSlot,jumlah);
	} else if (tipe == 8) {
		item = inventory.slot[noSlot];
		inventory.deleteItem(noSlot,jumlah);
		sellItem(item);
	} else {
		inventory.deleteItem(noSlot,jumlah);
	}
}

void Player::move(int arah,int jumlahStep) {
/*

*/
	

void harvest();
/*

*/

void sellItem(Item);
/*

*/

void buyItem(Item);
/*

*/

void teleport(Area);
/*

*/