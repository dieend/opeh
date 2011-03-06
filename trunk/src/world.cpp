#include "world.h"
#define RUMAH 0
#define LAHAN 1
#define TOKO 2
#define HARVEST 0
#define WATER 1
#define SLASH 2

// volatile unsigned long randomizer()
// {
	// unsigned long tsc;
	// asm("rdtsc":"=A"(tsc));
	// return tsc;
// }

World::World(){
	// ctor
	weather = 0;
	area[RUMAH] = new Area(RUMAH);
	area[LAHAN] = new Area(LAHAN);
	area[TOKO ] = new Area(TOKO );
	player = new Player();
	kurcaci[HARVEST] = new Kurcaci(HARVEST);
	kurcaci[WATER] = new Kurcaci(WATER);
	kurcaci[SLASH] = new Kurcaci(SLASH);
	time = new Time();
}

World::World(World& world) {
	// cctor
	time = new Time(world->time);
	player = new Player(world->player);
	area[RUMAH] = new Area(world->area[RUMAH];
	area[LAHAN] = new world.area[LAHAN];
	area[TOKO ] = world.area[TOKO ];
	weather = world.weather;
}

World::~World() {
	// dtor
	cout << "Terima Kasih telah bermain bersama kami ^^\n";
}
World& World::operator=(const World& world) {
	time = world.time;
	player = world.player;
	area[RUMAH] = world.area[RUMAH];
	area[LAHAN] = world.area[LAHAN];
	area[TOKO ] = world.area[TOKO ];
	weather = world.weather;
	return (*this);
}

void World::save(const string& pathFile,const World& world){
	// menulis kondisi world ke file
	ofstream fout(pathFile.c_str(), ios::out | ios::binary);
	fout.seekp(0);
	fout.write((char*)(&world),sizeof(World));
	fout.close();
}

void World::load(const string& pathFile, World& world){
	ifstream fin (pathFile.c_str(), ios::in | ios::binary);
	fin.seekg(0);
	fin.read((char*)(&world), sizeof(World));
	fin.close();
}

void World::doWeather() {
	if (weather < 9000) {
		cout << "normal\n";
	}else 
	if (9000<= weather && weather <=9900) {
		cout << "raining\n";
	}else {
		cout << "tornado";
	}
}
void World::setWeather() {
	int temp;
	srand(temp);
	weather = rand()*rand()%10000;
	doWeather();
}

ostream& operator<<(ostream& c,const World& world){
	c << world.area[2].typeArea<< endl;
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			c<< world.area[2].grid[i][j];
		}
		c<< endl;
	}
	return c;
}
