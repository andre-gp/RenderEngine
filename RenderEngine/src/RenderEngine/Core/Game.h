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
		virtual void start() { };

		virtual void update() { };

		virtual void lateUpdate() { };

		virtual void exit() { } ;
	};

	Game* CreateGame();

	StartingConfiguration GetStartingConfiguration();
}

