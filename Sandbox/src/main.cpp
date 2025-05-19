#include <RenderEngine.h>
#include <iostream>

Vector3 pos;

class Sandbox : public RenderEngine::Game
{
	int getStartingWidth() override { return 850; }
	int getStartingHeight() override { return 850; }

	void start() override
	{
		RE_INFO("Starting");
	}

	void update() override
	{
		
	}

	void lateUpdate() override
	{
		
	}

	void exit() override
	{
		RE_INFO("Exiting");
	}
};

RenderEngine::Game* RenderEngine::CreateGame()
{
	return new Sandbox();
}