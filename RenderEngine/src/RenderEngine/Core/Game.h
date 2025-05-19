#pragma once

namespace RenderEngine
{
	class Game
	{
	public:
		/* ------- STARTING CONFIGS -------- */
		virtual int getStartingWidth() { return 450; }
		virtual int getStartingHeight() { return 450; }

		virtual void start() { };

		virtual void update() { };

		virtual void lateUpdate() { };

		virtual void exit() { } ;
	};

	Game* CreateGame();
}

