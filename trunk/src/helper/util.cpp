#include "util.h"

Utilities* Utilities::utilities = NULL;

Utilities::Utilities(){
    color = 0x07;
}
void Utilities::setError(char* kata){
    error = kata;
}
void Utilities::printError(){
    gotoxy(3,53);
    cout << error;
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
        oldBG.pop();
    } else B=0x00;
    color &= 0x0F;
    color |= B;
    draw();
}

void Utilities::resetFG(){
    int F;
    if (!oldFG.empty()) {
        F = oldFG.top();
        oldFG.pop();
    } else F=0x07;
    color &= 0xF0;
    color |= F;
    draw();
}

void Utilities::printPeta(ostream& c)
{
    gotoxy(0,0);
	c << char(201)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	c << char(186); setBG(LAQUA);setFG(BLACK); c <<"                  OOO   PPPP   EEEE  HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LAQUA); c <<"  ";setFG(RED); c << "_____"; resetFG();setFG(BLACK); c << "          OO OO  PP PP  EE    HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LAQUA); c <<" ";setFG(RED); c << "////"<<char(92) << char(92) << char(92); resetFG();setFG(BLACK); c <<"         OO OO  PPPP   EEEE  HHHHH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LGREEN);setFG(RED); c <<"////  "<<char(92) << char(92) << char(92) ; resetFG();setFG(BLACK); c <<"        OO OO  PP     EE    HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LGREEN);setFG(YELLOW); c <<"|___[]__|";resetFG();setFG(BLACK); c << "         OOO   PP     EEEE  HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;	
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LGREEN); c <<"                                                 "; resetBG();setBG(GRAY); c << "            "; resetBG(); c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LGREEN); c <<"           ";setFG(BLACK);c <<"______________________________";resetFG(); c <<"        ";resetBG();setBG(GRAY);c << char (201);for (int i = 1; i <= 9 ; i++) {c<< char(205);}c <<char (187) << " "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LGREEN); c <<"          ";setFG(BLACK);setBG(LAQUA);c <<"/  ";setFG(RED);c <<"x> x>  <x      x>       x>  ";resetFG(); c << "\\";resetBG();resetFG();c <<"       ";resetBG();setBG(GRAY);c << char (186); c << "    ";setFG(LYELLOW);c << char(148); resetFG(); c <<"    " << char (186) <<" "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LGREEN); c <<"         ";setFG(BLACK);setBG(LAQUA);c <<char(179);c << "   ";setFG(LYELLOW);c << "<x  x> ";resetFG();c <<"_____________";setFG(LYELLOW); c << " x> x>   ";resetFG();c << char(179);resetBG();resetFG();c <<"      ";resetBG();setBG(GRAY);c << char (204);for (int i = 1; i <= 9 ; i++) {c<< char(205);}c <<char (185) <<" "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LGREEN); c <<"          ";setFG(BLACK);setBG(LAQUA);c << "\\________/";resetBG();c << "             ";setBG(LAQUA);c << "\\_______/"; resetBG(); resetFG(); c <<"       " ;resetBG();setBG(GRAY);c << char (186); setBG(YELLOW); c <<"         "; resetBG(); c << char (186) <<" "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GRAY); c <<"  xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx  " << char (186); setBG(YELLOW); c << "         "; resetBG(); c << char (186) <<" "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GRAY); c <<" xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx " << char (186); setBG(YELLOW); c << "         "; resetBG(); c << char (186) <<" "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GRAY); c <<"  xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx  " << char (200);for (int i = 1; i <= 9 ; i++) {c<< char(205);}c << char (188) <<" "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GRAY); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GRAY); c <<"  xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx  "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GRAY); c <<" xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx xxxxx "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GRAY); c <<"  xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx   xxx  "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(GREEN); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"           "<<char(186)<<"                                   "<<char(186)<<"                       "<< char(186) << endl;
	c << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"           "<<char(186)<<"                                   "<<char(186)<<"                       "<< char(186) << endl;
	c << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"           "<<char(186)<<"                                   "<<char(186)<<"                       "<< char(186) << endl;
	c << char(200)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);

}

