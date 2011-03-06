#include "map.h"
#include <iostream>
using namespace std;

map::map() : sizer(13),sizec(12)
{
  arr = new int* [sizer];
  int i,j;
  for(i=0;i<13;i++)
    arr[i] = new int[sizec];
  for(i=0;i<sizer;i++)
  {
    arr[i][0]=4;
    arr[i][sizec-1]=4;
  }
  for(i=0;i<sizec;i++)
  {
    arr[0][i]=4;
    arr[sizer-1][i]=4;
  }
  for(i=1;i<8;i++)
    arr[1][i]=4;
  for(i=1;i<sizer-1;i++)
    for(j=1;j<sizec-1;j++)
      arr[i][j]=0;
  arr[1][8]=arr[1][9]=arr[1][10]=5;
}

map::~map()
{
  cout << "dtor map\n";
  for(int i=0;i<sizec;i++)
    delete [] *arr;
  delete [] arr;
}

int map::getsizer()
{
  return sizer;
}

int map::getsizec()
{
  return sizec;
}

void map::setmapij(int i,int j,int val)
{
  arr[i][j]=val;
}

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

void bfsdwarf(dwarf d,deque<int> &dq)
{
}
