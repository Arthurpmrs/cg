#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

// Cores do catavento: 0 - Branco, 1 - Vermelho, 2 - Azul, 3 - Verde
GLfloat r[] = {1.0, 1.0, 0.00, 0.0};
GLfloat g[] = {1.0, 0.0, 0.00, 1.0};
GLfloat b[] = {1.0, 0.0, 1.00, 0.0};
int offset = 0;

// Aparentemente, no C o módulo de um número negativo continua negativo, o que não
// era desejado para minha implementação, então usei essa função auxiliar que
// vi em: https://stackoverflow.com/a/19288271/8736974
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

void pinwheelFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.90, 0.66, 0.10);
    glBegin(GL_POLYGON);
        glVertex2i(248, 250);
        glVertex2i(251, 250);
        glVertex2i(248, 100);
        glVertex2i(251, 100);
    glEnd();

    // Folhas do catavento
    glColor3f(r[mod(offset, 4)], g[mod(offset, 4)], b[mod(offset, 4)]);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(200, 420);
        glVertex2i(300, 420);
    glEnd();

    glColor3f(r[mod(offset + 1, 4)], g[mod(offset + 1, 4)], b[mod(offset + 1, 4)]);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(350, 370);
        glVertex2i(350, 270);
    glEnd();

    glColor3f(r[mod(offset + 2, 4)], g[mod(offset + 2, 4)], b[mod(offset + 2, 4)]);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(200, 220);
        glVertex2i(300, 220);
    glEnd(); 

    glColor3f(r[mod(offset + 3, 4)], g[mod(offset + 3, 4)], b[mod(offset + 3, 4)]);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 320);
        glVertex2i(150, 370);
        glVertex2i(150, 270);
    glEnd(); 

    glFlush();
}

void handleKeyboard(int key, int x, int y) {
    // A ideia é o catavento mude no sentido anti-horário quando clicamos o direcional
    // esquerdo, e horário quando clicamos o direito.
    switch (key) {
        case GLUT_KEY_LEFT:
            offset += 1;
            break;
        case GLUT_KEY_RIGHT:
            offset -= 1;
            break;
        default:
            break;
    }
    glutPostRedisplay(); 
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 1000);
    glutCreateWindow("Cata-vento");

    init();

    glutDisplayFunc(pinwheelFunc);
    glutSpecialFunc(handleKeyboard);

    glutMainLoop();
}