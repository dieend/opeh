#include "map.h"
#include <iostream>
using namespace std;

map::map(): sizer(12),sizec(12)
{
  arr = new char* [sizer];
  int i,j;
  for(i=0;i<sizer;i++)
    arr[i] = new char[sizec];
    
  for(i=0;i<sizer;i++)
    for(j=0;j<sizec;j++)
      arr[i][j]=' ';
      
  for(i=0;i<sizer;i++)
  {
    arr[i][0]='#';
    arr[i][sizec-1]='#';
  }
  for(i=0;i<sizec;i++)
  {
    arr[0][i]='#';
    arr[sizer-1][i]='#';
  }
  //setting titik penjualan
  arr[1][8]='#';
  arr[1][9]='#';
  //setting posisi default dwarf
  arr[3][8]='3';
  arr[3][9]='3';
  arr[3][10]='3';
  arr[7][5]='0';
  for(i=2;i<=7;i++)
    arr[5][i]='1';
  for(i=3;i<=7;i++)
    arr[6][i]='1';
  arr[7][6]='2';
  arr[7][7]='2';
  arr[8][6]='2';
  arr[8][7]='2';
  arr[2][8]='0';
  t0=2;
  t1=11;
  t2=4;  
}

//dtor map
map::~map()
{
  cout << "dtor\n";
  for(int i=0;i<sizec;i++)
    delete [] *arr;
  delete [] arr;
}

map::map(const map& m)
{
  int i,j;
  sizer=m.sizer;
  sizec=m.sizec;
  
  for(i=0;i<sizec;i++)
    delete [] *arr;
  delete [] arr;

  arr = new char* [sizer];
  for(i=0;i<sizer;i++)
    arr[i] = new char[sizec];
    
  for(i=0;i<=sizer;i++)
    for(j=0;j<sizec;j++)
      arr[i][j]=m.arr[i][j];
      
  t0=m.t0;
  t1=m.t1;
  t2=m.t2;
}

map& map::operator=(const map &m)
{
     sizer=m.sizer;
     sizec=m.sizec;
     int i,j;
     for(i=0;i<sizer;i++)
       for(j=0;j<sizec;j++)
         arr[i][j]=m.arr[i][j];
     return (*this);
}

//mengembalikan ukutan baris map
int map::getsizer()
{
  return sizer;
}

//mengembalikan ukuran kolom map
int map::getsizec()
{
  return sizec;
}

//setting value map[i][j] menjadi val
void map::setmapij(int i,int j,char val)
{
  arr[i][j]=val;
}

char map::getvalij(int i,int j)
{
  return arr[i][j];
}

void map::setvalpoint(Point p,char nc)
{
  setmapij(p.getX(),p.getY(),nc);
}

char map::getvalpoint(Point p)
{
  return arr[p.getX()][p.getY()];
}

//menampilkan isi map untuk debugging
void map::performmap()
{
  int i,j;
  for(i=0;i<sizer;i++)
  {
    for(j=0;j<sizec;j++)
      cout << arr[i][j];
    cout << endl;
  }
}

void map::sett0(int nt0)
{
  t0=nt0;
}

void map::sett1(int nt1)
{
  t1=nt1;
}

void map::sett2(int nt2)
{
  t2=nt2;
}

int map::gett0()
{
  return t0;
}

int map::gett1()
{
  return t1;
}

int map::gett2()
{
  return t2;
}
