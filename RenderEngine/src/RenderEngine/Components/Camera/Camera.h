#pragma once

#include "RenderEngine/TypeDefs.h"
#include "RenderEngine/Components/Transform.h"

class Camera
{
public:
	virtual Mat4 GetViewMatrix() const
	{
		return glm::translate(Mat4(1.0f), transform.position);
	}


	Transform transform;

protected:

	
};