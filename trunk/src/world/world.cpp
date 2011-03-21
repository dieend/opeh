#include "world.h"

World::World(ifstream& fin){
    cout << "world:"<<fin.tellg()<<endl;
    fin.read((char*)(this), sizeof(World));
    area[RUMAH] = new Area(RUMAH);
    cout << "lahan:"<<fin.tellg()<<endl;
    area[LAHAN] = new Area(fin,LAHAN);
    area[TOKO] = new Area(TOKO);
    cout << "player:"<<fin.tellg()<<endl;
    player = new Player(fin,area[RUMAH]);    
        area[RUMAH]->setPlayer(player);
        area[LAHAN]->setPlayer(player);
        area[TOKO ]->setPlayer(player);
        Dwarf::Field = area[LAHAN];
    	dwarf[HARVEST]	= new Dwarf(HARVEST);
	dwarf[WATER] 	= new Dwarf(WATER);
	dwarf[SLASH]	= new Dwarf(SLASH);
        area[LAHAN]->setDwarf(0,dwarf[0]);
        area[LAHAN]->setDwarf(1,dwarf[1]);
        area[LAHAN]->setDwarf(2,dwarf[2]);
        cout << "time:"<<fin.tellg()<<endl;
    time = new Time(fin);
//    Utilities::getInstances().printRumah(cout);
//    system("pause");
}

World::World() {
    player = NULL;
    dwarf[0] = NULL;
    dwarf[1] = NULL;
    dwarf[2] = NULL;
    area[0] = NULL;
    area[1] = NULL;
    area[2] = NULL;
    time = NULL;
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
        Dwarf::Field = area[LAHAN];
	dwarf[HARVEST]	= new Dwarf(HARVEST);
	dwarf[WATER] 	= new Dwarf(WATER);
	dwarf[SLASH]	= new Dwarf(SLASH);
        area[LAHAN]->setDwarf(0,dwarf[0]);
        area[LAHAN]->setDwarf(1,dwarf[1]);
        area[LAHAN]->setDwarf(2,dwarf[2]);
	time 		= new Time();
        Dwarf::setDefault(*dwarf[WATER],*dwarf[HARVEST],*dwarf[SLASH]);
        Utilities::getInstances().printRumah(cout);
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
        cout << "~world";
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
	 // masih salah
        fout.seekp(0);
        Item* dummyItem = new Item();
        cout << "world" << fout.tellp() << endl;
        fout.write((char*)(&world),sizeof(World));
        cout << "area" << fout.tellp() << endl;
        for (int i=3; i<MAXROW; i++){
            for (int j=0; j<MAXCOLUMN; j++){
                int type = world.getArea(1)->getGrid(i,j)->getType();
                if (type==GTANAMAN) {
                    fout.write((char*)&type,sizeof(int));
                    fout.write((char*)(world.getArea(1)->getGrid(i,j)),sizeof(Grid_Plant));
                } else if (type==GLAHAN){
                    fout.write((char*)&type,sizeof(int));
                    fout.write((char*)(world.getArea(1)->getGrid(i,j)),sizeof(Grid_Lahan));
                } else {
                    world.getArea(1)->getGrid(i,j)->setType(GLAHAN);
                    fout.write((char*)&type,sizeof(int));
                    fout.write((char*)(world.getArea(1)->getGrid(i,j)),sizeof(Grid_Lahan));
                    world.getArea(1)->getGrid(i,j)->setType(type);
                }
            }
        }
        cout << "player" << fout.tellp() << endl;
        fout.write((char*)(world.getPlayer()),sizeof(Player));
        cout << "inventory" << fout.tellp() << endl;
        fout.write((char*)(world.getPlayer()->getInventory()),sizeof(Inventory));
        cout << "item0" << fout.tellp() << endl;
        if (world.getPlayer()->getInventory()->cekSlot(0)) fout.write((char*)(world.getPlayer()->getInventory()->getSlot(0)),sizeof(Item)); else fout.write((char*)(dummyItem),sizeof(Item));
        cout << "item1" << fout.tellp() << endl;
        if (world.getPlayer()->getInventory()->cekSlot(1)) fout.write((char*)(world.getPlayer()->getInventory()->getSlot(1)),sizeof(Item)); else fout.write((char*)(dummyItem),sizeof(Item));
        cout << "item2" << fout.tellp() << endl;
        if (world.getPlayer()->getInventory()->cekSlot(2)) fout.write((char*)(world.getPlayer()->getInventory()->getSlot(2)),sizeof(Item)); else fout.write((char*)(dummyItem),sizeof(Item));
        cout << "time" << fout.tellp() << endl;
        fout.write((char*)(world.time),sizeof(Time));
	fout.close();
        system("pause");
}

World* World::load(const string& pathFile){
    ifstream fin (pathFile.c_str(), ios::in | ios::binary);
    fin.seekg(0);
    World* world = new World(fin);
    fin.close();
    return world;
}

