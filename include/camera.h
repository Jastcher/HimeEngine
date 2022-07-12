#pragma once
#include"object.h"
#include"window.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"
#include"glm/gtx/rotate_vector.hpp"
#include"glm/gtx/vector_angle.hpp"

class Camera : public Object {

public:
	float fov;
	float sensitivity;
	float speed = 2.0f;
	float aspect;

	Camera(float fov, float aspect, Mesh* mesh, Material* material, Shader* shader);
	
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix(float nearPlane, float farPlane);

	void Update(Window* window, float deltaTime);
private:
	bool cameraEnabled = false;
	bool firstClick = true;

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
};

