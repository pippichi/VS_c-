#ifndef __RECTANGLE_H_
#define __RECTANGLE
#include"Point.h"
#include<iostream>

class Rectangle :private Point {
public:
	void move(float offx, float offy) { Point::move(offx, offy); }
	void initRectangle(float x, float y, float w, float h) {
		initPoint();
		this->w = w;
		this->h = h;
	}
	float getX() { return Point::getX(); }
	float getY() { return Point::getY(); }
	float getW() { return w; }
	float getH() { return h; }
private:
	float w, h;
};

#endif