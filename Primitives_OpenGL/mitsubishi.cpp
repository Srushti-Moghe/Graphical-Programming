// header files
#include <GL/freeglut.h>
// #include <GL/gl.h>
// #include <GL/glut.h>

// global variable declarations
bool bIsFullScreen = false;

void Triangle(void);

// entry-point function
int main(int argc, char* argv[])
{
	// function declarations
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);

	// code
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Logo2");

	gluOrtho2D(-5, 5, -5, 5);

	initialize();
 
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);
	

	glutMainLoop();

	return(0);
}
void initialize(void)
{
	// code
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);		// White Background
}
void resize(int width, int height)
{
	// code
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();

	Triangle();	

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bIsFullScreen == false)
		{
			glutFullScreen();
			bIsFullScreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bIsFullScreen = false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_RIGHT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}

}

void uninitialize(void)
{
	// code
}

// Triangle()
void Triangle(void)
{	
	// Main red triangle side length 3, center at origin
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f, -1.732050, 0.0f);
	glVertex3f(-3.0f, -1.732050f, 0.0f);
	glVertex3f(0.0f, 3.464101f, 0.0f);
	glEnd();

	// top right white triangle side length 1
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.732050f, 0.0f);
	glEnd();

	// top left white triangle side length 1
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.732050f, 0.0f);
	glEnd();

	// bottom triangle side length 1
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.732050f, 0.0f);
	glVertex3f(1.0f, -1.732050f, 0.0f);
	glEnd();

	glFlush();
}





