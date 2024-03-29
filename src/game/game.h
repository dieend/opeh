#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include "../world/world.h"
#pragma comment(lib,"Winmm.lib")
using namespace std;

class Game {
	private:
		string perintah;
		string paramStr[5];
		int paramInt[5];
                void getNew(char* kata, int done);
                void getLoad(char* kata, int done);
                void getTeleport(char* kata, int done);
                void getArah (char* kata, int done);
                void getInventory (char* kata, int done);
                void getPlow(char* kata, int done);
                void getPut(char* kata, int done);
                void getSlash(char* kata, int done);
                void getWater(char* kata, int done);
                void getHarvest(char* kata, int done);
                void getWakeUp(char* kata, int done);
                void getSleep(char* kata, int done);
                void getStatus(char* kata, int done);
                void getSave(char* kata, int done);
                void getExit(char* kata, int done);
                void getStore(char* kata, int done);
                void getBuy(char* kata,int done);
                void getSell(char* kata,int done);
                void getCheat(char * kata, int done);
                void getEat(char * kata, int done);
				void getHelp(char * kata, int done);


	public:
                char* parseLine();
		World* world;
		Game();
		void Run();
		void getPerintah();
		bool doPerintah();
		virtual ~Game();

};
#endif
