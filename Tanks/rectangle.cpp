#ifndef H_RECT
#define H_RECT
#include "rectangle.h"
#endif

float pointsAngle(point p1, point p2){

	float arctg = atan((p1.y - p2.y)/(p1.x - p2.x));
	float outVal = (p1.x  >= p2.x) ? arctg : PI + arctg;

	return outVal;

}

rectangle::rectangle(void)
{
}

rectangle::rectangle(point CENTER, float width, float height){

	rotOffset = 0;
	offset = CENTER;

	point p1(width/2, -height/2);
	point p2(width/2, height/2);
	point p3(-width/2, height/2);
	point p4(-width/2, -height/2);

	line right(p1,p2);
	line up(p2,p3);
	line left(p3,p4);
	line down(p4,p1);

	formSide[0] = right;
	formSide[1] = up;
	formSide[2] = left;
	formSide[3] = down;

	this -> addChild(&formSide[0]);
	this -> addChild(&formSide[1]);
	this -> addChild(&formSide[2]);
	this -> addChild(&formSide[3]);


}


bool rectangle::inRect (point p1){

	bool in;
	short pair1 = 0, pair2 = 0;

	for(int i=0; i<4; i++){

		
		if(formSide[i].compare(p1)) if(i % 2 == 0) pair1 ++; else pair2 ++;
		else if(i % 2 == 0) pair1 --; else pair2 --;

	}

	if ((pair1 ==0) && (pair2 == 0)) return true;
	else return false;

}

float rectangle::checkConflict(rectangle rect2){

	for (int i = 0; i < 4; i++)
		if (inRect(rect2.formSide[i].pos)) {

			float angle = pointsAngle(pos, rect2.formSide[i].pos);

			float RDangle = pointsAngle(pos, formSide[0].pos);
			float RUangle = pointsAngle(pos, formSide[1].pos);
			float LUangle = pointsAngle(pos, formSide[2].pos);
			float LDangle = pointsAngle(pos, formSide[3].pos);

			if( angle > RDangle && angle < RUangle) return 0 + rotation;
			if( angle > RUangle && angle < LUangle) return PI/2 + rotation;
			if( angle > LUangle && angle < LDangle) return PI + rotation;
			if( angle > LDangle && angle < RDangle) return 3*PI/2 + rotation;

			return -10;

		}

}

rectangle::~rectangle(void)
{
}
