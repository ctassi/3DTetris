#include "GameSpace.h"
#include <glut.h>
#include "SOIL.h"
#include "Tetris_Utils.h"
#include "Tetronimo.h"


GameSpace::GameSpace(void)
{
	width = 5; // default width of 5
	length = 5; // default length of 5
	height = 12; // default height of 12
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < length; j++)
		{
			for(int k = 0; k < height; k++)
			{
				filled.push_back(0); // initialize vector with 0s
			}
		}
	}
	glEnable( GL_TEXTURE_2D ); // enable texture
}

void GameSpace::draw(GLfloat cubeWidth)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our window to black
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations

	// ---------------------------------------------------------------
	// ------ Drawing of box environment -----------------------------
	// ---------------------------------------------------------------

	int count = 0; // number of rectangles drawn (for alternating color purposes)
	glTranslatef(0.0, 0.0, -1.0f); // start drawing a little ways in.
	for(int i = 0; i < 12; i++) // For each layer
	{
		for(int j = 0; j < 5; j++) // top wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0f, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, -(cubeWidth * 2.5), 0.0 - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, -(cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, -(cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, -(cubeWidth * 2.5), 0.0 - cubeWidth*i);
			glEnd();
		}
		count++; // to alternate colors properly
		for(int j = 0; j < 5; j++) // left wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, 0.0 - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, 0.0 - cubeWidth*i);
			glEnd();
		}
		count++; // to alternate colors properly
		for(int j = 0; j < 5; j++) // bottom wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, (cubeWidth * 2.5), 0.0 - cubeWidth*i);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*j, (cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, (cubeWidth * 2.5), -cubeWidth - cubeWidth*i);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*j, (cubeWidth * 2.5), 0.0 - cubeWidth*i);
			glEnd();
		}
		count++; // to alternate colors properly
		for(int j = 0; j < 5; j++) // right wall, 5 squares across
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, 0.0 - cubeWidth*i);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 2.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, -cubeWidth - cubeWidth*i);
				glVertex3f((cubeWidth * 2.5), -(cubeWidth * 1.5) + cubeWidth*j, 0.0 - cubeWidth*i);
			glEnd();
		}
	}
	// Draw the bottom of the box
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if( count % 2)
				glColor3f(0.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0, 0.2f, 0.2f);
			count++;
			glBegin(GL_QUADS);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*i, -(cubeWidth * 2.5) + cubeWidth*j, -12*cubeWidth);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*i, -(cubeWidth * 2.5) + cubeWidth*j, -12*cubeWidth);
				glVertex3f(-(cubeWidth * 1.5) + cubeWidth*i, -(cubeWidth * 1.5) + cubeWidth*j, -12*cubeWidth);
				glVertex3f(-(cubeWidth * 2.5) + cubeWidth*i, -(cubeWidth * 1.5) + cubeWidth*j, -12*cubeWidth);
			glEnd();
		}
	}
	// ---------------------------------------------------------------
	// ------ End drawing of box environment -------------------------
	// ---------------------------------------------------------------

	// ---------------------------------------------------------------
	// ------ Begin drawing of fallen tetronimos ---------------------
	// ---------------------------------------------------------------
	// Load texture once at the beginning
	GLuint tex_2d = SOIL_load_OGL_texture
		(
			"cube-border.bmp",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT
		);
	glBindTexture(GL_TEXTURE_2D, tex_2d); // bind the texture so the cubes will have border
	for(int k = 11; k >= 0; k--) // for each layer
	{
		for(int dist = length/2 + width/2; dist >=0; dist--) // draw the ones farther from center first for visual appearance
		{
			for(int i = 0; i < width; i++) // double for loop to get all 25 cubes in layer
			{
				for(int j = 0; j < length; j++)
				{

					int index = i + j * length + k * length * width; // convert x,y,z (i,j,k) to index

					if(filled[index] && (abs(width/2 - i) + abs(length/2 - j)) == dist) // if filled and appropriate distance, draw
					{
						glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
						glTranslatef((i-2)*cubeWidth, (j-2)*cubeWidth, -1.0-0.5*cubeWidth-k*cubeWidth);
						switch (k) // different colors based on height
						{
						case 0:
							glColor3f(1.0, 0.0, 0);
							break;
						case 1:
							glColor3f(0.5, 0.0, 0.9);
							break;
						case 2:
							glColor3f(0.9, 0.5, 0);
							break;
						case 3:
							glColor3f(0.9, 0.9, 0.0);
							break;
						case 4:
							glColor3f(0.0, 0.5, 0.9);
							break;
						case 5:
							glColor3f(0.2, 0.6, 0.4);
							break;
						case 6:
							glColor3f(0.2, 0.1, 0.0);
							break;
						case 7:
							glColor3f(0.9, 0.0, 0.5);
							break;
						case 8:
							glColor3f(0.9, 0.5, 0.9);
							break;
						case 9:
							glColor3f(0.5, 0.5, 0.9);
							break;
						case 10:
							glColor3f(0.5, 0.9, 0.0);
							break;
						case 11:
							glColor3f(0.5, 0.9, 0.9);
							break;

						}

						drawCube(cubeWidth, i, j, tex_2d); // draw the cube

					}
				}
			}
		}
	}
	glDeleteTextures(1, &tex_2d); // delete the texture to free memeory
	// ---------------------------------------------------------------
	// ------ End drawing of fallen tetronimos ---------------------
	// ---------------------------------------------------------------

}


 GameSpace::~GameSpace(void)
{
}

