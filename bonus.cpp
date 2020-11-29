// moving point
#include<iostream>
#include<stdio.h>
#include<GL/glut.h>

using namespace std;
int x,y;

void lineB(float x1 , float y1 , float x2 , float y2){

glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
 glEnd();
}
void myInit (void)
{

//glClearColor(1.0, 0.0, 1.0, 0.0);
glColor3f(0.0, 1.0, 0.0);


glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();


gluOrtho2D(-100, 100, -100, 100);

}
void grid(void)
{
for(int i=-90; i<100;i=i+10)
{
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 0.0);
lineB(i,-100,i,100);
lineB(-100,i,100,i);
}
glEnd();
}
void jump(unsigned char key, int a, int b)
{

if(key =='k' || key =='K')
{
glClear(GL_COLOR_BUFFER_BIT);
x=x+1;
grid();
glBegin(GL_POINTS);
glColor3f(0.0, 1.0, 0.0);
glVertex2f(x,y);
glEnd();
glFlush();
}
else if(key =='j' || key == 'J')
{
glClear(GL_COLOR_BUFFER_BIT);
x=x-1;
grid();
glBegin(GL_POINTS);
glColor3f(0.0, 1.0, 0.0);
glVertex2f(x,y);
glEnd();
glFlush();
}
else if(key == 'H' || key == 'h')
{
glClear(GL_COLOR_BUFFER_BIT);
y=y-1;
grid();
glBegin(GL_POINTS);
glColor3f(0.0, 1.0, 0.0);
glVertex2f(x,y);
glEnd();
glFlush();
}
else if(key =='l' || key == 'L')
{
glClear(GL_COLOR_BUFFER_BIT);
y=y+1;
grid();
glBegin(GL_POINTS);
glColor3f(0.0, 1.0, 0.0);
glVertex2f(x,y);
glEnd();
glFlush();
}

}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);


grid();

glBegin(GL_POINTS);

//void glPointSize(8.0);
glColor3f(0.0, 1.0, 0.0);
glVertex2f(x,y);
glEnd();

glFlush();
}
int main (int argc, char** argv)
{

cout<<"Enter the coordinates of the character"<<endl;
cin>>x>>y;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1366, 768);
glutInitWindowPosition(0, 0);
glutCreateWindow("Bonus1");
myInit();
glutDisplayFunc(display);
glutKeyboardFunc(jump);
glutMainLoop();

return 0;
}
