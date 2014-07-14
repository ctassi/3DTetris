
 /*
 * This is a subclass of Tetronimo. This block looks like a set of axis.
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once

#include "Tetronimo.h"
#include <glut.h>

class zS3piece :
public Tetronimo
{
public:
	zS3piece(GLfloat initCubeWidth);
	zS3piece();
	~zS3piece(void);
};
