#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include"Point.h"

class Rectangle :public Point {
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint();
		this->w = w;
		this->h = h;
	}
	float getW() { return w; }
	float getH() { return h; }
private:
	float w, h;
};

#endif