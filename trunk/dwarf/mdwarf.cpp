#include <cstdlib>
#include <iostream>
#include "point.h"
#include "map.h"
using namespace std;

int main()
{
    point p1;
    p1.setx(2);
    p1.sety(3);
    p1.performpoint();
    point p2=p1;
    p2.performpoint();
    map rm;
    rm.performmap();
    dwarf dw1(1),dw2(2),dw3(3);
    nextmove(dw1,dw2,dw3);
    system("PAUSE");
    return 0;
}
