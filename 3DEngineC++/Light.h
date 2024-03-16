#pragma once
#include <GL/glut.h>

class Light
{
public:
    static void setup();
    static void enableFlatShading();
    static void enableGouraudShading();
    static void enablelight();
    static void disablelight();

};