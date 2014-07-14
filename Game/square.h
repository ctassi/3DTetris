
/*
 *  This is a subclass of Tetronimo. 2d square shape.
 *  Part of the 3D Tetris project designed by
 *  Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */

#pragma once
#include "Tetronimo.h"
#include "glut.h"

class Square :
public Tetronimo
{
public:
	Square(GLfloat initCubeWidth);
	Square();
	~Square(void);
};
