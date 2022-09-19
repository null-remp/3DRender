#include <iostream>

#define GLEW_STATIC
#include <glew/glew.h>
#include <GLFW/x64/glfw3.h>

#include "EngineComps/Window.h"
#include "EngineComps/Utils.h"
#include "EngineComps/Shader.h"

#include "Config.h"

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

Window window;

float vertices[] = {
   -0.5f, 0.0f, 0.0f,	1.0f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f,	1.0f, 0.0f, 1.0f,
	0.5f, 0.0f, 0.0f,	1.0f, 0.0f, 1.0f
};

int main()
{
	window.init();

	//Buffers
	unsigned int VAO;
	unsigned int VBO;
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAO);

	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Shader shader(MAIN_VERT_PATH, MAIN_FRAG_PATH);

	while (!window.ShouldClose())
	{
		processInput(window.GetWindow());

		glClearColor(0.3f, 0.23f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		
		shader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		

		window.SwapBuffers();
		window.PollEvents();
	}

	
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	window.Terminate();
	return 0;
}




