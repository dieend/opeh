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
Dwarf::Dwarf(Area * fieldinput,int ntype) : type(ntype),status(0),direction(2)
{
  field=fieldinput;
  if (type==0)
  {
    cGrid=fieldinput->getGrid(3,8);
  }
  else if (type==1)
  {
    cGrid=fieldinput->getGrid(3,9);
  }
  else if (type==2)
  {
    cGrid=fieldinput->getGrid(3,10);
  }
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

void setDefault(Dwarf& d0,Dwarf& d1,Dwarf& d2)
{
//setting status
  d0.sleep();
  d1.sleep();
  d2.sleep();
//setting posisi
/*  cmap->setvalpoint(cpos,' ');
  d0.setPosition(3,8);
  cmap->setvalpoint(cpos,'3');
  cmap->setvalpoint(cpos,' ');
  d0.setPosition(3,9);
  cmap->setvalpoint(cpos,'3');
  cmap->setvalpoint(cpos,' ');
  d0.setPosition(3,10);
  cmap->setvalpoint(cpos,'3');*/
  d0.setDirection(2);
  d1.setDirection(2);
  d2.setDirection(2);
//setting Grid kurcaci
  if (d0.cGrid->getPosisi().getX()<3)
  {
    d0.cGrid->setType(GJALAN);
  }
  else 
  {
    d0.cGrid->setType(GLAHAN);
  }
  d0.cGrid=Field->getGrid(2,7);
  cGrid->setType(WKURCACI);
  
  if (d1.cGrid->getPosisi().getX()<3)
  {
    d1.cGrid->setType(GJALAN);
  }
  else 
  {
    d1.cGrid->setType(GLAHAN);
  }
  d1.cGrid=Field->getGrid(2,8);
  cGrid->setType(HKURCACI);
  
  if (d2.cGrid->getPosisi().getX()<3)
  {
    d2.cGrid->setType(GJALAN);
  }
  else 
  {
    d2.cGrid->setType(GLAHAN);
  }
  d2.cGrid=Field->getGrid(2,9);
  cGrid->setType(SKURCACI);
  
}
  
//return type dwarf
int Dwarf::getType()
{
  return type;
}

//dwarf melakukan perkerjaan , return true jika pekerjaan berhasil dilakukan false jika tidak
bool Dwarf::doJob()
{
  
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

void Dwarf::setPosition(int i,int j)
{
  cpos.setX(i);
  cpos.setY(j);
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
  if (direction==3)
    return cpos.getLeft();
  else if (direction==4)
    return cpos.getUp();
  else if (direction==1)
    return cpos.getRight();
  else if (direction==2)
    return cpos.getDown();
}

//setting map dari grid
void Dwarf::setmap()
{
  int i,j;
  cmap->sett0(0);
  cmap->sett1(0);
  cmap->sett2(0);
  for(i=0;i<MAXBARIS;++i)
  {
    for(j=0;j<MAXKOLOM;++i)
    {
      Grid *tGrid=field->getGrid(i,j);
      int tG=tGrid->getType();
      if ((tG==GSELLINGBOX) || (tG==GUNSTEP))
      {
        cmap->setmapij(i+1,j+1,'#');
      }
      else if (tG==GPLAYER)
      {
        cmap->setmapij(i+1,j+1,'3');
      }
      else if (tG==GTANAMAN)
      {
        Grid_Plant * tGP=(Grid_Plant *)tGrid;
        int fase=tGP->getFase();
        
        if ((fase==DEWASA) || (fase==SDEWASA))
        {
          cmap->setmapij(i+1,j+1,'1');
          cmap->sett1(cmap->gett1()+1);
        }
        else if (fase==MATI)
        {
          cmap->setmapij(i+1,j+1,'2');
          cmap->sett2(cmap->gett2()+1);
        }
        else if (!tGP->isWatered())
        {
          cmap->setmapij(i+1,j+1,'0');
          cmap->sett3(cmap->gett3()+1);
        }
        else if (tGP->isWatered())
        {
          cmap->setmapij(i+1,j+1,'4');
        }
      }
    }
  }
}

void Dwarf::bfsdwarf()
{
     if ( (((type==0) && (cmap->gett0()!=0)) || ((type==1) && (cmap->gett1()!=0)) || ((type==2) && (cmap->gett2()!=0))) && (status==1) )
     {
     delete dwarfdqp;
     dwarfdqp=new deque<Point>;
     pair<Point,Point> sp;
     sp.first=cpos;
     sp.second=cpos;
     //cout << "cpos : " << cpos.getX() << ',' << cpos.getY() << endl;
     deque< pair<Point,Point> > dqptemp,dqptemp1,dqtemp2;
     dqptemp.push_back(sp);
     dqptemp1.push_back(sp);
     int i,j;
     map tmap;
     for(i=0;i<tmap.getsizer();i++)
       for(j=0;j<tmap.getsizec();j++)
         tmap.setmapij(i,j,cmap->getvalij(i,j));
     Point tesp;
     bool found=false;
     if ( chartoint(cmap->getvalpoint(cpos.getLeft()))==type )
     {
       dwarfdqp->push_back(cpos.getLeft());
     }
     else if ( chartoint(cmap->getvalpoint(cpos.getUp()))==type )
     {
       dwarfdqp->push_back(cpos.getUp());
     }
     else if ( chartoint(cmap->getvalpoint(cpos.getRight()))==type )
     {
       dwarfdqp->push_back(cpos.getRight());
     }
     else if ( chartoint(cmap->getvalpoint(cpos.getDown()))==type )
     {
       dwarfdqp->push_back(cpos.getDown());
     }
     else
     {
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
     //cout << dqptemp1.front().second.getX() << ',' << dqptemp1.front().second.getY() << endl;
     //cout << dqptemp1.back().second.getX() << ',' << dqptemp1.back().second.getY() << endl;
     while ( (sp.first.getX()!=sp.second.getX()) || (sp.first.getY()!=sp.second.getY()) )
     {
       dqptemp1.pop_back();
       if ( (dqptemp1.back().second.getX()==sp.first.getX()) && (dqptemp1.back().second.getY()==sp.first.getY()) )
       {
         dwarfdqp->push_front(sp.second);
         sp=dqptemp1.back();
       }
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
}

void Dwarf::oneMove()
{
     if ( (((type==0) && (cmap->gett0()!=0)) || ((type==1) && (cmap->gett1()!=0)) || ((type==2) && (cmap->gett2()!=0))) && (status==1) )
     {
     //cout << "isi dequedwarf " << (*dwarfdqp)[0].getX() << ',' << (*dwarfdqp)[0].getY() << endl;
     //cout << "cpos : " << cpos.getX() << ',' << cpos.getY() << endl;
     //cout << "front : " << getFrontpoint().getX() << ',' << getFrontpoint().getY() << endl;
     if ((*dwarfdqp)[0]==getFrontpoint())
     {
       if (  chartoint( cmap->getvalpoint(getFrontpoint()) )==type )
       {
         //cout << "success\n";
         //di sini ubah cpos, map dan grid, gunakan dojob(), tergantung pada type masing2 dwarf
         if (type==0)
         {
           //dojob() untuk water
           //cout << getFrontPoint
           //mengganti karakter 3 menjadi 4
           cmap->setvalpoint(getFrontpoint(),'4');
           cmap->sett0(cmap->gett0()-1);
         }
         else if (type==1)
         {
           //dojob() untuk harvest, mengganti karakter 1 menjadi 2
           cmap->setvalpoint(getFrontpoint(),'2');
           cmap->sett1(cmap->gett1()-1);
           cmap->sett2(cmap->gett2()+1);
         }
         else if (type==2)
         {
           //dojob() untuk slash, mengganti karakter 2 menjadi ' '
           cmap->setvalpoint(getFrontpoint(),' ');
           cmap->sett2(cmap->gett2()-1);
         }
       }
       else
       {
         //disini ubah posisi dwarf, ubah grid dan map
         cmap->setvalpoint(cpos,' ');

         if (cGrid->getPosisi().getX()<3)
         {
           cGrid->setType(GJALAN);
         }
         else 
         {
           cGrid->setType(GLAHAN);
         }
         cpos=getFrontpoint();
         cGrid=Field->getGrid(cpos.getX()-1,cpos.getY()-1);
         cmap->setvalpoint(cpos,'3');
         cGrid->setType(type+10);
       }
     }
     else//kasus jika hanya mengubah arah saja
     {
       if ((*dwarfdqp)[0]==cpos.getLeft())
       {
         //cout << "LEFT\n";
         direction=3;
       }
       else if ((*dwarfdqp)[0]==cpos.getUp())
       {
         //cout << "UP\n";
         direction=4;
       }
       else if ((*dwarfdqp)[0]==cpos.getRight())
       {
         //cout << "RIGHT\n";
         direction=1;
       }
       else if ((*dwarfdqp)[0]==cpos.getDown())
       {
         //cout << "DOWN\n";
         direction=2;
       }
     }
     //cout << "cpos : " << cpos.getX() << ',' << cpos.getY() << endl;
     //cout << "front : " << getFrontpoint().getX() << ',' << getFrontpoint().getY() << endl;
     }
}   
         
void Dwarf::nextMove(Dwarf& d0,Dwarf& d1,Dwarf &d2)
{
     /*cout << "tes\n";
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
     }*/
     d0.bfsdwarf();
     d0.oneMove();
     d1.bfsdwarf();
     d1.oneMove();
     d2.bfsdwarf();
     d2.oneMove();
     cmap->performmap();
}

Grid *Dwarf::getFrontGrid()
{
  	Grid* front;
	Point p;
	int temp;
	
	
	p = curGrid->getPosisi();
	if ((arahHadap == 1) && (p.getY() < 9)) {
		temp = p.getY();
		temp++;
		p.setY(temp);
		front = curArea->getGrid(p);
		return front;
	} else if ((arahHadap == 2) && (p.getX() < 9)) {
		temp = p.getX();
		temp++;
		p.setX(temp);
		front = curArea->getGrid(p);
		return front;
	} else if ((arahHadap == 3) && (p.getY() > 0)) {
		temp = p.getY();
		temp--;
		p.setY(temp);
		front = curArea->getGrid(p);
		return front;
	} else if ((arahHadap == 4) && (p.getX() > 0)) {
		temp = p.getX();
		temp--;
		p.setX(temp);
		front = curArea->getGrid(p);
		return front;
	} else {
		return NULL;
	}
}
