// header files
#include <GL/freeglut.h>


// global variable declarations
bool bIsFullScreen = false;

typedef struct
{
	float R, G, B, Y;
}color;

typedef struct
{
	float X, Y;
}coords;

void Square(coords, coords, color);

// void Square(void);
// void GreenSquare(void);
// void BlueSquare(void);
// void YellowSquare(void);

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
	glutCreateWindow("House");

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

	coords top_left;
	top_left.X = -1;
	top_left.Y = 1;

	coords bottom_right;
	bottom_right.X = 0;
	bottom_right.Y = 0;

	color mycolor;
	mycolor.R = 1; // Red
	mycolor.G = 0;
	mycolor.B = 0;

	Square(top_left, bottom_right, mycolor);

	top_left.X = 0;
	top_left.Y = 1;

	bottom_right.X = 1;
	bottom_right.Y = 0;

	mycolor.R = 0; // Green
	mycolor.G = 1;
	mycolor.B = 0;

	Square(top_left, bottom_right, mycolor);

	top_left.X = -1;
	top_left.Y = 0;

	bottom_right.X = 0;
	bottom_right.Y = -1;

	mycolor.R = 0; // Blue
	mycolor.G = 0;
	mycolor.B = 1;

	Square(top_left, bottom_right, mycolor);

	top_left.X = 0;
	top_left.Y = 0;

	bottom_right.X = 1;
	bottom_right.Y = -1;

	mycolor.R = 1; // Yellow
	mycolor.G = 1;
	mycolor.B = 0;

	Square(top_left, bottom_right, mycolor);
	
	// Square();
	// GreenSquare();
	// BlueSquare();
	// YellowSquare();

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

// Square
void Square(coords top_left, coords bottom_right, color col)
{
	glColor3f(col.R, col.G, col.B); 

	glBegin(GL_POLYGON);  

	glVertex3f(top_left.X, top_left.Y, 0);
	glVertex3f(bottom_right.X, top_left.Y, 0);
	glVertex3f(bottom_right.X, bottom_right.Y, 0);
	glVertex3f(top_left.X, bottom_right.Y, 0);

	glEnd();
}














