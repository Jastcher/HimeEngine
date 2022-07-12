#include"camera.h"

Camera::Camera(float fov, float aspect, Mesh* mesh, Material* material, Shader* shader)
	: Object(mesh, material, shader), fov(fov), aspect(aspect), sensitivity(100.0f) {}

glm::mat4 Camera::GetViewMatrix() {
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::lookAt(transform.position, transform.position + orientation, up);
	return view;
}

glm::mat4 Camera::GetProjectionMatrix(float nearPlane, float farPlane) {
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
	return projection; 
}

void Camera::Update(Window* window, float deltaTime) {
	// KEYBOARD
	if (glfwGetKey(window->window, GLFW_KEY_W) == GLFW_PRESS) {
		transform.position += orientation * speed * deltaTime;
	}
	if (glfwGetKey(window->window, GLFW_KEY_S) == GLFW_PRESS) {
		transform.position -= orientation * speed * deltaTime;
	}
	if (glfwGetKey(window->window, GLFW_KEY_A) == GLFW_PRESS) {
		transform.position -= glm::normalize(glm::cross(orientation, up)) * speed * deltaTime;
	}
	if (glfwGetKey(window->window, GLFW_KEY_D) == GLFW_PRESS) {
		transform.position += glm::normalize(glm::cross(orientation, up)) * speed * deltaTime;
	}
	if (glfwGetKey(window->window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		transform.position += up * speed * deltaTime;
	}
	if (glfwGetKey(window->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		transform.position -= up * speed * deltaTime;
	}

	// MOUSE
	if (glfwGetMouseButton(window->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		cameraEnabled = true;
	}
	if (cameraEnabled) {
		glfwSetInputMode(window->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick) {
			glfwSetCursorPos(window->window, window->width / 2, window->height / 2);
			firstClick = false;
		}

		double mouseX, mouseY;
		glfwGetCursorPos(window->window, &mouseX, &mouseY);
		float rotX = sensitivity * (float)(mouseY - window->height / 2) / window->height;
		float rotY = sensitivity * (float)(mouseX - window->width / 2) / window->width;
		
		orientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));
		orientation = glm::rotate(orientation, glm::radians(-rotY), up);

		glfwSetCursorPos(window->window, window->width / 2, window->height / 2);
	}
	if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetInputMode(window->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
		cameraEnabled = false;
	}
}
