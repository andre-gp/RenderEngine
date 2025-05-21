#pragma once

#include <map>

#include "Button.h"

/*-------- MODULE INCLUDED IN INPUT.H --------*/

class Keyboard
{
public:
	friend class InputInternal;

	bool getButtonDown(int btn)
	{		
		return findButton(btn)->getPressState() == PressState::Down;
	}

	bool getButton(int btn)
	{
		return findButton(btn)->getPressState() == PressState::Down ||
			findButton(btn)->getPressState() == PressState::Press;
	}

	bool getButtonUp(int btn)
	{
		return findButton(btn)->getPressState() == PressState::Up;
	}

	void lateUpdate()
	{
		auto it = buttons.begin();

		while (it != buttons.end())
		{
			it->second.lateUpdate();

			it++;
		}
	}

private:
	Button* findButton(int btn)
	{
		// When accessing maps in c++, if the key's not found, it automatically adds one.
		Button* btnPtr = &buttons[btn];

		return btnPtr;
	}

	std::map<int, Button> buttons{};
};