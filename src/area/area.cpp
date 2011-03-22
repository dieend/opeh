#include "area.h"
#include "../point/point.h"

Area::Area(ifstream& fin,int type):typeArea(type){
    if (type==LAHAN){
        G(0,0,2);G(0,1,9);G(0,2,9);G(0,3,9);G(0,4,9);G(0,5,9);G(0,6,9);G(0,7,2);G(0,8,GSELLINGBOX);G(0,9,GSELLINGBOX);
        G(1,0,2);G(1,1,2);G(1,2,2);G(1,3,2);G(1,4,2);G(1,5,2);G(1,6,2);G(1,7,2);G(1,8,GSELLINGBOX);G(1,9,GSELLINGBOX);
        G(2,0,2);G(2,1,2);G(2,2,2);G(2,3,2);G(2,4,2);G(2,5,2);G(2,6,2);G(2,7,2);G(2,8,2);G(2,9,2);
        for (int i=3; i<MAXROW; i++) {
            for (int j=0; j<MAXCOLUMN; j++) {
                int k;
                fin.read((char*)&k,sizeof(int));
                if (k==GTANAMAN){
                    grid[i][j] = new Grid_Plant(fin);
                } else {
                    grid[i][j] = new Grid_Lahan(fin);
                }
            }
        }
    }
}

Grid * Area::getGrid(int x, int y) {
    return grid[x][y];
}
Grid * Area::getGrid(Point p) {
    return grid[p.getX()][p.getY()];
}
Area::Area():typeArea(0) {
    for (int i=0; i<MAXROW; i++) {
        for (int j=0; j<MAXCOLUMN; j++) {
            grid[i][j] = new Grid();
        }
    }
}
int Area::getType(){
    return typeArea;
}
// Area::Area(const Area& area): typeArea(area.typeArea) {
	// for (int i=0; i<10; i++) {
		// for (int j=0; j<10; j++) {
			// grid[i][j] = new Grid(*(area.grid[i][j]));
		// }
	// }	
// }

Area::~Area(){
    for (int i=0; i<MAXROW; i++) {
        for (int j=0; j<MAXCOLUMN; j++) {
            delete grid[i][j];
        }
    }
}

