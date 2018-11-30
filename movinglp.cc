#include <random>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <cmath>

const size_t n_points = 100;
const float range = 1.0;
const float threshold = 0.3;
const float average_velocity = 0.0;
const float sigma_velocity = 0.2;
const float max_color = 1.0;
const float min_color = 0.0;
const float tau = 0.005;
const float boundeps = 0.01;

float x[n_points], y[n_points], z[n_points], 
      cr[n_points], cg[n_points], cb[n_points], 
      vx[n_points], vy[n_points], vz[n_points]; 

float distance(float x1, float y1, float z1, float x2, float y2, float z2){
    return std::sqrt(std::pow(x1-x2, 2) + std::pow(y1-y2, 2) + std::pow(z1-z2, 2)); 
}

void initialize(){
    std::default_random_engine gen(static_cast<long unsigned int>(time(0)));
    std::uniform_real_distribution<float> col(min_color, max_color);
    std::uniform_real_distribution<float> pos(-range, range);
    std::normal_distribution<float> vel(average_velocity, sigma_velocity);
    gen.seed();
    for (size_t i = 0; i < n_points; ++i){
        x[i] = pos(gen);
        y[i] = pos(gen);
        z[i] = 0.0;
        cr[i] = col(gen);
        cg[i] = col(gen);
        cb[i] = col(gen);
        vx[i] = vel(gen);
        vy[i] = vel(gen);
        vz[i] = 0.0;
    }
}

void forward(){
    for (size_t i = 0; i < n_points; ++i){
        x[i] += vx[i] * tau;
        y[i] += vy[i] * tau;
        z[i] += vz[i] * tau;
        if (std::fabs(x[i]) >= range - boundeps)
            vx[i] = -vx[i];
        if (std::fabs(y[i]) >= range - boundeps)
            vy[i] = -vy[i];
        if (std::fabs(z[i]) >= range - boundeps)
            vz[i] = -vz[i];

    }
}

void drawPoints(){
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-range, range, -range, range, -range, range);

    forward();

    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for (size_t i = 0; i < n_points; ++i){
        glColor3f(cr[i], cg[i], cb[i]);
        glVertex3f(x[i], y[i], z[i]);
    }
    glEnd();

    glBegin(GL_LINES);
    for (size_t i = 0; i < n_points; ++i){
        for (size_t j = i + 1; j < n_points; ++j){
            float dis = distance(x[i], y[i], z[i], x[j], y[j], z[j]);
            if ( dis < threshold){
                glColor3f((cr[i] + cr[j])/2, (cg[i] + cg[j])/2, (cb[i] + cb[j])/2);
                glVertex3f(x[i], y[i], z[i]);
                glVertex3f(x[j], y[j], z[j]);
            }
        }
    }
    glEnd();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}


int main(int argc, char **argv){
    initialize();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glShadeModel(GL_SMOOTH);   
    glEnable(GL_DEPTH_TEST); // Depth testing must be turned on
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OPENGL - MOVING LINED POINTS");
    glutDisplayFunc(drawPoints);
    glutMainLoop();
    return 0;
}

