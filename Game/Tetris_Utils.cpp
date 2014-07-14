#include <glut.h>

// drawCube with texture coordinates
void drawCube(GLfloat cubeWidth, int x, int y, GLuint tex_2d)
{
 
   // draw a cube (6 quadrilaterals)
   // attempts to draw in an order that will display well. Pretty good, but not perfect yet. TODO
  glBegin(GL_QUADS);				// start drawing the cube.
	// Back Face
	glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
	glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
	if(y > 2){
		// Top Face
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Right Of The Texture and Quad
	}
	else
	{
		// Bottom Face
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
	}
	if(x < 2)
	{
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Left Of The Texture and Quad
	}
	else
	{
		// Right face
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
	}
	
	
	if(y < 2){
		// Top Face
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Right Of The Texture and Quad
	}
	else
	{
		// Bottom Face
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
	}
	if(x > 2)
	{
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f(-(0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Left Of The Texture and Quad
	}
	else
	{
		// Right face
		glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth), -(0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
		glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth), -(0.5f * cubeWidth));	// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
	}
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f*cubeWidth, -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Left Of The Texture and Quad
	glTexCoord2f((0.5f * cubeWidth), 0.0f); glVertex3f( (0.5f * cubeWidth), -(0.5f * cubeWidth),  (0.5f * cubeWidth));	// Bottom Right Of The Texture and Quad
	glTexCoord2f((0.5f * cubeWidth), (0.5f * cubeWidth)); glVertex3f( (0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, (0.5f * cubeWidth)); glVertex3f(-(0.5f * cubeWidth),  (0.5f * cubeWidth),  (0.5f * cubeWidth));	// Top Left Of The Texture and Quad
 
  glEnd();					// Done Drawing The Cube
  
 
}