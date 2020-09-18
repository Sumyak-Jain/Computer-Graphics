// smiley shape

#include <GL/glut.h>
#include <math.h>

void init(void)
{
 //glClearColor(1.0, 1.0, 1.0, 0.0);

 glMatrixMode(GL_PROJECTION);  
 gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void smiley(void)
{
 glClear(GL_COLOR_BUFFER_BIT); 

 glColor3f(1,0,0);  
 float theta;

 glBegin(GL_LINES);
 for(int i=0; i<360; i++)
 {
  theta=i*3.14159/180;
  glVertex2i(60+40*cos(theta),60+40*sin(theta));
 }
 glEnd();

  glBegin(GL_LINES);
 for(int i=0; i<360; i++)
 {
  theta=i*3.14159/180;
  glVertex2i(45+3*cos(theta),75+3*sin(theta));
 }
 glEnd();

   glBegin(GL_LINES);
 for(int i=0; i<360; i++)
 {
  theta=i*3.14159/180;
  glVertex2i(75+3*cos(theta),75+3*sin(theta));
 }
 glEnd();

    glBegin(GL_LINES);
 for(int i=210; i<330; i++)
 {
  theta=i*3.14159/180;
  glVertex2i(60+25*cos(theta),60+25*sin(theta));
 }
 glEnd();

 glBegin(GL_LINES);    //Specify line segment geometry
  glVertex2i(60,70);
  glVertex2i(60,50);
  
 glEnd();

 glFlush(); 

}

int main(int argc, char* argv[])
{
 glutInit(&argc, argv);   
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  
 glutInitWindowPosition(50, 100);   
 glutInitWindowSize(400, 300);   
 glutCreateWindow("Sumyak smiley"); 

 init(); 
 glutDisplayFunc(smiley);
 glutMainLoop();    
 
 return 0;
}
