#ifndef dwarf_H
#define dwarf_H
#include "../point/point.h"
#include "../area/area.h"
#include "map.h"
class Dwarf
{
public :
        static void nextMove(Dwarf,Dwarf,Dwarf);
       Dwarf(int);
       ~Dwarf();
       bool doJob();
       void wakeUp();
       void sleep();
       int getStatus();
       void performStatus();
       void setPosition(Point);
       Point getPosition();
       void setDirection(int);
       int getDirection();
private :
        //const point defpos;
        Point cpos;
        //Grid *cGrid;
        //area[1] *field;
        int direction;//1 for left,2 for up,3 for right,4 for down
        int status;//wakeup(status=1),sleep(status=0)
        const int type;//dwarf type, 0 for water,1 for harvest,2 for slash
	map currmap;
        Area* curArea;
};


#endif