void Utilities::printToko(ostream& c) {
	gotoxy(0,0);
	c << char(201)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	c << char(186);setBG(LAQUA);setFG(BLACK); c <<"                     OOO   PPPP   EEEE  HH HH                          ";resetBG();resetFG(); c << char(186) << endl;
	c << char(186);setBG(LAQUA);setFG(BLACK); c <<"  -- --             OO OO  PP PP  EE    HH HH                          ";resetBG();resetFG(); c << char(186) << endl;
	c << char(186);setBG(LAQUA);setFG(BLACK); c <<" |__|__|            OO OO  PPPP   EEEE  HHHHH                          ";resetBG();resetFG(); c << char(186) << endl;
	c << char(186);setBG(LGREEN);setFG(BLACK); c <<" |  |  |            OO OO  PP     EE    HH HH                          ";resetBG();resetFG(); c << char(186) << endl;
	c << char(186);setBG(LGREEN);setFG(BLACK); c <<"  -- --              OOO   PP     EEEE  HH HH                          ";resetBG();resetFG(); c << char(186) << endl;	
	c << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                              ";setFG(RED); c << "_____ _____"; resetFG(); c << "                  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                             ";setFG(RED); c << "|";setBG(LRED);c << "__"; resetBG(); c<< "|";setBG(LRED);c << "__"; resetBG(); c<< "|";setBG(LRED);c << "__"; resetBG(); c<< "|";setBG(LRED);c << "__"; resetBG(); c<< "|";resetFG();c << " "<< char(201)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205) << char(187) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                             ";setFG(RED); c << "|";setBG(LRED);c << "__"; resetBG(); c<< "|";setBG(LRED);c << "__"; resetBG(); c<< "|";setBG(LRED);c << "__"; resetBG(); c<< "|";setBG(LRED);c << "__"; resetBG(); c<< "|";resetFG();c << " "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"    "<<char(17)<<"       ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"    ";setFG(LRED); c <<char(17); resetFG(); c <<"       ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(201) <<char(205) <<char(187) <<"  "<<char(201)<< char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<char(187)<<"  "<<char(201) <<char(205) <<char(187) <<"               "<< char(186);setBG(LBLUE); c <<"    ";setFG(LGREEN); c <<char(17); resetFG(); c <<"       ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(186);setFG(BLUE); c <<char(16) ;resetFG(); c <<char(186)<<"  "<<char(186);setBG(LGREEN);setFG(GREEN); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(186);setFG(LRED); c  <<char(17) ;resetFG(); c  <<char(186)<<"               "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(200) <<char(205) <<char(188) <<"  "<<char(186);setBG(LGREEN);setFG(GREEN); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(200) <<char(205) <<char(188) <<"               "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"            "<<char(186);setBG(LGREEN);setFG(GREEN); c <<"----O----";resetBG();resetFG(); c <<char(186)<<"                    "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(201) <<char(205) <<char(187) <<"  "<<char(186);setBG(LGREEN);setFG(GREEN); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(201) <<char(205) <<char(187) <<"               "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(186);setFG(LRED); c   <<char(16) ;resetFG(); c <<char(186)<<"  "<<char(186);setBG(LGREEN);setFG(GREEN); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(186);setFG(BLUE); c  <<char(17) ;resetFG(); c  <<char(186)<<"               "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(200) <<char(205) <<char(188) <<"  "<<char(200)<< char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<char(188)<<"  "<<char(200) <<char(205) <<char(188) <<"               "<< char(186);setBG(LBLUE); c <<"    ";setFG(YELLOW); c <<char(17); resetFG(); c <<"       ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"                                           "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(201) <<char(205) <<char(187) <<"  "<<char(201)<< char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<char(187)<<"  "<<char(201) <<char(205) <<char(187) <<"               "<< char(186);setBG(LBLUE); c <<"    ";setFG(BLACK); c <<char(17); resetFG(); c <<"       ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(186);setFG(LRED); c   <<char(16) ;resetFG(); c  <<char(186)<<"  "<<char(186);setBG(LBLUE);setFG(BLUE); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(186);setFG(BLUE); c   <<char(17) ;resetFG(); c   <<char(186)<<"               "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(200) <<char(205) <<char(188) <<"  "<<char(186);setBG(LBLUE);setFG(BLUE); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(200) <<char(205) <<char(188) <<"               "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ";setBG(YELLOW);c<<"            "<<char(186);setBG(LBLUE);setFG(BLUE); c <<"----O----";resetBG();resetFG(); c <<char(186)<<"                    "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"      "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(201) <<char(205) <<char(187) <<"  "<<char(186);setBG(LBLUE);setFG(BLUE); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(201) <<char(205) <<char(187) <<"               "<< char(186);setBG(LBLUE); c <<"            ";resetBG(); c << char(186) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(186);setFG(BLUE); c  <<char(16) ;resetFG(); c  <<char(186)<<"  "<<char(186);setBG(LBLUE);setFG(BLUE); c <<"    |    ";resetBG();resetFG(); c <<char(186)<<"  "<<char(186);setFG(LRED); c   <<char(17) ;resetFG(); c   <<char(186)<<"               "<< char(200)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205) << char(188) <<"  ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"     |";setBG(YELLOW);c<<"       "<<char(200) <<char(205) <<char(188) <<"  "<<char(200)<< char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<  char(205) << char(205) << char(205) <<char(188)<<"  "<<char(200) <<char(205) <<char(188) <<"                               ";resetBG();c<<"|     "<< char(186) << endl;
	c << char(186)<<"      ----- ----- ----- ----- ----- ----- ----- ----- ----- -----      "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"  Musim    "<<char(186)<<"   Nama Player                     "<<char(186)<<"    Item 1             "<< char(186) << endl;
	c << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"  Tanggal  "<<char(186)<<"   Status                          "<<char(186)<<"    Item 2             "<< char(186) << endl;
	c << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"  07.30    "<<char(186)<<"                                   "<<char(186)<<"    Item 3             "<< char(186) << endl;
	c << char(200)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
}

