#include <conio.h>
#include <cstdio>
#include <iostream>
#include "util.h"
using namespace std;
int main()
{
  
  Utilities::getInstances()->setBackground(RED);
  Utilities::getInstances()->setForeground(YELLOW);
  cout << "TEST\n";
  Utilities::getInstances()->resetColor();
  // cout << lahan_watered << " test " << white;
}
