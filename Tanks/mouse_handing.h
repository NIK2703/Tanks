#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif

#ifndef H_GLUT
#define H_GLUT
#include <glut.h>
#endif

#ifndef H_POINT
#define H_POINT
#include "point.h"
#endif

extern point mouse;
extern float tilesInHeight;
extern int windowWidth;
extern int windowHight;
extern float aspect;

extern void mouseCoord(int x, int y);