void Utilities::printRumah(ostream& c) {
	gotoxy(0,0);
	c << char(201)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	c << char(186); setBG(LAQUA);setFG(BLACK); c <<"                  OOO   PPPP   EEEE  HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LAQUA); c <<"  ";setFG(RED); c << "_____"; resetFG();setFG(BLACK); c << "          OO OO  PP PP  EE    HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LAQUA); c <<" ";setFG(RED); c << "////"<<char(92) << char(92) << char(92); resetFG();setFG(BLACK); c <<"         OO OO  PPPP   EEEE  HHHHH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LGREEN);setFG(RED); c <<"////  "<<char(92) << char(92) << char(92) ; resetFG();setFG(BLACK); c <<"        OO OO  PP     EE    HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(186); setBG(LGREEN);setFG(YELLOW); c <<"|___[]__|";resetFG();setFG(BLACK); c << "         OOO   PP     EEEE  HH HH                             "; resetBG();resetFG(); c << char(186) << endl;
	c << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;	
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LAQUA); setFG(LBLUE); c <<char (201);for(int i = 1; i <= 17; i++) {c << char (205);} c << char (187); resetFG();resetBG();setBG(YELLOW); c << " " ; setFG(BLACK); c << char (199) ;setBG(LGREEN); for (int i = 1; i <= 8; i++) {c << char (196);} resetBG(); c << char (182); resetFG(); c << "            " << char (201);for (int i = 1; i <= 17; i++) {c << char (205);} c << char(187); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LAQUA); setFG(LBLUE); c <<char (186) <<"  ";setFG(WHITE);setBG(WHITE); c << char (218); for (int i = 1; i <= 11; i++) {c << char (196);} c << char (191); resetBG();c  << "  ";resetFG(); c  << char (186); resetFG();resetBG();setBG(YELLOW); c << " " ; setFG(BLACK); c << char (186); setBG(LGREEN); c << "  " ; setFG(LRED); c << char (214); for (int i = 1; i <= 3; i++) {c << char (196);} c << char (191) ; resetFG(); c << " "; resetBG(); c << char (186) ; resetFG(); c << "            " << char (186); setBG(BLACK); c << "                 " ; resetBG();c << char (186) ; resetBG(); c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LAQUA); setFG(LBLUE); c <<char (186) <<"  ";setFG(WHITE);setBG(WHITE); c << char (179) << "           " << char (179) ;resetBG();c << "  ";resetFG(); c  << char (186); resetFG();resetBG();setBG(YELLOW); c << " " ; setFG(BLACK); c << char (186); setBG(LGREEN); c << "  " ; setFG(LRED); c << char (186) ; setBG(WHITE); c << "xxx" ; resetBG(); c << char (179) ; resetFG(); c << " "; resetBG(); c << char (186) ; resetFG(); c << "            " << char (186); setBG(BLACK); c << "                 ";resetBG();c << char (186); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LAQUA); setFG(LBLUE); c <<char (186) <<"  ";setFG(WHITE);setBG(WHITE); c << char (192); for (int i = 1; i <= 11; i++) {c << char (196);} c << char (217); resetBG();c << "  ";resetFG(); c  << char (186); resetFG();resetBG();setBG(YELLOW); c << " "; setFG(BLACK); c << char (186); setBG(LGREEN); c << "  " ; setFG(LRED); c << char (211); for (int i = 1; i <= 3; i++) {c << char (196);} c << char (217); resetFG();c << " "; resetBG();c << char (186); resetFG(); c << "            " << char (186); setBG(BLACK); c << "                 " ;resetBG();c << char (186); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LAQUA); setFG(LBLUE); c <<char (186) <<"                 " << char (186); resetFG();resetBG();setBG(YELLOW); c << " "; setFG(BLACK); c << char (182);setBG(LGREEN) ; for (int i = 1; i <= 8; i++) {c << char (196);} resetBG(); c << char (182); resetFG(); c << "            " << char (200);for (int i = 1; i <= 17; i++) {c << char (205);} c << char(188); resetBG();c <<"     "<< char(186) << endl; 
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (204);for(int i = 1; i <= 17; i++) {c << char (205);} c << char (185); resetFG();resetBG();setBG(YELLOW); c << "                                          "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c <<"/////////////////"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "                                          "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "                                          "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"/////////////////"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "                                          "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "                                          "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"/////////////////"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "                                          "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "                                          "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"/////////////////"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "        _        _____________        _   "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "       /" << char(178) << "\\      ";setBG(PURPLE);c<< "/             \\";resetBG(); c <<"      /" << char(178) << "\\  "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"/////////////////"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "      |"<< char(178) << char(178) << char(178) <<"|    ";setBG(PURPLE);c<< "/               \\";resetBG(); c <<"    |"<< char(178) << char(178) << char(178) <<"| "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (186); setFG(RED); c  <<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"; resetFG(); c << char (186); resetFG();resetBG();setBG(YELLOW); c << "       \\"<< char(178) <<"/    ";setBG(PURPLE);c<< "/                 \\";resetBG(); c <<"    \\"<< char(178) <<"/  "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(LPURPLE); setFG(LBLUE); c <<char (200);for(int i = 1; i <= 17; i++) {c << char (205);} cout << char (188); resetFG();resetBG();setBG(YELLOW); c << "             ";setBG(PURPLE);c<< "/                   \\";resetBG(); c <<"        "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                               ";setBG(PURPLE);c<< "/                     \\";resetBG(); c <<"       "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                              ";setBG(PURPLE);c<< "|                       |";resetBG(); c <<"      "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                              ";setBG(PURPLE);c<< "|                       |";resetBG(); c <<"      "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                              ";setBG(PURPLE);c<< "|                       |";resetBG(); c <<"      "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                              ";setBG(PURPLE);c<< "|                       |";resetBG(); c <<"      "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                              ";setBG(PURPLE);c<< "|                       |";resetBG(); c <<"      "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                               ";setBG(PURPLE);c<< "\\                     /";resetBG(); c <<"       "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                           _    ";setBG(PURPLE);c<< "\\                   /";resetBG(); c <<"    _   "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                          /"<< char(178) <<"\\    ";setBG(PURPLE);c<< "\\                 /";resetBG(); c <<"    /"<< char(178) <<"\\  "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                         |"<< char(178) << char(178) << char(178) <<"|    ";setBG(PURPLE);c<< "\\               /";resetBG(); c <<"    |"<< char(178) << char(178) << char(178) <<"| "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                          \\"<< char(178) <<"/      ";setBG(PURPLE);c<< "\\_____________/";resetBG(); c <<"      \\"<< char(178) <<"/  "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                                                             "; resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"    _____                                  " << char (218); for (int i = 1; i <= 16;i++) {c << char(196);}c << char (191); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"   /";setBG(GREEN);c << "     ";resetBG(); c << "\\                                 " << char (179); setBG(LYELLOW); c << "                " ;resetBG();c << char (179); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"  /";setBG(GREEN);setFG(LGREEN);c << "  xxx  ";resetBG();resetFG(); c << "\\                                " << char (195); for (int i = 1; i <= 16;i++) {c << char(196);}c << char (180); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<" |";setBG(GREEN);setFG(LGREEN);c << "  xxxxx  ";resetBG();resetFG(); c << "|                               " << char (179); setBG(LYELLOW); c << "                " ;resetBG();c << char (179); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<" |";setBG(GREEN);setFG(LGREEN);c << " xxxxxxx ";resetBG();resetFG(); c << "|                               " << char (195); for (int i = 1; i <= 16;i++) {c << char(196);}c << char (180); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<" |";setBG(GREEN);setFG(LGREEN);c << "  xxxxx  ";resetBG();resetFG(); c << "|                               " << char (179); setBG(LYELLOW); c << "                " ;resetBG();c << char (179); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"  \\";setBG(GREEN);setFG(LGREEN);c << "  xxx  ";resetBG();resetFG(); c << "/                                " << char (195); for (int i = 1; i <= 16;i++) {c << char(196);}c << char (180); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"   \\";setBG(GREEN);c << "_____";resetBG(); c << "/                                 " << char (179); setBG(LYELLOW); c << "                " ;resetBG();c << char (179); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"     "; setBG(YELLOW); c <<"                                           " << char (192); for (int i = 1; i <= 16;i++) {c << char(196);}c << char (217); resetBG();c <<"     "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"           "<<char(186)<<"                                   "<<char(186)<<"                       "<< char(186) << endl;
	c << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"           "<<char(186)<<"                                   "<<char(186)<<"                       "<< char(186) << endl;
	c << char(204)<<char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"           "<<char(186)<<"                                   "<<char(186)<<"                       "<< char(186) << endl;
	c << char(200)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);

}

