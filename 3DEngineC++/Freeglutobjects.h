#pragma once
#include "GameObject.h"

class Freeglutobjects
{
private:

public:
	static void drawCube(float size);
	static void drawTorus(float innerRadius, float outerRadius, int sides, int rings);
	static void drawTeapot(float size);
	static void drawSphere(float radius, int slices, int stacks);
	static void drawDoubleTeapot(float size);
};
