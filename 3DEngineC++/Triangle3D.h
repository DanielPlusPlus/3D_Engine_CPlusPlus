#pragma once
#include "RenderableObject.h"
#include "TexturableObjects.h"

class Triangle3D : RenderableObject, TexturableObjects
{
public:
	void render(float triangleVert[],float colorVert[], int size) override;
	void renderTextureColored(float triangleVert[], float colorVert[], int size, float textureVert[]);
	void renderTexture(float triangleVert[],int size, float textureVert[]);
};

