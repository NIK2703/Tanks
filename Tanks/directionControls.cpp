#ifndef H_DIRCTRLS
#define H_DIRCTRLS
#include "directionControls.h"
#endif
#ifndef H_STDIO
#define H_STDIO
#include <stdio.h>
#endif


extern point nullPoint;
extern point mouse;

dirMap moveControl(){
	dirMap keys;

	keys.right	=	GetAsyncKeyState(VK_RIGHT);
	keys.up		=	GetAsyncKeyState(VK_UP);
	keys.left	=	GetAsyncKeyState(VK_LEFT);
	keys.down	=	GetAsyncKeyState(VK_DOWN);

	return keys;
}

float dirCtrlKeboardArrows(obj* callObj){
	dirMap arrows = moveControl();
	char horizontal = 0 + arrows.right - arrows.left;
	char vertical = 0 + arrows.up - arrows.down; 

	switch(horizontal){
	case DIR_RIGHT:
		switch (vertical) {
		case DIR_UP: return PI/4; break;
		case DIR_NO_MOVE: return 0; break;
		case DIR_DOWN: return 7*PI/4; break;
		}	break;
	case DIR_NO_MOVE:
		switch (vertical) {
		case DIR_UP: return PI/2; break;
		case DIR_NO_MOVE: return -10; break;
		case DIR_DOWN: return 3*PI/2; break;
		}	break;
	case DIR_LEFT:
		switch (vertical) {
		case DIR_UP: return 3*PI/4; break;
		case DIR_NO_MOVE: return PI; break;
		case DIR_DOWN: return 5*PI/4; break;
		}	break;
	}


}

float lineLen(point p1, point p2){

	return sqrt(pow(p1.x + p2.x, 2) + pow(p1.y + p2.y, 2));

}

float dirCtrlMousePointer(obj* callObj){

	float tg = (mouse.y - callObj -> pos.y)/(mouse.x - callObj -> pos.x);
	float outVal = (mouse.x  >= callObj -> pos.x) ? (atan(tg) - callObj -> parent -> rotation) : PI + atan(tg) - callObj -> parent -> rotation ;
	return outVal;

}