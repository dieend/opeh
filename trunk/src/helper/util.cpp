#include "util.h"

Utilities* Utilities::utilities = NULL;

Utilities::Utilities(){
}

Utilities& Utilities::getInstances(){
	if (Utilities::utilities == NULL) {
		Utilities::utilities = new Utilities();
	}

	return *(Utilities::utilities);
}

void Utilities::setBackground(int B){
	color &= 0x0F;
	B <<= 4;
	color |= B;
	draw();
}
void Utilities::setForeground(int B){
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