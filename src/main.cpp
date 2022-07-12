#include "shader.h"
#include "window.h"
#include "renderer.h"

void window_size_callback(GLFWwindow* window, int width, int height); 

Window window(800, 600, "Hello World");
Scene scene;
Renderer renderer;

int main(void) {
	glfwSetFramebufferSizeCallback(window.window, window_size_callback);

	window.SetColor(0.2f, 0.3f, 0.3f);

	Shader colorShader("src/shaders/default.shader");
	Shader textureShader("src/shaders/texture.shader");
	Shader billboardShader("src/shaders/billboard.shader");

	Mesh mesh(renderer.quadVertices, renderer.quadIndices);
	Mesh lineMesh(renderer.lineVertices, renderer.lineIndices, GL_LINES);

	Material whiteMaterial;
	whiteMaterial.color = glm::vec3(1.0f, 1.0f, 1.0f);

	Material crateMaterial;
	crateMaterial.LoadTexture("res/textures/crate.jpg");

	Material camMaterial;
	camMaterial.LoadTexture("res/icons/video-camera.png");

	Object object(&mesh, &crateMaterial, &textureShader);
	object.transform.scale = glm::vec3(0.5f);
	object.transform.position = glm::vec3(-0.5f);
	object.transform.rotation = glm::vec3(-45.0f, 0.0f, 0.0f);

	Object object2(&mesh, &crateMaterial, &textureShader);
	object2.transform.scale = glm::vec3(0.5f);
	object2.transform.position = glm::vec3(0.5f);
	object2.transform.rotation = glm::vec3(0.0f, 0.0f, 45.0f);

	Object line(&lineMesh, &whiteMaterial, &colorShader);

	Camera camera(90.0f, window.aspect, &mesh, &camMaterial, &billboardShader);
	camera.transform.position = glm::vec3(1.0f, 0.0f, 0.0f);
	camera.transform.scale = glm::vec3(0.1f);

	Camera camera2(90.0f, window.aspect, &mesh, &camMaterial, &billboardShader);
	camera2.transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	camera2.transform.scale = glm::vec3(0.1f);

	scene.AddObject(&object);
	scene.AddObject(&object2);
	scene.AddObject(&line);
	scene.AddObject(&camera);
	scene.AddObject(&camera2);
	scene.AddCamera(&camera);
	scene.AddCamera(&camera2);
	scene.ChangeCamera(0);

	float currentFrame;
	float lastFrame = 0.0f;
	float deltaTime;
	float FPS;
	float frameTime;

	while (!glfwWindowShouldClose(window.window)) {
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		FPS = 1.0f / deltaTime;
		frameTime = deltaTime * 1000.0f;

		if(glfwGetKey(window.window, GLFW_KEY_O) == GLFW_PRESS) {
			scene.ChangeCamera(0);
		}
		if(glfwGetKey(window.window, GLFW_KEY_P) == GLFW_PRESS) {
			scene.ChangeCamera(1);
		}

		window.SetTitle(std::to_string(FPS).c_str());

		scene.activeCamera->Update(&window, deltaTime);

		window.Clear();
		renderer.RenderScene(&scene);
		window.Update();
    }

    glfwDestroyWindow(window.window);
    glfwTerminate();
}

void window_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

	for(Camera* camera : scene.cameras) {
		camera->aspect = (float)width/(float)height;
	}
}
