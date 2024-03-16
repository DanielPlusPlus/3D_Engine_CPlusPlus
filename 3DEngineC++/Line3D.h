#pragma once
#include "RenderableObject.h"
#include "TexturableObjects.h"

class Line3D : RenderableObject, TexturableObjects
{
public:
	void render(float linesVert[], float colorVert[], int size) override;
	void renderTextureColored(float linesVert[], float colorVert[], int size, float textureVert[]);
	void renderTexture(float linesVert[],int size, float textureVert[]);
};

