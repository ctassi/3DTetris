/*
 *  square.h
 *  block
 *
 *  Created by Camilla on 4/30/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#include "untitled.h"
#include "glut.h"

class Square :
public Tetronimo
{
public:
	Square(GLfloat initCubeWidth);
	Square();
	~Square(void);
};