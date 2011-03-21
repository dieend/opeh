#include "dwarf.h"
#include "map.h"
#include "../item/item.h"
#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#define chartoint(c) int(c)-int('0')
using namespace std;


//inisialisasi map baru
map *Dwarf::cmap= new map();

Area* Dwarf::Field = NULL;
//inisialisasi dwarf dengan menggunakan int ntype
Dwarf::Dwarf(int ntype) : type(ntype),status(0),direction(2)
{
  if (type==0)
  {
    cGrid=Field->getGrid(2,7);
  }
  else if (type==1)
  {
    cGrid=Field->getGrid(2,8);
  }
  else if (type==2)
  {
    cGrid=Field->getGrid(2,9);
  }
  cGrid->setType(type+10);
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
  if  (cGrid->getPosisi().getX()<3)
  {
    cGrid->setType(GJALAN);
  }
  else 
  {
    cGrid->setType(GLAHAN);
  }
  if (Field->getGrid(2,7+type)->getType()==GLAHAN)
  {
    setPosition(3,8+type);
    cGrid=Field->getGrid(2,7+type);
  }
  else
  {
    bool found=false;
	int i=0;
	while ((i<3) && (!found))
	{
	  if (Field->getGrid(2,7+i)->getType()==GLAHAN)
	    found=true;
	  else
	    ++i;
	}
	if (found)
	{
	  setPosition(3,8+i);
	  cGrid=Field->getGrid(2,7+i);
	}
	else
	{
	  setPosition(3,7);
	  cGrid=Field->getGrid(2,6);
	}
  }
  cmap->setvalpoint(cpos,'3');
  cGrid->setType(type+10);
}

void Dwarf::setDefault(Dwarf& d0,Dwarf& d1,Dwarf& d2)
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
  d0.cGrid=d0.Field->getGrid(2,7);
  d0.cGrid->setType(WKURCACI);
  
  if (d1.cGrid->getPosisi().getX()<3)
  {
    d1.cGrid->setType(GJALAN);
  }
  else 
  {
    d1.cGrid->setType(GLAHAN);
  }
  d1.cGrid=d1.Field->getGrid(2,8);
  d1.cGrid->setType(HKURCACI);
  
  if (d2.cGrid->getPosisi().getX()<3)
  {
    d2.cGrid->setType(GJALAN);
  }
  else 
  {
    d2.cGrid->setType(GLAHAN);
  }
  d2.cGrid=d2.Field->getGrid(2,9);
  d2.cGrid->setType(SKURCACI);
  
}
  
//return type dwarf
int Dwarf::getType()
{
  return type;
}

