#pragma once

#include "Button.h"

/*-------- MODULE INCLUDED IN INPUT.H --------*/

#define MOUSE_BTN_COUNT 3

namespace MouseButton
{
	enum MouseButton
	{
		LMB = 0,
		RMB = 1,
		MMB = 2
	};
}

class Mouse
{

	friend class InputInternal;

public:
	Mouse()
	{

	}

	bool getButtonDown(MouseButton::MouseButton btn) const
	{
		return buttons[btn].getPressState() == PressState::Down;
	}

	bool getButton(MouseButton::MouseButton btn) const
	{
		return buttons[btn].getPressState() == PressState::Down ||
			   buttons[btn].getPressState() == PressState::Press;
	}

	bool getButtonUp(MouseButton::MouseButton btn) const
	{
		return buttons[btn].getPressState() == PressState::Up;
	}

	// MAKE INPUT A FRIEND CLASS
	void earlyUpdate()
	{
		hasReceivedInput = false;


	}

	

	

	inline double getX() const { return x; }
	inline double getY() const { return y; }
	inline double getDeltaX() const { return deltaX; }
	inline double getDeltaY() const { return deltaY; }

	bool hasReceivedInput = false;
private:
	void setPos(double xPos, double yPos)
	{
		x = xPos;
		y = yPos;

		deltaX = x - lastX;
		deltaY = y - lastY;
		lastX = x;
		lastY = y;

		hasReceivedInput = true;
	}

	void lateUpdate()
	{
		if (!hasReceivedInput)
		{
			deltaX = 0.0f;
			deltaY = 0.0f;
			lastX = x;
			lastY = y;
		}

		for (size_t i = 0; i < MOUSE_BTN_COUNT; i++)
		{
			buttons[i].lateUpdate();
		}
	}

	double x = 400;
	double y = 300;

	double lastX = 400;
	double lastY = 300;


	double deltaX{ 0 };
	double deltaY{ 0 };


	Button buttons[MOUSE_BTN_COUNT];
};
