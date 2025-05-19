#pragma once

#include "Mouse.h"

class Input
{
	friend class Window;

public:

	const Mouse* getMouse() const { return &mouse; }

private:
	void setMouseButton(int btn, int action)
	{
		mouse.buttons[btn].setState(action);
	}

	void setCursorPos(double x, double y)
	{
		mouse.setPos(x, y);
	}

	void lateUpdate()
	{
		mouse.lateUpdate();
	}

	Mouse mouse{};
};

