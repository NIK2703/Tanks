#ifndef H_POINT
#define H_POINT
#include "point.h"
#endif

#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif

#define CMP_UP true
#define CMP_DOWN false

class line :public obj
{

public:
	friend class rectangle;

	line(void);
	line(point p1, point p2);

	bool compare(point cmpPoint);

	~line(void);
};

