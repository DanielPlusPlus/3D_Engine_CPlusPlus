#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GameObject.h"

class TransformableObject
{
public:
	virtual void translate(const glm::vec3& translation) = 0;
    virtual void rotate(float angle, const glm::vec3& axis) = 0;
	virtual void scale(const glm::vec3& scale) = 0;
};
