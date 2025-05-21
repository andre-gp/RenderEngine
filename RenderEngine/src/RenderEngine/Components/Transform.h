#pragma once

#include "RenderEngine/TypeDefs.h"

class Transform
{
public:
	
	Vector3 position;

	void LookAt(Vector3 target)
	{
		auto reverseLook = glm::normalize(position - target);
		Vector3 worldUp = Vector3(0, 1, 0);
		right = glm::normalize(glm::cross(worldUp, reverseLook));
		up = glm::normalize(glm::cross(reverseLook, right));
	}


	Vector3 forward;
	Vector3 up;
	Vector3 right;

private:
};