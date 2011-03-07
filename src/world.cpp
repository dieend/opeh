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
	weather 		= 0;
	area[RUMAH] 	= new Area(RUMAH);
	area[LAHAN] 	= new Area(LAHAN);
	area[TOKO ] 	= new Area(TOKO );
	player 			= new Player();
	kurcaci[HARVEST]= new Kurcaci(HARVEST);
	kurcaci[WATER] 	= new Kurcaci(WATER);
	kurcaci[SLASH]	= new Kurcaci(SLASH);
	time 			= new Time();
}

World::World(World& world) {
	// cctor
	weather 	= world.weather;
	time 		= new Time(*(world.getTime()));
	player 		= new Player(*(world.getPlayer()));
	area[RUMAH] = new Area(*(world.getArea(RUMAH)));
	area[LAHAN] = new Area(*(world.getArea(LAHAN)));
	area[TOKO ] = new Area(*(world.getArea(TOKO )));
	kurcaci[HARVEST]= new Kurcaci(*(world.getKurcaci(HARVEST)));
	kurcaci[WATER] 	= new Kurcaci(*(world.getKurcaci(WATER)));
	kurcaci[SLASH]	= new Kurcaci(*(world.getKurcaci(SLASH)));
}

World::~World() {
	delete time;
	delete player;
	delete area[RUMAH];
	delete area[LAHAN];
	delete area[TOKO];
	delete kurcaci[HARVEST];
	delete kurcaci[WATER];
	delete kurcaci[SLASH];
	// dtor
}
World& World::operator=(const World& world) {
	weather 	= world.weather;
	time 		= new Time(*(world.getTime()));
	player 		= new Player(*(world.getPlayer()));
	area[RUMAH] = new Area(*(world.getArea(RUMAH)));
	area[LAHAN] = new Area(*(world.getArea(LAHAN)));
	area[TOKO ] = new Area(*(world.getArea(TOKO )));
	kurcaci[HARVEST]= new Kurcaci(*(world.getKurcaci(HARVEST)));
	kurcaci[WATER] 	= new Kurcaci(*(world.getKurcaci(WATER)));
	kurcaci[SLASH]	= new Kurcaci(*(world.getKurcaci(SLASH)));
	return (*this);
}

void World::save(const string& pathFile,const World& world){
	// menulis kondisi world ke file
	ofstream fout(pathFile.c_str(), ios::out | ios::binary);
	fout.seekp(0);
	// masih salah
	fout.write((char*)(&world),sizeof(World));
	fout.close();
}

void World::load(const string& pathFile, World& world){
	ifstream fin (pathFile.c_str(), ios::in | ios::binary);
	fin.seekg(0);
	// masih salah
	fin.read((char*)(&world), sizeof(World));
	fin.close();
}

void World::doWeather() {
	// belum diimplementasi
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

ostream& operator<<(ostream& c,const World* world){
	// belum diimplementasi
	if (world != NULL) {
		char tmp[100];
		sprintf(tmp,"%10sDesa Opeh%10s\n","s","s");
		c << judul << tmp << white;
		if (world->getPlayer()->getCurArea()->typeArea == 0) c << "Rumah:\n";
		if (world->getPlayer()->getCurArea()->typeArea == 1) c << "Lahan Pertanian\n";
		c << *(world->getPlayer()->getCurArea());
	} else {
		c << "> New Game\n\n";
		c << "> Load Game\n\n\n\n\n\n";
	}
	c << "Perintah:\n";
	return c;
}

Area* getArea(int n) {
	return (area[n]);
}

Kurcaci* getKurcaci(int n) {
	return kurcaci[n];
}

void kurcaciWork(){
}