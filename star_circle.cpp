// drawing a circle inside a star made from triangles

#include <GL/glut.h>
#include <math.h>
void line_join(float x1 , float y1 , float x2 , float y2){
    
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    
}

void cirlce()
{
    float theta;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i<360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(0.125*cos(theta),0.125*sin(theta));
    }
    glEnd();
    glFlush();
}
void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    
   glColor3f(0.0,1.0,1.0);
    
    line_join(0.0, 1.0, -0.86, -0.50);
    line_join(0.0, 1.0, 0.86, -0.50);
    line_join(-0.86, -0.50, 0.86, -0.50);
    
    glColor3f(1.0,0.0,1.0);
    
    
    line_join(0.0, -1.0, 0.86, 0.50);
    line_join(0.0, -1.0, -0.86, 0.50);
    line_join(0.86, 0.50, -0.86, 0.50);
    
    glColor3f(0.0,1.0,1.0);
    
    
    line_join(0.0, 0.5, 0.43, -0.25);
    line_join(0.0, 0.5, -0.43, -0.25);
    line_join(0.43, -0.25, -0.43, -0.25);
    
    glColor3f(1.0,0.0,1.0);
    
    line_join(0.0, -0.250, 0.216, 0.125);
    line_join(0.0, -0.250, -0.216, 0.125);
    line_join(0.216, 0.125, -0.216, 0.125);
    
    glColor3f(1.0,1.0,1.0);
    cirlce();
    
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(550, 550);
    glutCreateWindow("Sumyak circle in star");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
