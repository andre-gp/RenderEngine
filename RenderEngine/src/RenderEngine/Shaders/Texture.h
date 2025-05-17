#pragma once

#include <glad/glad.h>

class Texture
{
public:
	Texture(const char* path, GLint format);

	unsigned int textureID;
};