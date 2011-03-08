#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
using namespace std;

class Game() {
	private:
		string perintah;
		string parameter[5];
		int perintah[5];
	public:
		World* world;
		Game();
		void run();
		void getPerintah();
		void doPerintah() {
}
#endif