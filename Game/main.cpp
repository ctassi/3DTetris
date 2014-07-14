/*
 * Main file for 3D Tetris
 * Couldn't break it into subclasses due to unknown bug with textures
 * Commented as well as possible to make readable.
 */

#include <stdlib.h>
#include <Windows.h>
#include <glut.h> // needs to come after stdlib and Windows to prevent an error from both defining a function/variable
#include <time.h>
#include "GameSpace.h" // Environment around the falling tetronimo

#include "Tetronimo.h"
#include "Line.h"
#include "Lpiece.h"
#include "S.h"
#include "square.h"
#include "T.h"
#include "zS.h"
#include "zS3.h"
#include "zS5.h"

#include "SOIL.h"

#include <MMsystem.h> //needed for sound

#pragma comment(lib, "Winmm.lib") //needed for sound

// Game variables
bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255) - stores key states. Not used now
int gameState = 0; // state of program. 0 is title screen, 1 is game, 2 is gameover, 4 is options screen, 5 is instructions
GLfloat z = 0.0f; // z of cube
GLfloat cubeWidth = .25f; // scaling factor for basically everything drawn
GLfloat xPos = 0.0f; // x of cube
GLfloat yPos = 0.0f; // y of cube
GameSpace* gamespace; // the environment variable. Pointer
Tetronimo* tet; // Tetronimo pointer
bool gameover = false; // will be used to detect loss, not implemented
int initSpeed = 1000;
int	speed = 1000; // lower is faster. Starts at 1000 milliseconds
int score = 0; // Score
int totalLines = 0; // total lines cleared
bool sound = false; // sound on or off, starts off

void keyOperations (void) {
	// Empty function unless we use keyStates variable
}

/*
// Obsolete function with introduction of GameSpace, kept just in case needed for debugging
void displayBox(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our window to black
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations

	keyOperations();
	// ---------------------------------------------------------------
	// ------ Drawing of box environment -----------------------------
	// ---------------------------------------------------------------

	int count = 0; // number of rectangles drawn (for alternating color purposes)
	glTranslatef(0.0, 0.0, -1.0f); // start drawing a little ways in.
	for(int i = 0; i < 12; i++) // For each layer
	{
		for(int j = 0; j < 5; j++) // top wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0f, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, -(cubeWidth * 2.5), 0.0 - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, -(cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, -(cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, -(cubeWidth * 2.5), 0.0 - cubeWidth*i);
			glEnd();
		}
		count++; // to alternate colors properly
		for(int j = 0; j < 5; j++) // left wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, 0.0 - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, 0.0 - cubeWidth*i);
			glEnd();
		}
		count++; // to alternate colors properly
		for(int j = 0; j < 5; j++) // bottom wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, (cubeWidth * 2.5), 0.0 - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, (cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, (cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, (cubeWidth * 2.5), 0.0 - cubeWidth*i);
			glEnd();
		}
		count++; // to alternate colors properly
		for(int j = 0; j < 5; j++) // right wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, 0.0 - cubeWidth*i);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, 0.0 - cubeWidth*i);
			glEnd();
		}
	}
	// Draw the bottom of the box
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*i, -(cubeWidth * 2.5) + cubeWidth*j, -12*cubeWidth);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*i, -(cubeWidth * 2.5) + cubeWidth*j, -12*cubeWidth);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*i, -(cubeWidth * 1.5) + cubeWidth*j, -12*cubeWidth);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*i, -(cubeWidth * 1.5) + cubeWidth*j, -12*cubeWidth);
			glEnd();
		}
	}
	// ---------------------------------------------------------------
	// ------ End drawing of box environment -------------------------
	// ---------------------------------------------------------------
}
*/

// Draws the falling tetronimo
void drawTetronimo()
{
	// ---------------------------------------------------------------
	// ------ Drawing of tetronimo (cube for now) --------------------
	// ---------------------------------------------------------------
	tet->setXYZ(xPos, yPos, z); // make sure the tetronimo's coordinates are up to date.

	// make sure it isn't going out of bounds
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

    // re-set the coordinates in case of changes
	tet->setXYZ(xPos, yPos, z);
	tet->draw(); // draw
}

