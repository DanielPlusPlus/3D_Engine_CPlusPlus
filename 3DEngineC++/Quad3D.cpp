#include "Quad3D.h"

void Quad3D::render(float quadVert[], float colorVert[], int size)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, quadVert);
	glColorPointer(3, GL_FLOAT, 0, colorVert);
	glDrawArrays(GL_QUADS, 0, size);  
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Quad3D::renderTextureColored(float quadVert[], float colorVert[], int size, float textureVert[])
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
	glVertexPointer(3, GL_FLOAT, 0, quadVert);
	glColorPointer(3, GL_FLOAT, 0, colorVert);
	glDrawArrays(GL_QUADS, 0, size);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Quad3D::renderTexture(float quadVert[], int size, float textureVert[])
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
	glVertexPointer(3, GL_FLOAT, 0, quadVert);
	glDrawArrays(GL_QUADS, 0, size);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