void Utilities::printAwal(ostream& c) {
	gotoxy(0,0);
	c << char(201)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"             ,-----.    .-------.     .-''-.  .---.  .---.             "<< char(186) << endl;
	c << char(186)<<"           .'       '.  \\   ";setBG(LPURPLE); c<<"   ";resetBG(); c<<"  \\  .'      \\ |   |  |   |             "<< char(186) << endl;
	c << char(186)<<"          /   ";setBG(LRED); c<<"     ";resetBG(); c<<"   \\ |  ";setBG(LPURPLE); c<<"  ";resetBG();setBG(LYELLOW); c<<" ";resetBG();setBG(LPURPLE); c<<"  ";resetBG(); c<<" | /  ";setBG(LRED); c<<"   ";resetBG(); c<<"    '|   |   ";setBG(LPURPLE); c<<"   ";resetBG(); c<<"              "<< char(186) << endl;
	c << char(186)<<"         ;   ";setBG(LRED); c<<"       ";resetBG(); c<<"   :|   ";setBG(LPURPLE); c<<"   ";resetBG(); c<<"  /.  ";setBG(LRED); c<<"  ";resetBG();setBG(LYELLOW); c<<" ";resetBG();setBG(LRED); c<<"  ";resetBG(); c<<"   ||   '- ";setBG(LPURPLE); c<<"  ";resetBG();setBG(LYELLOW); c<<" ";resetBG();setBG(LPURPLE); c<<"  ";resetBG(); c<<"             "<< char(186) << endl;
	c << char(186)<<"         |  ";setBG(LRED); c<<"   ";resetBG();setBG(LYELLOW); c<<"   ";resetBG(); setBG(LRED); c<<"   ";resetBG(); c<<"  ||   '-.-' |   ";setBG(LRED); c<<"   ";resetBG(); c<<" ___||       ";setBG(LPURPLE); c<<"   ";resetBG(); c<<"              "<< char(186) << endl;
	c << char(186)<<"         :  ";setBG(LRED); c<<"   ";resetBG(); setBG(LYELLOW); c<<"   ";resetBG(); setBG(LRED); c<<"   ";resetBG(); c<<"  ;|   |     '  \\   .---.|    --.   |             "<< char(186) << endl;
	c << char(186)<<"          \\  ";setBG(LRED); c<<"       ";resetBG(); c<<"  / |   |      \\  `-'    /| ";setBG(LYELLOW); c<<"   ";resetBG(); c<<"  |   |             "<< char(186) << endl;
	c << char(186)<<"           '.       .'  /   )       \\       /  ";setBG(LYELLOW); c<<"  ";resetBG();setBG(YELLOW); c<<" ";resetBG();setBG(LYELLOW);  c<<"  ";resetBG(); c<<" |   |             "<< char(186) << endl;
	c << char(186)<<"             '-----'    `---'        `'-..-'  ' ";setBG(LYELLOW); c<<"   ";resetBG(); c<<"  '---'             "<< char(186) << endl;	
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<" ___       _ __            ______   ___ ___    _ __                    "<< char(186) << endl;
	c << char(186)<<"|   |__   / x  \\          |      | |   |   |  / x  \\                   "<< char(186) << endl;
	c << char(186)<<"|      \\ | (\\__/|         |_    _| |       | | (\\__/|                  "<< char(186) << endl;
	c << char(186)<<"|__X__/   \\____\\            |__|   |___|___|  \\____\\                   "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                   .-') _   ('-.  ) (`-.      .-') _                   "<< char(186) << endl;
	c << char(186)<<"                 ( OO ) )_(  OO)  ( OO ).   (  OO) )                   "<< char(186) << endl;
	c << char(186)<<"             ,--./ ,--,'(,------.(_/.  \\_)-./     '._                  "<< char(186) << endl;
	c << char(186)<<"             |   \\ |  |\\ |  .---' \\  `.'  / |'--...__)                 "<< char(186) << endl;
	c << char(186)<<"             |    \\|  | )|  |      \\     /\\ '--.  .--'                 "<< char(186) << endl;
	c << char(186)<<"             |  .     |/(|  '--.    \\   \\ |    |  |                    "<< char(186) << endl;
	c << char(186)<<"             |  |\\    |  |  .--'   .'    \\_)   |  |                    "<< char(186) << endl;
	c << char(186)<<"             |  | \\   |  |  `---. /  .'.  \\    |  |                    "<< char(186) << endl;
	c << char(186)<<"             `--'  `--'  `------''--'   '--'   `--'                    "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                      ('-.     _  .-')  _   .-')       ('-.  _  .-')   "<< char(186) << endl;
	c << char(186)<<"                     ( OO ).-.( \\( -O )( '.( OO )_   _(  OO)( \\( -O )  "<< char(186) << endl;
	c << char(186)<<"             ,------./ . --. / ,------. ,--.   ,--.)(,------.,------.  "<< char(186) << endl;
	c << char(186)<<"          ('-| _.---'| \\-.  \\  |   /`. '|   `.'   |  |  .---'|   /`. ' "<< char(186) << endl;
	c << char(186)<<"          (OO|(_\\  .-'-'  |  | |  /  | ||         |  |  |    |  /  | | "<< char(186) << endl;
	c << char(186)<<"          /  |  '--.\\| |_.'  | |  |_.' ||  |'.'|  | (|  '--. |  |_.' | "<< char(186) << endl;
	c << char(186)<<"          \\_)|  .--' |  .-.  | |  .  '.'|  |   |  |  |  .--' |  .  '.' "<< char(186) << endl;
	c << char(186)<<"            \\|  |_)  |  | |  | |  |\\  \\ |  |   |  |  |  `---.|  |\\  \\  "<< char(186) << endl;
	c << char(186)<<"             `--'    `--' `--' `--' '--'`--'   `--'  `------'`--' '--' "<< char(186) << endl;                                                    
	c << char(186)<<"                              ";setBG(GRAY); c<<"  ";resetBG();c<<"                                       "<< char(186) << endl;
	c << char(186)<<"                             ";setBG(GRAY); c<<"   ";resetBG();c<<"                                       "<< char(186) << endl;
	c << char(186)<<"                             ";setBG(GRAY); c<<"  ";resetBG();c<<"                  ";setBG(WHITE); c<<"  ";resetBG(); c<<"                    "<< char(186) << endl;
	c << char(186)<<"                             ";setBG(GRAY); c<<" ";resetBG();c<<"                  ";setBG(WHITE); c<<"    ";resetBG(); c<<"  ";setBG(WHITE); c<<"  ";resetBG(); c<<"               "<< char(186) << endl;
	c << char(186)<<"                    ________[_]________      ";setBG(WHITE); c<<"       ";resetBG();;setBG(WHITE); c<<"     ";resetBG(); c<<"              "<< char(186) << endl;
	c << char(186)<<"           ";setBG(WHITE); c<<"  ";resetBG(); c<<"      /\\        ______    \\    ";setBG(WHITE); c<<"              ";resetBG(); c<<"             "<< char(186) << endl;
	c << char(186)<<"          ";setBG(WHITE); c<<"    ";resetBG(); c<<"    //_\\       \\    /\\    \\";setBG(BLUE); c<<"  ";resetBG();setBG(WHITE); c<<" ";resetBG();  setBG(BLUE); c<<" ";resetBG();setBG(WHITE); c<<" ";resetBG(); setBG(BLUE); c<<"   ";resetBG();setBG(WHITE); c<<"  ";resetBG(); setBG(BLUE); c<<"        ";resetBG();c<<"            "<< char(186) << endl;
	c << char(186)<<"   ";setBG(WHITE); c<<"  ";resetBG(); c<<"    ";setBG(WHITE); c<<" ";resetBG(); c<<"";setBG(WHITE); c<<" ";resetBG(); setBG(BLUE); c<<"    ";resetBG();c<<"  //___\\       \\__/  \\    \\"; setBG(BLUE); c<<"                  ";resetBG();c<<"           "<< char(186) << endl;
	c << char(186)<<"  ";setBG(WHITE); c<<"    ";resetBG(); c<<"   ";setBG(WHITE); c<<" ";resetBG(); setBG(BLUE); c<<"      ";resetBG();c<<"//_____\\       \\ |[]|     \\";setBG(BLUE); c<<"                  ";resetBG();c<<"          "<<char(186) << endl;
	c << char(186)<<" ";setBG(BLUE); c<<" ";resetBG();setBG(WHITE); c<<" ";resetBG();setBG(BLUE); c<<" ";resetBG();setBG(WHITE); c<<" ";resetBG(); setBG(BLUE); c<<"  ";resetBG();c<<" "; setBG(BLUE); c<<"       ";resetBG();c<<"//_______\\       \\|__|      \\                           "<< char(186) << endl;
	c << char(186)<<"";setBG(BLUE); c<<"              ";resetBG(); c<<"/XXXXXXXXXX\\                  \\                          "<< char(186) << endl;
	c << char(186)<<"";setBG(BLUE); c<<"          ";resetBG(); c<<"   /_I_II  I__I_\\__________________\\                         "<< char(186) << endl;
	c << char(186)<<"               I_I|  I__I_____[]_|_[]_____I                            "<< char(186) << endl;
	c << char(186)<<"               I_II  I__I_____[]_|_[]_____I                            "<< char(186) << endl;
	c << char(186)<<"               I II__I  I     XXXXXXX     I                            "<< char(186) << endl;
	c << char(186)<<"              ";setBG(LGREEN); c<<"    ";resetBG();c<<"    ";setBG(LGREEN); c<<"                     ";resetBG();c<<"                            "<< char(186) << endl; 
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(204)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                             >>>New Game<<<                            "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(186)<<"                             >>>Load Game<<<                           "<< char(186) << endl;
	c << char(186)<<"                                                                       "<< char(186) << endl;
	c << char(200)<< char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
}