// basic house

#include <GL/glut.h>
GLfloat t,u=1;
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glColor3f(20.0f, 0.0f, 0.0f);           // set the drawing color to black 
	glPointSize(10.0);		            //set the point size to 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);// to be explained
}
 
void mouse(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON){
        t=0;
        u=1;
    }
    else if(button==GLUT_RIGHT_BUTTON){
        t=1;
        u=0;
    }
    else{

    }
    glutPostRedisplay();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);    
	
	int y = 200;
		glBegin(GL_LINE_LOOP);
		
		glVertex2i(70, 10 + y );         // draw some points (don't know how many)
		glVertex2i(70, 130 + y);
		glVertex2i(150, 130 + y);
		glVertex2i(150, 10 + y);
		glEnd();
		glBegin(GL_LINE_LOOP);

		glVertex2i(70, 130 + y);         // draw some points (don't know how many)
		glVertex2i(110, 230 + y);
		glVertex2i(150, 130 + y);

		glEnd();
		glBegin(GL_LINE_LOOP);

		glVertex2i(150, 130 + y);         // draw some points (don't know how many)
		glVertex2i(300, 130 + y);
		glVertex2i(300, 10 + y);
		glVertex2i(150, 10 + y);

		glEnd();
		glBegin(GL_LINE_LOOP);

		glVertex2i(110, 230 + y);         // draw some points (don't know how many)
		glVertex2i(300, 230 + y);
		glVertex2i(300, 130 + y);
		glVertex2i(70, 130 + y);

		glEnd();
		glBegin(GL_LINE_LOOP);

		glVertex2i(180, 40 + y);         // draw some points (don't know how many)
		glVertex2i(180, 100 + y);
		glVertex2i(270, 100 + y);
		glVertex2i(270, 40 + y);

		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2i(225, 100 + y);
		glVertex2i(225, 40 + y);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2i(180, 70 + y);
		glVertex2i(270, 70 + y);

		glEnd();
		
		

		glFlush();

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(640, 480);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("House"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMouseFunc(mouse);
	glutMainLoop(); 
	
			     // go into a perpetual loop
}
