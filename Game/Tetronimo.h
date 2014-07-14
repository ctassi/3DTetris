 /*
 * This is the base Tetronimo class. Most of the functions for working with Tetronimos.
 * Part of the 3D Tetris project designed by
 * Matt Nulle, Camilla Tassi, and Jonathan Alvarez
 */
#pragma once

#include <vector>
#include <glut.h>

class Tetronimo
{
public:
    // Constructors initialize variables
	Tetronimo(void);
	Tetronimo(GLfloat initCubeWidth);
	~Tetronimo(void);

    // Draws the tetronimo in xyz spot indicated
	void draw();

	// rotation functions
	void rotateX();
	void rotateY();
	void rotateZ();

    // returns [minX minY minZ maxX maxY maxZ] for determining if it has left the arena
	std::vector<int> boundingBox();

    // for manipulating the tetronimo's position
	void setXYZ(int xNew, int yNew, int zNew);

	// getting information about the tetronimo's position
	int getX();
	int getY();
	int getZ();
	std::vector<int> getXOff();
	std::vector<int> getYOff();
	std::vector<int> getZOff();

// protected so that derived classes can easily access
protected:
    // location of tetronimo and each block
	int x, y, z;
	std::vector<int> xOff, yOff, zOff;
	// width of a given cube for drawing purposes
	GLfloat cubeWidth;
};

