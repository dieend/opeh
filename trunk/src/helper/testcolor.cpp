#include <iostream>
#include "util.h"
using namespace std;
int main()
{
	Utilities::getInstances().setBackground(BLACK); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "BLACK" << endl;
	Utilities::getInstances().setBackground(BLUE); cout << "   " ;
	Utilities::getInstances().resetColor();			cout << "BLUE" << endl;
	Utilities::getInstances().setBackground(GREEN);	cout << "   ";
	Utilities::getInstances().resetColor();			cout << "GREEN" << endl;
	Utilities::getInstances().setBackground(AQUA); cout << "   " ;
	Utilities::getInstances().resetColor();			cout << "AQUA" << endl;
	Utilities::getInstances().setBackground(RED); cout << "   " ;
	Utilities::getInstances().resetColor();			cout << "RED" << endl;
	Utilities::getInstances().setBackground(PURPLE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "PURPLE" << endl;
	Utilities::getInstances().setBackground(YELLOW); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "YELLOW" << endl;
	Utilities::getInstances().setBackground(WHITE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "WHITE" << endl;	
	Utilities::getInstances().setBackground(GRAY); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "GRAY" << endl;	
	Utilities::getInstances().setBackground(LBLUE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LBLUE" << endl;	
	Utilities::getInstances().setBackground(LGREEN); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LGREEN" << endl;
	Utilities::getInstances().setBackground(LAQUA); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LAQUA" << endl;	
	Utilities::getInstances().setBackground(LRED); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LRED" << endl;	
	Utilities::getInstances().setBackground(LPURPLE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LPURPLE" << endl;
	Utilities::getInstances().setBackground(LYELLOW); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LYELLOW" << endl;	
	Utilities::getInstances().setBackground(LWHITE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LWHITE" << endl;	
	Utilities::getInstances().destroy();
}
