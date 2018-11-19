#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif
#ifndef H_RECT
#define H_RECT
#include "rectangle.h"
#endif

class destrObj :public obj
{

	rectangle pathBlocker;

public:
	destrObj(void);
	~destrObj(void);
};

