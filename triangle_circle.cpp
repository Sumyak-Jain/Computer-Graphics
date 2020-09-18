#include<GL/glut.h>
#include<math.h>


void init(){
   //glClearColor(1.0, 1.0, 1.0, 0.0); // Set display window colour to white
    glMatrixMode(GL_PROJECTION);
    glOrtho(-10,10,-10,10,0,10);
}


void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0,0.0,1.0);


     glBegin(GL_LINES);
     glColor3f(1.0, 0.0, 0.0);
     for(int i=0;i<360;i++)
     {
         float theta1= (i+0.5)*3.142/180;
         float theta2= (i-0.5)*3.142/180;
         glVertex2f(8*cos(theta1),8*sin(theta1));
         glVertex2f(8*cos(theta2),8*sin(theta2));
     }
     glEnd();

     glBegin(GL_LINES);
     glColor3f(1.0, 1.0,0.0);
     glVertex2f(0,8);
     glVertex2f(-6.3,-5);

     glVertex2f(-6.3,-5);
     glVertex2f(6.3,-5);

     glVertex2f(6.3,-5);
     glVertex2f(0,8);

     glVertex2f(0,8);
     glVertex2f(0,-5);

     glVertex2f(0,2);
     glVertex2f(-2.91,2);

     glVertex2f(0,4);
     glVertex2f(-1.95,4);

     glVertex2f(0,6);
     glVertex2f(-0.97,6);

     glVertex2f(0,0);
     glVertex2f(-3.88,0);

     glVertex2f(0,-2);
     glVertex2f(-4.85,-2);

     glVertex2f(0,-4);
     glVertex2f(-5.83,-4);


     //diagonal lines

     glVertex2f(0,2);
     glVertex2f(2.43,3);

     glVertex2f(0,4);
     glVertex2f(1.46,5);

     glVertex2f(0,6);
     glVertex2f(0.73,6.5);

     glVertex2f(0,0);
     glVertex2f(3.40,1);

     glVertex2f(0,-2);
     glVertex2f(4.37,-1);

     glVertex2f(0,-4);
     glVertex2f(5.34,-3);


     glEnd();
     glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Sumyak triangle in circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
