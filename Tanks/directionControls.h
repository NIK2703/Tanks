#ifndef H_WINDOWS
#define H_WINDOWS					
#include <Windows.h>
#endif
#ifndef H_MOVEOBJ
#define H_MOVEOBJ
#include "moveobj.h"
#endif

#define DIR_RIGHT		 1
#define DIR_UP			 1
#define DIR_LEFT		-1
#define DIR_DOWN		-1
#define DIR_NO_MOVE		 0

float lineLen(point p1, point p2);

struct dirMap{
	bool right;
	bool up;
	bool left;
	bool down;
};

dirMap moveControl();

float dirCtrlKeboardArrows(obj* callObj);

float dirCtrlMousePointer(obj* callObj);