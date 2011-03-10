#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <conio.h>
#include "../world/world.h"
using namespace std;

class Game {
	private:
		string perintah;
		string paramStr[5];
		int paramInt[5];
	public:
		World* world;
		Game();
		void Run();
		void getPerintah();
		bool doPerintah();
		virtual ~Game();
};
#endif
