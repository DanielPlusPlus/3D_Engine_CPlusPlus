#pragma once
#include "GameObject.h"

class RenderableObject
{
public:
	virtual void render(float vert[], float colorVert[], int size) = 0;
};

