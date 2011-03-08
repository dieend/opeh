#include "dwarf.h"
#include <iostream>
using namespace std;

//konstruktor dwarf, dengan type tertentu
dwarf::dwarf(int ntype) : type(ntype),status(1),direction(4),success(0)
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

//destruktur dwarf
dwarf::~dwarf() 
{
  status=0;
}

//dwarf melakukan pekerjaan sesuai dengan typenya, menset success menjadi 1
void dwarf::dojob() 
{
     success=1;
}

//dwarf diaktifkan
void dwarf::wakeup()
{
  status=1;
}

//dwarf di-nonaktifkan
void dwarf::sleep()
{
  status=0;
}

//mendapatkan status dari dwarf
int dwarf::getstatus()
{
  return status;
}

//menampilkan no dwarf dan statusnya
void dwarf::performstatus()
{
  cout << type << " ";
  if (status==1)
    cout << "wake_up.";
  else 
    cout << "sleep.";
}

//men-set posisi dwarf
void dwarf::setposition(point p)
{
  cpos.setx(p.getx());
  cpos.sety(p.gety());
}

//mendapatkan current posisi dari dwarf
point dwarf::getposition()
{
  return cpos;
}

//menset arah hadap dwarf, 1 for left,2 for up,3 for right,4 for down
void dwarf::setdirection(int nd)
{
  direction=nd;
}


//mendapatkan current arah hadap dwarf bertipe tertentu
int dwarf::getdirection()
{
  return direction;
}

//men-set success menjadi 0/fail
void dwarf::setsuccess0()
{
     success=0;
}

//mendapatkan status success pekerjaan suatu dwarf
int dwarf::getsuccess()
{
    return success;
}
