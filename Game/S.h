 /*
 * This is a subclass of Tetronimo. 2d S shape
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once
#include "Tetronimo.h"
#include "glut.h"

class Spiece :
public Tetronimo
{
public:
	Spiece(GLfloat initCubeWidth);
	Spiece();
	~Spiece(void);
};
