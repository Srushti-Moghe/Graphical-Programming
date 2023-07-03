// header files
#include <GL/freeglut.h>

#define _USE_MATH_DEFINES
#include <math.h>

// global variable declarations
bool bIsFullScreen = false;

GLenum currenttype = GL_POLYGON;


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

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangular Tree");

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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
	glLoadIdentity();

	glColor3f(0.5f, 0.35f, 0.5f); 
	glBegin(GL_POLYGON); // Rectangle - 1

	glVertex3f(0.3f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.3f, 0.0f);
	glVertex3f(0.4f, 0.3f, 0.0f);
	glVertex3f(0.4f, 0.0f, 0.0f);
		
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON); // Triangle - 3

	glVertex3f(0.1f, 0.3f, 0.0f);
	glVertex3f(0.35f, 0.6f, 0.0f);
	glVertex3f(0.6f, 0.3f, 0.0f);

	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f); 
	glBegin(GL_POLYGON); // Triangle - 2

	glVertex3f(0.2f, 0.6f, 0.0f);
	glVertex3f(0.35f, 0.8f, 0.0f);
	glVertex3f(0.5f, 0.6f, 0.0f);

	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f); 
	glBegin(GL_POLYGON); // Triangle - 1

	glVertex3f(0.25f, 0.8f, 0.0f);
	glVertex3f(0.35f, 0.9f, 0.0f);
	glVertex3f(0.45f, 0.8f, 0.0f);

	glEnd();

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















