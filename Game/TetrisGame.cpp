#include "TetrisGame.h"
#include <stdlib.h>
#include <Windows.h>
#include <glut.h>
#include "GameSpace.h"
#include "Tetronimo.h"


TetrisGame::TetrisGame(void)
{
	state = 0; // state of program. 0 is title screen, 1 is game for now
	z = 0.0f; // z of cube
	cubeWidth = .25f; // scaling factor for basically everything drawn
	xPos = 0.0f; // x of cube
	yPos = 0.0f; // y of cube
	gamespace = new GameSpace(); // the environment variable. Pointer
	tet = new Tetronimo();
	gameover = false; // will be used to detect loss, not implemented
}


TetrisGame::~TetrisGame(void)
{
}

// Draws the falling tetronimo (currently cube) TODO
void TetrisGame::drawTetronimo()
{
	// ---------------------------------------------------------------
	// ------ Drawing of tetronimo (cube for now) --------------------
	// ---------------------------------------------------------------
	tet->setXYZ(xPos, yPos, z);
	std::vector<int> box = tet->boundingBox();

	if(box[0] < -2)
		xPos += (-2-box[0]);
	if(box[1] < -2)
		yPos += (-2-box[1]);
	if(box[2] < 0)
		z += (0-box[2]);
	if(box[3] > 2)
		xPos += (2-box[3]);
	if(box[4] > 2)
		yPos += (2-box[4]);
	if(box[5] > 11)
		z += (11-box[5]);
	tet->setXYZ(xPos, yPos, z);
	tet->draw();
	/*
	glLoadIdentity(); // Reset coordinates for drawing
	glTranslatef(0.0, 0.0, -1.0f); // push it 1 in
	// bounds checking
	if(z < 0.0)
		z = 0.0;
	else if (z > 11)
		z = 11;
	if(xPos < -2)
		xPos = -2;
	if(xPos > 2)
		xPos = 2;
	if(yPos < -2)
		yPos = -2;
	if(yPos > 2)
		yPos = 2;

	// set the color to white
	glColor3f(1.0, 1.0, 1.0);
	// move to proper location
	glTranslatef(xPos*cubeWidth, yPos*cubeWidth, (-z-.5)*cubeWidth);
	// draw wire cube. Eventually want transluscent cube TODO
	glutWireCube(cubeWidth);
	*/
	// ---------------------------------------------------------------
	// ------ End drawing of tetronimo -------------------------------
	// ---------------------------------------------------------------

}

// Display basic title screen, code from Jonathan
void TetrisGame::displayTitle (void) {
  glClearColor(0.0f, 0.0f, 0.5f, 0.0f); // Clear the background of our window to red  
  glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
  glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  
  glTranslatef(0,0,-1.0f);
  int i=0;
  char *title = "3D TETRIS";
  char *authors = "By Matt Nulle, Jonathan Alvarez, and Camilla Tassi";
  char *instructions = "Instructions";
  char *instructions2 = "Press 'n' to start a new game";
  char *instructions3 = "Press 'o' to change the options";
  char *instructions4 = "Press 'p' to exit the game";

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

void TetrisGame::display (void) {  
	
	// state machine
	switch (state)
	{
	case 0: // display title
		displayTitle();
		break;
	case 1:
		// play game
		gamespace->checkAndClear(); // Check if should clear a level
		gamespace->draw(cubeWidth); // draw the environment
	//	displayBox();
		drawTetronimo(); // draw the tetronimo

		break;
	}
	glFlush(); // Flush the OpenGL buffers to the window  
}  

void TetrisGame::keyPressed (unsigned char key, int x, int y) {  
	// detect various key presses
	switch (key) {
	case 'q':
		tet->rotateX();
		break;
	case 'w':
		tet->rotateY();
		break;
	case 'e':
		tet->rotateZ();
		break;
	case 'a':
		tet->rotateX();
		tet->rotateX();
		tet->rotateX();
		break;
	case 's':
		tet->rotateY();
		tet->rotateY();
		tet->rotateY();
		break;
	case 'd':
		tet->rotateZ();
		tet->rotateZ();
		tet->rotateZ();
		break;
	case ' ':
		//while(z <= 11 && !gamespace->getSpace(xPos+2, yPos+2, z))
		while(z <= 11 && !gamespace->isOccupied(tet))
		{
			z++;
			tet->setXYZ(xPos, yPos, z);
			glutPostRedisplay();
		}
		if(z <= 0)
		{
			gameover = true;
		}
		else
		{
			//gamespace->setSpace(xPos+2, yPos+2, z-1, 1);
			tet->setXYZ(xPos, yPos, z-1);
			gamespace->setSpaces(tet, 1);
			tet->~Tetronimo();
			tet = new Tetronimo();
			xPos = 0; yPos = 0; z = 0;
			tet->setXYZ(xPos, yPos, z);
		}
		break;
	case 'n':
		if(state == 0) 
			state = 1;
		else 
			state = 0;
		break;
	case 'p':
		exit(0);
		break;
	case 't':
		gamespace->setSpace(xPos+2, yPos+2, z, 1);
		xPos = 0; yPos = 0; z = 0;
		break;

	}
	glutPostRedisplay(); // re-draw window
}  

void TetrisGame::specialPressed (int key, int x, int y) {  
	switch (key) {
	case GLUT_KEY_UP:
		yPos += 1;
		break;
	case GLUT_KEY_DOWN:
		yPos -= 1;
		break;
	case GLUT_KEY_LEFT:
		xPos -= 1;
		break;
	case GLUT_KEY_RIGHT:
		xPos += 1;
		break;
	

	}
	glutPostRedisplay(); // re-draw window
}  

void TetrisGame::onTimer()
{
	switch (state)
	{
	case 0: // title screen, do nothing
		break;
	case 1: // game
		dropTetronimo();
		break;
	}
}

// returns a 1 if it set the blocks, 0 if just moved down
int TetrisGame::dropTetronimo()
{
	z++; // drop the tetronimo
	tet->setXYZ(xPos, yPos, z);
	if(z > 11 || gamespace->isOccupied(tet)) // if hit bottom or a block
	{
		//gamespace->setSpace(xPos+2, yPos+2, z-1, 1); // add to gamespace
		tet->setXYZ(xPos, yPos, z-1);
		gamespace->setSpaces(tet, 1);
		tet->~Tetronimo();
		tet = new Tetronimo();
		xPos = 0; yPos = 0; z = 0;
		tet->setXYZ(xPos, yPos, z);
		glutPostRedisplay();
		return 1;
	}
	glutPostRedisplay(); // redraw
	return 0;
}
