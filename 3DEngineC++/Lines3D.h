#pragma once
#include "RenderableObject.h"
#include "TexturableObjects.h"

class Lines3D : RenderableObject, TexturableObjects
{
public:
	void render(float polylinesVert[],float colorVert[],int size) override;
	void renderTextureColored(float polylinesVert[], float colorVert[], int size, float textureVert[]);
	void renderTexture(float polylinesVert[],int size, float textureVert[]);
};

