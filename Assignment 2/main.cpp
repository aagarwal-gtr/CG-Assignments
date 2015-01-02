/*
'w' for wireframe mode
'f' for forward walk
'b' for backward walk
*/

#include <GL/glut.h>

GLfloat arm, move, knee, knee2;
GLint a,b;

void process_key(unsigned char key, int x, int y) //Processes key: 'f' for forward walk 'b' for backward walk
{
	
	if(key=='f'||key=='F')
	{
		move+=0.5;
		switch(a){
			case 0: 
				a++;arm=8;knee=0.5;knee2=0.2;break;
			case 1:
				a++;arm=16;knee=0.8;knee2=0.5;break;
			case 2:
				a++;arm=22;knee=1.2;knee2=0.7;break;
			case 3:
				a++;arm=16;knee=0.8;knee2=0.2;break;
			case 4:
				a++;arm=8;knee=0.5;knee2=0.2;break;
			case 5:
				a++;arm=0;knee=0;knee2=0;break;
			case 6:
				a++;arm=-8;knee=-0.5;knee2=0.2;break;
			case 7:
				a++;arm=-16;knee=-0.8;knee2=0.5;break;
			case 8:
				a++;arm=-22;knee=-1.2;knee2=0.7;break;
			case 9:
				a++;arm=-16;knee=-0.8;knee2=0.5;break;
			case 10:
				a++;arm=-8;knee=-0.5;knee2=0.2;break;
			case 11:
				a=0;arm=0;knee=0;knee2=0;break;
		}
	}
	else if(key=='b'||key=='B')
	{
		move-=0.5;
		switch(a){
			case 0: 
				a++;arm=8;knee=0.5;knee2=0.2;break;
			case 1:
				a++;arm=16;knee=0.8;knee2=0.5;break;
			case 2:
				a++;arm=22;knee=1.2;knee2=0.7;break;
			case 3:
				a++;arm=16;knee=0.8;knee2=0.2;break;
			case 4:
				a++;arm=8;knee=0.5;knee2=0.2;break;
			case 5:
				a++;arm=0;knee=0;knee2=0;break;
			case 6:
				a++;arm=-8;knee=-0.5;knee2=0.2;break;
			case 7:
				a++;arm=-16;knee=-0.8;knee2=0.5;break;
			case 8:
				a++;arm=-22;knee=-1.2;knee2=0.7;break;
			case 9:
				a++;arm=-16;knee=-0.8;knee2=0.5;break;
			case 10:
				a++;arm=-8;knee=-0.5;knee2=0.2;break;
			case 11:
				a=0;arm=0;knee=0;knee2=0;break;
		}
	}
	else if(key=='w'||key=='W')
	{
		if(b==0){glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);b=1;}
		else{glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);b=0;}
	}
	else
	{
	
	}
	glutPostRedisplay();
}

void torso() //Draws torso and lower body
{
   glPushMatrix();
   glTranslatef(0.0,3.0,0.0);
   glScalef(4.0,3.0,2.0);
   glutSolidCube(1.0);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.0,1.0,0.0);
   glScalef(3.0,2.0,1.5);
   glutSolidCube(1.0);
   glPopMatrix();
}

void head() //Draws head
{
   glPushMatrix();
   glTranslatef(0.0,0.0,0.0);
   glScalef(1.0, 1.5, 1.0);
   glutSolidCube(1.4);
   glPopMatrix();
}

void left_upper_arm() //Draws Left Upper Arm
{
   glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glRotatef(arm, 1.0, 0.0, 0.0);
   glTranslatef(0.0,1.5,0.0);
   glScalef(1.0,2.0,1.0);
   glutSolidCube(1.0f);
   glPopMatrix();
}

void left_lower_arm() //Draws Left Lower Arm
{
   glPushMatrix();
   glRotatef(-arm, 1.0, 0.0, 0.0);
   glTranslatef(0.0,1.0,0.0);
   glScalef(1.0,1.5,1.0);
   glColor3f(1.0, 1.0, 0.0);
   glutSolidCube(1.0f);
   glTranslatef(0.0,0.6,0);
   glScalef(1.0,0.2,2.0);
   glColor3f(0.0, 0.0, 1.0);
   glutSolidCube(1.0f);
   glPopMatrix();
}

void right_upper_arm() //Draws Right Upper Arm
{
   glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glRotatef(-arm, 1.0, 0.0, 0.0);
   glTranslatef(0.0,1.5,0.0);
   glScalef(1.0,2.0,1.0);
   glutSolidCube(1.0f);
   glPopMatrix();
}

