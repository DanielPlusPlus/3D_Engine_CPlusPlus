#include "FanStrip3D.h"

void FanStrip3D::render(float stripVert[], float colorVert[], int size)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, stripVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, size);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void FanStrip3D::renderTextureColored(float stripVert[], float colorVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);

    glVertexPointer(3, GL_FLOAT, 0, stripVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, size);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void FanStrip3D::renderTexture(float stripVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
    glVertexPointer(3, GL_FLOAT, 0, stripVert);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, size);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void FanStrip3D::renderFan(float fanVert[], float colorVert[], int size)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, fanVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);

    glDrawArrays(GL_TRIANGLE_FAN, 0, size);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void FanStrip3D::renderFanTextureColored(float fanVert[], float colorVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
    glVertexPointer(3, GL_FLOAT, 0, fanVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);

    glDrawArrays(GL_TRIANGLE_FAN, 0, size);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void FanStrip3D::renderFanTexture(float fanVert[], int size, float textureVert[])
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
    glVertexPointer(3, GL_FLOAT, 0, fanVert);

    glDrawArrays(GL_TRIANGLE_FAN, 0, size);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
