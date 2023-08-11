// header files
#include <GL/freeglut.h>

#define _USE_MATH_DEFINES
#include <math.h>

// global variable declarations
bool bIsFullScreen = false;


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
	glutCreateWindow("Smiley");

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

	// Yellow circle
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);

	float radius = 0.50f;
	for (int i = 0; i < 1000; i++)
	{
		float angle = 2.0f * M_PI * i / 1000;
		glVertex2f(radius * cos(angle), radius * sin(angle));		// centering circle
	}
	glEnd();

	// Left Eye	
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);

	float radius_1 = 0.12f;
	float x_centre_1 = -0.20f;
	float y_centre_1 = 0.20f;
	for (int i = 0; i < 1000; i++)
	{
		float angle = 2.0f * M_PI * i / 1000;
		glVertex2f(x_centre_1 + radius_1 * cos(angle), y_centre_1 + radius_1 * sin(angle));
	}
	glEnd();

	// Right Eye	
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);

	float radius_2 = 0.12f;
	float x_centre_2 = 0.20f;
	float y_centre_2 = 0.20f;
	for (int i = 0; i < 1000; i++)
	{
		float angle = 2.0f * M_PI * i / 1000;
		glVertex2f(x_centre_2 + radius_2 * cos(angle), y_centre_2 + radius_2 * sin(angle));
	}
	glEnd();

	// wink	
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);

	float radius_3 = 0.10f;
	float x_centre_3 = 0.20f;
	float y_centre_3 = 0.20f;
	for (int i = 0; i < 1000; i++)
	{
		float angle = 1.0f * M_PI * i / 1000;
		glVertex2f(x_centre_3 + radius_3 * cos(angle), y_centre_3 + radius_3 * sin(angle));
	}
	glEnd();

	// smile
	
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);

	float radius_4 = 0.30f;
	float x_centre_4 = 0.00f;
	float y_centre_4 = -0.15f;
	for (int i = 0; i < 1000; i++)
	{
		float angle = M_PI + (1.0f * M_PI * i / 1000);
		glVertex2f(x_centre_4 + radius_4 * cos(angle), y_centre_4 + radius_4 * sin(angle));
	}
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



















