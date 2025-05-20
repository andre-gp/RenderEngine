#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.h"

#include "RenderEngine/Core/Game.h"

class Engine
{
public:

	/// <summary>
	/// This function initializes the game engine. 
	/// This should be your first call, and you must call it only once.
	/// </summary>
	/// <returns>The initialization status (0 = success / -1 = failed)</returns>
	int init(RenderEngine::StartingConfiguration* config)
	{
		this->clearColor = config->clearColor;

		/*-------- INIT AND CONFIGURE GLFW --------*/
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mainWindow = new Window(config->width, config->height, "Main Window"); // TODO: Read from a config file.

		/*-------- glad: LOAD ALL OPENGL FUNCTION POINTERS --------*/
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			RE_CORE_CRITICAL("Failed to initialize GLAD\n");

			return NULL;
		}

		return 0;
	}

	bool isRunning()
	{
		return !mainWindow->shouldClose();
	}

	void update()
	{
		checkErrors();

		clearScreen();

		glfwPollEvents();

		mainWindow->update();
	}



	void lateUpdate()
	{
		mainWindow->lateUpdate();
	}

	void terminate()
	{
		for (size_t i = 0; i < windows.size(); i++)
		{
			delete windows[i];
		}

		windows.clear();

		/*-------- glfw: TERMINATE, CLEARING ALL PREVIOUSLY ALLOCATED GLFW RESOURCES --------*/
		glfwTerminate();

	}

	const Input* input() const { return mainWindow->getInput(); }

	Vector4 clearColor{};

private:

	void checkErrors()
	{
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			RE_CORE_ERROR("OpenGL error: {0}\n", error);
		}
	}

	void clearScreen()
	{
		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	Window* mainWindow;
	std::vector<Window*> windows{};
};

