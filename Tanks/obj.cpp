#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif



obj::obj(void)
{

	pos = nullPoint;
	offset = nullPoint;
	rotation = 0;
	rotOffset = 0;

}

obj::obj(point POS, float ANGLE){

	offset = POS;
	rotation = ANGLE;

}

void obj::setOffset(point newOffset){

	offset = newOffset;

}

void obj:: refreshPos(){

	if(parent){
		pos = (parent -> pos + offset).rotate(parent -> pos,parent -> rotation);
		rotation = parent -> rotation + rotOffset;
	}

}

void obj::addChild(obj* newChild){

	childList.push_back(newChild);
	newChild -> parent = this;

}



void obj::nextTact(){

	refreshPos();

	objBody.draw(pos,rotation,1);

	int childNum = childList.size();
	for(int i = 0; i < childNum; i++)
		childList[i] -> nextTact();

}

void obj::setPos(point newPos){

	pos = newPos;

}

point obj::getPos(){

	return pos;

}

obj::~obj(void)
{
}
