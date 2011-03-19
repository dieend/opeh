#include "game.h"
void Game::Run() {
    bool notExit = true;
    do {
        system("cls");
        if (world != NULL) cout << (*world);
        else {
            cout << "> New Game\n\n";
            cout << "> Load Game\n\n";
        }
        try {
                getPerintah();
                cout << "perintahnya : " << perintah << endl;
                cout << "int: " << (char)9 << paramInt[0] << (char) 9 << paramInt[1] << endl;
                cout << "str: " << (char)9 << paramStr[0] << (char) 9 << paramStr[1] << endl;
                notExit = doPerintah();
        } catch (int i) {
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
        }
    }while(notExit);
}

bool Game::doPerintah() {
	if (world == NULL) {
            if (perintah == "new") {
                world = new World(paramStr[0]);
            } else if (perintah == "load") {
            } else if (perintah == "exit") {
                return false;
            } else {
                throw 2;
            }

	} else {
            if (perintah == "teleport") {
                    int where = world->getPlayer()->getCurArea()->getType();
                    if (paramStr[0] == "-help") {
                            if (where ==0) {
                                    cout << "Anda bisa teleport ke `lahan`\n";
                            } else if (where == 1) {
                                    cout << "Anda bisa teleport ke `rumah` atau `toko` \n";
                            } else if (where == 2) {
                                    cout << "Anda bisa teleport ke `lahan`\n";
                            }
                            getch();
                    } else if (0>paramInt[0] || paramInt[0] >2){
                        throw 2;
                    } else if (where == 0) {
                        if (paramStr[0] == "lahan") world->getPlayer()->teleport(world->getArea(1));
                        if (paramStr[0] == "toko") throw 2;
                        if (paramStr[0] == "rumah") throw 2;
                    } else if (where == 1) {
                        if (paramStr[0] == "lahan") throw 2;
                        if (paramStr[0] == "toko") world->getPlayer()->teleport(world->getArea(2));
                        if (paramStr[0] == "rumah") world->getPlayer()->teleport(world->getArea(0));
                    } else if (where == 2) {
                        if (paramStr[0] == "lahan") world->getPlayer()->teleport(world->getArea(1));
                        if (paramStr[0] == "toko") throw 2;
                        if (paramStr[0] == "rumah") throw 2;
                    }
            } else if (perintah == "right") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(KANAN);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                    }
            } else if (perintah == "left") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(KIRI);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                    }
            } else if (perintah == "up") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(ATAS);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                    }
            } else if (perintah == "down") {
                    for (int i=0; i<paramInt[0]; i++) {
                            world->getPlayer()->move(BAWAH);
                            world->getTime()->next10Minutes(world->getPlayer()->getStatus());
                    }
            } else if (perintah == "inventory") {
                    world->getPlayer()->getInventory()->listItem();
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
                    world->getDwarf(paramInt[0]-1)->wakeUp();
            } else if (perintah == "sleep" ) {
                if (0 < paramInt[0] && paramInt[0]<=3 && world->getPlayer()->getCurArea()->getType()==LAHAN){
                    world->getDwarf(paramInt[0]-1)->wakeUp();
                } else if (0==paramInt[0] && world->getPlayer()-> getCurArea()->getType()==RUMAH){
                    world->getTime()->nextDay();
                }
            } else if (perintah == "status") {
                    cout << 1 << " " << ((world->getDwarf(0)->getStatus())?"wake_up":"sleep") << endl;
                    cout << 2 << " " << ((world->getDwarf(1)->getStatus())?"wake_up":"sleep") << endl;
                    cout << 3 << " " << ((world->getDwarf(2)->getStatus())?"wake_up":"sleep") << endl;
            } else if (perintah == "save") {
                    World::save("save.oph",*world);
            } else if (perintah == "exit") {
                    delete world;
                    world = NULL;
            } else if (perintah == "store") {
                if (world->getPlayer()->getFrontGrid()->getType()==GSTORE){
                    system("cls");
                    Toko * toko = (Toko*) world->getPlayer()->getFrontGrid();
                    toko->listItem();
                    getch();
                } else throw 2;
            } else if (perintah == "buy") {
					if (world->getPlayer()->getFrontGrid()->getType() == GSTORE) {
						world->getPlayer()->buyItem(paramStr[0],paramInt[0]);
					} else throw 2;
            } else if (perintah == "sell") {
					if (world->getPlayer()->getFrontGrid()->getType() == GSTORE) {
						world->getPlayer()->sellItem(paramInt[0],paramInt[1]);
					} else throw 2;
            }
		
	}
        if (world != NULL) {
            if (!(perintah == "up" || perintah=="down" || perintah=="left" || perintah=="right" || perintah=="sleep")) {
                world->getTime()->next10Minutes(world->getPlayer()->getStatus());
            }
            cout << world->getTime()->iscDay() << endl;

            if (world->getTime()->iscDay()) {
                world->setWeather();
                for (int i=0; i<MAXROW; i++){
                    for (int j=0; j<MAXCOLUMN; j++){
                        cout << i << j << endl;
                        world->getArea(1)->getGrid(i,j)->grow();
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
    delete kata;
}

Game::Game() {
    world = NULL;
}
Game::~Game(){
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
    if (i>2) throw 0;
}
void Game::getLoad(char* kata, int done) {
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>2) throw 0;
}
void Game::getTeleport(char* kata, int done) {
    char stmp[100];
    int i = 0;
    do {
        sscanf(kata+done,"%s",stmp);
        done+=strlen(stmp)+1;
        paramStr[i] = stmp;
    } while (paramStr[i++][0] != '#');
    if (i>2) throw 0;
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
        if (i>2) throw 0;
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw 0;
            }
        }else{
            throw 0;
        }
    }else if (perintah == "left") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw 0;
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw 0;
            }
        }else{
            throw 0;
        }
    } else if (perintah == "up") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw 0;
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw 0;
            }
        }else{
            throw 0;
        }
    } else if (perintah == "down") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw 0;
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw 0;
            }
        }else{
            throw 0;
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
        throw 0;
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
        throw 0;
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
        throw 0;
    }
    if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
        sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw 0;
        }
    }else{
        throw 0;
    }
    if ('0' <= paramStr[1][0] && paramStr[1][0]<='9') {
        sscanf(paramStr[1].c_str(),"%d",&paramInt[1]);
        if (paramInt[0]>1000){
            throw 0;
        }
    }else{
        throw 0;
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
        throw 0;
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
        throw 0;
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
        throw 0;
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
        throw 0;
    }
    if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
        sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw 0;
        }
    }else{
        throw 0;
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
        throw 0;
    }
    if (i>1){
        if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
            sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
            if (paramInt[0]>1000){
                throw 0;
            }
        }else{
            throw 0;
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
        throw 0;
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
        throw 0;
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
            throw 0;
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
        throw 0;
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
        throw 0;
    }
    if ('0' <= paramStr[1][0] && paramStr[1][0]<='9') {
        sscanf(paramStr[1].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw 0;
        }
    }else{
        throw 0;
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
        throw 0;
    }
    if ('0' <= paramStr[0][0] && paramStr[0][0]<='9') {
        sscanf(paramStr[0].c_str(),"%d",&paramInt[0]);
        if (paramInt[0]>1000){
            throw 0;
        }
    }else{
        throw 0;
    }
    if ('0' <= paramStr[1].c_str()[0] && paramStr[1][0]<='9') {
        sscanf(paramStr[1].c_str(),"%d",&paramInt[1]);
        if (paramInt[0]>1000){
            throw 0;
        }
    }else{
        throw 0;
    }
}