Area::Area(int tipe)
	: typeArea(tipe) {
	if (tipe == RUMAH) {
		G(0,0,GBED);G(0,1,GBED);G(0,2,GBED);G(0,3,GSAVE);G(0,4,GSAVE);G(0,5,2);G(0,6,2);G(0,7,GUNSTEP);G(0,8,GUNSTEP);G(0,9,GUNSTEP);
		G(1,0,GBED);G(1,1,GBED);G(1,2,GBED);G(1,3,GJALAN);G(1,4,GJALAN);G(1,5,GJALAN);G(1,6,GJALAN);G(1,7,GJALAN);G(1,8,GJALAN);G(1,9,GJALAN);
		G(2,0,GBED);G(2,1,GBED);G(2,2,GBED);G(2,3,GJALAN);G(2,4,GJALAN);G(2,5,GJALAN);G(2,6,GJALAN);G(2,7,GJALAN);G(2,8,GJALAN);G(2,9,GJALAN);
		G(3,0,GBED);G(3,1,GBED);G(3,2,GBED);G(3,3,GJALAN);G(3,4,GJALAN);G(3,5,GUNSTEP);G(3,6,GUNSTEP);G(3,7,GUNSTEP);G(3,8,GUNSTEP);G(3,9,GJALAN);
		G(4,0,2);G(4,1,2);G(4,2,2);G(4,3,2);G(4,4,2);G(4,5,9);G(4,6,9);G(4,7,9);G(4,8,9);G(4,9,2);
		G(5,0,2);G(5,1,2);G(5,2,2);G(5,3,2);G(5,4,2);G(5,5,9);G(5,6,9);G(5,7,9);G(5,8,9);G(5,9,2);
		G(6,0,2);G(6,1,2);G(6,2,2);G(6,3,2);G(6,4,2);G(6,5,9);G(6,6,9);G(6,7,9);G(6,8,9);G(6,9,2);
		G(7,0,2);G(7,1,2);G(7,2,2);G(7,3,2);G(7,4,2);G(7,5,2);G(7,6,2);G(7,7,2);G(7,8,2);G(7,9,2);
		G(8,0,9);G(8,1,9);G(8,2,2);G(8,3,2);G(8,4,2);G(8,5,2);G(8,6,2);G(8,7,2);G(8,8,8);G(8,9,8);
		G(9,0,9);G(9,1,9);G(9,2,2);G(9,3,2);G(9,4,2);G(9,5,2);G(9,6,2);G(9,7,2);G(9,8,8);G(9,9,8);
	}else 
	if(tipe == TOKO) {
		G(0,0,2);G(0,1,2);G(0,2,2);G(0,3,2);G(0,4,2);G(0,5,9);G(0,6,9);G(0,7,3);G(0,8,9);G(0,9,9);
		G(1,0,2);G(1,1,2);G(1,2,2);G(1,3,2);G(1,4,2);G(1,5,2);G(1,6,2);G(1,7,3);G(1,8,9);G(1,9,9);
		G(2,0,9);G(2,1,2);G(2,2,2);G(2,3,2);G(2,4,2);G(2,5,2);G(2,6,2);G(2,7,3);G(2,8,9);G(2,9,9);
		G(3,0,2);G(3,1,2);G(3,2,2);G(3,3,2);G(3,4,2);G(3,5,2);G(3,6,2);G(3,7,3);G(3,8,9);G(3,9,9);
		G(4,0,2);G(4,1,2);G(4,2,2);G(4,3,2);G(4,4,2);G(4,5,2);G(4,6,2);G(4,7,3);G(4,8,9);G(4,9,9);
		G(5,0,2);G(5,1,2);G(5,2,9);G(5,3,9);G(5,4,2);G(5,5,2);G(5,6,2);G(5,7,3);G(5,8,9);G(5,9,9);
		G(6,0,2);G(6,1,2);G(6,2,9);G(6,3,9);G(6,4,2);G(6,5,2);G(6,6,2);G(6,7,3);G(6,8,9);G(6,9,9);
		G(7,0,2);G(7,1,2);G(7,2,2);G(7,3,2);G(7,4,2);G(7,5,2);G(7,6,2);G(7,7,3);G(7,8,9);G(7,9,9);
		G(8,0,2);G(8,1,2);G(8,2,9);G(8,3,9);G(8,4,2);G(8,5,2);G(8,6,2);G(8,7,3);G(8,8,9);G(8,9,9);
		G(9,0,2);G(9,1,2);G(9,2,9);G(9,3,9);G(9,4,2);G(9,5,2);G(9,6,2);G(9,7,3);G(9,8,9);G(9,9,9);
	} else {
            G(0,0,2);G(0,1,9);G(0,2,9);G(0,3,9);G(0,4,9);G(0,5,9);G(0,6,9);G(0,7,2);G(0,8,GSELLINGBOX);G(0,9,GSELLINGBOX);
            G(1,0,2);G(1,1,2);G(1,2,2);G(1,3,2);G(1,4,2);G(1,5,2);G(1,6,2);G(1,7,2);G(1,8,GSELLINGBOX);G(1,9,GSELLINGBOX);
            G(2,0,2);G(2,1,2);G(2,2,2);G(2,3,2);G(2,4,2);G(2,5,2);G(2,6,2);G(2,7,2);G(2,8,2);G(2,9,2);
            for (int i=3; i<MAXROW; i++) {
                for (int j=0; j<MAXCOLUMN; j++) {
                    Point P(i,j);
                    grid[i][j] = new Grid_Lahan(P,GLAHAN,2);
                }
            }
	}
}
		
