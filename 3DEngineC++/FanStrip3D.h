#pragma once
#include "RenderableObject.h"
#include "TexturableObjects.h"

class FanStrip3D : RenderableObject, TexturableObjects
{
public:
	void render(float stripVert[],float colorVert[],int size) override;
	void renderTextureColored(float stripVert[], float colorVert[], int size, float textureVert[]);
	void renderTexture(float stripVert[], int size, float textureVert[]);
	void renderFan(float fanVert[], float colorVert[], int size);
	void renderFanTextureColored(float fanVert[], float colorVert[], int size, float textureVert[]);
	void renderFanTexture(float fanVert[],int size, float textureVert[]);
};

