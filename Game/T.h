
 /*
 * This is a subclass of Tetronimo. 2D shape, T
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once

#include "Tetronimo.h"
#include <glut.h>

class Tpiece :
public Tetronimo
{
public:
	Tpiece(GLfloat initCubeWidth);
	Tpiece();
	~Tpiece(void);
};
