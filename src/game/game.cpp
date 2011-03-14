#include "game.h"
void Game::Run() {
    bool notExit = true;
    do {
        system("cls");
        cout << world;
        if (world != NULL) cout << (*world);
        else {
            cout << "> New Game\n\n";
            cout << "> Load Game\n\n\n\n\n\n";
        }
        try {
                getPerintah();
                cout << "perintahnya : " << perintah << endl;
                cout << "int: " << (char)9 << paramInt[0] << (char) 9 << paramInt[1] << endl;
                cout << "str: " << (char)9 << paramStr[0] << (char) 9 << paramStr[1] << endl;
//                int x=getch();
//                if (x==224) getch();
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
                                    cout << "Anda bisa teleport ke `lahan` (kode 1)\n";
                            } else if (where == 1) {
                                    cout << "Anda bisa teleport ke `rumah` (kode 0) atau `toko` (kode 2)\n";
                            } else if (where == 2) {
                                    cout << "Anda bisa teleport ke `lahan` (kode 1)\n";
                            }
                            getch();
                    } else
                    if (where == 0) {
                            if (paramInt[0] != 1) {
                                    throw 2;
                            }
                            world->getPlayer()->teleport(world->getArea(paramInt[0]));
                    } else if (where == 1) {
                            if (paramInt[0] == 1) {
                                    throw 2;
                            }
                            world->getPlayer()->teleport(world->getArea(paramInt[0]));
                    } else if (where == 2) {
                            if (paramInt[0] !=1) {
                                    throw 2;
                            }
                            world->getPlayer()->teleport(world->getArea(paramInt[0]));
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
        cout << " C";
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
        cout << " B";
	return true;
}
void Game::getPerintah(){
	//terima perintah user
    char c; int i=0;
    char stmp[100],kata[100];
    int itmp;
    bool shortcut = false;
    do {
        c = getch();
        if ((int)c == -32) {
            shortcut = true;
            c = getch();
            if (c==72) {
                perintah = "up";
                paramInt[0] = 1;
            } else if (c==75) {
                perintah = "left";
                paramInt[0] = 1;
            } else if (c==77) {
                perintah = "right";
                paramInt[0] = 1;
            } else if (c==80) {
                perintah = "down";
                paramInt[0] = 1;
            } else {
                perintah = "fail";
            }
            return;
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
        }
    } while (c!= '#' && !shortcut);
    cout << c;
    kata[i++] = ' ';
    kata[i++] = '#';
    kata[i] = '\0';
    int done = 0;
    if (!shortcut){
        sscanf(kata,"%s",stmp);
        perintah = stmp;
        done = perintah.size()+1;
    }
    i = 0;
    cout << perintah << done;
    if (perintah == "new") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw 0;
    } else if (perintah == "load") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw 0;
    } else if (perintah == "teleport") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>2) throw 0;
        if (paramStr[0][0] != '-' || ('0' <= paramStr[0][0] && paramStr[0][0]<='9')) {
            paramInt[0] = paramStr[0][0]-'0';
        } else {
            throw 0;
        }
    } else if (perintah == "right") {
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
    } else if (perintah == "left") {
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
    } else if (perintah == "inventory") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "plow") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "put") {
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
    } else if (perintah == "slash") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "water") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "harvest") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "wake_up") {
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
    } else if (perintah == "sleep") {
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
    } else if (perintah == "status") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "save") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "sleep") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "exit") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "store") {
        do {
            sscanf(kata+done,"%s",stmp);
            done+=strlen(stmp)+1;
            paramStr[i] = stmp;
        } while (paramStr[i++][0] != '#');
        if (i>1){
            throw 0;
        }
    } else if (perintah == "buy") {
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
    } else if (perintah == "sell") {
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
}

Game::Game() {
    world = NULL;
}
Game::~Game(){
    delete world;
}