// Display title screen.
void titleText (void) {
	glClearColor(0.0f, 0.0f, 0.5f, 0.0f); // Clear the background of our window to blue
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
	glTranslatef(0,0,-1.0f); // move back into the screen a bit
	GLuint tex_2d = SOIL_load_OGL_texture // load the texture
	(
		"3D Title Screen.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT
	);
	glBindTexture(GL_TEXTURE_2D, tex_2d); // bind the texture so the cubes will have border
	// draw square over the screen
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-.615, -.58, 0);

		glTexCoord2f(0, 1);
		glVertex3f(-.615, .58, 0);

		glTexCoord2f(1, 1);
		glVertex3f(.615, .58, 0);

		glTexCoord2f(1, 0);
		glVertex3f(.615, -.58, 0);
	glEnd();
	glDeleteTextures(1, &tex_2d); // delete the texture to free memeory
}

// Display options screen
void displayOptions (void) {
	glClearColor(0.0f, 0.0f, 0.5f, 0.0f); // Clear the background of our window to blue
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
	glTranslatef(0,0,-1.0f); // drop back into the screen a bit
	GLuint tex_2d; // just declare to start
	char* filename; // filename to find picture
	switch(initSpeed) // pick picture based on current settings
	{
	case 1000: // easy highlighted
		{
			if(sound) // on
				filename = "images/3D Options EON.png";
			else // off
				filename = "images/3D Options EOFF.png";
		}
		break;
	case 800: // medium highlighted
		{
			if(sound) // on
				filename = "images/3D Options MON.png";
			else // off
				filename = "images/3D Options MOFF.png";
		}
		break;
	case 600: // hard highlighted
		{
			if(sound) // on
				filename = "images/3D Options HON.png";
			else // off
				filename = "images/3D Options HOFF.png";
		}
		break;
	}
	tex_2d = SOIL_load_OGL_texture
	(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT
	); // load the image as specified above
	glBindTexture(GL_TEXTURE_2D, tex_2d); // bind the texture so the cubes will have border
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-.615, -.58, 0);

		glTexCoord2f(0, 1);
		glVertex3f(-.615, .58, 0);

		glTexCoord2f(1, 1);
		glVertex3f(.615, .58, 0);

		glTexCoord2f(1, 0);
		glVertex3f(.615, -.58, 0);
	glEnd();
	glDeleteTextures(1, &tex_2d); // delete the texture to free memeory
}

// Display instructions screen
void displayInstructions (void) {
	glClearColor(0.0f, 0.0f, 0.5f, 0.0f); // Clear the background of our window to blue
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
	glTranslatef(0,0,-1.0f); // drop back into the screen a bit
	GLuint tex_2d = SOIL_load_OGL_texture
	(
		"images/New3DInstruct.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT
	); // load the image
	glBindTexture(GL_TEXTURE_2D, tex_2d); // bind the texture so the cubes will have border
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-.615, -.58, 0);

		glTexCoord2f(0, 1);
		glVertex3f(-.615, .58, 0);

		glTexCoord2f(1, 1);
		glVertex3f(.615, .58, 0);

		glTexCoord2f(1, 0);
		glVertex3f(.615, -.58, 0);
	glEnd();
	glDeleteTextures(1, &tex_2d); // delete the texture to free memeory
}

// Display a screen at the end of the game.
void gameOverScreen()
{
	glClearColor(0.0f, 0.0f, 0.5f, 0.0f); // Clear the background of our window to blue
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
	glTranslatef(0,0,-1.0f); // drop back into the screen
	GLuint tex_2d = SOIL_load_OGL_texture // load image
	(
		"images/GameOver.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT
	);
	glBindTexture(GL_TEXTURE_2D, tex_2d); // bind the texture so the cubes will have border
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-.615, -.58, 0);

		glTexCoord2f(0, 1);
		glVertex3f(-.615, .58, 0);

		glTexCoord2f(1, 1);
		glVertex3f(.615, .58, 0);

		glTexCoord2f(1, 0);
		glVertex3f(.615, -.58, 0);
	glEnd();
	glDeleteTextures(1, &tex_2d); // delete the texture to free memeory
}

// create a new tetronimo
void newTetronimo()
{
	int piece = rand() % 8; // random number 0-7
	// make a different piece depending on value of random number
	switch(piece)
	{
	case 0:
		tet = new Line();
		break;
	case 1:
		tet = new Lpiece();
		break;
	case 2:
		tet = new Spiece();
		break;
	case 3:
		tet = new Square();
		break;
	case 4:
		tet = new Tpiece();
		break;
	case 5:
		tet = new zS5piece();
		break;
	case 6:
		tet = new zS3piece();
		break;
	case 7:
		tet = new zSpiece();
		break;
	}
}

