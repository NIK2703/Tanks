#ifndef H_POINT
#define H_POINT
#include "point.h"
#endif

point::point(void)
{

	x = 0;
	y = 0;

}

point::point(float X, float Y){

	x = X;
	y = Y;

}

point point::operator+(point b){

	point c;
	c.x = x + b.x;
	c.y = y + b.y;
	return c;

}

point point::operator-(point b){

	point c;
	c.x = x - b.x;
	c.y = y - b.y;
	return c;

}


point point::operator*(float s){

	point b;
	b.x = x * s;
	b.y = y * s;
	return b;

}

point point::rotate(point center, float angle){

	point newPoint;
	newPoint.x = (x - center.x) * cos(angle) - (y - center.y) * sin(angle) + center.x;
	newPoint.y = (x - center.x) * sin(angle) + (y - center.y) * cos(angle) + center.y;

	return newPoint;

}

point::~point(void)
{

	/*delete x;
	delete y;*/

}

