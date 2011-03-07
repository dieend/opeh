#include "dwarf.h"
#include <iostream>
using namespace std;

dwarf::dwarf(int ntype) : type(ntype),status(1),direction(4)
{
  if (ntype==0)
  {
    cpos.setx(1);
    cpos.sety(8);
  }
  else if (ntype==1)
  {
    cpos.setx(1);
    cpos.sety(9);
  }
  else if (ntype==2)
  {
    cpos.setx(1);
    cpos.sety(10);
  }
}

dwarf::~dwarf() 
{
  status=0;
}

bool dwarf::dojob()
{
     return 1;
}

void dwarf::wakeup()
{
  status=1;
}

void dwarf::sleep()
{
  status=0;
}

int dwarf::getstatus()
{
  return status;
}

void dwarf::performstatus()
{
  cout << type << " ";
  if (status==1)
    cout << "wake_up.";
  else 
    cout << "sleep.";
}

void dwarf::setposition(point p)
{
  cpos.setx(p.getx());
  cpos.sety(p.gety());
}

point dwarf::getposition()
{
  return cpos;
}

void dwarf::setdirection(int nd)
{
  direction=nd;
}

int dwarf::getdirection()
{
  return direction;
}

