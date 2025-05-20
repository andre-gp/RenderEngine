#pragma once

namespace RenderEngine
{
	struct StartingConfiguration
	{
		int width{ 450 };
		int height{ 450 };
		Vector4 clearColor{};

		StartingConfiguration(int width, int height, const Vector4& clearColor)
			: width(width), height(height), clearColor(clearColor)
		{
		}
	};


	class Game
	{
	public:
		/* ------- STARTING CONFIGS -------- */
		virtual int getStartingWidth() { return 450; }
		virtual int getStartingHeight() { return 450; }
		virtual Vector4 getStartingClearColor() { return { 0.2f, 0.3f, 0.3f, 1.0f }; }

		virtual void start() { };

		virtual void update() { };

		virtual void lateUpdate() { };

		virtual void exit() { } ;
	};

	Game* CreateGame();

	StartingConfiguration GetStartingConfiguration();
}

