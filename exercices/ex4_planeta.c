//
//  Atividade Transformacao Planetas
//
//  Adaptado de Marcelo Costa on 16/03/2025.
//  Copyright (c) 2012 Universidade Federal de Alagoas - UFAL. All rights reserved.
//

#include <GL/gl.h>
#include <GL/glut.h>

static int year=0, day=0;

// Inicializa parâmetros de rendering
void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_MODELVIEW); 
    gluPerspective(60.0, 1.0, 1.0, 80.0);
}

// Função callback chamada para fazer o desenho
void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    
	glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);

        glRotatef((GLfloat) year, 1.0, 0.0, 0.0);

        glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
        glutWireSphere(1.0, 20, 16); 
	glPopMatrix();
    
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);

        glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
        glTranslatef(2.0, 0.0, 0.0);

        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.2, 10, 8);
	glPopMatrix();

    glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);

        glRotatef((GLfloat) -year, 0.0, 1.0, 0.0);
        glTranslatef(4.0, 0.0, 0.0);

        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.3, 10, 8); 
	glPopMatrix();

    glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);

        glRotatef((GLfloat) -year, 0.0, 1.0, 0.0);
        glTranslatef(4.0, 0.0, 0.0);

        glRotatef((GLfloat) -year, 1.0, 0.0, 0.0);
        glTranslatef (0.0, 0.6, 0.0);

        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.1, 10, 8); 
	glPopMatrix();

    glPushMatrix();
		glColor3f(0.0, 1.0, 1.0);

        glRotatef((GLfloat) -year, 0.0, 1.0, 0.0);
        glTranslatef(4.0, 0.0, 0.0);

        glRotatef((GLfloat) year, 1.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 0.8);

        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.1, 10, 8);
	glPopMatrix();
    
    glutSwapBuffers();
}

void reshape (int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	gluLookAt(0.0, 0.0, 7, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //posicao da camera
    
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
        case 'd':
            day = (day + 10) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            day = (day - 10) % 360;
            glutPostRedisplay();
            break;
        case 'y':
            year = (year + 2) % 360;
            glutPostRedisplay();
            break;
        case 'Y':
            year = (year - 2) % 360;
            glutPostRedisplay();
            break;
        default:
            break;
	}
}

int main(int argc, char** argv){
	
    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Rotacao de Planetas");
	
    init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}