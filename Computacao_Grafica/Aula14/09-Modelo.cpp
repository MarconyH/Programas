#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

GLfloat angleX, angleY;
GLuint idTextura;

typedef struct vertex {
  float x;
  float y;
  float z;
} vertex;

typedef struct face {
  int v1, v2, v3;
  int n1, n2, n3;
  int t1, t2, t3;
} face;

std::vector<face> faces;
std::vector<vertex> vertices;
std::vector<vertex> normals;
std::vector<vertex> textures;

void loadObj(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  while (1) {
    char lineHeader[128];
    int res = fscanf(file, "%s", lineHeader);
    if (res == EOF) break;  // EOF = End Of File. Quit the loop.

    if (strcmp(lineHeader, "v") == 0) {
      vertex v;
      fscanf(file, "%f %f %f\n", &v.x, &v.y, &v.z);
      vertices.push_back(v);
    } else if (strcmp(lineHeader, "vn") == 0) {
      vertex n;
      fscanf(file, "%f %f %f\n", &n.x, &n.y, &n.z);
      normals.push_back(n);
    } else if (strcmp(lineHeader, "vt") == 0) {
      vertex vt;
      fscanf(file, "%f %f\n", &vt.x, &vt.y);
      textures.push_back(vt);
    } else if (strcmp(lineHeader, "f") == 0) {
      face f;
      fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &f.v1, &f.t1, &f.n1, &f.v2,
             &f.t2, &f.n2, &f.v3, &f.t3, &f.n3);
      faces.push_back(f);
    }
  }
}

void loadBMP(const char *filename) {
  unsigned int width, height;
  unsigned char header[54];

  unsigned char *data;

  FILE *file;
  file = fopen(filename, "rb");

  if (file == NULL) return;

  // Leitura do cabeçalho
  if (fread(header, 1, 54, file) != 54) {
    printf("Problema ao ler cabeçalho do arquivo!\n");
    return;
  }
  width = *(int *)&(header[0x12]);
  height = *(int *)&(header[0x16]);

  data = (unsigned char *)malloc(width * height * 3);
  fread(data, width * height * 3, 1, file);
  fclose(file);

  for (int i = 0; i < width * height; ++i) {
    int index = i * 3;
    unsigned char B, R;
    B = data[index];
    R = data[index + 2];

    data[index] = R;
    data[index + 2] = B;
  }

  glGenTextures(1, &idTextura);
  glBindTexture(GL_TEXTURE_2D, idTextura);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, data);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glEnable(GL_TEXTURE_2D);
}

void displayPersp(void) {
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  gluLookAt(0, 10, 30, 0, 0, 0, 0, 1, 0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // glColor3f(0.0f, 0.5f, 0.0f);

  glPushMatrix();
  glRotatef(angleX, 1, 0, 0);
  glRotatef(angleY, 0, 1, 0);

  // glutSolidTeapot(10);

  // Desenha o modelo
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < faces.size(); ++i) {
    vertex &vertex1 = vertices[faces[i].v1 - 1];
    vertex &vertex2 = vertices[faces[i].v2 - 1];
    vertex &vertex3 = vertices[faces[i].v3 - 1];

    vertex &normal1 = normals[faces[i].n1 - 1];
    vertex &normal2 = normals[faces[i].n2 - 1];
    vertex &normal3 = normals[faces[i].n3 - 1];

    vertex &texture1 = textures[faces[i].t1 - 1];
    vertex &texture2 = textures[faces[i].t2 - 1];
    vertex &texture3 = textures[faces[i].t3 - 1];

    glTexCoord2f(texture1.x, texture1.y);
    glNormal3f(normal1.x, normal1.y, normal1.z);
    glVertex3f(vertex1.x, vertex1.y, vertex1.z);

    glTexCoord2f(texture2.x, texture2.y);
    glNormal3f(normal2.x, normal2.y, normal2.z);
    glVertex3f(vertex2.x, vertex2.y, vertex2.z);

    glTexCoord2f(texture3.x, texture3.y);
    glNormal3f(normal3.x, normal3.y, normal3.z);
    glVertex3f(vertex3.x, vertex3.y, vertex3.z);
  }
  glEnd();

  glPopMatrix();

  glutSwapBuffers();
}

void init() {
  angleX = 0;
  angleY = 90;

  GLfloat posicaoLuz[4] = {0.0, 0.0, 50.0, 1.0};
  GLfloat luzAmbiente[4] = {0.25, 0.25, 0.25, 1.0};
  GLfloat luzDifusa[4] = {0.5, 0.5, 0.5, 1.0};
  GLfloat luzEspecular[4] = {0.9, 0.9, 0.9, 1.0};
  GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};

  GLint especMaterial = 50;

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  glShadeModel(GL_SMOOTH);

  glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
  glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

  glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
  glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  loadBMP("./vase.bmp");
  loadObj("./vase.obj");
}

void resize(GLsizei w, GLsizei h) {
  if (h == 0) h = 1;

  glViewport(0, 0, w, h);

  GLfloat fAspect = (GLfloat)w / (GLfloat)h;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90, fAspect, 0.1, 1000);
}

void keyboard(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_LEFT:
      angleY -= 10;
      break;
    case GLUT_KEY_RIGHT:
      angleY += 10;
      break;
    case GLUT_KEY_UP:
      angleX += 10;
      break;
    case GLUT_KEY_DOWN:
      angleX -= 10;
      break;
    case 32:
      angleX = 0;
      angleY = 90;
      break;
    case 27:
      exit(0);
      break;
  }
  glutPostRedisplay();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Modelo");
  glutDisplayFunc(displayPersp);
  glutReshapeFunc(resize);
  glutSpecialFunc(keyboard);
  init();

  glutMainLoop();
  return 0;
}
