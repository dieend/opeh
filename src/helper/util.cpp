#include "util.h"

Utilities::Utilities(){
}

Utilities* Utilities::getInstances(){
	if (utilities == NULL) {
		utilities = new Utilites();
	} else {
		return utilites;
	}
}

void Utilities::setBackground(int B){
	color &= 0x0F;
	B <<= 4;
	color |= B;
	draw();
}
void Utilities::setForeground(int);{
	color &= 0xF0;
	color|=B;
	draw();
}
void Utilities::resetColor(){
	color =0x07;
	draw();
}
void Utilities::draw(){
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, color);
}