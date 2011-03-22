#include "point.h"

int main () {
	Point P1, P3;
	Point P2 (3,4);
	int x,y;
	
	cout << "Masukkan nilai x = ";
	cin >> x;
	cout << "Masukkan nilai y = ";
	cin >> y;
	
	P1.setX(x);
	P1.setY(y);
	
	P3 = P1;
	
	cout << "Apakah P1 > P2? ";
	if (P3 > P2) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	
	return 0;
}