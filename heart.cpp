// heart shape

#include <GL/glut.h>
#include <cmath>

void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(400, 40);
    glutInitWindowSize(400, 400);
    glutCreateWindow("sumyak heart");
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glutDisplayFunc(display);
  
    glutMainLoop();

    return 0;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -2, 2);

  
    glPointSize(1);
    glColor3ub(255, 0, 0);  // Color Red
    glBegin(GL_POINTS);
        for (float x = -1.139; x <= 1.139; x += 0.001) 
        {
            float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
            float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
            float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
            glVertex2f(x, y1);
            glVertex2f(x, y2);
        }
    glEnd();
    
    glFlush();
}

