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
	weather 	= 0;
	area[RUMAH] 	= new Area(RUMAH);
	area[LAHAN] 	= new Area(LAHAN);
	area[TOKO ] 	= new Area(TOKO );
	player 		= new Player(area[RUMAH]);
        area[RUMAH]->setPlayer(player);
        area[LAHAN]->setPlayer(player);
        area[TOKO ]->setPlayer(player);
        cout << area[RUMAH]->getPlayer() << endl << endl;
	dwarf[HARVEST]	= new Dwarf(HARVEST);
	dwarf[WATER] 	= new Dwarf(WATER);
	dwarf[SLASH]	= new Dwarf(SLASH);
	time 		= new Time();
        time->setZero();
}

World::World(World& world) {
	// cctor
	weather 	= world.weather;
	time 		= new Time(*(world.getTime()));
	player 		= new Player(*(world.getPlayer()));
	area[RUMAH] = new Area(*(world.getArea(RUMAH)));
	area[LAHAN] = new Area(*(world.getArea(LAHAN)));
	area[TOKO ] = new Area(*(world.getArea(TOKO )));
	dwarf[HARVEST]= new Dwarf(*(world.getDwarf(HARVEST)));
	dwarf[WATER] 	= new Dwarf(*(world.getDwarf(WATER)));
	dwarf[SLASH]	= new Dwarf(*(world.getDwarf(SLASH)));
}

World::~World() {
	delete time;
	delete player;
	delete area[RUMAH];
	delete area[LAHAN];
	delete area[TOKO];
	delete dwarf[HARVEST];
	delete dwarf[WATER];
	delete dwarf[SLASH];
	// dtor
}
World& World::operator=(World& world) {
	weather 	= world.weather;
	time 		= new Time(*(world.getTime()));
	player 		= new Player(*(world.getPlayer()));
	area[RUMAH] = new Area(*(world.getArea(RUMAH)));
	area[LAHAN] = new Area(*(world.getArea(LAHAN)));
	area[TOKO ] = new Area(*(world.getArea(TOKO )));
	dwarf[HARVEST]= new Dwarf(*(world.getDwarf(HARVEST)));
	dwarf[WATER] 	= new Dwarf(*(world.getDwarf(WATER)));
	dwarf[SLASH]	= new Dwarf(*(world.getDwarf(SLASH)));
	return (*this);
}

void World::save(const string& pathFile,World& world){
	// menulis kondisi world ke file
	ofstream fout(pathFile.c_str(), ios::out | ios::binary);
	fout.seekp(0);
	// masih salah
	fout.write((char*)(&world),sizeof(World));
	fout.close();
}

World* World::load(const string& pathFile){
	World* world = new World();
	ifstream fin (pathFile.c_str(), ios::in | ios::binary);
	fin.seekg(0);
	// masih salah
	fin.read((char*)(&world), sizeof(World));
	fin.close();
	return world;
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

ostream& operator<<(ostream& c,World& world){
	// belum diimplementasi
	char tmp[100];
	sprintf(tmp,"%10sDesa Opeh%10s\n","","");
	c << judul << tmp << white;
	if (world.getPlayer()->getCurArea()->typeArea == 0) c << "Rumah:\n" << white;
	if (world.getPlayer()->getCurArea()->typeArea == 1) c << "Lahan Pertanian\n:" << white;
        if (world.getPlayer()->getCurArea()->typeArea == 1) c << "Toko:\n" << white;
	c << (world.getPlayer()->getCurArea());


//* UNCOMMENT FOR DEBUG
        cout << "Player position : " << new Point(world.player->getCurGrid()->getPosisi())<< endl;
        cout << "Player area : " << world.player->getCurArea()->getType() << endl;
        cout << "Area masking: " << endl;
        for (int i=0; i<10; i++) {
            for (int j=0; j<10;j++){
                cout << world.getArea(world.player->getCurArea()->getType())->getGrid(i,j)->getType();
            }
            cout << "|";
            for (int j=0; j<10;j++){
                cout << world.getArea(world.player->getCurArea()->getType())->getGrid(i,j)->getFase();
            }
            cout << endl;
        }
        cout << "Time Day: " << world.time->getDay() << " Jam " << world.time->getJam() << " Menit " << world.time->getMinutes() << endl;
        cout << "Player has status " << world.getPlayer()->getStatus();
        cout << "Player Inventory: " << endl;
        for (int i=0; i<3; i++) {
            if (world.player->getInventory()->cekSlot(i)){
                cout << "slot " << i <<" exist\n";
                cout << "tipe item bibit" << world.player->getInventory()->getSlot(0)->getTipeBibit() << endl;
                cout << "tipe item buah" << world.player->getInventory()->getSlot(0)->getTipeBuah() << endl;
                cout << "tipe item tanaman" << world.player->getInventory()->getSlot(0)->getTipeTanaman() << endl;
                cout << "price beli" << world.player->getInventory()->getSlot(0)->getCostBuy() << endl;
                cout << "price sell" << world.player->getInventory()->getSlot(0)->getCostSell() << endl;
                cout << "efek buah " << world.player->getInventory()->getSlot(0)->getEfekBuah() << endl;
                cout << "efek time " << world.player->getInventory()->getSlot(0)->getEfekTime() << endl;
            } else {
                cout << "slot "<< i << "not exist\n";
            }
        }
//*/


	c << "Perintah:\n";
	return c;
}

Area* World::getArea(int n) {
	return (area[n]);
}

Dwarf* World::getDwarf(int n) {
	return (dwarf[n]);
}

void World::kurcaciWork(){
}

Time* World::getTime() {
    return time;
}
Player* World::getPlayer() {
    return player;
}