void World::doWeather() {
	// belum diimplementasi
	if (weather == SUNNY) {
	}else 
	if (weather==RAIN) {
            for (int i=0; i<MAXROW; i++){
                for (int j=0; j<MAXCOLUMN; j++){
                    Grid* front = area[1]->getGrid(i,j);
                    int tipe = front->getType();
                     if (tipe == GLAHAN) {
                            Grid_Lahan* lahan = (Grid_Lahan*)front;
                            lahan->setSiram();
                    } else if (tipe == GTANAMAN) {
                            Grid_Plant* tanaman = (Grid_Plant*)front;
                            if (!(tanaman->isWatered())) {
                                    tanaman->setSiram();
                            }
                    }
                }
            }
	}else if (weather == STORM) {
            if (time->iscDay()){
//                for
            }
	}
}
void World::setWeather() {
	weather = rand()*rand()%100;
        if (weather < 60) {
            weather = SUNNY;
	}else
	if (60<= weather && weather <90) {
            weather = RAIN;
	}else {
            weather = STORM;
	}
}

ostream& operator<<(ostream& c,World& world){
	    c << (world.getPlayer()->getCurArea());
        Utilities::getInstances().gotoxy(3,55);cout << ((world.time->getSeason()==0)?"SPRING":((world.time->getSeason()==1)?"SUMMER":"FALL"));
        Utilities::getInstances().gotoxy(5,57);cout << (world.time->getDay()) << ((world.time->getDay()==1 || world.time->getDay()==21)?"st":((world.time->getDay()==2 || world.time->getDay()==22)?"nd":"th"));
        Utilities::getInstances().gotoxy(3,59);cout << (world.time->getJam()<10?"0":"")<< world.time->getJam()<<":"<< (world.time->getMinutes()<10?"0":"")<<world.time->getMinutes();
        Utilities::getInstances().gotoxy(16,55);cout << world.player->getName();
        Utilities::getInstances().gotoxy(16,57); cout << (world.player->getStatus()==0?"NORMAL":(world.player->getStatus()==1?"PARALYZED":(world.player->getStatus()==2?"POISONED":(world.player->getStatus()==3?"FULLPOWER":"SICK"))));
        Utilities::getInstances().gotoxy(26,55);cout << world.getPlayer()->getMoney() << endl;
        Utilities::getInstances().gotoxy(53,55);cout <<"             ";
        Utilities::getInstances().gotoxy(53,57);cout <<"             ";
        Utilities::getInstances().gotoxy(53,59);cout <<"             ";
        Utilities::getInstances().gotoxy(53,55);
        if (world.player->getInventory()->cekSlot(0)) {
            if (world.player->getInventory()->getSlot(0)->getIDitem()<12) cout << char(231) << " ";
            else cout <<char(235) << " ";
            cout << world.getPlayer()->getInventory()->getSlot(0)->getNama();
        } else {
            cout << "EMPTY";
        }
        Utilities::getInstances().gotoxy(53,57);
        if (world.player->getInventory()->cekSlot(1)) {
            if (world.player->getInventory()->getSlot(1)->getIDitem()<12) cout << "o ";
            else cout <<"B ";
            cout << world.getPlayer()->getInventory()->getSlot(1)->getNama();
        } else {
            cout << "EMPTY";
        }
        Utilities::getInstances().gotoxy(53,59);
        if (world.player->getInventory()->cekSlot(2)) {
            if (world.player->getInventory()->getSlot(2)->getIDitem()<12) cout << "o ";
            else cout <<"B ";
            cout << world.getPlayer()->getInventory()->getSlot(2)->getNama();
        } else {
            cout << "EMPTY";
        }
        Utilities::getInstances().gotoxy(65,55); if (world.player->getInventory()->cekSlot(0)) cout << world.getPlayer()->getInventory()->getJumlah(0);
        Utilities::getInstances().gotoxy(65,57); if (world.player->getInventory()->cekSlot(1)) cout << world.getPlayer()->getInventory()->getJumlah(1);
        Utilities::getInstances().gotoxy(65,59); if (world.player->getInventory()->cekSlot(2)) cout << world.getPlayer()->getInventory()->getJumlah(2);        
        Utilities::getInstances().gotoxy(3,51);cout << "Perintah:";
        Utilities::getInstances().printError();
        Utilities::getInstances().gotoxy(62,9);
        if (world.weather==SUNNY){
            c << "SUNNY";
        } else if (world.weather==RAIN) {
            c << "RAIN";
        } else {
            c << "STORM";
        }
        Utilities::getInstances().gotoxy(28,59);
        Grid* depan = world.getPlayer()->getFrontGrid();
        if (depan != NULL){
            int type = depan->getType();
            if (type==HKURCACI){
                cout<< "Freedom";
            } else if (type == WKURCACI){
                cout << "Justice";
            } else if (type == SKURCACI){
                cout << "Destiny";
            } else if (type == GTANAMAN){
                Grid_Plant* gp = (Grid_Plant*) depan;
                Item* brg = Item::makeBuah(gp);
                cout << brg->getNama();
                cout << " (" << gp->getUmur() <<")";
            } else if (type == GSTORE){
                cout << "Store";
            } else if (type == GSAVE){
                cout << "Diary";
            } else if (type == GBED){
                cout << "Bed";
            }
        } else {
                cout << "                               ";
        }
	return c;
}

Area* World::getArea(int n) {
	return (area[n]);
}

Dwarf* World::getDwarf(int n) {
	return (dwarf[n]);
}
Time* World::getTime() {
    return time;
}
Player* World::getPlayer() {
    return player;
}

int World::getWeather(){
    return weather;
}