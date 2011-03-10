#include <cstdlib>
#include <iostream>
#include "time.h"
using namespace std;

int main(int argc, char *argv[])
{
    Time rt;
    int x=50;
    while (x--)
    {
          rt.nextMinutes(10);
          cout << "minutes : " << rt.getMinutes() << "|jam = " << rt.getJam() << "|day = " << rt.getDay() << "|season = " << rt.getSeason() << endl;
          if (rt.iscJam())
            cout << "jam berganti\n";
          else
            cout << "jam tidak berganti\n";
          if (rt.iscDay())
            cout << "hari berganti\n";
          else 
            cout << "hari tidak berganti\n";
          if (rt.iscSeason())
            cout << "season berganti\n";
          else 
            cout << "season tidak berganti\n";
    }
    system("PAUSE");
    return 0;
}
