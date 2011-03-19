#include "util.h"

Utilities* Utilities::utilities = NULL;

Utilities::Utilities(){
    color = 0x07;
}

Utilities& Utilities::getInstances(){
	if (Utilities::utilities == NULL) {
		Utilities::utilities = new Utilities();
	}

	return *(Utilities::utilities);
}

void Utilities::setBG(int B){
    oldBG.push(color&0xF0);
    color &= 0x0F;
    B <<= 4;
    color |= B;
    draw();
}
void Utilities::setFG(int F){
    oldFG.push(color&0x0F);
    color &= 0xF0;
    color|=F;
    draw();
}
void Utilities::setColor(int B,int F){
    Utilities::setBG(B);
    Utilities::setFG(F);
}

void Utilities::resetColor(){
    resetBG();
    resetFG();
}
void Utilities::draw(){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, color);
}

void Utilities::destroy() {
    if (Utilities::utilities != NULL) delete Utilities::utilities;
}
void Utilities::gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int Utilities::wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int Utilities::wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }

void Utilities::resetBG(){
    int B;
    if (!oldBG.empty()){
        B= oldBG.top();
        printf("%x",B);
        oldBG.pop();
    } else B=0x00;
    setBG(B);
}

void Utilities::resetFG(){
    int F;
    if (!oldFG.empty()) {
        F = oldFG.top();
        printf("%x",F);
        oldFG.pop();
    } else F=0x07;
    setFG(F);
}