#pragma once

#include "Mouse.h"
#include "Keyboard.h"

class InputInternal
{
	friend class Window;

public:

	const Mouse* getMouse() const { return &mouse; }
	Keyboard* getKeyboard() { return &keyboard; }

private:
	void setKeyboardButton(int btn, int action)
	{
		// Doesn't set if is detecting repeated key press (action == 2)
		if(action <= 1)
			keyboard.buttons[btn].setState(action);
	}

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
		keyboard.lateUpdate();
	}

	Mouse mouse{};

	Keyboard keyboard{};
};

