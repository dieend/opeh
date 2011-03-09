#ifndef map_H
#define map_H
#include "dwarf.h"
#include <deque>
using namespace std;

class map
{
public :
       map();
       ~map();
       //void setsizer(int nsr);
       //void setsizec(int nsc);
       int getsizer();
       int getsizec();
       void setmapij(int,int,int);
       void performmap();
       void bfsdwarf(Dwarf,deque<int> &);
private :
        int **arr;
        const int sizer;
        const int sizec;
};


#endif
