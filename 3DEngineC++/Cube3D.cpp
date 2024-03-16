#include "Cube3D.h"

Cube3D::Cube3D()
{
}

void Cube3D::render(float cubeVert[], float cubeNorm[], float cubeCols[], unsigned char cubeInd[])
{
    for (int i = 0; i < 8; ++i) {
        glm::vec4 point(cubeVert[i * 3], cubeVert[i * 3 + 1], cubeVert[i * 3 + 2], 1.0f);
        point = transformationMatrix * point;
        cubeVert[i * 3] = point.x;
        cubeVert[i * 3 + 1] = point.y;
        cubeVert[i * 3 + 2] = point.z;
    }

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cubeVert);
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, cubeNorm);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cubeCols);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, cubeInd);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Cube3D::renderTextureColored(float cubeVert[], float cubeNorm[], float cubeCols[], unsigned char cubeInd[], float textureVert[])
{
	for (int i = 0; i < 8; ++i) {
		glm::vec4 point(cubeVert[i * 3], cubeVert[i * 3 + 1], cubeVert[i * 3 + 2], 1.0f);
		point = transformationMatrix * point;
		cubeVert[i * 3] = point.x;
		cubeVert[i * 3 + 1] = point.y;
		cubeVert[i * 3 + 2] = point.z;
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cubeVert);
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, cubeNorm);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cubeCols);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, cubeInd);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Cube3D::renderTexture(float cubeVert[], float cubeNorm[], unsigned char cubeInd[], float textureVert[])
{
	for (int i = 0; i < 8; ++i) {
		glm::vec4 point(cubeVert[i * 3], cubeVert[i * 3 + 1], cubeVert[i * 3 + 2], 1.0f);
		point = transformationMatrix * point;
		cubeVert[i * 3] = point.x;
		cubeVert[i * 3 + 1] = point.y;
		cubeVert[i * 3 + 2] = point.z;
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cubeVert);
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, cubeNorm);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, textureVert);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, cubeInd);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Cube3D::translate(const glm::vec3& translation) {
    transformationMatrix = glm::translate(transformationMatrix, translation);
    return;
}

void Cube3D::rotate(float angle, const glm::vec3& axis) {
    transformationMatrix = glm::rotate(transformationMatrix, glm::radians(angle), axis);
    return;
}

void Cube3D::scale(const glm::vec3& scaling) {
    transformationMatrix = glm::scale(transformationMatrix, scaling);
    return;
}
