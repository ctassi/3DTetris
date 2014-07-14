#include "zS3.h"

// constructors set up the offsets to create the distinct shapes
zS3piece::zS3piece(GLfloat initCubeWidth)
: Tetronimo(initCubeWidth)
{
	xOff.push_back(-1);  //  #3 piece
	yOff.push_back(-1);
	zOff.push_back(0);

	xOff.push_back(-1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(-1);
	yOff.push_back(0);
	zOff.push_back(1);


}

zS3piece::zS3piece()
{
	xOff.push_back(-1);  //  piece
	yOff.push_back(-1);
	zOff.push_back(0);

	xOff.push_back(-1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(-1);
	yOff.push_back(0);
	zOff.push_back(1);


}


zS3piece::~zS3piece(void)
{
}

