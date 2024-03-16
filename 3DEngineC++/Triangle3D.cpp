#include "Triangle3D.h"

void Triangle3D::render(float triangleVert[], float colorVert[], int size)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVert);
	glColorPointer(3, GL_FLOAT, 0, colorVert);
	glDrawArrays(GL_TRIANGLES, 0, size); 
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Triangle3D::renderTextureColored(float triangleVert[], float colorVert[], int size, float textureVert[])
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVert);
	glColorPointer(3, GL_FLOAT, 0, colorVert);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
	glDrawArrays(GL_TRIANGLES, 0, size);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Triangle3D::renderTexture(float triangleVert[], int size, float textureVert[])
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVert);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
	glDrawArrays(GL_TRIANGLES, 0, size);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
