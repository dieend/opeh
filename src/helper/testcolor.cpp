#include <iostream>
#include "util.h"
using namespace std;
int main()
{
  
  Utilities::getInstances().setBackground(RED);
  Utilities::getInstances().setForeground(YELLOW);
  // Utilities::getInstances().resetColor();
  Utilities::getInstances().setBackground(WHITE);
  cout << "TEST\n";
  // cout << lahan_watered << " test " << white;
}
