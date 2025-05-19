#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "RenderEngine/Input/Input.h"

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
	}


	bool shouldClose()
	{
		return glfwWindowShouldClose(glfwWindow);
	}

	void update()
	{
		glfwSwapBuffers(glfwWindow);
	}

	void lateUpdate()
	{
		input.lateUpdate();
	}

	const Input* getInput() const { return &input; }

private:

	Input input;

	GLFWwindow* glfwWindow;
};

