#ifndef dwarf_H
#define dwarf_H
#include "point.h"
#include "map.h"
#include <deque>
class Dwarf
{
public :
       Dwarf(int);
       ~Dwarf();
       void setDefault();
       int getType();
       bool doJob();
       void wakeUp();
       void sleep();
       int getStatus();
       void performStatus();
       void setPosition(Point);
       Point getPosition();
       void setDirection(int);
       int getDirection();
       int getsuccess();
       void bfsdwarf();
       static void setmap();
       static void nextMove(Dwarf&,Dwarf&,Dwarf&);
private :
        //Grid *cGrid;
        //area[1] *field;
        const int type;//dwarf type, 0 for water,1 for harvest,2 for slash
        int status;//wakeup(status=1),sleep(status=0)
        Point cpos;
        int direction;//1 for left,2 for up,3 for right,4 for down
		static map *cmap;
		deque<Point> *dwarfdqp;//setting rute untuk dwarf tertentu
};

#endif
