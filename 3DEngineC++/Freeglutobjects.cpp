#include "Freeglutobjects.h"

void Freeglutobjects::drawCube(float size) {
    glutWireCube(size);
}


void Freeglutobjects::drawTorus(float innerRadius, float outerRadius, int sides, int rings) {
    glutWireTorus(innerRadius, outerRadius, sides, rings);
}


void Freeglutobjects::drawTeapot(float size) {
    glutWireTeapot(size);
}



void Freeglutobjects::drawSphere(float radius, int slices, int stacks) {
    glutWireSphere(radius, slices, stacks);
}


void Freeglutobjects::drawDoubleTeapot(float size) {
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glutWireTeapot(size);
    glTranslatef(2.0, 0.0, 0.0);
    glutWireTeapot(size);
    glPopMatrix();
}