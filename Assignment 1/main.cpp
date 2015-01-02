#include<GL/glut.h> // (if using GLUT)

class scrPt{
public:
	GLint x, y;
};

void setPixel(GLint x, GLint y)
{
	glPointSize(3);
	glBegin(GL_POINTS);
	  glVertex2i(x, y);
	glEnd();
}

void paraPlotPoints(scrPt);

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //Set display-window color to white

	glMatrixMode(GL_PROJECTION); //Set projection parameters
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void paraDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //Clear display window.

	glColor3f(0.0, 0.0, 1.0); //Set color of primitive to blue
	
	scrPt paraPt; paraPt.x=0; paraPt.y=0;

	GLint p=-9; //Initial value of midpoint parameter

	//Plot intial parabola vertex
	paraPlotPoints(paraPt);

	//Calculate next points and plot in 1st quadrant
	while(paraPt.x<=10){
		paraPt.x++;
		if(p+2*paraPt.x+3<0){
			p+=2*paraPt.x+3;
		    paraPt.y+=1/2;
		}
		else{
			paraPt.y+=3/2;
			p+=2*paraPt.x-17;
		}
		paraPlotPoints(paraPt);
	}

	p=paraPt.x*paraPt.x+paraPt.x-20*paraPt.y-79/4;
	
	while(paraPt.y<=20){
		paraPt.y++;
		if(p+2*paraPt.x-18<0){
			p+=2*paraPt.x-18;
		    paraPt.x+=3/2;
		}
		else{
			paraPt.x+=1/2;
			p-=20;
		}
		paraPlotPoints(paraPt);
	}

	//following code draws the x and y axis in green to illustrate relative position of parabola

	glColor3f(0.0, 1.0, 0.0); //Set line segment color to blue
	
	glPointSize(2);

	int p1[]={-50, 0};
	int p2[]={50, 0};
	int p3[]={0, -60};
	int p4[]={0, 60};

	glBegin(GL_LINES);
	  //Specify line-segment geometry
	  glVertex2iv(p1);
	  glVertex2iv(p2);
	  glVertex2iv(p3);
	  glVertex2iv(p4);
	glEnd();

	glFlush(); //Process all OpenGL routines as quickly as possible
}

void paraPlotPoints(scrPt paraPt)
{
	setPixel(paraPt.x, paraPt.y); //plots (x, y) in first quadrant
	setPixel(-paraPt.x, paraPt.y); //plots (-x, y) in second quadrant taking y axis symmetry into account
}

void main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);

	//Set display mode
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	//Set top-left display-window position
	glutInitWindowPosition(50, 100);

	//Set display-window width and height
	glutInitWindowSize(200, 200);

	//Create display window
	glutCreateWindow("Parabola Drawing Algorithm");

	//Execute initialization procedure
	init();

	//Send graphics to display window
	glutDisplayFunc(paraDraw);

	//Display everything and wait
	glutMainLoop();
}