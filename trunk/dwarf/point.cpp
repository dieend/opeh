#include "point.h"
#include <iostream>
using namespace std;

point::point()
{
}

point::point(int nx,int ny)
{
  x=nx;
  y=ny;
}

point::point(const point&p)
{
  x=p.x;
  y=p.y;
}

point& point::operator=(const point& p)
{
  this->x=p.x;
  this->y=p.y;
  return *this;
}

void point::setx(int nx)
{
  x=nx;
}

void point::sety(int ny)
{
  y=ny;
}

int point::getx()
{
  return x;
}

int point::gety()
{
  return y;
}

void point::goleft()
{
  y--;
}

void point::goup()
{
  x--;
}

void point::goright()
{
  y++;
}

void point::godown()
{
  x++;
}
  
void point::performpoint()
{
  cout << "x = " << x << ",y = " << y << endl;
}

