
#include "S.h"

// constructors set up the offsets to create the distinct shapes
Spiece::Spiece(GLfloat initCubeWidth)
: Tetronimo(initCubeWidth)
{
	xOff.push_back(-1);  //__-- piece
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(1);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(1);
	zOff.push_back(0);


}

Spiece::Spiece()
{
	xOff.push_back(-1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(1);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(1);
	zOff.push_back(0);

}


Spiece::~Spiece(void)
{
}
