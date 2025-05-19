#pragma once

#include <cstdint>

namespace PressState
{
	enum PressState : uint8_t
	{
		NotPressing = 0,
		Down = 1,
		Press = 2,
		Up = 3
	};

}


class Button
{

public:

	void setState(bool isPressing)
	{
		pressState = isPressing ? PressState::Down : PressState::Up;
	}

	void lateUpdate()
	{
		if (pressState == PressState::Down)
		{
			pressState = PressState::Press;
		}
		else if (pressState == PressState::Up)
		{
			pressState = PressState::NotPressing;
		}
	}

	inline PressState::PressState getPressState() const { return pressState; }

private:
	PressState::PressState pressState = PressState::NotPressing;
};