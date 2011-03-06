#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "time.h"
#include "area.h"
#include "player.h"
using namespace std;

class World{
private:
	Time* time;
	Player* player;
	Area* area[3];
	Kurcaci* kurcaci[3];
	int weather;
	void doWeather();
	
public:
	World(); // ctor
	World(World&); // cctor
	virtual ~World(); // dtor
	World& operator=(const World&);
	friend ostream& operator<<(ostream&,const World&);
	static void save(const string&,const World&); // menulis kondisi world ke file
	static World* load(const string&);  
	void setWeather();
	Area* getArea(int);
	Kurcaci* getKurcaci(int);
	void kurcaciWork();
};
#endif
