#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>

// Rotate X and Y
double rX=0;
double rY=0;

// The coordinates for the vertices of the cube
double x = 0.5;
double y = 0.5;
double z = 0.5;

void drawCube()
{
    glClearColor(0.4, 0.4, 0.4, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    // Rotate when user changes rX and rY
    glLoadIdentity();
    glRotatef(rX, 1.0, 0.0, 0.0);
    glRotatef(rY, 0.0, 1.0, 0.0);

    // BACK
    glBegin(GL_TRIANGLES);
    glColor3f(0.4, 0.3, 0.5);
    glVertex3f(x, y, z);
    glVertex3f(x, -y, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, -y, z);
    glVertex3f(x, -y, z);
    glVertex3f(-x, y, z);
    glEnd();

    // FRONT
    glBegin(GL_TRIANGLES);
    glColor3f(0.1, 0.5, 0.3);
    glVertex3f(-x, y, -z);
    glVertex3f(0, 0, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(0, 0, -z);
    glVertex3f(x, -y, -z);
    glVertex3f(-x, y, -z);
    glVertex3f(x, y, -z);
    glVertex3f(0, 0, -z);
    glVertex3f(0, 0, -z);
    glVertex3f(x, y, -z);
    glVertex3f(x, -y, -z);
    glEnd();

    // LEFT
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.5, 0.6);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, -y, z);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, -y, z);
    glVertex3f(-x, y, -z);
    glEnd();

    // RIGHT
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(x, y, z);
    glVertex3f(x, y, -z);
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);
    glVertex3f(x, y, -z);
    glVertex3f(x, -y, z);
    glEnd();

    // TOP
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.0, 0.0);
    glVertex3f(x, y, z);
    glVertex3f(x, y, -z);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, -z);
    glEnd();

    // BOTTOM
    glBegin(GL_TRIANGLES);
    glColor3f(0.4, 0.0, 0.4);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, -y, z);
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(x, -y, z);
    glEnd();

    glFlush();
    glutSwapBuffers();//when double buffer is used, use swap
}

void keyboard(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            rY += 15;
            break;
        case GLUT_KEY_LEFT:
            rY -= 15;
            break;
        case GLUT_KEY_UP:
            rX += 15;
            break;
        case GLUT_KEY_DOWN:
            rX -= 15;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//use dowble buffer
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Cube");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(drawCube);
    glutSpecialFunc(keyboard);
    glutMainLoop();

    return 0;
}
