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
#ifndef H_BODY
#define H_BODY
#include "body.h"
#endif
#ifndef H_BODY_PRESETS
#define H_BODY_PRESETS
#include "body_presets.h"
#endif
#ifndef H_MOUSE
#define H_MOUSE
#include "mouse_handing.h"
#endif
#ifndef H_DIRCTRLS
#define H_DIRCTRLS
#include "directionControls.h"
#endif
#ifndef H_RECT
#define H_RECT
#include "rectangle.h"
#endif




// defines
#define WIN_X_OFFSET 100
#define WIN_Y_OFFSET 100
#define WIN_NAME "Tanks"


float tilesInHeight = 12;

// global vars
int windowWidth = 960;
int windowHight = 480;
float aspect = (float)windowWidth / windowHight;
point mouse(1,1);

float colors[][3] = {{0,0,0},{1,1,1},{0.25,1,0.5},{0.70,0.70,0.70},{0.25,0.9,0.5}};
point nullPoint(0,0);
point one(1,1);

obj WINDOW(nullPoint,0);
obj MAP(nullPoint,0);

moveObj player(one,0,0.15,0,0.15);
obj track1(nullPoint,0);
obj track2(nullPoint,0);
moveObj tower(nullPoint,0,PI/4,0,-1);

rectangle test(nullPoint,2,2);

// func prototypes
void mainMenuInit();
void mainMenu();
void gameInit();
void game();
void mouseCoord(int x, int y);
void windowResizeFunc(int width, int height);

// CODE
void main(int argc, char **argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

	glutInitWindowSize(windowWidth,windowHight);
	glutInitWindowPosition(WIN_X_OFFSET,WIN_Y_OFFSET);
	glutCreateWindow(WIN_NAME);
	glutReshapeFunc(windowResizeFunc);

	mainMenuInit();

	glutMainLoop();

}

void mouseCoord(int x, int y){

	mouse.x = (((float) x / windowWidth) * tilesInHeight - tilesInHeight/2) * aspect;
	mouse.y = -(((float) y / windowHight) * tilesInHeight - tilesInHeight/2);

}

void windowResizeFunc(int width, int height){

	windowWidth = width;
	windowHight = height;
	aspect = (float)windowWidth / windowHight;

	printf("%f\n\n",aspect);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluOrtho2D(-aspect*tilesInHeight/2.0,aspect*tilesInHeight/2.0,-tilesInHeight/2,tilesInHeight/2);
	glMatrixMode(GL_MODELVIEW);

}



void mainMenuInit(){

	/*glutDisplayFunc(mainMenu);*/

	gameInit();
	
	/*glClearColor(1,1,1,0);
	glColor3f(0,0,0);
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-24,24,-24,24);
	glMatrixMode(GL_MODELVIEW);*/

}

void gameInit(){

	glClearColor(1,1,1,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-aspect*tilesInHeight/2.0,aspect*tilesInHeight/2.0,-tilesInHeight/2,tilesInHeight/2);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(game);
	glutPassiveMotionFunc(mouseCoord);
	WINDOW.addChild(&MAP);
	
	MAP.addChild(&player);
	
	point p3(0,0), p4(2,0.4);

	////////////
	player.setDirControlFunc(dirCtrlKeboardArrows);
	tower.setDirControlFunc(dirCtrlMousePointer);
	tower.toogleSmoothRotating();

	point p50(1.05,0);
	point p5(1.0,0.3);
	bdRoundRect(&tower.objBody,nullPoint,p5,0.15,colors[4],p50);
	tower.objBody.addCircle(nullPoint,0.7,20,colors[4]);
	
	point track1Offset(0,0.85);
	point track2Offset(0,-0.85);
	
	track1.setOffset(track1Offset);
	bdRoundRect(&track1.objBody,p3,p4,0.2,colors[3]);
	player.addChild(&track1);

	track2.setOffset(track2Offset);
	bdRoundRect(&track2.objBody,p3,p4,0.2,colors[3]);
	player.addChild(&track2);

	player.addChild(&tower);
	player.addChild(&test);


	point p1(0,0), p2(2,1.4);

	bdRoundRect(&player.objBody,p1,p2,0.2,colors[2]);
	///////////


}

