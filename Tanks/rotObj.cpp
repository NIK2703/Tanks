#ifndef H_ROTOBJ
#define H_ROTOBJ
#include "rotObj.h"
#endif

rotObj::rotObj(){

}

rotObj::rotObj(point POS, float ANGLE, float ROTSPEED, float DIRECTION): obj(POS, ANGLE)
{

	

}



void rotObj::nextTact(){

	refreshPos();

	if (rotating||autoRotate) rotate();

	objBody.draw(pos,rotation,1);

	int childNum = childList.size();
	for(int i = 0; i < childNum; i++)
		childList[i] -> nextTact();

	

}

void rotObj::toogleAutoRotate(short param){

	if(param == 2){

		if(autoRotate) autoRotate = 0;
		else autoRotate = 1;

	} else
		autoRotate = param;

}

rotObj::~rotObj(void)
{
}