void right_lower_arm() //Draws Right Lower Arm
{
   glPushMatrix();
   glRotatef(arm, 1.0, 0.0, 0.0);
   glTranslatef(0.0,1.0,0.0);
   glScalef(1.0,1.5,1.0);
   glColor3f(1.0, 1.0, 0.0);
   glutSolidCube(1.0f);
   glTranslatef(0.0,0.6,0);
   glScalef(1.0,0.2,2.0);
   glColor3f(0.0, 0.0, 1.0);
   glutSolidCube(1.0f);
   glPopMatrix();
}

void left_upper_leg() //Draws Left Upper Leg
{
   glPushMatrix();
   glRotatef(arm, 1.0, 0.0, 0.0);
   glTranslatef(-0.5,1.5,0.0);
   glScalef(1.0,3.0,1.0);
   glColor3f(0.0, 1.0, 0.0);
   glutSolidCube(1.0f); 
   glPopMatrix();
}

void left_lower_leg() //Draws Left Lower Leg
{
   glPushMatrix();
   glRotatef(-arm, 1.0, 0.0, 0.0);
   glTranslatef(-0.5,1.0,0.0);
   glTranslatef(0.0,-knee2,knee);
   glScalef(1.0,2.0,1.0);
   glColor3f(1.0, 1.0, 0.0);
   glutSolidCube(1.0f);
   glTranslatef(0.0, 0.6, 0.0);
   glScalef(1.0, 0.2, 2.0);
   glColor3f(0.0, 0.0, 1.0);
   glutSolidCube(1.0f);
   glPopMatrix();
}

void right_upper_leg() //Draws Right Upper Leg
{
   glPushMatrix();
   glRotatef(-arm, 1.0, 0.0, 0.0);
   glTranslatef(0.5,1.5,0.0);
   glScalef(1.0,3.0,1.0);
   glColor3f(0.0, 1.0, 0.0);
   glutSolidCube(1.0f); 
   glPopMatrix();
}

void right_lower_leg() //Draws Right Lower Leg
{
   glPushMatrix();
   glRotatef(arm, 1.0, 0.0, 0.0);
   glTranslatef(0.5,1.0,0.0);
   glTranslatef(0.0,-knee2,-knee);
   glScalef(1.0,2.0,1.0);
   glColor3f(1.0, 1.0, 0.0);
   glutSolidCube(1.0f);
   glTranslatef(0.0, 0.6, 0.0);
   glScalef(1.0, 0.2, 2.0);
   glColor3f(0.0, 0.0, 1.0);
   glutSolidCube(1.0f);
   glPopMatrix();
}

void floor() //Draws Floor
{
	glPushMatrix();

	glTranslatef(0.0,-1.0,5.0);
	glTranslatef(0.0,0.0,-move);
	glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINES);
    for (GLfloat i = -15; i <= 15; i += 0.2) {
         glVertex3f(i, 0, 15); glVertex3f(i, 0, -15);
         glVertex3f(15, 0, i); glVertex3f(-15, 0, i);
    }
    glEnd();

	glPopMatrix();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat) h / (GLfloat) w,
            10.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-10.0 * (GLfloat) w / (GLfloat) h,
            10.0 * (GLfloat) w / (GLfloat) h, 0.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void) //Draws robot by calling other body part drawin functions
{
	glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	gluLookAt(-3,1,2,0,0,0,0,1,0);
    glColor3f(1.0, 0.0, 0.0);

    glTranslatef(0.0,0.0,move);
	torso();
    glPushMatrix();

    glTranslatef(0.0, 5.0, 0.0);
    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(0.0, 0.6, 0.0);
    head();

    glPopMatrix();
    glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
    glTranslatef(2.5, 5.0, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
    left_upper_arm();

    glTranslatef(0.0, 2.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    left_lower_arm();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.5, 5.0, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
    right_upper_arm();

    glTranslatef(0.0, 2.0, 0.0);
    right_lower_arm();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5, 0.0, 0.0);
    glRotatef(180.0, 1.0, 0.0, 0.0);
    left_upper_leg();

    glTranslatef(0.0, 3.0, 0.0);
    left_lower_leg();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5, 0.0, 0.0);
    glRotatef(180.0, 1.0, 0.0, 0.0);
    right_upper_leg();

    glTranslatef(0.0, 3.0, 0.0);
    right_lower_leg();

    glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0,-5.2,0.0);
	floor();

    glPopMatrix();
	glFlush();
    glutSwapBuffers();
}
void main(int argc, char **argv)
{
    glutInit(&argc, argv);
	arm=0; move=0; a=0; b=0;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // no need to call this
    glutInitWindowSize(500, 500);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glutCreateWindow("CG Assignment 2: Walking Robot");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc( process_key );
    glutMainLoop();
}