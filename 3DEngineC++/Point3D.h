#pragma once
#include "RenderableObject.h"

class Point3D : RenderableObject{

public:
    void render(float pointVert[], float colorVert[], int size) override;
};

