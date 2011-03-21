#ifndef _POINT_H
#define _POINT_H

#include <iostream>
using namespace std;

class Point {
	public :
	//ctor
	Point();
	Point(int,int);
	
	//cctor
	Point(const Point &);
	
	//dtor
	~Point();
	
	//operator=
	Point& operator= (const Point &);
	
	//metode get dan set
	int getX();
	void setX(int);
	int getY();
	void setY(int);
	
	//metode perbandingan
	bool operator< (Point);
	
	bool operator> (Point);

	bool operator== (Point);
	
	void setLeft();
	void setUp();
	void setRight();
	void setDown();
	Point getLeft();
	Point getUp();
	Point getRight();
	Point getDown();
	bool isAround(int,int);//mengembalikan true jika Point berada di sekitar(R,D,L,U) int,int
        friend ostream& operator<<(ostream&,Point*);
        friend ostream& operator<<(ostream&,Point&);
	private:
	int x;
	int y;
};

#endif
