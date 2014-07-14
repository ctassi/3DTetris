#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gl/glut.h>

bool* keyStates = new bool[256];


void keyOperations(unsigned char key, int x, int y) {
  bool* keyStates = new bool[256];
  keyStates[key] = true; // Set the state of the current key to pressed
  glutPostRedisplay();

  switch (key) {
  case 's':
    exit(0);
    break;
  case 'o':
    exit(0);
    break;
  case 'q':
    exit(0);
    break;
  }
  
}
void titleText (void) {
  int i=0;
  char *title = "3D TETRIS";
  char *authors = "By Matt Nulle, Jonathan Alvarez, and Camilla Tassi";
  char *instructions = "Instructions";
  char *instructions2 = "Press 's' to start a new game";
  char *instructions3 = "Press 'o' to change the options";
  char *instructions4 = "Press 'q' to exit the game";

  glRasterPos2f(-0.25, 0.75);
  for (i=0; i < 9; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
  }
  glRasterPos2f(-0.70, 0.65);
  for (i=0;  i< 50; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, authors[i]);
  }
  glRasterPos2f(-0.25, 0.35);
  for (i=0; i < 12; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, instructions[i]);
  }
  glRasterPos2f(-0.50, 0.15);
  for (i=0; i < 32; i ++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, instructions2[i]);
  }
  glRasterPos2f(-0.50, -0.05);
  for (i=0; i<32; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, instructions3[i]);
  }
  glRasterPos2f(-0.50, -0.25);
  for (i=0; i<32; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, instructions4[i]);
  }
  
}
void display(void) {
  glClearColor(0.0f, 0.0f, 0.5f, 0.0f); // Clear the background of our window to red  
  glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
  glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  

  titleText();

  glFlush();
}
int main (int argc, char **argv) {  
  glutInit(&argc, argv); // Initialize GLUT  
  glutInitDisplayMode (GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)  
  glutInitWindowSize (700, 700); // Set the width and height of the window  
  glutInitWindowPosition (100, 100); // Set the position of the window  
  glutCreateWindow ("Your first OpenGL Window"); // Set the title for the window

  glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering  
  glutKeyboardFunc(keyOperations);

  glutMainLoop();
}
