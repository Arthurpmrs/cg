#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.14

void circleFunc() {
    GLfloat cosine, sine;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.90, 0.66, 0.10);
    glBegin(GL_LINE_LOOP);
        for(GLint i = 0; i < 100; i++) {
            cosine = cos(i * 2 * PI / 100.0);
            sine = sin(i * 2 * PI / 100.0);
            glVertex2f(0.3 * cosine, 0.3 * sine);
            printf("%f, %f", cosine, sine);
        }
    glEnd();

    glFlush();
}


void initCircle() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(200, 1000);
    glutCreateWindow("Circulo");

    initCircle();

    glutDisplayFunc(circleFunc);

    glutMainLoop();
}