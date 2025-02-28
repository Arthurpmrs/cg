#include <GL/gl.h>
#include <GL/glut.h>

GLsizei winWidth = 400, winHeight = 300;

void picoleFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2i(248, 250);
        glVertex2i(251, 250);
        glVertex2i(248, 100);
        glVertex2i(251, 100);
    glEnd();
        
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(200, 120);
        glVertex2i(300, 120);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse) {
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
        int x1 = xMouse;
        int y1 = winHeight - yMouse;
        plotPoint(x1, y1);
        printf("x1 da função: %d", x1);
        printf("y1 da função: %d", y1);
    }
    glFLush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, GLdouble (newWidth), 0.0, )
}

void displayFunc(void) {
    glCLear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(200, 1000);
    glutCreateWindow("Pontos usando Mouse");

    init();

    glutDisplayFunc(picoleFunc);
    glutMouseFunc();
    glutMainLoop();
}