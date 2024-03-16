#pragma once
#include "RenderableObject.h"
#include "TexturableObjects.h"

class Quad3D : RenderableObject, TexturableObjects
{
public:
	void render(float quadVert[],float colorVert[], int size) override;
	void renderTextureColored(float quadVert[], float colorVert[], int size, float textureVert[]);
	void renderTexture(float quadVert[],int size, float textureVert[]);
};

