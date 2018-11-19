#ifndef H_POINT
#define H_POINT
#include "point.h"
#endif

#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif

#ifndef H_LINE
#define H_LINE
#include "line.h"
#endif

float pointsAngle(point p1, point p2);

class rectangle:public obj
{
	

public:

	line formSide[4];

	rectangle(void);
	rectangle(point CENTER, float width, float height);

	float checkConflict(rectangle rect2);

	bool inRect (point p1);

	~rectangle(void);
};