void Game::printPeta()
{
	cout << char(201)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	cout << char(186)<<"                  OOO   PPPP   EEEE  HH HH                             "<< char(186) << endl;
	cout << char(186)<<"  _____          OO OO  PP PP  EE    HH HH                             "<< char(186) << endl;
	cout << char(186)<<" ////"<<char(92) << char(92) << char(92)<<"         OO OO  PPPP   EEEE  HHHHH                             "<< char(186) << endl;
	cout << char(186)<<"////  "<<char(92) << char(92) << char(92) <<"        OO OO  PP     EE    HH HH                             "<< char(186) << endl;
	cout << char(186)<<"|___[]__|         OOO   PP     EEEE  HH HH                             "<< char(186) << endl;	
	cout << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	cout << char(186)<<"                                                            _____      "<< char(186) << endl;
	cout << char(186)<<"                                      " << char(31)  <<"     " << char(31)  <<"     " << char(31)  <<"        |_____|     "<< char(186) << endl;
	cout << char(186)<<"                                                                       "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"     |     |     |     |     |     |     |     |     |     |     |     "<< char(186) << endl;
	cout << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	cout << char(186)<<"                                                                       "<< char(186) << endl;
	cout << char(186)<<"                                                                       "<< char(186) << endl;
	cout << char(186)<<"                                                                       "<< char(186) << endl;
	cout << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	cout << char(186)<<"  Musim    "<<char(186)<<"   Nama Player                     "<<char(186)<<"    Item 1             "<< char(186) << endl;
	cout << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	cout << char(186)<<"  Tanggal  "<<char(186)<<"   Status                          "<<char(186)<<"    Item 2             "<< char(186) << endl;
	cout << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	cout << char(186)<<"  07.30    "<<char(186)<<"                                   "<<char(186)<<"    Item 3             "<< char(186) << endl;
	cout << char(200)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

}
