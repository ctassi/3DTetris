#include "Lpiece.h"
#include "Tetronimo.h"

// constructors set up the offsets to create the distinct shapes
Lpiece::Lpiece(GLfloat initCubeWidth)
: Tetronimo(initCubeWidth)
{
	xOff.push_back(-1);  // ___| piece
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(1);
	zOff.push_back(0);

}

Lpiece::Lpiece()
{
	xOff.push_back(-1);  // ___| piece
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(1);
	zOff.push_back(0);

}


Lpiece::~Lpiece(void)
{
}
