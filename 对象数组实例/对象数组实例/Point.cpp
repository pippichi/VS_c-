#include"stdafx.h"
#include<iostream>
#include"Point.h"
using namespace std;

Point::Point(int x, int y) : x(x), y(y) {
	cout << "Consructor called" << endl;
}
Point::Point() : x(0), y(0) {
	cout << "Default constructor called" << endl;
}
Point::~Point() {
	cout << "Destructor called" << endl;
}
void Point::move(int NewX, int NewY) {
	cout << "Moving the point to (" << NewX << ',' << NewY << ") " << endl;
	x = NewX;
	y = NewY;
}