int GameSpace::getSpace(int x, int y, int z)
{
	int index = x + y * length + z * length * width; // convert to index
	return filled[index]; // return value at index
}

int GameSpace::isOccupied(Tetronimo* tet)
{
	int occupied = 0;
	for(int i = 0; i < 4; i++)
	{
		int xtemp = tet->getX() + tet->getXOff()[i] + 2;
		int ytemp = tet->getY() + tet->getYOff()[i] + 2;
		int ztemp = tet->getZ() + tet->getZOff()[i];
		int index = xtemp + ytemp * length + ztemp * length * width; // convert to index
		if(index < 0 || index > 4+4*5 + 11*25 || filled[index])
			occupied = 1;
	}
	return occupied;
}

void GameSpace::setSpace(int x, int y, int z, int value)
{
	int index = x + y * length + z * length * width; // convert to index
	filled[index] = value; // set value at index
}

void GameSpace::setSpaces(Tetronimo* tet, int value)
{
	for(int i = 0; i < 4; i++)
	{
		int x = tet->getX() + tet->getXOff()[i] + 2;
		int y = tet->getY() + tet->getYOff()[i] + 2;
		int z = tet->getZ() + tet->getZOff()[i];
		int index = x + y * length + z * length * width; // convert to index
		filled[index] = value; // set value at index
	}
}

int GameSpace::checkAndClear()
{
	int linesCleared = 0;
	for(int i = 0; i < 12; i++) // for each layer, starting at top
	{
		if(check(i)) // if the layer is full
		{
			linesCleared++;
			for(int k = 0; k < width; k++) // for each row
			{
				for(int l = 0; l < length; l++) // for each cube in row
				{
					for(int j = i; j > 0; j--) // From the current level to the 2nd from top
					{
						int index = k + l * length + j * length * width;
						int oneUp = k + l * length + (j-1) * length * width;
						filled[index] = filled[oneUp]; // set the space to the value of the space above it
					}
					filled[k + l * length] = 0; // set top layer to empty
				}
			}
		}
	}
	return linesCleared;
}

bool GameSpace::check(int level)
{
	for(int i = 0; i < length; i++) // double for loop to check the layer
	{
		for(int j = 0; j < width; j++)
		{
			int index = i + j * length + level * length * width; // convert to index
			if(!filled[index]) // if it's empty, layer not complete
				return false;
		}
	}
	return true; // if we haven't returned false yet, return true
}

void GameSpace::resetSpace()
{
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < length; j++)
		{
			for(int k = 0; k < height; k++)
			{
				int index = i + j * length + k * length * width;
				filled[index] = 0; // reset vector to 0s
			}
		}
	}
}
