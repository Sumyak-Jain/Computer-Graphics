//Bresenham line drawing algorithm

#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
 
int xa,xb,ya,yb;
void display (void)
{
int dx=xb-xa;
int dy=yb-ya;
int p0 = 2*dy - dx;
float x=xa,y=ya;
 
glClear (GL_COLOR_BUFFER_BIT);
 
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POINTS);
glVertex2i(x,y);
int p =p0;
int k;
for(k=0;k<dx;k++)
{
if(p<0)
{
x = x+1;
glVertex2i(x,y);
}
 
else
{
x = x+1; y = y+1;
glVertex2i(x,y);
}
}
 
glEnd();
glFlush();
}
 
void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
 
int main(int argc, char** argv)
{
printf("Enter the points\n(X1,Y1,X2,Y2):-\n");
scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Breshanman Line Algorithm ");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
