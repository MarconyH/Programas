#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLdouble posicao = 0;
GLdouble rotacao = 0;
int cam_view = 2;

void render_floor()
{
  glColor3f(0.5, 0.8, 0.5);
  glBegin(GL_LINES);
  for (GLfloat i = -100; i <= 100; i += 10)
  {
    glVertex3f(i, -10, 100);
    glVertex3f(i, -10, -100);
    glVertex3f(100, -10, i);
    glVertex3f(-100, -10, i);
  }
  glEnd();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  render_floor();

  glPushMatrix();
  {
    glTranslatef(posicao, 0, 0);

    glPushMatrix();
    {
      glColor3f(1.0f, 0.0f, 0.0f);
      glScalef(40, 1, 5);
      glutSolidCube(1);
    }
    glPopMatrix();
    glPushMatrix();
    {
      glTranslatef(20, 0, 0);
      glPushMatrix();
      {
        glRotatef(rotacao, 0, 1, 0);

        glPushMatrix();
        {
          glTranslatef(0, 10, 0);
          glColor3f(0.0f, 0.0f, 1.0f);
          glScalef(1, 20, 1);
          glutWireCube(1);
        }
        glPopMatrix();

        glPushMatrix();
        {
          glTranslatef(0, 20, 0);
          glColor3f(0.0f, 0.0f, 1.0f);
          glScalef(1, 1, 5);
          glutWireCube(1);
        }
        glPopMatrix();

        glPushMatrix();
        {
          glTranslatef(0, -5, 0);
          glColor3f(0.25f, 0.25f, 0.25f);
          glutSolidTorus(1, 3, 15, 30);
        }
        glPopMatrix();
      }
      glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    {
      glTranslatef(-20, -5, 0);
      glColor3f(0.25f, 0.25f, 0.25f);
      glutSolidTorus(1, 3, 15, 30);
    }
    glPopMatrix();
  }
  glPopMatrix();

  glutSwapBuffers();
}

void change_cam_view()
{
  switch (cam_view)
  {
  case 0:
    gluLookAt(100, 0, 0, 0, 0, 0, 0, 1, 0);
    break;
  case 1:
    gluLookAt(0, 250, 0, 0, 0, 0, 1, 0, 0);
    break;
  case 2:
    gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
    break;
  }
}

void configView()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  glViewport(0, 0, 800, 600);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45, 800 / 600.0, 0.5, 500);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  change_cam_view();
}

void resize(GLsizei w, GLsizei h)
{
  if (h == 0)
    h = 1;
}

void specialkeys(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_UP:
    posicao += 2;
    break;
  case GLUT_KEY_DOWN:
    posicao -= 2;
    break;
  case GLUT_KEY_LEFT:
    rotacao -= 5;
    rotacao = (rotacao < -45) ? -45 : rotacao;
    break;
  case GLUT_KEY_RIGHT:
    rotacao += 5;
    rotacao = (rotacao > 45) ? 45 : rotacao;
    break;
  }
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    exit(0);
    break;
  case 32:
    cam_view = (++cam_view % 3);
    posicao = 0;
    rotacao = 0;
    configView();
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

void init(void)
{
  // Especifica que a cor de fundo da janela será branca
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  // Habilita o z-buffer
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Visualizacao 3D");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(specialkeys);
  configView();
  init();
  glutMainLoop();
  return 0;
}
