#include "Window.h"

#include <iostream>

#define GLEW_STATIC
#include <glew/glew.h>
#include <GLFW/x64/glfw3.h>

#include "../Config.h"

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::MakeContextCurrent()
{
	glfwMakeContextCurrent(mWindow);

}

int Window::init()
{
	if (!glfwInit())
	{
		std::cerr << "GLFW didn't initialize success." << std::endl;
		return -1;
	}

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Window", nullptr, nullptr);

	MakeContextCurrent();
	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);


	if (mWindow == nullptr)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return -1;
	}

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW." << std::endl;
		glfwTerminate();
		return -1;
	}

	return 0;
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(mWindow);
}

int Window::ShouldClose()
{
	return glfwWindowShouldClose(mWindow);
}

void Window::Terminate()
{
	glfwTerminate();
}
