#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif

#define ANGLE_RAD 0.0174533

class moveObj : virtual public obj
{
protected:

	bool moving;
	float speed;

	bool rotating;
	bool smoothRotating;
	float direction, rotSpeed;

	float (*dirControlFunc) (obj* callObj);

	

public:

	

	moveObj(void);

	moveObj(point POS, float ANGLE,float ROTSPEED, float DIRECTION, float SPEED);

	void setDirControlFunc(float (*dirCtrlFunc) (obj* callObj));

	void refreshDir();

	void rotate();

	void move();

	virtual void nextTact();

	void toogleSmoothRotating(short param = 2);

	~moveObj(void);
};

