// header files
#include <GL/freeglut.h>

// global variable declarations
bool bIsFullScreen = false;

// GLenum currenttype = GL_POLYGON;

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
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Logo1");

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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
	glColor3f(1, 0, 0); // Red

	glBegin(GL_TRIANGLES); // Triangle 1

	glVertex3f(-0.25f, 0.25f, 0.0f);
	glVertex3f(-0.25f, -0.25f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);

	glEnd();	

	glBegin(GL_TRIANGLES); // Triangle 3

	glVertex3f(0.25f, 0.25f, 0.0f);
	glVertex3f(0.25f, -0.25f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLES); // Triangle 2

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLES); // Triangle 4

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.25f, -0.25f, 0.0f);
	glVertex3f(0.25f, -0.25f, 0.0f);

	glEnd();
}





