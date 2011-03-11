#include <cstdlib>
#include <iostream>
#include "time.h"
using namespace std;

int main(int argc, char *argv[])
{
    Time rt;
    //ini fungsi waktu dipake per aksi , 1 inputan anda untuk 1 aksi
    int n=100;
    while (n--)
    {
      int state;
      cin >> state;
      rt.next10Minutes(state);
      rt.performtime();
    }
    system("PAUSE");
    return 0;
}
