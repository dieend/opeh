#include "player.h"

Player::Player () {
}

//Player::Player (Inventory i) {
//}

Player::~Player () {
}

void Player::setMoney()	{
	/*
	
	*/
	money = 2000;
}

int Player::getMoney() {
/*

*/
	return money;
}

static Player* Player::getInstances() {
/*

*/
	return player;
}

Grid * Player::getFrontGrid() {
/*
	maksud lu kyk gini Din??
*/
	Point* p = new Point();
	int temp;
	
	
	p = front.getPosisi();
	
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
	
	Grid* front = curArea->getGrid(p);
	return front;
}

void Player::setStatus(int a) {
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
	Grid* front = *this.getFrontGrid();
	
	tipe = front.getType();
	if (tipe == 0) {
		front.setFase(1);
	} else if (tipe == 5) {
		if (front.getFase() == 2) {
			front.setFase(0);
			front.setType(0);
		}
	}
}

void Player::slash() {
/*

*/
	int tipe;
	Grid* front = *this.getFrontGrid();
	
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
	Grid* front = *this.getFrontGrid();
	
	tipe = front.getType();
	if (tipe == 5) {
		if (front.isWatered() == 0) {
			front.setSiram() == 1
			front.getFase == 
		}
	}
}

void eat(int numInv) {
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

void put(int,int);
/*

*/

void move(int,int);
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