#ifndef H_VECTOR
#define H_VECTOR
#include <vector>
#endif
#ifndef H_POINT
#define H_POINT
#include "point.h"
#endif

#define ANGLE_RAD 0.0174533
#define ANGLE_ERROR 0.1
#define FIG vector<point>

using namespace std;

class body
{
public:

	vector<FIG> parts;
	vector<float*> partCol;

	void addRect(point p1, point p2, float color[3]);

	void addCircle(point center, float radius, int vertexNum, float color[3]);

	void exportParts(body* exBody, point offset);

	void draw(point center, float rotation, float s /*scale*/);

	body(void);
	~body(void);
};

