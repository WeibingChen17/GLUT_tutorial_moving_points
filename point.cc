#include <random>
#include "GL/freeglut.h"
#include "GL/gl.h"

double range = 1.0;
const size_t n_points = 100;

std::default_random_engine gen;
std::uniform_real_distribution<float> color(0.0, 1.0);
std::uniform_real_distribution<float> xyz(-range, range);

float x[n_points], y[n_points], z[n_points], cr[n_points], cg[n_points], cb[n_points];

void drawPoints(){
	glClearColor(0.4, 0.4, 0.4, 0.4);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-range, range, -range, range, -range, range);

	glPointSize(2.0f);
	glBegin(GL_POINTS);
	for (size_t i = 0; i < n_points; ++i){
		glColor3f(cr[i], cg[i], cb[i]);
		glVertex3f(x[i], y[i], z[i]);
	}
	glEnd();
	
	glFlush();
}

int main(int argc, char **argv){
	for (size_t i = 0; i < n_points; ++i){
		x[i] = xyz(gen);
		y[i] = xyz(gen);
		z[i] = 0.0;
		cr[i] = color(gen);
		cg[i] = color(gen);
		cb[i] = color(gen);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OPENGL - Points");
	glutDisplayFunc(drawPoints);
	glutMainLoop();
	return 0;
}

