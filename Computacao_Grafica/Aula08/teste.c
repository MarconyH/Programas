#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

void display(void)
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Define a cor de fundo da cena (cor
                                        // usada para limpar o buffer de cor)
  glClear(GL_COLOR_BUFFER_BIT);         // Inicializa o buffer de cores antes de ele
                                        // ser alterado

  glMatrixMode(GL_MODELVIEW); // Informa que as operações seguintes serão
                              // executadas na matrix modelview
  glLoadIdentity();           // Carrega a matriz identidade

  /*glPointSize(10);  // Define quantos pixels representarão um vértice na tela
  glBegin(GL_POINTS);
  {
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-0.5, 0);
    glVertex2f(-0.5, 0.5);
  }
  glEnd();

  glBegin(GL_QUADS);
  {
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.75, -0.2);
    glVertex2f(-0.35, -0.5);
    glVertex2f(-0.35, 0.5);
    glVertex2f(-0.15, 0.45);
  }
  glEnd();

  glLineWidth(5);
  glBegin(GL_TRIANGLE_STRIP);  // Indica que serão desenhados somente pontos
  {
    glColor3f(1.0f, 0.0f, 0.0f);  // Define a cor do desenho em formato RGB
    glVertex2f(0, 0);  // Especifica pontos no espaço bidimensional (pixels)

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, 0);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
  }
  glEnd();  // Encerra a criação de pontos
  */
  glPushMatrix();
  glTranslatef(0.05, 0.3, 0.0);
  glBegin(GL_QUADS);
  {
    glColor3f(0.75, 0, 0.3);
    glVertex2f(-0.7, 0.2);
    glVertex2f(-0.7, -0.5);
    glVertex2f(0, -0.5);
    glVertex2f(0, 0.2);
  }
  glEnd();

  glBegin(GL_QUADS);
  {
    glColor3f(0.7, 0, 0.7);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.2, -0.5);
    glVertex2f(-0.2, -0.1);

    glColor3f(0, 0.5, 1);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.2, -0.5);
    glVertex2f(-0.35, -0.8);
    glVertex2f(-0.65, -0.8);
  }
  glEnd();

  glPointSize(7);
  glBegin(GL_POINTS);
  {
    glColor3f(0, 1, 1);
    glVertex2f(-0.45, -0.3);
  }
  glEnd();

  glBegin(GL_TRIANGLES);
  {
    glColor3f(0, 0.5, 0);
    glVertex2f(-0.7, 0.2);
    glVertex2f(0, 0.2);
    glVertex2f(-0.35, 0.7);
  }
  glEnd();

  glBegin(GL_QUADS);
  {
    glColor3f(0, 0.5, 1);
    glVertex2f(-0.35, 0.7);
    glVertex2f(0, 0.2);
    glVertex2f(0.95, 0.2);
    glVertex2f(0.6, 0.7);

    glColor3f(0, 0.25, 0.35);
    glVertex2f(0, 0.2);
    glVertex2f(0, -0.5);
    glVertex2f(0.95, -0.5);
    glVertex2f(0.95, 0.2);

    /*
        glColor3f(0, 1, 0.5);
        glVertex2f(0.02375, 0.1);
        glVertex2f(0.02375, -0.2);
        glVertex2f(0.45125, -0.2);
        glVertex2f(0.45125, 0.1);
        //half 0.475
        glVertex2f(0.49875, 0.1);
        glVertex2f(0.49875, -0.2);
        glVertex2f(0.92625, -0.2);
        glVertex2f(0.92625, 0.1);
        */
    glColor3f(0, 0, 0.5);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.05, -0.2);
    glVertex2f(0.38, -0.2);
    glVertex2f(0.38, 0.1);

    glVertex2f(0.57, 0.1);
    glVertex2f(0.57, -0.2);
    glVertex2f(0.9, -0.2);
    glVertex2f(0.9, 0.1);
  }
  glEnd();
  glLineWidth(5);
  glBegin(GL_LINES);
  {
    glColor3f(0, 0, 1);
    glVertex2f((0.57+0.9)/2, 0.1);
    glVertex2f((0.57+0.9)/2, -0.2);

    glVertex2f(0.9, (0.1-0.2)/2);
    glVertex2f(0.57, (0.1-0.2)/2);  

    
    glVertex2f((0.38+0.05)/2, 0.1);
    glVertex2f((0.38+0.05)/2, -0.2);

    glVertex2f(0.38, (0.1-0.2)/2);
    glVertex2f(0.05, (0.1-0.2)/2); 

  } 
  glEnd();
  glPopMatrix();

  glFlush(); // Informa que as operações devem ser processadas imediatamente e
             // exibidas na tela
}

/*Recebe um o comprimento (width) e altura (height) da janela em pixels.*/
void resize(GLsizei w, GLsizei h)
{
  if (h == 0)
    h = 1;

  printf("Tam. janela: (%i,%i)\n", w, h);
}

/*Recebe um código para cada tecla (ASCII) e as coordenadas do mouse.*/
void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    exit(0);
    break;
  case 32:
    glClearColor(1.0f, 1.0f, 1.0f,
                 1.0f); // Define a cor de fundo da cena (cor usada para
                        // limpar o buffer de cor)
    break;
  default:
    printf("Código tecla: %i. Mouse em (%i,%i)\n", key, x, y);
    break;
  }
  glutPostRedisplay(); // Informa que a janela atual deve ser redesenhada
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv); // Inicializa a OpenGL
  glutInitDisplayMode(
      GLUT_SINGLE |
      GLUT_RGB);                 // Configura os modos de exibição (mais detalhes no futuro)
  glutInitWindowSize(1036, 700); // Define o tamanho da janela em pixels
  glutInitWindowPosition(0, 0);  // Define a posição inicial da janela
  glutCreateWindow(
      "Primeiro Exemplo"); // Cria a janela especificando seu título
  glutDisplayFunc(
      display);               // Especifica a função de rendering (exibe a cena no loop)
  glutReshapeFunc(resize);    // Especifica função a ser executada quando a janela
                              // é redimensionada
  glutKeyboardFunc(keyboard); // Especifica função a ser executada quando uma
                              // tecla é pressionada

  glutMainLoop(); // Executa o loop de renderização
  return 0;
}
