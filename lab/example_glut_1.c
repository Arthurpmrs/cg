//
//  Introducao
//
//  Created by Marcelo Costa on 15/12/12.
//  Copyright (c) 2012 Universidade Federal de Alagoas - UFAL. All rights reserved.
//

//#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

// #include <GLUT/glut.h>


void init (void)
{
    /* selecionar cor de fundo (preto) */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode (GL_MODELVIEW); //Projecao 2D
    
    //gluOrtho2D (0.0, 600.0, 0.0, 600.0); //Definindo os limites da Porta de Visao (ViewPort)
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); //normalizado 
}

void display(void)
{
    /* Limpar o Buffer de pixels  */
    glClear (GL_COLOR_BUFFER_BIT);
    
    glPointSize(10.0f); // Define o tamanho do ponto para 10 pixels
    glColor3f (1.0, 0.0, 0.0);
   
   //GL_POINTS
    glBegin(GL_POINTS);
        glVertex3f (0.25, 0.25, 0.5);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.75, 0.90, 0.0);
        glVertex3f (0.75, 0.81, 0.0);
        glVertex3f (0.75, 0.88, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    glEnd();

    //GL_LINES
    glBegin(GL_LINES);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
    glEnd();
        
     //GL_LINE_STRIP 
    glBegin(GL_LINE_STRIP);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.30, 0.45, 0.0);
    glEnd();

    //GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
        glVertex3f (0.25, 0.25, 0.0); //mesmas coordenadas do Line Strip, mas com loop
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.30, 0.45, 0.0);
        glVertex3f (0.30, 0.55, 0.0);
    glEnd();



    
    /* 
        Inicia o processo de desenho através dos
        dados bufferizados
    */
    glFlush ();
}



int main(int argc, char** argv) {
    
	glutInit(&argc, argv);
    
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 400); //tamanho em pixels da janela
	glutInitWindowPosition (200, 200); //define posicao da Window na tela
	
    /*
        Cria uma janela com base nos parâmetros especificados
        nas funções glutInitWindowSize e glutInitWindowPosition
        com o nome de título especificado em seu argumento
    */
    glutCreateWindow ("Exemplos Linhas");
    
	init();
    
    // Associa a função display como uma função de callback
	glutDisplayFunc(display);
    
	/*
        Inicia a execução do programa OpenGL.
        O programa irá executar num loop infinito devendo
        o desenvolvedor especificar as condições de saída do mesmo
        através de interrupções no próprio programa ou através
        de comandos de mouse ou teclado como funções de callback
    */
    glutMainLoop();
    
	/* C ANSI requer que main retorne um inteiro */
	return 0;
    
}
