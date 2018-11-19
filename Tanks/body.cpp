#ifndef H_BODY
#define H_BODY
#include "body.h"
#endif
#ifndef H_GLUT
#define H_GLUT
#include <glut.h>
#endif

body::body(void)
{

}

void body::addRect(point p1, point p2, float color[3]){

	FIG newfig;

	point p3(p1.x,p2.y);
	point p4(p2.x,p1.y);

	newfig.push_back(p1);
	newfig.push_back(p3);
	newfig.push_back(p2);
	newfig.push_back(p4);
	
	

	parts.push_back(newfig);
	partCol.push_back(color);

}

void body::addCircle(point center, float radius, int vertexNum, float color[3]){
	float steep = 360/vertexNum;
	FIG newfig;
	double angle = 0 ;

	for(int i = 0; i <= vertexNum ; i++, angle += steep){

		point newVertex(
			center.x+radius*cos(angle*ANGLE_RAD),
			center.y+radius*sin(angle*ANGLE_RAD)
			);

		newfig.push_back(newVertex);

	}

	partCol.push_back(color);
	parts.push_back(newfig);

}

void body::exportParts(body* exBody, point offset){
	
	int exPartNum = exBody -> parts.size();
	
	for(int i = 0; i < exPartNum; i++){

		FIG newfig;
		int vertexNum = exBody -> parts[i].size();

		for(int j = 0; j < vertexNum; j++)
			newfig.push_back(parts[i][j] + offset);

		parts.push_back(newfig);
		partCol.push_back(exBody -> partCol[i]);
	};

};

void body::draw(point center, float rotation, float s /*scale*/){

	int partsNum = parts.size();

	for(int i = 0; i < partsNum ; i++){

		int fignum = parts[i].size();
		glColor3f(partCol[i][0],partCol[i][1],partCol[i][2]);

		glBegin(GL_POLYGON);
		for(int j = 0; j < fignum ; j++){

			point outp = (center + parts[i][j]*s).rotate(center,rotation);
			glVertex2d(outp.x, outp.y);

		}
		glEnd();

	}

}

body::~body(void)
{
}
