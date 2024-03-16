#pragma once
#include "GameObject.h"
#include "TransformableObject.h"
#include "TexturableObjects.h"

class Cube3D : TransformableObject, TexturableObjects
{
public:
    Cube3D();
	void render(float cubeVert[], float cubeNorm[], float cubeCols[], unsigned char cubeInd[]);
    void renderTextureColored(float cubeVert[], float cubeNorm[], float cubeCols[], unsigned char cubeInd[], float textureVert[]);
    void renderTexture(float cubeVert[], float cubeNorm[], unsigned char cubeInd[], float textureVert[]);
    void translate(const glm::vec3& translation) override;
    void rotate(float angle, const glm::vec3& axis) override;
    void scale(const glm::vec3& scale) override;
private:
    glm::mat4 transformationMatrix = glm::mat4(1.0f);
};

