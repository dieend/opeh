#ifndef map_H
#define map_H
#include "../point/point.h"
using namespace std;

class map
{
public :
       map();
       ~map();
       map(const map &);
       map& operator=(const map&);
       int getsizer();
       int getsizec();
       void setmapij(int,int,char);
       char getvalij(int,int);
       void setvalpoint(Point,char);
       char getvalpoint(Point);
       void performmap();
       void sett0(int);
       void sett1(int);
       void sett2(int);
       int gett0();
       int gett1();
       int gett2();
private :
        char **arr;
        int sizer;
        int sizec;
        int t0;//banyaknya 0/water di field
        int t1;//banyaknya 1/harvest di field
        int t2;//banyaknya 2/slash di field
};


#endif
