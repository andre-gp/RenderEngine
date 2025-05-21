#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "RenderEngine/Input/InputInternal.h"

#define GET_WINDOW_DATA(glfwWindow) (Window*) glfwGetWindowUserPointer(glfwWindow);

class Window
{
public:
	Window(int width, int height, const char* name)
	{
		glfwWindow = glfwCreateWindow(width, height, name, NULL, NULL);

		if (glfwWindow == NULL)
		{
			RE_CORE_CRITICAL("Failed to create GLFW window \n");

			glfwTerminate();
		}

		glfwMakeContextCurrent(glfwWindow);

		glfwSetWindowUserPointer(glfwWindow, this);

		glfwSetCursorPosCallback(glfwWindow, [](GLFWwindow* glfwWindow, double xpos, double ypos)
			{
				Window* window = GET_WINDOW_DATA(glfwWindow);

				window->input.setCursorPos(xpos, ypos);
			});

		glfwSetMouseButtonCallback(glfwWindow, [](GLFWwindow* glfwWindow, int button, int action, int mods)
			{
				Window* window = GET_WINDOW_DATA(glfwWindow);

				window->input.setMouseButton(button, action);				
			});

		glfwSetKeyCallback(glfwWindow, [](GLFWwindow* glfwWindow, int key, int scancode, int action, int mods)
			{
				//RE_CORE_LOG("Key:{0}, Scancode:{1}, Action:{2}, Mods:{3}", key, scancode, action, mods);

				Window* window = GET_WINDOW_DATA(glfwWindow);

				window->input.setKeyboardButton(key, action);
			});
	}


	bool shouldClose()
	{
		return glfwWindowShouldClose(glfwWindow);
	}

	void update()
	{
		
	}

	void lateUpdate()
	{
		glfwSwapBuffers(glfwWindow);

		input.lateUpdate();
	}

	InputInternal* getInput() { return &input; }

private:

	InputInternal input;

	GLFWwindow* glfwWindow;
};

