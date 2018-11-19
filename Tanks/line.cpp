#ifndef H_LINE
#define H_LINE
#include "line.h"
#endif


line::line(void)
{
}

line::line(point p1, point p2){

	rotOffset = atan((p2.y - p1.y)/(p2.x - p1.x));
	offset.x = p1.x;
	offset.y = p1.y;

}

bool line::compare(point cmpPoint){


	point eqPoint ((cmpPoint.y - pos.y)/tan(rotation) + pos.x,tan(rotation) * (cmpPoint.x - pos.x) + pos.y); //y точки, находящейся на линии, равной с данной по x 

	
	/*if (eqPoint.y < cmpPoint.y) return CMP_UP;
	else if (eqPoint.y > cmpPoint.y) return CMP_DOWN;*/
	if (eqPoint.x < cmpPoint.x) return CMP_UP;
	else if(eqPoint.x > cmpPoint.x) return CMP_DOWN;

}




line::~line(void)
{
}
