#pragma once
#include "BitmapHandler.h"

class TexturableObjects
{
	GLuint textureId;
public:
	BitmapHandler texture;
	TexturableObjects();
	void bindTexture();
	void unbindTexture();
};

