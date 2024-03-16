#include "Line3D.h"

void Line3D::render(float linesVert[], float colorVert[], int size)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, linesVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);
    glDrawArrays(GL_LINES, 0, size);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void Line3D::renderTextureColored(float linesVert[], float colorVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
    glVertexPointer(3, GL_FLOAT, 0, linesVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);
    glDrawArrays(GL_LINES, 0, size);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Line3D::renderTexture(float linesVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
    glVertexPointer(3, GL_FLOAT, 0, linesVert);
    glDrawArrays(GL_LINES, 0, size);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
