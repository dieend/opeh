#include "area.h"
#define RUMAH 0
#define LAHAN 1
#define TOKO 2
#define G(i,j,n) grid[(i)][(j)]=new Grid((i),(j),(n))

Grid * Area::getGrid(int x, int y) {
	return grid[x][y];
}
Grid * Area::getGrid(Point p) {
	return grid[p.getX()][p.getY()];
}
Area::Area():typeArea(0) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
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
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			delete grid[i][j];
		}
	}	
}

Area::Area(int tipe)
	: typeArea(tipe) {
	if (tipe == RUMAH) {
		G(0,0,2);G(0,1,9);G(0,2,6);G(0,3,9);G(0,4,2);G(0,5,2);G(0,6,2);G(0,7,2);G(0,8,2);G(0,9,2);
		G(1,0,9);G(1,1,2);G(1,2,2);G(1,3,2);G(1,4,2);G(1,5,2);G(1,6,2);G(1,7,2);G(1,8,2);G(1,9,2);
		G(2,0,9);G(2,1,2);G(2,2,2);G(2,3,2);G(2,4,2);G(2,5,2);G(2,6,2);G(2,7,2);G(2,8,2);G(2,9,2);
		G(3,0,2);G(3,1,2);G(3,2,2);G(3,3,2);G(3,4,9);G(3,5,9);G(3,6,2);G(3,7,2);G(3,8,2);G(3,9,9);
		G(4,0,2);G(4,1,2);G(4,2,2);G(4,3,2);G(4,4,9);G(4,5,9);G(4,6,2);G(4,7,2);G(4,8,2);G(4,9,9);
		G(5,0,2);G(5,1,2);G(5,2,2);G(5,3,2);G(5,4,2);G(5,5,2);G(5,6,2);G(5,7,2);G(5,8,2);G(5,9,2);
		G(6,0,5);G(6,1,5);G(6,2,5);G(6,3,2);G(6,4,2);G(6,5,2);G(6,6,2);G(6,7,2);G(6,8,2);G(6,9,2);
		G(7,0,5);G(7,1,5);G(7,2,5);G(7,3,2);G(7,4,2);G(7,5,2);G(7,6,2);G(7,7,2);G(7,8,2);G(7,9,2);
		G(8,0,5);G(8,1,5);G(8,2,5);G(8,3,2);G(8,4,2);G(8,5,2);G(8,6,8);G(8,7,8);G(8,8,8);G(8,9,2);
		G(9,0,5);G(9,1,5);G(9,2,5);G(9,3,2);G(9,4,2);G(9,5,2);G(9,6,8);G(9,7,8);G(9,8,8);G(9,9,2);
	}else 
	if(tipe == TOKO) {
		G(0,0,9);G(0,1,2);G(0,2,2);G(0,3,9);G(0,4,9);G(0,5,2);G(0,6,9);G(0,7,9);G(0,8,9);G(0,9,9);
		G(1,0,9);G(1,1,9);G(1,2,2);G(1,3,2);G(1,4,2);G(1,5,2);G(1,6,9);G(1,7,9);G(1,8,9);G(1,9,9);
		G(2,0,9);G(2,1,2);G(2,2,2);G(2,3,2);G(2,4,2);G(2,5,2);G(2,6,9);G(2,7,9);G(2,8,9);G(2,9,9);
		G(3,0,2);G(3,1,2);G(3,2,2);G(3,3,2);G(3,4,2);G(3,5,2);G(3,6,3);G(3,7,9);G(3,8,9);G(3,9,9);
		G(4,0,2);G(4,1,2);G(4,2,2);G(4,3,2);G(4,4,9);G(4,5,9);G(4,6,3);G(4,7,9);G(4,8,9);G(4,9,9);
		G(5,0,2);G(5,1,2);G(5,2,2);G(5,3,9);G(5,4,9);G(5,5,9);G(5,6,3);G(5,7,9);G(5,8,9);G(5,9,9);
		G(6,0,9);G(6,1,9);G(6,2,9);G(6,3,9);G(6,4,2);G(6,5,2);G(6,6,3);G(6,7,9);G(6,8,9);G(6,9,9);
		G(7,0,9);G(7,1,9);G(7,2,9);G(7,3,9);G(7,4,2);G(7,5,2);G(7,6,9);G(7,7,9);G(7,8,9);G(7,9,9);
		G(8,0,9);G(8,1,9);G(8,2,9);G(8,3,9);G(8,4,2);G(8,5,2);G(8,6,9);G(8,7,9);G(8,8,9);G(8,9,9);
		G(9,0,9);G(9,1,9);G(9,2,9);G(9,3,9);G(9,4,2);G(9,5,2);G(9,6,9);G(9,7,9);G(9,8,9);G(9,9,9);
	} else {
		for (int i=0;i<3; i++) {
			for (int j=0; j<10; j++) {
				Point P(i,j);
				if ((i==1 || i==2) && (j==8 || j==9)) {
					grid[i][j] = new Grid(P,2,0);
				} else {
					grid[i][j] = new Grid(P,0,2);
				}
			}
		}
		for (int i=3; i<10; i++) {
			for (int j=0; j<10; j++) {
				Point P(i,j);
				grid[i][j] = new Grid(P,1,0);
			}
		}
	}
}

string peta_rumah[10] = {
		".[-]......",
		"*.........",
		"*.........",
		"..../\\n..]",
		"...n\\/...]",
		"..........",
		"BBB.......",
		"BBB.......",
		"BBB...III.",
		"BBB...III."
		};
string peta_toko[10] = {
		"&..%%.#[-]",
		"%&....#..*",
		"&.....#..*",
		"......#...",
		"......#<..",
		"......#..v",
		"n/\\n..#.**",
		"n\\/n..#***",
		"n/\\n..#.**",
		"n\\/n..#***"
};
		
ostream& operator<<(ostream& c,Area* area) {
	if (area->typeArea==0) {
		c << dinding << "+----------+\n|" << white;
		for (int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				if (area->getGrid(i,j)->getType() == 1) {
                                    Player * p = area->getPlayer();
					c << lantai << p << white;
				} else {
					c << lantai << peta_rumah[i][j] << white;
				}
			}
			c << endl;
		}
		c << dinding << "+----------+\n|" << white;
	} else if (area->typeArea==1) {
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				c << (area->getGrid(i,j));
			}
		}
	} else if (area->typeArea==2) {
		c << dinding << "+----------+\n|" << white;
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				if (area->getGrid(i,j)->getType() == 1) {
					c << toko << (area->getPlayer()) << white;
				} else {
					c << toko << peta_toko[i][j] << white;
				}
			}
			c << endl;
		}
		c << dinding << "+----------+\n|" << white;
	}
	return c;
}

Player* Area::getPlayer(){
    return player;
}

void Area::setPlayer(Player* p){
    player = p;
}