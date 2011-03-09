#include "dwarf.h"
#include <iostream>
using namespace std;

Dwarf::Dwarf(int ntype) : type(ntype),status(1),direction(4)
{
  if (ntype==0)
  {
    cpos.setX(1);
    cpos.setY(8);
  }
  else if (ntype==1)
  {
    cpos.setX(1);
    cpos.setY(9);
  }
  else if (ntype==2)
  {
    cpos.setX(1);
    cpos.setY(10);
  }
}

Dwarf::~Dwarf()
{
  status=0;
}

bool Dwarf::dojob()
{
     return 1;
}

void Dwarf::wakeup()
{
  status=1;
}

void Dwarf::sleep()
{
  status=0;
}

int Dwarf::getstatus()
{
  return status;
}

void Dwarf::performstatus()
{
  cout << type << " ";
  if (status==1)
    cout << "wake_up.";
  else 
    cout << "sleep.";
}

void Dwarf::setposition(Point p)
{
  cpos.setX(p.getX());
  cpos.setY(p.getY());
}

Point Dwarf::getposition()
{
  return cpos;
}

void Dwarf::setdirection(int nd)
{
  direction=nd;
}

int Dwarf::getdirection()
{
  return direction;
}

