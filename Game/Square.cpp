
/*
 *  line.cpp
 *  block
 *
 *  Created by Camilla on 4/30/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */
#include "square.h"
// constructors set up the offsets to create the distinct shapes
Square::Square(GLfloat initCubeWidth)
: Tetronimo(initCubeWidth)
{
	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(1);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(1);
	zOff.push_back(0);


}

Square::Square()
{
	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(1);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(1);
	zOff.push_back(0);
}


Square::~Square(void)
{
}
