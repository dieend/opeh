#ifndef UTIL_H
#define UTIL_H

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LBLUE 9
#define LGREEN 10
#define LAQUA 11
#define LRED 12
#define LPURPLE 13
#define LYELLOW 14
#define LWHITE 15
#include <cstdio>
#include <windows.h>
#include <stack>
using namespace std;
class Utilities{
private:
    Utilities();
    int color;
    stack<int> oldFG;
    stack<int> oldBG;
    void draw();
    static Utilities* utilities;
public:
    static Utilities& getInstances();
    void setColor(int,int);
    void setBG(int);
    void setFG(int);
    void resetColor();
    void resetBG();
    void resetFG();
    void destroy();
    void gotoxy(int,int);
    int wherex();
    int wherey();
};

#endif
