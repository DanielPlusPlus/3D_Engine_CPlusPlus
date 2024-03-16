#include "TexturableObjects.h"
#include "stb_image.h"

void TexturableObjects::bindTexture()
{
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0,
        GL_RGB, GL_UNSIGNED_BYTE, texture.data.data());
    
}

TexturableObjects::TexturableObjects()
{
}

void TexturableObjects::unbindTexture()
{
    glDeleteTextures(1, &textureId);
    glDisable(GL_TEXTURE_2D);
}
