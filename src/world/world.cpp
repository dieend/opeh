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

World::World() {
}
World::World(string nama){
	// ctor
	weather 	= 0;
	area[RUMAH] 	= new Area(RUMAH);
	area[LAHAN] 	= new Area(LAHAN);
	area[TOKO ] 	= new Area(TOKO );
	player 		= new Player(area[RUMAH],2000,nama);
        area[RUMAH]->setPlayer(player);
        area[LAHAN]->setPlayer(player);
        area[TOKO ]->setPlayer(player);
	dwarf[HARVEST]	= new Dwarf(HARVEST);
	dwarf[WATER] 	= new Dwarf(WATER);
	dwarf[SLASH]	= new Dwarf(SLASH);
	time 		= new Time();
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
    cout << "world destruct";
	delete time;
        delete area[RUMAH];
	delete area[LAHAN];
	delete area[TOKO];
	delete player;
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
	if (weather < 50) {
		cout << "normal\n";
	}else 
	if (50<= weather && weather <=80) {
		cout << "raining\n";
	}else {
		cout << "tornado";
	}
        system("pause");
}
void World::setWeather() {
	int temp;
	srand(temp);
	weather = rand()*rand()%100;
	doWeather();
}

ostream& operator<<(ostream& c,World& world){
	// belum diimplementasi
	char tmp[100];
	sprintf(tmp,"%10sDesa Opeh%10s\n","","");
	c << judul << tmp << white;
	if (world.getPlayer()->getCurArea()->typeArea == 0) c << "Rumah:\n" << white;
	if (world.getPlayer()->getCurArea()->typeArea == 1) c << "Lahan Pertanian:\n" << white;
        if (world.getPlayer()->getCurArea()->typeArea == 2) c << "Toko:\n" << white;
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
        cout << "Player has status " << world.getPlayer()->getStatus() << endl;
        cout << "Player has money " << world.getPlayer()->getMoney() << endl;
        cout << "Player Inventory: " << endl;
        if (world.player->getInventory()->cekSlot(0)) {cout << "slot 0 exist. "; cout << "jumlah "<< world.player->getInventory()->getJumlah(0) << "\t\t\t";}if (world.player->getInventory()->cekSlot(1)) {cout << "slot 1 exist. "; cout << "jumlah "<< world.player->getInventory()->getJumlah(1) << "\t\t\t";}if (world.player->getInventory()->cekSlot(2)) {cout << "slot 2 exist. "; cout << "jumlah "<< world.player->getInventory()->getJumlah(2) << "\t\t\t";} cout << endl;
        if (world.player->getInventory()->cekSlot(0)) cout << "BIBIT? "<< world.player->getInventory()->getSlot(0)->isBibit()<< "\t\t\t";if (world.player->getInventory()->cekSlot(1)) cout << "BIBIT? "<< world.player->getInventory()->getSlot(1)->isBibit()<< "\t\t\t";if (world.player->getInventory()->cekSlot(2)) cout << "BIBIT? "<< world.player->getInventory()->getSlot(2)->isBibit()<< "\t\t\t";cout << endl;
        if (world.player->getInventory()->cekSlot(0)) cout << "tipe item buah" << world.player->getInventory()->getSlot(0)->getTipeBuah() << "\t\t\t";if (world.player->getInventory()->cekSlot(1)) cout << "tipe item buah" << world.player->getInventory()->getSlot(1)->getTipeBuah() << "\t\t\t";if (world.player->getInventory()->cekSlot(2)) cout << "tipe item buah" << world.player->getInventory()->getSlot(2)->getTipeBuah() << "\t\t\t";cout << endl;
        if (world.player->getInventory()->cekSlot(0)) cout << "tipe item tanaman" << world.player->getInventory()->getSlot(0)->getTipeTanaman() << "\t\t\t";if (world.player->getInventory()->cekSlot(1)) cout << "tipe item tanaman" << world.player->getInventory()->getSlot(1)->getTipeTanaman() << "\t\t\t";if (world.player->getInventory()->cekSlot(2)) cout << "tipe item tanaman" << world.player->getInventory()->getSlot(2)->getTipeTanaman() << "\t\t\t";cout << endl;
        if (world.player->getInventory()->cekSlot(0)) cout << "price beli" << world.player->getInventory()->getSlot(0)->getCostBuy() << "\t\t\t";if (world.player->getInventory()->cekSlot(1)) cout << "price beli" << world.player->getInventory()->getSlot(1)->getCostBuy() << "\t\t\t";if (world.player->getInventory()->cekSlot(2)) cout << "price beli" << world.player->getInventory()->getSlot(2)->getCostBuy() << "\t\t\t";cout << endl;
        if (world.player->getInventory()->cekSlot(0)) cout << "price sell" << world.player->getInventory()->getSlot(0)->getCostSell() << "\t\t\t";if (world.player->getInventory()->cekSlot(1)) cout << "price sell" << world.player->getInventory()->getSlot(1)->getCostSell() << "\t\t\t";if (world.player->getInventory()->cekSlot(2)) cout << "price sell" << world.player->getInventory()->getSlot(2)->getCostSell() << "\t\t\t";cout << endl;
        if (world.player->getInventory()->cekSlot(0)) cout << "efek buah " << world.player->getInventory()->getSlot(0)->getEfekBuah() << "\t\t\t";if (world.player->getInventory()->cekSlot(1)) cout << "efek buah " << world.player->getInventory()->getSlot(1)->getEfekBuah() << "\t\t\t";if (world.player->getInventory()->cekSlot(2)) cout << "efek buah " << world.player->getInventory()->getSlot(2)->getEfekBuah() << "\t\t\t";cout << endl;
        if (world.player->getInventory()->cekSlot(0)) cout << "efek time " << world.player->getInventory()->getSlot(0)->getEfekTime() << "\t\t\t";if (world.player->getInventory()->cekSlot(1)) cout << "efek time " << world.player->getInventory()->getSlot(1)->getEfekTime() << "\t\t\t";if (world.player->getInventory()->cekSlot(2)) cout << "efek time " << world.player->getInventory()->getSlot(2)->getEfekTime() << "\t\t\t";cout << endl;
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

