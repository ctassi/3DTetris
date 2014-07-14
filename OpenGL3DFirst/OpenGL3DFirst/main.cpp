#include <glut.h>
bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)  
GLfloat z = -5.0f;
GLfloat theta = 0.0f;
GLfloat theta2 = 0.0f;

void keyOperations (void) {	
	char *text = "This is a test";
    for (int i = 0; i < 14; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

	if (keyStates['a']) { // If the 'a' key has been pressed  
		z += .5f;
	}
	if (keyStates['z']) {
		z -= .5f;
	}
	if(keyStates['s']) {
		theta += 90.0f;
	}
	if(keyStates['x']) {
		theta -= 90.0f;
	}
	if(keyStates['d']) {
		theta2 += 90.0f;
	}
	if(keyStates['c']) {
		theta2 -= 90.0f;
	}

}  
  
void display (void) {  
	
  
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our window to red  
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  

	keyOperations();  

	glRotatef(theta, 0.0f, 1.0f, z);

	glTranslatef(-1.0f, 0.0f, z); // Push eveything 5 units back into the scene, otherwise we won't see the primitive  
	glColor4f(1.0, 1.0, 1.0, 0.1);
	glutWireCube(2.0f); // Render the primitive
	glTranslatef(2.0f, 0.0f, 0.0f); // Push eveything 5 units back into the scene, otherwise we won't see the primitive  
	glutWireCube(2.0f); // Render the primitive
	glTranslatef(-1.0f, 0.0f, z);
	glutWireCube(1.0f);

	/*char *text = "This is a test";
    for (int i = 0; i < 14; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}*/

	glFlush(); // Flush the OpenGL buffers to the window  
}  
  
void reshape (int width, int height) {  
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window  
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed  
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)  
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes  
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly  
  
}  
  
void keyPressed (unsigned char key, int x, int y) {  
	keyStates[key] = true; // Set the state of the current key to pressed  
	glutPostRedisplay();
}  
  
void keyUp (unsigned char key, int x, int y) {  
	keyStates[key] = false; // Set the state of the current key to not pressed  
	glutPostRedisplay();
}  
  
int main (int argc, char **argv) {  
	glutInit(&argc, argv); // Initialize GLUT  
	glutInitDisplayMode (GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)  
	glutInitWindowSize (1000, 500); // Set the width and height of the window  
	glutInitWindowPosition (100, 100); // Set the position of the window  
	glutCreateWindow ("Your first OpenGL Window"); // Set the title for the window  
  
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering  
  
	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping  
  
	glutIgnoreKeyRepeat(true);
	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
	glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events  
  
	glutMainLoop(); // Enter GLUT's main loop  
}  