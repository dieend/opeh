#include <cstdlib>
#include <iostream>
#include "../point/point.h"
#include "map.h"
#include "fnextmove.cpp"
using namespace std;

int main()
{
    Point p1;
    p1.setX(2);
    p1.setY(3);
//    p1.performPoint();
//    point p2=p1;
//    p2.performPoint();
    map rm;
    rm.performmap();
    Dwarf dw1(1),dw2(2),dw3(3);
    nextmove(dw1,dw2,dw3);
    system("PAUSE");
    return 0;
}
