#ifndef H_PATHBLCKR
#define H_PATHBLCKR
#include "pathBlocker.h"
#endif

class destroyable :
	public pathBlocker
{
public:
	destroyable(void);
	~destroyable(void);
};

