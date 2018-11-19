#ifndef H_MATH
#define H_MATH
#include <math.h>
#endif

#define PI 3.1415

class point
{

public:

	friend class line;

	float x, y;

	point(void);

	point(float x, float y);

	point operator+(point b);

	point operator-(point b);

	point operator*(float s);

	point rotate(point center, float angle);

	~point(void);

};

