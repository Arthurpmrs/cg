#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape (int w, int h);

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6
#define BRANCO   0.8, 0.8, 0.8
#define MARROM   0.8, 0.5, 0.4

static GLfloat vertices[39]={
  0.0,  30.0, 30.0, /* 0 */
  20.0, 30.0, 30.0, /* 1 */
  30.0, 20.0, 30.0, /* 2 */
  30.0,  0.0, 30.0, /* 3 */
  0.0,   0.0, 30.0, /* 4 */
  0.0,  30.0,  0.0, /* 5 */
  30.0, 30.0,  0.0, /* 6 */
  30.0,  0.0,  0.0, /* 7 */
  0.0,   0.0,  0.0, /* 8 */
  30.0, 30.0, 20.0, /* 9 */
  30.0, 30.0, 30.0, /* 10 */
  0.0, 45.0, 15.0,  /* 11 */
  30.0, 45.0, 15.0  /* 12 */
}; 

static GLubyte frenteIndices[]    = {0,4,3,2,1};
static GLubyte trasIndices[]      = {5,6,7,8};
static GLubyte esquerdaIndices[]  = {0,5,8,4};
static GLubyte direitaIndices[]   = {2,3,7,6,9};
static GLubyte topoIndices[]      = {0,1,9,6,5};
static GLubyte fundoIndices[]     = {3,4,8,7};
static GLubyte trianguloIndices[] = {1,2,9};
static GLubyte piramideEsquerda[] = {1,2,10};
static GLubyte piramideDireita[] = {2,9,10};
static GLubyte piramideTopo[] = {1,10,9};
static GLubyte telhadoEsquerda[] = {0,11,5};
static GLubyte telhadoDireita[] = {6,12,10};
static GLubyte telhadoFront[] = {10,12,11,0};
static GLubyte telhadoBack[] = {12,6,5,11};


    
static int eixoy, eixox;
int largura, altura;
double cx = 120.0;
double cy = 0.0;
double cz = 0.0;
double angle = 0.0;
double angle_radian = 0.0;
double d = 120.0;

int main(int argc, char** argv){
  int i;
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (1000, 700); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glOrtho (-50, 50, -50, 50, -50 , 50);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE); 
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  largura=w; 
  altura=h;
}

void display(void){
  glPushMatrix();
  glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) eixox, 1.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);

  glColor3f (AZUL); /* frente */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, frenteIndices);

  glColor3f (AMARELO); /* esquerda */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerdaIndices);

  glColor3f (VERMELHO); /* tras */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, trasIndices);

  glColor3f (VERDE); /* direita */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, direitaIndices);

  glColor3f (CYAN); /* topo */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, topoIndices);

  glColor3f (LARANJA); /* fundo */
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, fundoIndices);

  glColor3f (CINZA); /* triangulo */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, trianguloIndices);

  // Faces da pirâmide que completa o buraco (reboco)
  glColor3f (BRANCO);
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, piramideEsquerda);
  glColor3f (BRANCO);
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, piramideDireita);
  glColor3f (BRANCO);
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, piramideTopo);

  // Telhado
  glColor3f (MARROM);
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, telhadoEsquerda);
  glColor3f (MARROM);
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, telhadoDireita);

  glColor3f (MARROM);
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, telhadoFront);
  glColor3f (MARROM);
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, telhadoBack);

  glDisableClientState (GL_VERTEX_ARRAY);

  glPopMatrix();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'a':
    printf("%d, %d\n",x,y);
    break;
  case 'y':
    eixoy = (eixoy + 5) % 360;
    glutPostRedisplay();
    break;
  case 'Y':
    eixoy = (eixoy - 5) % 360;
    glutPostRedisplay();
    break;
  case 'x':
    eixox = (eixox + 5) % 360;
    glutPostRedisplay();
    break;
  case 'X':
    eixox = (eixox - 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 20.0, 300.0);
    gluLookAt(cx, cy, cz, 15, 15, 15, 0, 1, 0);
    glutPostRedisplay();
    break;
  case 'o':
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -50 , 50);
    glutPostRedisplay();
    break;
  case 'e':
    angle += 5.0;
    angle_radian = (2 * 3.14 * angle) / 360.0;
    cx = d * cos(angle_radian);
    cz = d * sin(angle_radian);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 10.0, 400.0);
    gluLookAt(cx, cy, cz, 15, 15, 15, 0, 1, 0);
    glutPostRedisplay();
    break;
  case 'q':
    angle += 5.0;
    angle_radian = (2 * 3.14 * angle) / 360.0;
    cx = d * cos(angle_radian);
    cy = d * sin(angle_radian);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 10.0, 400.0);
    gluLookAt(cx, cy, cz, 15, 15, 15, 0, 1, 0);
    glutPostRedisplay();
    break;
  }
}