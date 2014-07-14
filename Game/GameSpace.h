/*
 * This is the arena in which 3D tetris is played.
 * Keeps track of which spaces have been filled.
 * Clears lines as necessary
 * Draws the background and all fallen blocks.
 */

#pragma once
#include <vector>
#include <glut.h>
#include "Tetronimo.h"

class GameSpace
{
public:
	GameSpace(void); // constructor
	~GameSpace(void); // destructor
	void draw(GLfloat cubeWidth); // draw everything

	int getSpace(int x, int y, int z); // get value of space (0 empty)
	int isOccupied(Tetronimo* tet);
	void setSpace(int x, int y, int z, int value); // set value of space (0 empty)
	void setSpaces(Tetronimo* tet, int value);

	int checkAndClear(); // check if any levels are full and clear them if they are
	bool check(int level); // return true if specified level is clear

	void resetSpace();

private:
	int width; // width of environment
	int length; // length of environment
	int height; // height of environment
	std::vector<int> filled; // vector for storing space data.
};

