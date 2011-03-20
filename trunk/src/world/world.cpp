#include "world.h"
#include <iomanip>
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
        int temp;
	srand(temp);
}

World::~World() {
	delete time;
        delete area[RUMAH];
	delete area[LAHAN];
	delete area[TOKO];
	delete player;
	delete dwarf[HARVEST];
	delete dwarf[WATER];
	delete dwarf[SLASH];
        Utilities::getInstances().destroy();
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
	// // menulis kondisi world ke file
	// ofstream Opeh("opeh.txt", ios::out);
	
	// // masih salah
	// fout.write((char*)(&world),sizeof(World));
	// fout.close();
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
	weather = rand()*rand()%100;
	doWeather();
}

ostream& operator<<(ostream& c,World& world){
	// belum diimplementasi
	char tmp[100];
        c << (world.getPlayer()->getCurArea());
/* UNCOMMENT FOR DEBUG
        Utilities::getInstances().setColor(AQUA,BLACK);
	c << tmp;
        Utilities::getInstances().resetColor();
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
 */
        Utilities::getInstances().gotoxy(74,0);cout << "Time Day: " << world.time->getDay() << " Jam " << world.time->getJam() << " Menit " << world.time->getMinutes() << world.time->getSeason() << endl;
        Utilities::getInstances().gotoxy(74,1);cout << "Player has status " << world.getPlayer()->getStatus() << endl;
        Utilities::getInstances().gotoxy(74,2);cout << "Player has money " << world.getPlayer()->getMoney() << endl;
        Utilities::getInstances().gotoxy(74,3);cout << "Player Inventory: " << endl;
        Utilities::getInstances().gotoxy(74,4);if (world.player->getInventory()->cekSlot(0)) {cout <<setw(15) <<left <<"slot 0 exist. "; cout <<"jumlah "<< world.player->getInventory()->getJumlah(0);}if (world.player->getInventory()->cekSlot(1)) {cout << setw(15) <<left <<"slot 1 exist. "; cout<<"jumlah "<< world.player->getInventory()->getJumlah(1);}if (world.player->getInventory()->cekSlot(2)) {cout << setw(15) <<left <<"slot 2 exist. "; cout<<"jumlah "<< world.player->getInventory()->getJumlah(2);} cout << endl;
        Utilities::getInstances().gotoxy(74,5);if (world.player->getInventory()->cekSlot(0)) cout << setw(15) <<left <<"BIBIT? "<< world.player->getInventory()->getSlot(0)->isBibit();if (world.player->getInventory()->cekSlot(1)) cout << setw(15) <<left <<"BIBIT? "<< world.player->getInventory()->getSlot(1)->isBibit();if (world.player->getInventory()->cekSlot(2)) cout << setw(15) <<left <<"BIBIT? "<< world.player->getInventory()->getSlot(2)->isBibit();cout << endl;
        Utilities::getInstances().gotoxy(74,6);if (world.player->getInventory()->cekSlot(0)) cout << setw(15) <<left <<"tipe item buah" << world.player->getInventory()->getSlot(0)->getTipeBuah();if (world.player->getInventory()->cekSlot(1)) cout << setw(15) <<left <<"tipe item buah" << world.player->getInventory()->getSlot(1)->getTipeBuah();if (world.player->getInventory()->cekSlot(2)) cout << setw(15) <<left <<"tipe item buah" << world.player->getInventory()->getSlot(2)->getTipeBuah();cout << endl;
        Utilities::getInstances().gotoxy(74,7);if (world.player->getInventory()->cekSlot(0)) cout << setw(15) <<left <<"tipe item tanaman" << world.player->getInventory()->getSlot(0)->getTipeTanaman();if (world.player->getInventory()->cekSlot(1)) cout << setw(15) <<left <<"tipe item tanaman" << world.player->getInventory()->getSlot(1)->getTipeTanaman();if (world.player->getInventory()->cekSlot(2)) cout << setw(15) <<left <<"tipe item tanaman" << world.player->getInventory()->getSlot(2)->getTipeTanaman();cout << endl;
        Utilities::getInstances().gotoxy(74,8);if (world.player->getInventory()->cekSlot(0)) cout << setw(15) <<left <<"price beli" << world.player->getInventory()->getSlot(0)->getCostBuy();if (world.player->getInventory()->cekSlot(1)) cout << setw(15) <<left <<"price beli" << world.player->getInventory()->getSlot(1)->getCostBuy();if (world.player->getInventory()->cekSlot(2)) cout << setw(15) <<left <<"price beli" << world.player->getInventory()->getSlot(2)->getCostBuy();cout << endl;
        Utilities::getInstances().gotoxy(74,9);if (world.player->getInventory()->cekSlot(0)) cout << setw(15) <<left <<"price sell" << world.player->getInventory()->getSlot(0)->getCostSell();if (world.player->getInventory()->cekSlot(1)) cout << setw(15) <<left <<"price sell" << world.player->getInventory()->getSlot(1)->getCostSell();if (world.player->getInventory()->cekSlot(2)) cout << setw(15) <<left <<"price sell" << world.player->getInventory()->getSlot(2)->getCostSell();cout << endl;
        Utilities::getInstances().gotoxy(74,10);if (world.player->getInventory()->cekSlot(0)) cout << setw(15) <<left <<"efek buah " << world.player->getInventory()->getSlot(0)->getEfekBuah();if (world.player->getInventory()->cekSlot(1)) cout << setw(15) <<left <<"efek buah " << world.player->getInventory()->getSlot(1)->getEfekBuah();if (world.player->getInventory()->cekSlot(2)) cout << setw(15) <<left <<"efek buah " << world.player->getInventory()->getSlot(2)->getEfekBuah();cout << endl;
        
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

