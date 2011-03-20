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
       Point getFrontpoint();
       void setDirection(int);
       int getDirection();
       static void setmap();//setting map agar mengikuti grid
       void bfsdwarf();//setting gerakan terpendek
       void oneMove();
       static void nextMove(Dwarf&,Dwarf&,Dwarf&);//setting 1 gerakan ke depan masing-masing kurcaci
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
