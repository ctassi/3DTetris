 /*
 * This is a subclass of Tetronimo. 2D straight line piece.
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once
#include "Tetronimo.h"
#include <glut.h>

class Line :
	public Tetronimo
{
public:
	Line(GLfloat initCubeWidth);
	Line();
	~Line(void);
};

