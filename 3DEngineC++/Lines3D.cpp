#include "Lines3D.h"

void Lines3D::render(float polylinesVert[], float colorVert[], int size)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, polylinesVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);
    glDrawArrays(GL_LINE_STRIP, 0, size);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void Lines3D::renderTextureColored(float polylinesVert[], float colorVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
    glVertexPointer(3, GL_FLOAT, 0, polylinesVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);
    glDrawArrays(GL_LINE_STRIP, 0, size);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Lines3D::renderTexture(float polylinesVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
    glVertexPointer(3, GL_FLOAT, 0, polylinesVert);
    glDrawArrays(GL_LINE_STRIP, 0, size);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
