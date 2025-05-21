#pragma once

#include "Camera.h"

class LookAtCamera : public Camera
{
public:
	Mat4 GetViewMatrix() const override
	{
		const float radius = 20.0f;
		float camX = sin(glfwGetTime()) * radius;
		float camZ = cos(glfwGetTime()) * radius;
		glm::mat4 view;
		view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

		return view;

		return glm::lookAt(transform.position,
			Vector3(0.f),
			Vector3(0.0f, 1.0f, 0.0f));
	}
};