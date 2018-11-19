#ifndef H_MOVEOBJ
#define H_MOVEOBJ
#include "moveObj.h"
#endif

moveObj::moveObj()
{
}

moveObj::moveObj(point POS, float ANGLE,float ROTSPEED, float DIRECTION, float SPEED):  obj(POS,ANGLE){

	rotSpeed = ROTSPEED;
	direction = DIRECTION;
	speed = SPEED;
	smoothRotating = 1;

}

void moveObj::setDirControlFunc(float (*dirCtrlFunc) (obj* callObj)){

	dirControlFunc = dirCtrlFunc;

}

void moveObj::refreshDir(){

	if(dirControlFunc)
		direction = dirControlFunc(this);
		

	if (direction < - 2 * PI) {
		rotating = false;
		moving = false;
	}
	else {
		rotating = true;

		if(speed > 0)
		moving = true;
			else moving = false;
	}

}

void moveObj::rotate(){

	if (rotOffset - direction > PI) rotOffset -= 2 * PI;
	else if (direction - rotOffset > PI) rotOffset += 2 * PI;

	if (rotOffset < direction - rotSpeed * (smoothRotating ? 2 : 1)) rotOffset += rotSpeed;
	else if (rotOffset > direction + rotSpeed * (smoothRotating ? 2 : 1)) rotOffset -= rotSpeed;
	else rotOffset -= smoothRotating ? (rotOffset - direction)/2 : (rotOffset - direction); 
	
}

void moveObj::move(){

		offset.x += speed * cos(rotOffset);
		offset.y += speed * sin(rotOffset);

}

void moveObj::nextTact(){

	refreshDir();
	if (rotating) rotate();
	if (moving) move();

	refreshPos();

	objBody.draw(pos,rotation,1);

	int childNum = childList.size();
	for(int i = 0; i < childNum; i++)
		childList[i] -> nextTact();

	

}

void moveObj::toogleSmoothRotating(short param){

	if(param == 2){

		if(smoothRotating) smoothRotating = 0;
		else smoothRotating = 1;

	} else
		smoothRotating = param;

}

moveObj::~moveObj(void)
{
}
