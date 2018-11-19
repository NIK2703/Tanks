#ifndef H_BODY_PRESETS
#define H_BODY_PRESETS
#include "body_presets.h"
#endif


void bdRoundRect(body* B, point p1, point p2, float roundRadius, float color[3],point offset){

	point center = (p1 + p2) * 0.5;
	float halfWidth = (p1.x < p2.x) ? (p2.x - p1.x)/2 : (p1.x - p2.x)/2;
	float halfHeight = (p1.y < p2.y) ? (p2.y - p1.y)/2 : (p1.y - p2.y)/2;

	point pt1(-halfWidth,- halfHeight + roundRadius ), pt2(halfWidth,halfHeight - roundRadius), pt3(-halfWidth + roundRadius ,-halfHeight), pt4(halfWidth - roundRadius, halfHeight);
	point pt5(-halfWidth + roundRadius,-halfHeight + roundRadius), pt6(-halfWidth + roundRadius, halfHeight - roundRadius);
	point pt7(halfWidth - roundRadius,halfHeight - roundRadius), pt8(halfWidth - roundRadius,-halfHeight + roundRadius);

	B -> addRect(pt1 + offset,pt2 + offset,color);
	B -> addRect(pt3 + offset,pt4 + offset,color);
	B -> addCircle(pt5 + offset,roundRadius,15,color);
	B -> addCircle(pt6 + offset,roundRadius,15,color);
	B -> addCircle(pt7 + offset,roundRadius,15,color);
	B -> addCircle(pt8 + offset,roundRadius,15,color);

}