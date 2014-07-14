#include "zS.h"
#include "Tetronimo.h"

// constructors set up the offsets to create the distinct shapes
zSpiece::zSpiece(GLfloat initCubeWidth)
: Tetronimo(initCubeWidth)
{
	xOff.push_back(-1);  //  #4 piece
	yOff.push_back(-1);
	zOff.push_back(0);

	xOff.push_back(-1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(1);


}

zSpiece::zSpiece()
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

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(1);


}


zSpiece::~zSpiece(void)
{
}
