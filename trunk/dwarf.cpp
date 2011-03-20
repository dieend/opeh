#include "dwarf.h"
#include "map.h"
#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#define chartoint(c) int(c)-int('0')
using namespace std;

//inisialisasi map baru
map *Dwarf::cmap= new map;

//inisialisasi dwarf dengan menggunakan int ntype
Dwarf::Dwarf(int ntype) : type(ntype),status(1),direction(4)
{
  dwarfdqp = new deque<Point>;
  if (ntype==0)
  {
    cpos.setX(3);
    cpos.setY(8);
  }
  else if (ntype==1)
  {
    cpos.setX(3);
    cpos.setY(9);
  }
  else if (ntype==2)
  {
    cpos.setX(3);
    cpos.setY(10);
  }
}

//destruktor dwarf
Dwarf::~Dwarf()
{
}

void Dwarf::setDefault()
{
  status=1;
  if (type==0)
  {
    cpos.setX(3);
    cpos.setY(8);
  }
  else if (type==1)
  {
    cpos.setX(3);
    cpos.setY(9);
  }
  else if (type==2)
  {
    cpos.setX(3);
    cpos.setY(10);
  }
  direction=4;
}
  
//return type dwarf
int Dwarf::getType()
{
  return type;
}

//dwarf melakukan perkerjaan , return true jika pekerjaan berhasil dilakukan false jika tidak
bool Dwarf::doJob()
{
  return false;
}

//mengaktifkan dwarf
void Dwarf::wakeUp()
{
  status=1;
}

//menon-aktifkan dwarf
void Dwarf::sleep()
{
  status=0;
}

//return status dwarf
int Dwarf::getStatus()
{
  return status;
}

//menampilkan status dwarf
void Dwarf::performStatus()
{
  cout << type << " ";
  if (status==1)
    cout << "wake_up.";
  else 
    cout << "sleep.";
}

//setting posisi dwarf
void Dwarf::setPosition(Point p)
{
  cpos.setX(p.getX());
  cpos.setY(p.getY());
}

//return posisi dwarf
Point Dwarf::getPosition()
{
  return cpos;
}

//setting arah hadap dwarf
void Dwarf::setDirection(int nd)
{
  direction=nd;
}

//return arah hadap dwarf
int Dwarf::getDirection()
{
  return direction;
}

Point Dwarf::getFrontpoint()
{
  if (direction==1)
    return cpos.getLeft();
  else if (direction==2)
    return cpos.getUp();
  else if (direction==3)
    return cpos.getRight();
  else if (direction==4)
    return cpos.getDown();
}

//setting map dari grid
void Dwarf::setmap()
{
}

