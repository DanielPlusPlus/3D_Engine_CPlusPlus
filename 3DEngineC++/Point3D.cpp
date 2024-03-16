#include "Point3D.h"

void Point3D::render(float pointVert[], float colorVert[], int size)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, pointVert);
    glColorPointer(3, GL_FLOAT, 0, colorVert);
    glDrawArrays(GL_POINTS, 0, size/2);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
