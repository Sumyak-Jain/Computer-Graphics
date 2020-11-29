#include <GL/glut.h>
struct Point {
  GLfloat x, y;
  Point(GLfloat x = 0, GLfloat y = 0): x(x), y(y) {}
  Point midpoint(Point p) {return Point((x + p.x) / 2.0, (y + p.y) / 2.0);}
};

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  static Point vertices[] = {Point(0, 0), Point(200, 500), Point(500, 0)};
  static Point p = vertices[0];
  glBegin(GL_POINTS);
  for (int k = 0; k < 10000000; k++) {
    p = p.midpoint(vertices[rand() % 3]);
    glVertex2f(p.x, p.y);
  }
  glEnd();
  glFlush();
}

void init() {
  glClearColor(1.0, 1.0, 0.4, 1.0);
  glColor3f(0.1, 1.0, 0.0);

  // Set up the viewing volume: 500 x 500 x 1 window with origin lower left.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, 1.0);
}
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(40, 40);
  glutCreateWindow("sumyak Green Triangle");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
