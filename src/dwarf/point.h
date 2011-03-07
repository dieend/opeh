#ifndef point_H
#define point_H

class point
{
public :
       point();
       point(int,int);
       point(const point&);
       point& operator=(const point&);
       void setx(int);
       void sety(int);
       int getx();
       int gety();
       void goleft();
       void goup();
       void goright();
       void godown();
       void performpoint();
private :
        int x;
        int y;
};

#endif
