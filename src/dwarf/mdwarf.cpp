#include <cstdlib>
#include <iostream>
#include "dwarf.h"
#include "map.h"
#include "../point/point.h"
#include <deque>
#include <conio.h>
using namespace std;

int main()
{
    Dwarf d0(0),d1(1),d2(2);
    //d1.sleep();
    //d2.sleep();
    deque<Point> dqp;
//    d0.bfsdwarf();
    char c;
    do
    {
      cout << "Press enter to do some job : ";
      c=getch();
      if ( (int)c ==13 )
      {
        system("cls");
        Dwarf::nextMove(d0,d1,d2);
      }
    }while ((int)c==13);
    system("PAUSE");
    return 0;
}