// Display the game as currently set
void display (void) {

	int i, linesCleared;
	char message[100];
	// state machine
	switch (gameState)
	{
	case 0: // display title
		titleText();
		break;
	case 1:
		// play game
		linesCleared = gamespace->checkAndClear(); // Check if should clear a level
		score += 100 * linesCleared;
		totalLines += linesCleared;
		speed = initSpeed - 100 * (int)(totalLines/10);
		gamespace->draw(cubeWidth); // draw the environment

		drawTetronimo(); // draw the tetronimo

		// display line count and score. Score first
		itoa(score, message, 10);
		glLoadIdentity();
		glTranslatef(0.0, 0.0, -1.0);
		glRasterPos2f(0.5, 0.5);
		for (i=0; i < 9; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
			message[i] = ' ';
		}
        // display line count
		itoa(totalLines, message, 10);
		glRasterPos2f(-0.5, 0.5);
		for (i=0; i < 9; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
		}
		break;
	case 2: // game over
		gameOverScreen();
		break;
	case 3: // pause, do nothing
		break;
	case 4: // display options screen
		displayOptions();
		break;
	case 5: // display instructions screen
		displayInstructions();
		break;
	}
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
	// detect various key presses
	switch (key) {
	case 'q': // rotate x
		tet->rotateX();
		if(gamespace->isOccupied(tet)) // if moving into other blocks
		{
			tet->rotateX();
			tet->rotateX();
			tet->rotateX();
		}
		break;
	case 'w': // rotate y
		tet->rotateY();
		if(gamespace->isOccupied(tet)) // if moving into other blocks
		{
			tet->rotateY();
			tet->rotateY();
			tet->rotateY();
		}
		break;
	case 'e': // rotate z
		tet->rotateZ();
		if(gamespace->isOccupied(tet)) // if moving into other blocks
		{
			tet->rotateZ();
			tet->rotateZ();
			tet->rotateZ();
		}
		break;
	case 'a': // rotate x other way
		tet->rotateX();
		tet->rotateX();
		tet->rotateX();
		if(gamespace->isOccupied(tet)) // if moving into other blocks
		{
			tet->rotateX();
		}
		break;
	case 's': // rotate y other way
		tet->rotateY();
		tet->rotateY();
		tet->rotateY();
		if(gamespace->isOccupied(tet)) // if moving into other blocks
		{
			tet->rotateY();
		}
		break;
	case 'd': // rotate z other way
		tet->rotateZ();
		tet->rotateZ();
		tet->rotateZ();
		if(gamespace->isOccupied(tet)) // if moving into other blocks
		{
			tet->rotateZ();
		}
		break;
	case ' ': // drop the tetronimo
		while(z <= 11 && !gamespace->isOccupied(tet)) // while not at the bottom or hitting another block
		{
			z++; // drop the tetronimo
			score += 2; // double score per drop for hard drop
			tet->setXYZ(xPos, yPos, z); // set the tetronimo to the new person
			glutPostRedisplay();
		}
		if(z <= 0) // if still at the top of the arena
		{
			gameState = 2; // game over
		}
		else // haven't lost yet
		{
			tet->setXYZ(xPos, yPos, z-1); // set to previous block (since we just went into the bottom or a block)
			gamespace->setSpaces(tet, 1); // set the spaces to filled
			tet->~Tetronimo(); // destroy the old tetronimo
			newTetronimo(); // make a new one
			xPos = 0; yPos = 0; z = 0; // default the location
			tet->setXYZ(xPos, yPos, z); // make sure it's all 0s
		}
		break;
	case 'n': // switch between menu and game without restarting game
		if(gameState == 0)
			gameState = 1;
		else
			gameState = 0;
		break;
	case 'p': // pause the game and restart game
		if(gameState == 1)
			gameState = 3;
		else if(gameState == 3)
			gameState = 1;
		break;
	case 27: // esc key, quit
		exit(0);
		break;
	case 'i': // go to instruction screen or to menu screen
		if(gameState == 5)
			gameState = 0;
		else
			gameState = 5;
		break;
	case 'o': // go to option screen or to menu
		if(gameState == 4)
			gameState = 0;
		else
			gameState = 4;
		break;
	}
	tet->setXYZ(xPos, yPos, z); // set the xyz just in case anything's changed

	// Make sure it hasn't gone out of bounds
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
	glutPostRedisplay(); // re-draw window
}

