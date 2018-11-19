#ifndef H_POINT
#define H_POINT
#include "point.h"
#endif
#ifndef H_OBJ
#define H_OBJ
#include "obj.h"
#endif
#ifndef H_GLUT
#define H_GLUT
#include <glut.h>
#endif
#ifndef H_MOVEOBJ
#define H_MOVEOBJ
#include "moveObj.h"
#endif
#ifndef H_WINDOWS
#define H_WINDOWS					
#include <Windows.h>
#endif
#ifndef H_BODY
#define H_BODY
#include "body.h"
#endif
#ifndef H_RECT
#define H_RECT
#include "rectangle.h"
#endif

// defines
#define FRAME_DELAY 16
#define ms / FRAME_DELAY
// -------

extern obj WINDOW;
extern moveObj player;
extern rectangle test;


extern void game(){

	glClear(GL_COLOR_BUFFER_BIT);
	WINDOW.nextTact();

	glPointSize(1);
	glColor3f(1,0,0);
	

	glutSwapBuffers();
	glutPostRedisplay();
	
	Sleep(FRAME_DELAY);

}