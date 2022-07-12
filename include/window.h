#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "log.h"

class Window {
public:
	GLFWwindow* window;
	int width;
	int height;
	float aspect;
	const char* title;
	bool vSync;

	Window(int width, int height, const char* title);
	~Window();

	void Clear();
	void Update();
	void SetColor(float r, float g, float b);
	void SetTitle(const char* title);
	void SetVSync(bool vSync);

};
