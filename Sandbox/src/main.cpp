#include <RenderEngine.h>
#include <iostream>

Vector3 pos;

class Sandbox : public RenderEngine::Game
{
	#pragma region Starting Configs
	int getStartingWidth() override { return 850; }
	int getStartingHeight() override { return 850; }
	Vector4 getStartingClearColor() override { return { 1,0,0,1 }; }
	#pragma endregion

	Shader* cubeShader{};
	Shader* lightShader{};

	void start() override
	{
		cubeShader = new Shader{ "src/shaders/VertexShader.vert", "src/shaders/FragmentShader.frag" } ;
		//lightShader = new Shader{ "src/shaders/LightVertex.vert", "src/shaders/LightFrag.frag" };
		RE_INFO("Starting");
	}

	void update() override
	{
		if (RenderEngine::engine->input()->getMouse()->getButtonDown(MouseButton::LMB))
		{
			RE_LOG("Pressed left mouse btn");
		}
	}

	void lateUpdate() override
	{
		
	}

	void exit() override
	{
		
	}
};

RenderEngine::Game* RenderEngine::CreateGame()
{
	return new Sandbox();
}

RenderEngine::StartingConfiguration RenderEngine::GetStartingConfiguration()
{
	return RenderEngine::StartingConfiguration{ 800, 800, Vector4(1.f,1.f,0,1) };
}