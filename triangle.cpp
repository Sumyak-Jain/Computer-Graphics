// star made with triangles and triangles


#include<GL/glut.h>
#include<GL/gl.h>
#include<cmath>

void init(void)
{
 glMatrixMode(GL_PROJECTION);  // Set projection parameters
 gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
 glClear(GL_COLOR_BUFFER_BIT); // Clear display window

 glColor3f(0.0, 1.0, 0.0);  //Set line colour to red

 glBegin(GL_LINES);    //Specify line segment geometry
  glVertex2i(50,80 );
  glVertex2i(90,80);
  glVertex2i(50,60);
  glVertex2i(70,100);
  glVertex2i(50,80);
  glVertex2i(70,40);
  glVertex2i(70,100);
  
  glVertex2i(90,60);
  glVertex2i(50,60);
  glVertex2i(90,60);
  glVertex2i(70,40);
  glVertex2i(90,80);
  glVertex2i(70,80);
  glVertex2i(55,65);
  glVertex2i(70,80);
  glVertex2i(85,65);
  glVertex2i(55,65);
  glVertex2i(85,65);
  glVertex2i(62.5,72.5);
  glVertex2i(77.5,72.5);
  glVertex2i(62.5,72.5);
  glVertex2i(70,65);
  glVertex2i(70,65);
  glVertex2i(77.5,72.5);
  
 glEnd();

 glFlush(); // Process all OpenGL routines

}

int main(int argc, char* argv[])
{
 glutInit(&argc, argv);      // Initalise GLUT
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Set display mode
 
 glutInitWindowPosition(50, 100);    // Set window position
 glutInitWindowSize(400, 300);     // Set window size
 glutCreateWindow("sumyak star"); // Create display window

 init();       // Execute initialisation procedure
 glutDisplayFunc(lineSegment); // Send graphics to display window
 glutMainLoop();     // Display everything and wait
 
 return 0;
}
