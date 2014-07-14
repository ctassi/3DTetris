#include "T.h"
#include "Tetronimo.h"

// constructors set up the offsets to create the distinct shapes
Tpiece::Tpiece(GLfloat initCubeWidth)
: Tetronimo(initCubeWidth)
{
	xOff.push_back(-1);  //T piece
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(1);
	yOff.push_back(0);
	zOff.push_back(0);

	xOff.push_back(0);
	yOff.push_back(1);
	zOff.push_back(0);


}

Tpiece::Tpiece()
{
	        xOff.push_back(-1);  //T piece
        yOff.push_back(0);
        zOff.push_back(0);

        xOff.push_back(0);
        yOff.push_back(0);
        zOff.push_back(0);

        xOff.push_back(1);
        yOff.push_back(0);
        zOff.push_back(0);

        xOff.push_back(0);
        yOff.push_back(1);
        zOff.push_back(0);


}


Tpiece::~Tpiece(void)
{

}
