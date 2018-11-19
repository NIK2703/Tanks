#ifndef H_PATHBLCKR
#define H_PATHBLCKR
#include "pathBlocker.h"
#endif

float len(point p1, point p2){

	return sqrt(pow(p2.x-p1.x , 2) + pow(p2.y - p1.y, 2));

}

pathBlocker::pathBlocker(void)
{

	/*pbListNum = pbList.size();
	pbList.push_back(this);*/

}

pathBlocker::pathBlocker(float areaWidth, float areaHeight, unsigned short PBCLASS){

	rectangle rect(nullPoint,areaWidth, areaHeight);
	pbClass = PBCLASS;
	scanAreaRad = sqrt(pow(areaWidth/2, 2) + pow(areaHeight/2, 2));

}

float pathBlocker::checkConflict(pathBlocker pb2){

	if (len(pos, pb2.pos) < scanAreaRad + pb2.scanAreaRad)
		 return interArea.checkConflict(pb2.interArea);

	return -10;

}


pathBlocker::~pathBlocker(void)
{
}
