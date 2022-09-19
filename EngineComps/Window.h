#pragma once
struct GLFWwindow;

class Window
{
private:
	GLFWwindow* mWindow = nullptr;

private:
	void MakeContextCurrent(); 
	
public:
	int init();

	GLFWwindow* GetWindow() const;

	void PollEvents();
	void SwapBuffers();
	int ShouldClose();
	void Terminate();
};

