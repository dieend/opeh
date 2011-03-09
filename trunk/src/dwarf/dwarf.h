#ifndef dwarf_H
#define dwarf_H
#include "../point/point.h"
class Dwarf
{
       friend void nextmove(Dwarf,Dwarf,Dwarf);
public :
       Dwarf(int);
       ~Dwarf();
       bool dojob();
       void wakeup();
       void sleep();
       int getstatus();
       void performstatus();
       void setposition(Point);
       Point getposition();
       void setdirection(int);
       int getdirection();
private :
        //const point defpos;
        Point cpos;
        //Grid *cGrid;
        //area[1] *field;
        int direction;//1 for left,2 for up,3 for right,4 for down
        int status;//wakeup(status=1),sleep(status=0)
        const int type;//dwarf type, 0 for water,1 for harvest,2 for slash
};

#endif