//dwarf melakukan perkerjaan , return true jika pekerjaan berhasil dilakukan false jika tidak
int Dwarf::doJob()
{
	int retval;
    if (type==0)//dojob untuk type 0 adalah water
	{
		retval=0;
		int tipe;
		Grid* front = getFrontGrid();
		Grid_Plant* tanaman;
		Grid_Lahan* lahan;
		Point p;
	
		if (front != NULL) {
			tipe = front->getType();
			p = front->getPosisi();
			if (tipe == GLAHAN) {
				lahan = (Grid_Lahan*)front;
				lahan->setSiram();
			} else if (tipe == GTANAMAN) {
				tanaman = (Grid_Plant*)front;
				if (!(tanaman->isWatered())) {
				tanaman->setSiram();
				}
			}
		}
		return retval;
	}
	else if (type==1)//dojob untuk type 1 adalah harvest
	{
		int tipe;
		int fase;
		Grid* front = getFrontGrid();
		Grid_Plant* tanaman;
		Point p;	
		if (front != NULL) {
			tipe = front->getType();
			p = front->getPosisi();
			if (tipe == GTANAMAN) {
				tanaman = (Grid_Plant*)front;
				fase = tanaman->getFase();
				if ((fase == DEWASA) || (fase == SDEWASA)) {
					tanaman->setPanen();
					Item *itdwarf = Item::makeBuah(tanaman);
					retval=itdwarf->getCostSell();
					delete itdwarf;
				// if (tanaman->getFase() == MATI) {
					// delete front;
					// front = new Grid_Lahan(p,0,0);
					// curArea->setGrid(front);
				// }
				}
				else
				{
					retval=0;
				}
			}
		}
		return retval;
	}
	else if (type==2)//dojob untuk type 2 adalah slash
	{
		retval=0;
		int tipe;
		Grid* front = getFrontGrid();
		Grid_Plant* tanaman;
		Point p;
	
		if (front != NULL) {
			tipe = front->getType();
			p = front->getPosisi();
			if (tipe == GTANAMAN) {
				tanaman = (Grid_Plant*)front;
				if ((tanaman->getFase() >= REMAJA) && (tanaman->getFase() < DBIBIT )) {
					delete front;
					front = new Grid_Lahan(p,GLAHAN,0);
					Field->setGrid(front);
				}
			}
		}
		return retval;
	}
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
  for(i=0;i<MAXROW;i++)
  {
    for(j=0;j<MAXCOLUMN;j++)
    {
      Grid* tGrid=Field->getGrid(i,j);
      int tG=tGrid->getType();
      if ((tG==GSELLINGBOX) || (tG==GUNSTEP))
      {
          cout << "sellbox";
        cmap->setmapij(i+1,j+1,'#');
      }
      else if (tG==GPLAYER || tG==HKURCACI || tG==WKURCACI || tG==SKURCACI)
      {
          cout << "player";
          cmap->setmapij(i+1,j+1,'3');
      }
      else if (tG==GTANAMAN)
      {
          cout << "tanaman";
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
          cmap->sett0(cmap->gett0()+1);
        }
        else if (tGP->isWatered())
        {
          cmap->setmapij(i+1,j+1,'4');
        }
      } else {
          cmap->setmapij(i+1,j+1,' ');
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

int Dwarf::oneMove()
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
		   doJob();
		   return 0;
         }
         else if (type==1)
         {
           //dojob() untuk harvest, mengganti karakter 1 menjadi 2
           cmap->setvalpoint(getFrontpoint(),'2');
           cmap->sett1(cmap->gett1()-1);
           cmap->sett2(cmap->gett2()+1);
		   return doJob();
         }
         else if (type==2)
         {
           //dojob() untuk slash, mengganti karakter 2 menjadi ' '
           cmap->setvalpoint(getFrontpoint(),' ');
           cmap->sett2(cmap->gett2()-1);
		   doJob();
		   return 0;
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
		 return 0;
       }
	   return 0;
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
	   return 0;
     }
     //cout << "cpos : " << cpos.getX() << ',' << cpos.getY() << endl;
     //cout << "front : " << getFrontpoint().getX() << ',' << getFrontpoint().getY() << endl;
     }
	 else if ((status==0) || ( (type==0) && (cmap->gett0()==0) ) || ((type==1) && (cmap->gett1()==0)) || ((type==2) && (cmap->gett2()==0)))
	 {
	   setDefault();
	   return 0;
	 }
}   
         
int Dwarf::nextMove(Dwarf& d0,Dwarf& d1,Dwarf &d2)
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
	 int val;
     d0.bfsdwarf();
     d0.oneMove();
     d1.bfsdwarf();
     money=d1.oneMove();
     d2.bfsdwarf();
     d2.oneMove();
	 return money;
}

Grid *Dwarf::getFrontGrid()
{
  	Grid* front;
	Point p;
	int temp;
	
	
	p = cGrid->getPosisi();
	if ((direction == 1) && (p.getY() < 9)) {
		temp = p.getY();
		temp++;
		p.setY(temp);
		front = Field->getGrid(p);
		return front;
	} else if ((direction == 2) && (p.getX() < 9)) {
		temp = p.getX();
		temp++;
		p.setX(temp);
		front = Field->getGrid(p);
		return front;
	} else if ((direction == 3) && (p.getY() > 0)) {
		temp = p.getY();
		temp--;
		p.setY(temp);
		front = Field->getGrid(p);
		return front;
	} else if ((direction == 4) && (p.getX() > 0)) {
		temp = p.getX();
		temp--;
		p.setX(temp);
		front = Field->getGrid(p);
		return front;
	} else {
		return NULL;
	}
}


ostream& operator<<(ostream& c, Dwarf* p){
    if (p->getType()==0){
        Utilities::getInstances().setFG(BLUE);
    } else if (p->getType()==1){
        Utilities::getInstances().setFG(YELLOW);
    } if (p->getType()==2){
        Utilities::getInstances().setFG(RED);
    }
    int xUL = p->cGrid->getPosisi().getX()*4+11;
    int yUL = p->cGrid->getPosisi().getY()*6+7;
    Utilities::getInstances().gotoxy(yUL+2,xUL+1);
    if (p->getDirection() == 1) {
        c << (char) 16;
    } else if (p->getDirection() == 2) {
        c << (char) 31;
    } else if (p->getDirection() == 3) {
        c << (char) 17;
    } else {
        c << (char) 30;
    }
    Utilities::getInstances().resetFG();
    return c;
}

map* Dwarf::getMap(){
    return cmap;
}