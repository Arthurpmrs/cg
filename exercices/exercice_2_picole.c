#include <GL/gl.h>
#include <GL/glut.h>

void picoleFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.90, 0.66, 0.10);
    glBegin(GL_POLYGON);
        glVertex2i(248, 250);
        glVertex2i(251, 250);
        glVertex2i(248, 100);
        glVertex2i(251, 100);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(200, 220);
        glVertex2i(300, 220);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(200, 420);
        glVertex2i(300, 420);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(150, 370);
        glVertex2i(150, 270);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(350, 370);
        glVertex2i(350, 270);
    glEnd();

    glFlush();
}

void initPicole() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 1000);
    glutCreateWindow("Picole");

    initPicole();

    glutDisplayFunc(picoleFunc);

    glutMainLoop();
}