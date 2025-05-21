#include <RenderEngine.h>
#include <iostream>

Vector3 pos;

class Sandbox : public RenderEngine::Game
{
	Shader* cubeShader{};
	Shader* lightShader{};

	unsigned int VBO;
	unsigned int VAO;

	LookAtCamera camera{};

	void start() override
	{
		cubeShader = new Shader{ "src/shaders/VertexShader.vert", "src/shaders/FragmentShader.frag" };
		//lightShader = new Shader{ "src/shaders/LightVertex.vert", "src/shaders/LightFrag.frag" };


		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Primitives::Cube::verticesWithNormals), Primitives::Cube::verticesWithNormals, GL_STATIC_DRAW);

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// Unbind Buffers
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glEnable(GL_DEPTH_TEST);

		glDisable(GL_CULL_FACE);

		camera.transform.position = Vector3(0, 0, -30.f);
	}

	void update() override
	{
		if (Input::keyboard()->getButtonDown(GLFW_KEY_F))
		{
			
		}

		if (Input::keyboard()->getButtonUp(GLFW_KEY_F))
		{
			
		}

		cubeShader->use();

		glBindVertexArray(VAO);

		Mat4 modelMat = Mat4(1.f);
		modelMat = glm::translate(modelMat, Vector3(0.f, 0.0f, 0.f));
		modelMat = glm::rotate(modelMat, (float)glm::radians(glfwGetTime() * 100) * 2.f, Vector3(0, 1, 0));

		Mat4 projectionMat = glm::perspective(glm::radians(40.f), 1.f, 0.1f, 100.f);

		Mat4 viewMat = camera.GetViewMatrix();


		cubeShader->setMat4("projectionMatrix", projectionMat);
		cubeShader->setMat4("viewMatrix", viewMat);

		for (int i = -5; i < 5; i++)
		{
			modelMat = glm::translate(Mat4(1.f), Vector3(i + (i * 0.5f), 0.0f, 0.f));
			cubeShader->setMat4("modelMatrix", modelMat);

			glDrawArrays(GL_TRIANGLES, 0, 36);
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
	return RenderEngine::StartingConfiguration{ 800, 800, Vector4(1.f,0.6f,0.6,1) };
}

//if (RenderEngine::engine->input()->getMouse()->getButtonDown(MouseButton::LMB))
//{
//	RE_LOG("Pressed left mouse btn");
//}