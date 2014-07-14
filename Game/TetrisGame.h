/*
 * Failed attempt to organize code.
 * For some unknown reason, textures stopped working when lines were transferred into this class.
 * Currently not in use or commented.
 */

#pragma once
#include <stdlib.h>
#include <Windows.h>
#include <glut.h>
#include "GameSpace.h"
#include "Tetronimo.h"

class TetrisGame
{
public:
	TetrisGame(void);
	~TetrisGame(void);

	void drawTetronimo();
	void displayTitle();
	void display();

	void keyPressed (unsigned char key, int x, int y);
	void specialPressed (int key, int x, int y);

	void onTimer();
	int dropTetronimo();

private:
	int state; // state of program. 0 is title screen, 1 is game for now
	GLfloat z; // z of cube
	GLfloat cubeWidth; // scaling factor for basically everything drawn
	GLfloat xPos; // x of cube
	GLfloat yPos; // y of cube
	GameSpace* gamespace; // the environment variable. Pointer
	Tetronimo* tet;
	bool gameover; // will be used to detect loss, not implemented
};

