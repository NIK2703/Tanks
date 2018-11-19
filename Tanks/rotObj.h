#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif

class rotObj :public obj
{
protected:

	

public:

	

	virtual void nextTact();

	rotObj(point POS, float ANGLE, float ROTSPEED, float DIRECTION);

	rotObj();

	

	~rotObj(void);
};

