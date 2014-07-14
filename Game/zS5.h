/*
 * This is a subclass of Tetronimo. It implements one of the 3-d reflected shapes.
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once

#include "Tetronimo.h"
#include <glut.h>

class zS5piece :
public Tetronimo
{
public:
	zS5piece(GLfloat initCubeWidth);
	zS5piece();
	~zS5piece(void);
};
