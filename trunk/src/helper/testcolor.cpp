#include <iostream>
#include "utility.h"
using namespace std;
int main()
{
	Utilities::getInstances().setBG(BLACK); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "BLACK" << endl;
	Utilities::getInstances().setBG(BLUE); cout << "   " ;
	Utilities::getInstances().resetColor();			cout << "BLUE" << endl;
	Utilities::getInstances().setBG(GREEN);	cout << "   ";
	Utilities::getInstances().resetColor();			cout << "GREEN" << endl;
	Utilities::getInstances().setBG(AQUA); cout << "   " ;
	Utilities::getInstances().resetColor();			cout << "AQUA" << endl;
	Utilities::getInstances().setBG(RED); cout << "   " ;
	Utilities::getInstances().resetColor();			cout << "RED" << endl;
	Utilities::getInstances().setBG(PURPLE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "PURPLE" << endl;
	Utilities::getInstances().setBG(YELLOW); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "YELLOW" << endl;
	Utilities::getInstances().setBG(WHITE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "WHITE" << endl;	
	Utilities::getInstances().setBG(GRAY); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "GRAY" << endl;	
	Utilities::getInstances().setBG(LBLUE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LBLUE" << endl;	
	Utilities::getInstances().setBG(LGREEN); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LGREEN" << endl;
	Utilities::getInstances().setBG(LAQUA); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LAQUA" << endl;	
	Utilities::getInstances().setBG(LRED); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LRED" << endl;	
	Utilities::getInstances().setBG(LPURPLE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LPURPLE" << endl;
	Utilities::getInstances().setBG(LYELLOW); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LYELLOW" << endl;	
	Utilities::getInstances().setBG(LWHITE); cout << "   ";
	Utilities::getInstances().resetColor();			cout << "LWHITE" << endl;	
	Utilities::getInstances().destroy();
}
