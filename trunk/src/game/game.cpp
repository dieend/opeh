#include "game.h"

void Game::Run() {
    bool notExit = true;
    
    do {
        if (world != NULL) {
            cout << (*world);
        } else {
            Utilities::getInstances().printAwal(cout);
        }
        try {
            if (world==NULL) {
                Utilities::getInstances().gotoxy(3,53);
                cout<<"                                                     ";
                Utilities::getInstances().gotoxy(3,53);
            } else {
                Utilities::getInstances().gotoxy(3,52);
                cout<<"                                                     ";
                Utilities::getInstances().gotoxy(3,52);
            }
            getPerintah();
            notExit = doPerintah();
        } catch (int i) {
            Utilities::getInstances().gotoxy(3,53);
            if (i==0) {
                    cerr << "input tidak sesuai format!\n";
            } else if (i==1) {
                    cerr << "tidak ada perintah yang dimaksud\n";
            } else if (i==2) {
                    cerr << "perintah ini tidak bisa dilakukan disini\n";
            } else {
            }
            int x = getch();
            if (x==224) getch();
        } catch (const char * kata){
            Utilities::getInstances().setError(kata);
        }
    }while(notExit);
}

bool Game::doPerintah() {
	if (world == NULL) {
            if (perintah == "new") {
                system("cls");
                Utilities::getInstances().gotoxy(10,0);
                Utilities::getInstances().scenario(paramStr[0]);
                world = new World(paramStr[0]);
//				PlaySound(NULL,0,0);
//				PlaySound("02-spring.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC|SND_NOSTOP);
            } else if (perintah == "load") {
                world = World::load("save.oph");
				if (world->getTime()->getSeason() == 0) {
//					PlaySound(NULL,0,0);
//					PlaySound("02-spring.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC|SND_NOSTOP);
				} else if (world->getTime()->getSeason() == 1) {
//					PlaySound(NULL,0,0);
//					PlaySound("03-summer.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC|SND_NOSTOP);
				} else if (world->getTime()->getSeason() == 2) {
//					PlaySound(NULL,0,0);
//					PlaySound("04-fall.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC|SND_NOSTOP);
				}
            } else if (perintah == "exit") {
                system("cls");
                return false;
            } else {
                throw "The command can't be done here";
            }

	} else {
            if (perintah == "teleport") {

                int where = world->getPlayer()->getCurArea()->getType();
                if (paramStr[0] == "-help") {
                        if (where ==0) {
                                cout << "You can teleport to `lahan`\n";
                        } else if (where == 1) {
                                cout << "You can teleport to `rumah` atau `toko` \n";
                        } else if (where == 2) {
                                cout << "You can teleport to `lahan`\n";
                        }
                        getch();
                } else if (0>paramInt[0] || paramInt[0] >2){
                    throw "It's nowhere";
                } else if (world->getWeather() != STORM) {
                    if(where == 0) {
                        if (paramStr[0] == "lahan") world->getPlayer()->teleport(world->getArea(1));
                        if (paramStr[0] == "toko") throw "You can't go from here";
                        if (paramStr[0] == "rumah") throw "You can't go from here";
                    } else if (where == 1) {
                        if (paramStr[0] == "lahan") throw "You can't go from here";
                        if (paramStr[0] == "toko") world->getPlayer()->teleport(world->getArea(2));
                        if (paramStr[0] == "rumah") world->getPlayer()->teleport(world->getArea(0));
                    } else if (where == 2) {
                        if (paramStr[0] == "lahan") world->getPlayer()->teleport(world->getArea(1));
                        if (paramStr[0] == "toko") throw "You can't go from here";
                        if (paramStr[0] == "rumah") throw "You can't go from here";
                    }
                } else throw "The place can't be accessed";
            } else if (perintah == "right") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(KANAN);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                            world->getPlayer()->setStatus(world->getTime()->getSTime());
                            Dwarf::setmap();
                            Utilities::getInstances().gotoxy(0,75);
                            world->getPlayer()->setMoney(Dwarf::nextMove(*(world->getDwarf(0)),*(world->getDwarf(1)),*(world->getDwarf(2)))+world->getPlayer()->getMoney());
                            world->doWeather();
                    }
            } else if (perintah == "left") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(KIRI);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                            world->getPlayer()->setStatus(world->getTime()->getSTime());
                            Dwarf::setmap();
                            Utilities::getInstances().gotoxy(0,75);
                            world->getPlayer()->setMoney(Dwarf::nextMove(*(world->getDwarf(0)),*(world->getDwarf(1)),*(world->getDwarf(2)))+world->getPlayer()->getMoney());
                            world->doWeather();
                    }
            } else if (perintah == "up") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(ATAS);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                            world->getPlayer()->setStatus(world->getTime()->getSTime());
                            Dwarf::setmap();
                            Utilities::getInstances().gotoxy(0,75);
                            world->getPlayer()->setMoney(Dwarf::nextMove(*(world->getDwarf(0)),*(world->getDwarf(1)),*(world->getDwarf(2)))+world->getPlayer()->getMoney());
                            world->doWeather();
                    }
            } else if (perintah == "down") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(BAWAH);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                            world->getPlayer()->setStatus(world->getTime()->getSTime());
                            Dwarf::setmap();
                            Utilities::getInstances().gotoxy(0,75);
                            world->getPlayer()->setMoney(Dwarf::nextMove(*(world->getDwarf(0)),*(world->getDwarf(1)),*(world->getDwarf(2)))+world->getPlayer()->getMoney());
                            world->doWeather();
                    }
            } else if (perintah == "inventory") {
                    world->getPlayer()->getInventory()->listDescription();
            } else if (perintah == "plow") {
                    world->getPlayer()->plow();
            } else if (perintah == "put") {
                    world->getPlayer()->put(paramInt[0],paramInt[1]);
            } else if (perintah == "slash") {
                    world->getPlayer()->slash();
            } else if (perintah == "water") {
                    world->getPlayer()->water();
            } else if (perintah == "harvest") {
                    world->getPlayer()->harvest();
            } else if (perintah == "wake_up") {
                    world->getDwarf(paramInt[0])->wakeUp();
            } else if (perintah == "sleep" ) {
                if (0 <= paramInt[0] && paramInt[0]<3 && world->getPlayer()->getCurArea()->getType()==LAHAN){
                    cout << world->getDwarf(paramInt[0])->getStatus();
                    world->getDwarf(paramInt[0])->sleep();
                } else if (world->getPlayer()->getFrontGrid()!=NULL && world->getPlayer()->getFrontGrid()->getType()==GBED){
                    world->getTime()->nextDay();
                    world->getPlayer()->getCurGrid()->setType(GJALAN);
                    world->getPlayer()->setCurGrid(world->getPlayer()->getCurArea()->getGrid(6,4));
                    world->getPlayer()->getCurArea()->getGrid(6,4)->setType(GPLAYER);
                    world->getPlayer()->setArah(1);
                }else {
                    throw "You can't do it here";
                }
            } else if (perintah == "status") {
                    cout << 0 << " " << ((world->getDwarf(0)->getStatus())?"wake_up":"sleep") << endl;
                    cout << 1 << " " << ((world->getDwarf(1)->getStatus())?"wake_up":"sleep") << endl;
                    cout << 2 << " " << ((world->getDwarf(2)->getStatus())?"wake_up":"sleep") << endl;
            } else if (perintah == "save") {
                if (world->getPlayer()->getFrontGrid()!=NULL && world->getPlayer()->getFrontGrid()->getType()== GSAVE){
                    World::save("save.oph",*world);
                } else {
                    string kata = "You can't do it here";
                    throw kata.c_str();
                }
            } else if (perintah == "exit") {
                if (world->getPlayer()->getCurArea()->getType()==RUMAH){
                    system("cls");
                    delete world;
                    world = NULL;
                    return false;
                } else {
                    throw "You can't do it here";
                }
            } else if (perintah == "store") {
                if (world->getPlayer()->getFrontGrid()->getType()==GSTORE){
                    system("cls");
                    Toko * toko = (Toko*) world->getPlayer()->getFrontGrid();
                    toko->listItem();
                    cin.get();
                } else throw "The command must be used in front of store";
            } else if (perintah == "buy") {
                if (world->getPlayer()->getFrontGrid()->getType() == GSTORE) {
                        world->getPlayer()->buyItem(paramStr[0],paramInt[0]);
                } else throw "The command must be used in front of store";
            } else if (perintah == "sell") {
                if (world->getPlayer()->getFrontGrid()->getType() == GSTORE) {
                        world->getPlayer()->sellItem(paramInt[0],paramInt[1]);
                } else throw "The command must be used in front of store";
            } else if (perintah == "eat") {
                world->getPlayer()->eat(paramInt[0]);
            } else if (perintah == "cheat") {
                if (paramStr[0] == "nextday") {
                    world->getTime()->nextDay();
                } else if (paramStr[0] == "nextseason") {
                    world->getTime()->nextSeason();
                } else if (paramStr[0] == "teleport") {
                    if (paramStr[1] == "lahan") world->getPlayer()->teleport(world->getArea(1));
                    if (paramStr[1] == "toko") world->getPlayer()->teleport(world->getArea(2));
                    if (paramStr[1] == "rumah") world->getPlayer()->teleport(world->getArea(0));
                } else if (paramStr[0] == "randomize") {
                    world->setWeather();
                } else if (paramStr[0] == "status") {
                    world->getPlayer()->setStatus(paramInt[0]);
                } else if (paramStr[0] == "grow") {
                    for (int i = 1; i <= paramInt[0]; i++) {
                        cout << paramInt[0] << endl;
                        for (int j = 3; j < MAXROW; j++) {
                            for (int k = 0; k < MAXCOLUMN; k++) {
                                    if (world->getArea(1)->getGrid(j,k)->getType() == GTANAMAN) {
                                            Grid_Plant * tanam = (Grid_Plant*) world->getArea(1)->getGrid(j,k);
                                            tanam->setSiram();
                                    }
                            }
                        }
                        for (int j=0; j<MAXROW; j++){
                                for (int k=0; k<MAXCOLUMN; k++) {
                                        world->getArea(1)->getGrid(j,k)->grow(world->getTime()->getSeason());
                                }
                        }
                    }
                } else if (paramStr[0] == "money") {
                    world->getPlayer()->setMoney(99999999);
                } else if (paramStr[0] == "buy") {
                    world->getPlayer()->buyItem(paramStr[1],paramInt[0]);
                }
            }
	}
        if (world != NULL) {
            if (!(perintah == "up" || perintah=="down" || perintah=="left" || perintah=="right" || perintah=="sleep")) {
                world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                Dwarf::setmap();
                world->getPlayer()->setMoney(Dwarf::nextMove(*(world->getDwarf(0)),*(world->getDwarf(1)),*(world->getDwarf(2)))+world->getPlayer()->getMoney());
                if (world->getPlayer()->getStatus() == 2) {
                    world->getPlayer()->teleport(world->getArea(0));
                    world->getPlayer()->getCurGrid()->setType(GJALAN);
                    world->getPlayer()->setCurGrid(world->getPlayer()->getCurArea()->getGrid(6,4));
                    world->getPlayer()->getCurArea()->getGrid(6,4)->setType(GPLAYER);
                    world->getPlayer()->setArah(1);
                }
                world->getPlayer()->setStatus(world->getTime()->getSTime());
                world->doWeather();
            }

            if (world->getTime()->iscDay()) {
                Dwarf::setDefault(*(world->getDwarf(0)),*(world->getDwarf(1)),*(world->getDwarf(2)));
                world->setWeather();
		world->getPlayer()->setStatus(0);
                for (int i=0; i<MAXROW; i++){
                    for (int j=0; j<MAXCOLUMN; j++){
                        world->getArea(1)->getGrid(i,j)->grow(world->getTime()->getSeason());
                    }
                }
            }
        }
	return true;
}
void Game::getPerintah(){
    //terima perintah user
    char * kata;
    kata = parseLine();
    char stmp[100];
    int done = 0;
    sscanf(kata,"%s",stmp);
    perintah = stmp;
    done = perintah.size()+1;
    if (perintah == "new") getNew(kata,done);
    else if (perintah == "load") getLoad(kata,done);
    else if (perintah == "teleport") getTeleport(kata,done);
    else if (perintah == "right" || perintah == "left" || perintah == "down" || perintah == "up") getArah(kata,done);
    else if (perintah == "inventory") getInventory(kata,done);
    else if (perintah == "plow") getPlow(kata,done);
    else if (perintah == "put") getPut(kata,done);
    else if (perintah == "slash") getSlash(kata,done);
    else if (perintah == "water") getWater(kata,done);
    else if (perintah == "harvest") getHarvest(kata,done);
    else if (perintah == "wake_up") getWakeUp(kata,done); 
    else if (perintah == "sleep") getSleep(kata,done);
    else if (perintah == "status") getStatus(kata,done);
    else if (perintah == "save") getSave(kata,done);
    else if (perintah == "exit") getExit(kata,done);
    else if (perintah == "store") getStore(kata,done);
    else if (perintah == "buy") getBuy(kata,done); 
    else if (perintah == "sell")getSell(kata,done);
	else if (perintah == "cheat") getCheat(kata,done);
	else if (perintah == "eat") getEat(kata,done);
    delete kata;
}

