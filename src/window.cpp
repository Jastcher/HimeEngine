#include"window.h"

Window::Window(int _width, int _height, const char* _title)
	: width(_width), height(_height), aspect(_width/_height), title(_title) {
	if (!glfwInit()) {
		LOG("Failed to initialize GLFW");
		glfwTerminate();
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		LOG("Failed to create GLFW window");
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG("Failed to initialize GLAD");
		glfwTerminate();
	}
	glViewport(0, 0, width, height);

	SetVSync(true);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	

}

Window::~Window() {
	glfwTerminate();
}

void Window::Clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::SetColor(float r, float g, float b) {
	glClearColor(r, g, b, 1.0f);
}

void Window::SetTitle(const char* _title) {
	title = _title;
	glfwSetWindowTitle(window, title);
}

void Window::SetVSync(bool vSync) {
	glfwSwapInterval(vSync);
}

