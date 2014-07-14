#include "zS5.h"
#include "Tetronimo.h"

// constructors set up the offsets to create the distinct shapes
zS5piece::zS5piece(GLfloat initCubeWidth)
: Tetronimo(initCubeWidth)
{
	xOff.push_back(1);  //  #5 piece
	yOff.push_back(-1);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(1);


}

zS5piece::zS5piece()
{
	xOff.push_back(1);  //  piece
	yOff.push_back(-1);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(1);


}


zS5piece::~zS5piece(void)
{
}
