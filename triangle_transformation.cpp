//scaling,rotation and reflection of triangle
#include<iostream> 
#include<GL/glut.h> 
#include<math.h> 

using namespace std;

float x,x2,x3,y,y2,y3,tx,ty,Sx,Sy,X,X2,X3,Y,Y2,Y3,theta;
int choice,choice1;

void rotation(float theta)
{
     glBegin(GL_TRIANGLES);
           glColor3f(1.0, 1.0,0.0);
		glVertex2f(x,y);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
	glEnd();
		
	glFlush(); 
	float theta_radians = (theta*3.142)/180;
	
	X = x*cos(theta_radians) - y*sin(theta_radians);
	Y = x*sin(theta_radians) + y*cos(theta_radians);
	
	X2 = x2*cos(theta_radians) - y2*sin(theta_radians);
	Y2 = x2*sin(theta_radians) + y2*cos(theta_radians);
	
	X3= x3*cos(theta_radians) - y3*sin(theta_radians);;
	Y3 = x3*sin(theta_radians) + y3*cos(theta_radians);	
}

void reflection(int choice1)
{
  glBegin(GL_TRIANGLES);
           glColor3f(1.0, 1.0,0.0);
		glVertex2f(x,y);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
	glEnd();
		
	glFlush(); 
	if(choice1==1)
	{
		X = x;
		Y = -y;
		X2 = x2;
		Y2 = -y2;
		X3 = x3;
		Y3 = -y3;
	}
	
	else if(choice1==2)
	{
		X = -x;
		Y = y;
		X2 = -x2;
		Y2 = y2;
		X3 = -x3;
		Y3 = y3;
	}
	
	else
	{
		X = -x;
		Y = -y;
		X2 = -x2;
		Y2 = -y2;
		X3 = -x3;
		Y3 = -y3;
	}

}
void scaling(float Sx, float Sy)

{

         glBegin(GL_TRIANGLES);
           glColor3f(1.0, 1.0,0.0);
		glVertex2f(x,y);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
	glEnd();
		
	glFlush(); 
	
	X = x*Sx;
	X2 = x2*Sx;
	X3 = x3*Sx;
	
	Y = y*Sy;
	Y2 = y2*Sy;
	Y3 = y3*Sy;
}

void myInit (void)
{ 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	gluOrtho2D(-100,100,-100,100); 
} 

void displayMe (void)
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	
	if(choice==1)
	{
		scaling(Sx,Sy);
	}
	
	else if(choice==2)
	{
		rotation(theta);
	}
	
	else
	{
		reflection(choice1);
	}
	
	glBegin(GL_TRIANGLES);
	glColor3f(2.0, 3.0,2.0);
		glVertex2f(X,Y);
		glVertex2f(X2,Y2);
		glVertex2f(X3,Y3);
	glEnd();
		
	glFlush(); 
} 

int main (int argc, char** argv) 
{
	cout<<"Enter the vertices of the triangle\n";
	cin>>x>>y>>x2>>y2>>x3>>y3;
	
	cout<<"Enter your choice:\n1.Scaling\n2.Rotation\n3.Reflection\n";
	cin>>choice;
	
	switch(choice)
	{
		case 1: cout<<"Enter the scaling factors for x and y\n";
			cin>>Sx>>Sy;
		break;
		
		case 2: cout<<"Enter the angle of rotation in degrees\n";
			cin>>theta;
		break;
		
		case 3: cout<<"1.Reflection about x-axis\n2.Reflection about y-axis\n3.Reflection about origin.\n";
			cin>>choice1;
		break;
	}
	
	
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sumyak scaling,rotation and reflection of triangle"); 
	myInit(); 	
	glutDisplayFunc(displayMe); 
	glutMainLoop(); 
}
