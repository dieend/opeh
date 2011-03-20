#ifndef dwarf_H
#define dwarf_H
#include "point.h"
#include "map.h"
#include <deque>
class Dwarf
{
public :
       Dwarf(Area*,int);
       virtual ~Dwarf();
       static void setDefault(Dwarf&,Dwarf&,Dwarf&);
       int getType();
       bool doJob();
       void wakeUp();
       void sleep();
       int getStatus();
       void performStatus();
       void setPosition(int,int);
       void setPosition(Point);
       Point getPosition();
       Point getFrontpoint();
       void setDirection(int);
       int getDirection();
       static void setmap();//setting map agar mengikuti grid
       void setField();
       void bfsdwarf();//setting gerakan terpendek
       void oneMove();
       static void nextMove(Dwarf&,Dwarf&,Dwarf&);//setting 1 gerakan ke depan masing-masing kurcaci
       Grid * getFrontGrid();
private :
        Grid *cGrid;
        Area *field;
        const int type;//dwarf type, 0 for water,1 for harvest,2 for slash,3,for moving object,4 for watered plant,not harvest yet
        int status;//wakeup(status=1),sleep(status=0)
        Point cpos;
        int direction;//3 for left,4 for up,1 for right,2 for down
		static map *cmap;
		deque<Point> *dwarfdqp;//setting rute untuk dwarf tertentu
};

#endif
