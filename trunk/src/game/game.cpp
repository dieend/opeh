#include "game.h"
#define KANAN 2
#define KIRI 4
#define ATAS 1
#define BAWAH 3
void Game::Run() {
	bool notExit;
	do {
		cout << world;
		try {
			getPerintah();
			notExit = doPerintah();
		} catch (int i) {
			if (i==0) {
				cerr << "input tidak sesuai format!\n";
			} else if (i==1) {
				cerr << "tidak ada perintah yang dimaksud\n";
			} else if (i==2) {
				cerr << "perintah ini tidak bisa dilakukan disini\n";
			}
			getch();
		}
	}while(notExit);
}

bool Game::doPerintah() {
	if (world == NULL) {
		if (perintah == "new") {
		} else if (perintah == "load") {
		} else throw 2;
	} else {
		if (perintah == "teleport") {
			int where = world->getPlayer()->getCurArea()->getType();
			if (paramStr[0] == "-help") {
				if (where ==0) {
					cout << "Anda bisa teleport ke `lahan` (kode 1)\n";
				} else if (where == 1) {
					cout << "Anda bisa teleport ke `rumah` (kode 0) atau `toko` (kode 2)\n";
				} else if (where == 2) {
					cout << "Anda bisa teleport ke `lahan` (kode 1)\n";
				}
			} else
			if (where == 0) {
				if (paramInt[0] != 1) {
					throw 2;
				}
				world->getPlayer()->teleport(world->getArea(paramInt[0]));
			} else if (where == 1) {
				if (paramInt[0] == 1) {
					throw 2;
				}
				world->getPlayer()->teleport(world->getArea(paramInt[0]));
			} else if (where == 2) {
				if (paramInt[0] !=1) {
					throw 2;
				}
				world->getPlayer()->teleport(world->getArea(paramInt[0]));
			}
		} else if (perintah == "right") {
			for (int i=0; i<paramInt[0]; i++) {
				world->getPlayer()->move(KANAN);
				world->getTime()->next10Minutes();
			}
		} else if (perintah == "left") {
			for (int i=0; i<paramInt[0]; i++) {
				world->getPlayer()->move(KIRI);
				world->getTime()->next10Minutes();
			}
		} else if (perintah == "up") {
			for (int i=0; i<paramInt[0]; i++) {
				world->getPlayer()->move(ATAS);
				world->getTime()->next10Minutes();
			}
		} else if (perintah == "down") {
			for (int i=0; i<paramInt[0]; i++) {
				world->getPlayer()->move(BAWAH);
				world->getTime()->next10Minutes();
			}
		} else if (perintah == "inventory") {
			world->getPlayer()->getInventory()->listItem();
		} else if (perintah == "plow") {
			world->getPlayer()->plow();
		} else if (perintah == "put") {
			world->getPlayer()->put(paramInt[0],paramInt[1]);
		} else if (perintah == "slash") {
			world->getPlayer()->slash();
		} else if (perintah == "water") {
			world->getPlayer()->water();
		} else if (perintah == "harvest") {
			world->getPlayer()->harvest();
		} else if (perintah == "wake_up") {
			world->getDwarf(paramInt[0]-1)->wakeUp();
		} else if (perintah == "sleep") {
			world->getDwarf(paramInt[0]-1)->wakeUp();
		} else if (perintah == "status") {
			cout << 1 << " " << ((world->getDwarf(0)->getStatus())?"wake_up":"sleep") << endl;
			cout << 2 << " " << ((world->getDwarf(1)->getStatus())?"wake_up":"sleep") << endl;
			cout << 3 << " " << ((world->getDwarf(2)->getStatus())?"wake_up":"sleep") << endl;
		} else if (perintah == "save") {
			World::save("save.oph",*world);
		} else if (perintah == "sleep") {
			world->getTime()->nextDay();
		} else if (perintah == "exit") {
			delete world;
		} else if (perintah == "store") {
			
		} else if (perintah == "buy") {
			world->getPlayer()->buyItem(paramStr[0],paramInt[0]);
		} else if (perintah == "sell") {
			world->getPlayer()->sellItem(paramInt[1],paramInt[1]);
		}
		if (!(perintah == "up" || perintah=="down" || perintah=="left" || perintah=="right")) {
			world->getTime()->next10Minutes();
		}
		world->setWeather();
	}
	return true;
}
void Game::getPerintah(){
	//parsing perintah user
	int x = getch();
	string tmp;
        string dummy;
	perintah = "";
	if (x==224) {
		x = getch();
		if (x==72) {
			perintah = "up";
			paramInt[0] = 1;
		} else if (x==75) {
			perintah = "left";
			paramInt[0] = 1;
		} else if (x==77) {
			perintah = "right";
			paramInt[0] = 1;
		} else if (x==80) {
			perintah = "down";
			paramInt[0] = 1;
		}
	} else {
		cout << (char)x;
		perintah += (char)x;
		cin >> tmp;
		perintah += tmp;
		if (perintah == "new") {
			cin >> paramStr[0];
		} else if (perintah == "load") {
			cin >> paramStr[0];
		} else if (perintah == "teleport") {
			cin >> paramInt[0];
		} else if (perintah == "right") {
			cin >> paramInt[0];
		} else if (perintah == "left") {
			cin >> paramInt[0];
		} else if (perintah == "up") {
			cin >> paramInt[0];
		} else if (perintah == "down") {
			cin >> paramInt[0];
		} else if (perintah == "inventory") {
		} else if (perintah == "plow") {
		} else if (perintah == "put") {
			cin >> paramInt[0] >> paramInt[1];
		} else if (perintah == "slash") {
		} else if (perintah == "water") {
		} else if (perintah == "harvest") {
		} else if (perintah == "wake_up") {
			cin >> paramInt[0];
		} else if (perintah == "sleep") {
			cin >> paramInt[0];
		} else if (perintah == "status") {
			cin >> paramStr[0];
		} else if (perintah == "save") {
		} else if (perintah == "sleep") {
		} else if (perintah == "exit") {
		} else if (perintah == "store") {
		} else if (perintah == "buy") {
			cin >> paramStr[0] >> paramInt[0];
		} else if (perintah == "sell") {
			cin >> paramInt[0] >> paramInt[1];
		} else {
			throw 1;
		}
		cin >> dummy;
		if (dummy != "#") throw 0;
	}
}

Game::Game() {
}
Game::~Game(){
    delete world;
}