void specialPressed (int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP: // up arrow
		// Move up unless already occupied
		yPos += 1;
		if(gamespace->isOccupied(tet))
			yPos -=1;
		tet->setXYZ(xPos, yPos, z);
		break;
	case GLUT_KEY_DOWN: // down arrow
        // Move down unless already occupied
		yPos -= 1;
		if(gamespace->isOccupied(tet))
			yPos +=1;
		tet->setXYZ(xPos, yPos, z);
		break;
	case GLUT_KEY_LEFT: // left arrow
	    // Move left unless already occupied
		xPos -= 1;
		if(gamespace->isOccupied(tet))
			xPos +=1;
		tet->setXYZ(xPos, yPos, z);
		break;
	case GLUT_KEY_RIGHT: // right arrow
	    // Move right unless already occupied
		xPos += 1;
		if(gamespace->isOccupied(tet))
			xPos -=1;
		tet->setXYZ(xPos, yPos, z);
		break;


	}
	tet->setXYZ(xPos, yPos, z);
	// Make sure not out of bounds
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
	glutPostRedisplay(); // re-draw window
}

// interpret mouse clicks, only checks in menu states
void mouseClick(int button, int state, int x, int y)
{
    // main menu
	if(gameState == 0 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(150 <= x && x <= 725 && 255 <= y && y <= 337) // New Game
		{
			score = 0;
			totalLines = 0;
			xPos = yPos = z = 0;
			newTetronimo();
			gamespace->resetSpace();
			gameState = 1;
		}
		if(150 <= x && x <= 725 && 375 <= y && y <= 460) // Instructions
		{
			gameState = 5;
		}
		if(150 <= x && x <= 725 && 500 <= y && y <= 580) // Options
		{
			gameState = 4;
		}

	}
	// options
	else if(gameState == 4 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(505 <= y && y <= 570 && 379 <= x && x <= 505) // sound on
		{
			sound = true;
			PlaySound(TEXT("C:\\Tetris.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);

		}
		else if(505 <= y && y <= 570 && 549 <= x && x <= 676) // sound off
		{
			sound = false;
			PlaySound(0, 0, 0);
		}
		else if(337 <= y && y <= 404 && 366 <= x && x <= 502) // easy
		{
			initSpeed = 1000;
		}
		else if(337 <= y && y <= 404 && 526 <= x && x <= 663) // medium
		{
			initSpeed = 800;
		}
		else if(337 <= y && y <= 404 && 676 <= x && x <= 813) // hard
		{
			initSpeed = 600;
		}
		else if(668 <= y && y <= 729 && 692 <= x && x <= 818) // back to menu
		{
			gameState = 0;
		}
	}
	// instructions
	else if(gameState == 5 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(643 <= x && x <= 832 && 672 <= y && y <= 742) // back
		{
			gameState = 0;
		}
	}

	glutPostRedisplay();
}

// Timer function for dropping tetronimos
void Timer(int value)
{
	switch (gameState)
	{
	case 0: // title screen, do nothing
		break;
	case 1: // game
		tet->setXYZ(xPos, yPos, z); // make sure tet is up to date
		// make sure it's in bounds
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

		z++; // drop the tetronimo
		score += 1;
		tet->setXYZ(xPos, yPos, z);
		if(z > 11 || gamespace->isOccupied(tet)) // if hit bottom or a block
		{
			if(z <= 1) // we're at the top, game over
				gameState = 2;
			tet->setXYZ(xPos, yPos, z-1); // set the coordinates, redundant
			gamespace->setSpaces(tet, 1); // fill the spaces
			tet->~Tetronimo(); // destroy the tetronimo
			newTetronimo(); // create a new tetronimo
			xPos = 0; yPos = 0; z = 0; // reset coords
			tet->setXYZ(xPos, yPos, z); // reset tet coords
		}
		glutPostRedisplay(); // redraw
		break;
	}
	glutTimerFunc(speed, Timer, value); // run again in a second
}

int main (int argc, char **argv) {
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode (GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize (850, 800); // Set the width and height of the window
	glutInitWindowPosition (200, 50); // Set the position of the window
	glutCreateWindow ("3D Tetris"); // Set the title for the window

	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering

	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping

	glutIgnoreKeyRepeat(true); // This makes it so you have to click each time, not hold the key


	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
	glutSpecialFunc(specialPressed);
	glutMouseFunc(mouseClick);

	glutTimerFunc(speed,Timer,0); // initialize timer function to go off after 1 second
	gamespace = new GameSpace(); // initialize gamespace
	newTetronimo();
	if(sound)
		PlaySound(TEXT("C:\\Tetris.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	else
		PlaySound(0, 0, 0);
	srand(time(NULL));
	glutMainLoop(); // Enter GLUT's main loop
}
