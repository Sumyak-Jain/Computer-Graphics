// triangle in circle with a line

#include<GL/glut.h>
#include<GL/gl.h>
#include<cmath>


void init(void)
{
 glClearColor(1.0, 1.0, 1.0, 0.0); // Set display window colour to white

}
void draw(void){

glClear(GL_COLOR_BUFFER_BIT);

float t1,t2,t3,t4,t5,t6;

glPointSize(2);
 glBegin(GL_POINTS);
 glColor3f(1.0, 0.0, 0.0);
 for(int i=0;i<1000;++i)
  {
  glVertex3f(cos(2*3.14159*i/180.0),sin(2*3.14159*i/180.0),0);
  
   if(i==45)
	{
	t1=cos(2*3.14159*i/180.0);
	t2=sin(2*3.14159*i/180.0);
	}  

  else if(i==112)
	{
	t3=cos(2*3.14159*i/180.0);
	t4=sin(2*3.14159*i/180.0);
	}  

  else if(i==157)
	{
	t5=cos(2*3.14159*i/180.0);
	t6=sin(2*3.14159*i/180.0);
	}  

}  
 
 glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0, 0.0, 0.0);
glVertex2f(t1,t2);
glVertex2f(t3,t4);
glVertex2f(t5,t6);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0, 1.0,0.0);
glVertex2f(t1,t2);
glVertex2f((t3+t5)/2,(t4+t6)/2);
glEnd();
 glFlush();
}

int main(int argc,char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("Triangle in circle");
init();
//glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
//gluOrtho2D(100,200,100,200);
glutDisplayFunc(draw);
glutMainLoop();


return 0;
}
