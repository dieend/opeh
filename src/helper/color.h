#pragma once
#include <iostream>
#include <windows.h>
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
using namespace std;

class Utilities{
private:
    Utilities();
    int color;
	Utilities * utilities;
	void draw();
public:
	static Utilities* getInstances();
	void setBackground(int);
	void setForeground(int);
	void resetColor();
};

