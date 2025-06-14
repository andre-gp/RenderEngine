#pragma once

#include "RenderEngine/TypeDefs.h"

/*-------- CORE CLASSES --------*/
#include "RenderEngine/Core/Engine.h"
#include "RenderEngine/Core/Game.h"

/*-------- UTILITY CLASSES --------*/
#include "RenderEngine/Shaders/Shader.h"
#include "RenderEngine/Shaders/Texture.h"

#include "RenderEngine/Utility/Primitives.h"

/*------- CAMERA --------*/
#include "RenderEngine/Components/Camera/LookAtCamera.h"



extern RenderEngine::Game* RenderEngine::CreateGame();

extern RenderEngine::StartingConfiguration RenderEngine::GetStartingConfiguration();

namespace RenderEngine
{	
	Game* game;

	Engine* engine;

	void init()
	{
		RenderEngine::Log::Init();

		engine = new Engine();

		game = CreateGame();

		engine->init(&GetStartingConfiguration());

		game->start();
	}

	void update()
	{
		RenderEngine::engine->update();

		RenderEngine::game->update();
	}

	void lateUpdate()
	{
		RenderEngine::game->lateUpdate();

		RenderEngine::engine->lateUpdate();
	}


	void terminate()
	{
		RE_CORE_INFO("Terminating program!");

		game->exit();

		engine->terminate();

		delete game;

		delete engine;
	}

}

namespace Input
{
	Keyboard* keyboard()
	{
		return RenderEngine::engine->input()->getKeyboard();
	}

	const Mouse* mouse()
	{
		return RenderEngine::engine->input()->getMouse();
	}
}

int main()
{
	RenderEngine::init();

	while (RenderEngine::engine->isRunning())
	{
		RenderEngine::update();

		RenderEngine::lateUpdate();
	}

	RenderEngine::terminate();
}


