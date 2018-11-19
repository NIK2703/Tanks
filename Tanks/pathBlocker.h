#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif

#ifndef H_RECT
#define H_RECT
#include "rectangle.h"
#endif

#define PB_STATIC	0
#define PB_MOVABLE	1
#define PB_SHELL	2

float len(point p1, point p2);


class pathBlocker :virtual public obj
{

	unsigned short pbClass;
	rectangle interArea;
	float scanAreaRad;

	
	int pbListNum;


public:



	pathBlocker(void);

	pathBlocker(float areaWidth, float areaHeight, unsigned short PBCLASS);

	float checkConflict(pathBlocker pb2);

	~pathBlocker(void);
};
//
//vector<pathBlocker*> pbList;
