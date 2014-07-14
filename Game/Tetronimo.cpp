#include "Tetronimo.h"
#include <glut.h>

/*
 * Initialize variables
 * x, y, z, to 0, cubewidth to 0.25 or given value
 */
Tetronimo::Tetronimo(void)
{
	x = y = z = 0;
	cubeWidth = 0.25;
}

Tetronimo::Tetronimo(GLfloat initCubeWidth)
{
	x = y = z = 0;
	cubeWidth = initCubeWidth;
}

Tetronimo::~Tetronimo(void)
{
}

/*
 * Draw the tetronimo with wire cubes
 */
void Tetronimo::draw()
{
	glLoadIdentity(); // Reset coordinates for drawing
	glTranslatef(0.0, 0.0, -1.0f); // push it 1 in

	// set the color to white
	glColor3f(1.0, 1.0, 1.0);
	// move to proper location
	glTranslatef(x*cubeWidth, y*cubeWidth, (-z-.5)*cubeWidth);
	for(int i = 0; i < 4; i++)
	{
		glPushMatrix(); // store the default spot
		glTranslatef(xOff[i]*cubeWidth, yOff[i]*cubeWidth, -zOff[i]*cubeWidth); // move to the offset
		glutWireCube(cubeWidth); // draw cube
		glPopMatrix(); // move back to default
	}
}

/*
 * Rotate around the x axis
 */
void Tetronimo::rotateX()
{
	int temp;
	for(int i = 0; i < yOff.size(); i++) // for each value in offsets
	{
	    // linear algebra rotation matrix multiplication
		temp = yOff[i];
		yOff[i] = zOff[i];
		zOff[i] = -temp;
	}

}

/*
 * Rotate around the y axis
 */
void Tetronimo::rotateY()
{
	int temp;
	for(int i = 0; i < xOff.size(); i++) // for each value in offsets
	{
	    // linear algebra rotation matrix multiplication
		temp = xOff[i];
		xOff[i] = zOff[i];
		zOff[i] = -temp;
	}
}

/*
 * Rotate around the z axis
 */
void Tetronimo::rotateZ()
{
	int temp;
	for(int i = 0; i < yOff.size(); i++) // for each value in offsets
	{
	    // linear algebra rotation matrix multiplication
		temp = yOff[i];
		yOff[i] = -xOff[i];
		xOff[i] = temp;
	}
}

// returns a vector in the form of {firstX, firstY, firstZ, secondX, secondY, secondZ}
// where each point corresponds to opposite corners of the bounding box
std::vector<int> Tetronimo::boundingBox()
{
	int minX, minY, minZ, maxX, maxY, maxZ;
	minX = minY = minZ = maxX = maxY = maxZ = 0; // initialize to 0.
	std::vector<int> temp;

    // find the minimum and maximum of each offset
	for(int i = 0; i < 4; i++)
	{
		if(xOff[i] < minX)
			minX = xOff[i];
		if(xOff[i] > maxX)
			maxX = xOff[i];
		if(yOff[i] < minY)
			minY = yOff[i];
		if(yOff[i] > maxY)
			maxY = yOff[i];
		if(zOff[i] < minZ)
			minZ = zOff[i];
		if(zOff[i] > maxZ)
			maxZ = zOff[i];
	}
	// add the overall x,y,z position and push onto vector for returning.
	temp.push_back(minX+x);
	temp.push_back(minY+y);
	temp.push_back(minZ+z);
	temp.push_back(maxX+x);
	temp.push_back(maxY+y);
	temp.push_back(maxZ+z);
	return temp;
}

// set the x,y,z coordinates as specified
void Tetronimo::setXYZ(int xNew, int yNew, int zNew)
{
	x = xNew;
	y = yNew;
	z = zNew;
}

// return the x position of the tetronimo
int Tetronimo::getX()
{
	return x;
}

// return the y position of the tetronimo
int Tetronimo::getY()
{
	return y;
}

// return the z position of the tetronimo
int Tetronimo::getZ()
{
	return z;
}

// return the x offsets of the tetronimo
std::vector<int> Tetronimo::getXOff()
{
	return xOff;
}

// return the y offsets of the tetronimo
std::vector<int> Tetronimo::getYOff()
{
	return yOff;
}

// return the z offsets of the tetronimo
std::vector<int> Tetronimo::getZOff()
{
	return zOff;
}
