#ifndef __POINT_H_
#define __POINT_H_

class Point {
public:
	float getX() const { return x; }
	float getY() const { return y; }
	void move(float offX, float offY) { x += offX; y += offY; }
	void initPoint(float x = 0, float y = 0) { this->x = x; this->y = y; }

private:
	float x, y;
};

#endif