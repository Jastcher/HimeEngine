#pragma once
#include"scene.h"

class Renderer {

public:
	Renderer();

	void RenderScene(Scene* scene);
	void RenderObject(Object* object, glm::mat4 cameraViewMatrix, glm::mat4 cameraProjectionMatrix);

public:
	std::vector<Vertex> quadVertices = {
		Vertex{ glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
		Vertex{ glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
		Vertex{ glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f) }
	};

	std::vector<unsigned int> quadIndices = {
		0, 1, 2,
		2, 3, 0
	};
	
	std::vector<Vertex> lineVertices = {
		Vertex{ glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) }
	};

	std::vector<unsigned int> lineIndices = {
		0, 1
	};
};
