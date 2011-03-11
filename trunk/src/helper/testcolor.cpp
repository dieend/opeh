#include <conio.h>
#include <cstdio>
#include <iostream>
#include "color.h"
using namespace std;
int main()
{
  
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hStdout, BACKGROUND_BLUE);
  cout << "tes "<< endl;
  // cout << lahan_watered << " test " << white;
}
