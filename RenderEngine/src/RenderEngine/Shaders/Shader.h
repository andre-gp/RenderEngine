#pragma once

#include <glad/glad.h>
#include <glm/vec3.hpp>

#include <string>

#define PATH_DEFAULT_VERTEX_SHADER "C:/Users/andre/Documents/Projetos/OpenGL-Learning/RenderEngine/RenderEngine/src/Shaders/vertexShader.vert"
#define PATH_DEFAULT_FRAGMENT_SHADER "C:/Users/andre/Documents/Projetos/OpenGL-Learning/RenderEngine/RenderEngine/src/Shaders/fragmentShader.frag"


class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);

	// program ID
	unsigned int programID;

	void use();

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec3(const std::string& name, Vector3 value) const;
	void setMat4(const std::string& name, Mat4 value) const;

	void deleteProgram();

private:
	int loadAndCompileShader(const char* path, GLenum type);
};