#include "GL/freeglut.h"
#include "GL/gl.h"

void drawTriagnle(){
	glClearColor(0.4, 0.4, 0.4, 0.4); //set the background 
	glClear(GL_COLOR_BUFFER_BIT);//clear the screen

	glColor3f(1.0, 1.0, 1.0); //set teh color of triangle
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);// set the view mode

	glBegin(GL_TRIANGLES); // begin the plotting of triangles by vertices. Multiple triangles could be plotted. Every three points are treated as a triangle.
	glVertex3f(-0.7, 0.7, 0);
	glVertex3f(0.7, 0.7, 0);
	glVertex3f(0, -1, 0);
	glEnd();//end the plotting
	
	glFlush();//flush the buffer
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);//use single buffer
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OPENGL - Triangle");
	glutDisplayFunc(drawTriagnle);//register the display function
	glutMainLoop();//main loop
	return 0;
}

