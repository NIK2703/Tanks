#ifndef H_VECTOR
#define H_VECTOR
#include <vector>
#endif

#ifndef H_GLUT
#define H_GLUT
#include <glut.h>
#endif

#ifndef H_POINT
#define H_POINT
#include "point.h"
#endif

#ifndef H_BODY
#define H_BODY
#include "body.h"
#endif


using namespace std;
extern point nullPoint;


class obj
{
protected:
	obj* parent;
	vector<obj*> childList;

	point pos;
	point offset;
	float rotation;
	float rotOffset;

public:

	friend float dirCtrlMousePointer(obj* callObj);

	body objBody;

	obj(void);

	obj(point POS, float ANGLE);

	void setOffset(point newOffset);

	void refreshPos();

	void addChild(obj* newChild);

	virtual void nextTact();

	void setPos(point newPos);

	point getPos();

	~obj(void);

};

