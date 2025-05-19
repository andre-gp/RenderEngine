#pragma once

#include "RenderEngine/TypeDefs.h"

/*-------- CLASSES --------*/
#include "RenderEngine/Core/Engine.h"
#include "RenderEngine/Core/Game.h"

extern RenderEngine::Game* RenderEngine::CreateGame();

namespace RenderEngine
{
	Game* game;

	Engine* engine;

	void init()
	{
		RenderEngine::Log::Init();

		engine = new Engine();

		game = CreateGame();

		engine->init(game->getStartingWidth(), game->getStartingHeight());

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


