#include "game.h"

Game::run() {
	do {
		cout << world;
		getPerintah();
	}while(doPerintah());
}

Game::doPerintah() {
	if (world == NULL) {
		if (perintah[0] == "new") {
		} else if (perintah[0] == "load")
	} else {
		if (perintah[0] == "") {
		} else if (perintah[0] == "teleport") {
		} else if (perintah[0] == "right") {
		} else if (perintah[0] == "left") {
		} else if (perintah[0] == "up") {
		} else if (perintah[0] == "down") {
		} else if (perintah[0] == "inventory") {
		} else if (perintah[0] == "") {
		} else if (perintah[0] == "") {
		} else if (perintah[0] == "") {
		}
	}
	world->next10minutes();
}
Game::getPerintah(){
	//parsing input user
	nperintah = 0;
	string input;
	cin >> input
	while (input != "#") {
		perintah[nperintah++] = input;
		cin >> input;
	} 
}
