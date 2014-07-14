/*
 * File containing useful functions for 3D Tetris
 * Only function is drawCube
 *   - similar to glutSolidCube but with texture coordinates for drawing the border
 */

#include <glut.h>

// drawCube with texture coordinates
void drawCube(GLfloat size, int x, int y, GLuint tex_2d);
