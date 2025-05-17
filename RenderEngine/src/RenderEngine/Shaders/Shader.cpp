#include "pchRender.h"
#include "Shader.h"



Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	int vertexShader = loadAndCompileShader(vertexPath, GL_VERTEX_SHADER);

	int fragmentShader = loadAndCompileShader(fragmentPath, GL_FRAGMENT_SHADER);

	programID = glCreateProgram();

	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);

	int success;
	char infoLog[512];

	glGetProgramiv(programID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(programID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINK_FAILED\n" << infoLog << '\n';
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use()
{
	glUseProgram(programID);
}

void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(programID, name.c_str()), x, y, z);
}

void Shader::setVec3(const std::string& name, glm::vec3 value) const
{
	glUniform3f(glGetUniformLocation(programID, name.c_str()), value.x, value.y, value.z);
}

void Shader::deleteProgram()
{
	glDeleteProgram(programID);
}

int Shader::loadAndCompileShader(const char* path, GLenum type)
{
	std::ifstream file{ path };

	// Ensure stream can throw exceptions.
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::string sourceString{ std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
	const char* source = sourceString.c_str();

	int shader = glCreateShader(type);

	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int sucess;
	char infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &sucess);

	if (!sucess)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);

		std::cout << path << ": ";

		if (type == GL_VERTEX_SHADER)
		{
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		else if (type == GL_FRAGMENT_SHADER)
		{
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	return shader;
}
