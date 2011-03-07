#include "point.h"

//ctor
Point::Point() {
}

Point::Point(int NewX,int NewY) {
	x = NewX;
	y = NewY;
}

//cctor
Point::Point(const Point & P) {
	x = P.x;
	y = P.y;
}

//dtor
Point::~Point() {
}

//operator=
Point& Point::operator= (const Point & P) {
	x = P.x;
	y = P.y;
	
	return (*this);
}

//metode get dan set
int Point::getX() {
	return x;
}

void Point::setX(int newx) {
	x = newx;
}

int Point::getY() {
	return y;
}

void Point::setY(int newy) {
	y = newy;
}

//metode perbandingan
bool Point::operator< (Point P) {
	if ((x < P.getX()) && (y < P.getY())) {
		return true;
	} else {
		return false;
	}
}

bool Point::operator> (Point P) {
	if ((x > P.getX()) && (y > P.getY())) {
		return true;
	} else {
		return false;
	}
}

bool Point::operator== (Point P) {
	if ((x == P.getX()) && (y == P.getY())) {
		return true;
	} else {
		return false;
	}
}