ostream& operator<<(ostream& c,Area* area) {
	
	if (area->typeArea==RUMAH) {
            system("cls");
            Utilities::getInstances().printRumah(c);
            for (int i=0; i<10; i++) {
                for(int j=0; j<10; j++) {
                    if (area->getGrid(i,j)->getType() == 1) {
                        Player * here = area->getPlayer();
                        
                        Point posisi(i,j);
                        Utilities::getInstances().setBG(YELLOW);
                        c << here;
                        Utilities::getInstances().resetBG();
//                        if (here->getArah()==ATAS) posisi.setDown();
//                        if (here->getArah()==KIRI) posisi.setRight();
//                        if (here->getArah()==KANAN) posisi.setLeft();
//                        if (here->getArah()==BAWAH) posisi.setUp();
//                        here = area->getGrid(posisi);

                    }
                }
            }
	} else if (area->typeArea==LAHAN) {
            system("cls");
            Utilities::getInstances().printPeta(c);
            Utilities::getInstances().setBG(GRAY);
            for (int i=0; i<3; i++) {
                for (int j=0; j<10; j++) {
                    Grid* grid = area->getGrid(i,j);
                    if (grid->getType() == GPLAYER) { //player
                        Player * p = area->getPlayer();
                        c << p;
                    }else if (grid->getType()==WKURCACI){
                        Dwarf* d = area->getDwarf(0);
                        c << d;
                    }else if (grid->getType()==HKURCACI){
                        Dwarf* d = area->getDwarf(1);
                        c << d;
                    }else if (grid->getType()==SKURCACI){
                        Dwarf* d = area->getDwarf(2);
                        c << d;
                    } else if (grid->getType()== GTANAMAN){ //tanaman
                        Grid_Plant * plant;
                        plant = (Grid_Plant*) grid;
                        c << plant;
                    } else if (grid->getType()==GLAHAN) {
                        Grid_Lahan * L;
                        L = (Grid_Lahan *) grid;
                        c << L;
                    } 
                }
                c << endl;
            }
            Utilities::getInstances().resetBG();
            Utilities::getInstances().setBG(GREEN);
            for (int i=3; i<10; i++) {
                for (int j=0; j<10; j++) {
                    Grid* grid = area->getGrid(i,j);
                    if (grid->getType() == GPLAYER) { //player
                        Grid_Lahan * L;
                        L = (Grid_Lahan *) grid;
                        c << L;
                        Player * p = area->getPlayer();
                        c << p;
                    }else if (grid->getType()==WKURCACI){
                        Dwarf* d = area->getDwarf(0);
                        c << d;
                    }else if (grid->getType()==HKURCACI){
                        Dwarf* d = area->getDwarf(1);
                        c << d;
                    }else if (grid->getType()==SKURCACI){
                        Dwarf* d = area->getDwarf(2);
                        c << d;
                    } else if (grid->getType()== GTANAMAN){ //tanaman
                        Grid_Plant * plant;
                        plant = (Grid_Plant*) grid;
                        c << plant;
                    } else if (grid->getType()==GLAHAN) {
                        Grid_Lahan * L;
                        L = (Grid_Lahan *) grid;
                        c << L;
                    }
                }
                c << endl;
            }
            Utilities::getInstances().resetBG();
	} else if (area->typeArea==TOKO) {
			Utilities::getInstances().printToko(c);
            Utilities::getInstances().setBG(YELLOW);
            for (int i=0; i<10; i++) {
                for (int j=0; j<10; j++) {
                    if (area->getGrid(i,j)->getType() == 1) {
                        Player * here = area->getPlayer();
                        Point posisi(i,j);
                        c << here;
					}
				}
			}
            Utilities::getInstances().resetBG();
	}
        
	return c;
}

Player* Area::getPlayer(){
    return player;
}

void Area::setPlayer(Player* p){
    player = p;
}

void Area::setGrid(Grid* g){
    Point p=g->getPosisi();
    grid[p.getX()][p.getY()] = g;
}

void Area::setDwarf(int si, Dwarf* d){
    dwarf[si] = d;
}

Dwarf* Area::getDwarf(int si) {
    return dwarf[si];
}
