
 /*
 * This is a subclass of Tetronimo. This is the reflection of zS5piece
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once

#include "Tetronimo.h"
#include <glut.h>

class zSpiece :
public Tetronimo
{
public:
	zSpiece(GLfloat initCubeWidth);
	zSpiece();
	~zSpiece(void);
};