Game::Game() {
    world = NULL;
//	PlaySound("01-title.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC|SND_NOSTOP);
}
Game::~Game(){
    cout << "dtor game\n";
    delete world;
}

char* Game::parseLine() {
    char* kata = new char[100];
    char c;
    int i = 0;
    bool shortcut = false;
    do {
        c = getch();
        if ((int)c == -32) {
            shortcut = true;
            c = getch();
            if (c==72) {
                string str =  "up 1 #";
                copy(str.begin(),str.end(),kata);
                kata[str.size()] = '\0';
//                paramInt[0] = 1;
            } else if (c==75) {
                string str =  "left 1 #";
                copy(str.begin(),str.end(),kata);
                kata[str.size()] = '\0';
//                perintah = "left";
//                paramInt[0] = 1;
            } else if (c==77) {
                string str =  "right 1 #";
                copy(str.begin(),str.end(),kata);
                kata[str.size()] = '\0';
//                perintah = "right";
//                paramInt[0] = 1;
            } else if (c==80) {
                string str =  "down 1 #";
                copy(str.begin(),str.end(),kata);
                kata[str.size()] = '\0';
//                perintah = "down";
//                paramInt[0] = 1;
            } else {
//                perintah = "fail";
            }
        } else if (('0' <= c && c<='9') || ('a'<=c && c<='z')) {
            kata[i++] = c;
            kata[i]='\0';
            cout << c;
        } else if ('A'<=c && c<='Z') {
            kata[i++] = (char)(c+32);
            kata[i]='\0';
            cout << c;
        } else if ((int) c == 32) {
            kata[i++] = ' ';
            kata[i] = '\0';
            cout << " ";
        } else if ((int)c==8) {
            if (i>0) kata[--i] = '\0';
            cout << "\b \b";
        } else {
            kata[i++] = c;
            kata[i] = '\0';
            cout << c;
        }
    } while (c!= '#' && !shortcut);
    if (!shortcut) {
        kata[i++] = ' ';
        kata[i++] = '#';
        kata[i] = '\0';
    }
    
    return kata;
}
void Game::getNew(char* kata, int done) {
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>2) throw "Input doesn't match any format";
}
void Game::getLoad(char* kata, int done) {
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>2) throw "Input doesn't match any format";
}
void Game::getTeleport(char* kata, int done) {
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>2) throw "Input doesn't match any format";
}
void Game::getArah (char* kata, int done) {
    char stmp[100];
    int i = 0;
    if (perintah == "right") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw "Input doesn't match any format";
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw "Input doesn't match any format";
            }
        }else{
            throw "Input doesn't match any format";
        }
    }else if (perintah == "left") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw "Input doesn't match any format";
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw "Input doesn't match any format";
            }
        }else{
            throw "Input doesn't match any format";
        }
    } else if (perintah == "up") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw "Input doesn't match any format";
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw "Input doesn't match any format";
            }
        }else{
            throw "Input doesn't match any format";
        }
    } else if (perintah == "down") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw "Input doesn't match any format";
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw "Input doesn't match any format";
            }
        }else{
            throw "Input doesn't match any format";
        }
    }
}
void Game::getInventory (char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getPlow(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getPut(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>3){
        throw "Input doesn't match any format";
    }
    if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
        sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw "Input doesn't match any format";
        }
    }else{
        throw "Input doesn't match any format";
    }
    if ('0' <= paramStr[1][0] && paramStr[1][0]<='9') {
        sscanf(paramStr[1].c_str(),"%d",&paramInt[1]);
        if (paramInt[0]>1000){
            throw "Input doesn't match any format";
        }
    }else{
        throw "Input doesn't match any format";
    }
}
void Game::getSlash(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getWater(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getHarvest(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getWakeUp(char* kata, int done){
    char stmp[100];
   int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>2){
        throw "Input doesn't match any format";
    }
    if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
        sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw "Input doesn't match any format";
        }
    }else{
        throw "Input doesn't match any format";
    }
}
void Game::getSleep(char* kata, int done){
      char stmp[100];
   int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>2){
        throw "Input doesn't match any format";
    }
    if (i>1){
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw "Input doesn't match any format";
            }
        }else{
            throw "Input doesn't match any format";
        }
    } else {
        paramInt[0] = 0;
    }
}
void Game::getStatus(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getSave(char* kata, int done){
    char stmp[100];
   int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getExit(char* kata, int done){
    char stmp[100];
   int i = 0;
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw "Input doesn't match any format";
        }
    }
void Game::getStore(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>1){
        throw "Input doesn't match any format";
    }
}
void Game::getBuy(char* kata, int done) {
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>3){
        throw ("Input doesn't match any format");
    }
    if ('0' <= paramStr[1][0] && paramStr[1][0]<='9') {
        sscanf(paramStr[1].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw ("Input doesn't match any format");
        }
    }else{
        throw ("Input doesn't match any format");
    }
}
void Game::getSell(char* kata, int done){
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>3){
        throw ("Input doesn't match any format");
    }
    if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
        sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw "Input doesn't match any format";
        }
    }else{
        throw ("Input doesn't match any format");
    }
    if ('0' <= paramStr[1].c_str()[0] && paramStr[1][0]<='9') {
        sscanf(paramStr[1].c_str(),"%d",&paramInt[1]);
        if (paramInt[0]>1000){
            throw ("Input doesn't match any format");
        }
    }else{
        throw ("Input doesn't match any format");
    }
}

void Game::getCheat(char * kata, int done) {
	char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
	if ((paramStr[0] == "status") || (paramStr[0] == "grow")) {
		cout << paramStr[1] << endl;
		sscanf(paramStr[1].c_str(),"%d",&paramInt[0]);
	} else if (paramStr[0] == "buy") {
		sscanf(paramStr[2].c_str(),"%d",&paramInt[0]);
	}
}

void Game::getEat(char * kata, int done) {
	char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
	if (i > 2) {
		throw "Input doesn't match any format";
	}
	if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
		sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
	} else {
		throw "Input doesn't match any format";
	}
}
		