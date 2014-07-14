#include <GLUT/glut.h>

void init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    double aspect = (double)viewport[2] / (double)viewport[3];
    gluPerspective(60, aspect, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // move back a bit
    glTranslatef( 0, 0, -35 );

    static float angle = 0;
    angle += 1.0f;

    glPushMatrix();
	glTranslatef(0,0,0);
	glRotatef(0, 0.0, 0.0, 0.0);  //only rotates each cube, not entire figure on axis.
	glColor3ub(0, 238, 0);
	glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-5,0,0); //-x
	glRotatef(0, 0.0, 0.0, 0.0);
	glColor3ub(0, 238, 0);
	glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0,5,0);
	glRotatef(0, 0.0, 0.0, 0.0);
	glColor3ub(0, 238, 0);
	glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(5,5,0);
	glRotatef(0, 0.0, 0.0, 0.0);   //if 2*angle, twice as fast.
	glColor3ub(0, 238, 0);
	glutSolidCube(5);
    glPopMatrix();

    /*glPushMatrix();
	glTranslatef(-10,-10,0);
	glRotatef(angle, 0.1, 0.2, 0.5);
	glColor3ub(255,255,0);
	glutSolidCube(5);
    glPopMatrix(); */

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

void timer(int extra)
{
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Green __--“)

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    init();

    glutMainLoop();
    return 0;
}