void Dwarf::bfsdwarf()
{
     delete dwarfdqp;
     dwarfdqp=new deque<Point>;
     pair<Point,Point> sp;
     sp.first=cpos;
     sp.second=cpos;
     cout << "cpos : " << cpos.getX() << ',' << cpos.getY() << endl;
     deque< pair<Point,Point> > dqptemp,dqptemp1;
     dqptemp.push_back(sp);
     dqptemp1.push_back(sp);
     int i,j;
     map tmap;
     for(i=0;i<tmap.getsizer();i++)
       for(j=0;j<tmap.getsizec();j++)
         tmap.setmapij(i,j,cmap->getvalij(i,j));
     Point tesp;
     bool found=false;
     while ( (!dqptemp.empty()) && (!found))
     {
       tesp=dqptemp.front().second;
         if ((chartoint(tmap.getvalpoint(tesp.getLeft()))==type))
         {
           found=true;
           sp.first=tesp;
           sp.second=tesp.getLeft();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
         }
         if ((tmap.getvalpoint(tesp.getLeft())==' '))
         {
           sp.first=tesp;
           sp.second=tesp.getLeft();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
           tmap.setvalpoint(tesp.getLeft(),'#');
         }
         if ((chartoint(tmap.getvalpoint(tesp.getUp()))==type))
         {
           found=true;
           sp.first=tesp;
           sp.second=tesp.getUp();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
         }
         if ((tmap.getvalpoint(tesp.getUp())==' '))
         {
           sp.first=tesp;
           sp.second=tesp.getUp();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
           tmap.setvalpoint(tesp.getUp(),'#');
         }
         if ((chartoint(tmap.getvalpoint(tesp.getRight()))==type))
         {
           found=true;
           sp.first=tesp;
           sp.second=tesp.getRight();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
         }
         if ((tmap.getvalpoint(tesp.getRight())==' '))
         {
           sp.first=tesp;
           sp.second=tesp.getRight();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
           tmap.setvalpoint(tesp.getRight(),'#');
         }
         if ((chartoint(tmap.getvalpoint(tesp.getDown()))==type))
         {
           found=true;
           sp.first=tesp;
           sp.second=tesp.getDown();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
         }
         if ((tmap.getvalpoint(tesp.getDown())==' '))
         {
           sp.first=tesp;
           sp.second=tesp.getDown();
           dqptemp.push_back(sp);
           dqptemp1.push_back(sp);
           tmap.setvalpoint(tesp.getDown(),'#');
         }
         dqptemp.pop_front();
       }
     
     found=false;
     cout << dqptemp1.front().second.getX() << ',' << dqptemp1.front().second.getY() << endl;
     cout << dqptemp1.back().second.getX() << ',' << dqptemp1.back().second.getY() << endl;

     while ( (sp.first.getX()!=sp.second.getX()) || (sp.first.getY()!=sp.second.getY()) )
     {
       dqptemp1.pop_back();
       if ( (dqptemp1.back().second.getX()==sp.first.getX()) && (dqptemp1.back().second.getY()==sp.first.getY()) )
       {
         dwarfdqp->push_front(sp.second);
         sp=dqptemp1.back();
       }
     }
     /*for(i=0;i<dwarfdqp->size();++i)
     {
       cout << (*dwarfdqp)[i].getX() << ',' << (*dwarfdqp)[i].getY() << endl;
     }
         
     cout << "tes\n" << endl << endl;*/
     
     //map tmap;
     //tmap=(*cmap);
}

void Dwarf::oneMove()
{
     if ((*dwarfdqp)[0]==getFrontpoint())
     {
       if (dwarfdqp->size()==1)
       {
         cout << "success\n";
         //di sini ubah cpos, map dan grid, gunakan dojob(), tergantung pada type masing2 dwarf
         if (type==0);
       }
       else
       {
         //disini ubah posisi dwarf, ubah grid dan map.
         cmap->setvalpoint(cpos,' ');
         cpos=getFrontpoint();
         cmap->setvalpoint(cpos,'3');
       }
     }
     else//kasus jika hanya mengubah arah saja
     {
       if ((*dwarfdqp)[0]==cpos.getLeft())
       {
         direction=1;
       }
       else if ((*dwarfdqp)[0]==cpos.getUp())
       {
         direction=2;
       }
       else if ((*dwarfdqp)[0]==cpos.getRight())
       {
         direction=3;
       }
       else if ((*dwarfdqp)[0]==cpos.getDown())
       {
         direction=4;
       }
     }
}   
         
void Dwarf::nextMove(Dwarf& d0,Dwarf& d1,Dwarf &d2)
{
     cout << "tes\n";
     deque<Dwarf> dqdwarf;
     //Check masing-masing pekerjaan dwarf dan status dwarf, jika masih ada tujuan dan wake_up maka dimasukkan di deque
     if ((cmap->gett0()!=0) && (d0.getStatus()==1))
     {
       dqdwarf.push_back(d0);
       d0.bfsdwarf();
     }
     if ((cmap->gett1()!=0) && (d1.getStatus()==1))
     {
       dqdwarf.push_back(d1);
       d1.bfsdwarf();
     }
     if ((cmap->gett2()!=0) && (d2.getStatus()==1))
     {
       dqdwarf.push_back(d2);
       d2.bfsdwarf();
     }
     if (dqdwarf.size()==1)
     {
       //Lakukan perjalanan untuk satu dwarf
       
       cout << "tes\n";
       d0.oneMove();
       cmap->performmap();
     }
}
