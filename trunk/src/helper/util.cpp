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
void Utilities::setForeground(int F){
	color &= 0xF0;
	color|=F;
	draw();
}
void Utilities::setColor(int B,int F){
    Utilities::setBackground(B);
    Utilities::setForeground(F);
}

void Utilities::resetColor(){
	color =0x07;
	draw();
}
void Utilities::draw(){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, color);
}

void Utilities::destroy() {
    if (Utilities::utilities != NULL) delete Utilities::utilities;
}
