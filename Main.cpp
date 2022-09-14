#include <iostream>

#define GLEW_STATIC
#include <glew/glew.h>
#include <GLFW/x64/glfw3.h>

#include "EngineComps/Window.h"

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

Window window;

int main()
{
	window.init();

	 


	while (!window.ShouldClose())
	{
		processInput(window.GetWindow());

		glClearColor(0.3f, 0.23f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.SwapBuffers();
		window.PollEvents();
	}
	
	window.Terminate();
	return 0;
}



