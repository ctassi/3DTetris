 /*
 * This is a subclass of Tetronimo. 2d L shape.
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once

#include "Tetronimo.h"
#include "glut.h"

class Lpiece :    //___|
public Tetronimo
{
public:
	Lpiece(GLfloat initCubeWidth);
	Lpiece();
	~Lpiece(void);
};
